#include "CorrelationCalculator.h"

#include <iostream>


int main(int argc, const char *argv[])
{
  TimeSeries tsA;
  TimeSeries tsB;

  double priceA;
  double priceB;

  while (true) {
    std::cin >> priceA; 

    if (priceA == -1) {
      break;
    }

    std::cin >> priceB; 

    if (priceB == -1) {
      break;
    }

    tsA.addPrice(priceA);
    tsB.addPrice(priceB);
  }

  CorrelationCalculator cc(tsA, tsB);

  std::cout << " correlation is " << cc.correlation() << std::endl;

  return 0;
}