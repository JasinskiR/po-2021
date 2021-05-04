#include "Wektor.hh"

template <uint SIZE>
double &Wektor<SIZE>::operator[](uint indeks) {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[indeks];
}

template <uint SIZE>
Wektor<SIZE> Wektor<SIZE>::operator+(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] + Arg2[i];
  }

  return Wynik;
}

template <uint SIZE>
const double &Wektor<SIZE>::operator[](uint indeks) const {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[indeks];
}

template <uint SIZE>
Wektor<SIZE> Wektor<SIZE>::operator-(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] - Arg2[i];
  }

  return Wynik;
}

template <uint SIZE>
Wektor<SIZE> Wektor<SIZE>::operator*(const double &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] * Arg2;
  }

  return Wynik;
}

template <uint SIZE>
double Wektor<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
  double Wynik=0;
  for (uint i = 0; i < SIZE; ++i) {
    Wynik += this->cords[i] * Arg2[i];
  }
  return Wynik;
}

template <uint SIZE>
double Wektor<SIZE>::dlugosc() const {
  double Wynik=0;
  for (uint i = 0; i < SIZE; ++i) {
    Wynik += pow(2, this->cords[i]);
  }

  return sqrt(Wynik);
}

template <uint SIZE>
std::istream &operator>>(std::istream &strm, Wektor<SIZE> &Wektor) {
  for (uint i = 0; i < SIZE; ++i) {
    strm >> Wektor[i];
  }
  // compilator sam ustawi failbita na strm jezeli zostanie wczytana
  // nieprawidlowa wartosc
  if (!strm.good()) {
    strm.clear();
    strm.ignore(std::numeric_limits<int>::max(), '\n');
    std::cerr << "Blad danych - brak conajmniej jednej skladowej wierzcholka"
              << std::endl;
    exit(0);
  }
  return strm;
}

template <uint SIZE>
std::ostream &operator<<(std::ostream &strm, const Wektor<SIZE> &Wektor) {
  for (uint i = 0; i < SIZE; ++i) {
    strm << std::setw(12) << std::fixed << std::setprecision(10) << Wektor[i]
         << " ";
  }
  strm << std::endl;
  return strm;
}

// template <uint SIZE>
// Wektor<SIZE> Wektor<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
//   Wektor<SIZE> Wynik;
//   for (uint i = 0; i < SIZE; ++i) {
//     Wynik += this->cords[i] * Arg2[i];
//   }
//   return Wynik;
// }


template class Wektor<2>;
template class Wektor<3>;
template std::ostream &operator<<(std::ostream &strm, const Wektor<2> &Wektor);
template std::istream &operator>>(std::istream &strm, Wektor<2> &Wektor);
template std::ostream &operator<<(std::ostream &strm, const Wektor<3> &Wektor);
template std::istream &operator>>(std::istream &strm, Wektor<3> &Wektor);
//pod testy
template class Wektor<6>;
template std::ostream &operator<<(std::ostream &strm, const Wektor<6> &Wektor);