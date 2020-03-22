#include "CompoundIntRateCalculator.h"

#include <cmath>

CompoundIntRateCalculator::CompoundIntRateCalculator(double rate)
: m_rate(rate)
{
}

CompoundIntRateCalculator::~CompoundIntRateCalculator()
{
}

CompoundIntRateCalculator::CompoundIntRateCalculator(const CompoundIntRateCalculator &v)
: m_rate(v.m_rate)
{
}

CompoundIntRateCalculator &CompoundIntRateCalculator::operator=(const CompoundIntRateCalculator &v)
{
  if (this != &v)
  {
    this->m_rate = v.m_rate;
  }

  return *this;
}

double CompoundIntRateCalculator::multiplePeriod(double value, int numPeriods)
{
  return value * pow(1 + m_rate, numPeriods);
}

double CompoundIntRateCalculator::continuousCompound(double value, int numPeriods)
{
  return value * exp(m_rate * numPeriods);
}
