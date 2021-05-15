#ifndef HEXA_PRISM_HPP
#define HEXA_PRISM_HPP

#include "CoordinateS.hpp"

class HexaP : public CoordS {
 public:
  double radius;
  double height;
  int id;

  HexaP(Vector<3> ctr, MatrixRot<3> ort, CoordS *predec, double r, double h)
      : CoordS(ctr, ort, predec), radius(r), height(h), id(-1) {}
  void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
  std::array<Vector<3>, 12> calcVert();
};
#endif