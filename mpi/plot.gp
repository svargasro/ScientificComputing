# Configurar el terminal (opcional)
set terminal pdf
set output 'BW2.pdf'  

# Títulos de los ejes
set xlabel 'Size [N]'
set ylabel 'Bandwidth [Mb]'

# Título del gráfico
set title 'Bandwidth vs N'

# Cambiar las leyendas (labels)
set key top left  # Posicionar la leyenda en la esquina superior izquierda

# Graficar los dos conjuntos de datos
plot 'BW1PC.txt' using 1:2 with points title '1 computador', \
     'mpi_BW_2192.out' using 1:2 with points title '2 computadores'

# Si estás usando un script, puedes ejecutar gnuplot desde la consola:
# gnuplot graficos.gnu