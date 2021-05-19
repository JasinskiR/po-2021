#ifndef SCENE_HPP
#define SCENE_HPP

#include <chrono>
#include <thread>

#include "Drone.hpp"

class Animation {
  static double velocity;

 public:
  typedef void (Drone::*droneFPtr)(const double&);
  static void animeTime(
      std::initializer_list<std::pair<droneFPtr, const double&> > fPairL,
      Drone* dron, std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif