#include "Statystyka.hh"

#include <iostream>

Statystyki inicjuj(Statystyki &Statystyka) {
  Statystyka.lpoprawnych = 0;
  Statystyka.lpytan = 0;
  Statystyka.proba = 0;

  return Statystyka;
}

Statystyki zwieksz_p(Statystyki &StatTestu) {
  StatTestu.proba++;

  return StatTestu;
}

Statystyki zwieksz_lpyt(Statystyki &StatTestu) {
  StatTestu.lpytan++;

  return StatTestu;
}

Statystyki zwieksz_lpop(Statystyki &StatTestu) {
  StatTestu.lpoprawnych++;

  return StatTestu;
}

Statystyki wyzeruj_p(Statystyki &StatTestu) {
  StatTestu.proba=0;

  return StatTestu;
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
