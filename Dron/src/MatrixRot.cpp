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
      matrixR[0][0] = 1;
      matrixR[0][1] = 0;
      matrixR[0][2] = 0;
      matrixR[1][0] = 0;
      matrixR[1][1] = cos(angle * M_PI / 180);
      matrixR[1][2] = -sin(angle * M_PI / 180);
      matrixR[2][0] = 0;
      matrixR[2][1] = sin(angle * M_PI / 180);
      matrixR[2][2] = cos(angle * M_PI / 180);
      break;
    case Axis::OY:
      matrixR[0][0] = cos(angle * M_PI / 180);
      matrixR[0][1] = 0;
      matrixR[0][2] = sin(angle * M_PI / 180);
      matrixR[1][0] = 0;
      matrixR[1][1] = 1;
      matrixR[1][2] = 0;
      matrixR[2][0] = -sin(angle * M_PI / 180);
      matrixR[2][1] = 0;
      matrixR[2][2] = cos(angle * M_PI / 180);
      break;
    case Axis::OZ:
      matrixR[0][0] = cos(angle * M_PI / 180);
      matrixR[0][1] = -sin(angle * M_PI / 180);
      matrixR[0][2] = 0;
      matrixR[1][0] = sin(angle * M_PI / 180);
      matrixR[1][1] = cos(angle * M_PI / 180);
      matrixR[1][2] = 0;
      matrixR[2][0] = 0;
      matrixR[2][1] = 0;
      matrixR[2][2] = 1;
      break;
  }
}

/**
 * Wczytuje oś ze strumienia
 *
 * @param strm - strumień z którego ma zostać wczytana oś
 * @param os - oś która ma zostać wczytana
 * @return Zwracamy referencję do przysłanego strumienia
 */
std::istream &operator>>(std::istream &strm, Axis &os) {
  char tmp;
  strm >> tmp;
  switch (tmp) {
    case 'x':
    case 'X': {
      os = Axis::OX;
      break;
    }
    case 'y':
    case 'Y': {
      os = Axis::OY;
      break;
    }
    case 'z':
    case 'Z': {
      os = Axis::OZ;
      break;
    }
    default: {
      strm.setstate(std::ios::failbit);
      break;
    }
  }
  return strm;
}

template class MatrixRot<3>;
template std::ostream &operator<<(std::ostream &strm,
                                  const MatrixRot<3> &matrix);