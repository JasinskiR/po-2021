#ifndef HEXA_PRISM_HPP
#define HEXA_PRISM_HPP

/**
 * @file
 * @brief Definicja klasy Graniastosłub sześciokątny foremny

 *
 */
#include "CoordinateS.hpp"
#include "DrawingInterface.hpp"

/**
 * @brief Modeluje pojęcie klasy HexaP
 *
 */
class HexaP : public CoordS, public DInter {
  /**
   * @brief Promien graniastosłupa (w oparciu o obiekt wpisany w koło)
   *
   */
  double radius;
  /**
   * @brief Wysokośc graniastosłupa
   *
   */
  double height;
  /**
   * @brief zmienna id pozwalająca na rysowanie obiektu
   *
   */
  int id;

 public:
 /**
  * @brief Konstruktor obiektu HexaP
  * 
  * @param ctr - środek współrzędnych obiektu
  * @param ort - macierz orientacji obiektu
  * @param predec - wskaźnik na poprzedni układ współrzędnych obiektu
  * @param r - promień obiektu
  * @param h - wysokośc obiektu
  */
  HexaP(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec,
        const double &r, const double &h)
      : CoordS(ctr, ort, predec), radius(r), height(h), id(-1) {}
  void draw() override;

  /**
   * @brief   /**
   * @brief Funkcja przeliczająca wierzchołki obiektu
   * 
   * @return std::array<Vector<3>, 12> - zwraca tablicę zawierający poszczegołne wierzchołki
   */
  std::array<Vector<3>, 12> calcVert();

    /**
   * @brief metoda zwracająca id obiektu
   * 
   * @return int - zwraca liczbę reprezentującą id obeiktu
   */
  int idGet() { return id; }
  /**
   * @brief Destruktor obiektu klasy HexaP
   * 
   */
  ~HexaP() { DInter::apiGet()->erase_shape(id); }
};
#endif