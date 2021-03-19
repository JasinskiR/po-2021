#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH

#include <iostream>

struct Statystyki {
  unsigned int lpoprawnych;
  unsigned int lpytan;
  unsigned int proba;
};

Statystyki inicjuj(Statystyki &StatTestu);
std::ostream &operator<<(std::ostream &strm, const Statystyki &StatTestu);

#endif
