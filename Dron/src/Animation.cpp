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
  for (auto fPair : fPairL) {
    double time = std::abs(fPair.second / velocity);
    if (fPair.first == &Drone::rotate) {
      double fps = 2.5 * time;
      for (double i = 0; i < fps; ++i) {
        (dron->*(fPair.first))(fPair.second / fps);
        (dron->draw(api));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    } else {
      double fps = 45 * time;
      for (double i = 0; i < fps; ++i) {
        (dron->*(fPair.first))(fPair.second / fps);
        (dron->draw(api));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }
}