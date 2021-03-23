#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH

#include <iostream>

struct Statystyki {
  unsigned int lpoprawnych;
  unsigned int lpytan;
  unsigned int proba;
};

Statystyki inicjuj(Statystyki &StatTestu);
Statystyki zwieksz_p(Statystyki &StatTestu);     // liczba prob
Statystyki zwieksz_lpyt(Statystyki &StatTestu);  // liczba pytan
Statystyki zwieksz_lpop(Statystyki &StatTestu);  // liczba poprawnych odpowiedzi
Statystyki wyzeruj_p(Statystyki &StatTestu); // wyzerowanie liczby prob
std::ostream &operator<<(std::ostream &strm, const Statystyki &StatTestu);

#endif
