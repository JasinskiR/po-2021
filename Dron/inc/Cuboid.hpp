#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "CoordinateS.hpp"

class Cuboid : public CoordS {
  double height;
  double width;
  double depth;
  int id;

 public:
  Cuboid(Vector<3> ctr, MatrixRot<3> ort, CoordS *predec, double h, double w,
         double d)
      : CoordS(ctr, ort, predec), height(h), width(w), depth(d), id(-1) {}
  void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
  std::array<Vector<3>, 8> calcVert();
};
#endif