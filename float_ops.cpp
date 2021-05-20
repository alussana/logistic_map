#include "float_ops.hpp"
#include <cmath>

bool are_different(double a, double b, double epsilon)
{
  return std::abs(a - b) > epsilon;
}