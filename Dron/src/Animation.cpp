#include "Animation.hpp"

double Animation::velocity = 10;

// void Scene::animeTime(dronPtr fPtr, Drone* dron, double value) {
//   uint32_t fps = value / velocity;
//   for (uint32_t i = 0; i < fps; ++i) {
//     dron->goVertical(i / fps * value);

//   }
// }
void Animation::animeTime(
    std::initializer_list<std::pair<droneFPtr, const double&> > fPairL,
    Drone* dron, std::shared_ptr<drawNS::Draw3DAPI> api) {
  for (auto fPair : fPairL) {
    std::cout<<"Test"<<std::endl;
    int fps = fPair.second * velocity;
    for (auto i = 0; i < fps; ++i) {
      std::cout<<"Test2"<<std::endl;
      (dron->*(fPair.first))(fPair.second/fps);
      (dron->draw(api));
      std::this_thread::sleep_for (std::chrono::milliseconds(200));
    }
  }
}