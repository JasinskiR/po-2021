#include "Surface.hpp"

/**
 * @brief Konstruktor obiektu klasy Surface
 * Tworzy powierzchnię na adanej wyoskości
 *
 * @param H
 */
Surface::Surface(const double &H) { height = H; }

/**
 * @brief Funkcja pozwalająca narysować powierzchnię o zadanych wymiarach
 *
 * @param colour - kolor rysowanej powierzchni
 */
void Surface::draw(std::string colour) {
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
              colour);
    }
  }
  DInter::apiGet()->redraw();
}