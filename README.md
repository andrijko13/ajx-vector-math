#About

The ajx namespace provides classes for all basic linear algebra vector/matrix needs. Initially designed for use by game developers

#Installing

Installing ajx and all of it's libraries is easy. Just making a build directory, and run cmake/make/make install!

```bash
mkdir build; cd build
cmake -j4 .. && make && make install
```

Building the project requires the system to have `boost` library installed, as well as a c++ compiler (g++)

# Usage

Make sure to import the headers for the classes you are using, and use away! Examples are located in `/src/testing/main.cpp`

```c++
#include <ajx/vec2d.h>
#include <iostream>

int main(int argc, char **argv) {
  ajx::vec2d <int> velocity1 (10, 10);
  ajx::vec2d <int> velocity2 (-15, 30);
  ajx::vec2d <int> result = velocity1 + velocity2;
  
  std::cout << "The added velocity is X: " << result.x() << " Y: " << result.y() << std::endl;
  
  return 0;
}
```
