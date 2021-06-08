#ifndef COORD_SYSTEM_HPP
#define COORD_SYSTEM_HPP

/**
 * @file
 * @brief Definicja klasy układu współrzędnych
 *
 */
#include "Dr3D_gnuplot_api.hpp"
#include "MatrixRot.hpp"

/**
 * @brief Modeluje pojęcie klasy CoordS
 *
 */
class CoordS {
 protected:
  /**
   * @brief Wskaźnik na poprzedni układ współrzędnych
   * nullptr będzie odpowiednikiem układu globalnego
   */
  CoordS *predecessor;
  /**
   * @brief Wektor położenia środka układu współrzędnych
   *
   */
  Vector<3> center;
  /**
   * @brief Macierz orientacji ukłądu współrzędnych
   *
   */
  MatrixRot<3> orientation;
  /**
   * @brief Metoda przeliczająca wektor na punkty zdolne do narysowania
   *
   * @param vector
   * @return drawNS::Point3D
   */
  drawNS::Point3D convert(const Vector<3> &vector);

 public:
  /**
   * @brief Domyślny konstrukotor
   *
   */
  CoordS() = default;
  /**
   * @brief Konstruktor obiektu klasy CoordS
   *
   * @param ctr - środek układu współrzędnych
   * @param ort - macierz orientacji
   * @param predec - wskaźnik na poprzedni ukłąd współrzędnych
   */
  CoordS(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec)
      : predecessor(predec), center(ctr), orientation(ort) {}
  /**
   * @brief Metoda wykonująca translację układu współrzędnych o zadany wektor
   *
   * @param vector - wektor translacji
   */
  void translation(const Vector<3> &vector);
  /**
   * @brief metoda pozwalajaca obrót układu współrzędnych
   * 
   * @param matrix - macierz obrotu
   */
  void rotation(const MatrixRot<3> &matrix);
  /**
   * @brief Metoda zwracająca wektor w poprzednim układzie współrzędnych
   * 
   * @param point - wektor - punkt
   * @return Vector<3> - wektor po przeliczeniu
   */
  Vector<3> pointInPredec(Vector<3> point);
  /**
   * @brief Metoda zwracająca wektor w globalnym układzie współrzędnych
   * 
   * @param point - wektor - punkt
   * @return Vector<3> - wektor po przeliczeniu
   */
  Vector<3> coordSInGlob(Vector<3> point);
};

#endif