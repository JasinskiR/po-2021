#ifndef DRONE_INTER_HPP
#define DRONE_INTER_HPP

class DroneI {
 public:
  virtual void goForward(const double &distance) = 0;

  virtual void goVertical(const double &height) = 0;

  virtual void rotate(const double &angle) = 0;

  virtual void animation(const double &height, const double &angle,
                         const double &distance) = 0;

  virtual void rotorSpin() = 0;

  virtual void route(const double &height, const double &angle,
                     const double &distance) = 0;

  virtual void lean(const double &angle) = 0;
  virtual ~DroneI() {}
};

#endif