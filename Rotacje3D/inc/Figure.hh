#ifndef FIGURE_HH
#define FIGURE_HH

#include <fstream>
#include <iostream>
#include <limits>

#include "Dr2D_gnuplot_api.hh"
#include "MacierzRot.hh"

class Figura {
 private:
  std::array<Wektor<2>, 4> Wierzcholki;
  std::fstream read;

 public:
  Figura() = default;
  Figura(Wektor<2> LG, Wektor<2> PG, Wektor<2> PD, Wektor<2> LD);
  void rotacja(double kat_stopnie);
  void translacje(Wektor<2> W);
  void rysuj(std::shared_ptr<drawNS::Draw2DAPI> rysownik);
  const Wektor<2> &operator[](unsigned int indeks) const;
  Wektor<2> &operator[](unsigned int indeks);
  drawNS::Point2D konwertuj(Wektor<2> W);
  bool wczytaj();
  bool otworz(std::string name);
  bool czy_Figura();
  std::size_t l_punktow() const { return Wierzcholki.size(); };
};

std::ostream &operator<<(std::ostream &strm, const Figura &wierzcholki);
std::istream &operator>>(std::istream &strm, Figura &wierzcholki);

//#include "Figure.cpp"
#endif
