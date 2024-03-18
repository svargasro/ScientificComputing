#include <catch2/catch_test_macros.hpp>
#include "primes.h"


TEST_CASE( "Primes are computed", "[isPrime]" ) {
    REQUIRE( isPrime( 1) == false );
}



//Compilar con g++ -std=c++17 test_primes.cpp primes.cpp -lCatch2 -lCatch2Main
