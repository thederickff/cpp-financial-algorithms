#include "CompoundIntRateCalculator.h"

#include <iostream>

int main(int argc, const char *argv[])
{

  if (argc != 4)
  {
    std::cout << "usage: progName <interest rate> <present value> <num periods>" << std::endl;

    return 1;
  }

  double interest = atof(argv[1]);
  double value = atof(argv[2]);
  int numPeriods = atoi(argv[3]);

  CompoundIntRateCalculator circ(interest);
  double res = circ.multiplePeriod(value, numPeriods);
  double conRes = circ.continuousCompound(value, numPeriods);

  std::cout << " future value for multiple period compound is " << res << std::endl;
  std::cout << " future value for continuous compound is " << conRes << std::endl;

  return 0;
}