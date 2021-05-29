#ifndef D_INTERFACE
#define D_INTERFACE

#include <iostream>

#include "Dr3D_gnuplot_api.hpp"

class DInter {
 protected:
  static std::shared_ptr<drawNS::Draw3DAPI> api;
  int id;

 public:
  std::shared_ptr<drawNS::Draw3DAPI> apiGet() { return api; }
  virtual void draw() = 0;
};

#endif