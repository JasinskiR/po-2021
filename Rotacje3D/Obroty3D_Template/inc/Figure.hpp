#ifndef FIGURE_HPP
#define FIGURE_HPP
/*!
 * \file
 * \brief Definicja klasy Figure
 *
 * Plik zawiera definicję klasy Figure
 */

#include <fstream>
#include <iostream>
#include <limits>

#include "Dr3D_gnuplot_api.hpp"
#include "MacierzRot.hpp"

/**
 * @brief Modeluje pojęcie prostopadłościanu
 *
 */

class Figura {
 private:

  /**
   * @brief Tablica przechowująca 8 wierzchołków prostopadłościanu
   *
   * Prostopadłościan jest zlokalizowany w przestrzeni 3D
   * Pojedynczy punkt jest zmodelowany za pomocą klasy Wektor
   */
  std::array<Wektor<3>, 8> Wierzcholki;

  /**
   * @brief Zmienna typu fstream, która służy do otwierania oraz wczytywania
   * pliku z danymi
   *
   */
  std::fstream read;

  /**
   * @brief  Konwersja wierchołka na odpowiednie parametry do rysowania w
   * Gnuplot'cie
   */
  drawNS::Point3D konwertuj(Wektor<3> W);

  /**
   * @brief Zmienna pomocnicza do odpowiedniego rysowania jak i usuwania
   * obiektów z Gnuplot'a
   *
   */
  int id = -1;

 public:

  /**
   * @brief Konstruktor domyślny dla prostopadłościanu
   * Ustawia je wszystkie na zera
   *
   */
  Figura() = default;
  
  /**
   * @brief Konstruktor kopiujący
   *
   */
  Figura(const Figura &F) : Wierzcholki{F.Wierzcholki}, id{F.id} {}

  /**
   * @brief Kopiujący operator przypisania
   *
   */
  Figura &operator=(const Figura &F);

  /**
   * @brief Inicjalizuje figurę
   * Inicjalizuje figurę na podstawie innego obiektu klasy Figure
   *
   */
  Figura(std::array<Wektor<3>, 8> W);

  /**
   * @brief Funkcja składowa wykonująca rotację bryły
   *
   */
  void rotacja(const MacierzRot<3> &Macierz);

  /**
   * @brief Funkcja składowa wykonująca translację bryły
   *
   */
  void translacje(Wektor<3> W);

  /**
   * @brief Funkcja składowa odpowiedzialna za rysowanie bryły w gnuplot'cie
   *
   */
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik);

  /**
   * @brief Funkcja składowa odpowiedzialna za przypisanie wartości wierzchołkom
   *
   */
  void dodaj();

  /**
   * @brief Funkcja składowa odpowiedzialna za usunięcie kształtu bryły z
   * gnuplot'a
   *
   */
  void usun(std::shared_ptr<drawNS::Draw3DAPI> rysownik);

  /**
   * @brief Operator dostępowy do wierzchołków prostopadłościanu
   *
   */
  const Wektor<3> &operator[](uint32_t indeks) const;

  /**
   * @brief Operator dostępowy do wierzchołków prostopadłościanu
   *
   */
  Wektor<3> &operator[](uint32_t indeks);

  /**
   * @brief Funkcja składowa odpowiedzialna za wczytanie wierzchołków bryły z
   * pliku zewnętrznego
   *
   */
  bool wczytaj();

  /**
   * @brief Funkcja skłądowa odpowiedzialna za otwarcie pliku
   */
  bool otworz(std::string name);

  /**
   * @brief Funkcja składowa wykonująca sprawdzenie poszczególnych parametrów
   * prostopadłościanu
   */
  bool czy_Figura();

  /**
   * @brief Funkcja składowa zliczająca ilość wierzchołków
   */
  std::size_t l_punktow() const { return Wierzcholki.size(); };

};

/**
 * @brief Wypisuje prostopadłościan do strumienia
 */
std::ostream &operator<<(std::ostream &strm, const Figura &wierzcholki);

/**
 * @brief Wczytuje prostopadłościan do strumienia
 */
std::istream &operator>>(std::istream &strm, Figura &wierzcholki);

#endif
