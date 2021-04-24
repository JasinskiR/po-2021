#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <fstream>
#include <iostream>
#include <limits>

#include "Dr2D_gnuplot_api.hh"
#include "Macierz2x2.hh"

class Prostokat {
 private:
  std::array<Wektor2D, 4> Wierzcholki;

 public:
  Prostokat();
  Prostokat(Wektor2D LG, Wektor2D LD, Wektor2D PD, Wektor2D PG);
  void rotacja(double kat_stopnie);
  void translacje(Wektor2D W);
  void rysuj(std::shared_ptr<drawNS::Draw2DAPI> rysownik);
  const Wektor2D &operator[](int indeks) const;
  drawNS::Point2D konwertuj(Wektor2D W);
  bool otworz(std::string name);
  bool czy_prostokat();
};

std::ostream &operator<<(std::ostream &strm, const Prostokat &wierzcholki);

#endif
