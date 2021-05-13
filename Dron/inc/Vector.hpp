#ifndef VECTOR_HPP
#define VECTOR_HPP

/**
 * @file
 * @brief Definicja klasy szablonowej Wektor
 */

#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

/**
 * @brief Modeluje pojęcie Wektora/Punktu w przestrzeni n-wymiarowej
 *
 * Przechuje wszystkie współrzędne wierzchołka w tablicy
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

 public:
  /**
   * @brief Inicjalizuje wektor na podstawie wspołrzędnych w tablicy
   * @param pkt - tablica współrzędnych które zostaną skopiowane do tablicy
   * wektora
   */
  Vector(std::array<double, SIZE> pkt) : cords(pkt){};

  /**
   * @brief Inicjalizuje wektor
   *
   * Ustawia wszystkie współrzędne na zera
   */
  Vector() : cords{} {};

  /**
   * @brief Modeluje operacje dodania dwóch wektorów do siebie
   */
  Vector<SIZE> operator+(const Vector<SIZE> &Arg2) const;

  /**
   * @brief Modeluje operacje odejmowania dwóch wektorów od siebie
   */
  Vector<SIZE> operator-(const Vector<SIZE> &Arg2) const;

  /**
   * @brief Modeluje pojęcie mnożenia wektora przez stałą
   */
  Vector<SIZE> operator*(const double &Arg2) const;

  /**
   * @brief Modeluje pojęcie mnożenia skalarnego wektorów
   */
  double operator*(const Vector<SIZE> &Arg2) const;

  /**
   * @brief Liczy długość wektora
   */
  double dlugosc() const;

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
std::istream &operator>>(std::istream &strm, Vector<SIZE> &Vector);

/**
 * @brief  Wpisuje wektor do strumienia.
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Vector<SIZE> &Vector);

#include "Vector.tpp"
#endif