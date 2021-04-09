#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include <fstream>
#include <limits>
#include "WyrazenieZesp.hh"
/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
// struct BazaTestu {
//   WyrazenieZesp
//       *wskTabTestu;        /* Wskaznik na tablice zawierajaca pytania testu
//       */
//   unsigned int IloscPytan; /* Ilosc wszystkich pytan */
//   unsigned int
//       IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
// };

class BazaTestu {
 private:
  std::fstream read;

 public:
  bool pobierz_pytanie(WyrazenieZesp &W);
  bool otworz_baze_pytan(std::string nazwa);
  std::istream& get_read() {return read;}
  std::istream& blad();
};

#endif
