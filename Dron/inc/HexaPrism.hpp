#ifndef HEXA_PRISM_HPP
#define HEXA_PRISM_HPP

#include "CoordinateS.hpp"

class HexaP : public CoordS {
  double radius;
  double height;
  int id;

 public:
  HexaP(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec,
        const double &r, const double &h)
      : CoordS(ctr, ort, predec), radius(r), height(h), id(-1) {}
  void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
  std::array<Vector<3>, 12> calcVert();
};
#endif