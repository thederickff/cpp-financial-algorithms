#include "MovingAverageCalculator.h"

#include <iostream>

int main(int argc, const char *argv[])
{
  if (argc != 2)
  {
    std::cout << "usage: progName <num period>" << std::endl;

    return 1;
  }

  int numPeriods = atoi(argv[1]);

  double price;
  MovingAverageCalculator mac(numPeriods);

  while (1) {
    std::cin >> price;

    if (price == -1) {
      break;
    }

    mac.addPriceQuote(price);
  }

  std::vector<double> ma = mac.calculateMA();

  for (int i = 0; i < ma.size(); ++i)
  {
    std::cout << "average value " << i << " = " << ma[i] << std::endl;
  }

  std::vector<double> ema = mac.calculateEMA();

  for (int i = 0; i < ema.size(); ++i)
  {
    std::cout << "exponential average value " << i << " = " << ema[i] << std::endl;
  }


  return 0;
}