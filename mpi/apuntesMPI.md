

Tenemos varios procesos, cada uno con memoria independiente.
* Variables privadas 
* Nos permite ejecutar en varias máquinas. 
* Si necesitamos que los procesos se comuniquen, MPI nos ayuda a que eso suceda.

mpi: Message Passing Interface:
- Point to point: send, recv.
- Point to may points: broadcas, scatter.


¿Cómo se compila?

mpic++ mpi_code.cpp

¿Cómo se corre?

mpirun -np 2 ./a.out

¿Qué es importante saber? 
Quién soy yo y cuántos hay. 

int pid = mpi_...

if(pid==0){

}
else{


}


Slurm: Manejador de recursos:
Con sbatch lo corre en background, no interactivo.

$sbatch ___.sh


## IntroMPI (Memoria distribuida):

