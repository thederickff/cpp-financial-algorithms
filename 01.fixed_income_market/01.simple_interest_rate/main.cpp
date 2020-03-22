#include "IntRateCalculator.h"

#include <iostream>

int main(int argc, const char* argv[])
{
  if (argc != 3)
  {
    std::cout << "usage: progName <interest rate> <value>" << std::endl;
    return 1;
  }

  double rate = atof(argv[1]);
  double value = atof(argv[2]);

  IntRateCalculator irc(rate);
  double res = irc.singlePeriod(value);
  std::cout << "result is " << res << std::endl;

  return 0;
}