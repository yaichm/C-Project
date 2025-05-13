#include "univers.h"
#include "vecteur.h"
#include "particuleA.hpp"
#include "StormerVerlet.hpp"

using namespace std;


Univers* creer_univers(int k){
    Univers* monUnivers=new Univers();

    const int N = pow(2,k);  //  (2^k)^3 particules
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                double x = static_cast<double>(i) / (N - 1);
                double y = static_cast<double>(j) / (N - 1);
                double z = static_cast<double>(k) / (N - 1);
                
                Vecteur vect_pois=Vecteur (x,y,z);
                Vecteur vect_vites=Vecteur (1,1,1);
                Vecteur vect_force=Vecteur (1,1,1);
                double masse=1; // symbolique 

                ParticuleA p = ParticuleA(masse,vect_pois,vect_vites,vect_force);
                monUnivers->ajouterParticule(p);
            }
        }
    }
    return monUnivers;
}
int main() {
    Univers *monUnivers = creer_univers(3);
    monUnivers->afficher();
    for (int i = 3 ; i < 8 ; i++){
        creer_univers(i);

    }
    return 0;
}