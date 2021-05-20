#include <iostream>
#include <algorithm>
#include "Population.hpp"
#include "float_ops.hpp"

Population::Population(double r, double v, int n)
{
  start_individuals = v;
  generations = n;
  growth_rate = r;
}

std::vector<double> Population::run_simulation()
{
  std::vector<double> simulation(generations);  
  simulation[0] = start_individuals;

  for (int i = 1; i < generations; i++)
  {
    simulation[i] = growth_rate * simulation[i - 1] * (1 - simulation[i - 1]);
  }
  
  return simulation;
}

std::vector<double> Population::find_limits(int p)
{
  if (p < 1000 || generations / p < 1000)
  {
    std::cout << "Error: Population equilibrium is evaluated on the last ";
    std::cout << p << " generations out of a total of " << generations;
    std::cout << " generations.\n";
    std::cout << "Equilibrium cannot be assessed with reasonable precision.\n";
    exit(1);
  }
  else
  {
    std::vector<double> sim = run_simulation();
    std::vector<double> v = std::vector<double>(sim.begin() + sim.size() - p, sim.end());
    sort(v.begin(), v.end());

    std::vector<double> limits;
    limits.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
      bool ans = are_different(v[i], v[i - 1]);
      if (ans) {
        limits.push_back(v[i]);
      }
    }
    
    return limits;
  }

}

double Population::get_growth_rate()
{
  return growth_rate;
}

double Population::get_start_individuals()
{
  return start_individuals;
}

int Population::get_generations()
{
  return generations;
}

Population::~Population()
{

}
