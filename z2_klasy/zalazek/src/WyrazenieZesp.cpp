#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream &operator<<(std::ostream &strm, const Operator &o) {
  switch (o) {
    case Op_Dodaj: {
      strm << '+';

      break;
    }
    case Op_Odejmij: {
      strm << '-';
      break;
    }
    case Op_Mnoz: {
      strm << '*';
      break;
    }
    case Op_Dziel: {
      strm << '/';
      break;
    }
  }
  return strm;
}

std::ostream &operator<<(std::ostream &strm, const WyrazenieZesp WyrZ) {
  strm << WyrZ.get_Arg1() << WyrZ.get_Op() << WyrZ.get_Arg2();
  return strm;
}

std::istream &operator>>(std::istream &strm, WyrazenieZesp &WyrZ) {
  LZespolona _Arg1, _Arg2;
  Operator _Op;
  strm >> _Arg1 >> _Op >> _Arg2;
  WyrZ.set_Arg1(_Arg1);
  WyrZ.set_Op(_Op);
  WyrZ.set_Arg2(_Arg2);
  return strm;
}

std::istream &operator>>(std::istream &strm, Operator &o) {
  char znak;
  strm >> znak;
  switch (znak) {
    case '+': {
      o = Op_Dodaj;
      break;
    }
    case '-': {
      o = Op_Odejmij;
      break;
    }
    case '*': {
      o = Op_Mnoz;
      break;
    }
    case '/': {
      o = Op_Dziel;
      break;
    }
    default: {
      strm.setstate(std::ios::failbit);
      break;
    }
  }
  return strm;
}

LZespolona WyrazenieZesp::oblicz() const {
  LZespolona Wynik;
  switch (Op) {
    case Op_Dodaj: {
      Wynik = Arg1 + Arg2;
      break;
    }
    case Op_Odejmij: {
      Wynik = Arg1 - Arg2;
      break;
    }
    case Op_Mnoz: {
      Wynik = Arg1 * Arg2;
      break;
    }
    case Op_Dziel: {
      Wynik = Arg1 / Arg2;
      break;
    }
  }
  return Wynik;
}
// ostream & operator << (ostream & strm, const operator O) {}
// ostream & operator << (ostream & strm, const WyrazenieZesp WyrZ) {
// strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
//}