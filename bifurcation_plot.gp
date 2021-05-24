set term png
set out "bifurcation_plot.png"
plot "bifurcation_plot.txt" using 1:2 pt 7 ps 0.1 notitle
set out
