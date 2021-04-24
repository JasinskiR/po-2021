#include "Menu.hh"
using namespace std;

void Menu::wyswietl(Prostokat prostokat) {
  drawNS::Draw2DAPI *rysownik = new drawNS::APIGnuPlot2D(-10, 10, -10, 10, 0);
  cout << *this;
  prostokat.rysuj(rysownik);
  cout << "Twoj wybor? (m - menu) > ";
  while (cin >> wybor) {  // program zakonczy sie tylko poprzez podanie
                          // odpowiedniego przelacznika albo bledem
    system("clear");
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
          cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
        kat = kat * l_pow;
        prostokat.rotacja(kat);
        if(!prostokat.czy_prostokat()) {
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
          cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
        prostokat.translacje(W_translacji);
        break;
      }
      case 'w': {
        // wyswietl wsporzedne
        cout << prostokat;
        break;
      }
      case 'm': {  // wyswietlenie menu
        cout << *this;
        break;
      }
      default:
        continue;  // znaki biale sa pomijane
    }
    prostokat.rysuj(rysownik);

    cout << "Twoj wybor? (m - menu) > ";
  }
  delete rysownik;
}

std::ostream &operator<<(std::ostream &strm, const Menu &Menu) {
  strm << "\t\tMENU\n";
  strm << "o - obrot prostokata o zadany kat\n";
  strm << "p - przesuniecie prostokata o zadany wektor\n";
  strm << "w - wyswietlenie wspolrzednych wierzcholkow\n";
  strm << "m - wyswietl menu\n";
  strm << "k - koniec dzialania programu\n ";

  return strm;
}