#include "Univers.hpp"
#include "cellule.hpp"
#include <functional>
using namespace std;



Univers::Univers(const vector<double>& dimension, double sigma, double r_cut){
    this->r_cut = r_cut;
    this->sigma = sigma;

    this->dim = dimension.size();
    dimensions.resize(dim);

    for (size_t i=0; i<dim; i++){
        dimensions[i] = static_cast<size_t> (dimension[i]/r_cut);
    }

    nb_cellules = 1;

    for (size_t i=0; i< dim ; i++){
        nb_cellules*=dimensions[i];
    }
    this->nb_cellules=nb_cellules;

    this->cellules.resize(nb_cellules);
    initIndices(nb_cellules);

}


vector<size_t> Univers::getVoisinage(size_t indx){
    return voisinage[indx];
}

size_t Univers::linearIndex(const vector<size_t>& idx) const { 
    size_t lin = 0;
    size_t stride = 1;
    for (size_t d = 0; d < dim; ++d) {
        lin += idx[d] * stride;
        stride *= dimensions[d];
    }
    return lin;
}

vector<size_t> Univers::getDimensions(){
    return dimensions ;
}

void Univers::initIndices(size_t nb_totalCells) {
    vector<size_t> idx(dim);
    vector<size_t> particules_vides;

    for (size_t lin = 0; lin < nb_totalCells; ++lin) {
        size_t rem = lin;
        
        for (size_t d = 0; d < dim; ++d) {
            idx[d] = rem % dimensions[d];
            rem /= dimensions[d];
        }

        cellules[lin] = Cellule(idx, particules_vides);
    }
}


void Univers::buildVoisinage(size_t nb_Cellues) {
    voisinage.resize(nb_Cellues);
    // Pour chaque cellule linéaire
    for (size_t lin = 0; lin < nb_Cellues; ++lin) {
        const auto& idx = cellules[lin].getIndices();
        
        // Générer tous les décalages di ∈ {-1, 0, 1} pour chaque dimension
        std::vector<size_t> cand(idx);  // Copie des indices de la cellule

        // Fonction DFS pour parcourir toutes les combinaisons de décalages
        std::function<void(size_t)> dfs = [&](size_t d) {
            if (d == dim) {  // Si on a parcouru toutes les dimensions
                // Vérifier que cand est dans les bornes
                for (size_t k = 0; k < dim; ++k)
                    if (cand[k] >= dimensions[k]) return;  // Hors des bornes
                // Ajouter la cellule voisine aplatie à la liste des voisins (indice linéaire)
                size_t lin_voisin = linearIndex(cand);
                voisinage[lin].push_back(lin_voisin);  // Ajout de l'indice linéaire
            } else {
                // Essayer les déplacements -1, 0, +1 pour la dimension d
                if (idx[d] > 0) {
                    cand[d] = idx[d] - 1;
                    dfs(d + 1);  // Appel récursif pour la dimension suivante
                }
                cand[d] = idx[d];  // Ne pas changer la coordonnée
                dfs(d + 1);
                if (idx[d] + 1 < dimensions[d]) {
                    cand[d] = idx[d] + 1;
                    dfs(d + 1);  // Appel récursif pour la dimension suivante
                }
            }
        };

        // Lancer DFS à partir de la première dimension
        dfs(0);
    }
}


size_t Univers::getTotalCells(){
    return nb_cellules;
}

Cellule& Univers::cellule(const std::vector<size_t>& idx) {
    size_t lin = linearIndex(idx);
    return cellules[lin];
}


void Univers::setSigma(double sigma){
    this->sigma = sigma;
}

void Univers::setR_cut(double r_cut){
    this->r_cut = r_cut;
}

void Univers::assignCells( std::vector<ParticuleA>& parList) {
    // 1) Vider toutes les cellules
    for (auto & cell : cellules) {
    cell.getParticules().clear();
    }

    // 2) Pour chaque particule i
    for (int i = 0; i < (int)parList.size(); ++i) {
    const auto& pos = parList[i].getPosition(); 
    std::vector<size_t> idx(dimensions);

    // 3) Calcul de l’indice de cellule en chaque dimension
    for (size_t d = 0; d < dim; ++d) {
    // pos[d] / cutoff_ → coordonnée dans [0, dims_[d])
    size_t c = (size_t)std::floor(pos[d] / r_cut);
    // on s’assure de rester dans [0, dims_[d]-1]
    idx[d] = std::min(c, dimensions[d] - 1);
    }

    // 4) Conversion en index linéaire
    size_t lin = linearIndex(idx);

    // 5) Ajout de l’indice de particule
    cellules[lin].getParticules().push_back(i);
    }
}
// Dans StörmerVerlet.hpp on aura ajouté :
// void assignCells(const std::vector<ParticuleA>& parList);
// std::vector<Vecteur> force_cells(const std::vector<ParticuleA>& parList);

vector<Vecteur> Univers::force_cells(std::vector<ParticuleA> &parList) {
    const double rc2 = r_cut*r_cut;
    int n = parList.size();
    std::vector<Vecteur> forces(n, Vecteur(0,0,0));

    // 1) Affecter chaque particule à sa cellule
    assignCells(parList);

    // 2) Pour chaque cellule linéaire c
    for (size_t c = 0; c < cellules.size(); ++c) 
    {
        // 2a) Pour chaque particule i dans la cellule c
        for (int i : cellules[c].getParticules()) {
        const auto xi = parList[i].getPosition();
        // 2b) Itérer sur les cellules voisines pré-calculées
        for (size_t nc : voisinage[c]) {
        // 2c) Pour chaque particule j dans la cellule voisine
        for (int j : cellules[nc].getParticules()) {
        if (j <= i) continue; // éviter i==j et double comptage
        const auto xj = parList[j].getPosition();

        // 3) Calcul de la distance au carré
        double dx = xi[0] - xj[0];
        double dy = xi[1] - xj[1];
        double dz = xi[2] - xj[2];
        double d2 = dx*dx + dy*dy + dz*dz;
        if (d2 > rc2) continue; // en dehors du cutoff

        // 4) Calcul du potentiel de Lennard-Jones / force
        double inv_r2 = 1.0 / d2;
        double inv_r6 = inv_r2*inv_r2*inv_r2;
        double fcoef = 24.0 * (inv_r6*inv_r6 - inv_r6) * inv_r2;
        Vecteur f(dx*fcoef, dy*fcoef, dz*fcoef);

        // 5) Action–réaction
        forces[i] += f; // j → i
        forces[j] -= f; // i → j
        }
    }
    }
    }
    return forces;
}


vector<vector<Vecteur>>Univers::algoStr(double dt, double dfin,
    vector<ParticuleA> &parList,
    int n, ofstream &file) {
    double t = 0;
    vector<vector<Vecteur>> trajectoires;

    // --- Boucle temporelle ---
    assignCells(parList);
    while (t < dfin) {

    // 1) Calcul des forces via cell-list
    auto F = force_cells(parList);
    for (int i = 0; i < n; ++i)
    parList[i].setForce(F[i]);

    // 2) Intégration Störmer–Verlet (positions)
    file << "Nouvelle position\n";
    vector<double> old_fx, old_fy, old_fz;
    vector<Vecteur> snapshot;
    for (int i = 0; i < n; ++i) {
        auto f = parList[i].getForce();
        old_fx.push_back(f[0]);
        old_fy.push_back(f[1]);
        old_fz.push_back(f[2]);

        parList[i].setPosition(dt);
        snapshot.push_back(parList[i].getPosition());
        parList[i].save(file);
    }

    // 3) Réaffectation avant recalcul des forces
    assignCells(parList);
    auto F2 = force_cells(parList);
    for (int i = 0; i < n; ++i)
    parList[i].setForce(F2[i]);

    // 4) Mise à jour des vitesses
    for (int i = 0; i < n; ++i) {
    parList[i].setVitesse(
    dt, Vecteur(old_fx[i], old_fy[i], old_fz[i])
    );
    }

    trajectoires.push_back(std::move(snapshot));
    t += dt;
    }
    return trajectoires;
}