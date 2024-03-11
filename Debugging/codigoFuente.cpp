#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);

int main (int argc, char **argv)
{
int ii, jj;
  ii =  0;
  jj = -1;

  int a =  foo(ii, jj);
  int b=  foo(jj, ii);
  double c = baz(25.9);
  std::cout<<a<<" "<<b<<" "<<c<<std::endl;


  return EXIT_SUCCESS;
}

int foo(int a, int b){

if(a==0 || b==0 || bar(a,b)==0){
 std::cout<<"Los argumentos de la función foo deben ser distintos de 0 y si el primer argumento es positivo, 2 multiplicado por el primer argumento no puede ser igual al segundo argumento."<<std::endl;
 return EXIT_FAILURE;
 }

return a/b + b/bar(a, b) + b/a;
}

   int bar(int a, int b)
{
 int c = std::abs(a);
return c + a - b;
}

double baz(double x)
{
if (x > 0){
  std::cout<<"El valor introducido en la función baz debe ser menor o igual a 0."<<std::endl;
  return EXIT_FAILURE;}
double v = 1-(x+1);
return std::sqrt(v);
}


//Makefile:


// CXXFLAGS= -g -fsanitize=leak,address,undefined

// all: codigoFuente.x

// codigoFuente.x: codigoFuente.cpp
// #	Sanitizers:

// 	g++ ${CXXFLAGS} codigoFuente.cpp -o x.codigoFuente
// 	./codigoFuente.x

// # 	Valgrind:

// #	g++ -g codigoFuente.cpp -o codigoFuente.x
// #	valgrind --tool=memcheck --track-origins=yes --leak-check=full ./codigoFuente.x

// # 	Wall:

// #	g++ -g -Wall codigoFuente.cpp -o codigoFuente.x
// #	./codigoFuente.x
