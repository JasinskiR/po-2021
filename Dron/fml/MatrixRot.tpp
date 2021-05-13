#include "MatrixRot.hpp"
#include <cassert>
#include <cmath>
#include <limits>

/**
 *  Inicjalizuje macierz rotacji jako macierz jednostokowa
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji
 */
template <uint32_t SIZE>
MacierzRot<SIZE>::MacierzRot() : Macierz{} {
  for (uint32_t i = 0; i < SIZE; ++i) {
    Macierz[i][i] = 1;
  }
}

/**
 * Mnoży odpowiednie składowe macierzy z odpowiednimi składowymi wektora.
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji oraz rozmiar wektora
 * @param Arg2 - wektor przez który chcemy przemnożyć macierz
 * @return Zwracamy wektor który jest wynikiem mnożenia
 */
template <uint32_t SIZE>
Vector<SIZE> MacierzRot<SIZE>::operator*(const Vector<SIZE> &Arg2) const {
  Vector<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->Macierz[i] * Arg2;
  }
  return Wynik;
}

/**
 * Operacja transponowania macierzy
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji oraz rozmiar wektora
 * @return  Zwraca macierz która jest wynikiem jej transponowania
 */
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

/**
 * Mnoży odpowiednie składowe macierzy z odpowiednimi składowymi drugiej
 * macierzy.
 *
 * @tparam SIZE - Określa wymiar obu macierzy rotacji
 * @param Arg2 - macierz przez którą chcemy przemnożyć pierwszą macierz
 * @return Zwraca macierz która jest wynikiem mnożenia
 */
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

/**
 * Możemy za jego pomocą dostać się do poszczególnych wierszów macierzy rotacji.
 * Umożliwa on dostęp do wierszy, bez możliwości modyfikacji.
 * Gdy indeks jest spoza zakresu [0;SIZE] zostanie wypisany stosowny komunikat
 * oraz nastąpi wyjście z programu.
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji
 * @param index - indeks wiersza do którego chcemy uzyskać dostęp
 * @return zwraca odpowiedni niemodyfikowalny wiersz macierzy rotacji
 */
template <uint32_t SIZE>
const Vector<SIZE> &MacierzRot<SIZE>::operator[](uint32_t index) const {
  if (index < 0 || index > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Macierz[index];
}

/**
 * Konstruktor macierzy obrotu
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji
 * @param angle - kąt o który będziemy obracać
 * @param o - oś układu współrzędnych wokół której chcemy wykonywać obrót
 */
template <uint32_t SIZE>
MacierzRot<SIZE>::MacierzRot(const double &angle, Axis o) {
  static_assert(!(SIZE <> 3), "Program nie obsluguje obrotow w innych wymiarach niz 3!");
}

/**
 * Wczytuje oś ze strumienia
 *
 * @param strm - strumień z którego ma zostać wczytana oś
 * @param os - oś która ma zostać wczytana
 * @return Zwracamy referencję do przysłanego strumienia
 */
std::istream &operator>>(std::istream &strm, Axis &os) {
  char tmp;
  strm >> tmp;
  switch (tmp) {
    case 'x':
    case 'X': {
      os = Axis::OX;
      break;
    }
    case 'y':
    case 'Y': {
      os = Axis::OY;
      break;
    }
    case 'z':
    case 'Z': {
      os = Axis::OZ;
      break;
    }
    default: {
      strm.setstate(std::ios::failbit);
      break;
    }
  }

  return strm;
}

/**
 * Wypisanie macierzy rotacji na odpowiedni strumień
 *
 * @param strm - strumień na który ma zostać wypisana macierz
 * @param Macierz - macierz rotacji która zostanie wpisana do strumienia
 * @return Zwracamy referencję do przysłanego strumienia
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const MacierzRot<SIZE> &Macierz) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm << Macierz[i] << std::endl;
  }

  return strm;
}

/**
 * Funkcja kopiująca wartości macierzy rotacji do innej macierzy tego samego typu
 * 
 * @tparam SIZE - Określa wymiar macierzy rotacji
 * @param Matrix - Obiekt klasy MacierzRot z którego następuje przekopiowanie wartości
 * @return  Zwraca referencję do obiektu do którego zostały wpisane dane
 */
template <uint32_t SIZE>
MacierzRot<SIZE> &MacierzRot<SIZE>::operator=(const MacierzRot<SIZE> &Matrix) {
  if (this != &Matrix) {
    for (uint32_t i = 0; i < SIZE; ++i) {
      for (uint32_t j = 0; j < SIZE; ++j) {
        Macierz[i][j] = Matrix[i][j];
      }
    }
  }
  return *this;
}

template class MacierzRot<3>;
template std::ostream &operator<<(std::ostream &strm,
                                  const MacierzRot<3> &Macierz);