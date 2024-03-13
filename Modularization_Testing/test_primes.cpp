#include <catch2/catch_test_macros.hpp>
#include "primes.h"
#define CATCH_CONFIG_MAIN

TEST_CASE( "Primes are computed", "[isPrime]" ) {
    REQUIRE( isPrime( 1) == false );
}



//Compilar con g++ -std=c++17 printprimes.cpp primes.cpp -lCatch2 -lCatch2Main
