#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char **argv)
{
  
  int N = std::atoi(argv[1]);
  int tag1 = 0;
  int tag2 = 1;

  std::vector<double> msgVector(N);
  
    int pid, np;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    double Inicio, Fin;
    
      if (pid == 0)
        {
	  Inicio = MPI_Wtime();
	  MPI_Send(&msgVector[0], N, MPI_DOUBLE, 1, tag1, MPI_COMM_WORLD);	    
	  MPI_Recv(&msgVector[0], N, MPI_DOUBLE, 1, tag2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  Fin = MPI_Wtime();
	  double t= Fin - Inicio;
	  double bandWidth = (N*sizeof(double)/(t/2.0))/std::pow(10.0,6);
	  std::cout<<N<<" "<<bandWidth<<std::endl;
	  //	  std::cout<<t<<std::endl;
	  
        }
        else if (pid == 1)
        {
            
            MPI_Recv(&msgVector[0], N, MPI_DOUBLE, 0, tag1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   
	    MPI_Send(&msgVector[0], N, MPI_DOUBLE, 0, tag2, MPI_COMM_WORLD);
        }
    
    MPI_Finalize();
    return 0;
}

//for N in $(seq 0 500 20000); do mpirun -np 2 a.out $N; done > BW1PC.txt

/*
  Arias Polanco Emmanuel, Castro Millan Juan Sebastian, Sanchez Poveda Juan Felipe, Millan Diaz Juan Esteban, Vargas Rodriguez Sergio.
 */




