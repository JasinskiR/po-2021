#ifndef VECTOR_HPP
#define VECTOR_HPP

/**
 * @file
 * @brief Definicja klasy szablonowej Wektor
 */

#include <array>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

/**
 * @brief Modeluje pojęcie Wektora/Punktu w przestrzeni n-wymiarowej
 *
 * Przechowuje wszystkie współrzędne wierzchołka w tablicy
 * oraz pozwala wykonywać na nich podstawowe operacje
 *
 * @tparam SIZE - Określa w ilo-wymiarowej przestrzeni przechowujemy nasz wektor
 */
template <uint32_t SIZE>
class Vector {
 private:
  /**
   * @brief Tablica przechowująca wszystkie współrzędne wektora
   */
  std::array<double, SIZE> cords;

  /**
   * @brief Zmienna przechowujaca aktualną ilość obiektów typu Vector
   * Inicjalizacja zmiennej wartością 0
   */
  inline static uint64_t rightNow = 0;

  /**
   * @brief Zmienna przechowujaca łączną ilość obiektów typu Vector
   * Inicjalizacja zmiennej wartością 0
   */
  inline static uint64_t overall = 0;

 public:
  /**
   * @brief Funkcja zwracająca aktualną ilość obiektów typu Vector
   */
  uint64_t rightNowG() { return rightNow; }

  /**
   * @brief Funkcja zwracająca łączną ilość obiektów typu Vector
   */
  uint64_t overallG() { return overall; }
  /**
   * @brief Inicjalizuje wektor na podstawie wspołrzędnych w tablicy
   * oraz dodaje ilość obiektów typu Vector
   * @param pt - tablica współrzędnych które zostaną skopiowane do tablicy
   * wektora
   */
  Vector(std::array<double, SIZE> pt) : cords(pt) {
    rightNow++;
    overall++;
  };

  /**
   * @brief Inicjalizuje wektor
   *
   * Ustawia wszystkie współrzędne na zera
   * oraz dodaje ilość obiektów typu Vector
   */
  Vector() : cords{} {
    rightNow++;
    overall++;
  }
  
  /**
   * @brief Construct a new Vector object
   */
  Vector(const Vector<SIZE> &vector) : cords(vector.cords) {
    rightNow++;
    overall++;
  };

  /**
   * @brief Copy operator of Vector object
   */
  Vector<SIZE> operator=(const Vector<SIZE> &vector);

  /**
   * @brief Destroy the Vector object
   * and subtracts the number of current Vector objects
   */
  ~Vector() { --rightNow; }
  /**
   * @brief Modeluje operacje dodania dwóch wektorów do siebie
   */
  Vector<SIZE> operator+(const Vector<SIZE> &secondV) const;

  /**
   * @brief Modeluje operacje odejmowania dwóch wektorów od siebie
   */
  Vector<SIZE> operator-(const Vector<SIZE> &secondV) const;

  /**
   * @brief Modeluje pojęcie mnożenia wektora przez stałą
   */
  Vector<SIZE> operator*(const double &constValue) const;

  /**
   * @brief Modeluje pojęcie mnożenia skalarnego wektorów
   */
  double operator*(const Vector<SIZE> &secondV) const;

  /**
   * @brief Liczy długość wektora
   */
  const double length() const;

  /**
   * @brief Operator dostępowy do współrzędnych wektora.
   */
  const double &operator[](uint32_t index) const;  // getter

  /**
   * @brief Operator dostępowy do współrzędnych wektora.
   */
  double &operator[](uint32_t index);  // setter
};

/**
 * @brief  Wczytuje wektor ze strumienia.
 */
template <uint32_t SIZE>
std::istream &operator>>(std::istream &strm, Vector<SIZE> &vector);

/**
 * @brief  Wpisuje wektor do strumienia.
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Vector<SIZE> &vector);

#include "Vector.tpp"
#endif