#include "DrawingInterface.hpp"

/**
 * @brief Statyczne przypisanie do wskaźnika przechowującego informacje o
 * gnuplocie
 *
 */
std::shared_ptr<drawNS::Draw3DAPI> DInter::api(
    new drawNS::APIGnuPlot3D(-7, 7, -7, 7, -1, 10, -1));
