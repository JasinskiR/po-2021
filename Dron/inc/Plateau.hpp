#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Block.hpp"

class Plat : public BlockI, public DInter, public LandI {
  int id;

 public:
  Plat(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
       std::pair<int, int> s)
      : BlockI(ctr, ort, h, {s.first, s.second}), id(-1) {draw();}
  void draw() override;
  int idGet() { return id; }
  std::vector<Vector<3>> calcVert();
  std::string type() override { return "Plaskowyz"; }
  Vector<3> cords() override { return center; }
  bool isAbove(std::shared_ptr<DroneI> drone) override { return true; }
  bool canLand(std::shared_ptr<DroneI> drone, const double &altitude) override {
    return true;
  }
  ~Plat();
};

#endif