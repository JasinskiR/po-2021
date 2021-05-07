#include "Figure.hpp"

const Wektor<3> &Figura::operator[](uint32_t indeks) const {
  if (indeks < 0 || indeks > this->l_punktow()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}

Wektor<3> &Figura::operator[](uint32_t indeks) {
  if (indeks < 0 || indeks > this->l_punktow()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}

std::ostream &operator<<(std::ostream &strm, const Figura &F) {
  strm << "Wierzcholki figury wynosza: \n";
  for (uint32_t i = 0; i < F.l_punktow(); ++i) {
    strm << "P" << i + 1 << " " << F[i] << std::endl;
  }
  return strm;
}

std::istream &operator>>(std::istream &strm, Figura &F) {
  strm >> F;

  return strm;
}

void Figura::translacje(Wektor<3> W) {
  for (uint32_t i = 0; i < this->l_punktow(); ++i) {
    Wierzcholki[i] = Wierzcholki[i] + W;
  }
}

void Figura::rotacja(const MacierzRot<3> & Macierz) {
  for (uint32_t i = 0; i < this->l_punktow(); ++i) {
    Wierzcholki[i] = Macierz * Wierzcholki[i];
  }
}

Figura::Figura(std::array<Wektor<3>, 8> W) {
  double epsilon = 0.01;
  if (epsilon < abs((W[0] - W[1]) * (W[1] - W[2])) ||
      epsilon < abs((W[0] - W[1]) * (W[1] - W[5])) ||
      epsilon < abs((W[1] - W[2]) * (W[1] - W[5]))) {
    std::cerr << "Boki nie sa prostopadle" << std::endl;
    exit(0);
  }
  if (epsilon < abs(((W[0] - W[1]).dlugosc() - (W[6] - W[7]).dlugosc())) ||
      epsilon < abs((W[0] - W[3]).dlugosc() - (W[5] - W[6]).dlugosc()) ||
      epsilon < abs((W[0] - W[4]).dlugosc() - (W[2] - W[6]).dlugosc())) {
    std::cerr << "Boki nie sa rowne" << std::endl;
    exit(0);
  }
  for (uint32_t i = 0; i < 8; ++i) {
    Wierzcholki[i] = W[i];
  }
}

void Figura::rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  int pom;
  std::vector<std::vector<drawNS::Point3D>> tmp;
  std::vector<drawNS::Point3D> punkty;
  for (uint32_t i = 0; i < this->l_punktow(); ++i) {
    punkty.push_back(konwertuj(Wierzcholki[i]));
    if (i % 4 == 3) {
      tmp.push_back(punkty);
      punkty.clear();
    }
  }
  pom = rysownik->draw_polyhedron(tmp, "red");

  if (id != -1) {
    rysownik->erase_shape(id);
  }
  id = pom;
}

drawNS::Point3D Figura::konwertuj(Wektor<3> W) {
  return drawNS::Point3D(W[0], W[1], W[2]);
}

bool Figura::otworz(std::string name) {
  read.open(name, std::ios::in);
  if (!read.good()) {
    return false;
  }
  return true;
}

bool Figura::wczytaj() {
  for (int i = 0; i < 8; ++i) {
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
  if (epsilon < abs((Wierzcholki[0] - Wierzcholki[1]) *
                    (Wierzcholki[1] - Wierzcholki[2])) ||
      epsilon < abs((Wierzcholki[0] - Wierzcholki[1]) *
                    (Wierzcholki[1] - Wierzcholki[5])) ||
      epsilon < abs((Wierzcholki[1] - Wierzcholki[2]) *
                    (Wierzcholki[1] - Wierzcholki[5]))) {
    return false;
  }
  if (epsilon < abs(((Wierzcholki[1] - Wierzcholki[0]).dlugosc() -
                     (Wierzcholki[7] - Wierzcholki[6]).dlugosc())) ||
      epsilon < abs((Wierzcholki[3] - Wierzcholki[0]).dlugosc() -
                    (Wierzcholki[6] - Wierzcholki[5]).dlugosc()) ||
      epsilon < abs((Wierzcholki[4] - Wierzcholki[0]).dlugosc() -
                    (Wierzcholki[6] - Wierzcholki[2]).dlugosc())) {
    return false;
  }
  return true;
}

void Figura::dodaj() {
  for (uint32_t i = 0; i < 8; ++i) {
    std::cout << "\nPodaj wspolrzedne wierzcholka " << i + 1
              << " (trzy liczby odzielone spacja): ";
    std::cin >> Wierzcholki[i];
  }
}

void Figura::usun(std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  if (id != -1) {
    rysownik->erase_shape(id);
  }
}

const Figura &Figura::operator=(const Figura &F) {
  if (this != &F) {
    Wierzcholki = F.Wierzcholki;
    id = F.id;
  }
  return F;
}