#include "HexaPrism.hpp"

void HexaP::draw(std::shared_ptr<drawNS::Draw3DAPI> api) {
  int tmp;
  std::vector<std::vector<drawNS::Point3D>> vertices;
  std::vector<drawNS::Point3D> points;
  std::array<Vector<3>, 12> calcV = this->calcVert();
  for (uint32_t i = 0; i < 12; ++i) {
    points.push_back(convert(calcV[i]));
    if (i % 6 == 5) {
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

std::array<Vector<3>, 12> HexaP::calcVert() {
  std::array<Vector<3>, 12> resultV;
  int signz = 1;
  for (uint32_t i = 0, j = 0; j < 12; ++i, ++j) {
    resultV[j] = coordSInGlob(MatrixRot<3>(60 * (i + 1), Axis::OZ) *
                     Vector<3>({0, radius, signz * height / 2}) +
                 this->center);
    if (i % 6 == 5) {
      signz = -signz;
      i = -1;
    }
  }
  return resultV;
}