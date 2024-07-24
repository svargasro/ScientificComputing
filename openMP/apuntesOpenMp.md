Usamos #include "omp.h"
#pragma omp pararell 




La línea "#pragma omp parallel for reduction(+:suma)" de pragmaParallelFor.cpp me dice que hagamos un for paralelo y un reduction sobre la suma. Reparte el rango del for en threads y convierte variables privadas con una sola instrucción. 
(+:variable)

No olvidar: g++ -fopenpm 
Y OMP_NUM_THREADS=2 ./a.out



Repaso:
openMP es para memoria compartida. 

SpeedUp:
S= T1/TN 
S_ideal = T1/T1/N = N 

Eficiencia:
E = S/N


thrd = ...





