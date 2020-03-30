#include "FundamentalsCalculator.h"

#include <iostream>

int main(int argc, const char *argv[])
{
  FundamentalsCalculator fc("AAPL", 543.99, 12.20);

  // values are in millions
  fc.setAssets(243139);
  fc.setBookValue(165234);
  fc.setEarnings(35885);
  fc.setEpsGrowth(0.22);
  fc.setExpectedEarnings(39435);
  fc.setLiabilitiesAndIntangibles(124642);
  fc.setNetIncome(37235);
  fc.setNumberOfShares(891990);
  fc.setShareholdersEquity(123549);

  std::cout << "P/E: " << fc.PE() / 1000 << std::endl; // price in thousands
  std::cout << "Forward P/E: " << fc.forwardPE() / 1000 << std::endl;
  std::cout << "Book Value: " << fc.bookValue() << std::endl;
  std::cout << "Price to Book: " << fc.priceToBookRatio() << std::endl;
  std::cout << "Price earnings to growth: " << fc.priceEarningsToGrowth() << std::endl;
  std::cout << "Return on equity: " << fc.returnOnEquity() << std::endl;
  std::cout << "Dividend: " << fc.getDividend() << std::endl;

  return 0;
}