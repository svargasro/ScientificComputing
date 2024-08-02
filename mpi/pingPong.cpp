#include <cstdio>
#include "mpi.h"
#include <string>

/* Problem parameters */
double pingPong(int integer,int pid, int np);

int main(int argc, char **argv)
{
  
  int initialNumber=3;

  /* problem variables */
  int pid, np;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);


  pingPong(initialNumber, pid, np);


  /* finish */
  MPI_Finalize();
  return 0;
}

double f(double x) {
  return x*x;
}

double integral_serial(double xmin, double xmax, double n)
{
  double area = 0.0;
  double width = (xmax - xmin)/n;

  for (int i = 0; i < n; ++i) {
    double at = xmin + i*width + width/2.0; // center in the middle
    double heigth = f(at);
    area = area + width*heigth;
  }
  return area;
}

double pingPong(int integer, int iterations,int pid, int np){

  if (pid==0){
  //Recibir datos parciales iniciales.
   
  //Modificación
  for(int m=1; m<; ipid++){
  //Recibir: mpi
    int tag=0;
    double Itmp;
    MPI_Recv(&Itmp,1,MPI_DOUBLE, ipid,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE);


    Itotal += Itmp;
  }
  //Imprimir el valor total
  printf("The area from %lf to %lf is : %lf \n", xmin, xmax, Itotal);
  }
  else{
    int tag=0;
    //Enviar mi suma parcial al pid 0
    MPI_Send(&Ilocal,1,MPI_DOUBLE,0,tag, MPI_COMM_WORLD);
      }

  return Ilocal;
}


/*
Fernandez Llanes Jeysson
Rueda Mantilla Juan Diego
Rubiano Vargas Ruben Dario
Vargas Rodriguez Sergio
Arias Ortiz Maria Lucia
*/


/*
MPI_Send(
    void* data, //void es "cualquier tipo de dato".
    int count, //Cuento a partir de la dirección de memoria la cantidad de bloques.
    MPI_Datatype datatype, //Para que sepa qué tan grueso es el bloque de memoria.
    int destination, //A quién se la envío.
    int tag, //Identificador de envíos.
    MPI_Comm communicator)

MPI_Recv(
    void* data, //Guardo lo que recibo.
    int count,
    MPI_Datatype datatype,
    int source, //El pid del que recibo datos.
    int tag,
    MPI_Comm communicator,
    MPI_Status* status)

*/
