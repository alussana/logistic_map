#include <iostream>
#include <vector>
#include "Population.hpp"

int main() {
  Population test_pop = Population(3, 0.25);
  
  std::vector<double> v = test_pop.find_limits();
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << "\n";
  }
  
  return 0;
}