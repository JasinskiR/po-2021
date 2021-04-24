#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr2D_gnuplot_api.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "Wektor2D.hh"

using namespace std;

int main(int argc, char** argv) {
  Prostokat tmp;
  if (tmp.otworz(argv[1])) { 
    //is.good ignore itp. dopisac obsluge bledow
  }


  // drawNS::Draw2DAPI* rysownik = new drawNS::APIGnuPlot2D(-10, 10, -10, 10,
  // 0);

  // delete rysownik;
}