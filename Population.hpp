#include <vector>

class Population
{

  double start_individuals, growth_rate;
  int generations;
  double get_growth_rate();
  double get_start_individuals();
  int get_generations();
  std::vector<double> run_simulation();

public:

  Population(double, double = 0.01, int = 10000000);
  ~Population();
  
  std::vector<double> find_limits(int = 1000);

};
