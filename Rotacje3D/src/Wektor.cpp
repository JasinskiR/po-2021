#include "Wektor.hh"

template <unsigned int SIZE>
double &Wektor<SIZE>::operator[](unsigned int indeks) {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[indeks];
}

template <unsigned int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator+(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (unsigned int i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] + Arg2[i];
  }

  return Wynik;
}

template <unsigned int SIZE>
const double &Wektor<SIZE>::operator[](unsigned int indeks) const {
  if (indeks < 0 || indeks > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[indeks];
}

template <unsigned int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator-(const Wektor<SIZE> &Arg2) const {
  Wektor<SIZE> Wynik;
  for (unsigned int i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] - Arg2[i];
  }

  return Wynik;
}

template <unsigned int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator*(const double &Arg2) const {
  Wektor<SIZE> Wynik;
  for (unsigned int i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] * Arg2;
  }

  return Wynik;
}

template <unsigned int SIZE>
double Wektor<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
  double Wynik=0;
  for (unsigned int i = 0; i < SIZE; ++i) {
    Wynik += this->cords[i] * Arg2[i];
  }
  return Wynik;
}

template <unsigned int SIZE>
double Wektor<SIZE>::dlugosc() const {
  double Wynik=0;
  for (unsigned int i = 0; i < SIZE; ++i) {
    Wynik += pow(2, this->cords[i]);
  }

  return sqrt(Wynik);
}

template <unsigned int SIZE>
std::istream &operator>>(std::istream &strm, Wektor<SIZE> &Wektor) {
  for (unsigned int i = 0; i < SIZE; ++i) {
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

template <unsigned int SIZE>
std::ostream &operator<<(std::ostream &strm, const Wektor<SIZE> &Wektor) {
  for (unsigned int i = 0; i < SIZE; ++i) {
    strm << std::setw(12) << std::fixed << std::setprecision(10) << Wektor[i]
         << " ";
  }
  strm << std::endl;
  return strm;
}

// template <unsigned int SIZE>
// Wektor<SIZE> Wektor<SIZE>::operator*(const Wektor<SIZE> &Arg2) const {
//   Wektor<SIZE> Wynik;
//   for (unsigned int i = 0; i < SIZE; ++i) {
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