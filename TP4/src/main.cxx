#include <iostream>
#include "Univers.hpp"
#include "cellule.hpp"

using namespace std;

int main() {
    // Dimensions de l'univers (par exemple, 10.0 unités de long pour chaque dimension)
    std::vector<double> dimensions = {10.0, 10.0};
    double sigma = 1.0;   // Valeur arbitraire pour sigma
    double r_cut = 2.0;   // Valeur arbitraire pour r_cut (distance maximale d'interaction)

    // Création d'un objet Univers avec les paramètres définis
    Univers monUnivers(dimensions, sigma, r_cut);

    // Affichage des dimensions et du nombre total de cellules
    std::cout << "Dimensions de l'univers : ";
    for (auto dim : monUnivers.getDimensions()) {
        std::cout << dim << " ";
    }
    std::cout << std::endl;

    std::cout << "Nombre total de cellules : " << monUnivers.getTotalCells() << std::endl;

    // Affichage des indices de la première cellule
    vector<size_t> idx = {1, 0};
    auto& cellule0 = monUnivers.cellule(idx);
    cout << "Indices de la cellule (1, 0) : ";
    for (auto val : cellule0.getIndices()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test de la méthode getVoisinage pour la première cellule
    monUnivers.buildVoisinage(monUnivers.getTotalCells());

    // printer les voisins de la premiere cellule
    size_t indx = 8;
    for (auto var : monUnivers.getVoisinage(indx))
    {
        cout << "Le voisin \n";
        cout << var <<endl;
    }
    return 0;
}
