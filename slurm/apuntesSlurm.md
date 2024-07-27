Cluster (NLHPC)

Comandos:

* sinfo: idle significa que se puede usar.
* squeue: Dice qué trabajos se están ejecutando. 
* srun: Correr tarea. Comandos interactivos.
* Varias tareas a la vez: -n (Cuántos task) -N(Número máximo de nodos que se van a usar)
Comando "srun -n 2 -N 2 hostname" 2 procesos en 2 nodos, por lo tanto en cada nodo un proceso. Salen 2 salas. 
Cada partición tiene un número de nodos. (Nodo es como computador)
* scancel JOBID: Cancela un srun

Bandera -p indica partición: 

srun -p 12threads,16threads -n 10 -N 5 hostname


Stress: 
stress -t 10 -c 1
(Timeout 10 segundos, mata a los 10 segundos y usa un core. Corre un programa pesado.)



*********************************
Slurm Scripts:
