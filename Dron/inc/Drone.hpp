#ifndef DRONE_HPP
#define DRONE_HPP

/**
 * @file
 * @brief Definicja klasy dron
 *
 */

#include "Cuboid.hpp"
#include "HexaPrism.hpp"
#include "LandscapeInterface.hpp"

/**
 * @brief Modeluje pojęcie Drona jako złożonego obiektu
 * Tworzy obiekt dron złożony z korpusu, wirników, łopatek wirnika oraz
 * elementów dodatkowych Zawiera również funkcje pozwalające na
 * przemieszczanie/animacje drona
 */
class Drone : protected CoordS, public DInter, public DroneI, public LandI {
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
  /**
   * @brief Kolor rysowania drona
   *
   */
  std::string colour;

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
        routeId(-1),
        colour("red") {
    draw(colour);
  }

  void goForward(const double &distance) override;

  void goVertical(const double &height) override;

  void rotate(const double &angle) override;

  void draw(std::string colour) override;

  void animation(const double &height, const double &angle,
                 const double &distance) override;

  void rotorSpin() override;

  void route(const double &height, const double &angle,
             const double &distance) override;

  void lean(const double &angle) override;

  /**
   * @brief metoda zwracająca id obiektu
   *
   * @return int - zwraca liczbę reprezentującą id obeiktu
   */
  int idGet() { return id; }
  bool isAbove(std::shared_ptr<DroneI> drone) override { return true; }
  bool canLand(std::shared_ptr<DroneI> drone, const double &altitude) override {
    return true;
  }

  std::string colourGet() override { return colour; };
  void colourSet(std::string colourN) override { colour = colourN; };
  std::string type() override { return "Dron"; }
  Vector<3> cords() override { return center; }
  /**
   * @brief Destruktor obiektu klasy Drone
   *
   */
  ~Drone();
};

#endif