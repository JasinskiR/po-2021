#include "Drone.hpp"
void Drone::goForward(const double &distance) {
  Vector<3> course({0, distance, 0});
  course = this->orientation * course;
  this->center = this->center + course;
}

void Drone::goVertical(const double &height) {
  Vector<3> altitude({0, 0, height});
  this->center = this->center + altitude;
}
void Drone::rotate(const double &angle) {
  MatrixRot<3> matrixR(angle, Axis::OZ);
  this->orientation = this->orientation * matrixR;
}

void Drone::draw(std::shared_ptr<drawNS::Draw3DAPI> api) {
  dBody.draw(api);
  for (uint32_t i = 0; i < 4; ++i) {
    rotor[i].draw(api);
  }
  // searchlight ?
}
void Drone::animation(double height, double angle, double distance,
                      std::shared_ptr<drawNS::Draw3DAPI> api) {
  this->goVertical(height);
  this->draw(api);
  int i = 0;
  while (i != 2) {
    std::cin >> i;
  }
  this->rotate(angle);
  this->draw(api);
  i = 0;
  while (i != 2) {
    std::cin >> i;
  }
  this->goForward(distance);
  this->draw(api);
  i = 0;
  while (i != 2) {
    std::cin >> i;
  }
  this->goVertical(-height);
  this->draw(api);
  i = 0;
  while (i != 2) {
    std::cin >> i;
  }

}  // w innej klasie
void Drone::rotorSpin() {}