#include <iostream>
#include "bifurcationplot.hpp"
#include "population.hpp"

int main() {
  BifurcationPlot bifplot = BifurcationPlot(1, 4, 0.01, 0.25, 100000);
  bifplot.scan_r("out.txt");
  return 0;
}