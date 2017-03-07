#include "vec2d.h"
#include <iostream>

int main(int argc, char ** argv) {

    ajx::vec2d <double> velocity1 (10.0, 10.0);
    ajx::vec2d <double> velocity2 (-15.0, 30.0);
    ajx::vec2d <double> res = ajx::vec2d<double>::ZeroVector();
    ajx::vec2d <double> result = velocity1 + velocity2 + res;

    std::cout << "The added velocity is X: " << result.x() << " Y: " << result.y() << std::endl;


    return 0;
}
