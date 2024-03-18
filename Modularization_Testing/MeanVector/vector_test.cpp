#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm> //Library that contains fill.
#include <cmath>
#include <numeric>
#include "catch2/catch.hpp"
#include "vector_ops.hpp"



TEST_CASE("Mean of a vector is computed", "[mean]") {
double relativPrec = 1.0e-3; //Precisión relativa
const int N=20; //Tamaño de los arreglos de prueba.


//Vector lleno con el mismo valor.
std::vector<double> sameValueVector(N); //Se decalara el vector que tendrá en todas las componentes el mismo valor.
double sameValue=3.2;
std::fill(sameValueVector.begin(), sameValueVector.end(), sameValue); //Se llena el vector con el valor "sameValue".


//Vector lleno de ceros.
std::vector<double> zerosVector(N);
std::fill(zerosVector.begin(), zerosVector.end(), 0.0); //Se llena el vector con ceros.


//Caso básico. El promedio debe ser 7.0 con N=15.
std::vector<double> basicVector(15);
std::iota(basicVector.begin(), basicVector.end(), 0.0);


//Vector de dimensión 0. La función debe devolver 1.
std::vector<double> dimensionZeroVector(0);


//Vector con una sola componente. La función debe devolver el valor de esa componente.
double oneDimensionVectorValue = 324.4;
std::vector<double> oneDimensionVector = {oneDimensionVectorValue};


//Vector de dimensión mayor a 100 que inicia desde 0.0 y sus elementos aumentan de a 1.
/*
En este caso, se calcula analíticamente el promedio teniendo en cuenta
que si el vector tiene dimensión L, la suma interna de sus elementos se puede calcular como
la sumatoria desde i=0 hasta L-1 de i; la cual mediante la sustitución m= i+1 se puede
calcular analíticamente. De ese modo el promedio para un vector de dimensión L, siempre
será (L+1)/2 - 1.
 */
const int L = 500; //Dimensión del vector.
std::vector<double> bigVector(L);

std::iota(bigVector.begin(), bigVector.end(), 0.0);
double averageBigVector = (L+1)/2.0 -1.0; //Cálculo analítico del promedio.

//Require:
REQUIRE( std::fabs(1.0 - mean(sameValueVector)/sameValue) < relativPrec ); //Caso vector lleno de un mismo elemento.
REQUIRE( std::fabs(0.0 - mean(zerosVector)) < relativPrec );  //Caso vector de ceros.
REQUIRE( std::fabs(1.0 - mean(basicVector)/7.0) < relativPrec ); //Caso vector básico.
REQUIRE( std::fabs(1.0 - mean(dimensionZeroVector)/1.0) < relativPrec  ); //Caso vector con dimensión cero.
REQUIRE( std::fabs(1.0 - mean(oneDimensionVector)/oneDimensionVectorValue) < relativPrec  ); //Caso vector unidimensional
REQUIRE( std::fabs(1.0 - mean(bigVector)/averageBigVector) < relativPrec  ); //Caso vector de dimensión grande.

}
