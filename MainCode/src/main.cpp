/// \file main_c1.cpp

#include <cstdio>
#include <windows.h>
#include "functions.h"
#include "TE_Float.h"

extern "C" int main() {

    volatile bool run {true};
    TE::float32_t angle {0.0F};

    printf("Increment a vector angle by 33.5. Boring, I know \n");

    while (run) {
        angle = TE::runRotatingVector(angle, 33.5F);
        printf("Vector angle: %3.1F \n", angle);
        Sleep(100UL);
    }
}
