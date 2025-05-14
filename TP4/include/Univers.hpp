#ifndef UNIVERS_HPP
#define UNIVERS_HPP
#include "cellule.hpp"

class Univers{
    private:
        size_t dim;
        vector<size_t> dimensions;
        double r_cut;
        vector<Cellule> cellules;
        double sigma;
        vector<vector<vector<size_t>>> voisinage;
        size_t nb_cellules;
    public:
        Univers(const vector<double>& dimensions, double sigma, double r_cut);
        void setSigma(double sigma );
        void setR_cut(double r_cut);

        void  initIndices(size_t nb_cellules);
        size_t linearIndex(const vector<size_t>& idx) const;
        Cellule& cellule(const vector<size_t>& idx);
        void buildVoisinage(size_t nb_Cellues);
        size_t getTotalCells();
        vector<vector <size_t>> getVoisinage(size_t indx);
        vector<size_t> getDimensions(); 
        
};

#endif