#ifndef SCENE_HPP
#define SCENE_HPP

#include "Drone.hpp"
#include "LandscapeInterface.hpp"
#include "Surface.hpp"

class Scene {
  std::vector<std::shared_ptr<LandI>> objectL;
  uint32_t getDroneIndex(const uint32_t &index) const;
  uint32_t getObstacleIndex(const uint32_t &index) const;

 public:
  Scene();
  void add();
  void removeE();
  void sAnimation(const uint32_t &id, const double &height, const double &angle,
                  const double &distance);
  void print();
};

#endif