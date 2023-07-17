cd ../
cmake -G "Unix Makefiles" -D CMAKE_C_COMPILER="C:/msys64/mingw64/bin/gcc.exe" -D CMAKE_CXX_COMPILER="C:/msys64/mingw64/bin/g++.exe" -D CMAKE_MAKE_PROGRAM="C:/msys64/mingw64/bin/mingw32-make.exe" -B GccBuild
cd GccBuild
"C:/msys64/mingw64/bin/mingw32-make.exe" 
PAUSE