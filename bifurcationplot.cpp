#include "bifurcationplot.hpp"
#include "population.hpp"
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

BifurcationPlot::BifurcationPlot(double min_r, double max_r, double s, double v, int n)
{
  min_growth_rate = min_r;
  max_growth_rate = max_r;
  step = s;
  start_individuals = v;
  generations = n;
}

int BifurcationPlot::scan_r(std::string file_name)
{
  std::ofstream out_file;
  out_file.open(file_name);
  int steps = find_steps();
  for(int i = 0; i <= steps; i++)
  {
    double r = min_growth_rate + i * step;
    Population pop = Population(r, start_individuals, generations);
    std::vector<double> v = pop.find_steady_states();
    out_file << r;
    for(int j = 0; j < v.size(); j++)
    {
      out_file << "\t" << v[j];
    }
    out_file << "\n";
  }
  out_file.close();
  return 0;
}

std::vector<std::vector<double>> BifurcationPlot::scan_r()
{
  int steps = find_steps();
  for(int i = 0; i <= steps; i++)
  {
    double r = min_growth_rate + (double)i / (double)steps;
    Population pop = Population(r, start_individuals, generations);
    /*
    TODO
    */
  }
}

int BifurcationPlot::find_steps()
{
  float steps;
  steps = (max_growth_rate - min_growth_rate) / step;
  return std::round(steps);
}

BifurcationPlot::~BifurcationPlot()
{

}