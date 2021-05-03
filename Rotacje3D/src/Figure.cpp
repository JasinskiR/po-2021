#include "Figure.hh"

const Wektor<2> &Figura::operator[](unsigned int indeks) const {
  if (indeks < 0 || indeks > this->l_punktow()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}

Wektor<2> &Figura::operator[](unsigned int indeks) {
  if (indeks < 0 || indeks > this->l_punktow()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}

std::ostream &operator<<(std::ostream &strm, const Figura &F) {
  strm << "Wierzcholki figury wynosza: \n";
  for (unsigned int i = 0; i < F.l_punktow(); ++i) {
    strm << "P" << i + 1 << " " << F[i] << std::endl;
  }
  return strm;
}

std::istream &operator>>(std::istream &strm, Figura &F) {
  strm >> F;

  return strm;
}

void Figura::translacje(Wektor<2> W) {
  for (unsigned int i = 0; i < this->l_punktow(); ++i) {
    Wierzcholki[i] = Wierzcholki[i] + W;
  }
}

void Figura::rotacja(double kat_stopnie) {
  MacierzRot<2> Macierz(kat_stopnie, OZ);
  Wierzcholki[0] = Macierz * Wierzcholki[0];
  Wierzcholki[1] = Macierz * Wierzcholki[1];
  Wierzcholki[2] = Macierz * Wierzcholki[2];
  Wierzcholki[3] = Macierz * Wierzcholki[3];
}
/*template <>
void Figura<3>::rotacja(double kat_stopnie) {
  // MacierzRot<3> Macierz(kat_stopnie);
  // Wierzcholki[0] = Macierz * Wierzcholki[0];
  // Wierzcholki[1] = Macierz * Wierzcholki[1];
  // Wierzcholki[2] = Macierz * Wierzcholki[2];
  // Wierzcholki[3] = Macierz * Wierzcholki[3];
}
template <unsigned int SIZE>
void Figura<SIZE>::rotacja(double kat_stopnie) {
  static_assert(SIZE < 4, "Program nie obsluguje hiperobrotow");
}
*/

Figura::Figura(Wektor<2> LG, Wektor<2> PG, Wektor<2> PD, Wektor<2> LD) {
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

void Figura::rysuj(std::shared_ptr<drawNS::Draw2DAPI> rysownik) {
  int static id = -1;
  int pom;
  std::vector<drawNS::Point2D> tmp;
  for (unsigned i = 0; i < this->l_punktow(); ++i) {
    tmp.push_back(konwertuj(Wierzcholki[i]));
  }
  tmp.push_back(konwertuj(Wierzcholki[0]));
  pom = rysownik->draw_polygonal_chain(tmp, "red");

  if (id != -1) {
    rysownik->erase_shape(id);
  }
  id = pom;
}

drawNS::Point2D Figura::konwertuj(Wektor<2> W) {
  return drawNS::Point2D(W[0], W[1]);
  // if (SIZE == 3) return drawNS::Point2D(W[0], W[1], W[3]);
}

bool Figura::otworz(std::string name) {
  read.open(name, std::ios::in);
  if (!read.good()) {
    return false;
  }
  return true;
}

bool Figura::wczytaj() {
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
  return true;
}

bool Figura::czy_Figura() {
  double epsilon = 0.01;
  if (epsilon < abs((Wierzcholki[3] - Wierzcholki[0]) *
                    (Wierzcholki[3] - Wierzcholki[2]))) {
    return false;
  }
  if (epsilon < abs(((Wierzcholki[3] - Wierzcholki[0]).dlugosc() -
                     (Wierzcholki[2] - Wierzcholki[1]).dlugosc()))) {
    return false;
  }
  return true;
}
