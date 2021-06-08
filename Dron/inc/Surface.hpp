#ifndef SURFACE_HPP
#define SURFACE_HPP
/**
 * @file
 * @brief Definicja klasy powierzchni (planety)
 *
 */
#include "DrawingInterface.hpp"

/**
 * @brief Modeluje pojęcie klasy Surface
 *
 */
class Surface : public DInter {
  /**
   * @brief Wysokość na której ma być narysowana powierzchnia
   *
   */
  double height;

 public:
 /**
  * @brief Konstruktor obiektu klasy Surface
  * 
  * @param height - parametr wyoskości
  */
  Surface(const double &height);
  void draw(std::string colour) override;
};
#endif