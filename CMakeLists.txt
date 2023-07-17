cmake_minimum_required(VERSION 3.15)

project(BasicCMakeProject)
set(CMAKE_CXX_STANDARD 20)
# The std library is compiled statically with the project, because there is a mismatch between the libstdc++.dll used in Windows and MSYS. For more info, see:
# https://stackoverflow.com/questions/54386599/entry-point-not-found-error-on-running-c-exe-file-after-compiling-with-mingw
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

#Uncomment to force analyzer usa in GCC/CLANG.
#set(CXX_ANALYZER true)

string(TOLOWER "${CMAKE_CXX_COMPILER_ID}" COMPILER_ID)
message(STATUS "Compiler ID string is: ${COMPILER_ID}")

if (COMPILER_ID STREQUAL "clang")
    message(STATUS "CLANG detected. Adding CLANG specific compile flags.")
    add_link_options("-fuse-ld=lld")
    set(IS_CLANG_BUILD true)
    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wthread-safety")
else ()
    set(IS_CLANG_BUILD false)
endif ()

if (COMPILER_ID STREQUAL "gnu")
    message(STATUS "GCC detected. Adding GCC specific compile flags.")
    set(IS_GCC_BUILD true)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wduplicated-cond -Wunsafe-loop-optimizations -Wuseless-cast -Wlogical-op -Waggressive-loop-optimizations")
else ()
    set(IS_GCC_BUILD false)
endif ()

if (CXX_ANALYZER)
    if (IS_GCC_BUILD)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fanalyzer")
    endif ()
    if (IS_CLANG_BUILD)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -Xanalyzer -analyze")
    endif ()
endif ()

if (CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC/CLANG detected, adding compile flags")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -Og")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wdouble-promotion -Wnull-dereference -Wuninitialized -Wsuggest-override -Wfloat-equal -Wcast-align -Wwrite-strings -Wconversion -Wzero-as-null-pointer-constant -Wparentheses -Wold-style-cast -Wshadow")
endif (CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(Catch2)
add_subdirectory(Lib)
add_subdirectory(MainCode)
