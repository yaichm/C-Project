/// Code élémentaire pour le calcul de la trace d'une matrice.
/// Printemps 2022
/// Objectif : manipuler les éléments de base du C++
///            utiliser des outils de profiling et de débogage
/// ref: l'exercice est inspiré très largement de ressources WWW

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;


double *SolveExplicite(int n);
double *SolveImplicite(int n);
double *SolveExpliciteEDO(int n);


/// Driver principal pour le calcul de la tace d'une matrice
int main() {

  cout << endl << "the solution for Euler explicite " << endl << flush;
  double *Sol1 = SolveExplicite(40);
  for(int i=0;i<50;++i){
    cout << Sol1[i] << " | ";
  }
  cout << endl << "the solution for Euler implicite " << endl << flush;
  double *Sol2 = SolveImplicite(40);
  for(int i=0;i<50;++i){
    cout << Sol2[i] << " | ";
  }
  cout << endl << "the solution for Euler explicite EDO " << endl << flush;
  double *Sol3 = SolveExpliciteEDO(40);
  for(int i=0;i<50;++i){
    cout << Sol3[i] << " | ";
  }
  cout << endl;

  return 0;
}


double *SolveExplicite(int n){
  double h = 1.0/n;
  double *Sortie = (double *) calloc(n,sizeof(double));
  Sortie[0] = 1;
  for(int i=1;i<n;++i){
      Sortie[i] = Sortie[i-1]*(2*h*h*(i-1) + 1);
  }
  return Sortie;
}

double *SolveImplicite(int n){
  double h = 1.0/n;
  double *Sortie = (double *) calloc(n,sizeof(double));
  Sortie[0] = 1;
  for(int i=1;i<n;++i){
      Sortie[i] = Sortie[i-1]/(1 + 2*h*h*i);
  }
  return Sortie;
}

double *SolveExpliciteEDO(int n){
  double h = 1.0/n;
  double *Sortie = (double *) calloc(n,sizeof(double));
  Sortie[0] = 1;
  for(int i=1;i<n;++i){
      Sortie[i] = Sortie[i-1]*(50*h*cos((i-1)*h));
  }
  return Sortie;
}