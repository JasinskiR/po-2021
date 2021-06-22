#ifndef CUB_PLAT_HPP
#define CUB_PLAT_HPP

/**
 * @file
 * @brief Definicja klasy płaskowyżu prostopadłościennego
 *
 */
#include "Block.hpp"
#include "Drone.hpp"

/**
 * @brief Modeluje pojęcie obiektu klasy CubPlat
 *
 */
class CubPlat : public BlockI, public DInter, public LandI {
  /**
   * @brief zmienna id pozwalająca na rysowanie obiektu
   *
   */
  int id;
  std::string colour;

 public:
  /**
   * @brief Construct a new Cub Plat object
   *
   * @param ctr - środek współrzędnych obiektu
   * @param ort - macierz orientacji obiektu
   * @param h - wysokośc obiektu
   * @param w - szerokośc obiektu
   * @param d - głębokość obiektu
   */
  CubPlat(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
          const double &w, const double &d)
      : BlockI(ctr, ort, h, w, d), id(-1), colour("red") {
    draw(colour);
  }

  /**
   * @brief metoda zwracająca id obiektu
   *
   * @return int - zwraca liczbę reprezentującą id obeiktu
   */
  int idGet() { return id; }
  void draw(std::string colour) override;
  bool isAbove(DroneI *drone, const double &altitude) override;
  bool canLand(DroneI *drone, const double &altitude) override;
  bool collision(DroneI *drone, const double &altitude) override;
  double getHeight() override { return height; }

  /**
   * @brief Funkcja przeliczająca wierzchołki obiektu
   *
   * @return std::array<Vector<3>, 8> - zwraca tablicę zawierający poszczegołne
   * wierzchołki
   */
  std::array<Vector<3>, 8> calcVert();
  std::string type() override { return "Plaskowyz prosty"; }
  Vector<3> cords() override { return center; }
  /**
   * @brief Destruktor obiektu klasy CubPlat
   *
   */
  ~CubPlat();
};

#endif