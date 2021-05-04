#include "MacierzRot.hpp"

template <uint32_t SIZE>
Wektor<SIZE> MacierzRot<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->Macierz[i] * Arg2;
  }
  return Wynik;
}

template <uint32_t SIZE>
MacierzRot<SIZE> MacierzRot<SIZE>::transponowanie() const {
  MacierzRot<SIZE> T;
  for (uint32_t i = 0; i < SIZE; ++i) {
    for (uint32_t j = 0; j < SIZE; ++j) {
      T.Macierz[i][j] = Macierz[j][i];
    }
  }
  return T;
}

template <uint32_t SIZE>
MacierzRot<SIZE> MacierzRot<SIZE>::operator*(
    const MacierzRot<SIZE> &Arg2) const {
  MacierzRot<SIZE> MacierzW, T;
  T = Arg2.transponowanie();
  for (uint32_t i = 0; i < SIZE; ++i) {
    for (uint32_t j = 0; j < SIZE; ++j) {
      MacierzW.Macierz[i][j] = Macierz[i] * T[j];
    }
  }
  return MacierzW;
}

template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const MacierzRot<SIZE> &Macierz) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm << Macierz[i] << std::endl;
  }

  return strm;
}

template <uint32_t SIZE>
MacierzRot<SIZE>::MacierzRot() {
  for (uint32_t i = 0; i < SIZE; ++i) {
    for (uint32_t j = 0; j < SIZE; ++j) {
      if (i == j)
        Macierz[i][j] = 1;
      else
        Macierz[i][j] = 0;
    }
  }
}
template <uint32_t SIZE>
const Wektor<SIZE> &MacierzRot<SIZE>::operator[](uint32_t indeks) const {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Macierz[indeks];
}
// Chyba nie potrzebne ?
// template <>
// MacierzRot<2>::MacierzRot(const double &kat, OS o) {
//   Macierz[0][0] = cos(kat * M_PI / 180);
//   Macierz[0][1] = -sin(kat * M_PI / 180);
//   Macierz[1][0] = sin(kat * M_PI / 180);
//   Macierz[1][1] = cos(kat * M_PI / 180);
// }

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

template <uint32_t SIZE>
MacierzRot<SIZE>::MacierzRot(const double &kat, OS o) {
  static_assert(SIZE < 4, "Program nie obsluguje hiperobrotow");
}

std::istream &operator>>(std::istream &strm, OS &os) {
  char tmp;
  strm >> tmp;
  switch (tmp) {
    case 'x':
    case 'X': {
      os = OX;
      break;
    }
    case 'y':
    case 'Y': {
      os = OY;
      break;
    }
    case 'z':
    case 'Z': {
      os = OZ;
      break;
    }
    default: {
      strm.setstate(std::ios::failbit);
      break;
    }
  }

  return strm;
}

template class MacierzRot<3>;
template std::ostream &operator<<(std::ostream &strm,
                                  const MacierzRot<3> &Macierz);