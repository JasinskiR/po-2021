#ifndef WEKTOR_HPP
#define WEKTOR_HPP

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
class Wektor {
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
  Wektor(std::array<double, SIZE> pkt) : cords(pkt){};

  /**
   * @brief Inicjalizuje wektor
   *
   * Ustawia wszystkie współrzędne na zera
   */
  Wektor() : cords{} {};

  /**
   * @brief Modeluje operacje dodania dwóch wektorów do siebie
   */
  Wektor<SIZE> operator+(const Wektor<SIZE> &Arg2) const;

  /**
   * @brief Modeluje operacje odejmowania dwóch wektorów od siebie
   */
  Wektor<SIZE> operator-(const Wektor<SIZE> &Arg2) const;

  /**
   * @brief Modeluje pojęcie mnożenia wektora przez stałą
   */
  Wektor<SIZE> operator*(const double &Arg2) const;

  /**
   * @brief Modeluje pojęcie mnożenia skalarnego wektorów
   */
  double operator*(const Wektor<SIZE> &Arg2) const;

  /**
   * @brief Liczy długość wektora
   */
  double dlugosc() const;

  /**
   * @brief Operator dostępowy do współrzędnych wektora.
   */
  const double &operator[](uint32_t indeks) const;  // getter

  /**
   * @brief Operator dostępowy do współrzędnych wektora.
   */
  double &operator[](uint32_t indeks);  // setter
};

/**
 * @brief  Wczytuje wektor ze strumienia.
 */
template <uint32_t SIZE>
std::istream &operator>>(std::istream &strm, Wektor<SIZE> &Wektor);

/**
 * @brief  Wpisuje wektor do strumienia.
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Wektor<SIZE> &Wektor);

#endif
