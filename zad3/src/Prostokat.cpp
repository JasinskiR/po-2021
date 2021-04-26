#include "Prostokat.hh"

Prostokat::Prostokat() {
  Wierzcholki[0] = Wektor2D(0, 0);
  Wierzcholki[1] = Wektor2D(0, 1);
  Wierzcholki[2] = Wektor2D(1, 0);
  Wierzcholki[3] = Wektor2D(1, 1);
}

const Wektor2D &Prostokat::operator[](int indeks) const {
  if (indeks < 0 || indeks > 4) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}

std::ostream &operator<<(std::ostream &strm, const Prostokat &Wierzcholki) {
  strm << "Wierzcholki prostokata wynosza: \n"
       << "LD = (" << Wierzcholki[0] << ")" << std::endl
       << "PD = (" << Wierzcholki[1] << ")" << std::endl
       << "PG = (" << Wierzcholki[2] << ")" << std::endl
       << "LG = (" << Wierzcholki[3] << ")" << std::endl;

  return strm;
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

Prostokat::Prostokat(Wektor2D LG, Wektor2D PG, Wektor2D PD, Wektor2D LD) {
  double epsilon = 0.01;
  if (epsilon < abs((LG - LD) * (LG - PG))) {
    std::cerr << "Boki nie sa prostopadle" << std::endl;
    exit(0);
  }
  if (epsilon < abs(((LG - LD).dlugosc() - (PG - PD).dlugosc()))) {
    std::cerr << "Boki nie sa rowne" << std::endl;
    exit(0);
  }
  Wierzcholki[0] = LD;
  Wierzcholki[1] = PD;
  Wierzcholki[2] = PG;
  Wierzcholki[3] = LG;
}

void Prostokat::rysuj(std::shared_ptr<drawNS::Draw2DAPI> rysownik) {
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
    exit(0);
  }
  for (int i = 0; i < 4; ++i) {
    if (!read.eof()) {
      read >> Wierzcholki[i];
      if (!read.good()) {
        read.clear();
        read.ignore(std::numeric_limits<int>::max(), '\n');
        std::cerr << "Blad danych - brak conajmniej jednego wierzcholka"
                  << std::endl;
        exit(0);
      }
    }
  }

  Prostokat prostokat(Wierzcholki[3], Wierzcholki[2], Wierzcholki[1],
                      Wierzcholki[0]);  // kolejnosc wczytywania LD PD PG LG
                                        // w tej samej kolejności muszą zostać
                                        // podane wierzcholki w pliku
  *this = prostokat;
  return true;
}

bool Prostokat::czy_prostokat() {
  double epsilon = 0.01;
  if (epsilon < abs((Wierzcholki[3] - Wierzcholki[0]) *
                    (Wierzcholki[3] - Wierzcholki[2]))) {
    std::cerr << "Boki nie sa prostopadle" << std::endl;
    return false;
  }
  if (epsilon < abs(((Wierzcholki[3] - Wierzcholki[0]).dlugosc() -
                     (Wierzcholki[2] - Wierzcholki[1]).dlugosc()))) {
    std::cerr << "Boki nie sa rowne" << std::endl;
    return false;
  }
  return true;
}
