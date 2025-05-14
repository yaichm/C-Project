#include <iostream>
#include <vector>
#include "Univers.hpp"

int main() {
    // Dimensions de l'univers (par exemple, 10.0 unités de long pour chaque dimension)
    vector<double> dimensions = {10.0, 10.0};
    double sigma = 1.0;   // Valeur arbitraire pour sigma
    double r_cut = 2.0;   // Valeur arbitraire pour r_cut (distance maximale d'interaction)

    // Création d'un objet Univers avec les paramètres définis
    Univers Univers(dimensions, sigma, r_cut);

    // Construction du voisinage pour toutes les cellules
    Univers.buildVoisinage(Univers.getTotalCells());

    // Affichage des voisins pour la première cellule (indice 0)
    const auto& voisins = Univers.getVoisinage(0);
    cout << "Voisins de la cellule (0, 0) :\n";
    for (const auto& voisin : voisins) {
        cout << "(";
        for (size_t d = 0; d < voisin.size(); ++d) {
            cout << voisin[d];
            if (d < voisin.size() - 1) cout << ", ";
        }
        cout << ")\n";
    }

    // Affichage des indices de la cellule 0
    cout << "\nIndices de la cellule 0 : ";
    const auto& idx = Univers.cellule({0, 0}).getIndices();
    for (size_t d = 0; d < idx.size(); ++d) {
        cout << idx[d] << " ";
    }
    cout << endl;

    return 0;
}
