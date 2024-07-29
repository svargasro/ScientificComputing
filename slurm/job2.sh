#!/bin/bash
#SBATCH --partition=12threads
#SBATCH --job-name="openMPSlurm"
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=12
#SBATCH --mem-per-cpu=660


export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

time ./a.out 1000000000





