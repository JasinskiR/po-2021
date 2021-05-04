#ifndef WEKTOR_H
#define WEKTOR_H

#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

template <uint32_t SIZE>
class Wektor {
 private:
  std::array<double, SIZE> cords;

 public:
  Wektor(std::array<double, SIZE> arg) : cords(arg){};
  Wektor() = default;
  Wektor<SIZE> operator+(const Wektor<SIZE> &Arg2) const;
  Wektor<SIZE> operator-(const Wektor<SIZE> &Arg2) const;
  Wektor<SIZE> operator*(const double &Arg2) const;
  //Wektor<SIZE> operator*(const Wektor<SIZE> &Arg2) const;
  double operator*(const Wektor<SIZE> &Arg2) const;
  double dlugosc() const;

  const double &operator[](uint32_t indeks) const;  // getter
  double &operator[](uint32_t indeks);              // setter
};

template <uint32_t SIZE>
std::istream &operator>>(std::istream &strm, Wektor<SIZE> &Wektor);

template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Wektor<SIZE> &Wektor);


#endif
