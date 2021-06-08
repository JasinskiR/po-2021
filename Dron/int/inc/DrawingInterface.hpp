#ifndef D_INTERFACE_HPP
#define D_INTERFACE_HPP
/**
 * @file
 * @brief Definicja klasy interfejs rysowania

 */
#include <iostream>

#include "Dr3D_gnuplot_api.hpp"
/**
 * @brief Modeluje pojęcie klasy DInter
 *
 */
class DInter {
 protected:
  /**
   * @brief Statyczny wskaźnik do Gnuplota
   *
   */
  static std::shared_ptr<drawNS::Draw3DAPI> api;
  /**
   * @brief id elementu
   *
   */
  int id;

 public:
  /**
   * @brief Metoda zwracająca wskaźnik do gnuplota
   *
   * @return std::shared_ptr<drawNS::Draw3DAPI> - zwracany wskaźnik
   */
  std::shared_ptr<drawNS::Draw3DAPI> apiGet() { return api; }
  /**
   * @brief Wirtualna metoda rysowania elementów
   *
   * @param colour - kolor w jakim ma zostać narysowany obiekt
   */
  virtual void draw(std::string colour) = 0;
  /**
   * @brief Wirtualny destruktor obiektu klasy DInter
   *
   */
  virtual ~DInter() {}
};

#endif
