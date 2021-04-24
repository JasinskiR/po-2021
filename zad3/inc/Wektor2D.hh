#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <array>
#include <cmath>
#include <iostream>
#include <limits>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D {
 private:
  std::array<double, 2> Wektor;

 public:
  Wektor2D(double x, double y) : Wektor{x, y} {};
  Wektor2D() : Wektor2D(0, 0){};
  Wektor2D operator+(const Wektor2D &Arg2) const;
  Wektor2D operator-(const Wektor2D &Arg2) const;
  Wektor2D operator*(const double &Arg2) const;
  double operator*(const Wektor2D &Arg2) const;
  double dlugosc() const;

  const double &operator[](int indeks) const;  // getter
  double &operator[](int indeks);              // setter wektor[0]=3.00;
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream &operator>>(std::istream &strm, Wektor2D &Wektor);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream &operator<<(std::ostream &strm, const Wektor2D &Wektor);

#endif
