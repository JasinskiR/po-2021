#include <iostream>

#include "Drone.hpp"
#include "Surface.hpp"

using namespace std;

int main() {
  shared_ptr<drawNS::Draw3DAPI> api(
      new drawNS::APIGnuPlot3D(-5, 5, -5, 5, -1, 10, 100));
  system("clear");
  Surface(-1, api);
  Drone dron(Vector<3>({0, 0, 0}), MatrixRot<3>());
  dron.draw(api);
  char choice;
  while (true) {
    system("clear");
    cout << "Obsluga drona \"BeeMo\"" << endl;
    cout << "a - animacja drona" << endl;
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
      case 'K':
      case 'k':
        return 0;
      default:
        cout << "Nie rozpoznana opcja!" << endl;
        cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
  }
}