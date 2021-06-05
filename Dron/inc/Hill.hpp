#ifndef HILL_HPP
#define HILL_HPP

#include "Block.hpp"

class Hill : public BlockI, public DInter, public LandI {
  int id;

 public:
  Hill(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
       std::pair<int, int> s)
      : BlockI(ctr, ort, h, {s.first, s.second}), id(-1) {draw();}

  int idGet() { return id; }
  void draw() override;
  bool isAbove(std::shared_ptr<DroneI> drone) override { return true; }
  bool canLand(std::shared_ptr<DroneI> drone, const double &altitude) override {
    return false;
  }
  std::vector<Vector<3>> calcVert();
  std::string type() override { return "Wzgorze"; }
  Vector<3> cords() override { return center; }
  ~Hill();
};

#endif