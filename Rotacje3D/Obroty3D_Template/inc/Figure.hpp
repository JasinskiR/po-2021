#ifndef FIGURE_H
#define FIGURE_H

#include <fstream>
#include <iostream>
#include <limits>

#include "Dr3D_gnuplot_api.hpp"
#include "MacierzRot.hpp"

class Figura {
 private:
  std::array<Wektor<3>, 8> Wierzcholki;
  std::fstream read;
  drawNS::Point3D konwertuj(Wektor<3> W);

 public:
  Figura() = default;
  Figura(std::array<Wektor<3>, 8> W);
  void rotacja(double kat_stopnie, OS os);
  void translacje(Wektor<3> W);
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik);

  const Wektor<3> &operator[](uint32_t indeks) const;
  Wektor<3> &operator[](uint32_t indeks);

  bool wczytaj();
  bool otworz(std::string name);
  bool czy_Figura();

  std::size_t l_punktow() const { return Wierzcholki.size(); };
};

std::ostream &operator<<(std::ostream &strm, const Figura &wierzcholki);
std::istream &operator>>(std::istream &strm, Figura &wierzcholki);

#endif
