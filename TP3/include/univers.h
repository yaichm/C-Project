#ifndef UNIVERS_HPP
#define UNIVERS_HPP

#include <vector>
#include "particuleA.hpp"
#include "StormerVerlet.hpp"

class Univers {
private:
    std::vector<ParticuleA> particules;

public:
    // Constructeur (optionnel)
    Univers();
    const std::vector<ParticuleA>& getParticules() const;


    // Ajouter une particule
    void ajouterParticule(const ParticuleA& p);

    // Afficher toutes les particules
    void afficher() const;

    // Obtenir une particule (lecture seule)
    const ParticuleA& getParticule(int index) const;

    // Obtenir une particule (modifiable)
    ParticuleA& getParticuleModifiable(int index);

    // Nombre total de particules
    size_t taille() const;

    // Vider l'univers
    void nettoyer();
};

#endif // UNIVERS_HPP