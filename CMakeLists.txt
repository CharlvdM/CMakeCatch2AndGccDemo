cmake_minimum_required(VERSION 3.15)

project(BasicCMakeProject)
set(CMAKE_CXX_STANDARD 20)
# The std library is compiled statically with the project, because there is a mismatch between the libstdc++.dll used in Windows and MSYS. For more info, see:
# https://stackoverflow.com/questions/54386599/entry-point-not-found-error-on-running-c-exe-file-after-compiling-with-mingw
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

add_subdirectory(Catch2)
add_subdirectory(Lib)
add_subdirectory(MainCode)
