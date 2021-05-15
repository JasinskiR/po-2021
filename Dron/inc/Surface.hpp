#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "Dr3D_gnuplot_api.hpp"

class Surface {
  double height;

 public:
  Surface(const double &height, std::shared_ptr<drawNS::Draw3DAPI> api);
};
#endif