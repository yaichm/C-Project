#include <list>
#include <random>
#include <sstream>
#include "Particule.hpp"
using namespace std;



double ParticuleA::getMasse() const { return masse; }

/**
 * @brief Récupère la position de la particule.
 * @return La position de la particule (vecteur).
 */
Vecteur ParticuleA::getPosition() const { return vect_position; }

/**
 * @brief Récupère la vitesse de la particule.
 * @return La vitesse de la particule (vecteur).
 */
Vecteur ParticuleA::getVitesse() const { return vect_vitesse; }

/**
 * @brief Récupère la force exercée sur la particule.
 * @return La force exercée (vecteur).
 */
Vecteur ParticuleA::getForce() const { return vect_force; }

/**
 * @brief Met à jour la position de la particule en fonction du temps dt.
 * @param dt Le pas de temps.
 */
Vecteur ParticuleA::setPosition(double dt) {
    vect_position += vect_vitesse*dt + vect_force*(0.5 * dt * dt / masse);  // Utilisation des opérateurs de Vecteur
    return vect_position;  // Retourne la nouvelle position
}

/**
 * @brief Met à jour la vitesse de la particule en tenant compte des forces appliquées.
 * @param dt Le pas de temps.
 * @param old_force La force de la particule à l'instant précédent.
 */
Vecteur ParticuleA::setVitesse(double dt, const Vecteur& old_force) {
    vect_vitesse += (vect_force + old_force) * (0.5 * dt / masse);  // Utilisation des opérateurs de Vecteur
    return vect_vitesse;  // Retourne la nouvelle vitesse
}

/**
 * @brief Met à jour la force appliquée à la particule.
 * @param new_force Nouvelle force appliquée (vecteur).
 */
Vecteur ParticuleA::setForce(const Vecteur& new_force) {
    vect_force = new_force;  // Assigner le vecteur de force
    return vect_force;  // Retourne la nouvelle force
}

/**
 * @brief Sauvegarde la position actuelle de la particule dans un fichier.
 * @param file Fichier de sortie.
 */
bool ParticuleA::save(std::ofstream &file, double dt, int indice) const {
    if (file) {
        file << "Vecteur position de la particule " << indice << " à " << dt << " s : ";
        file << vect_position << "\n";  // Affiche le vecteur
        return true;
    }
    return false;
}


/**
 * @brief Affiche les coordonnées de la particule dans la console.
 */
string ParticuleA::affiche_parm() const {
    std::ostringstream oss;
    oss << "(" << vect_position[0] << ", " << vect_position[1] << ", " << vect_position[2] << ")";
    return oss.str();
}


ParticuleA::ParticuleA(double m, const Vecteur& vect_posi, const Vecteur& vect_vite, const Vecteur& vect_forc)
        : masse(m), vect_position(vect_posi), vect_vitesse(vect_vite), vect_force(vect_forc) {}
