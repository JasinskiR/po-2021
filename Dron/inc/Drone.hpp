#ifndef DRONE_HPP
#define DRONE_HPP

#include "CoordinateS.hpp"
#include "Cuboid.hpp"
#include "HexaPrism.hpp"

class Drone : public CoordS {
 public:
  Cuboid dBody;
  std::array<HexaP, 4> rotor;
  int id;

  Drone(Vector<3> ctr, MatrixRot<3> ort)
      : CoordS(ctr, ort, nullptr),
        dBody(Vector<3>({0, 0, 0}), MatrixRot<3>(), this, 0.5, 1, 2),
        rotor({
            HexaP(Vector<3>({0.5, 1, 0.25}), MatrixRot<3>(), this, 0.5, 0.2),
            HexaP(Vector<3>({-0.5, 1, 0.25}), MatrixRot<3>(), this, 0.5, 0.2),
            HexaP(Vector<3>({0.5, -1, 0.25}), MatrixRot<3>(), this, 0.5, 0.2),
            HexaP(Vector<3>({-0.5, -1, 0.25}), MatrixRot<3>(), this, 0.5, 0.2),
        }),
        id(-1){};
  void goForward(const double &distance);
  void goVertical(const double &height);
  void rotate(const double &angle);
  void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
  void animation(double height, double angle,
                 double distance,std::shared_ptr<drawNS::Draw3DAPI> api);  // w innej klasie (pozniej)
  void rotorSpin();
};
#endif