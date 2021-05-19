#include <vector>

class Population
{

  double start_individuals, growth_rate, individuals;
  int generations;
  double next_generation();
  double get_growth_rate();
  double get_start_individuals();
  double get_individuals();
  int get_generations();
  std::vector<double> run_simulation();

public:

  Population(double r, double v = 0.01, int n = 10000000);
  ~Population();
  
  std::vector<double> find_limits(int p = 1000);

};
