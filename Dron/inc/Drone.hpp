#ifndef DRONE_HPP
#define DRONE_HPP

#include "Cuboid.hpp"
#include "HexaPrism.hpp"


class Drone : protected CoordS {
  Cuboid dBody;
  std::array<HexaP, 4> rotor;
  std::array<HexaP, 2> searchlight;
  std::array<std::array<Cuboid, 2>, 4> rotorBlades;
  int id;
  int routeId;

 public:
  Drone(Vector<3> ctr, MatrixRot<3> ort)
      : CoordS(ctr, ort, nullptr),
        dBody(Vector<3>({0, 0, 0}), MatrixRot<3>(), this, 0.5, 1, 2),
        rotor({
            HexaP(Vector<3>({0.5, 1, 0.25}), MatrixRot<3>(), &this->dBody, 0.5,
                  0.2),
            HexaP(Vector<3>({-0.5, 1, 0.25}), MatrixRot<3>(), &this->dBody, 0.5,
                  0.2),
            HexaP(Vector<3>({0.5, -1, 0.25}), MatrixRot<3>(), &this->dBody, 0.5,
                  0.2),
            HexaP(Vector<3>({-0.5, -1, 0.25}), MatrixRot<3>(), &this->dBody,
                  0.5, 0.2),
        }),
        searchlight(
            {HexaP(Vector<3>({0.25, 1.05, 0}), MatrixRot<3>(90, Axis::OX),
                   &this->dBody, 0.15, 0.1),
             HexaP(Vector<3>({-0.25, 1.05, 0}), MatrixRot<3>(90, Axis::OX),
                   &this->dBody, 0.15, 0.1)}),

        rotorBlades({{{Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[0], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[0], 0.03, 0.7, 0.02)},
                      {Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[1], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[1], 0.03, 0.7, 0.02)},
                      {Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[2], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[2], 0.03, 0.7, 0.02)},
                      {Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[3], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[3], 0.03, 0.7, 0.02)}}}),
        id(-1),
        routeId(-1){};
  void goForward(const double &distance);
  void goVertical(const double &height);
  void rotate(const double &angle);
  void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
  void animation(
      double height, double angle, double distance,
      std::shared_ptr<drawNS::Draw3DAPI> api);  // w innej klasie (pozniej)
  void rotorSpin();
  void route(double height, double angle, double distance,
             std::shared_ptr<drawNS::Draw3DAPI> api);
};

void wait4key();
#endif