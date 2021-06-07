#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "DrawingInterface.hpp"

class Surface : public DInter {
  double height;

 public:
  Surface(const double &height);
  void draw(std::string colour) override;
};
#endif