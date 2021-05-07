#include "Wektor.hpp"

template <uint32_t SIZE>
double &Wektor<SIZE>::operator[](uint32_t indeks) {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[indeks];
}

template <uint32_t SIZE>
Wektor<SIZE> Wektor<SIZE>::operator+(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] + Arg2[i];
  }

  return Wynik;
}

template <uint32_t SIZE>
const double &Wektor<SIZE>::operator[](uint32_t indeks) const {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[indeks];
}

template <uint32_t SIZE>
Wektor<SIZE> Wektor<SIZE>::operator-(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] - Arg2[i];
  }

  return Wynik;
}

template <uint32_t SIZE>
Wektor<SIZE> Wektor<SIZE>::operator*(const double &Arg2) const {
  Wektor<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] * Arg2;
  }

  return Wynik;
}

template <uint32_t SIZE>
double Wektor<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
  double Wynik = 0;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik += this->cords[i] * Arg2[i];
  }
  return Wynik;
}

template <uint32_t SIZE>
double Wektor<SIZE>::dlugosc() const {
  double Wynik = 0;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik += pow(this->cords[i],2);
  }

  return sqrt(Wynik);
}

template <uint32_t SIZE>
std::istream &operator>>(std::istream &strm, Wektor<SIZE> &Wektor) {
  for (uint32_t i = 0; i < SIZE; ++i) {
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

template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Wektor<SIZE> &Wektor) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm << std::setw(12) << std::fixed << std::setprecision(10) << Wektor[i]
         << " ";
  }
  strm << std::endl;
  return strm;
}

template class Wektor<3>;

template std::ostream &operator<<(std::ostream &strm, const Wektor<3> &Wektor);
template std::istream &operator>>(std::istream &strm, Wektor<3> &Wektor);