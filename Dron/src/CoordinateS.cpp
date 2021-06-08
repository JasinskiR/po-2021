#include "CoordinateS.hpp"

/**
 * @brief Funkcja wykonująca translacje układu współrzędnych o zadanyc wektor
 *
 * @param vector - wektor o jaki ma zostać przeprowadzona translacja
 */
void CoordS::translation(const Vector<3> &vector) {
  for (uint32_t i = 0; i < 3; ++i) {
    this->center = this->center + vector;
  }
}
/**
 * @brief Funkcja wykonująca obrót układu współrzędnych o zadaną macierz obrotu
 *
 * @param matrix - macierz obrotu
 */
void CoordS::rotation(const MatrixRot<3> &matrix) {
  this->orientation = this->orientation * matrix;
}

/**
 * @brief Funkcja zwracająca punkt w poprzednim układzie współrzędnych
 *
 * @param point - wektor przechowujący informacje o aktualnym położeniu punktu
 * @return Vector<3> - zwracany obiekt klasy Vector po przeliczeniu do
 * poprzedniego ukłądu współrzędnych
 */
Vector<3> CoordS::pointInPredec(Vector<3> point) {
  return (this->orientation * point + this->center);
}

/**
 * @brief Funkcja zwracająca punkt w globalnym układzie współrzędnych
 * Funkcja bazuje na rekurencji wykorzystując funkcje pointInPredec(Vector<3>
 * point) tej samej klasy w celu dostania się do globalnego układu
 *
 * @param resultV - wektor, który chcemy przerobi
 * @return Vector<3> - przerobiony wektor do ukadu globalnego
 */
Vector<3> CoordS::coordSInGlob(Vector<3> resultV) {
  if (this->predecessor != nullptr) {
    resultV = pointInPredec(resultV);
    return this->predecessor->coordSInGlob(resultV);
  }
  return pointInPredec(resultV);
}

/**
 * @brief Funkcja pozwalająca zmienić wektor na punkt zdolny do narysowania
 * przez gnuplot
 *
 * @param vector - wektor, który ma byc przerobiony
 * @return drawNS::Point3D - punkt zdolny do narysowania
 */
drawNS::Point3D CoordS::convert(const Vector<3> &vector) {
  return drawNS::Point3D(vector[0], vector[1], vector[2]);
}