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
  Population(double, double = 0.25, int = 100000);
  std::vector<double> find_steady_states(int = 500);
  ~Population();
};
