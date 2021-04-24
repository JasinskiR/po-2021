#include "Prostokat.hh"

Prostokat::Prostokat() {
  Wierzcholki[0] = Wektor2D(0, 0);
  Wierzcholki[1] = Wektor2D(0, 1);
  Wierzcholki[2] = Wektor2D(1, 0);
  Wierzcholki[3] = Wektor2D(1, 1);
}

const Wektor2D &Prostokat::operator[](int indeks) const {
  if (indeks < 0 || indeks > 4) {
    std::cerr << "Wierzcholkioza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}

std::ostream &operator<<(std::ostream &strm, const Prostokat &Wierzcholki) {
  strm << "Wierzcholki prostokata wynosza: "
       << "LG = (" << Wierzcholki[0] << ")" << std::endl
       << "WierzcholkiG = (" << Wierzcholki[1] << ")" << std::endl
       << "LD = (" << Wierzcholki[2] << ")" << std::endl
       << "WierzcholkiD = (" << Wierzcholki[3] << ")" << std::endl;
}

void Prostokat::translacje(Wektor2D W) {
  Wierzcholki[0] = Wierzcholki[0] + W;
  Wierzcholki[1] = Wierzcholki[1] + W;
  Wierzcholki[2] = Wierzcholki[2] + W;
  Wierzcholki[3] = Wierzcholki[3] + W;
}

void Prostokat::rotacja(double kat_stopnie) {
  Macierz2x2 Macierz(kat_stopnie);
  Wierzcholki[0] = Macierz * Wierzcholki[0];
  Wierzcholki[1] = Macierz * Wierzcholki[1];
  Wierzcholki[2] = Macierz * Wierzcholki[2];
  Wierzcholki[3] = Macierz * Wierzcholki[3];
}

Prostokat::Prostokat(Wektor2D LG, Wektor2D LD, Wektor2D WierzcholkiD,
                     Wektor2D WierzcholkiG) {
  double epsilon = 0.01;
  if (epsilon < (LG - LD) * (LG - WierzcholkiG)) {
    std::cerr << "Boki nie sa prostopadle" << std::endl;
    exit(0);
  }
  if (epsilon < ((LG - LD).dlugosc() - (WierzcholkiG - LG).dlugosc())) {
    std::cerr << "Boki nie sa prostopadle" << std::endl;
    exit(0);
  }
}
void Prostokat::rysuj(drawNS::Draw2DAPI *rysownik) {
  std::vector<drawNS::Point2D> tmp;
  tmp.push_back(konwertuj(Wierzcholki[0]));
  tmp.push_back(konwertuj(Wierzcholki[1]));
  tmp.push_back(konwertuj(Wierzcholki[2]));
  tmp.push_back(konwertuj(Wierzcholki[3]));
  tmp.push_back(konwertuj(Wierzcholki[0]));
  int id = rysownik->draw_polygonal_chain(tmp, "red");

  rysownik->erase_shape(id);
}

drawNS::Point2D Prostokat::konwertuj(Wektor2D W) {
  return drawNS::Point2D(W[0], W[1]);
}

bool Prostokat::otworz(std::string name) {
  std::fstream read;
  read.open(name, std::ios::in);
  if (!read.good()) {
    std::cerr << "Blad otwarcia pliku" << std::endl;
  }
  if (!read.eof()) {
    for (int i = 0; i < 4; ++i) {
      read >> Wierzcholki[i];
    }
  }
  return true;
}
