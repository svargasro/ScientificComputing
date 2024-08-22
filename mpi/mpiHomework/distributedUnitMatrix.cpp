#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>

void fillMatrix(int N, int np, int pid);

int main(int argc, char **argv)
{
  
  int N = std::atoi(argv[1]);

  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  //Manejo de errores cuando np no es divisor de N. También maneja el caso en el que np sea mayor que N. El ejercicio pide que lo supongamos.
  if(pid==0){
    if(N%np != 0 || N<=0){
      std::cerr <<"El número de procesos (NP) debe ser divisor del tamaño de la matriz (N) y N >= NP y N>0"<<"\n";
      MPI_Abort(MPI_COMM_WORLD, 1);
    }
  }
  MPI_Barrier(MPI_COMM_WORLD); // Todos los procesos llegan a este punto y esperan. Para evitar que el error se imprima varias veces.

  fillMatrix(N, np, pid); //Función en donde se llena e imprime la matriz.

  MPI_Finalize();
  return 0;
}

void fillMatrix(int N, int np, int pid){

  int localRows= N/np; //El número de filas que tendrá cada matriz local.

/*
  Se linealiza la matriz de tal forma que el elemento (0,0) tiene el índice 0 y es el que está en la esquina superior izquierda.
  El elemento (0,1) tiene el índice 1 y está a la derecha del elemento (0,0).
  Se adopta la convención (fila, columna) donde la fila 0 corresponde a la que está más arriba y la columna 0 a la que está más a la izquierda.
*/
  int matrixSize= localRows*N; //Tamaño de la matriz local.
  std::vector<int> localMatrix(matrixSize,0); //La matriz local se inicializa en ceros.


  int initialOne= pid*localRows; //La ubicación del primer 1 en el arreglo.

  //Habrán tantos 1 como el tamaño de filas de la matriz local:
  for(int i=0;i<localRows;i++) {
    int indexOne= initialOne + i*(N+1); //El siguiente 1 estará ubicado siempre a N+1 posiciones del anterior 1.
    localMatrix[indexOne] = 1; //Se llenan los valores de 1 correspondientes.
//  std::cout<<"pid: "<<pid<<" "<<"index1: "<<indexOne<<"\n";
  }
  int tag=0;

  if(pid==0){
    double initialTime, finalTime,t,bandWidthValue;
    double bandWidth=0.0;
    //Se recorre el arreglo del pid=0 y para que quede como una matriz, se imprime un salto de línea cuando se completa el número de columnas.
    for (int i=0;i<matrixSize;i++) {
      std::cout<<localMatrix[i]<<" ";
      if((i+1)%N==0){std::cout<<"\n";}
    }

    std::vector<double> bandWidthVector(np-1); //Vector que guarda el bandWith de cada proceso.

    for(int ipid=1; ipid<np; ipid++){ //Bucle para recibir e imprimir la información de los otros procesos.
      std::vector<int> tmpLocalMatrix(matrixSize);
      initialTime = MPI_Wtime();
      MPI_Recv(&tmpLocalMatrix[0], matrixSize, MPI_INT, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      finalTime = MPI_Wtime();
      t= finalTime - initialTime;
      bandWidthValue = (matrixSize*sizeof(int)/t)/std::pow(10.0,6); //Se calcula el Bandwidth en MB/s
      bandWidthVector[ipid-1]= bandWidthValue; //Se guarda el valor del bandwidth de cada ipid.
      bandWidth += bandWidthValue; //bandwidth en MB/s se acumula el de todos los nodos.
      //std::cout<<"pid: "<<ipid<<"\n";
      for (int i=0;i<matrixSize;i++) { //Impresión de la matriz local de cada pid.
        std::cout<<tmpLocalMatrix[i]<<" ";
        if((i+1)%N==0){std::cout<<"\n";}
      }
    }
    for(int ipid=1; ipid<np;ipid++){
    std::cout<<"Bandwidth del pid 0 con pid "<<ipid<<": "<<bandWidthVector[ipid-1]<<" MB/s \n";
    }

    std::cout<<"Bandwidth promedio: "<<bandWidth/(np-1)<<" MB/s \n"; //Se imprime el promedio de bandwidth en consola.

  }
  else{
    MPI_Send(&localMatrix[0], matrixSize, MPI_INT, 0, tag, MPI_COMM_WORLD); //Envío de datos al pid=0
  }
}

/*
Correr con los comandos:
mpic++ distributedUnitMatrix.cpp -o distributedUnitMatrix.x

mpirun -np 3 --oversubscribe distributedUnitMatrix.x 6
 */
