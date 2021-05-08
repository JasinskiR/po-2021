#include "Scene.hpp"

/**
 * Na podstawie przesłenego obiektu klasy Figure zostaje wywołana funkcja
 * dodawania figury a następnie jest ona dodana do kontenera przechowującego
 * wszystkie bryły.
 *
 *@param obj - przesyłana figura
 */
void Scene::Add(Figura *obj) {
  if (obj == nullptr) {
    obj = new Figura;
    obj->dodaj();
  }
  this->figures.push_back(obj);
}

/**
 * Usuwa figure z wektora.
 * Jeśli numer figury jest błędny wypisywany stosowny komunikat oraz
 * nastepuje wyjście z programu
 *
 * @param ind - indeks bryły do usunięcia w zakresie [1;ILOŚĆ_BRYŁ]
 * @param rysownik - wskażnik do dołączonej klasy obsługującej Gnuplot'a
 */
void Scene::Remove(const uint32_t &ind,
                   std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  if (ind < 0 || ind >= figures.size()) {
    std::cerr << "Poza pamiecia" << std::endl;
    exit(0);
  } else {
    figures[ind]->usun(rysownik);
    this->figures.erase(figures.begin() + ind);
  }
}

/**
 * Możemy za jego pomocą dostać się do poszczególnych figur.
 * Umożliwa on modifikację tychże figur.
 * Gdy indeks jest spoza zakresu [0;ILOŚĆ_BRYŁ] zostanie wypisywany stosowny
 * komunikat oraz nastepuje wyjście z programu
 *
 * @param ind - indeks figury do której chcemy uzyskać dostęp
 * @return zwraca referencję do figury którą chcemy zmodyfikować
 */
Figura &Scene::operator[](const uint32_t &ind) {
  if (ind < 0 || ind >= figures.size()) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return *(figures[ind]);
}

/**
 * Wypisanie ilości dostępnych figur na strumień. Wypisanie następuje w formie
 * podania dozwolonych indeksów brył
 *
 * @param strm - strumien na który mają zostać wypisane indeksy
 * @param figures - scena, która ma zostać wypisana
 * @return zwracamy referencję do przysłanego strumienia
 */
std::ostream &operator<<(std::ostream &strm, const Scene &figures) {
  strm << "Dostepne indeksy figur to :" << std::endl;
  for (uint32_t i = 0; i < figures.n_figures(); ++i) {
    strm << i + 1 << " ";
  }
  return strm;
}

/**
 * Rysuje wszystkie figury zawarte w wektorze
 *
 * @param rysownik - wskażnik do dołączonej klasy obsługującej Gnuplot'a
 */
void Scene::rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik) {
  for (uint32_t i = 0; i < figures.size(); ++i) {
    figures[i]->rysuj(rysownik);
  }
}
