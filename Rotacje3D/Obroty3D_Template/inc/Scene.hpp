#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>

#include "Figure.hpp"
#include "MacierzRot.hpp"

/*!
 * \file 
 * \brief Definicja klasy Scene
 * 
 * Plik zawiera definicję klasy Scene
 */

class Scene {
 private:
  std::vector<Figura *> figures;

 public:
  void Add(Figura *obj = nullptr);  // Add()
  void Remove(const uint32_t &ind, std::shared_ptr<drawNS::Draw3DAPI> rysownik);
  Figura &operator[](const uint32_t &ind);
  std::size_t n_figures() const { return figures.size(); };
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik);
};
std::ostream &operator<<(std::ostream &strm, const Scene &figures);

#endif