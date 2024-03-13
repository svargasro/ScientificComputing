#include "primes.h"

bool isPrime(long n)
{

  bool flag = true;

  if(n<=1)return !flag;

  for(long j=2; j*j<=n; j++){
    if (n%j == 0) return !flag;
  }

  return flag;
}

bool isSeven(long n)
{
if (n==7) return true;
  else return false;
  }
