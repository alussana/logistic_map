#include "float_ops.hpp"
#include <cmath>

bool are_different(double const &a, double const &b, double epsilon)
{
  return std::fabs(a - b) > epsilon;
}

bool are_different(float const &a, float const &b, float epsilon)
{
  return std::fabs(a - b) > epsilon;
}