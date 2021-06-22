#ifndef BLOCK_HPP
#define BLOCK_HPP

/**
 * @file
 * @brief Definicja klasy interfejsu bryły
 *
 */
#include <chrono>
#include <random>

#include "CoordinateS.hpp"
#include "DrawingInterface.hpp"
#include "LandscapeInterface.hpp"

/**
 * @brief Modeluje pojęcie klasy BlockI
 *
 */
class BlockI : protected CoordS {
 protected:
  /**
   * @brief wysokość brył
   *
   */
  double height;
  /**
   * @brief szerokośc bryły
   *
   */
  double width;
  /**
   * @brief głębokośc bryły
   *
   */
  double depth;
  /**
   * @brief para liczb reprezentująca zakres rozmiary bryły
   *
   */
  std::pair<int, int> size;
  /**
   * @brief zmienna przechowująca liczbę wierzchołków podstawy bryły
   *
   */
  int numberOfVert;

 public:
  /**
   * @brief Konstruktor nowego obiektu klasy BlockI
   *
   * @param ctr - środek współrzędnych obiektu
   * @param ort - macierz orientacji obiektu
   * @param h - wyoskośc bryły
   * @param s - para liczb
   */
  BlockI(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
         std::pair<int, int> s)
      : CoordS(ctr, ort, nullptr), height(h), size(s.first, s.second) {
    numberOfVert = drawNumber(3, 9);
  }
  /**
   * @brief Konstruktor nowego obiektu klasy BlockI
   *
   * @param ctr - środek współrzędnych obiektu
   * @param ort - macierz orientacji obiektu
   * @param h - wyoskośc bryły
   * @param w - szerokośc bryły
   * @param d - głębokośc bryły
   */
  BlockI(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
         const double &w, const double &d)
      : CoordS(ctr, ort, nullptr), height(h), width(w), depth(d) {}

  /**
   * @brief Funkcja zwracająca losową liczbę z określonego przedziału
   *
   * @param min - wartośc minimalna zakresu
   * @param max - wartość maksymalna zakresu
   * @return int - zwraca liczbę z określonego przedziału
   */
  int drawNumber(int min, int max);
  /**
   * @brief Wirtualna metoda zwracająca wysokość obiektu/przeszkody
   *
   * @return double - wysokość wyrażona za pomoća zmiennej double
   */
  virtual double getHeight() = 0;
  /**
   * @brief Wirtualny destrultor obiektu klasy BlockI
   *
   */
  virtual ~BlockI() {}
};
#endif