# Ejercicio.

Como puede ver, para llenar correctamente el arreglo local y que represente bien su parte en la matriz global se debe tener en cuenta el pid.

** Recibir un argumento de la línea de comandos que indica el valor de N
** Asegurarse de que cada procesos llene correctamente la submatriz local de acuerdo a su pid

** Coordinar para que el proceso con pid 0 imprima la matriz completa correctamente y en orden. Esto se puede hacer así:

1. El proceso 0 imprime su parte de la matriz
2. Luego el proceso 0 va recibiendo la matriz de cada uno de los otros procesos y la va imprimiendo. Los otros procesos simplemente envían su pedazo de matriz al proceso 0.

** El pid 0 tambien debe imprimir el ancho de banda de la comunicacion con cada nodo (se puede sacar un promedio entre los nodos). NO incluir el tiempo de impresión, solamente comunicación.

Debe adjuntar el archivo .cpp funcional. La evaluación se realizará verificando que el programa imprime correctamente la matriz para cualquier valor de N y de NP (desde que NP sea divisor de N, se puede hacer esa suposición). 
