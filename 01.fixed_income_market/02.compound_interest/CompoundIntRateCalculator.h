#ifndef __FinancialSamples_CompoundIntRateCalculator__
#define __FinancialSamples_CompoundIntRateCalculator__

class CompoundIntRateCalculator {
public:
  CompoundIntRateCalculator(double rate);
  CompoundIntRateCalculator(const CompoundIntRateCalculator &v);
  CompoundIntRateCalculator &operator=(const CompoundIntRateCalculator &v);
  ~CompoundIntRateCalculator();

  double multiplePeriod(double value, int numPeriods);
  double continuousCompound(double value, int numPeriods);
private:
  double m_rate;
};

#endif /* defined(__FinancialSamples_CompoundIntRateCalculator__) */