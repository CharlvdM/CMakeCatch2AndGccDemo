cmake_minimum_required(VERSION 3.15)

project(Lib)
set(CMAKE_CXX_STANDARD 20)

# Create library
add_library(Lib STATIC
    src/libFunctions.cpp)

target_include_directories(Lib PUBLIC inc)

# Create an executable for the Catch2 test code
add_executable(Lib_Tests 
    test/test_main.cpp
    test/test_libFunctions.cpp
    # include all the source files that have to be tested
    src/libFunctions.cpp)

# Includes
target_include_directories(Lib_Tests PUBLIC inc)

# Libraries
target_link_libraries(Lib_Tests PRIVATE Catch2::Catch2)