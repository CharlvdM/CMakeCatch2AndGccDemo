cmake_minimum_required(VERSION 3.15)

project(MainCode)
set(CMAKE_CXX_STANDARD 20)

add_executable(MainCode
    src/main.cpp
    src/functions)

target_include_directories(MainCode PUBLIC inc)
target_link_libraries(MainCode PUBLIC Lib)

# Create an executable for the Catch2 test code
add_executable(MainCode_Tests 
    test/test_main.cpp
    test/test_functions.cpp
    # include all the source files that have to be tested
    src/functions.cpp)

# Includes
target_include_directories(MainCode_Tests PUBLIC inc)

# Libraries
target_link_libraries(MainCode_Tests PUBLIC Lib)
target_link_libraries(MainCode_Tests PRIVATE Catch2::Catch2)