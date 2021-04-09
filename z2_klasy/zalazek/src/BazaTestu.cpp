#include "BazaTestu.hh"

#include <cassert>
#include <cstring>
#include <iostream>

bool BazaTestu::otworz_baze_pytan(std::string nazwa) {
  read.open(nazwa, std::fstream::in);
  if (read.is_open()) {
    return true;
  } else {
    return false;
  }
}

bool BazaTestu::pobierz_pytanie(WyrazenieZesp& W) {
  read >> std::ws;
  if (!read.eof()) {
    read >> W;
    return true;
  }
  return false;
}

std::istream& BazaTestu::blad() {
  read.clear();
  read.ignore(std::numeric_limits<int>::max(), '\n');
  std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl
            << std::endl;
  return read;
}