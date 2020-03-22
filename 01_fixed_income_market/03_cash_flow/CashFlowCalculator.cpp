#include "CashFlowCalculator.h"

#include <iostream>
#include <cmath>

CashFlowCalculator::CashFlowCalculator(double rate)
: m_rate(rate)
{
}

CashFlowCalculator::CashFlowCalculator(const CashFlowCalculator &v)
: m_rate(v.m_rate)
{
}

CashFlowCalculator &CashFlowCalculator::operator=(const CashFlowCalculator &v)
{
  if (this != &v)
  {
    this->m_cashPayments = v.m_cashPayments;
    this->m_timePeriods = v.m_timePeriods;
    this->m_rate = v.m_rate;    
  }

  return *this;
}

CashFlowCalculator::~CashFlowCalculator()
{
}

void CashFlowCalculator::addCashPayment(double value, int timePeriod)
{
  m_cashPayments.push_back(value);
  m_timePeriods.push_back(timePeriod);
}

double CashFlowCalculator::presentValue()
{
  double total = 0;

  for (int i = 0; i < m_cashPayments.size(); ++i) {
    total += presentValue(m_cashPayments[i], m_timePeriods[i]);
  }

  return total;
}

double CashFlowCalculator::presentValue(double futureValue, int timePeriod)
{
  double pv = futureValue / pow(1 + m_rate, timePeriod);

  std::cout << " value " << pv << std::endl;

  return pv;
}