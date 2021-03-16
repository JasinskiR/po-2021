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
LZespolona operator+(LZespolona &Skl1, LZespolona &Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator-(LZespolona &Skl1, LZespolona &Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator*(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;

  return Wynik;
}

LZespolona sprzezenie(LZespolona &Zespolona) {
  LZespolona Wynik;
  Wynik.re = Zespolona.re;
  Wynik.im = (-1) * Zespolona.im;

  return Wynik;
}

double modul(LZespolona &Zespolona) {
  double wynik;
  wynik = sqrt(Zespolona.re * Zespolona.re + Zespolona.im * Zespolona.im);

  return wynik;
}
LZespolona operator/(LZespolona &Licznik, double dzielnik) {
  LZespolona Wynik;
  if (dzielnik == 0.00) {
    std::cerr << "Blad krytyczny, dzielenie przez 0" << std::endl;
    exit(1);
  }
  Wynik.re = Licznik.re / dzielnik;
  Wynik.im = Licznik.im / dzielnik;

  return Wynik;
}
LZespolona operator/(LZespolona &Skl1, LZespolona &Skl2) {
  LZespolona Wynik, Licznik;
  Licznik = Skl1 * (sprzezenie(Skl2));
  Wynik = Licznik / pow(modul(Skl2), 2);

  return Wynik;
}

LZespolona inicjuj(LZespolona &L1, double x, double y) {
  L1.re = x;
  L1.im = y;

  return L1;
}

bool operator==(const LZespolona &Skl1, const LZespolona &Skl2) {
  double epsilon = 0.000000001;
  if (epsilon < abs(Skl1.re - Skl2.re)) return false;
  if (epsilon < abs(Skl1.im - Skl2.im)) return false;

  return true;
}

bool operator!=(const LZespolona &Skl1, const LZespolona &Skl2) {
  return !(Skl1==Skl2);
}

std::ostream& operator<<(std::ostream& strm, const LZespolona& L1) {
  strm<<"("<<L1.re<<std::showpos<<L1.im<<std::noshowpos<<"i)";
  return strm;
}

std::istream& operator>>(std::istream& strm,LZespolona& L1) {
  char znak;
  strm>>znak;
  if (znak != '(') {
    strm.setstate(std::ios::failbit);
  }
  strm >> L1.re;
  strm >> L1.im;
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
