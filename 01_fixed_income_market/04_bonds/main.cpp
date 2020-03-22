#include "BondCalculator.h"

#include <iostream>

int main(int argc, const char *argv[])
{
  if (argc != 5)
  {
    
    std::cout << "usage: progName <institution> <principal> <coupon> <num periods>" << std::endl;

    return 1;
  }

  std::string issuer = argv[1];
  double principal = atof(argv[2]);
  double coupon = atof(argv[3]);
  int numPeriods = atoi(argv[4]);

  BondCalculator bc(issuer, numPeriods, principal, coupon);
  std::cout << "reading information for bond issued by " << issuer << std::endl;
  std::cout << " the internal rate of return is " << bc.interestRate() << std::endl;

  return 0;
}