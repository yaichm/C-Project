#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "vecteur.hpp"  
#include "Particule.hpp"  
#include "Univers.hpp"     
#include "cellule.hpp"     

using namespace std;

int main() {
    vector<double> dimension = {250, 40};
    double sigma = 1.0;   // Paramètre de Lennard-Jones (sigma)
    double r_cut = 2.5*sigma;   // Rayon de coupure
    double epsilon = 5.0;

    // Créez l'univers
    Univers univers(dimension, sigma, r_cut, epsilon);

    const int N = 160;  // Exemple de 8 particules
    vector<ParticuleA> particules;

    // Création des particules dans l'univers
    for (int i = 0; i < N; ++i) {
        double x = static_cast<double>(i) / N;
        double y = static_cast<double>(i) / N;
        double z = 0;
        Vecteur position(x, y, z);
        Vecteur vitesse(0, 10.0, 0.0);
        Vecteur force(0.0, 0.0, 0.0);
        double masse = 1.0;
        particules.push_back(ParticuleA(masse, position, vitesse, force));
    }

    // univers.assignCells(particules);

    ofstream file("trajectoires.txt");

    double dt = 0.05;  // Pas de temps
    double dfin = 19.5; // Durée de la simulation (en temps)

    vector<vector<Vecteur>> trajectoires = univers.algoStr(dt, dfin, particules, N, file);

    // for (const auto& trajectoire : trajectoires) {
    //     for (const auto& pos : trajectoire) {
    //         cout << "Position: (" << pos[0] << ", " << pos[1] << ", " << pos[2] << ")" << endl;
    //     }
    // }

    file.close();
    return 0;
}
