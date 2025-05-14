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
    out << "Vecteur : ";
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

Vecteur testVecteur() {
    cout << "===== TEST CONSTRUCTEURS =====" << endl;
    Vecteur v1;
    Vecteur v2(1, 2, 3);
    Vecteur v3(v2);

    cout << "v1 : " << v1 << endl;
    cout << "v2 : " << v2 << endl;
    cout << "v3 (copie de v2) : " << v3 << endl;

    cout << "\n===== TEST OPÉRATEUR + =====" << endl;
    Vecteur v4 = v2 + v3;
    cout << "v4 (v2 + v3) : " << v4 << endl;

    cout << "\n===== TEST OPÉRATEUR * (produit scalaire) =====" << endl;
    double produitScalaire = v2 * v3;
    cout << "Produit scalaire v2 * v3 : " << produitScalaire << endl;

    cout << "\n===== TEST OPÉRATEUR * (multiplication scalaire) =====" << endl;
    Vecteur v5 = v2 * 2;
    cout << "v5 (v2 * 2) : " << v5 << endl;

    cout << "\n===== TEST OPÉRATEUR *= =====" << endl;
    v2 *= 3;
    cout << "v2 après v2 *= 3 : " << v2 << endl;

    cout << "\n===== TEST OPÉRATEUR [] =====" << endl;
    cout << "Coordonnée x de v2 : " << v2[0] << endl;
    cout << "Coordonnée y de v2 : " << v2[1] << endl;
    cout << "Coordonnée z de v2 : " << v2[2] << endl;

    cout << "\n===== TEST MODIFICATION PAR [] =====" << endl;
    v2[0] = 10;
    v2[1] = 20;
    v2[2] = 30;
    cout << "v2 modifié : " << v2 << endl;

    cout << "\n===== TEST EXCEPTION OPÉRATEUR [] =====" << endl;
    try {
        cout << v2[3] << endl;
    } catch (const out_of_range& e) {
        cout << "Exception attrapée : " << e.what() << endl;
    }

    cout << "\n===== TEST ENTRÉE UTILISATEUR =====" << endl;
    cout << "Entrez un vecteur (x y z) : ";
    Vecteur v6;
    cin >> v6;
    cout << "Vous avez entré : " << v6 << endl;
    return v6;
}