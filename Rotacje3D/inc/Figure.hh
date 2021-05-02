#ifndef FIGURE_HH
#define FIGURE_HH

#include <fstream>
#include <iostream>
#include <limits>

#include "Dr2D_gnuplot_api.hh"
#include "MacierzRot.hh"

template <unsigned int SIZE>
class Figura {
 private:
  std::array<Wektor<SIZE>, 4> Wierzcholki;

 public:
  Figura() = default;
  Figura(Wektor<SIZE> LG, Wektor<SIZE> PG, Wektor<SIZE> PD, Wektor<SIZE> LD);
  void rotacja(double kat_stopnie);
  void translacje(Wektor<SIZE> W);
  void rysuj(std::shared_ptr<drawNS::Draw2DAPI> rysownik);
  const Wektor<SIZE> &operator[](unsigned int indeks) const;
  Wektor<SIZE> &operator[](unsigned int indeks);
  drawNS::Point2D konwertuj(Wektor<SIZE> W);
  bool wczytaj(std::string name);
  bool otworz(std::string name);
  bool czy_Figura();
  std::size_t l_punktow() const { return Wierzcholki.size(); };
};

template <unsigned int SIZE>
std::ostream &operator<<(std::ostream &strm, const Figura<SIZE> &wierzcholki);
template <unsigned int SIZE>
std::istream &operator>>(std::istream &strm, Figura<SIZE> &wierzcholki);

#include "Figure.cpp"
#endif
