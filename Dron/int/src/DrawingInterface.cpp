#include "DrawingInterface.hpp"

std::shared_ptr<drawNS::Draw3DAPI> DInter::api(
    new drawNS::APIGnuPlot3D(-7, 7, -7, 7, -1, 10, -1));
