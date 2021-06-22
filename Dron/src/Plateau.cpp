#include "Plateau.hpp"

/**
 * @brief Funkcja rysująca obiekt
 *
 */
void Plat::draw(std::string colour) {
  int tmp;
  std::vector<std::vector<drawNS::Point3D>> vertices;
  std::vector<drawNS::Point3D> points;
  std::vector<Vector<3>> calcV = this->calcVert();
  for (int i = 0; i < numberOfVert * 4; ++i) {
    points.push_back(convert(calcV[i]));
    if (i % numberOfVert == numberOfVert - 1) {
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
std::vector<Vector<3>> Plat::calcVert() {
  Vector<3> tmp;
  double tmpH = 0, radius, max = 0, min;
  std::vector<Vector<3>> resultV, second;
  for (int i = 0; i < numberOfVert * 2; ++i) {
    radius = (double)this->drawNumber(size.first, size.second);
    tmp = coordSInGlob((MatrixRot<3>(360 / numberOfVert * (i + 1), Axis::OZ) *
                        Vector<3>({0, radius, tmpH})));
    resultV.push_back(tmp);

    if (radius > max) max = radius;
    if (radius < min) min = radius;
    if (i % numberOfVert == numberOfVert - 1) {
      lowerAreaR = max;
      min = size.second + 1;
      tmpH = height;
      second = resultV;
      for (int i = 0; i < numberOfVert; ++i) resultV.push_back(second[i]);
    }
  }
  for (int i = 0; i < numberOfVert; ++i)
    resultV.push_back(Vector<3>({0, 0, height}));

  upperAreaR = min;
  return resultV;
}

/**
 * @brief Destruktor obiektu klasy Plat
 * usuwa kształt obiektu/figury oraz odświeża gnuplota
 *
 */
Plat::~Plat() {
  DInter::apiGet()->erase_shape(id);
  DInter::apiGet()->redraw();
}

bool Plat::isAbove(DroneI* drone, const double& altitude) {
  if (altitude > height) {
    if (lowerAreaR >= upperAreaR) {
      Vector<3> distance = dynamic_cast<LandI*>(drone)->cords() - this->cords();
      if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) <=
          lowerAreaR + drone->getAreaR())
        return true;
    } else if (lowerAreaR < upperAreaR) {
      Vector<3> distance = dynamic_cast<LandI*>(drone)->cords() - this->cords();
      if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) <=
          upperAreaR + drone->getAreaR())
        return true;
    }
  }
  return false;
}

bool Plat::canLand(DroneI* drone, const double& altitude) {
  if (altitude > height) {
    Vector<3> distance = dynamic_cast<LandI*>(drone)->cords() - this->cords();
    if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) < this->upperAreaR-drone->getAreaR()/2)
      return true;
  }
  return false;
}

bool Plat::collision(DroneI* drone, const double& altitude) {
  if (altitude < height) {
    Vector<3> distance = dynamic_cast<LandI*>(drone)->cords() - this->cords();
    if (lowerAreaR >= upperAreaR) {
      if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) <= lowerAreaR)
        return true;
    }
    if (lowerAreaR < upperAreaR) {
      if (std::sqrt(pow(distance[0], 2) + pow(distance[1], 2)) <= upperAreaR)
        return true;
    }
  }
  return false;
}