cd ../
set PATH="%PATH%;C:\msys64\mingw64\bin;C:\msys64\mingw64\lib"
"C:\msys64\usr\bin\cmake.exe" -G "Unix Makefiles" -D CMAKE_C_COMPILER="C:/msys64/mingw64/bin/gcc.exe" -D CMAKE_CXX_COMPILER="C:/msys64/mingw64/bin/g++.exe" -D CMAKE_MAKE_PROGRAM="C:/msys64/usr/bin/make.exe" CmakeLists.txt
"C:\msys64\usr\bin\make.exe" 
PAUSE