#!/bin/bash
#SBATCH --job-name=mpi_BW     # Job name
#SBATCH --output=mpi_BW_%j.out        # Standard output  log
#SBATCH --error=mpi_BW_%j.err        # Standard  error log
#SBATCH --ntasks=2                # Number of MPI tasks (processes)
#SBATCH --nodes=2                 # Number of nodes
#SBATCH --ntasks-per-node=1        # Adjust based on your cluster's configuration
#SBATCH --time=01:00:00            # Time limit hrs:min:sec
#SBATCH --partition=12threads        # Partition name

## Load the necessary modules (adjust based on your system)
#module load mpi

# Run the MPI program using srun
#srun pwd
#srun hostname
#srun --mpi=pmi2 ./a.out
#srun --mpi=pmi2 hostname
#srun echo $SLURMD_NODENAME
#srun -n $SLURM_NTASKS ./a.out
for N in $(seq 0 500 20000); do mpirun -np 2 ./a.out $N; done 

#mpirun hostname
