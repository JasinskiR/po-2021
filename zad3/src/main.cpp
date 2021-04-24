#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr2D_gnuplot_api.hh"
#include "Macierz2x2.hh"
#include "Menu.hh"
#include "Prostokat.hh"
#include "Wektor2D.hh"

using namespace std;

int main(int argc, char** argv) {
  Prostokat tmp, rectangle;
  string _wybor;
  if (argc > 1) {
    if (tmp.otworz(argv[1])) {
      Menu menu;
      menu.wyswietl(tmp);
    }
  }
}