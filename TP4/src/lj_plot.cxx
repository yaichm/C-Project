#include <cmath>
#include <vector>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

// Potentiel LJ
double lj(double r) {
    double sr = 1.0/r;
    double sr6 = std::pow(sr,6);
    return 4.0*(sr6*sr6 - sr6);
}

int main(){
    int N = 500;
    std::vector<double> r(N), V(N);
    for(int i=0; i<N; ++i){
        r[i] = 0.8 + (3.0-0.8)*i/(N-1);
        V[i] = lj(r[i]);
    }

    plt::figure_size(800,400);
    plt::plot(r, V, {{"color","orange"},{"label","LJ V(r)"}});
    plt::title("Potentiel de Lennard-Jones");
    plt::xlabel("r");
    plt::ylabel("V(r)");
    plt::legend();
    plt::grid(true);
    plt::show();
    return 0;
}

