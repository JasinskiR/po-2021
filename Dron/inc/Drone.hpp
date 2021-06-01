#ifndef DRONE_HPP
#define DRONE_HPP

/**
 * @file
 * @brief Definicja klasy dron
 *
 */

#include "Cuboid.hpp"
#include "HexaPrism.hpp"

/**
 * @brief Modeluje pojęcie Drona jako złożonego obiektu
 * Tworzy obiekt dron złożony z korpusu, wirników, łopatek wirnika oraz
 * elementów dodatkowych Zawiera również funkcje pozwalające na
 * przemieszczanie/animacje drona
 */
class Drone : protected CoordS, public DInter {
  /**
   * @brief obiekt klasy Cuboid odpowiedzialany za tworzenie korpusu drona
   *
   */
  Cuboid dBody;
  /**
   * @brief tablica obiektów klasy HexaP odpowiedzialany za tworzenie korpusu
   * drona wirniki drona
   *
   */
  std::array<HexaP, 4> rotor;
  /**
   * @brief tablica obiektów klasy HexaP odpowiedzialany za tworzenie elemntów
   * dodatkowych
   *
   */
  std::array<HexaP, 2> searchlight;
  /**
   * @brief tablica obiektó klasy Cuboid odpowiedzialany za tworzenie łopatek
   * wirnika
   *
   */
  std::array<std::array<Cuboid, 2>, 4> rotorBlades;
  /**
   * @brief zmienna pomocnicza dla klasy DInter umożliwiająca rysowanie drona
   *
   */
  int id;
  /**
   * @brief zmienna pomocnicza dla klasy DInter umożliwiająca rysowanie trasy
   * drona
   *
   */
  int routeId;

 public:
  /**
   * @brief Konstruktor nowego obiektu klasy Dron
   *
   * @param ctr - wektor początkowego położenia drona
   * @param ort - macierz orientacji drona
   */
  Drone(const Vector<3> &ctr, const MatrixRot<3> &ort)
      : CoordS(ctr, ort, nullptr),
        dBody(Vector<3>({0, 0, 0}), MatrixRot<3>(), this, 0.5, 1, 2),
        rotor({
            HexaP(Vector<3>({0.5, 1, 0.25}), MatrixRot<3>(), &this->dBody, 0.5,
                  0.2),
            HexaP(Vector<3>({-0.5, 1, 0.25}), MatrixRot<3>(), &this->dBody, 0.5,
                  0.2),
            HexaP(Vector<3>({0.5, -1, 0.25}), MatrixRot<3>(), &this->dBody, 0.5,
                  0.2),
            HexaP(Vector<3>({-0.5, -1, 0.25}), MatrixRot<3>(), &this->dBody,
                  0.5, 0.2),
        }),
        searchlight(
            {HexaP(Vector<3>({0.25, 1.05, 0}), MatrixRot<3>(90, Axis::OX),
                   &this->dBody, 0.15, 0.1),
             HexaP(Vector<3>({-0.25, 1.05, 0}), MatrixRot<3>(90, Axis::OX),
                   &this->dBody, 0.15, 0.1)}),

        rotorBlades({{{Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[0], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[0], 0.03, 0.7, 0.02)},
                      {Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[1], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[1], 0.03, 0.7, 0.02)},
                      {Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[2], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[2], 0.03, 0.7, 0.02)},
                      {Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(45, Axis::OZ),
                              &this->rotor[3], 0.03, 0.7, 0.02),
                       Cuboid(Vector<3>({0, 0, 0}), MatrixRot<3>(135, Axis::OZ),
                              &this->rotor[3], 0.03, 0.7, 0.02)}}}),
        id(-1),
        routeId(-1){};
  /**
   * @brief Funkcja opisująca poziomy ruch drona
   *
   * @param distance - parametr przechowujący odległość do pokonania
   */
  void goForward(const double &distance);
  /**
   * @brief Funkcja opisująca pionowy ruch drona
   *
   * @param height - parametr przechowujący wysokość do pokonania
   */
  void goVertical(const double &height);
  /**
   * @brief Funkcja opisująca rotację drona
   *
   * @param angle - parametr przechowujący kąt obrotu drona
   */
  void rotate(const double &angle);
  /**
   * @brief Funkcja pozwalająca rysowanie drona
   *
   */
  void draw() override;
  /**
   * @brief Funkcja realizująca animacje ruchu drona
   *
   * @param height - wysokość przelotu
   * @param angle - kąt roatacji drona
   * @param distance  - odległość przelotu
   */
  void animation(const double &height, const double &angle,
                 const double &distance);
  /**
   * @brief Funkcja realizująca obracanie się łopatek wirnika
   *
   */
  void rotorSpin();
  /**
   * @brief Funkcja rysująca planowaną trasę drona
   *
   * @param height - wysokość
   * @param angle - kąt
   * @param distance - odległość
   */
  void route(const double &height, const double &angle, const double &distance);
  /**
   * @brief Funkcja realizująca pochylanie się drona podczas lotu
   *
   * @param angle - kąt pochylenia
   */
  void lean(const double &angle);
  /**
   * @brief Funkcja zwracająca prywatny element id
   * 
   * @return int - zwraca wartość id drona
   */
  int idGet() { return id; }
//   void removeD();
};

#endif