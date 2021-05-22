#ifndef SCENE_HPP
#define SCENE_HPP

/**
 * @file
 * @brief Definicja klasy animacji ruchów obiektu
 *
 */

#include <chrono>
#include <thread>

#include "Drone.hpp"
/**
 * @brief Modeluje pojęcie animacji ruchów obiektu
 *
 */

class Animation {
  /**
   * @brief Zmienna statyczna odpowiedzialna za stałą prędkość ruchu
   *
   */
  static double velocity;

 public:
  /**
   * @brief Typedef przypisujący nazwe alternatywną dla wywołania wskaźnika na
   * funkcję
   *
   */
  typedef void (Drone::*droneFPtr)(const double&);

  /**
   * @brief Funkcja realizująca animacje poszczególnych ruchów obiektu
   */
  static void animeTime(
      std::initializer_list<std::pair<droneFPtr, const double&> > fPairL,
      Drone* dron, std::shared_ptr<drawNS::Draw3DAPI> api);
  //static double varFlight(double i, double fps);
};

#endif