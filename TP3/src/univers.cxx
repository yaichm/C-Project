#include "univers.h"

using namespace std;




const ParticuleA& Univers::getParticule(int index) const {
    return particules.at(index);  
}

ParticuleA& Univers::getParticuleModifiable(int index) {
    return particules.at(index);  
}
const std::vector<ParticuleA>& Univers::getParticules() const {
    return particules;
}


size_t Univers::taille() const {
    return this->getParticules().size();
}

void Univers::nettoyer() {
    particules.clear();
}


void Univers::ajouterParticule(const ParticuleA& p) {
    particules.push_back(p);
}

void Univers:: afficher() const {
    cout << "Contenu de l'univers (" << particules.size() << " particules) :" << endl;
    for (const auto& p : particules) {
        cout << p.affiche_parm() << endl;
    }
}

Univers::Univers(){}