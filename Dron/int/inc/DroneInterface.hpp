#ifndef DRONE_INTER_HPP
#define DRONE_INTER_HPP

/**
 * @file
 * @brief Definicja klasy interfejs drona
 *
 */
/**
 * @brief Modeluje pojęcie klasy DoneI
 *
 */
class DroneI {
  std::string colour;

 public:
  /**
   * @brief Wirtualna metoda realizująca lot horyzontalny drona
   *
   * @param distance - odległośc do pokonania
   */
  virtual void goForward(const double &distance) = 0;

  /**
   * @brief Wirtualna metoda realizująca lot wertykalny drona
   *
   * @param height - wysokośc do wzniesienia
   */
  virtual void goVertical(const double &height) = 0;

  /**
   * @brief Wirtualna metoda realizująca obrót drona wokół osi OZ
   *
   * @param angle - kąt obrotu
   */
  virtual void rotate(const double &angle) = 0;

  /**
   * @brief Wirtualna metoda realizująca animację lotu drona
   *
   * @param height - wysokość lotu
   * @param angle - kąt rotacji
   * @param distance - dystans do przebycia
   */
  virtual void animation(const double &height, const double &angle,
                         const double &distance) = 0;

  /**
   * @brief Wirtualna metoda realizująca obrót łpoatek wirnika
   *
   */
  virtual void rotorSpin() = 0;

  /**
   * @brief Wirtualna metoda rysująca tor lotu drona
   *
   * @param height - wyokość lotu
   * @param angle - kąt odchylenia w poziomie
   * @param distance - dystans lotu
   */
  virtual void route(const double &height, const double &angle,
                     const double &distance) = 0;

  /**
   * @brief Wirtualna metoda realizująca pochylanie się drona podczas lotu
   *
   * @param angle - kąt pochylenia
   */
  virtual void lean(const double &angle) = 0;

  /**
   * @brief Wirtualny destruktor drona
   *
   */
  virtual ~DroneI() {}
  virtual std::string colourGet() { return colour; };
  virtual void colourSet(std::string colourN) { colour = colourN; };
  virtual void draw(std::string colour) = 0;
};

#endif