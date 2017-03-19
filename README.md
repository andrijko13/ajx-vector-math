[![Version](https://img.shields.io/badge/Version-1.0.1-blue.svg)](https://github.com/andriko13/ajx-vector-math)
[![Build Status](https://travis-ci.org/andriko13/ajx-vector-math.svg?branch=master)](https://travis-ci.org/andriko13/ajx-vector-math)
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-orange.svg?style=flat)](https://github.com/andriko13/ajx-vector-math/issues)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/andriko13/ajx-vector-math/blob/master/LICENSE.txt)


# About

The ajx namespace provides classes for all basic linear algebra vector/matrix needs. Initially designed for use by game developers

# Installing

Installing ajx and all of it's libraries is easy. Just make a build directory, and run cmake/make/make install!

```bash
mkdir build; cd build
cmake -j4 .. && make && make install
```

Building the project requires the system to have `boost` library installed, as well as a c++ compiler (g++)

## Running Tests

You can run the test suite to make sure that the library is functioning. Individual tests can be found in `/binaries/tests/`.

To run the full test suite, you can use `make test` inside the build directory

# Usage

Make sure to import the headers for the classes you are using, and use away! Examples are located in `/src/examples`

Once you compile the library, you can run the examples from the `/binaries` folder

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
