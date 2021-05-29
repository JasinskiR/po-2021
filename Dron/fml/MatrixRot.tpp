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
MatrixRot<SIZE>::MatrixRot() : matrixR{} {
  for (uint32_t i = 0; i < SIZE; ++i) {
    matrixR[i][i] = 1;
  }
}

/**
 * Mnoży odpowiednie składowe macierzy z odpowiednimi składowymi wektora.
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji oraz rozmiar wektora
 * @param vector - wektor przez który chcemy przemnożyć macierz
 * @return Zwracamy wektor który jest wynikiem mnożenia
 */
template <uint32_t SIZE>
Vector<SIZE> MatrixRot<SIZE>::operator*(const Vector<SIZE> &vector) const {
  Vector<SIZE> result;
  for (uint32_t i = 0; i < SIZE; ++i) {
    result[i] = this->matrixR[i] * vector;
  }
  return result;
}

/**
 * Operacja transponowania macierzy
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji oraz rozmiar wektora
 * @return  Zwraca macierz która jest wynikiem jej transponowania
 */
template <uint32_t SIZE>
MatrixRot<SIZE> MatrixRot<SIZE>::transposition() const {
  MatrixRot<SIZE> transM;
  for (uint32_t i = 0; i < SIZE; ++i) {
    for (uint32_t j = 0; j < SIZE; ++j) {
      transM.matrixR[i][j] = matrixR[j][i];
    }
  }
  return transM;
}

/**
 * Mnoży odpowiednie składowe macierzy z odpowiednimi składowymi drugiej
 * macierzy.
 *
 * @tparam SIZE - Określa wymiar obu macierzy rotacji
 * @param secondM - macierz przez którą chcemy przemnożyć pierwszą macierz
 * @return Zwraca macierz która jest wynikiem mnożenia
 */
template <uint32_t SIZE>
MatrixRot<SIZE> MatrixRot<SIZE>::operator*(
    const MatrixRot<SIZE> &secondM) const {
  MatrixRot<SIZE> resultM, T;
  T = secondM.transposition();
  for (uint32_t i = 0; i < SIZE; ++i) {
    for (uint32_t j = 0; j < SIZE; ++j) {
     resultM.matrixR[i][j] = matrixR[i] * T[j];
    }
  }
  return resultM;
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
const Vector<SIZE> &MatrixRot<SIZE>::operator[](uint32_t index) const {
  if (index < 0 || index > SIZE) {
    throw std::out_of_range{ "MacierzRot<" + std::to_string(SIZE) + "> out of range!" };
  }
  return matrixR[index];
}

/**
 * Konstruktor macierzy obrotu
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji
 * @param angle - kąt o który będziemy obracać
 * @param o - oś układu współrzędnych wokół której chcemy wykonywać obrót
 */
template <uint32_t SIZE>
MatrixRot<SIZE>::MatrixRot(const double &angle, Axis o) {
  static_assert(SIZE == 3, "Program nie obsluguje obrotow w innych wymiarach niz 3!");
}

/**
 * Wypisanie macierzy rotacji na odpowiedni strumień
 *
 * @param strm - strumień na który ma zostać wypisana macierz
 * @param matrix - macierz rotacji która zostanie wpisana do strumienia
 * @return Zwracamy referencję do przysłanego strumienia
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const MatrixRot<SIZE> &matrix) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm << matrix[i] << std::endl;
  }

  return strm;
}

/**
 * Funkcja kopiująca wartości macierzy rotacji do innej macierzy tego samego typu
 * 
 * @tparam SIZE - Określa wymiar macierzy rotacji
 * @param matrix - Obiekt klasy MatrixRot z którego następuje przekopiowanie wartości
 * @return  Zwraca referencję do obiektu do którego zostały wpisane dane
 */
template <uint32_t SIZE>
MatrixRot<SIZE> &MatrixRot<SIZE>::operator=(const MatrixRot<SIZE> &matrix) {
  if (this != &matrix) {
    for (uint32_t i = 0; i < SIZE; ++i) {
      for (uint32_t j = 0; j < SIZE; ++j) {
        matrixR[i][j] = matrix[i][j];
      }
    }
  }
  return *this;
}