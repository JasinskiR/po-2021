#include <iostream>

#include "Scene.hpp"

using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

int main() {
  system("clear");
  Scene scene;
  char choice;
  while (true) {
    system("clear");
    cout << "Obsluga drona \"BeeMo\"" << endl;
    cout << "a - animacja drona" << endl;
    cout << "d - dodaj drona" << endl;
    // cout << "u - usun element" << endl;
    cout << "p - dodaj przeszkode" << endl;
    cout << "w - wyswietl liczbe wektorow" << endl;
    cout << "k - wyjscie z programu" << endl;
    cout << "Twoj wybor? > ";
    cin >> choice;
    switch (choice) {
      case 'A':
      case 'a': {
        int id;
        cout << "Podaj id drona: ";
        cin >> id;
        double height;
        double angle;
        double distance;
        cout << "Podaj wysokosc przelotowa: ";
        while (true) {
          cin >> height;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Blednie podana wysokosc przelotowa, sprobuj jeszcze raz:"
                 << endl;
            continue;
          } else if (height <= 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Wysokosc przelotowa powinna byc wieksza od zera, sprobuj "
                    "jeszcze raz:"
                 << endl;
            continue;
          } else
            break;
        }
        cout << "\nRotacja drona" << endl
             << "(wartosc dodatnia odpowiedzialna za rotacje drona w lewo)"
             << endl
             << "(wartosc ujemna odpowiedzialna za rotacje drona w prawo)"
             << endl
             << "Podaj kat rotacji drona: ";
        while (true) {
          cin >> angle;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Blednie podany kat roatcji, sprobuj jeszcze raz:" << endl;
            continue;
          } else
            break;
        }
        cout << "\nOdlegosc do pokonania" << endl
             << "(wartosc dodatnia odpowiedzialna za ruch drona do przodu)"
             << endl
             << "(wartosc ujemna odpowiedzialna za ruch drona do tylu)" << endl
             << "Podaj odlegosc: ";
        while (true) {
          cin >> distance;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Blednie podany dystans, sprobuj jeszcze raz:" << endl;
            continue;
          } else
            break;
        }
        system("clear");
        cout << "Rozpoczecie symulacji ruchu drona..." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        scene.sAnimation(id - 1, height, angle, distance);
        cout << "\nSymulacja zakonczona..." << endl;

        wait4key();
        break;
      }
      case 'W':
      case 'w': {
        cout << "\nAktualna ilosc obiektow klasy Vector: "
             << Vector<3>::rightNowG() << endl;
        cout << "Laczna ilosc obiektow klasy Vector: " << Vector<3>::overallG()
             << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        wait4key();
        break;
      }

      case 'P':
      case 'p': {
        bool var = true;
        int choiceN = 0;
        while (var) {
          cout << "Wybierz rodzaj elementu krajobrazu: " << endl;
          cout << "1 - Wzgorze" << endl;
          cout << "2 - Plaskowyz" << endl;
          cout << "Twoj wybor? > ";
          cin >> choiceN;
          switch (choiceN) {
            case 1: {
              cout << "Podaj wektor polozenia wzgorza (x,y) (bez nawiasow, "
                      "wartosci odzielone znakiem bialym):";
              double x, y;
              while (true) {
                cin >> x;
                cin >> y;
                if (!cin.good()) {
                  cin.clear();
                  cin.ignore(std::numeric_limits<int>::max(), '\n');
                  cout << "Blednie podane wspolrzedne, sprobuj jeszcze raz:"
                       << endl;
                  continue;
                } else
                  break;
              }
              cout << "Podaj wysokosc wzgorza: ";
              double height;
              while (true) {
                cin >> height;
                if (!cin.good()) {
                  cin.clear();
                  cin.ignore(std::numeric_limits<int>::max(), '\n');
                  cout << "Blednie podana wysokosc, sprobuj jeszcze raz:"
                       << endl;
                  continue;
                } else
                  break;
              }
              cout << "Podaj zakres rozmiaru wzgorza (min,max) (bez nawiasow, "
                      "wartosci odzielone znakiem bialym):";
              int min, max;
              while (true) {
                cin >> min;
                cin >> max;
                if (!cin.good()) {
                  cin.clear();
                  cin.ignore(std::numeric_limits<int>::max(), '\n');
                  cout << "Blednie podany zakres, sprobuj jeszcze raz:" << endl;
                  continue;
                } else
                  break;
              }
              scene.addHill(Vector<3>({x, y, -1}), height, {min, max});
              var = false;
              break;
            }
            case 2: {
              cout << "Podaj wektor polozenia plaskowyzu (x,y) (bez nawiasow, "
                      "wartosci odzielone znakiem bialym):";
              double x, y;
              while (true) {
                cin >> x;
                cin >> y;
                if (!cin.good()) {
                  cin.clear();
                  cin.ignore(std::numeric_limits<int>::max(), '\n');
                  cout << "Blednie podane wspolrzedne, sprobuj jeszcze raz:"
                       << endl;
                  continue;
                } else
                  break;
              }
              cout << "Podaj wysokosc plaskowyzu: ";
              double height;
              while (true) {
                cin >> height;
                if (!cin.good()) {
                  cin.clear();
                  cin.ignore(std::numeric_limits<int>::max(), '\n');
                  cout << "Blednie podana wysokosc, sprobuj jeszcze raz:"
                       << endl;
                  continue;
                } else
                  break;
              }
              cout << "Podaj zakres rozmiaru plaskowyzu (min,max) (bez "
                      "nawiasow, wartosci odzielone znakiem bialym):";
              int min, max;
              while (true) {
                cin >> min;
                cin >> max;
                if (!cin.good()) {
                  cin.clear();
                  cin.ignore(std::numeric_limits<int>::max(), '\n');
                  cout << "Blednie podany zakres, sprobuj jeszcze raz:" << endl;
                  continue;
                } else
                  break;
              }
              scene.addPlat(Vector<3>({x, y, -1}), height, {min, max});
              var = false;
              break;
            }
            default: {
              cout << "Nie rozpoznana opcja!" << endl;
              cin.clear();
              cin.ignore(std::numeric_limits<int>::max(), '\n');
              break;
            }
          }
        }
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        break;
      }
      case 'D':
      case 'd': {
        cout << "Podaj wektor polozenia wzgorza (x,y) (bez nawiasow, wartosci "
                "odzielone znakiem bialym):";
        double x, y;
        while (true) {
          cin >> x;
          cin >> y;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Blednie podane wspolrzedne, sprobuj jeszcze raz:" << endl;
            continue;
          } else
            break;
        }
        scene.addDron(Vector<3>({x, y, -0.75}));
        break;
      }
      // case 'U':
      // case 'u': {
      //   bool var = true;
      //   int choiceN = 0;
      //   while (var) {
      //     cout << "Wybierz rodzaj elementu do usuniecia: " << endl;
      //     cout << "1 - Wzgorze" << endl;
      //     cout << "2 - Plaskowyz" << endl;
      //     cout << "3 - Dron" << endl;
      //     cout << "Twoj wybor? > ";
      //     cin >> choiceN;
      //     switch (choiceN) {
      //       case 1: {
      //         cout << "Podaj id wzgorza:";
      //         int id;
      //         while (true) {
      //           cin >> id;
      //           if (!cin.good()) {
      //             cin.clear();
      //             cin.ignore(std::numeric_limits<int>::max(), '\n');
      //             cout << "Blednie podane id, sprobuj jeszcze raz:" << endl;
      //             continue;
      //           } else
      //             break;
      //         }
      //         scene.removeH(id-1);
      //         var = false;
      //         break;
      //       }
      //       case 2: {
      //         cout << "Podaj id plaskowyzu:";
      //         int id;
      //         while (true) {
      //           cin >> id;
      //           if (!cin.good()) {
      //             cin.clear();
      //             cin.ignore(std::numeric_limits<int>::max(), '\n');
      //             cout << "Blednie podane id, sprobuj jeszcze raz:" << endl;
      //             continue;
      //           } else
      //             break;
      //         }
      //         scene.removeP(id-1);
      //         var = false;
      //         break;
      //       }
      //       case 3: {
      //         cout << "Podaj id drona:";
      //         int id;
      //         while (true) {
      //           cin >> id;
      //           if (!cin.good()) {
      //             cin.clear();
      //             cin.ignore(std::numeric_limits<int>::max(), '\n');
      //             cout << "Blednie podane id, sprobuj jeszcze raz:" << endl;
      //             continue;
      //           } else
      //             break;
      //         }
      //         scene.removeD(id-1);
      //         var = false;
      //         break;
      //       }
      //       default: {
      //         cout << "Nie rozpoznana opcja!" << endl;
      //         cin.clear();
      //         cin.ignore(std::numeric_limits<int>::max(), '\n');
      //         break;
      //       }
      //     }
      //   }
      //   cin.clear();
      //   cin.ignore(std::numeric_limits<int>::max(), '\n');
      //   break;
      // }
      case 'K':
      case 'k':
        return 0;
      default:
        cout << "Nie rozpoznana opcja!" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
  }
}