#include "LZespolona.hh"

#include <cmath>

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator+(const LZespolona &Skl2) const {
  LZespolona Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator-(const LZespolona &Skl2) const {
  LZespolona Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator*(const LZespolona &Skl2) const {
  LZespolona Wynik;

  Wynik.re = re * Skl2.re - im * Skl2.im;
  Wynik.im = re * Skl2.im + Skl2.re * im;

  return Wynik;
}

LZespolona LZespolona::sprzezenie() const {
  LZespolona Wynik;
  Wynik.re = re;
  Wynik.im = (-1) * im;

  return Wynik;
}

double LZespolona::modul() const {
  double wynik;
  wynik = sqrt(re * re + im * im);

  return wynik;
}

LZespolona LZespolona::operator/(const double &dzielnik) const {
  LZespolona Wynik;
  if (dzielnik == 0.00) {
    std::cerr << "Blad krytyczny, dzielenie przez 0" << std::endl;
    exit(1);
  }
  Wynik.re = re / dzielnik;
  Wynik.im = im / dzielnik;

  return Wynik;
}

LZespolona LZespolona::operator/(const LZespolona &Skl2) const {
  LZespolona Wynik, Licznik;
  Licznik = *this * (Skl2.sprzezenie());
  Wynik = Licznik / pow(Skl2.modul(), 2);

  return Wynik;
}

bool LZespolona ::operator==(const LZespolona &Skl2) const {
  double epsilon = 0.01;
  if (epsilon < fabs(re - Skl2.re)) return false;
  if (epsilon < fabs(im - Skl2.im)) return false;

  return true;
}

bool LZespolona::operator!=(const LZespolona &Skl2) const {
  return !(*this == Skl2);
}

std::ostream &operator<<(std::ostream &strm, const LZespolona &L1) {
  strm << "(" << L1.get_re() << std::showpos << L1.get_im() << std::noshowpos
       << "i)";
  return strm;
}

std::istream &operator>>(std::istream &strm, LZespolona &L1) {
  char znak;
  double _re, _im;
  strm >> znak;
  if (znak != '(') {
    strm.setstate(std::ios::failbit);
  }
  strm >> _re;
  L1.set_re(_re);
  strm >> _im;
  L1.set_im(_im);
  strm >> znak;
  if (znak != 'i') {
    strm.setstate(std::ios::failbit);
  }
  strm >> znak;
  if (znak != ')') {
    strm.setstate(std::ios::failbit);
  }

  return strm;
}
