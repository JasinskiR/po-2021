#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

template <unsigned int SIZE>
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

  const double &operator[](unsigned int indeks) const;  // getter
  double &operator[](unsigned int indeks);              // setter
};

template <unsigned int SIZE>
std::istream &operator>>(std::istream &strm, Wektor<SIZE> &Wektor);

template <unsigned int SIZE>
std::ostream &operator<<(std::ostream &strm, const Wektor<SIZE> &Wektor);

#endif
