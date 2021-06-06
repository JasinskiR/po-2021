#ifndef HILL_HPP
#define HILL_HPP

/**
 * @file
 * @brief Definicja klasy wzgórza

 *
 */
#include "Block.hpp"

/**
 * @brief Modeluje pojęcie obiektu Hill - wzgorze będącego przeszkodą
 * Tworzy obiekt złożony z losowej liczby wierzchołków [3;9]s
 *
 */
class Hill : public BlockI, public DInter, public LandI {
  /**
   * @brief zmienna id pozwalająca na rysowanie obiektu
   *
   */
  int id;

 public:
  /**
   * @brief Konstruktor obiektu klasy Hill
   *
   * @param ctr - środek współrzędnych obiektu
   * @param ort - macierz orientacji obiektu
   * @param h - wysokośc obiektu
   * @param s - para liczb tworząca zakres rozmiaru obiektu
   */
  Hill(const Vector<3> &ctr, const MatrixRot<3> &ort, const double &h,
       std::pair<int, int> s)
      : BlockI(ctr, ort, h, {s.first, s.second}), id(-1) {
    draw();
  }
  /**
   * @brief metoda zwracająca id obiektu
   *
   * @return int - zwraca liczbę reprezentującą id obeiktu
   */
  int idGet() { return id; }
  void draw() override;
  bool isAbove(std::shared_ptr<DroneI> drone) override { return true; }
  bool canLand(std::shared_ptr<DroneI> drone, const double &altitude) override {
    return false;
  }
  /**
   * @brief Funkcja przeliczająca wierzchołki obiektu
   *
   * @return std::vector<Vector<3>> - zwraca vector zawierający poszczegołne
   * wierzchołki
   */
  std::vector<Vector<3>> calcVert();
  std::string type() override { return "Wzgorze"; }
  Vector<3> cords() override { return center; }
  /**
   * @brief Destruktor obiektu klasy Hill
   *
   */
  ~Hill();
};

#endif