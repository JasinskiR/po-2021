#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <chrono>
#include <random>

#include "CoordinateS.hpp"
#include "DrawingInterface.hpp"

class Plat : protected CoordS, public DInter {
  double height;
  std::pair<int, int> size;
  int id;

 public:
  int numberOfVert;
  Plat(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
       std::pair<int, int> s)
      : CoordS(ctr, ort, nullptr), height(h), size(s.first, s.second), id(-1) {
    numberOfVert = drawNumber(3, 9);
  }
  int drawNumber(int min, int max);
  void draw() override;
  int idGet() { return id; }
  // void removeP();
  std::vector<Vector<3>> calcVert();
};

#endif