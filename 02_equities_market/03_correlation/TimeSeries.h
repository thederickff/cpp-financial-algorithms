#ifndef __FinancialSamples_TimeSeries__
#define __FinancialSamples_TimeSeries__

#include <iostream>
#include <vector>

class TimeSeries
{
public:
  TimeSeries();
  TimeSeries(const TimeSeries &v);
  TimeSeries &operator=(const TimeSeries &v);
  ~TimeSeries();

  void addPrice(double value);
  double standardDeviation();
  double averagePrice();

  size_t size();
  double elem(int i);
private:
  std::vector<double> m_prices;
};

#endif /* defined(__FinancialSamples_TimeSeries__) */