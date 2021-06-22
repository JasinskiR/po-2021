#ifndef ANIMATION_HPP
#define ANIMATION_HPP

/**
 * @file
 * @brief Definicja klasy animacji ruchów obiektu
 *
 */

#include <chrono>
#include <thread>

#include "Block.hpp"
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
   *
   * @param fPairL - lista par składających się z wskaźnika na funkcję oraz
   * zmiennej, która ta funkcja przyjmuje
   * @param dron - wskaźnik na aktualny obiekt
   * @param height - wysokość przelotu
   */
  static void animeTime(
      std::initializer_list<std::pair<droneFPtr, const double&> > fPairL,
      Drone* dron, double height);
  // static double varFlight(double i, double fps);
};

#endif