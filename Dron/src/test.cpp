#include <initializer_list>
#include <iostream>

void foo(const std::initializer_list<int>& lista) {
  for (int elem : lista) {
    std::cout << elem << std::endl;
  }
}
void goo(const std::initializer_list<std::pair<int,char>>& lista_par) {
  for (auto elem : lista_par) {
    std::cout << elem.first << elem.second << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  foo({1, 2, 3});
  std::pair<int, char> para = {1, 'c'};
  goo({para,{2,'d'},{3,'b'}});
  std::cout << para.first << std::endl;
  return 0;
}
