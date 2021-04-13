#include <iostream>
#include <limits>

#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT;

  if (!BazaT.otworz_baze_pytan(argv[1])) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej (odpowiedz podawac do 3 miejsca "
          "po przecinku): "
       << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Odpowiedz;
  Statystyki Statystyka;
  int proba = 0;
  // Statystyka.inicjuj();
  while (BazaT.pobierz_pytanie(WyrZ_PytanieTestowe)) {
    if (BazaT.get_read().good()) {
      Statystyka.zwieksz_lpyt();
      cout << "Zadanie " << Statystyka.get_lpytan() << ". ";
      cout << "Podaj wynik operacji : " << WyrZ_PytanieTestowe << " =" << endl;
      cout << "Twoja odpowiedz: ";
      cin >> Odpowiedz;

      while (!cin.good()) {
        if (proba < 3) {
          proba++;
          cout
              << "\nBlad zapisu liczby zespolonej. Sprobuj jeszcze raz. (proba "
              << proba << " z 3)" << endl
              << endl;
          cin.clear();
          cin.ignore(numeric_limits<int>::max(), '\n');
          cout << "Twoja odpowiedz: ";
          cin >> Odpowiedz;
        } else {
          cin.clear();
          cin.ignore(numeric_limits<int>::max(), '\n');
        }
      }
      if (Odpowiedz == WyrZ_PytanieTestowe.oblicz() && proba != 3) {
        proba=0;;
        cout << "Odpowiedz poprawna" << endl;
        Statystyka.zwieksz_lpop();
      } else {
        proba=0;;
        cout << "Blad. Prawidlowym wynikiem jest: "
             << WyrZ_PytanieTestowe.oblicz() << endl
             << endl;
      }
    } else
      BazaT.blad();
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << Statystyka;
  cout << endl;
}