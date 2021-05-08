#ifndef SCENE_HPP
#define SCENE_HPP
/**
 * @file
 * @brief Definicja klasy Scena
 *
 */

#include <iostream>

#include "Figure.hpp"
#include "MacierzRot.hpp"

/**
 * @brief Klasa modeluje pojęcie wielu brył naraz w przestrzeni 3D
 *
 * Zawiera ona kontener przechowujący wszystkie bryły
 * oraz elementy wspomagające wyświetlanie operacji w programie gnuplot.
 */
class Scene {
 private:
  /**
   * @brief Wektor przechowujący wszystkie figury
   *
   * Może ich pomieścić od 1 do bardzo dużej ilości ograniczoną pamięcią
   * urządzenia.
   */
  std::vector<Figura *> figures;

 public:
  /**
   * @brief Dodanie nowej figury
   */
  void Add(Figura *obj = nullptr);  // Add()

  /**
   * @brief Usunięcie bryły z przestrzeni na podstawie jej numeru
   */
  void Remove(const uint32_t &ind, std::shared_ptr<drawNS::Draw3DAPI> rysownik);

  /**
   * \brief Operator dostępowy do figur na scenie
   */
  Figura &operator[](const uint32_t &ind);

  /**
   * @brief Zwracanie ilości figur w przestrzeni
   *
   * @return Rozmiar wektora, przechowującego wszystkie figury
   */
  std::size_t n_figures() const { return figures.size(); };

  /**
   * @brief Rysuje wszystkie figury zawarte w wektorze
   */
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik);
};

/**
 * @brief Wpisuje scene do strumienia.
 */
std::ostream &operator<<(std::ostream &strm, const Scene &figures);

#endif