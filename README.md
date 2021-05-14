Project Author: Charl van de Merwe  
Date: May 2021

# Overview
This project is setup to illustrate the basics of using CMake (with CMakeLists files), Catch2 and GCC.

# Getting Started
Clone the project (make sure that the "initialize all submodels" checkbox is ticked) and open Visual Studio, using the "Open a local folder" option, on the CMakeAndCatch2Demo directory. The configured CMakeLists.txt files should allow you to compile and run the 
project without any additional configuration required, i.e. Visual Studio understands how to do so based on the CMakeLists.txt files. If main.cpp is run, an angle is incremented by 33.5 degrees 
and is bound to 0 to 360 degrees. I know this is a pretty boring program, but illustrating how the tools used in this project works is what is of importance here.

# Project Folder Structure
- MainCode: Contains the main project executable (main.cpp), additional files with functions used by the project and Catch2 test cases for these functions.
- Lib: Contains a library of code that could be used in the project. All of the functions in the library is tested with Catch2 test cases.
- Catch2: The entire Catch2 library. Catch2 is configured as a submodule on git.
- Scripts: Batch files to compile and run the project using GCC

# Catch2
Catch2 is used to test all of the functions in the project. 

Catch2's Git documentation is pretty good and sufficient: [Tutorials](https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md#top)

The behaviour driven development style is generally preferred: [BBD-Style](https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md#bdd-style)

# CMake
CMake is used to configure the project, so that the project is independant of the IDE and compiler. In the PCC project, this allows us to do the development (including test cases) in any IDE
(e.g. Visual Studio or CLion) and allows us to check for compile errors and test case errors in the DevOps pipeline (which uses GCC).

In this demo project, a library is configured (see Lib/CMakeLists.txt) which is then linked to the main project (see MainCode/CMakeLists.txt).

Three executables are configured in this project:
- Main project executable (see `add_executable(MainCode...` in MainCode/CMakeLists.txt)
- Main project test cases executable (see `add_executable(MainCode_Tests...` in MainCode/CMakeLists.txt)
- Library test cases executable (see `add_executable(Lib_Tests...` in Lib/CMakeLists.txt)

For the basics on CMake, see [this introduction to the basics](https://cliutils.gitlab.io/modern-cmake/chapters/basics.html)

See also the Catch2 CMake integration documentation: [Catch2 CMake Integration](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top)

# GCC
GCC is a free compiler. We use the MSYS2 collection of tools, which includes GCC. To install GCC using MSYS2: [MSYS2 link](https://www.msys2.org/). See also 
[this information on MSYS installation](https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2).

For the basics on compilers and GCC specifically, see [this tutorial](https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052). For a little bit more in-depth
information on GCC, see [this tutorial](https://medium.com/leclevietnam/build-c-application-with-gnu-gcc-by-command-line-gnu-make-and-cmake-a9d28a6f9764)

In order to execute gcc commands from command line, the bin files of MinGW have to be added to the path variable. This can be done in the cmd prompt during runtime (will have to be done each 
time the cmd promt is opened):

`set PATH="%PATH%;C:\msys64\mingw64\bin;C:\msys64\mingw64\lib"`

Once the path is configured, the Make files can be generated from the configuration specified in the CMakeLists.txt files by running the following command (in cmd prompt in the 
CMakeAndCatch2Demo directory):

`"C:\msys64\usr\bin\cmake.exe" -G "Unix Makefiles" -D CMAKE_C_COMPILER="C:/msys64/mingw64/bin/gcc.exe" -D CMAKE_CXX_COMPILER="C:/msys64/mingw64/bin/g++.exe" -D CMAKE_MAKE_PROGRAM="C:/msys64/usr/bin/make.exe" CmakeLists.txt`

Executing the make files builds the project. Run the following command:

`"C:\msys64\usr\bin\make.exe"`

The main project or the test files can then be executed by running one of the following commands:

`MainCode\MainCode.exe`

`Lib\Lib_Tests.exe`

`MainCode\MainCode_Tests.exe`

Batch files are created for these commands in the Scripts folder for your double clicking convenience.

Note that once the project is compiled with GCC, a CMakeCache file will be added to the top level directory. This file has to be deleted before the project can be compiled again with Visual Studio.

TODO: Specify different build and cache output directories in the scripts.
