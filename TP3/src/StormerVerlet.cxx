#include "StormerVerlet.hpp"

using namespace std;


vector<Vecteur> Störmer_Verlet::force_grav(const std::vector<ParticuleA> &parList, int n)  {
    int i, j;
    double fx, fy, fz, mi, mj, dxi, dyi, dzi, dx, dy, dz, r, f;
    vector<Vecteur> forces;  // Vecteur pour stocker les forces de chaque particule

    for (i = 0; i < n; i++) {
        fx = fy = fz = 0;
        mi = parList[i].getMasse();
        dxi = parList[i].getPosition()[0];  // Accès via l'indice pour x
        dyi = parList[i].getPosition()[1];  // Accès via l'indice pour y
        dzi = parList[i].getPosition()[2];  // Accès via l'indice pour z

        for (j = 0; j < n; j++) {
            if (j != i) {  // Évite l'auto-interaction
                mj = parList[j].getMasse();
                dx = dxi - parList[j].getPosition()[0];  // Accès via l'indice pour x
                dy = dyi - parList[j].getPosition()[1];  // Accès via l'indice pour y
                dz = dzi - parList[j].getPosition()[2];  // Accès via l'indice pour z
                r = dx * dx + dy * dy + dz * dz;  // Distance au carré en 3D
                f = (G * mi * mj) / (r * sqrt(r));  // Force gravitationnelle

                fx += f * dx;
                fy += f * dy;
                fz += f * dz;  // Force dans la direction z
            }
        }
        forces.push_back(Vecteur(fx, fy, fz)); // <-- On ajoute la force de la particule i
    }
    return forces;  // Retourne le vecteur des forces
}


    /**
     * @brief Implémente l'algorithme de Störmer-Verlet pour l'intégration du mouvement.
     * @param dt Pas de temps.
     * @param dfin Durée de la simulation.
     * @param parList Liste des particules.
     * @param n Nombre de particules.
     * @param file Fichier de sortie pour enregistrer les résultats.
     */
vector<vector<Vecteur>> Störmer_Verlet::algoStr(double dt, double dfin,vector<ParticuleA> &parList, int n,ofstream &file){
    double t_init = 0;
    int i;
    vector<vector<Vecteur>> trajectoires;

    while (t_init < dfin) {
        vector<double> old_fx, old_fy, old_fz;
        vector<Vecteur> snapshot; // <-- Snapshot à l'instant t

        
        file << "Nouvelle position" << "\n";  // Ajoute un marqueur pour chaque itération
        
        this->force_grav(parList, n);  // Calcul des forces

        t_init += dt;
        for (i = 0; i < n; i++) {
            // Sauvegarde des forces avant la mise à jour
            old_fx.push_back(parList[i].getForce()[0]);
            old_fy.push_back(parList[i].getForce()[1]);
            old_fz.push_back(parList[i].getForce()[2]);  // Sauvegarde de la force en z
            
            // Mise à jour de la position de la particule
            parList[i].setPosition(dt);  // Mise à jour de la position (x, y, z)
            snapshot.push_back(parList[i].getPosition()); // <-- On stocke la position à l'instant t
            parList[i].save(file);  // Sauvegarde de la position
        }

        this->force_grav(parList, n);  // Recalcul des forces après la mise à jour

        for (i = 0; i < n; i++) {
            // Mise à jour de la vitesse en tenant compte des trois dimensions
            parList[i].setVitesse(dt,  Vecteur(old_fx[i], old_fy[i], old_fz[i]));  // Mise à jour de la vitesse (x, y, z)
        }
        trajectoires.push_back(snapshot); // <-- Ajoute le snapshot à la trajectoire globale

    }
    return trajectoires;
}