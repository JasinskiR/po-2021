#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr2D_gnuplot_api.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "Wektor2D.hh"

using namespace std;

int main() { 
  Wektor2D W1(2,1);
  Wektor2D W2(5,2);
  Macierz2x2 M1(W2,W2);
  Macierz2x2 M2(W1,W1);
  cout << W1 + M1 * M2 * W2; 
}
