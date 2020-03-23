#include "TimeSeries.h"

#include <cmath>

TimeSeries::TimeSeries()
{
}

TimeSeries::TimeSeries(const TimeSeries &v)
: m_prices(v.m_prices)
{
}

TimeSeries &TimeSeries::operator=(const TimeSeries &v)
{
  if (this != &v)
  {
    this->m_prices = v.m_prices;
  }

  return *this;
}

TimeSeries::~TimeSeries()
{
}

void TimeSeries::addPrice(double value)
{
  m_prices.push_back(value);
}

double TimeSeries::standardDeviation()
{
  double total = 0;
  double mean = averagePrice();

  for (int i = 0; i < m_prices.size(); ++i)
  {
    double val = m_prices[i] - mean;
    total += val * val;
  }

  return sqrt(total / (m_prices.size() - 1));
}

double TimeSeries::averagePrice()
{
  double total = 0;

  for (int i = 0; i < m_prices.size(); ++i)
  {
    total += m_prices[i];
  }

  return total / m_prices.size();
}

size_t TimeSeries::size()
{
  return m_prices.size();
}

double TimeSeries::elem(int i)
{
  return m_prices[i];
}