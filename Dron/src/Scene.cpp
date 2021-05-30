#include "Scene.hpp"

Scene::Scene() {
  Surface surf(-1);
  surf.draw();
  Vector<3> droneBase({0, 0, -1});
  Vector<3> hillBase({4, 4, -1});
  Vector<3> platBase({-4, -4, -1});
  addHill(hillBase, 3, {1, 3});
  addPlat(platBase, 2, {1, 3});
  addDron(droneBase);
}

void Scene::sAnimation(const uint32_t &id, const double &height,
                       const double &angle, const double &distance) {
  if (id < 0 || id > droneL.size()) {
    throw std::out_of_range{"Dron<" + std::to_string(droneL.size()) +
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