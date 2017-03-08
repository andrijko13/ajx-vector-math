cmake_minimum_required (VERSION 2.6)
project (ajx)

set(CMAKE_CXX_COMPILER "g++")
enable_testing()

set(CMAKE_MACOSX_RPATH 1)

set(GCC_COVERAGE_COMPILE_FLAGS "")#"-std=c++11 -stdlib=libc++")
set(GCC_COVERAGE_LINK_FLAGS    "")

include_directories(include)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

file(GLOB TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/test/*.cpp)
message(STATUS "Test files: ${TEST_FILES}")

set (ajx_VERSION_MAJOR 0)
set (ajx_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

file(GLOB SOURCES "src/lib/*.cpp")
ADD_LIBRARY( ${PROJECT_NAME} SHARED
       ${SOURCES}
       )

#add_executable(prog src/test/main.cpp)
#target_link_libraries(prog ${PROJECT_NAME})

foreach(test_src_file ${TEST_FILES})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${test_src_file} NAME_WE)

        #Add compile target
        add_executable(${testName} ${test_src_file})

        #link to Boost libraries AND your targets and dependencies
        target_link_libraries(${testName} ${Boost_LIBRARIES} ${PROJECT_NAME})

        #I like to move testing binaries into a binaries/tests directory
        set_target_properties(${testName} PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/binaries/tests)

        #Finally add it to test execution - 
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binaries/tests 
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/binaries/tests/${testName} )
endforeach(test_src_file)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

