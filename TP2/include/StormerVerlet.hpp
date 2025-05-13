#ifndef STORMERVERLET_HPP
#define STORMERVERLET_HPP

#include "ParticuleA.hpp"
#include <vector>
#include <cmath>
#include <fstream>

class StormerVerlet {
public:
    std::vector<std::pair<double, double>> force_grav(const std::vector<ParticuleA> &parList, int n);
    std::vector<std::vector<std::pair<double, double>>> algoStr(double dt, double dfin, std::vector<ParticuleA> parList);
};

#endif
