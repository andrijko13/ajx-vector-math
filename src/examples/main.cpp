#include "vec2d.h"
#include <iostream>

int main(int argc, char **argv) {
  ajx::vec2d<int> position1(10,-30);
  ajx::vec2d<int> position2(-30,20);

  ajx::vec2d<int> result = position1 + position2;

  std::cout << "X: " << result.x() << " Y: " << result.y() << std::endl;

  return 0;
}