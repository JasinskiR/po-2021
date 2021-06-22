#pragma once

/**
 * @file
 * @brief Definicja klasy interfejs elementów krajobrazu
 */
#include "DroneInterface.hpp"

/**
 * @brief Modeluje pojęcie klasy LandI
 *
 */
class LandI {
 public:
  /**
   * @brief Wirtualna metoda informująca czy obiekt znajduje się nad innym
   * obiektem
   *
   * @param drone - obiekt, który badamy (docelowo ma znajdować się nad obiektem
   * krajobrazu)
   * @return true - jeżeli obiekt Dron jest nad innym obiektem
   * @return false - jeżeli obiekt Dron nie jest nad innym obiektem
   */
  virtual bool isAbove(DroneI* drone, const double& altitude) = 0;
  /**
   * @brief Wirtualna metoda informująca czy można lądować w danym miejscu
   *
   * @param drone - wskaźnik na drona który ma wylądować
   * @param altitude - wysokość na jakiej potencjalnie może wylądować dron
   * @return true - wartość zwracana w przypadku kiedy lądowanie jest dozwolone
   * @return false - wartość zwracana kiedy lądowanie nie jest możliwe
   */
  virtual bool canLand(DroneI* drone, const double& altitude) = 0;
  /**
   * @brief Wirtualna metoda odpowiedzialna za wykrywanie kolizji drona z przeszkodą
   * 
   * @param drone - dron, na którym wykonywana jest animacja
   * @param altitude - wysokość drona
   * @return true - wartośc zwracana jeśli nastąpi kolizja
   * @return false - wartośc zwracan jeśli nie ma kolicji
   */
  virtual bool collision(DroneI* drone, const double& altitude) = 0;
  /**
   * @brief Wirtualna metoda zwracająca nazwę obiektu
   *
   * @return std::string - zwraca ciąg znaków reprezentujący nazwę obiektu
   */
  virtual std::string type() = 0;
  /**
   * @brief Wirtualna metoda zwracająca położenie obiektu w przestrzeni
   *
   * @return Vector<3> - wektor położenia - lokalny środek układu współrzędnych
   */
  virtual Vector<3> cords() = 0;
  /**
   * @brief Wirtualny destruktor obiektu
   *
   */
  virtual ~LandI() {}
};
