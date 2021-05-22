#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "CoordinateS.hpp"

class Cuboid : public CoordS {
  double height;
  double width;
  double depth;
  int id;

 public:
  Cuboid(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec,
         const double &h, const double &w, const double &d)
      : CoordS(ctr, ort, predec), height(h), width(w), depth(d), id(-1) {}
  void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
  std::array<Vector<3>, 8> calcVert();
};
#endif