#include "CuboidPlat.hpp"

/**
 * @brief Rysuje obiekt klasy CubPlat
 *
 */
void CubPlat::draw(std::string colour) {
  int tmp;
  std::vector<std::vector<drawNS::Point3D>> vertices;
  std::vector<drawNS::Point3D> points;
  std::array<Vector<3>, 8> calcV = this->calcVert();
  for (uint32_t i = 0; i < 8; ++i) {
    points.push_back(convert(calcV[i]));
    if (i % 4 == 3) {
      vertices.push_back(points);
      points.clear();
    }
  }
  tmp = (DInter::apiGet())->draw_polyhedron(vertices, colour);

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
 * @return std::array<Vector<3>, 8> - zwraca tablicę zawierający poszczegołne
 * wierzchołki
 */
std::array<Vector<3>, 8> CubPlat::calcVert() {
  std::array<Vector<3>, 8> resultV;
  int signx = 1, signy = 1;
  for (uint32_t i = 0, j = 0; j < 4; ++i, ++j) {
    if (i % 2 == 1) signy = -signy;
    if (i % 3 == 2) signx = -signx;
    resultV[j] =
        coordSInGlob(Vector<3>({signx * width / 2, signy * depth / 2, 0}));
    if (i % 4 == 3) {
      signy = 1;
      signx = 1;
    }
  }
  for (uint32_t i = 0, j = 4; j < 8; ++i, ++j) {
    if (i % 2 == 1) signy = -signy;
    if (i % 3 == 2) signx = -signx;
    resultV[j] =
        coordSInGlob(Vector<3>({signx * width / 2, signy * depth / 2, height}));
  }
  return resultV;
}

/**
 * @brief Destruktor obiektu klasy CubPlat
 * usuwa kształt obiektu/figury oraz odświeża gnuplota
 *
 */
CubPlat::~CubPlat() {
  DInter::apiGet()->erase_shape(id);
  DInter::apiGet()->redraw();
}

/**
 * @brief Metoda pozwalająca sprawdzic czy dwa obiekty się przecinają (wraz z
 * ich obszarem kolizji) Funkcja bierze pod uwagę zaookrąglone rogi strefy
 * kolizji prostokąta
 * @param drone - dron który ma znajdować się nad obiektem
 * @return true - wartość zwracana, gdy obiekt jest nad płaskowyżem
 * @return false - wartość zwracana, gdy obiekt nie znajduje się nad płaskowyżem
 */
bool CubPlat::isAbove(DroneI *drone, const double &altitude) {
  if (altitude > height) {
    Vector<3> distance = dynamic_cast<LandI *>(drone)->cords() - this->cords();
    if (std::abs(distance[0]) > (width / 2 + drone->getAreaR())) return false;
    if (std::abs(distance[1]) > (depth / 2 + drone->getAreaR())) return false;

    if (std::abs(distance[0]) <= (width / 2)) return true;
    if (std::abs(distance[1]) <= (depth / 2)) return true;

    double corner;
    corner = pow((std::abs(distance[0]) - width / 2), 2) +
             pow((std::abs(distance[1]) - depth / 2), 2);
    return (corner <= pow((drone->getAreaR()), 2));
  }
  return false;
}

bool CubPlat::canLand(DroneI *drone, const double &altitude) {
  if (altitude > height) {
    Vector<3> distance = dynamic_cast<LandI *>(drone)->cords() - this->cords();
    if (std::abs(distance[0]) < (width / 2)) return true;
    if (std::abs(distance[1]) < (depth / 2)) return true;

    if (std::abs(distance[0]) >= (width / 2)) return false;
    if (std::abs(distance[1]) >= (depth / 2)) return false;
  }
  return false;
}

bool CubPlat::collision(DroneI *drone, const double &altitude) {
  if (altitude < height) {
    Vector<3> distance = dynamic_cast<LandI *>(drone)->cords() - this->cords();
    if (std::abs(distance[0]) <= (width / 2 + drone->getAreaR())) return true;
    if (std::abs(distance[1]) <= (depth / 2 + drone->getAreaR())) return true;
  }
  return false;
}