#include "Drone.hpp"

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

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
  for (uint32_t i = 0; i < 4; ++i) rotor[i].draw(api);
  for (uint32_t i = 0; i < 2; ++i) searchlight[i].draw(api);
  for (uint32_t i = 0; i < 4; ++i) {
    for (uint32_t j = 0; j < 2; ++j) rotorBlades[i][j].draw(api);
  }
  rotorSpin();
}
void Drone::animation(double height, double angle, double distance,
                      std::shared_ptr<drawNS::Draw3DAPI> api) {
  wait4key();
  this->goVertical(height);
  this->draw(api);
  wait4key();
  this->rotate(angle);
  this->draw(api);
  wait4key();
  this->goForward(distance);
  this->draw(api);
  wait4key();
  this->goVertical(-height);
  this->draw(api);
  wait4key();

}  // w innej klasie
void Drone::rotorSpin() {
  for (uint32_t i = 0; i < 4; ++i) {
    for (uint32_t j = 0; j < 2; ++j)
      rotorBlades[i][j].rotation(MatrixRot<3>(30, Axis::OZ));
  }
}