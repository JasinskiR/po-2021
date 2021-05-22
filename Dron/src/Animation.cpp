#include "Animation.hpp"

/**
 * @brief Przypisanie wartości do statycznej zmiennej odpowiedzialnej za
 * prędkość ruchów obiektu
 *
 */
double Animation::velocity = 10;

/**
 * Na podstawie przesłannej zmiennej interpretuje zmienną liczbę klatek do
 * wyświetlenia Wykonuje proces animacji oraz opóźnienia dla każdego przesłanego
 * wskaźnika na funkcję
 * @param fPairL - lista par składających się z wskaźnika na funkcję oraz
 * zmiennej, która ta funkcja przyjmuje
 * @param dron - wskaźnik na aktualny obiekt
 * @param api - wskaźnik do dołączonej klasy Gnuplot
 */
void Animation::animeTime(
    std::initializer_list<std::pair<droneFPtr, const double&> > fPairL,
    Drone* dron, std::shared_ptr<drawNS::Draw3DAPI> api) {
  double fps = 0;
  for (auto fPair : fPairL) {
    double time = std::abs(fPair.second / velocity);

    // If rotation of drone
    if (fPair.first == &Drone::rotate)
      fps = 2.5 * time;
    else
      // else other drone movement
      fps = 45 * time;
    for (double i = 0; i < fps; ++i) {
      (dron->*(fPair.first))(fPair.second / fps);

      if (fPair.first == &Drone::goForward) {
        // forward tilt//
        if (i * 9 < 3 * fps) dron->lean(-(velocity / 12));
        // flight with const tilt//
        // flight stabilization//
        if (i * 9 >= 6 * fps && i * 9 < 7 * fps) dron->lean((velocity / 4));
        // backward tilt//
        if (i * 9 >= 7 * fps && i * 9 < 8 * fps) dron->lean((velocity / 8));
        // flight stabilization//
        if (i * 9 >= 8 * fps) dron->lean(-(velocity / 8));
      }

      (dron->draw(api));
      api->redraw();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
}


