#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include <iostream>

#include "LZespolona.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
 private:
  LZespolona Arg1;  // Pierwszy argument wyrazenia arytmetycznego
  Operator Op;      // Opertor wyrazenia arytmetycznego
  LZespolona Arg2;  // Drugi argument wyrazenia arytmetycznego
 public:
  LZespolona oblicz() const;
  LZespolona get_Arg1() const { return Arg1; };
  LZespolona get_Arg2() const { return Arg2; };
  Operator get_Op() const { return Op; };
  void set_Arg1(LZespolona _Arg1) { Arg1 = _Arg1; };
  void set_Arg2(LZespolona _Arg2) { Arg2 = _Arg2; };
  void set_Op(Operator _Op) { Op = _Op; };
};

/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

std::ostream &operator<<(std::ostream &strm, const Operator &o);
std::ostream &operator<<(std::ostream &strm, const WyrazenieZesp WyrZ);
std::istream &operator>>(std::istream &strm, WyrazenieZesp &WyrZ);
std::istream &operator>>(std::istream &strm, Operator &o);

#endif
