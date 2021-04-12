#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH

#include <iostream>

class Statystyki {
 private:
  unsigned int lpoprawnych;
  unsigned int lpytan;
  unsigned int proba;

 public:
  Statystyki() : lpoprawnych(0), lpytan(0), proba(0) {};
  //void inicjuj();
  void zwieksz_p();     // liczba prob
  void zwieksz_lpyt();  // liczba pytan
  void zwieksz_lpop();  // liczba poprawnych odpowiedzi
  void wyzeruj_p();     // wyzerowanie liczby prob
  unsigned int get_lpoprawnych() const { return lpoprawnych; };
  unsigned int get_lpytan() const { return lpytan; };
  unsigned int get_proba() const { return proba; };
};

// Statystyki inicjuj(Statystyki &StatTestu);
// Statystyki zwieksz_p(Statystyki &StatTestu);     // liczba prob
// Statystyki zwieksz_lpyt(Statystyki &StatTestu);  // liczba pytan
// Statystyki zwieksz_lpop(Statystyki &StatTestu);  // liczba poprawnych
// odpowiedzi Statystyki wyzeruj_p(Statystyki &StatTestu);     // wyzerowanie
// liczby prob
std::ostream &operator<<(std::ostream &strm, const Statystyki &StatTestu);

#endif
