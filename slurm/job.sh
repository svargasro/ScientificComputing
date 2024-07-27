#SBATCH --partition=12threads
#SBATCH --ntasks-per-node=12
stress -t 10 -c 1




#Este comando es equivalente a usar SBATCH
#srun -p 12threads -n 18 stress -t 10 -c 1





# # SBATCH --nodes=2
# # BATCH --job-name="testmulti"
# # SBATCH --account="HerrComp" # not used
# # SBATCH --mail-type=ALL
# # SBATCH --mail-user=wfoquendop@unal.edu.co
# # SBATCH --time=01:00:00
# # SBATCH --cpus-per-task=1
