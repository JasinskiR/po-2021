#ifndef MACIERZROT_HH
#define MACIERZROT_HH

#include <iostream>

#include "Wektor.hh"

enum OS { OX, OY, OZ };

template <unsigned int SIZE>
class MacierzRot {
  std::array<Wektor<SIZE>, SIZE> Macierz;

 public:
  MacierzRot();
  MacierzRot(std::array<Wektor<SIZE>, SIZE> arg) : Macierz(arg){};
  MacierzRot(const double &kat, enum OS);
  Wektor<SIZE> operator*(const Wektor<SIZE> &Arg2) const;
  MacierzRot<SIZE> operator*(const MacierzRot<SIZE> &Arg2) const;
  MacierzRot<SIZE> transponowanie() const; 
  const Wektor<SIZE> &operator[](unsigned int indeks) const;
  Wektor<SIZE> &operator[](unsigned int indeks);
};

template <unsigned int SIZE>
std::ostream &operator<<(std::ostream &strm, const MacierzRot<SIZE> &Macierz);

//#include "MacierzRot.cpp"
#endif
