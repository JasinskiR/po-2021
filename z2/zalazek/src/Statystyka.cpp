#include "Statystyka.hh"

#include <iostream>

Statystyki inicjuj(Statystyki &Statystyka) {
  Statystyka.lpoprawnych = 0;
  Statystyka.lpytan = 0;
  Statystyka.proba = 0;

  return Statystyka;
}

std::ostream &operator<<(std::ostream &strm, const Statystyki &StatTestu) {
  strm << "Statystyka Testu: " << std::endl;
  strm << "Ilosc dobrych odpowiedzi: " << StatTestu.lpoprawnych << std::endl;
  strm << "Ilosc blednych odpowiedzi: "
       << StatTestu.lpytan - StatTestu.lpoprawnych << std::endl;
  strm << "Wynik procentowy poprawnych odpowiedzi:    "
       << (100 * ((double)StatTestu.lpoprawnych / (double)StatTestu.lpytan))
       << "%" << std::endl;
  return strm;
}
