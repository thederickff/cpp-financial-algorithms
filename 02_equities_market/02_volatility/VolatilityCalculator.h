#ifndef __FinancialSamples_VolatilityCalculator__
#define __FinancialSamples_VolatilityCalculator__

#include <vector>

class VolatilityCalculator
{
public:
  VolatilityCalculator();
  VolatilityCalculator(const VolatilityCalculator &v);
  VolatilityCalculator &operator=(const VolatilityCalculator &v);
  ~VolatilityCalculator();

  void addPrice(double price);
  double rangeVolatility();
  double standardDeviation();
  double mean();
  double averageDailyRange();

private:
  std::vector<double> m_prices;
};

#endif /* defined(__FinancialSamples_VolatilityCalculator__) */