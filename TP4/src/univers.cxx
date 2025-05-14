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


vector<vector <size_t>> Univers::getVoisinage(size_t indx){
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
    vector<ParticuleA*> particules_vides;

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
                // Ajouter la cellule voisine à la liste des voisins
                voisinage[lin].push_back(cellules[linearIndex(cand)].getIndices());
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