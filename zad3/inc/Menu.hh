#ifndef MENU_HH
#define MENU_HH

#include <cctype>
#include <iostream>
#include <cstdlib>

#include "Dr2D_gnuplot_api.hh"
#include "Prostokat.hh"

class Menu {
 private:
  char wybor;

 public:
  void wyswietl(Prostokat prostokat);
};

std::ostream &operator<<(std::ostream &strm, const Menu &Menu);

#endif