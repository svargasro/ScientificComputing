#include <iostream>
#include <math.h>

//Sergio Vargas Rodríguez
bool isPrime(int num){

bool flag = true;

 if(num<=1) flag = false;
 else{
   for (int i=2; i*i <= num; i++) {
     if (num%i == 0) {
       flag = false;
     }
   }
 }

return flag;
}


int main(int argc, char *argv[]) {

int limInf = std::stoi(argv[1]);
int limSup = std::stoi(argv[2]);

for (int i=limInf; i<= limSup; i++) {

  if (isPrime(i)){
   std::cout<<i<<std::endl;
  }
 }
  return 0;
}
