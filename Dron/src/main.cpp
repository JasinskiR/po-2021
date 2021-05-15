#include <iostream>

#include "Drone.hpp"
#include "Surface.hpp"

using namespace std;

int main() {
  shared_ptr<drawNS::Draw3DAPI> api(
      new drawNS::APIGnuPlot3D(-5, 5, -5, 5, -1, 10, 0));
  cout << "Obsluga drona \"DragonFly\"" << endl;
  Surface(-1, api);
  Drone dron(Vector<3>({0, 0, 0}), MatrixRot<3>());
  dron.draw(api);
  int i = 0;
  while (i != 2) {
    cin >> i;
  }
  dron.animation(5, 45, 3, api);
  dron.animation(2, -45, -3, api);
}