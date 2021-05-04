#include <fstream>
#include <iomanip>
#include <iostream>

#include "Dr2D_gnuplot_api.hh"
#include "Figure.hh"
#include "MacierzRot.hh"
#include "Wektor.hh"

using namespace std;

int main(int argc, char** argv) {
  Wektor<3> a({1.0,2.0,3.0});
  Wektor<3> b({4.0,5.0,6.0});
  Wektor<3> c({7.0,8.0,9.0});
  
MacierzRot<3> d({a,b,c});
MacierzRot<3> e({c,b,a});
cout<<d*e;


  //Wektor<2> wektor;
  Figura figura;
  bool status = false;
  char wybor;
  if (argc >= 2) {
    if (figura.otworz(argv[1])) {
      if (figura.wczytaj()) status = true;
    } else
      cerr << "Blad otwarcia pliku" << std::endl;
  } else {
    cout << "Brak nazwy pliku z figura jako argument wywolania" << endl;
    for (int i = 0; i < 4; ++i) {
      cout << "\nPodaj wspolrzedne wierzcholka " << i + 1
           << " (dwie liczby odzielone spacja): ";
      cin >> figura[i];
    }
    if (!figura.czy_Figura()) {
      cerr << "Podana figura nie jest prostokatem" << endl;
      exit(0);
    }
    status = true;
  }

  if (status) {
    shared_ptr<drawNS::Draw2DAPI> rysownik(
        new drawNS::APIGnuPlot2D(-10, 10, -10, 10, 0));
    cout << "\t\tMENU\n";
    cout << "o - obrot figuraa o zadany kat\n";
    cout << "p - przesuniecie figuraa o zadany wektor\n";
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
          double kat;
          cin >> kat;
          int l_pow;
          cin >> l_pow;
          if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
          }
          kat = kat * l_pow;
          figura.rotacja(kat);
          figura.rysuj(rysownik);
          if (!figura.czy_Figura()) {
            cerr << "Podana figura nie jest juz prostokatem" << endl;
            exit(0);
          }
          break;
        }

        case 'p': {
          // przesuniecie figuraa / potrzebny wektor
          double x, y;
          cin >> x >> y;
          Wektor<2> W_translacji({x, y});
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
          cout << "o - obrot figuraa o zadany kat\n";
          cout << "p - przesuniecie figuraa o zadany wektor\n";
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