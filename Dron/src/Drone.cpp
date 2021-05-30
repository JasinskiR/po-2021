#include "Drone.hpp"

#include <initializer_list>
#include <utility>

#include "Animation.hpp"

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

void Drone::draw() {
  dBody.draw();
  for (uint32_t i = 0; i < 4; ++i) rotor[i].draw();
  for (uint32_t i = 0; i < 2; ++i) searchlight[i].draw();
  for (uint32_t i = 0; i < 4; ++i) {
    for (uint32_t j = 0; j < 2; ++j) rotorBlades[i][j].draw();
  }
  DInter::apiGet()->redraw();
}
void Drone::animation(const double &height, const double &angle,
                      const double &distance) {
  route(height, angle, distance);
  double fall = -height;
  this->draw();
  std::initializer_list<std::pair<Animation::droneFPtr, const double &> >
      fPairL = {{&Drone::goVertical, height},
                {&Drone::rotate, angle},
                {&Drone::goForward, distance},
                {&Drone::goVertical, fall}};
  Animation::animeTime(fPairL, this);
  DInter::apiGet()->erase_shape(routeId);
  DInter::apiGet()->redraw();
}

void Drone::rotorSpin() {
  double angleS;
  for (uint32_t i = 0; i < 4; ++i) {
    angleS = 30;
    if (i % 2 == 0) angleS = -angleS;
    for (uint32_t j = 0; j < 2; ++j)
      rotorBlades[i][j].rotation(MatrixRot<3>(angleS, Axis::OZ));
  }
}

void Drone::lean(const double &angle) {
  MatrixRot<3> matrixR(angle, Axis::OX);
  dBody.rotation(MatrixRot<3>(angle, Axis::OX));
}

void Drone::route(const double &height, const double &angle,
                  const double &distance) {
  int tmp;
  tmp = DInter::apiGet()->draw_polygonal_chain(
      {convert(this->center), convert(this->center + Vector<3>({0, 0, height})),
       convert(this->orientation * MatrixRot<3>(angle, Axis::OZ) *
                   Vector<3>({0, distance, height}) +
               this->center),
       convert(this->orientation * MatrixRot<3>(angle, Axis::OZ) *
                   Vector<3>({0, distance, 0}) +
               this->center)},
      "blue");

  if (routeId != -1) {
    DInter::apiGet()->erase_shape(routeId);
  }
  routeId = tmp;
}