cmake_minimum_required (VERSION 2.6)
project (ajx)

set(CMAKE_MACOSX_RPATH 1)

set(GCC_COVERAGE_COMPILE_FLAGS "")
set(GCC_COVERAGE_LINK_FLAGS    "")

include_directories(include)

set (ajx_VERSION_MAJOR 0)
set (ajx_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

file(GLOB SOURCES "src/lib/*.cpp")
ADD_LIBRARY( ajx SHARED#STATIC
       ${SOURCES}
       )
#TARGET_LINK_LIBRARIES( MyLibraryName  ITKCommon )

add_executable(prog src/testing/main.cpp)
target_link_libraries(prog ajx)
