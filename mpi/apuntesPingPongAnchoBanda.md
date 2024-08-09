Medimos BW vs tamaño.

Veremos que cuando hagamos entre dos computadores va a tomar más tiempo que en un solo computador.

Tenemos que mandar n enteros, a diferencia que en PingPong. No solo 1. -> Usamos un arreglo de tamaño N. Vector data.

MPI_Send(&data[0],N,MPI_DOUBLE, )
MPI_Send(Dónde empieza,cuántos envío, tipo de datos, )

*Tiempo: Lo mido en el cero (MPI_Send): t1
En MPI_Recv: t2

Y entonces t=t2-t1.

*Ya no necesito operación. Solo envío y recepción. 
Para medir tiempo: MPI_Wtime

Bandwidth = Tamaño/(t/2)
