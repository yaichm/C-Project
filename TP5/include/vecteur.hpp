#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <stdexcept>

class Vecteur {
private:
    double x, y, z;  // Coordonnées du vecteur

public:
    // Constructeur par défaut
    Vecteur() ;

    // Constructeur par copie
    Vecteur& operator=(const Vecteur& v);


    // Constructeur avec paramètres
    Vecteur(double a, double b, double c) ;

    // Constructeur par copie
    Vecteur(const Vecteur &v);

    // Accesseur (lecture seule) et modification des coordonnées par indice
    double operator[](int i) const;
    double &operator[](int i);

    // Méthode pour modifier les coordonnées
    Vecteur setPo(double xa, double ya, double za);

    // Opérateur *= pour multiplication par un scalaire
    Vecteur &operator*=(double d);

    // Opérateur + pour additionner deux vecteurs
    Vecteur operator+(const Vecteur &v) const;

    // Produit scalaire
    double operator*(const Vecteur &v) const;

    Vecteur operator*(double d) const;
    Vecteur &operator+=(const Vecteur &vect);
    Vecteur &operator-=(const Vecteur &vect);

    friend std::ostream &operator<<(std::ostream &out, const Vecteur &v);
    friend std::istream &operator>>(std::istream &in, Vecteur &v);
    
};

Vecteur testVecteur();



#endif 