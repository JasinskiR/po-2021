#include <iostream>
#include <limits>

#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT, argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Odpowiedz;
  Statystyki Statystyka;
  inicjuj(Statystyka);
  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe)) {
    zwieksz_lpyt(Statystyka);

    cout << "Podaj wynik operacji : " << WyrZ_PytanieTestowe << " =" << endl;
    cout << "Twoja odpowiedz: ";
    cin >> Odpowiedz;
    while (!cin.good()) {
      if (Statystyka.proba < 3) {
        zwieksz_p(Statystyka);
        cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz. (proba "
             << Statystyka.proba << " z 3)" << endl
             << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Twoja odpowiedz: ";
        cin >> Odpowiedz;
      } else {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        Statystyka.proba = 0;
      }
    }
    if (Odpowiedz == oblicz(WyrZ_PytanieTestowe)) {
      cout << "Odpowiedz poprawna" << endl;
      zwieksz_lpop(Statystyka);
    } else {
      cout << "Blad. Prawidlowym wynikiem jest: " << oblicz(WyrZ_PytanieTestowe)
           << endl
           << endl;
    }
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << Statystyka;
  cout << endl;
}

//        NA NASTEPNE ZAJECIA       //
// Głowna petla
// 1 Pobranie pytania
// 2 pobranie odpowiedzzi
// 3 sprawdzenie poprawnosci 3x
// 4 sprawdzenie poprawnosci metytorycznej
// 5 aktualizacja statystyk
// 6 komunikat (czy dobrzez czy nie)
// 7 czy skonczyly sie pytania (nie -> 1)
// 8 Wyswietl podsumowanie