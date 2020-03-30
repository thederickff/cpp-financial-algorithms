 #include "FundamentalsCalculator.h"
 
FundamentalsCalculator::FundamentalsCalculator(const std::string &ticker, double price, double dividend)
: m_ticker(ticker), m_price(price), m_dividend(dividend),
  m_assets(0), m_bookValue(0), m_earnings(0), m_epsGrowth(0),
  m_expectedEarnings(0), m_liabilitiesAndIntangibles(0),
  m_netIncome(0), m_numberOfShares(0), m_shareholdersEquity(0)
{

}

FundamentalsCalculator::FundamentalsCalculator(const FundamentalsCalculator &v)
: m_assets(v.m_assets), m_bookValue(v.m_bookValue),
  m_dividend(v.m_dividend), m_earnings(v.m_earnings),
  m_epsGrowth(v.m_epsGrowth), m_expectedEarnings(v.m_expectedEarnings),
  m_liabilitiesAndIntangibles(v.m_liabilitiesAndIntangibles),
  m_netIncome(v.m_netIncome), m_numberOfShares(v.m_numberOfShares),
  m_price(v.m_price), m_shareholdersEquity(v.m_shareholdersEquity),
  m_ticker(v.m_ticker)
{

}

FundamentalsCalculator &FundamentalsCalculator::operator=(const FundamentalsCalculator &v)
{
  if (this != &v)
  {
    this->m_assets = v.m_assets;
    this->m_bookValue = v.m_bookValue;
    this->m_dividend = v.m_dividend;
    this->m_earnings = v.m_earnings;
    this->m_epsGrowth = v.m_epsGrowth;
    this->m_expectedEarnings = v.m_expectedEarnings;
    this->m_liabilitiesAndIntangibles = v.m_liabilitiesAndIntangibles;
    this->m_netIncome = v.m_netIncome;
    this->m_numberOfShares = v.m_numberOfShares;
    this->m_price = v.m_price;
    this->m_shareholdersEquity = v.m_shareholdersEquity;
    this->m_ticker = v.m_ticker;
  }

  return *this;
}

FundamentalsCalculator::~FundamentalsCalculator()
{
}

void FundamentalsCalculator::setNumberOfShares(int n)
{
  m_numberOfShares = n;
}

void FundamentalsCalculator::setEarnings(double val)
{
  m_earnings = val;
}

void FundamentalsCalculator::setExpectedEarnings(double val)
{
  m_expectedEarnings = val;
}

void FundamentalsCalculator::setBookValue(double val)
{
  m_bookValue = val;
}

void FundamentalsCalculator::setAssets(double val)
{
  m_assets = val;
}

void FundamentalsCalculator::setLiabilitiesAndIntangibles(double val)
{
  m_liabilitiesAndIntangibles = val;
}

void FundamentalsCalculator::setEpsGrowth(double val)
{
  m_epsGrowth = val;
}

void FundamentalsCalculator::setNetIncome(double val)
{
  m_netIncome = val;
}

void FundamentalsCalculator::setShareholdersEquity(double val)
{
  m_shareholdersEquity = val;
}


double FundamentalsCalculator::PE()
{
  return (m_price * m_numberOfShares) / m_earnings;
}

double FundamentalsCalculator::fowardPE()
{
  return (m_price * m_numberOfShares) / m_expectedEarnings;
}

double FundamentalsCalculator::bookValue()
{
  return m_bookValue;
}

double FundamentalsCalculator::priceToBookRatio()
{
  return (m_price * m_numberOfShares) / (m_assets - m_liabilitiesAndIntangibles);
}

double FundamentalsCalculator::priceEarningsToGrowth()
{
  return PE() / m_epsGrowth;
}

double FundamentalsCalculator::returnOnEquity()
{
  return m_netIncome / m_shareholdersEquity;
}

double FundamentalsCalculator::getDividend()
{
  return m_dividend;
}
