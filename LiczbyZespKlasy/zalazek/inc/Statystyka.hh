#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH

#include <iostream>

class Statystyki {
 private:
  unsigned int lpoprawnych;
  unsigned int lpytan;

 public:
  Statystyki() : lpoprawnych(0), lpytan(0){};
  //void inicjuj();
  void zwieksz_lpyt();  // liczba pytan
  void zwieksz_lpop();  // liczba poprawnych odpowiedzi
  unsigned int get_lpoprawnych() const { return lpoprawnych; };
  unsigned int get_lpytan() const { return lpytan; };
};

// Statystyki inicjuj(Statystyki &StatTestu);
// Statystyki zwieksz_p(Statystyki &StatTestu);     // liczba prob
// Statystyki zwieksz_lpyt(Statystyki &StatTestu);  // liczba pytan
// Statystyki zwieksz_lpop(Statystyki &StatTestu);  // liczba poprawnych
// odpowiedzi Statystyki wyzeruj_p(Statystyki &StatTestu);     // wyzerowanie
// liczby prob
std::ostream &operator<<(std::ostream &strm, const Statystyki &StatTestu);

#endif
