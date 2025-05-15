#include <gtest/gtest.h>
#include "vecteur.hpp"

// Test du constructeur par défaut
TEST(VecteurTest, ConstructeurParDef) {
    Vecteur v;
    EXPECT_DOUBLE_EQ(v[0], 0.0);
    EXPECT_DOUBLE_EQ(v[1], 0.0);
    EXPECT_DOUBLE_EQ(v[2], 0.0);
}

// Test du constructeur avec paramètres
TEST(VecteurTest, ConstructuerParam) {
    Vecteur v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v[0], 1.0);
    EXPECT_DOUBLE_EQ(v[1], 2.0);
    EXPECT_DOUBLE_EQ(v[2], 3.0);
}

// Test de l'opérateur +
TEST(VecteurTest, OperateurAddition) {
    Vecteur v1(1.0, 2.0, 3.0);
    Vecteur v2(4.0, 5.0, 6.0);
    Vecteur v3 = v1 + v2;
    EXPECT_DOUBLE_EQ(v3[0], 5.0);
    EXPECT_DOUBLE_EQ(v3[1], 7.0);
    EXPECT_DOUBLE_EQ(v3[2], 9.0);
}

// Test de l'opérateur * (produit scalaire)
TEST(VecteurTest, ProduitScalaire) {
    Vecteur v1(1.0, 2.0, 3.0);
    Vecteur v2(4.0, 5.0, 6.0);
    EXPECT_DOUBLE_EQ(v1 * v2, 32.0);
}

//Test de l'opérateur +=
TEST(VecteurTest, ajoutEgal){
    Vecteur v1(1.0, 2.0, 3.0);
    Vecteur v2(1.0, 2.0, 3.0);
    v2 +=v1;
    EXPECT_DOUBLE_EQ(v2[0], 2);
    EXPECT_DOUBLE_EQ(v2[1], 4);
    EXPECT_DOUBLE_EQ(v2[2], 6);
}

//Test de l'opérateur -=
TEST(VecteurTest, moinsequel){
    Vecteur v1(1.0, 2.0, 3.0);
    Vecteur v2(2.0, 1.0, 3.0);
    v2 -=v1;
    EXPECT_DOUBLE_EQ(v2[0], 1.0);
    EXPECT_DOUBLE_EQ(v2[1], -1.0);
    EXPECT_DOUBLE_EQ(v2[2], 0.0);
}

// Test de multiplication scalaire
TEST(VecteurTest, ProduitParConstant) {
    Vecteur v(1.0, 2.0, 3.0);
    Vecteur result = v * 2.0;
    EXPECT_DOUBLE_EQ(result[0], 2.0);
    EXPECT_DOUBLE_EQ(result[1], 4.0);
    EXPECT_DOUBLE_EQ(result[2], 6.0);
}

// Test de l'opérateur []
TEST(VecteurTest, OperateurIndice) {
    Vecteur v(10.0, 20.0, 30.0);
    EXPECT_DOUBLE_EQ(v[0], 10.0);
    EXPECT_DOUBLE_EQ(v[1], 20.0);
    EXPECT_DOUBLE_EQ(v[2], 30.0);
}

// Test de l'exception [] hors limite
TEST(VecteurTest, IndexOutOfBounds) {
    Vecteur v;
    EXPECT_THROW(v[3], std::out_of_range);
}

// Test de l’opérateur *=
TEST(VecteurTest, MultiplyAssign) {
    Vecteur v(1, 2, 3);
    v *= 2;
    EXPECT_DOUBLE_EQ(v[0], 2.0);
    EXPECT_DOUBLE_EQ(v[1], 4.0);
    EXPECT_DOUBLE_EQ(v[2], 6.0);
}

