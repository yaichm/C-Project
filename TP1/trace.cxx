// Code élémentaire pour le calcul de la trace d'une matrice.
/// Printemps 2022
/// Objectif : manipuler les éléments de base du C++
///            utiliser des outils de profiling et de débogage
/// ref: l'exercice est inspiré très largement de ressources WWW

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

double **initialization(int);
double *fill_vectors(double *, int);
void print_matrix(double **, int);
double *trace(double **, int);


/// Driver principal pour le calcul de la tace d'une matrice
int main() {
  int i, n;
  double **matrix;
  double *sum;

  cout << endl << "Enter the Dimension for a square matrix: " << flush;
  cin >> n;
  matrix = initialization(n);
  for (i = 1; i < n; i++)
    matrix[i] = fill_vectors(matrix[i], n);
  sum = trace(matrix, n);
  print_matrix(matrix, n);
  cout << endl << "Sum of the diagonal elements are: " << *sum<< endl;
  return 0;
}

/// @brief Routine d'initialization qui permet d'allouer la mémoire pour une
///        matrice carrée de taille n et renvoie un pointer vers
///        la matrice allouée
/// @param[in] n est la taille souhaitée de la matrice
/// @return    Renvoie le pointeur vers la matrice allouée
double **initialization(int n){
  double **matrice = (double **) calloc(n,sizeof(double *));
  if(!matrice) return NULL;
  for (int i = 0;i<n;++i){
      matrice[i] = (double * ) calloc(n,sizeof(double));
  }
  return matrice;
}

/// @brief Intitialise un vecteur avec des valeurs aléatoires comprises
///        entre dans l'intervalle [-10;10]
/// @param[in] vec est le vecteur à initialiser
/// @param[in] n   est la taille du vecteur à initialiser
/// @return    Renvoie le vecteur initialisé.
double *fill_vectors(double *vector, int n){
  for(int i=0;i<n;++i){
      vector[i] = rand() % 21 -10;
  }
  return vector;
}

/// @brief Affiche les éléments d'une matrice de taille n
/// @param[in] matrix est la matrice à afficher
/// @param[in] n est la taille de la matrice à afficher
void print_matrix(double **mat,int n){
  for(int i = 0 ; i<n ; ++i){
      for(int j = 0; j<n ; ++j){
          cout << mat[i][j] << " " ;
      }
      cout << "\n" << endl;
  }
}

/// @brief Calcul la trace d'une matrice
/// @param[in] matrix est la matrice dont on souhaite connaître la trace.
/// @param[in] n est la taille de la matrice.
double *trace(double **mat,int n){
  double *sum = new double(0);
  for(int i=0;i<n;++i){
      *sum += mat[i][i];
  }
  return sum;
}