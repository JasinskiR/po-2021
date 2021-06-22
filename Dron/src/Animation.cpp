#include "Animation.hpp"

#include "Scene.hpp"
/**
 * @brief Przypisanie wartości do statycznej zmiennej odpowiedzialnej za
 * prędkość ruchów obiektu
 *
 */
double Animation::velocity = 10;
/**
 * @brief Stała wysokości drona
 *
 */
#define droneConst 0.25

/**
 * Na podstawie przesłannej zmiennej interpretuje zmienną liczbę klatek do
 * wyświetlenia Wykonuje proces animacji oraz opóźnienia dla każdego przesłanego
 * wskaźnika na funkcję
 * @param fPairL - lista par składających się z wskaźnika na funkcję oraz
 * zmiennej, która ta funkcja przyjmuje
 * @param dron - wskaźnik na aktualny obiekt
 * @param height - wysokość przelotu
 */
void Animation::animeTime(
    std::initializer_list<std::pair<droneFPtr, const double&> > fPairL,
    Drone* dron, double height) {
  double fps = 0;
  double fall = -height;

  for (auto fPair : fPairL) {
    double time = std::abs(fPair.second / velocity);

    // If rotation of drone
    if (fPair.first == &Drone::rotate)
      fps = 2.5 * time;
    else
      // else other drone movement
      fps = 45 * time;

    for (double i = 0; i < fps; ++i) {
      if (fPair.first == &Drone::goVertical && fPair.second < 0) {
        (dron->*(fPair.first))(
            fall / fps);  // wykonanie opadanie od zminnej fall, która może
        // się zmienić w dalszej części funkcji
      }

      else {
        (dron->*(fPair.first))(fPair.second / fps);
      }

      if (fPair.first == &Drone::goForward) {
        bool col = false;  // collision
        for (uint32_t i = 0; i < Scene::getList().size(); ++i) {
          if (std::dynamic_pointer_cast<Drone>(Scene::getList()[i]).get() !=
              dron) {
            if (Scene::getList()[i]->collision(dron, dron->cords()[2])) {
              std::cout
                  << "Wysokie prawdopodobienstwo kolizji. Awaryjne ladowanie"
                  << std::endl;
              col = true;
            }
          }
          if (col) {
            (dron->*(fPair.first))(-fPair.second / fps);
            break;
          }
        }
      }

      dron->rotorSpin();
      dron->draw(dron->colourGet());
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Sprawdzanie czy można wylądować
    if (fPair.first == &Drone::goForward) {
      bool var = true;

      while (var) {
        for (uint32_t i = 0; i < Scene::getList().size(); ++i) {
          if (std::dynamic_pointer_cast<Drone>(Scene::getList()[i]).get() !=
              dron) {  // czy nie jest samym sobą

            if (Scene::getList()[i]->isAbove(dron, dron->cords()[2])) {
              while (Scene::getList()[i]->canLand(dron, dron->cords()[2]) ==
                     false) {
                dron->goForward(0.1);
                dron->rotorSpin();
                dron->draw(dron->colourGet());
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                if (!Scene::getList()[i]->isAbove(dron, dron->cords()[2]))
                  break;
              }
              if (Scene::getList()[i]->canLand(dron, dron->cords()[2])) {
                var = false;  // wyjście z głównej pętli jedynie kiedy
                              // dron może wylądować
                fall = -(dron->cords()[2] - 2 * droneConst -
                         std::dynamic_pointer_cast<BlockI>(Scene::getList()[i])
                             ->getHeight());
              } else
                fall = -(dron->cords()[2] - 2 * droneConst);
              var = false;
            }
          }
          if (!var) break;
        }
      }
    }
  }
}

// double Animation::varFlight(double i, double fps) {
//   if (i * 9 < 3 * fps) return (fps * (i * 2 + 1) / 9);
//   // if (i * 9 >= 6) return ();
//   else
//     return fps;
// }
