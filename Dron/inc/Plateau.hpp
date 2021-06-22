#ifndef PLATEAU_HPP
#define PLATEAU_HPP

/**
 * @file
 * @brief Definicja klasy przeszkody typu płaskowyż
 */
#include "Block.hpp"
#include "Drone.hpp"
/**
 * @brief Modeluje pojęcie płaskowyżu jako obiektu będącego przeszkodą
 * Tworzy obiekt złożony z losowej liczby wierzchołków [3;9]
 */
class Plat : public BlockI, public DInter, public LandI {
  /**
   * @brief zmienna id pozwalająca na rysowanie obiektu
   *
   */
  int id;
  std::string colour;
  /**
   * @brief dolny promień podstawy
   *
   */
  double lowerAreaR;
  /**
   * @brief górny promień podstawy
   *
   */
  double upperAreaR;

 public:
  /**
   * @brief Konstruktor obiektu klasy Plat
   *
   * @param ctr - środek współrzędnych obiektu
   * @param ort - macierz orientacji obiektu
   * @param h - wysokośc obiektu
   * @param s - para liczb tworząca zakres rozmiaru obiektu
   */
  Plat(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
       std::pair<int, int> s)
      : BlockI(ctr, ort, h, {s.first, s.second}), id(-1), colour("red") {
    draw(colour);
  }
  void draw(std::string colour) override;
  /**
   * @brief metoda zwracająca id obiektu
   *
   * @return int - zwraca liczbę reprezentującą id obeiktu
   */
  int idGet() { return id; }
  /**
   * @brief Funkcja przeliczająca wierzchołki obiektu
   *
   * @return std::vector<Vector<3>> - zwraca vector zawierający poszczegołne
   * wierzchołki
   */
  std::vector<Vector<3>> calcVert();
  std::string type() override { return "Plaskowyz"; }
  Vector<3> cords() override { return center; }
  bool isAbove(DroneI *drone, const double &altitude) override;
  bool canLand(DroneI *drone, const double &altitude) override;
  bool collision(DroneI *drone, const double &altitude) override;
  double getHeight() override { return height; }
  /**
   * @brief Destruktor obiektu
   *
   */
  ~Plat();
};

#endif