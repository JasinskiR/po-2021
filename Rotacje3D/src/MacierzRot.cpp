#include "MacierzRot.hh"

template <unsigned int SIZE>
Wektor<SIZE> MacierzRot<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (int i = 0; i < SIZE; ++i) {
    Wynik[i] = this->Macierz[i] * Arg2;
  }
  return Wynik;
}
/*
template <unsigned int SIZE>
MacierzRot<SIZE> MacierzRot<SIZE>::operator*(
    const MacierzRot<SIZE> &Arg2) const {
  MacierzRot<SIZE> MacierzW;
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
*/
template <unsigned int SIZE>
std::ostream &operator<<(std::ostream &strm, const MacierzRot<SIZE> &Macierz) {
  for (unsigned int i = 0; i < SIZE; ++i) {
    strm << Macierz[i] << std::endl;
  }

  return strm;
}
// TIA

template <>
MacierzRot<2>::MacierzRot(const double &kat, OS o) {
  Macierz[0][0] = cos(kat * M_PI / 180);
  Macierz[0][1] = -sin(kat * M_PI / 180);
  Macierz[1][0] = sin(kat * M_PI / 180);
  Macierz[1][1] = cos(kat * M_PI / 180);
}
template <>
MacierzRot<3>::MacierzRot(const double &kat, OS o) {
  switch (o) {
    case OX:
      Macierz[0][0] = 1;
      Macierz[0][1] = 0;
      Macierz[0][2] = 0;
      Macierz[1][0] = 0;
      Macierz[1][1] = cos(kat * M_PI / 180);
      Macierz[1][2] = -sin(kat * M_PI / 180);
      Macierz[2][0] = 0;
      Macierz[2][1] = sin(kat * M_PI / 180);
      Macierz[2][2] = cos(kat * M_PI / 180);
      break;
    case OY:
      Macierz[0][0] = cos(kat * M_PI / 180);
      Macierz[0][1] = 0;
      Macierz[0][2] = sin(kat * M_PI / 180);
      Macierz[1][0] = 0;
      Macierz[1][1] = 1;
      Macierz[1][2] = 0;
      Macierz[2][0] = -sin(kat * M_PI / 180);
      Macierz[2][1] = 0;
      Macierz[2][2] = cos(kat * M_PI / 180);
      break;
    case OZ:
      Macierz[0][0] = cos(kat * M_PI / 180);
      Macierz[0][1] = -sin(kat * M_PI / 180);
      Macierz[0][2] = 0;
      Macierz[1][0] = sin(kat * M_PI / 180);
      Macierz[1][1] = cos(kat * M_PI / 180);
      Macierz[1][2] = 0;
      Macierz[2][0] = 0;
      Macierz[2][1] = 0;
      Macierz[2][2] = 1;
      break;
  }
}
template <unsigned int SIZE>
MacierzRot<SIZE>::MacierzRot() {
  for (unsigned int i = 0; i < SIZE; ++i) {
    for (unsigned int j = 0; j < SIZE; ++j) {
      if (i == j)
        Macierz[i][j] = 1;
      else
        Macierz[i][j] = 0;
    }
  }
}
template <unsigned int SIZE>
const Wektor<SIZE> &MacierzRot<SIZE>::operator[](unsigned int indeks) const {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Macierz[indeks];
}
template <unsigned int SIZE>
Wektor<SIZE> &MacierzRot<SIZE>::operator[](unsigned int indeks) {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Macierz[indeks];
}