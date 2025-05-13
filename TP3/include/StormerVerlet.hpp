#ifndef StormerVerlet_hpp
#define StormerVerlet_hpp

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "vecteur.h" 
#include <list>
#include <random>
#include "particuleA.hpp"

using namespace std;

const double G = 1.0;  ///< Constante gravitationnelle simplifiée pour la simulation

/**
 * @class Störmer_Verlet
 * @brief Classe gérant l'intégration numérique avec l'algorithme de Störmer-Verlet.
 */
class Störmer_Verlet {
public:
    /**
     * @brief Calcule les forces gravitationnelles entre les particules.
     * @param parList Liste des particules.
     * @param n Nombre de particules.
     */
    vector<Vecteur> force_grav(const vector<ParticuleA> &parList, int n);

    /**
     * @brief Implémente l'algorithme de Störmer-Verlet pour l'intégration du mouvement.
     * @param dt Pas de temps.
     * @param dfin Durée de la simulation.
     * @param parList Liste des particules.
     * @param n Nombre de particules.
     * @param file Fichier de sortie pour enregistrer les résultats.
     */
    vector<vector<Vecteur>> algoStr(double dt, double dfin,vector<ParticuleA> &parList, int n,ofstream &file) ;

    //void algoStr(double dt, double dfin, vector<ParticuleA> &parList, int n, ofstream &file);
};

#endif // PARTICULE_H
