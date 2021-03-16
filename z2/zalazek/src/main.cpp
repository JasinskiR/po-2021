#include <iostream>

#include "BazaTestu.hh"

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

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe)) {
    //cout << " Podaj wynik operacji: " << wyswietl(WyrZ_PytanieTestowe) << "=" << endl;
    //cout << "Twoja odpowiedz: "
    //cin >> [Lzespolona]odpowiedz 
    //if(sprawdz(odpowiedz))
      //porownaj(odpowiedz,WyrZ_PytanieTestowe)
      //statystyka
    //else cout << "cos tam bledna"
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
    cin >> Odpowiedz;
    if (!cin.good()) {
      cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
      cin.clear();
    }
  }

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}

//        NA NASTEPNE ZAJECIA       //
//Głowna petla
//1 Pobranie pytania
//2 pobranie odpowiedzzi
//3 sprawdzenie poprawnosci 3x
//4 sprawdzenie poprawnosci metytorycznej 
// 5 aktualizacja statystyk
//6 komunikat (czy dobrzez czy nie)
//7 czy skonczyly sie pytania (nie -> 1)
//8 Wyswietl podsumowanie 