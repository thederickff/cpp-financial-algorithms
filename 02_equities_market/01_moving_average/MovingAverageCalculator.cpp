#include "MovingAverageCalculator.h"

MovingAverageCalculator::MovingAverageCalculator(int period)
: m_numPeriods(period)
{
}

MovingAverageCalculator::MovingAverageCalculator(const MovingAverageCalculator &v)
: m_numPeriods(v.m_numPeriods), m_prices(v.m_prices)
{
}

MovingAverageCalculator &MovingAverageCalculator::operator=(const MovingAverageCalculator& v)
{
  if (this != &v)
  {
    this->m_numPeriods = v.m_numPeriods;
    this->m_prices = v.m_prices;
  }

  return *this;
}

MovingAverageCalculator::~MovingAverageCalculator()
{
}

void MovingAverageCalculator::addPriceQuote(double close)
{
  m_prices.push_back(close);
}

std::vector<double> MovingAverageCalculator::calculateMA()
{
  std::vector<double> ma;
  double total = 0;

  for (int i = 0; i < m_prices.size(); ++i)
  {
    total += m_prices[i];

    if (i >= m_numPeriods) {
      ma.push_back(total / m_numPeriods);
      total -= m_prices[i - m_numPeriods];
    }
  }

  return ma;
}

std::vector<double> MovingAverageCalculator::calculateEMA()
{
  std::vector<double> ema;
  double multiplier = 2.0 / (m_numPeriods + 1);
  double total = 0;

  for (int i = 0; i < m_prices.size(); ++i)
  {
    total += m_prices[i];

    if (i == m_numPeriods) {
      ema.push_back(total / m_numPeriods);
      total -= m_prices[i - m_numPeriods];
    } else if (i > m_numPeriods) {
      ema.push_back((1 - multiplier) * ema.back() + multiplier * m_prices[i]);
      total -= m_prices[i - m_numPeriods];
    }
  }

  return ema;
}