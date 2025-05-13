#include "ParticuleA.hpp"
#include "StormerVerlet.hpp"
#include <list>
#include <random>
#include <fstream>

int main() {
    std::list<ParticuleA> particuls;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0,1.0);

    std::ofstream file("rst.txt");
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier rst.txt !" << std::endl;
        return 1;
    }

    std::vector<ParticuleA> particulList = {
        {1.0, 0, 0, 0, 0},
        {3.0e-6, 0, 1, -1, 0}
    };

    double dt = 50, tend = 468.5;
    StormerVerlet solver;

    auto resultats = solver.algoStr(dt, tend, particulList);

    for (const auto& positions : resultats) {
        file << "Nouvelle position\n";
        for (const auto& pos : positions) {
            file << pos.first << " " << pos.second << "\n";
        }
    }
    file.close();
}
