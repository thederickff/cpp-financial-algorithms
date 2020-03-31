#include "InvestmentInstrument.h"
#include "IntRateEngine.h"

#include <iostream>

int main(int argc, const char *argv[])
{
  IntRateEngine<BondInstrument> engineA;
  IntRateEngine<MortgageInstrument> engineB;

  BondInstrument bond(40000, 250);
  MortgageInstrument mortgage(250, 50000, 5000);

  engineA.setInstrument(bond);
  engineB.setInstrument(mortgage);

  std::cout << " bond anual int rate: " << engineA.getAnnualIntRate() * 100 << "%" << std::endl;
  std::cout << " mortgage anual int rate: " << engineB.getAnnualIntRate() * 100 << "%" << std::endl;

  return 0;
}