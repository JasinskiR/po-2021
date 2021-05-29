#include "DrawingInterface.hpp"

std::shared_ptr<drawNS::Draw3DAPI> DInter::api(
    new drawNS::APIGnuPlot3D(-5, 5, -5, 5, -1, 10, -1));
