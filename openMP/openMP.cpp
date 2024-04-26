#include <cstdio>
#include "omp.h"

int main(void)
{
    double x = 9.0;
//#pragma omp parallel num_threads(2)
#pragma omp parallel

    {// se generan los threads
        std::printf("Hello, world.\n");
        std::printf("Hello, world2.\n");
    } // mueren los threads

    return 0;
}
