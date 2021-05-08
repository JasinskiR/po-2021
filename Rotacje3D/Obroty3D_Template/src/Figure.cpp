#include "Figure.hpp"
/**
 * Możemy za jego pomocą dostać się do poszczególnych wierzchołków
 * prostopadłościanu. Umożliwiaon dostep do wierzchołków bez możliwości ich
 * modyfikacji.
 * Gdy indeks jest spoza zakresu [0;ilość wierzchołków] zostanie wypisany
 * stosowny komunikat oraz nastąpi wyjście z programu
 *
 * @param indeks - indeks wierzchołka do którego chcemy uzyskać dostęp
 * @return zwraca odpowiedni niemodyfikowalny wierzchołek prostopadłościanu
 */
const Wektor<3> &Figura::operator[](uint32_t indeks) const {
  if (indeks < 0 || indeks > this->l_punktow()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}
/**
 * Możemy za jego pomocą dostać się do poszczególnego wierzchołka
 * prostopadłościanu. Umożliwia on modyfikację wierzchołków. Gdy indeks jest
 * spoza zakresu [0;ilość wierzchołków] zostanie wypisany stosowny komunikat
 * oraz nastąpi wyjście z programu.
 *
 * @param indeks - indeks wierzchołka do którego chcemy uzyskać dostęp
 * @return zwraca referencję do wierzchołka prostopadłościanu który chcemy
 * zmodyfikować
 */
Wektor<3> &Figura::operator[](uint32_t indeks) {
  if (indeks < 0 || indeks > this->l_punktow()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return Wierzcholki[indeks];
}
/**
 * Wypisanie Figury na odpowiedni strumień
 *
 * @param strm - strumien na który ma zostać wypisany prostopadłościan
 * @param F prostopadłościan który ma zostać wypisany
 * @return wracamy referencję do przysłanego strumienia
 */
std::ostream &operator<<(std::ostream &strm, const Figura &F) {
  strm << "Wierzcholki figury wynosza: \n";
  for (uint32_t i = 0; i < F.l_punktow(); ++i) {
    strm << "P" << i + 1 << " " << F[i] << std::endl;
  }
  return strm;
}
/**
 * Wczytanie Figury z odpowiedniego strumienia
 *
 * @param strm - strumien z którego ma zostać wczytany prostopadłościan
 * @param F - prostopadłościan który ma zostać wczytany
 * @return zwracamy referencję do przysłanego strumienia
 */
std::istream &operator>>(std::istream &strm, Figura &F) {
  strm >> F;

  return strm;
}
/**
 * Realizuje translację prostopadłościanu o zadany wektor
 * Do kolejnych wierzchołków jest dodawany wektor translacyjny.
 *
 * @param W
 */
void Figura::translacje(Wektor<3> W) {
  for (uint32_t i = 0; i < this->l_punktow(); ++i) {
    Wierzcholki[i] = Wierzcholki[i] + W;
  }
}
/**
 * Rotacja jest wykonywana na podstawie macierzy rotacji.
 * Na kolejnych wierzchołkach jest wykonywana operacja mnożenia przez macierz
 * rotacji.
 *
 * @param Macierz - wyspecjalizowana macierz rotacji zainicjalizowana już
 * odpowiednimi wartości.
 */
void Figura::rotacja(const MacierzRot<3> &Macierz) {
  for (uint32_t i = 0; i < this->l_punktow(); ++i) {
    Wierzcholki[i] = Macierz * Wierzcholki[i];
  }
}
/**
 * Inicjalizuje obiekt Figure na podstawie wektorów z wierzchołkami
 *
 * @param W - parametr klasy Wektor, który przechowuje informacje o
 * współrzędnych wierzchołka
 */
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
/**
 * Rysuje dany prostopadłościan w zewnętrznej aplikacji Gnuplot
 *
 * @param rysownik - wskażnik do dołączonej klasy obsługującej Gnuplot'a
 */
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
/**
 * Konwertuje wierchołek na odpowiednie parametry do rysowania w Gnuplot'cie
 *
 * @param W - parametr klasy Wektor, który przechowuje informacje o
 * współrzędnych wierzchołka
 * @return zwraca prztworzony wektor na odpowiedni punkt
 */
drawNS::Point3D Figura::konwertuj(Wektor<3> W) {
  return drawNS::Point3D(W[0], W[1], W[2]);
}
/**
 * Otwiera plik w trybie do odczytu
 *
 * @param name - nazwa pliku który zostanie otworzony
 * @return true - gdy plik został otworzony poprawnie
 * @return false - gdy operacja otwarcia pliku się nie powiodła
 */
bool Figura::otworz(std::string name) {
  read.open(name, std::ios::in);
  if (!read.good()) {
    return false;
  }
  return true;
}
/**
 * Wczytuje oraz inicjalizuje wszystkie wierzchołki na podstawie danych z pliku.
 *
 * @return true - wartość zwracana, gdy wszystkie wierzchołki zostały wczytane
 * prawidłowo
 * @return false - wartość zwracama, gdy chociażby jeden wierzchołek został
 * wczytany nieprawidłowo lub plik zawiera uszkodzone dane
 */
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

/**
 * Funckja sprawdza to na podstawie porównywania długości odpowiednich boków
oraz kątów między odcinkami
 * W przypadku braku zgodności sprawdzanych parametrów zostanie zwrócona wartość
false
 * Gdyby długości były zgodne zostanie zwrócona wartość true
 * Funkcja także wypisze długości wszystkich boków.
 *
 * @return true - gdy wszystkie sprawdzane parametry są zgodne
 * @return false - gdy chociażby jedna z badanych właściwości prostopadłościanu
się nie zgadza
 */
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
/**
 * Operacja ręcznego dodawania obiektu klasy Figure na podstawie wierzchołków
 *
 */
void Figura::dodaj() {
  for (uint32_t i = 0; i < 8; ++i) {
    std::cout << "\nPodaj wspolrzedne wierzcholka " << i + 1
              << " (trzy liczby odzielone spacja): ";
    std::cin >> Wierzcholki[i];
  }
}
/**
 * Usuwa kształt narysowny w zewnętrznej aplikacji Gnuplot
 *
 * @param rysownik - wskażnik do dołączonej klasy obsługującej Gnuplot'a
 */
void Figura::usun(std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  if (id != -1) {
    rysownik->erase_shape(id);
  }
}
/**
 * Funkcja kopiująca wierzchołki obiektu klasy Figure do innego obiektu tej
 * samej klasy
 *
 * @param F - obiekt klasy Figure z którego następuje przekopiowanie
 * wierzchołków
 * @return zwraca referencję do przekazywanego obiektu
 */
const Figura &Figura::operator=(const Figura &F) {
  if (this != &F) {
    Wierzcholki = F.Wierzcholki;
    id = F.id;
  }
  return F;
}