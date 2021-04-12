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
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Odpowiedz;
  Statystyki Statystyka;
 // Statystyka.inicjuj();
  while (BazaT.pobierz_pytanie(WyrZ_PytanieTestowe)) {
    if (BazaT.get_read().good()) {
      Statystyka.zwieksz_lpyt();
      cout << "Zadanie " << Statystyka.get_lpytan() << ". ";
      cout << "Podaj wynik operacji : " << WyrZ_PytanieTestowe << " =" << endl;
      cout << "Twoja odpowiedz: ";
      cin >> Odpowiedz;
      while (!cin.good()) {
        if (Statystyka.get_proba() < 3) {
          Statystyka.zwieksz_p();
          cout
              << "\nBlad zapisu liczby zespolonej. Sprobuj jeszcze raz. (proba "
              << Statystyka.get_proba() << " z 3)" << endl
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
      if (Odpowiedz == WyrZ_PytanieTestowe.oblicz() &&
          Statystyka.get_proba() != 3) {
        Statystyka.wyzeruj_p();
        cout << "Odpowiedz poprawna" << endl;
        Statystyka.zwieksz_lpop();
      } else {
        Statystyka.wyzeruj_p();
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


