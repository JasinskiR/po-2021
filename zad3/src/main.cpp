#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr2D_gnuplot_api.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "Wektor2D.hh"

using namespace std;

// kolejnosc w jakiej powinny znalezc sie wierzcholki prostokata w pliku to LD
// PD PG LG

int main(int argc, char** argv) {
  Prostokat prostokat;
  char wybor;
  if (argc < 2) {
    cerr << "Brak nazwy pliku z prostokatem jako argument wywolania" << endl;
    exit(0);
  }
  if (prostokat.otworz(argv[1])) {
    shared_ptr<drawNS::Draw2DAPI> rysownik(
        new drawNS::APIGnuPlot2D(-10, 10, -10, 10, 0));
    cout << "\t\tMENU\n";
    cout << "o - obrot prostokata o zadany kat\n";
    cout << "p - przesuniecie prostokata o zadany wektor\n";
    cout << "w - wyswietlenie wspolrzednych wierzcholkow\n";
    cout << "m - wyswietl menu\n";
    cout << "c - wyczysc ekran menu\n";
    cout << "k - koniec dzialania programu\n ";
    prostokat.rysuj(rysownik);
    std::cout << "Twoj wybor? (m - menu) > ";
    while (cin >> wybor) {  // program zakonczy sie tylko poprzez podanie
                            // odpowiedniego przelacznika albo bledem
      switch (wybor) {
        case 'k': {  // wyjscie z programu
          exit(0);
        }
        case 'o': {
          // obrot a kat / potrzebny kat i ilosc powtorzen "o liczba liczba"
          double kat;
          cin >> kat;
          int l_pow;
          cin >> l_pow;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          kat = kat * l_pow;
          prostokat.rotacja(kat);
          prostokat.rysuj(rysownik);
          if (!prostokat.czy_prostokat()) {
            cerr<<"Podana figura nie jest juz prostokatem"<<endl;
            exit(0);
          }
          break;
        }

        case 'p': {
          // przesuniecie prostokata / potrzebny wektor
          double x, y;
          cin >> x >> y;
          Wektor2D W_translacji(x, y);
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          prostokat.translacje(W_translacji);
          prostokat.rysuj(rysownik);
          break;
        }
        case 'w': {
          // wyswietl wsporzedne
          cout << prostokat;
          break;
        }
        case 'm': {  // wyswietlenie menu
          cout << "\t\tMENU\n";
          cout << "o - obrot prostokata o zadany kat\n";
          cout << "p - przesuniecie prostokata o zadany wektor\n";
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
  } else {
    cerr << "Blad otwarcia pliku" << std::endl;
    exit(0);
  }
}