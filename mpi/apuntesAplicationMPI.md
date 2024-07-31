# MPI Aplicación Integración.

Algoritmos seriales más sencillos pero más fáciles de paralelizar. 


Inumérica = I cuando n tiene a infinito en el papel.

Pienso en partir sumatoria en 4.

In = sum = A1 + A2 + A3 
Partimos dominio. 

# Idea1:
Iserial 3000 
Iparalelo = 1000 + 1000 + 1000

# Idea2:
Iparalelo = 3000 + 3000 + 3000 (Tiempo no disminuye pero aumenta precisión.)

Tenemos 
Ntotal (Partición), np (numberprocess), pid (processid), a, b.

Nlocal = Ntotal/np (Si no es divisor hay que sumarle 1 más al último.)

if (pid == np-1){
Nlocal+ = 10%np;
}
 O bien podríamos repartir el sobrante de forma equivalente en todos los threads.
 
 LongLocal = (b-a)/np (Cuánto le toca a cada proceso)
 Hacen falta límites para cada proceso.
 
 xmin(pid) = a + LongLocal***pid
 xmax(pid) = xmin + llocal = (pid+1)*LongLocal

