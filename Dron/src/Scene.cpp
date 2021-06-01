#include "Scene.hpp"

Scene::Scene() {
  Surface surf(-1);
  surf.draw();
  Vector<3> droneBase({0, 0, -0.75});
  Vector<3> hillBase({3, 3, -1});
  Vector<3> platBase({-3, -3, -1});
  addHill(hillBase, 3, {1, 3});
  addPlat(platBase, 2, {1, 3});
  addDron(droneBase);
}

void Scene::sAnimation(const uint32_t &id, const double &height,
                       const double &angle, const double &distance) {
  if (id < 0 || id > droneL.size()) {
    throw std::out_of_range{"Dron id = <" + std::to_string(droneL.size()) +
                            "> out of range!"};
  }
  std::cout << droneL.size() << std::endl;
  droneL[id]->animation(height, angle, distance);
}

void Scene::addHill(const Vector<3> &vector, const double &height,
                    std::pair<int, int> range) {
  Hill *mt =
      new Hill(vector, MatrixRot<3>(), height, {range.first, range.second});
  hillL.push_back(mt);
  mt->draw();
}

void Scene::addPlat(const Vector<3> &vector, const double &height,
                    std::pair<int, int> range) {
  Plat *pt =
      new Plat(vector, MatrixRot<3>(), height, {range.first, range.second});
  platL.push_back(pt);
  pt->draw();
}

void Scene::addDron(const Vector<3> &vector) {
  Drone *dron = new Drone(vector, MatrixRot<3>());

  droneL.push_back(dron);
  dron->draw();
}

// void Scene::removeH(const uint32_t &id) {
//   if (id < 0 || id > hillL.size()) {
//     throw std::out_of_range{"Hill id = <" + std::to_string(hillL.size()) +
//                             "> out of range!"};
//   }
//   if (hillL[id]->idGet() != -1) {
//     hillL[id]->removeH();
//     this->hillL.erase(hillL.begin() + id);
//   }
// }
// void Scene::removeP(const uint32_t &id) {
//   if (id < 0 || id > platL.size()) {
//     throw std::out_of_range{"Plateau id = <" + std::to_string(platL.size()) +
//                             "> out of range!"};
//   }
//   if (platL[id]->idGet() != -1) {
//     platL[id]->removeP();
//     this->platL.erase(platL.begin() + id);
//   }
// }
// void Scene::removeD(const uint32_t &id) {
//   if (id < 0 || id > droneL.size()) {
//     throw std::out_of_range{"Drone id = <" + std::to_string(droneL.size()) +
//                             "> out of range!"};
//   }
//   if (droneL[id]->idGet() != -1) {
//     droneL[id]->removeD();
//     this->droneL.erase(droneL.begin() + id);
//   }
// }