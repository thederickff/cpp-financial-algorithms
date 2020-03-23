#include "VolatilityCalculator.h"

#include <iostream>
#include <cmath>

VolatilityCalculator::VolatilityCalculator()
{
}

VolatilityCalculator::VolatilityCalculator(const VolatilityCalculator &v)
: m_prices(v.m_prices)
{
}

VolatilityCalculator &VolatilityCalculator::operator=(const VolatilityCalculator &v)
{
  if (this != &v)
  {
    this->m_prices = v.m_prices;
  }

  return *this;
}

VolatilityCalculator::~VolatilityCalculator()
{
}

void VolatilityCalculator::addPrice(double price)
{
  m_prices.push_back(price);
}

double VolatilityCalculator::rangeVolatility()
{
  if (m_prices.size() < 1) {
    return 0;
  }

  double min = m_prices[0];
  double max = min;

  for (int i = 1; i < m_prices.size(); ++i)
  {
    if (min > m_prices[i]) {
      min = m_prices[i];
    }

    if (max < m_prices[i]) {
      max = m_prices[i];
    }
  }

  return max - min;
}

double VolatilityCalculator::averageDailyRange()
{
  if (m_prices.size() < 2) {
    return 0;
  }

  double previous = m_prices[0];
  double sum = 0;

  for (int i = 1; i < m_prices.size(); ++i) {
    double range = abs(m_prices[i] - previous);
    sum += range;
  }
  
  return sum / m_prices.size() - 1;
}


double VolatilityCalculator::mean()
{
  double total = 0;

  for (int i = 0; i < m_prices.size(); ++i)
  {
    total += m_prices[i];
  }

  return total / m_prices.size();
}

double VolatilityCalculator::standardDeviation()
{
  double average = mean();
  double sum = 0;

  for (int i = 0; i < m_prices.size(); ++i) {
    double val = m_prices[i] - average;
    sum += val * val;
  }

  return sqrt(sum / (m_prices.size() - 1));
}
