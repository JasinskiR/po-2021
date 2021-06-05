#ifndef CUB_PLAT_HPP
#define CUB_PLAT_HPP

#include "Block.hpp"

class CubPlat : public BlockI, public DInter, public LandI {
  int id;

 public:
  CubPlat(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
         const double &w, const double &d)
      : BlockI(ctr, ort, h, w, d), id(-1) {draw();}

  int idGet() { return id; }
  void draw() override;
  bool isAbove(std::shared_ptr<DroneI> drone) override { return true; }
  bool canLand(std::shared_ptr<DroneI> drone, const double &altitude) override {
    return false;
  }
  std::array<Vector<3>, 8> calcVert();
  std::string type() override { return "Plaskowyz prosty"; }
  Vector<3> cords() override { return center; }
  ~CubPlat();
};

#endif