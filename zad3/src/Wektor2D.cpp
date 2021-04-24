#include "Wektor2D.hh"

double &Wektor2D::operator[](int indeks) {
  if (indeks < 0 || indeks > 1) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wektor[indeks];
}

const double &Wektor2D::operator[](int indeks) const {
  if (indeks < 0 || indeks > 1) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wektor[indeks];
}

Wektor2D Wektor2D::operator+(const Wektor2D &Arg2) const {
  Wektor2D Wynik;
  Wynik[0] = this->Wektor[0] + Arg2[0];
  Wynik[1] = this->Wektor[1] + Arg2[1];

  return Wynik;
}

Wektor2D Wektor2D::operator-(const Wektor2D &Arg2) const {
  Wektor2D Wynik;
  Wynik[0] = Wektor[0] - Arg2[0];
  Wynik[1] = Wektor[1] - Arg2[1];

  return Wynik;
}

Wektor2D Wektor2D::operator*(const double &Arg2) const {
  Wektor2D Wynik;
  Wynik[0] = Wektor[0] * Arg2;
  Wynik[1] = Wektor[1] * Arg2;

  return Wynik;
}

double Wektor2D::operator*(const Wektor2D &Arg2) const {
  double Wynik;
  Wynik = Wektor[0] * Arg2[0] + Wektor[1] * Arg2[1];

  return Wynik;
}

double Wektor2D::dlugosc() const {
  double Wynik;
  Wynik = sqrt(pow(2, Wektor[0]) + pow(2, Wektor[1]));

  return Wynik;
}

std::istream &operator>>(std::istream &strm, Wektor2D &Wektor) {
  double x, y;
  strm >> x;
  strm >> y;
  // compilator sam ustawi failbita na strm jezeli zostanie wczytana
  // nieprawidlowa wartosc
  if (strm.good()) {
    Wektor[0] = x;
    Wektor[1] = y;
  } else {
    strm.clear();
    strm.ignore(std::numeric_limits<int>::max(), '\n');
    std::cerr << "Blad danych - brak conajmniej jednej skladowej wierzcholka"
              << std::endl;
    exit(0);
  }
  return strm;
}

std::ostream &operator<<(std::ostream &strm, const Wektor2D &Wektor) {
  strm << Wektor[0] << " " << Wektor[1];

  return strm;
}
