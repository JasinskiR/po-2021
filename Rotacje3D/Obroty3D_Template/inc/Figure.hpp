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

/*!
 * \brief Modeluje pojęcie prostopadłościanu
 *
 */

class Figura {
 private:
  std::array<Wektor<3>, 8> Wierzcholki;
  std::fstream read;
  drawNS::Point3D konwertuj(Wektor<3> W);
  int id = -1;

 public:
  /*!
   * \brief Konstruktor domyślny dla prostopadłościanu
   * Ustawia je wszystkie na zera
   *
   */
  Figura() = default;
  /*!
   * \brief Konstruktor kopiujący
   *
   */
  Figura(const Figura &F) : Wierzcholki{F.Wierzcholki}, id{F.id} {}
  /*!
   * \brief Operator przypisania
   * Kopiujący operator przypisania
   *
   */
  const Figura &operator=(const Figura &F);
  /*!
   * \brief Inicjalizuje figurę
   * Inicjalizuje figurę na podstawie innego obiektu klasy Figure
   *
   */
  Figura(std::array<Wektor<3>, 8> W);
  /*!
   * \brief Funkcja składowa wykonująca rotację bryły
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
