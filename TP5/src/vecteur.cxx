#include "vecteur.hpp"

using namespace std;

// Constructeurs
Vecteur::Vecteur() : x(0), y(0), z(0) {}

Vecteur::Vecteur(double a, double b, double c) : x(a), y(b), z(c) {}

Vecteur::Vecteur(const Vecteur& v) : x(v.x), y(v.y), z(v.z) {}

// Opérateurs d'accès
double Vecteur::operator[](int i) const {
    if (i == 0) return x;
    else if (i == 1) return y;
    else if (i == 2) return z;
    else throw out_of_range("L'indice " + to_string(i) + " est hors limite.");
}

double& Vecteur::operator[](int i) {
    if (i == 0) return x;
    else if (i == 1) return y;
    else if (i == 2) return z;
    else throw out_of_range("L'indice " + to_string(i) + " est hors limite.");
}

// Méthodes de modification
Vecteur Vecteur::setPo(double xa, double ya, double za) {
    x = xa;
    y = ya;
    z = za;
    return *this;  // On retourne l'objet lui-même mis à jour
}


// Opérateurs arithmétiques
Vecteur& Vecteur::operator=(const Vecteur& v) {
    if (this != &v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

Vecteur& Vecteur::operator*=(double d) {
    x *= d;
    y *= d;
    z *= d;
    return *this;
}

Vecteur Vecteur::operator+(const Vecteur& v) const {
    return Vecteur(x + v.x, y + v.y, z + v.z);
}

double Vecteur::operator*(const Vecteur& v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vecteur Vecteur::operator*(double d) const {
    return Vecteur(d * x, d * y, d * z);
}


Vecteur& Vecteur::operator+=(const Vecteur& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

// Fonctions amies
ostream& operator<<(ostream& out, const Vecteur& v) {
    for (int i = 0; i < 3; i++) {
        out << v[i] << " ";
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, Vecteur& v) {
    for (int i = 0; i < 3; i++) {
        in >> v[i];
    }
    return in;
}

