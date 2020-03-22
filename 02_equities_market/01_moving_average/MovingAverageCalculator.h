#ifndef __FinancialSamples_MovingAverageCalculator__
#define __FinancialSamples_MovingAverageCalculator__

#include <vector>

class MovingAverageCalculator
{
public:
  MovingAverageCalculator(int period);
  MovingAverageCalculator(const MovingAverageCalculator &v);
  MovingAverageCalculator &operator=(const MovingAverageCalculator &v);
  ~MovingAverageCalculator();

  void addPriceQuote(double close);
  std::vector<double> calculateMA();
  std::vector<double> calculateEMA();
private:
  int m_numPeriods;
  std::vector<double> m_prices;
};

#endif /* defined(__FinancialSamples_MovingAverageCalculator__) */