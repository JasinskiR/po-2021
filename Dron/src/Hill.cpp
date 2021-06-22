#include "Hill.hpp"

/**
 * @brief Rysuje obiekt klasy Hill
 *
 */
void Hill::draw(std::string colour) {
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
  tmp = DInter::apiGet()->draw_polyhedron(vertices, colour);

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
  double radius, max = 0;
  std::vector<Vector<3>> resultV;
  for (int i = 0; i < numberOfVert; ++i) {
    radius = (double)this->drawNumber(size.first, size.second);
    tmp = coordSInGlob((MatrixRot<3>(360 / numberOfVert * (i + 1), Axis::OZ) *
                        Vector<3>({0, radius, 0})));
    resultV.push_back(tmp);
    if (radius > max) max = radius;
  }
  for (int i = 0; i < numberOfVert; ++i) {
    tmp = coordSInGlob((Vector<3>({0, 0, height})));
    resultV.push_back(tmp);
  }
  areaR = max;
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

bool Hill::isAbove(DroneI *drone, const double &altitude) {
  if (altitude > height) {
    Vector<3> distance = dynamic_cast<LandI *>(drone)->cords() - this->cords();
    if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) <=
        areaR + drone->getAreaR())
      return true;
  }
  return false;
}

bool Hill::collision(DroneI *drone, const double &altitude) {
  if (altitude < height) {
    Vector<3> distance = dynamic_cast<LandI *>(drone)->cords() - this->cords();
    if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) <=
        areaR + (drone->getAreaR() / 4))
      return true;
  }
  return false;
}