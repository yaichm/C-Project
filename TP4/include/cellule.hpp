#ifndef CELLULE_HPP
#define CELLULE_HPP
#include "Particule.hpp"
#include "vecteur.hpp"
#include <vector>

using namespace std;

class Cellule{
    private:
        vector<size_t> indices;
        vector<size_t>  particules;
    public:
        Cellule( const vector<size_t>& indices, const vector<size_t> &particules);
        void setIndices(vector<size_t>& indices);
        vector<size_t> getIndices();
        vector<size_t> getParticules();
        Cellule();
        
};


#endif //CELLUE_HPP