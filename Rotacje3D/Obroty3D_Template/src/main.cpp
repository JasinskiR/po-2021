#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr3D_gnuplot_api.hpp"
#include "Figure.hpp"
#include "MacierzRot.hpp"
#include "Wektor.hpp"

using namespace std;

int main(int argc, char** argv) {
  Figura figura;
  bool status = false;
  char wybor;
  if (argc >= 2) {
    if (figura.otworz(argv[1])) {
      if (figura.wczytaj()) status = true;
    } else
      cerr << "Blad otwarcia pliku" << std::endl;
  } else {
    cout << "Brak nazwy pliku z wierzcholkami bryly jako argument wywolania"
         << endl;
    for (int i = 0; i < 8; ++i) {
      cout << "\nPodaj wspolrzedne wierzcholka " << i + 1
           << " (trzy liczby odzielone spacja): ";
      cin >> figura[i];
    }
    if (!figura.czy_Figura()) {
      cerr << "Podana bryla nie jest prostopadloscianem" << endl;
      exit(0);
    }
    status = true;
  }

  if (status) {
    shared_ptr<drawNS::Draw3DAPI> rysownik(
        new drawNS::APIGnuPlot3D(-10, 10, -10, 10, -10, 10, 0));
    //system("clear");
    cout << "\t\tMENU\n";
    cout << "o - obrot bryly o zadany kat\n";
    cout << "p - przesuniecie bryly o zadany wektor\n";
    cout << "w - wyswietlenie wspolrzednych wierzcholkow\n";
    cout << "m - wyswietl menu\n";
    cout << "c - wyczysc ekran menu\n";
    cout << "k - koniec dzialania programu\n ";
    figura.rysuj(rysownik);
    std::cout << "Twoj wybor? (m - menu) > ";
    while (cin >> wybor) {  // program zakonczy sie tylko poprzez podanie
                            // odpowiedniego przelacznika albo bledem
      switch (wybor) {
        case 'k': {  // wyjscie z programu
          exit(0);
        }
        case 'o': {
          // obrot a kat / potrzebny kat i ilosc powtorzen "o liczba liczba"
          // oraz os obrotu
          double kat;
          cin >> kat;
          int l_pow;
          cin >> l_pow;
          OS os;
          cin >> os;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          kat = kat * l_pow;
          figura.rotacja(kat, os);
          figura.rysuj(rysownik);
          if (!figura.czy_Figura()) {
            cerr << "Podana figura nie jest juz prostokatem" << endl;
            exit(0);
          }
          break;
        }

        case 'p': {
          // przesuniecie bryly / potrzebny wektor
          double x, y, z;
          cin >> x >> y >> z;
          Wektor<3> W_translacji({x, y, z});
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          figura.translacje(W_translacji);
          figura.rysuj(rysownik);
          break;
        }
        case 'w': {
          // wyswietl wsporzedne
          cout << figura;
          break;
        }
        case 'm': {  // wyswietlenie menu
          cout << "\t\tMENU\n";
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