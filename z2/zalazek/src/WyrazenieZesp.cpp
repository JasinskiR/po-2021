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
  strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
  return strm;
}

std::istream &operator>>(std::istream &strm, WyrazenieZesp &WyrZ) {
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
      std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete"
                << std::endl;
      break;
    }
  }
  return strm;
}

LZespolona oblicz(const WyrazenieZesp &WyrZ) {
  LZespolona Wynik;
  switch (WyrZ.Op) {
    case Op_Dodaj: {
      Wynik = WyrZ.Arg1 + WyrZ.Arg2;
      break;
    }
    case Op_Odejmij: {
      Wynik = WyrZ.Arg1 - WyrZ.Arg2;
      break;
    }
    case Op_Mnoz: {
      Wynik = WyrZ.Arg1 * WyrZ.Arg2;
      break;
    }
    case Op_Dziel: {
      Wynik = WyrZ.Arg1 / WyrZ.Arg2;
      break;
    }
  }
  return Wynik;
}
// ostream & operator << (ostream & strm, const operator O) {}
// ostream & operator << (ostream & strm, const WyrazenieZesp WyrZ) {
// strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
//}