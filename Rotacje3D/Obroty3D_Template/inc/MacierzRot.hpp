#ifndef MACIERZROT_HPP
#define MACIERZROT_HPP

/**
 * @file
 * @brief Definicja klasy MacierzRot(Macierz Rotacji)
 */
#include <iostream>

#include "Wektor.hpp"

  /**
   * @brief Określa rodzaj osi wokół której wykonywany będzie obrót
   *
   * Obrót może być wykonany wokół jednej z 3 osi układu współrzędnych
   */
  enum class OS {
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
class MacierzRot {
 private:
  /**
   * @brief Tablica przechowująca wartości wszystkich pól macierzy
   *
   * Składa się ona z wektorów
   */
  std::array<Wektor<SIZE>, SIZE> Macierz;

  /**
   * @brief Funkcja odpowiedzialana za transponowanie macierzy
   *
   */
  MacierzRot<SIZE> transponowanie() const;

 public:
  /**
   * @brief Inicjalizacja macierzy rotacji
   */
  MacierzRot();

  /**
   * @brief Inicjalizuje macierz rotacji na podstawie kąta obotu i osi wokół
   * której ma być wykonany obrót
   */
  MacierzRot(const double &kat, OS);

  /**
   * @brief Modeluje pojęcie mnożenia macierzy przez wektor
   */
  Wektor<SIZE> operator*(const Wektor<SIZE> &Arg2) const;

  /**
   * @brief Modeluje pojęcie mnozenia macierzy przez inną macierz
   */
  MacierzRot<SIZE> operator*(const MacierzRot<SIZE> &Arg2) const;

  /**
   * \brief Operator dostępowy do wierszów macierzy
   */
  const Wektor<SIZE> &operator[](uint32_t indeks) const;
};

/**
 * @brief  Wpisuje macierz rotacji do strumienia.
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const MacierzRot<SIZE> &Macierz);


/**
 * @brief  Pobiera os ze strumienia
 */
std::istream &operator>>(std::istream &strm, OS &os);

#endif
