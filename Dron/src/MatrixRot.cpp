#include "MatrixRot.hpp"
/**
 * @file
 * @brief Definicje poszczególnych specjalizacji funkcji składowych klasy MacierzRot
 */


/**
 * Konstruktor macierzy obrotu
 *
 * @tparam Specjalizacja zdefiniowana dla wartości parametru szablonowego
 * równego 3.
 * @param angle - kąt o który będziemy obracać
 * @param o - oś układu współrzędnych wokół której chcemy wykonywać obrót
 */
template <>
MatrixRot<3>::MatrixRot(const double &angle, Axis o) {
  switch (o) {
    case Axis::OX:
      Matrix[0][0] = 1;
      Matrix[0][1] = 0;
      Matrix[0][2] = 0;
      Matrix[1][0] = 0;
      Matrix[1][1] = cos(angle * M_PI / 180);
      Matrix[1][2] = -sin(angle * M_PI / 180);
      Matrix[2][0] = 0;
      Matrix[2][1] = sin(angle * M_PI / 180);
      Matrix[2][2] = cos(angle * M_PI / 180);
      break;
    case Axis::OY:
      Matrix[0][0] = cos(angle * M_PI / 180);
      Matrix[0][1] = 0;
      Matrix[0][2] = sin(angle * M_PI / 180);
      Matrix[1][0] = 0;
      Matrix[1][1] = 1;
      Matrix[1][2] = 0;
      Matrix[2][0] = -sin(angle * M_PI / 180);
      Matrix[2][1] = 0;
      Matrix[2][2] = cos(angle * M_PI / 180);
      break;
    case Axis::OZ:
      Matrix[0][0] = cos(angle * M_PI / 180);
      Matrix[0][1] = -sin(angle * M_PI / 180);
      Matrix[0][2] = 0;
      Matrix[1][0] = sin(angle * M_PI / 180);
      Matrix[1][1] = cos(angle * M_PI / 180);
      Matrix[1][2] = 0;
      Matrix[2][0] = 0;
      Matrix[2][1] = 0;
      Matrix[2][2] = 1;
      break;
  }
}
