#include "vec2d.h"
#include <iostream>

int main(int argc, char ** argv) {
	ajx::vec2d <int> position1(3, 4);
	ajx::vec2d <int> position2(3, 7);
	std::cout << position1.distance() << std::endl;
	ajx::vec2d <int> result = position1 + position2;
	std::cout << result.x() << " " << result.y() << std::endl;

    return 0;
}
