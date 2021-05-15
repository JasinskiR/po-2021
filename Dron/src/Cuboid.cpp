#include "Cuboid.hpp"

void Cuboid::draw(std::shared_ptr<drawNS::Draw3DAPI> api) {
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
  tmp = api->draw_polyhedron(vertices, "red");

  if (id != -1) {
    api->erase_shape(id);
  }
  id = tmp;
}

std::array<Vector<3>, 8> Cuboid::calcVert() {
  std::array<Vector<3>, 8> resultV;
  int signx = 1, signy = 1, signz = 1;
  for (uint32_t i = 0, j = 0; j < 8; ++i, ++j) {
    if (i % 2 == 1) signy = -signy;
    if (i % 3 == 2) signx = -signx;
    resultV[j] = coordSInGlob(Vector<3>({signx * width / 2, signy * depth / 2, signz * height / 2}));
    if (i % 4 == 3) {
      signz = -signz;
      signy = 1;
      signx = 1;
      i = -1;
    }
  }
  return resultV;
}