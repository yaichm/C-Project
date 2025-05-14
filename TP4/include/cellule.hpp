#ifndef CELLULE_HPP
#define CELLULE_HPP
#include "Particule.hpp"
#include "vecteur.hpp"
#include <vector>

using namespace std;

class Cellule{
    private:
        vector<size_t> indices;
        vector<ParticuleA*>  particules;
    public:
        Cellule( const vector<size_t>& indices, const vector<ParticuleA*> &particules);
        void setIndices(vector<size_t>& indices);
        vector<size_t> getIndices();
        
};


#endif //CELLUE_HPP