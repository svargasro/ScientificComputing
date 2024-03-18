#include "vector_ops.hpp"


/*
  Calcula el promedio de un vector de tamaño N.
*/
double mean(const std::vector<double> & data)
{
    double sumVector;
    int sizeVector = data.size();
    if (sizeVector == 0) {
        return 1.0;
    }

    for (int i = 0; i < sizeVector; i++) {
        sumVector += data[i];
    }

    return sumVector/sizeVector;
}
