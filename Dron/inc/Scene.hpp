#ifndef SCENE_HPP
#define SCENE_HPP

#include "Drone.hpp"
#include "Hill.hpp"
#include "Plateau.hpp"
#include "Surface.hpp"

class Scene {
  std::vector<Drone *> droneL;
  std::vector<Hill *> hillL;
  std::vector<Plat *> platL;

 public:
  Scene();
  void sAnimation(const uint32_t &id, const double &height, const double &angle,
                  const double &distance);
  void addHill(const Vector<3> &vector, const double &height,
               std::pair<int, int> range);
  void addPlat(const Vector<3> &vector, const double &height,
               std::pair<int, int> range);
  void addDron(const Vector<3> &vector);
  // void removeH(const uint32_t &id);
  // void removeP(const uint32_t &id);
  // void removeD(const uint32_t &id);
};

#endif