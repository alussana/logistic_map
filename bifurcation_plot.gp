set term png size 1200,800
set out "bifurcation_plot.png"
set title "x_{n+1} = rx_n(1 - x_n)"
set xlabel "r"
set ylabel "x at steady state"
plot "bifurcation_plot.txt" using 1:2 pt 7 ps 0.1 notitle
set out
