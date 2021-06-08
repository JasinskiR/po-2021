#include <iostream>

#include "Scene.hpp"

using namespace std;

/**
 * @brief Funkcja, która oczekuje na dowolny znak od użytkownika
 * Pełni rolę tymczasowego przerwania działania programu
 *
 */
void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

/**
 * @brief  Funkcja main
 *
 * Zawiera główną funkcjonalność programu
 * @return int - informacja o powodzeniu, bądź nie programu
 */
int main() {
  bool var = true;
  {
    system("clear");
    Scene scene;
    char choice;
    while (var) {
      system("clear");
      cout << "Obsluga drona \"BeeMo\"" << endl;
      cout << "a - animacja aktywnego drona" << endl;
      cout << "d - dodaj element" << endl;
      cout << "c - wybierz aktywnego drona" << endl;
      cout << "u - usun element" << endl;
      cout << "p - wyswietl id elementow" << endl;
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
              cout
                  << "Wysokosc przelotowa powinna byc wieksza od zera, sprobuj "
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
              cout << "Blednie podany kat roatcji, sprobuj jeszcze raz:"
                   << endl;
              continue;
            } else
              break;
          }
          cout << "\nOdlegosc do pokonania" << endl
               << "(wartosc dodatnia odpowiedzialna za ruch drona do przodu)"
               << endl
               << "(wartosc ujemna odpowiedzialna za ruch drona do tylu)"
               << endl
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
          cin.clear();
          cin.ignore(std::numeric_limits<int>::max(), '\n');
          scene.sAnimation(height, angle, distance);
          cout << "\nSymulacja zakonczona..." << endl;

          wait4key();
          break;
        }
        case 'D':
        case 'd': {
          scene.add();
          break;
        }
        case 'W':
        case 'w': {
          cout << "\nAktualna ilosc obiektow klasy Vector: "
               << Vector<3>::rightNowG() << endl;
          cout << "Laczna ilosc obiektow klasy Vector: "
               << Vector<3>::overallG() << endl;
          cin.clear();
          cin.ignore(std::numeric_limits<int>::max(), '\n');
          wait4key();
          break;
        }

        case 'U':
        case 'u': {
          scene.removeE();
          break;
        }
        case 'P':
        case 'p': {
          scene.print();
          cin.clear();
          cin.ignore(std::numeric_limits<int>::max(), '\n');
          wait4key();
          break;
        }
        case 'C':
        case 'c': {
          scene.choosenD();
          break;
        }
        case 'K':
        case 'k':
          var = false;
          break;
        default:
          cout << "Nie rozpoznana opcja!" << endl;
          cin.clear();
          cin.ignore(std::numeric_limits<int>::max(), '\n');
      }
    }
  }
  cout << "Ilosc wektorow po zakonczeniu dzialania programu:" << endl;
  cout << "\nAktualna ilosc obiektow klasy Vector: " << Vector<3>::rightNowG()
       << endl;
  cout << "Laczna ilosc obiektow klasy Vector: " << Vector<3>::overallG()
       << endl;
}
