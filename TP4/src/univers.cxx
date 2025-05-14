#include "Univers.hpp"
using namespace std;



Univers::Univers(const vector<double>& dimension, double sigma, double r_cut){
    this->r_cut = r_cut;
    this->sigma = sigma;

    this->dim = dimension.size();
    dimensions.resize(dim);

    for (size_t i=0; i<dim; i++){
        dimensions[i] = static_cast<size_t> (dimension[i]/r_cut);
    }

    size_t nb_cellules = 1;

    for (size_t i=0; i< dim ; i++){
        nb_cellules*=dimensions[i];
    }
    this->nb_cellules=nb_cellules;

    this->cellules.resize(nb_cellules);
    initIndices(nb_cellules);

}


vector<vector <size_t>> Univers::getVoisinage(size_t indx){
    return voisinage[indx];
}

size_t Univers::linearIndex(const vector<size_t>& idx) const { 
    size_t lin = 0;
    size_t stride = 1;
    for (size_t d = 0; d < dim; ++d) {
        lin += idx[d] * stride;
        stride *= dimensions[d];
    }
    return lin;
}

void Univers::initIndices(size_t nb_totalCells) {
        vector<size_t> idx(dim);
        for (size_t lin = 0; lin < nb_totalCells; ++lin) {
            size_t rem = lin;
            for (size_t d = 0; d < dim; ++d) {
                idx[d] = rem % dimensions[d];
                rem /= dimensions[d];
            }
            cellules[lin].setIndices(idx);
        }
    }


void Univers::buildVoisinage(size_t totalCells) {
    voisinage.resize(totalCells);
    for (size_t lin = 0; lin < totalCells; ++lin) {
        const auto& idx = cellules[lin].getIndices();

        // Pour chaque combinaison de décalages {-1, 0, +1} dans chaque dimension
        size_t nbVoisins = 1;
        for (size_t d = 0; d < dim; ++d) nbVoisins *= 3;

        for (size_t i = 0; i < nbVoisins; ++i) {
            std::vector<size_t> cand = idx;
            size_t n = i;

            // Générer les décalages pour chaque dimension
            bool skip = false;
            for (size_t d = 0; d < dim; ++d) {
                int offset = (int)(n % 3) - 1;  // -1, 0 ou +1
                n /= 3;

                int newCoord = (int)idx[d] + offset;
                if (newCoord < 0 || newCoord >= (int)dimensions[d]) {
                    skip = true; // Hors des bornes
                    break;
                }
                cand[d] = (size_t)newCoord;
            }

            if (!skip)
                voisinage[lin].push_back(cand);
        }
    }
}

size_t Univers::getTotalCells(){
    return nb_cellules;
}

Cellule& Univers::cellule(const std::vector<size_t>& idx) {
    size_t lin = linearIndex(idx);
    return cellules[lin];
}


void Univers::setSigma(double sigma){
    this->sigma = sigma;
}

void Univers::setR_cut(double r_cut){
    this->r_cut = r_cut;
}