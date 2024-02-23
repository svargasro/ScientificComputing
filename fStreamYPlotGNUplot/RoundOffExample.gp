set xlabel 'k'
set ylabel 'f(k)'
set term pdf
set out "fk.pdf"
plot 'data.txt' w lp lw 4 ps 2 t 'data'
