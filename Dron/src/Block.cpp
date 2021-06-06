#include "Block.hpp"

/**
 * @brief Losuje losową liczbę z zakresu [min;max]
 * Reprezentuje ona liczbę wierzchołków bryły
 *
 * @param min - wartośc minimalna zakresu
 * @param max - wartość maksymalna zakresu
 * @return int - zwraca liczbę będącą liczbą wierzchołków podstawy bryły
 */
int BlockI::drawNumber(int min, int max) {
  int n = std::chrono::steady_clock::now().time_since_epoch().count();
  static std::default_random_engine generator(n);
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}