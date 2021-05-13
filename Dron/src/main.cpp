#include <iomanip>
#include <iostream>

#include "Dr3D_gnuplot_api.hpp"
// #include "Figure.hpp"
#include "MatrixRot.hpp"
// #include "Scene.hpp"
#include "Vector.hpp"

using namespace std;

int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(
      new drawNS::APIGnuPlot3D(-50, 50, -50, 50, -50, 50, 0));
  cout << "Obsluga drona \"DragonFly\"" << endl;
  return 0;
}