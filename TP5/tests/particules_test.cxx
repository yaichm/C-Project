#include <gtest/gtest.h>
#include "Particule.hpp"  


TEST(ParticuleATest, ConstructorPrticules) {
    Vecteur pos{1.0, 2.0, 3.0};
    Vecteur vit{0.1, 0.2, 0.3};
    Vecteur forc{0.0, 0.0, 0.0};
    double masse = 5.0;

    ParticuleA p(masse, pos, vit, forc);

    EXPECT_DOUBLE_EQ(p.getMasse(), masse);
    EXPECT_EQ(p.getPosition(), pos);
    EXPECT_EQ(p.getVitesse(), vit);
    EXPECT_EQ(p.getForce(), forc);
}

TEST(ParticuleATest, SetPosition) {
    double masse = 2.0;
    Vecteur pos{0,0,0};
    Vecteur vit{1,0,0};
    Vecteur forc{0,2,0};  // force en y

    ParticuleA p(masse, pos, vit, forc);
    double dt = 1.0;

    Vecteur pos_expected = pos + vit * dt + forc * (0.5 * dt * dt / masse);
    Vecteur new_pos = p.setPosition(dt);

    EXPECT_EQ(new_pos, pos_expected);
    EXPECT_EQ(p.getPosition(), pos_expected);
}

TEST(ParticuleATest, SetVitesseUpdatesCorrectly) {
    double masse = 2.0;
    Vecteur pos{0,0,0};
    Vecteur vit{1,1,1};
    Vecteur forc{2,2,2};
    Vecteur old_forc{1,1,1};

    ParticuleA p(masse, pos, vit, forc);
    double dt = 1.0;

    Vecteur vitesse_expected = vit + (forc + old_forc) * (0.5 * dt / masse);
    Vecteur new_vit = p.setVitesse(dt, old_forc);

    EXPECT_EQ(new_vit, vitesse_expected);
    EXPECT_EQ(p.getVitesse(), vitesse_expected);
}

TEST(ParticuleATest, SetForceUpdatesCorrectly) {
    double masse = 2.0;
    Vecteur pos{0,0,0};
    Vecteur vit{0,0,0};
    Vecteur forc{0,0,0};

    ParticuleA p(masse, pos, vit, forc);

    Vecteur new_force{5,5,5};
    Vecteur returned_force = p.setForce(new_force);

    EXPECT_EQ(returned_force, new_force);
    EXPECT_EQ(p.getForce(), new_force);
}

TEST(ParticuleATest, AfficheParmReturnsCorrectString) {
    Vecteur pos{1.0, 2.0, 3.0};
    ParticuleA p(1.0, pos, Vecteur{0,0,0}, Vecteur{0,0,0});
    std::string expected = "(1, 2, 3)";  // selon la précision et l'implémentation du flux

    EXPECT_EQ(p.affiche_parm(), expected);
}

// Test save (on va tester que la méthode retourne true si le fichier est valide)
TEST(ParticuleATest, SaveReturnsTrueIfFileIsOpen) {
    Vecteur pos{1.0, 2.0, 3.0};
    ParticuleA p(1.0, pos, Vecteur{0,0,0}, Vecteur{0,0,0});

    std::ofstream file("test_save.txt");
    ASSERT_TRUE(file.is_open());

    bool result = p.save(file, 0.1, 1);
    file.close();

    EXPECT_TRUE(result);
}

// Test save retourne false si le fichier n'est pas ouvert
TEST(ParticuleATest, SaveReturnsFalseIfFileIsNotOpen) {
    Vecteur pos{1.0, 2.0, 3.0};
    ParticuleA p(1.0, pos, Vecteur{0,0,0}, Vecteur{0,0,0});

    std::ofstream file;  // non ouvert
    bool result = p.save(file, 0.1, 1);

    EXPECT_FALSE(result);
}
