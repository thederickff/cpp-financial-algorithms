#ifndef __FinancialSamples_CorrelationCalculator__
#define __FinancialSamples_CorrelationCalculator__

#include "TimeSeries.h"

class CorrelationCalculator
{
public:
  CorrelationCalculator(const TimeSeries &tsA, const TimeSeries &tsB);
  CorrelationCalculator(const CorrelationCalculator &v);
  CorrelationCalculator &operator=(const CorrelationCalculator &v);
  ~CorrelationCalculator();

  double correlation();
private:
  TimeSeries m_tsA;
  TimeSeries m_tsB;
};

#endif /* defined(__FinancialSamples_CorrelationCalculator__) */