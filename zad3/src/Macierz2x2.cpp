#include "Macierz2x2.hh"

Wektor2D Macierz2x2::operator*(const Wektor2D &Arg2) const {
  Wektor2D Wynik;
  Wynik[0] = this->Macierz[0] * Arg2;
  Wynik[1] = this->Macierz[1] * Arg2;

  return Wynik;
}

Macierz2x2 Macierz2x2::operator*(const Macierz2x2 &Arg2) const {
  Macierz2x2 MacierzW;
  MacierzW[0][0] =
      this->Macierz[0][0] * Arg2[0][0] + this->Macierz[0][1] * Arg2[1][0];
  MacierzW[0][1] =
      this->Macierz[0][0] * Arg2[0][1] + this->Macierz[0][1] * Arg2[1][1];
  MacierzW[1][0] =
      this->Macierz[1][0] * Arg2[0][0] + this->Macierz[1][1] * Arg2[1][0];
  MacierzW[1][1] =
      this->Macierz[1][0] * Arg2[0][1] + this->Macierz[1][1] * Arg2[1][1];

  return MacierzW;
}

std::ostream &operator<<(std::ostream &strm, const Macierz2x2 &Macierz) {
  strm << Macierz[0][0] << " " << Macierz[0][1] << std::endl
       << Macierz[1][0] << " " << Macierz[1][1] << std::endl;

  return strm;
}

Macierz2x2::Macierz2x2(const double &kat) {
  Macierz[0][0] = cos(kat);
  Macierz[0][1] = -sin(kat);
  Macierz[1][0] = sin(kat);
  Macierz[1][1] = cos(kat);
}

Macierz2x2::Macierz2x2() {
  Macierz[0][0] = 1;
  Macierz[0][1] = 0;
  Macierz[1][0] = 0;
  Macierz[1][1] = 1;
}

const Wektor2D &Macierz2x2::operator[](int indeks) const {
  if (indeks < 0 || indeks > 1) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Macierz[indeks];
}

Wektor2D &Macierz2x2::operator[](int indeks) {
  if (indeks < 0 || indeks > 1) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Macierz[indeks];
}