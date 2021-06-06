#include "Hill.hpp"

/**
 * @brief Rysuje obiekt klasy Hill
 *
 */
void Hill::draw() {
  int tmp;
  std::vector<std::vector<drawNS::Point3D>> vertices;
  std::vector<drawNS::Point3D> points;
  std::vector<Vector<3>> calcV = this->calcVert();
  for (int i = 0; i < numberOfVert * 2; ++i) {
    points.push_back(convert(calcV[i]));
    if (i % numberOfVert == numberOfVert - 1) {
      vertices.push_back(points);
      vertices.push_back(points);
      points.clear();
    }
  }
  tmp = DInter::apiGet()->draw_polyhedron(vertices, "red");

  if (id != -1) {
    DInter::apiGet()->erase_shape(id);
  }
  id = tmp;
  DInter::apiGet()->redraw();
}

/**
 * @brief Funkcja przeliczająca wierzchołki obiektu
 * Tworzy wierzchołki obiektu oraz przelicza je do układu globalnego
 *
 * @return std::vector<Vector<3>> - zwraca vector zawierający poszczegołne
 * wierzchołki
 */
std::vector<Vector<3>> Hill::calcVert() {
  Vector<3> tmp;
  std::vector<Vector<3>> resultV;
  for (int i = 0; i < numberOfVert; ++i) {
    tmp = coordSInGlob(
        (MatrixRot<3>(360 / numberOfVert * (i + 1), Axis::OZ) *
         Vector<3>({0, (double)this->drawNumber(size.first, size.second), 0})));
    resultV.push_back(tmp);
  }
  for (int i = 0; i < numberOfVert; ++i) {
    tmp = coordSInGlob((Vector<3>({0, 0, height})));
    resultV.push_back(tmp);
  }

  return resultV;
}

/**
 * @brief Destruktor obiektu klasy Hill
 * usuwa kształt obiektu/figury oraz odświeża gnuplota
 *
 */
Hill::~Hill() {
  DInter::apiGet()->erase_shape(id);
  DInter::apiGet()->redraw();
}