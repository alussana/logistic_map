g++ *cpp *hpp
./a.out
cat out.txt | awk '{ for(i=2; i <= NF; i++){print $1"\t"$i} }' > bifurcation_plot.txt
gnuplot bifurcation_plot.gp
