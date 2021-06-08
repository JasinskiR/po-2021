#ifndef CUBOID_HPP
#define CUBOID_HPP

/**
 * @file
 * @brief Definicja klasy prostopadłoscian
 *
 */
#include "CoordinateS.hpp"
#include "DrawingInterface.hpp"

/**
 * @brief Modeluje pojęcie klasy Cuboid
 *
 */
class Cuboid : public CoordS, public DInter {
  /**
   * @brief Wyskość obiektu
   *
   */
  double height;
  /**
   * @brief Szerokośc obiektu
   *
   */
  double width;
  /**
   * @brief Głębokośc obiektu
   *
   */
  double depth;
  /**
   * @brief zmienna id pozwalająca na rysowanie obiektu
   *
   */
  int id;

 public:
  /**
   * @brief Konstruktor nowego obiektu klasy uboid
   *
   * @param ctr - środek współrzędnych obiektu
   * @param ort - macierz orientacji obiektu
   * @param predec - wskaźnik na poprzedni układ współrzędnych obiektu
   * @param h - wysokość obiektu
   * @param w - szerokośc obiektu
   * @param d - głębokośc obiektu
   */
  Cuboid(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec,
         const double &h, const double &w, const double &d)
      : CoordS(ctr, ort, predec), height(h), width(w), depth(d), id(-1) {}
  void draw(std::string colour) override;

  /**
   * @brief metoda zwracająca id obiektu
   *
   * @return int - zwraca liczbę reprezentującą id obeiktu
   */
  int idGet() { return id; }

  /**
   * @brief
   * @brief Funkcja przeliczająca wierzchołki obiektu
   *
   * @return std::array<Vector<3>, 8> - zwraca tablicę zawierający poszczegołne
   * wierzchołki
   */
  std::array<Vector<3>, 8> calcVert();

  /**
   * @brief Destruktor obiektu klasy Cuboid
   *
   */
  ~Cuboid() { DInter::apiGet()->erase_shape(id); }
};
#endif