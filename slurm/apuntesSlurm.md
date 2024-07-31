Cluster (NLHPC)

Comandos:

* sinfo: idle significa que se puede usar.
* squeue: Dice qué trabajos se están ejecutando. 
* srun: Correr tarea. Comandos interactivos.
* Varias tareas a la vez: -n (Cuántos task) -N(Número máximo de nodos que se van a usar)
Comando "srun -n 2 -N 2 hostname" 2 procesos en 2 nodos, por lo tanto en cada nodo un proceso. Salen 2 salas. 
Cada partición tiene un número de nodos. (Nodo es como computador)
* scancel JOBID: Cancela un srun
* scontrol show partition "name" (Muestra info más general)
Bandera -p indica partición: 

* watch -n1 squeue (Ver comando cada 1 segundo)

srun -p 12threads,16threads -n 10 -N 5 hostname



Stress: 
stress -t 10 -c 1
(Timeout 10 segundos, mata a los 10 segundos y usa un core. Corre un programa pesado.)



*********************************
Slurm Scripts: Queremos decirle a Slurm lo que necesitamos que haga. 
Quiero dejar solo el comando stress dentro.

job.sh
Para correr: bash job.sh

Comentarios dentro de .sh se escriben como $SBATCH (Ver job.sh)

Para correr con $SBATCH:
sbatch job.sh


Hay generadores de scripts: https://wiki.nlhpc.cl/Generador_Scripts


Para mandar escalamiento, revisar si los nodos tienen el mismo procesador, por ejemplo. Deben ser exactamente iguales. cs

************************************************
Con paralelo:

Cuando estoy usando paralelo, entonces como quiero un solo comando pero que corra en varios nodos, entonces se usa #SBATCH --cpus-per-task=1

A veces hay que poner ruta a donde está ejecutable. 





--nodes 2
--ntasks-per-node=12 (Memoria distribuida: Procesos)

cpus-per-task: Threads por cada proceso. 

 
