#include "Surface.hpp"
Surface::Surface(const double &height, std::shared_ptr<drawNS::Draw3DAPI> api) {
  for (int x = -5; x < 5; ++x) {
    int y = -5;
    for (y = -5; y < 5; ++y) {
      api->draw_surface(
          std::vector<std::vector<drawNS::Point3D> >{
              {drawNS::Point3D(x, y, height), drawNS::Point3D(x + 1, y, height),
               drawNS::Point3D(x + 1, y, height), drawNS::Point3D(x, y, height),
               drawNS::Point3D(x, y, height)},
              {drawNS::Point3D(x, y + 1, height), drawNS::Point3D(x + 1, y + 1, height),
               drawNS::Point3D(x + 1, y + 1, height), drawNS::Point3D(x, y + 1, height),
               drawNS::Point3D(x, y + 1, height)}},
          "purple");
    }
  }
}