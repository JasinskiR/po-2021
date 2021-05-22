#ifndef COORD_SYSTEM_HPP
#define COORD_SYSTEM_HPP

#include "Dr3D_gnuplot_api.hpp"
#include "MatrixRot.hpp"

class CoordS {
 protected:
  CoordS *predecessor;
  Vector<3> center;
  MatrixRot<3> orientation;
  drawNS::Point3D convert(const Vector<3> &vector);

 public:
  CoordS() = default;
  CoordS(const Vector<3> &ctr, const MatrixRot<3> &ort, CoordS *predec)
      : predecessor(predec), center(ctr), orientation(ort) {}
  void translation(const Vector<3> &vector);
  void rotation(const MatrixRot<3> &matrix);
  Vector<3> pointInPredec(Vector<3> point);
  Vector<3> coordSInGlob(Vector<3> point);
};

#endif