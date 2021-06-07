#ifndef SCENE_HPP
#define SCENE_HPP

/**
 * @file
 * @brief Definicja klasy sceny
 *
 */

#include "Drone.hpp"
#include "LandscapeInterface.hpp"
#include "Surface.hpp"

/**
 * @brief Modeluje pojęcie klasy Scene
 *
 */
class Scene {
 private:
  /**
   * @brief vector przechowujący wszystkie elementy krajobrazu
   *
   */
  std::vector<std::shared_ptr<LandI>> objectL;
  /**
   * @brief metoda zwracająca indeks drona
   *
   * @param index - kolejny indeks drona
   * @return uint32_t - zwraca liczbę reprezentującą index obiektu
   */
  uint32_t getDroneIndex(const uint32_t &index) const;
  /**
   * @brief metoda zwracająca indeks przeszkody
   *
   * @param index - kolejny indeks przeszkody
   * @return uint32_t - zwraca liczbę reprezentującą index obiektu
   */
  uint32_t getObstacleIndex(const uint32_t &index) const;
  /**
   * @brief Wskaźnik na aktywnego drona
   *
   */
  std::shared_ptr<DroneI> activeD;

 public:
  /**
   * @brief Konstruktor nowego obiektu klasy Scene
   *
   */
  Scene();
  /**
   * @brief Metoda pozwalająca dodawanie nowego obiektu
   *
   */
  void add();
  /**
   * @brief Metoda pozwalająca usuwanie elementu krajobrazu
   *
   */
  void removeE();
  /**
   * @brief Metoda pozwalająca przeprowadzenie symulacji ruchu drona
   *
   * @param id - id drona
   * @param height - wysokość przelotu
   * @param angle - kąt obrotu
   * @param distance - dystans do przebycia
   */
  void sAnimation(const uint32_t &id, const double &height, const double &angle,
                  const double &distance);
  /**
   * @brief Wypisuje elemnty krajobrazu
   *
   */

  /**
   * @brief Metoda pozwalająca wybrać aktualnego drona
   *
   */
  void choosenD();
  void print();
  ~Scene() {}
};

#endif