#include "Plateau.hpp"

void Plat::draw() {
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
  tmp = DInter::apiGet()->draw_polyhedron(vertices, "red");

  if (id != -1) {
    DInter::apiGet()->erase_shape(id);
  }
  id = tmp;
  DInter::apiGet()->redraw();
}

std::vector<Vector<3>> Plat::calcVert() {
  Vector<3> tmp;
  double tmpH = 0;
  std::vector<Vector<3>> resultV, second;
  for (int i = 0; i < numberOfVert * 2; ++i) {
    tmp = coordSInGlob(
        (MatrixRot<3>(360 / numberOfVert * (i + 1), Axis::OZ) *
         Vector<3>(
             {0, (double)this->drawNumber(size.first, size.second), tmpH})));
    resultV.push_back(tmp);

    if (i % numberOfVert == numberOfVert - 1) {
      tmpH = height;
      second = resultV;
      for (int i = 0; i < numberOfVert; ++i) resultV.push_back(second[i]);
    }
  }
  for (int i = 0; i < numberOfVert; ++i)
    resultV.push_back(Vector<3>({0, 0, height}));

  return resultV;
}

Plat::~Plat() {
  DInter::apiGet()->erase_shape(id);
  DInter::apiGet()->redraw();
}