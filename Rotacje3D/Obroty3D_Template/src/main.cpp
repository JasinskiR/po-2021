#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr3D_gnuplot_api.hpp"
#include "Figure.hpp"
#include "MacierzRot.hpp"
#include "Scene.hpp"
#include "Wektor.hpp"

using namespace std;

int main(int argc, char** argv) {
  Figura bryla;
  Scene scena;
  bool status = false;
  char wybor;
  if (argc >= 2) {
    if (bryla.otworz(argv[1])) {
      if (bryla.wczytaj()) {
        status = true;
        scena.figures.push_back(bryla);
      }
    } else
      cerr << "Blad otwarcia pliku" << std::endl;
  } else {
    cout << "Brak nazwy pliku z wierzcholkami bryly jako argument wywolania"
         << endl;
    bryla.dodaj();
  }
  if (!bryla.czy_Figura()) {
    cerr << "Podana bryla nie jest prostopadloscianem" << endl;
    exit(0);
  }
  status = true;

  if (status) {
    shared_ptr<drawNS::Draw3DAPI> rysownik(
        new drawNS::APIGnuPlot3D(-10, 10, -10, 10, -10, 10, 0));
    // system("clear");
    cout << "\t\tMENU\n";
    cout << "a - dodaj nowa bryle\n";
    cout << "d - usun bryle\n";
    cout << "o - obrot bryly o zadany kat\n";
    cout << "p - przesuniecie bryly o zadany wektor\n";
    cout << "w - wyswietlenie wspolrzednych wierzcholkow\n";
    cout << "m - wyswietl menu\n";
    cout << "c - wyczysc ekran menu\n";
    cout << "k - koniec dzialania programu\n ";
    scena.rysuj(rysownik);
    std::cout << "Twoj wybor? (m - menu) > ";
    while (cin >> wybor) {  // program zakonczy sie tylko poprzez podanie
                            // odpowiedniego przelacznika albo bledem
      switch (wybor) {
        case 'k': {  // wyjscie z programu
          exit(0);
        }
        case 'a': {
          scena.Add(bryla);
          break;
        }
        case 'd': {
          uint32_t id_bryly;
          cin >> id_bryly;
          scena.Remove(id_bryly, rysownik);
          break;
        }
        case 'o': {
          // indeks bryly
          // obrot a kat / potrzebny kat i ilosc powtorzen "o liczba liczba"
          // oraz os obrotu
          uint32_t id_b;
          cin >> id_b;
          id_b -= 1;
          double kat;
          cin >> kat;
          uint32_t l_pow;
          cin >> l_pow;
          OS os;
          cin >> os;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          kat = kat * l_pow;
          scena[id_b].rotacja(kat, os);
          scena[id_b].rysuj(rysownik);
          if (!scena[id_b].czy_Figura()) {
            cerr << "Podana bryla nie jest juz prostopadloscianem" << endl;
            exit(0);
          }
          break;
        }

        case 'p': {
          uint32_t id_b;
          cin >> id_b;
          id_b -= 1;
          // przesuniecie bryly / potrzebny wektor
          double x, y, z;
          cin >> x >> y >> z;
          Wektor<3> W_translacji({x, y, z});
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          scena[id_b].translacje(W_translacji);
          scena[id_b].rysuj(rysownik);
          break;
        }
        case 'w': {
          uint32_t id_b;
          cin >> id_b;
          id_b -= 1;
          // wyswietl wsporzedne
          cout << scena[id_b];
          break;
        }
        case 'm': {  // wyswietlenie menu
          cout << "\t\tMENU\n";
          cout << "a - dodaj nowa bryle\n";
          cout << "d - usun bryle\n";
          cout << "o - obrot bryly o zadany kat\n";
          cout << "p - przesuniecie bryly o zadany wektor\n";
          cout << "w - wyswietlenie wspolrzednych wierzcholkow\n";
          cout << "m - wyswietl menu\n";
          cout << "c - wyczysc ekran menu\n";
          cout << "k - koniec dzialania programu\n ";
          break;
        }
        case 'c': {
          system("clear");
          break;
        }
        default: {
          continue;
        }
      }
      cout << "Twoj wybor? (m - menu) > ";
    }
  }
}