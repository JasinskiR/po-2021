#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "CoordinateS.hpp"
#include "DrawingInterface.hpp"

class Cuboid : public CoordS, public DInter {
  double height;
  double width;
  double depth;
  int id;

 public:
  Cuboid(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec,
         const double &h, const double &w, const double &d)
      : CoordS(ctr, ort, predec), height(h), width(w), depth(d), id(-1) {}
  void draw() override;
  std::array<Vector<3>, 8> calcVert();
};
#endif