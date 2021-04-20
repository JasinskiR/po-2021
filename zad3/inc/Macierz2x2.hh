#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>

#include "Wektor2D.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz2x2 {
  std::array<Wektor2D, 2> Macierz;
  double kat; //stopnie

 public:
  Macierz2x2();
  Macierz2x2(Wektor2D wiersz1, Wektor2D wiersz2) : Macierz{wiersz1, wiersz2} {};
  explicit Macierz2x2(double _kat) { kat = _kat; };
  Wektor2D operator*(const Wektor2D &Arg2) const;
  Macierz2x2 operator*(const Macierz2x2 &Arg2) const;
  const Wektor2D &operator[](int indeks) const;
  Wektor2D &operator[](int indeks);
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream &operator<<(std::ostream &strm, const Macierz2x2 &Macierz);

#endif
