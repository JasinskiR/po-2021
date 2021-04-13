#include "Statystyka.hh"

#include <iostream>

// void Statystyki::inicjuj() {
//   lpoprawnych = 0;
//   lpytan = 0;
//   proba = 0;
// }

void Statystyki::zwieksz_lpyt() { lpytan++; }

void Statystyki::zwieksz_lpop() { lpoprawnych++; }

std::ostream &operator<<(std::ostream &strm, const Statystyki &StatTestu) {
  strm << "Statystyka Testu: " << std::endl;
  strm << "Ilosc dobrych odpowiedzi: " << StatTestu.get_lpoprawnych()
       << std::endl;
  strm << "Ilosc blednych odpowiedzi: "
       << StatTestu.get_lpytan() - StatTestu.get_lpoprawnych() << std::endl;
  strm << "Wynik procentowy poprawnych odpowiedzi:    "
       << (100 * ((double)StatTestu.get_lpoprawnych() /
                  (double)StatTestu.get_lpytan()))
       << "%" << std::endl;
  return strm;
}
