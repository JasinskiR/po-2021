#include "Scene.hpp"

#include "CuboidPlat.hpp"
#include "Hill.hpp"
#include "Plateau.hpp"

#define TAB 9
#define ENTER 13

/**
 * @brief Konstruktor nowego obiektu klasy Scene
 * Odpowiada za stworzenie powierzchni oraz podstawowych elemntów krajobrazu
 * wraz z dronem
 *
 */
Scene::Scene() {
  Surface surf(-1);
  surf.draw("purple");
  Vector<3> droneBase({0, 0, -0.75});
  Vector<3> hillBase({3, 3, -1});
  Vector<3> platBase({-3, -3, -1});
  objectL.push_back(std::dynamic_pointer_cast<LandI>(
      std::shared_ptr<Hill>(new Hill(hillBase, MatrixRot<3>(), 3, {1, 3}))));
  objectL.push_back(std::dynamic_pointer_cast<LandI>(
      std::shared_ptr<Plat>(new Plat(platBase, MatrixRot<3>(), 2, {1, 3}))));

  activeD = std::make_shared<Drone>(droneBase, MatrixRot<3>());
  objectL.push_back(std::dynamic_pointer_cast<LandI>(activeD));
}

/**
 * @brief Wywietla wszystkie dostępne elementy krajobrazu wraz z ich ondeksem
 * oraz wektorem położenia
 * Oddzielnie są wyświtlane dostepne drony oraz przeskody
 *
 */
void Scene::print() {
  std::cout << "\nPRZESZKODY NATURALNE: " << std::endl;
  for (uint32_t i = 0, j = 1; i < objectL.size(); ++i) {
    if (std::dynamic_pointer_cast<BlockI>(this->objectL[i]) != nullptr)
      std::cout << "Przeszkoda o indeksie: " << j++ << " " << objectL[i]->type()
                << "\no wspolrzednych: " << objectL[i]->cords() << std::endl;
  }
  std::cout << "DRONY: " << std::endl;
  for (uint32_t i = 0, j = 1; i < objectL.size(); ++i) {
    if (std::dynamic_pointer_cast<DroneI>(this->objectL[i]) != nullptr) {
      std::cout << "Dron o indeksie: " << j++ << " " << objectL[i]->type()
                << "\no wspolrzednych: " << objectL[i]->cords() << std::endl;
    }
  }
}

/**
 * @brief Funkcja pozwalająca na symulację ruchu drona
 *
 * @param index - indeks drona, który ma być animowany
 * @param height - wyokośc przelotu
 * @param angle - kąt obrotu
 * @param distance - dystans do przebycia
 */
void Scene::sAnimation(const double &height, const double &angle,
                       const double &distance) {
  if (activeD != NULL)
    activeD->animation(height, angle, distance);
  else
    std::cout << "Nie wybrano drona!" << std::endl;
}

/**
 * @brief Funkcja pozwalająca dodanie nowego elementu do sceny
 * element jest przechowywany jest w vectorze elementów krajobrazu
 *
 */
void Scene::add() {
  std::cout << "p - Dodaj przeszkode" << std::endl;
  std::cout << "d - Dodaj drone" << std::endl;
  char option = 'a';
  std::cin >> option;
  switch (option) {
    case 'P':
    case 'p': {
      bool var = true;
      int choiceN = 0;
      while (var) {
        std::cout << "Wybierz rodzaj elementu krajobrazu: " << std::endl;
        std::cout << "1 - Wzgorze" << std::endl;
        std::cout << "2 - Plaskowyz" << std::endl;
        std::cout << "3 - Plaskowyz prosty" << std::endl;
        std::cout << "Twoj wybor? > ";
        std::cin >> choiceN;
        switch (choiceN) {
          case 1: {
            std::cout << "Podaj wektor polozenia wzgorza (x,y) (bez nawiasow, "
                         "wartosci odzielone znakiem bialym):";
            double x, y;
            while (true) {
              std::cin >> x;
              std::cin >> y;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout
                    << "Blednie podane wspolrzedne, sprobuj jeszcze raz : "
                    << std::endl;
                continue;
              } else
                break;
            }
            std::cout << "Podaj wysokosc wzgorza: ";
            double height;
            while (true) {
              std::cin >> height;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podana wysokosc, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            std::cout
                << "Podaj zakres rozmiaru wzgorza (min,max) (bez nawiasow, "
                   "wartosci odzielone znakiem bialym):";
            int min, max;
            while (true) {
              std::cin >> min;
              std::cin >> max;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podany zakres, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            objectL.push_back(
                std::dynamic_pointer_cast<LandI>(std::shared_ptr<Hill>(
                    new Hill(Vector<3>({x, y, -1}), MatrixRot<3>(), height,
                             {min, max}))));
            var = false;
            break;
          }
          case 2: {
            std::cout
                << "Podaj wektor polozenia plaskowyzu (x,y) (bez nawiasow, "
                   "wartosci odzielone znakiem bialym):";
            double x, y;
            while (true) {
              std::cin >> x;
              std::cin >> y;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout
                    << "Blednie podane wspolrzedne, sprobuj jeszcze raz : "
                    << std::endl;
                continue;
              } else
                break;
            }
            std::cout << "Podaj wysokosc plaskowyzu: ";
            double height;
            while (true) {
              std::cin >> height;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podana wysokosc, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            std::cout << "Podaj zakres rozmiaru plaskowyzu (min,max) (bez "
                         "nawiasow, wartosci odzielone znakiem bialym):";
            int min, max;
            while (true) {
              std::cin >> min;
              std::cin >> max;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podany zakres, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            objectL.push_back(
                std::dynamic_pointer_cast<LandI>(std::shared_ptr<Plat>(
                    new Plat(Vector<3>({x, y, -1}), MatrixRot<3>(), height,
                             {min, max}))));
            var = false;
            break;
          }
          case 3: {
            std::cout << "Podaj wektor polozenia plaskowyzu prostego (x,y) "
                         "(bez nawiasow, "
                         "wartosci odzielone znakiem bialym):";
            double x, y;
            while (true) {
              std::cin >> x;
              std::cin >> y;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout
                    << "Blednie podane wspolrzedne, sprobuj jeszcze raz : "
                    << std::endl;
                continue;
              } else
                break;
            }
            std::cout << "Podaj wysokosc plaskowyzu prostego: ";
            double height;
            while (true) {
              std::cin >> height;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podana wysokosc, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            std::cout << "Podaj szerokosc plaskowyzu prostego: ";
            double width;
            while (true) {
              std::cin >> width;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podana szerokosc, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            std::cout << "Podaj glebokosc plaskowyzu prostego: ";
            double depth;
            while (true) {
              std::cin >> depth;
              if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Blednie podana glebokosc, sprobuj jeszcze raz:"
                          << std::endl;
                continue;
              } else
                break;
            }
            objectL.push_back(
                std::dynamic_pointer_cast<LandI>(std::shared_ptr<CubPlat>(
                    new CubPlat(Vector<3>({x, y, -1}), MatrixRot<3>(), height,
                                width, depth))));
            var = false;
            break;
          }
          default: {
            std::cout << "Nie rozpoznana opcja!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
          }
        }
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      break;
    }
    case 'D':
    case 'd': {
      std::cout << "Podaj wektor polozenia drona (x,y) (bez nawiasow, wartosci "
                   "odzielone znakiem bialym):";
      double x, y;
      while (true) {
        std::cin >> x;
        std::cin >> y;
        if (!std::cin.good()) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<int>::max(), '\n');
          std::cout << "Blednie podane wspolrzedne, sprobuj jeszcze raz:"
                    << std::endl;
          continue;
        } else
          break;
      }
      objectL.push_back(
          std::dynamic_pointer_cast<LandI>(std::shared_ptr<DroneI>(
              new Drone(Vector<3>({x, y, -0.75}), MatrixRot<3>()))));
      break;
    }
  }
}

/**
 * @brief Funkcja pozwalająca usunięcie dostępnego elementu ze sceny
 *
 */
void Scene::removeE() {
  bool var = true;
  int choiceN = 0;
  while (var) {
    std::cout << "Wybierz rodzaj elementu do usuniecia: " << std::endl;
    std::cout << "1 - Przeszkoda" << std::endl;
    std::cout << "2 - Dron" << std::endl;
    std::cout << "Twoj wybor? > ";
    std::cin >> choiceN;
    switch (choiceN) {
      case 1: {
        std::cout << "Podaj id przeszkody:";
        int index;
        while (true) {
          std::cin >> index;
          if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Blednie podane id, sprobuj jeszcze raz:" << std::endl;
            continue;
          } else
            break;
        }
        objectL.erase(objectL.begin() + getObstacleIndex(index - 1));
        var = false;
        break;
      }
      case 2: {
        std::cout << "Podaj id drona:";
        int index;
        while (true) {
          std::cin >> index;
          if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Blednie podane id, sprobuj jeszcze raz:" << std::endl;
            continue;
          } else
            break;
        }
        objectL.erase(objectL.begin() + getDroneIndex(index - 1));
        var = false;
        break;
      }
      default: {
        std::cout << "Nie rozpoznana opcja!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        break;
      }
    }
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

/**
 * @brief Funkcja zwracająca indeks poszukiwanego drona w vectorze elementów
 * krajobrazu
 *
 * @param index - indeks drona który chcemy znaleźć
 * @return uint32_t - liczba reprezentująca indeks szukanego drona w vectorze
 * elementów
 */
uint32_t Scene::getDroneIndex(const uint32_t &index) const {
  uint32_t find = 0;
  for (uint32_t i = 0; i < this->objectL.size(); ++i) {
    if (std::dynamic_pointer_cast<DroneI>(this->objectL[i]) != nullptr) {
      if (find == index) {
        return i;
      }
      find++;
    }
  }
  throw std::out_of_range{"Dron id = <" + std::to_string(index + 1) +
                          "> out of range!"};
}

/**
 * @brief Funkcja zwracająca indeks poszukiwanej przeszkody w vectorze elementów
 * krajobrazu
 *
 * @param index indeks przeszkody którą chcemy znaleźć
 * @return uint32_t - liczba reprezentująca indeks szukanej przeszkody w
 * vectorze elementów
 */
uint32_t Scene::getObstacleIndex(const uint32_t &index) const {
  uint32_t find = 0;
  for (uint32_t i = 0; i < this->objectL.size(); ++i) {
    if (std::dynamic_pointer_cast<BlockI>(this->objectL[i]) != nullptr) {
      if (find == index) {
        return i;
      }
      find++;
    }
  }
  throw std::out_of_range{"Obstacle id = <" + std::to_string(index + 1) +
                          "> out of range!"};
}

void Scene::choosenD() {
  std::vector<std::shared_ptr<DroneI>> droneL;
  for (uint32_t i = 0; i < this->objectL.size(); ++i) {
    if (std::dynamic_pointer_cast<DroneI>(this->objectL[i]) != nullptr) {
      droneL.push_back(std::dynamic_pointer_cast<DroneI>(this->objectL[i]));
    }
  }
  char tab;
  std::cout << "Wybierz drona klikajac TAB " << std::endl;
  std::cout << "Naciśnięcie klawisza ENTER zatwierdza wybór " << std::endl;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
  system("stty raw");
  activeD->draw("green");
  static std::size_t i = 0;
  for (;;) {
    tab = std::cin.get();
    if (tab == TAB) {
      if (++i == droneL.size()) i = 0;
      activeD->draw("red");
      activeD = droneL[i];
      activeD->draw("green");
    }
    if (tab == ENTER) {
      activeD->colourSet("green");
      break;
    }
  }
  system("stty cooked");
}