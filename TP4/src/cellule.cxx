#include "cellule.hpp"


cellule::cellule(vector<ParticuleA> &listes_particules, vector<cellule> &listes_cellules, int n_dimension )
        : n_dimension(n_dimension), liste_cellules_voisin(listes_cellules), liste_particules_propres(listes_particules){}

