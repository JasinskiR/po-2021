#include "Drone.hpp"

#include <initializer_list>
#include <utility>

#include "Animation.hpp"

/**
 * @brief Funkcja realizująca ruch drona w poziomie
 * oraz aktualizuje układ współrzędnych
 *
 * @param distance - odległość jaką ma pokonać dron
 */
void Drone::goForward(const double &distance) {
  Vector<3> course({0, distance, 0});
  course = this->orientation * course;
  this->center = this->center + course;
}

/**
 * @brief Funkcja realizująca ruch drona w pionie
 * oraz aktualizuj układ współrzędnych
 *
 * @param height - wysokość na jaką ma się wznieść (lub opaść, jeżeli wartość
 * jest ujemna) dron
 */
void Drone::goVertical(const double &height) {
  Vector<3> altitude({0, 0, height});
  this->center = this->center + altitude;
}
/**
 * @brief Funkcja realizująca rotację drona w kierunku w którym ma polecieć
 *
 * @param angle - kąt o jaki ma się obrócić dron (znak zmiennej wpływa na
 * kierunek obrotu)
 */
void Drone::rotate(const double &angle) {
  MatrixRot<3> matrixR(angle, Axis::OZ);
  this->orientation = this->orientation * matrixR;
}
/**
 * @brief Funkcja rysująca obiekt dron wraz z jego elementami
 *
 */
void Drone::draw() {
  dBody.draw();
  for (uint32_t i = 0; i < 4; ++i) rotor[i].draw();
  for (uint32_t i = 0; i < 2; ++i) searchlight[i].draw();
  for (uint32_t i = 0; i < 4; ++i) {
    for (uint32_t j = 0; j < 2; ++j) rotorBlades[i][j].draw();
  }
  DInter::apiGet()->redraw();
}
/**
 * @brief Funkcja realizująca animację ruchu drona
 *
 * @param height - wysokość przelotu drona
 * @param angle - kąt rotacji drona
 * @param distance - odległośc jaką ma pokonać dron
 */
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
/**
 * @brief Funkcja odpowiedzialna za rotację łopatek wirników
 *
 */
void Drone::rotorSpin() {
  double angleS;
  for (uint32_t i = 0; i < 4; ++i) {
    angleS = 30;
    if (i % 2 == 0) angleS = -angleS;
    for (uint32_t j = 0; j < 2; ++j)
      rotorBlades[i][j].rotation(MatrixRot<3>(angleS, Axis::OZ));
  }
}
/**
 * @brief Funkcja pochylająca drona w kierunku w kótrym leci
 *
 * @param angle - kąt o jaki ma się pochylić dron
 */
void Drone::lean(const double &angle) {
  MatrixRot<3> matrixR(angle, Axis::OX);
  dBody.rotation(MatrixRot<3>(angle, Axis::OX));
}
/**
 * @brief Funkcja budująca planowaną trasę drona
 *
 * @param height - trasa pionowa lotu
 * @param angle - kąt odchylenia trasy
 * @param distance - długość trasy
 */
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

// void Drone::removeD() {
//   if (id != -1) {
//     DInter::apiGet()->erase_shape(id);
//     DInter::apiGet()->redraw();
//   }
// }