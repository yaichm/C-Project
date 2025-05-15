#include "Univers.hpp"
#include "cellule.hpp"
#include <iostream>
#include <chrono>

// Génère un groupe rectangulaire de particules
std::vector<ParticuleA> genererGroupe(int nx, int ny,double masse,const Vecteur& vitesse_init,Vecteur& origine,double espacement)
{
    std::vector<ParticuleA> groupe;
    groupe.reserve(nx * ny);
    for(int i = 0; i < nx; ++i) {
        for(int j = 0; j < ny; ++j) {
            double x = origine.get_x() + i * espacement;
            double y = origine.get_y() + j * espacement;
            groupe.emplace_back(masse, Vecteur{x, y, 0.0}, vitesse_init, Vecteur{0.0, 0.0, 0.0});
        }
    }
    return groupe;
}

int main()
{
    const double Δ          = pow(2.0, 1.0/6.0);  // espacement
    const double ε          = 10.0 ;                   // petite marge

    vector<double> dimension = {250, 40};
    double sigma = 1.0;           // Paramètre de Lennard-Jones (sigma)
    double r_cut = 2.5 * sigma;   // Rayon de coupure
    double epsilon = 5.0;

    // Créez l'univers
    Univers univers(dimension, sigma, r_cut, epsilon);
    // Tailles en particules
    const int nx1 = 40, ny1 = 40;
    const int nx2 = 160, ny2 = 40;

    // Dimensions physiques
    double Lx1 = nx1 * Δ, Hy1 = ny1 * Δ;
    double Lx2 = nx2 * Δ, Hy2 = ny2 * Δ;

    // Séparation minimale des centres (le rectangle en bas, le carré en haut)
    double gap         = ε;
    double sep_centres = (Hy1/2.0) + (Hy2/2.0) + gap;

    // Origines (coin inférieur gauche) :
    //   - Carré centré en x=0, centre y = +sep_centres/2 ⇒ origine y = centre_y - Hy1/2
    //   - Rectangle centré en x=0, centre y = -sep_centres/2 ⇒ origine y = centre_y - Hy2/2
    Vecteur origine_carre     { -Lx1/2.0,  +sep_centres/2.0 - Hy1/2.0, 0.0 };
    Vecteur origine_rectangle { -Lx2/2.0,  -sep_centres/2.0 - Hy2/2.0, 0.0 };

    // Vitesses initiales
    Vecteur v_carre{0.0, -10.0, 0.0};  // vitesse descendante le long de y
    Vecteur v_rect {0.0,  0.0, 0.0};   // rectangle immobile

    // Masses
    double masse = 1.0;

    // Génération des particules
    auto square    = genererGroupe(nx1, ny1, masse, v_carre,    origine_carre,     Δ);
    auto rectangle = genererGroupe(nx2, ny2, masse, v_rect,     origine_rectangle, Δ);

    // Concaténation
    std::vector<ParticuleA> toutesLesParticules;
    toutesLesParticules.reserve(square.size() + rectangle.size());
    toutesLesParticules.insert(toutesLesParticules.end(),
                            square.begin(), square.end());
    toutesLesParticules.insert(toutesLesParticules.end(),
                            rectangle.begin(), rectangle.end());

    // … passer `toutesLesParticules` à votre Univers pour la simulation …
    ofstream file("Simulation.txt");

    double dt = 0.05;     // Pas de temps
    double dfin = 19.5;   // Durée de la simulation (en temps)
    auto t0 = std::chrono::high_resolution_clock::now();

    vector<vector<Vecteur>> trajectoires = univers.algoStr(dt, dfin, toutesLesParticules, nx1*ny1 + nx2*ny2, file);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duree = t1 - t0;
    std::cout << "Temps d’exécution : " 
            << duree.count() << " s\n";

}