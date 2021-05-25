#include <iostream>
#include "bifurcationplot.hpp"
#include "population.hpp"

int main() {
  BifurcationPlot bifplot = BifurcationPlot();
  bifplot.scan_r("out.txt");
  return 0;
}