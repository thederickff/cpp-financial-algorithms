#include "VolatilityCalculator.h"

#include <iostream>

int main(int argc, const char *argv[])
{
  VolatilityCalculator vc;
  double price;

  while (true) {
    std::cin >> price;

    if (price == -1) {
      break;
    }

    vc.addPrice(price);
  }

  std::cout << "range volatility is " << vc.rangeVolatility() << std::endl;
  std::cout << "average daily range is " << vc.averageDailyRange() << std::endl;
  std::cout << "standard deviation is " << vc.standardDeviation() << std::endl;

  return 0;
}