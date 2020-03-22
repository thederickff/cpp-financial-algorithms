#ifndef __FinancialSamples_CashFlowCalculator__
#define __FinancialSamples_CashFlowCalculator__

#include <vector>

class CashFlowCalculator
{
public:
  CashFlowCalculator(double rate);
  CashFlowCalculator(const CashFlowCalculator &v);
  CashFlowCalculator &operator=(const CashFlowCalculator &v);
  ~CashFlowCalculator();

  void addCashPayment(double value, int timePeriod);
  double presentValue();
private:
  std::vector<double> m_cashPayments;
  std::vector<double> m_timePeriods;
  double m_rate;
  double presentValue(double futureValue, int timePeriod);
};

#endif /* defined(__FinancialSamples_CashFlowCalculator__) */