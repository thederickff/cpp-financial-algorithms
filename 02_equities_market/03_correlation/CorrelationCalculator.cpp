#include "CorrelationCalculator.h"

#include <iostream>
#include <cmath>

CorrelationCalculator::CorrelationCalculator(const TimeSeries& tsA, const TimeSeries& tsB)
: m_tsA(tsA), m_tsB(tsB)
{
}

CorrelationCalculator::CorrelationCalculator(const CorrelationCalculator &v)
: m_tsA(v.m_tsA), m_tsB(v.m_tsB)
{
}

CorrelationCalculator &CorrelationCalculator::operator=(const CorrelationCalculator &v)
{
  if (this != &v)
  {
    this->m_tsA = v.m_tsA;
    this->m_tsB = v.m_tsB;
  }

  return *this;
}

CorrelationCalculator::~CorrelationCalculator()
{
}

double CorrelationCalculator::correlation()
{
  if (m_tsA.size() != m_tsB.size()) {
    std::cout << "error: number of observations is different" << std::endl;
    return -1;
  }

  double meanA = m_tsA.averagePrice();
  double meanB = m_tsB.averagePrice();
  double total = 0;

  for (int i = 0; i < m_tsA.size(); ++i) {
    total += (m_tsA.elem(i) - meanA) * (m_tsB.elem(i) - meanB);
  }

  double devA = m_tsA.standardDeviation();
  double devB = m_tsB.standardDeviation();

  total /= (devA * devB);

  return total / (m_tsA.size() - 1);
}
