#include "cellule.hpp"


//Constructeur de cellule

Cellule::Cellule(const vector<size_t>& indx_cellule, const vector<size_t> &particules)
        : indices(indx_cellule), particules(particules){} 

void Cellule::setIndices(vector<size_t>& indices){
        indices = indices;
}
vector<size_t> Cellule::getIndices(){
        return indices;
}

vector<size_t> Cellule::getParticules(){
        return particules;
}

Cellule::Cellule() {

}