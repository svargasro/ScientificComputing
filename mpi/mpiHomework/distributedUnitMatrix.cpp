#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>

void fillMatrix(int N, int np, int pid);

int main(int argc, char **argv)
{
  
  //int N = std::atoi(argv[1]);
  int N=12;
  int tag1 = 0;
  int tag2 = 1;


  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  fillMatrix(N, np, pid);
  // double Inicio, Fin;

  // if (pid == 0)
  // {
	//   Inicio = MPI_Wtime();
	//   MPI_Send(&msgVector[0], N, MPI_DOUBLE, 1, tag1, MPI_COMM_WORLD);
	//   MPI_Recv(&msgVector[0], N, MPI_DOUBLE, 1, tag2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	//   Fin = MPI_Wtime();
	//   double t= Fin - Inicio;
	//   double bandWidth = (N*sizeof(double)/(t/2.0))/std::pow(10.0,6);
	//   std::cout<<N<<" "<<bandWidth<<std::endl;
	//   //	  std::cout<<t<<std::endl;

  // }
  // else if (pid == 1)
  // {

  //   MPI_Recv(&msgVector[0], N, MPI_DOUBLE, 0, tag1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  //   MPI_Send(&msgVector[0], N, MPI_DOUBLE, 0, tag2, MPI_COMM_WORLD);
  // }

  MPI_Finalize();
  return 0;
}

void fillMatrix(int N, int np, int pid){


  int localRows= N/np;

/*
Se linealiza la matriz de tal forma que el elemento (0,0) tiene el índice 0 y es el que está en la esquina superior izquierda.
El elemento (0,1) tiene el índice 1 y está a la derecha del elemento (0,0).
Se adopta la convención (fila, columna) donde la fila 0 corresponde a la que está más arriba y la columna 0 a la que está más a la izquierda.
*/
  int matrixSize= localRows*N;
  std::vector<int> localMatrix(matrixSize,0);




  int initialOne= pid*localRows; //La ubicación del primer 1 en el arreglo.

  //Habrán tantos 1 como el tamaño de filas de la matriz local:
  for(int i=0;i<localRows;i++) {
    int indexOne= initialOne + i*(N+1); //El siguiente 1 estará ubicado siempre a N+1 posiciones del anterior 1.
  localMatrix[indexOne] = 1; //Se llenan los valores de 1 correspondientes.
//  std::cout<<"pid: "<<pid<<" "<<"index1: "<<indexOne<<"\n";
  }
  int tag=0;

  if(pid==0){
    std::cout<<"pid: "<<pid<<"\n";
    //Se recorre el arreglo y para que quede como una matriz, se imprime un salto de línea cuando se completa el número de columnas.
    for (int i=0;i<matrixSize;i++) {
      std::cout<<localMatrix[i]<<" ";
      if((i+1)%N==0){std::cout<<"\n";}
    }
    for(int ipid=1; ipid<np; ipid++){
    //Recibir: mpi

    std::vector<int> tmpLocalMatrix(matrixSize);
    MPI_Recv(&tmpLocalMatrix[0], matrixSize, MPI_INT, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    for (int i=0;i<matrixSize;i++) {
      std::cout<<tmpLocalMatrix[i]<<" ";
      if((i+1)%N==0){std::cout<<"\n";}
    }
  }
  }
  else{
  MPI_Send(&localMatrix[0], matrixSize, MPI_INT, 0, tag, MPI_COMM_WORLD);
  }








}
