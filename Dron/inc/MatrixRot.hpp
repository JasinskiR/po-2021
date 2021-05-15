#ifndef MATRIXROT_HPP
#define MATRIXROT_HPP

/**
 * @file
 * @brief Definicja klasy MatrixRot(Macierz Rotacji)
 */
#include <iostream>

#include "Vector.hpp"

  /**
   * @brief Określa rodzaj osi wokół której wykonywany będzie obrót
   *
   * Obrót może być wykonany wokół jednej z 3 osi układu współrzędnych
   */
  enum class Axis {
    OX /** Oś OX układu współrzędnych */,
    OY /** Oś OY układu współrzędnych */,
    OZ /** Oś OZ układu współrzędnych */
  };

/**
 * @brief Modeluje pojęcie macierzy rotacji
 *
 * Macierz rotacji zawsze jest intepretowana jako macierz kwadratowa SIZExSIZE
 *
 * @tparam SIZE - Określa wymiar macierzy rotacji
 */
template <uint32_t SIZE>
class MatrixRot {
 private:
  /**
   * @brief Tablica przechowująca wartości wszystkich pól macierzy
   *
   * Składa się ona z wektorów
   */
  std::array<Vector<SIZE>, SIZE> matrixR;

  /**
   * @brief Funkcja odpowiedzialana za transponowanie macierzy
   *
   */
  MatrixRot<SIZE> transposition() const;

 public:
  /**
   * @brief Inicjalizacja macierzy rotacji
   */
  MatrixRot();

  /**
   * @brief Inicjalizuje macierz rotacji na podstawie kąta obotu i osi wokół
   * której ma być wykonany obrót
   */
  MatrixRot(const double &angle, Axis);

  /**
   * @brief Modeluje pojęcie mnożenia macierzy przez wektor
   */
  Vector<SIZE> operator*(const Vector<SIZE> &secondM) const;

  /**
   * @brief Modeluje pojęcie mnozenia macierzy przez inną macierz
   */
  MatrixRot<SIZE> operator*(const MatrixRot<SIZE> &secondM) const;

/**
 * @brief Operator kopiujący
 * 
 */
  MatrixRot<SIZE> &operator=(const MatrixRot<SIZE> &matrix);

  /**
   * \brief Operator dostępowy do wierszów macierzy
   */
  const Vector<SIZE> &operator[](uint32_t index) const;
};

/**
 * @brief  Wpisuje macierz rotacji do strumienia.
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const MatrixRot<SIZE> &matrix);


/**
 * @brief  Pobiera os ze strumienia
 */
std::istream &operator>>(std::istream &strm, Axis &os);

#include "MatrixRot.tpp"

#endif
