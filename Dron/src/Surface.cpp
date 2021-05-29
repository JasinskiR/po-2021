#include "Surface.hpp"

Surface::Surface(const double &H) { height = H; }

void Surface::draw() {
  for (int x = -5; x < 5; ++x) {
    int y = -5;
    for (y = -5; y < 5; ++y) {
      (DInter::apiGet())
          ->draw_surface(
              std::vector<std::vector<drawNS::Point3D> >{
                  {drawNS::Point3D(x, y, height),
                   drawNS::Point3D(x + 1, y, height),
                   drawNS::Point3D(x + 1, y, height),
                   drawNS::Point3D(x, y, height),
                   drawNS::Point3D(x, y, height)},
                  {drawNS::Point3D(x, y + 1, height),
                   drawNS::Point3D(x + 1, y + 1, height),
                   drawNS::Point3D(x + 1, y + 1, height),
                   drawNS::Point3D(x, y + 1, height),
                   drawNS::Point3D(x, y + 1, height)}},
              "purple");
    }
  }
  DInter::apiGet()->redraw();
}