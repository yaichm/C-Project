#ifndef PARTICULE_H
#define PARTICULE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "vecteur.hpp" 
#include <list>
#include <random>
#include <sstream>

using namespace std;

/**
 * @class ParticuleA
 * @brief Classe représentant une particule avec sa masse, position, vitesse et force.
 */
class ParticuleA {
private:
    double masse;      ///< Masse de la particule
    Vecteur vect_position; ///< Position de la particule
    Vecteur vect_vitesse;  ///< Vitesse de la particule
    Vecteur vect_force;    ///< Force exercée sur la particule

public:
    /**
     * @brief Constructeur de la classe ParticuleA.
     * @param m Masse de la particule.
     * @param vect_posi Position initiale de la particule.
     * @param vect_vite Vitesse initiale de la particule.
     * @param vect_forc Force initiale appliquée à la particule.
     */
    ParticuleA(double m, const Vecteur& vect_posi, const Vecteur& vect_vite, const Vecteur& vect_forc);

    /**
     * @brief Récupère la masse de la particule.
     * @return La masse de la particule.
     */
    double getMasse() const;

    /**
     * @brief Récupère la position de la particule.
     * @return La position de la particule (vecteur).
     */
    Vecteur getPosition() const;

    /**
     * @brief Récupère la vitesse de la particule.
     * @return La vitesse de la particule (vecteur).
     */
    Vecteur getVitesse() const;

    /**
     * @brief Récupère la force exercée sur la particule.
     * @return La force exercée (vecteur).
     */
    Vecteur getForce() const;

    /**
     * @brief Met à jour la position de la particule en fonction du temps dt.
     * @param dt Le pas de temps.
     */
    Vecteur setPosition(double dt);

    /**
     * @brief Met à jour la vitesse de la particule en tenant compte des forces appliquées.
     * @param dt Le pas de temps.
     * @param old_force La force de la particule à l'instant précédent.
     */
    Vecteur setVitesse(double dt, const Vecteur& old_force);

    /**
     * @brief Met à jour la force appliquée à la particule.
     * @param new_force Nouvelle force appliquée (vecteur).
     */
    Vecteur setForce(const Vecteur& new_force);

    /**
     * @brief Sauvegarde la position actuelle de la particule dans un fichier.
     * @param file Fichier de sortie.
     */
    bool save(std::ofstream &file, double dt, int indice) const;

    /**
     * @brief Affiche les coordonnées de la particule dans la console.
     */
    string affiche_parm() const;
};

#endif // PARTICULE_H
