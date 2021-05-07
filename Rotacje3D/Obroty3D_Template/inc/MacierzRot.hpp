#ifndef MACIERZROT_HPP
#define MACIERZROT_HPP

#include <iostream>

#include "Wektor.hpp"

enum OS { OX, OY, OZ };

template <uint32_t SIZE>
class MacierzRot {
  std::array<Wektor<SIZE>, SIZE> Macierz;
  MacierzRot<SIZE> transponowanie() const;

 public:
  MacierzRot();
  MacierzRot(const double &kat, enum OS);
  Wektor<SIZE> operator*(const Wektor<SIZE> &Arg2) const;
  MacierzRot<SIZE> operator*(const MacierzRot<SIZE> &Arg2) const;
  const Wektor<SIZE> &operator[](uint32_t indeks) const;
};

template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const MacierzRot<SIZE> &Macierz);

std::istream &operator>>(std::istream &strm, OS &os);

#endif
