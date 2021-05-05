#include "Scene.hpp"

void Scene::Add(Figura *obj) {
  if (obj == nullptr){ 
    obj = new Figura;
    obj->dodaj();
  
  }

  // obj->dodaj();
  this->figures.push_back(obj); 
}

void Scene::Remove(const uint32_t &ind,std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  figures[ind]->usun(rysownik);
  this->figures.erase(figures.begin() + ind);
}
Figura &Scene::operator[](const uint32_t &ind) {
  if (ind < 0 || ind > figures.size()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return *(figures[ind]);
}

std::ostream &operator<<(std::ostream &strm, const Scene &figures) {
  strm << "Dostepne indeksy figur to :" << std::endl;
  for (uint32_t i = 0; i < figures.n_figures(); ++i) {
    strm << i + 1 << " ";
  }
  return strm;
}

void Scene::rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  for (uint32_t i =0; i< figures.size(); ++i) {
    figures[i]->rysuj(rysownik);
  }
}