#include <iostream>
#include <string>
#include "primes.h"

int main (int argc, char **argv)
{
  long nmin = std::stol(argv[1]);
  long nmax = std::stol(argv[2]);

  long suma=0;
  for (long ii=nmin; ii<=nmax; ii++)
    {
      if(isPrime(ii)){
        std::cout<<ii<<std::endl;
        suma+=ii;
      if(isSeven(ii))std::cout<<"Sietexd"<<std::endl;
      }

    }



  std::cout<<"La suma: "<<suma<<std::endl;
}
//Para compilar, debo decirle qué archivo usar como función isPrime.
//Así, g++ ... printprimes.cpp primes.cpp
