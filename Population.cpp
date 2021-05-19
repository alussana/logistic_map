#include <iostream>
#include <algorithm>
#include "Population.hpp"

Population::Population(double r, double v, int n)
{
  start_individuals = v;
  generations = n;
  growth_rate = r;
  individuals = start_individuals;
}

double Population::next_generation()
{
  double new_individuals = growth_rate * individuals * (1 - individuals);
  individuals = new_individuals;
  return individuals;
}

std::vector<double> Population::run_simulation()
{
  std::vector<double> simulation(generations);
  for (int i = 0; i < generations; i++)
  {
    simulation[i] = next_generation();
  }
  return simulation;
}

std::vector<double> Population::find_limits(int p)
{
  if (p < 10 || generations / p < 1000)
  {
    std::cout << "Error: Population equilibrium is evaluated on the last ";
    std::cout << p << " generations out of a total of " << generations;
    std::cout << " generations.";
    exit(1);
  }
  else
  {
    std::vector<double> sim = run_simulation();
    std::vector<double> v = std::vector<double>(sim.begin() + sim.size() - p, sim.end());
    sort(v.begin(), v.end());

    std::vector<double> limits;
    double q = v[0];
    limits.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
      // TODO: write function to compare floats given some pecision epsilon
      if (v[i] != q) {
        limits.push_back(v[i]);
        q = v[i];
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

double Population::get_individuals()
{
  return individuals;
}

int Population::get_generations()
{
  return generations;
}

Population::~Population()
{

}
