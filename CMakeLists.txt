cmake_minimum_required(VERSION 3.15)

project(BasicCMakeProject)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Catch2)
add_subdirectory(Lib)
add_subdirectory(MainCode)
