#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <chrono>
#include <random>

#include "CoordinateS.hpp"
#include "DrawingInterface.hpp"
#include "LandscapeInterface.hpp"

class BlockI : protected CoordS {
 protected:
  double height;
  double width;
  double depth;
  std::pair<int, int> size;
  int numberOfVert;

 public:
  BlockI(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
         std::pair<int, int> s)
      : CoordS(ctr, ort, nullptr), height(h), size(s.first, s.second) {
    numberOfVert = drawNumber(3, 9);
  }

  BlockI(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
         const double &w, const double &d)
      : CoordS(ctr, ort, nullptr), height(h), width(w), depth(d) {}

  int drawNumber(int min, int max);
  virtual ~BlockI() {}
};
#endif