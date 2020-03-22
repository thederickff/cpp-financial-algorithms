#include "BondCalculator.h"

BondCalculator::BondCalculator(const std::string &institution, int numPeriods, double principal, double couponValue)
: m_institution(institution),
  m_numPeriods(numPeriods),
  m_principal(principal),
  m_coupon(couponValue)
{
}

BondCalculator::BondCalculator(const BondCalculator &v)
: m_institution(v.m_institution), 
  m_numPeriods(v.m_numPeriods),
  m_principal(v.m_principal),
  m_coupon(v.m_coupon)
{  
}

BondCalculator &BondCalculator::operator=(const BondCalculator &v)
{
  if (this != &v)
  {
    this->m_institution = v.m_institution;
    this->m_numPeriods = v.m_numPeriods;
    this->m_principal = v.m_principal;
    this->m_coupon = v.m_coupon;
  }

  return *this;
}

BondCalculator::~BondCalculator()
{
}

double BondCalculator::interestRate()
{
  return m_coupon / m_principal;
}