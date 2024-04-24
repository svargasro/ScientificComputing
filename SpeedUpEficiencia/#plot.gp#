set term pdf size 3in,3in font "Times New Roman,10"
set out "speed-up.pdf"

set xlabel "nThreads"
set ylabel "SpeedUp"

set xrange [0:16];
set yrange [0:16];

plot x lc "black" notitle, \
	 "speedUp.txt" using 1:2 pt 5 ps 0.5 dt 2 lc "green" notitle

set xlabel "nThreads"
set ylabel "Eficiencia"

set xrange [0:16];
set yrange [0:1.01];

plot 1 lc "red" notitle, \
	 0.6 lc "blue" notitle, \
	 "speedUp.txt" using 1:3 pt 5 ps 0.5 dt 2 lc "green" notitle

unset output