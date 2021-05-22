#include <iostream>

#include "Drone.hpp"
#include "Surface.hpp"

using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

int main() {
  shared_ptr<drawNS::Draw3DAPI> api(
      new drawNS::APIGnuPlot3D(-5, 5, -5, 5, -1, 10, -1));
  system("clear");
  Surface(-1, api);
  Vector<3> vector({0, 0, 0});
  Drone dron(vector, MatrixRot<3>());
  dron.draw(api);
  api->redraw();
  char choice;
  while (true) {
    system("clear");
    cout << "Obsluga drona \"BeeMo\"" << endl;
    cout << "a - animacja drona" << endl;
    cout << "w - wyswietl liczbe wektorow" << endl;
    cout << "k - wyjscie z programu" << endl;
    cout << "Twoj wybor? > ";
    cin >> choice;
    switch (choice) {
      case 'A':
      case 'a': {
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
        dron.animation(height, angle, distance, api);
        cout << "\nSymulacja zakonczona..." << endl;

        wait4key();
        break;
      }
      case 'W':
      case 'w': {
        cout << "\nAktualna ilosc obiektow klasy Vector: " << vector.rightNowG()
             << endl;
        cout << "Laczna ilosc obiektow klasy Vector: " << vector.overallG()
             << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        wait4key();
        break;
      }
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