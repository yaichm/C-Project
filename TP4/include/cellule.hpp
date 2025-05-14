#ifndef CELLULE_HPP
#define CELLULE_HPP
#include "Particule.hpp"
#include <vector>

using namespace std;

class cellule{
    private:
        vector<ParticuleA> liste_particules_propres;
        int n_dimension;
        vector<cellule> liste_cellules_voisin;
    public:
        cellule(vector<ParticuleA> &liste_prticules_propres, vector<cellule> & cellues, int n_dimenson);        
};


#endif //CELLUE_HPP