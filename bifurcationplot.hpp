#include <string>
#include <vector>

class BifurcationPlot
{
  double min_growth_rate;
  double max_growth_rate;
  double step;
  double start_individuals;
  int generations;
  std::vector<std::vector<double>> scan_r();
  int find_steps();
public:
  int scan_r(std::string);
  BifurcationPlot(double = 1, double = 4, double = 0.001, double = 0.25, int = 100000);
  ~BifurcationPlot();
};