#include "Vector.hpp"

/**
 * Możemy za jego pomocą dostać się do poszczególnych współrzędnych wektora.
 * Umożliwa on dostęp do współrzędnych, z możliwością modyfikacji.
 * Gdy indeks jest spoza zakresu [0;SIZE] zostanie wypisanystosowny komunikat
 * oraz nastąpi wyjście z programu
 *
 * @tparam SIZE - Określa wymiarowość w jakiej znajduje się wektor
 * @param index - indeks współrzędnej do której chcemy uzyskać dostęp
 * @return Modyfikowalna referencja do  określonej indeksem współrzędnej
 */
template <uint32_t SIZE>
double &Vector<SIZE>::operator[](uint32_t index) {
  if (index < 0 || index > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[index];
}

/**
 * Możemy za jego pomocą dostać się do poszczególnych współrzędnych wektora.
 * Umożliwa on dostęp do współrzędnych, bez możliwości modyfikacji.
 * Gdy indeks jest spoza zakresu [0;SIZE] zostanie wypisanystosowny komunikat
 * oraz nastąpi wyjście z programu
 *
 * @tparam SIZE - Określa wymiarowość w jakiej znajduje się wektor
 * @param index - indeks współrzędnej do której chcemy uzyskać dostęp
 * @return Niemodyfikowalna wartość określonej indeksem współrzędnej
 */
template <uint32_t SIZE>
const double &Vector<SIZE>::operator[](uint32_t index) const {
  if (index < 0 || index > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[index];
}

/**
 * Dodaje odpowiednie składowe dwóch wektorów i zwraca wynik.
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param secondV - Wektor który dodajemy
 * @return Zwraca wynik dodawania dwóch wektorów
 */
template <uint32_t SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector<SIZE> &secondV) const {
  Vector<SIZE> resultV;
  for (uint32_t i = 0; i < SIZE; ++i) {
    resultV[i] = this->cords[i] + secondV[i];
  }

  return resultV;
}

/**
 * Odejmuje odpowiednie składowe dwóch wektorów i zwraca wynik.
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param secondV - Wektor który odejmujemy
 * @return Zwraca wynik odejmowania dwóch wektorów
 */
template <uint32_t SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector<SIZE> &secondV) const {
  Vector<SIZE> resultV;
  for (uint32_t i = 0; i < SIZE; ++i) {
    resultV[i] = this->cords[i] - secondV[i];
  }

  return resultV;
}

/**
 * Mnoży wszystkie składowe wektora przez przysłaną stałą.
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param constValue - stała przez którą mnożymy
 * @return Zwraca wynik przemnożenia wektora przez stałą.
 */
template <uint32_t SIZE>
Vector<SIZE> Vector<SIZE>::operator*(const double &constValue) const {
  Vector<SIZE> resultV;
  for (uint32_t i = 0; i < SIZE; ++i) {
    resultV[i] = this->cords[i] * constValue;
  }

  return resultV;
}

/**
 * Mnoży odpowiednie składowe wektora przez składowe drugiego wektora oraz
 * dodaje je do siebie
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param secondV - stała przez którą mnożymy
 * @return Zwraca wynik przemnożenia wektora przez wektor.
 */
template <uint32_t SIZE>
double Vector<SIZE>::operator*(const Vector<SIZE> &secondV) const {
  double result = 0;
  for (uint32_t i = 0; i < SIZE; ++i) {
    result += this->cords[i] * secondV[i];
  }
  return result;
}

/**
 * Liczy długość wektora
 * @tparam SIZE - Określa wymiar wektora
 * @return Zwraca długość wektora
 */
template <uint32_t SIZE>
double Vector<SIZE>::length() const {
  double result = 0;
  for (uint32_t i = 0; i < SIZE; ++i) {
    result += pow(this->cords[i], 2);
  }

  return sqrt(result);
}

/**
 * Wczytanie wektora z odpowiedniego strumienia
 *
 * @param strm - strumien z którego ma zostać wczytany wektor
 * @param vector - wektor który ma zostać wczytany
 * @return zwracamy referencję do przysłanego strumienia
 */
template <uint32_t SIZE>
std::istream &operator>>(std::istream &strm, Vector<SIZE> &vector) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm >> vector[i];
  }
  // compilator sam ustawi failbita na strm jezeli zostanie wczytana
  // nieprawidlowa wartosc
  if (!strm.good()) {
    strm.clear();
    strm.ignore(std::numeric_limits<int>::max(), '\n');
    std::cerr << "Blad danych - brak conajmniej jednej skladowej wierzcholka"
              << std::endl;
    exit(0);
  }
  return strm;
}

/**
 * Wypisanie wektora na odpowiedni strumień
 *
 * @param strm - strumien na który ma zostać wypisany wektor
 * @param vector - wektor który ma zostać wypisany
 * @return zwracamy referencję do przysłanego strumienia
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Vector<SIZE> &vector) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm << std::setw(12) << std::fixed << std::setprecision(10) << vector[i]
         << " ";
  }
  strm << std::endl;
  return strm;
}