#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream &operator<<(std::ostream &strm, const Operator o) {
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
  strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
  return strm;
}
std::istream &operator>>(std::istream strm, WyrazenieZesp &WyrZ) {
  strm >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
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
      std::cerr << "Blad krytyczny, bledny operator matematyczny" << std::endl;
      exit(1);
    }
  }
  return strm;
}

// ostream & operator << (ostream & strm, const operator O) {}
// ostream & operator << (ostream & strm, const WyrazenieZesp WyrZ) {
// strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
//}