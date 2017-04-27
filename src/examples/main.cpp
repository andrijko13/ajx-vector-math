#include "vec2d.h"
#include "vec3d.h"
#include "matrix2d.h"
#include <iostream>

int main(int argc, char **argv) {
  ajx::vec2d<int> position1(10,-30);
  ajx::vec2d<int> position2(-30,20);

  ajx::vec2d<int> result = position1 + position2;

  std::cout << "X: " << result.x() << " Y: " << result.y() << std::endl;

  ajx::vec3d<double> velocity (20,20,0);
  std::cout << "Length of <20,20,0> is " << velocity.length() << std::endl;
  velocity = velocity.normalized();

  std::cout << "<20,20,0> normalized is <" << velocity.x() << ", " << velocity.y() << ", " << velocity.z() << ">" << std::endl;

  std::cout << "Length normalized is " << velocity.length() << std::endl;


  return 0;
}
