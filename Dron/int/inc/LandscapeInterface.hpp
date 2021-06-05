#pragma once

#include "DroneInterface.hpp"
// #include "Hill.hpp"
// #include "Plateau.hpp"

class LandI {
 public:
  virtual bool isAbove(std::shared_ptr<DroneI> drone) = 0;
  virtual bool canLand(std::shared_ptr<DroneI> drone,
                       const double &altitude) = 0;
  virtual std::string type() = 0;
  virtual Vector<3> cords() = 0;
  virtual ~LandI() {}
};
