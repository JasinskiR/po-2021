#include "Block.hpp"
int BlockI::drawNumber(int min, int max) {
  int n = std::chrono::steady_clock::now().time_since_epoch().count();
  static std::default_random_engine generator(n);
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}