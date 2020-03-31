#include "InvestmentInstrument.h"

BondInstrument::BondInstrument(double principal, double monthlyPayment)
: m_principal(principal), m_monthlyPayment(monthlyPayment)
{

}

BondInstrument::BondInstrument(const BondInstrument &v)
: m_principal(v.m_principal), m_monthlyPayment(v.m_monthlyPayment)
{

}

BondInstrument &BondInstrument::operator=(const BondInstrument &v)
{
  if (this != &v)
  {
    this->m_principal = v.m_principal;
    this->m_monthlyPayment = v.m_monthlyPayment;
  }

  return *this;
}

BondInstrument::~BondInstrument()
{

}

double BondInstrument::getPrincipal()
{
  return m_principal;
}

double BondInstrument::getMonthlyPayment()
{
  return m_monthlyPayment;
}


MortgageInstrument::MortgageInstrument(double monthlyPay, double propertyValue, double downPayment)
: m_monthlyPay(monthlyPay), m_propertyValue(propertyValue), m_downPayment(downPayment)
{

}

MortgageInstrument::MortgageInstrument(const MortgageInstrument &v)
: m_monthlyPay(v.m_monthlyPay), m_propertyValue(v.m_propertyValue), m_downPayment(v.m_downPayment)
{

}

MortgageInstrument &MortgageInstrument::operator=(const MortgageInstrument &v)
{
  if (this != &v)
  {
    this->m_monthlyPay = v.m_monthlyPay;
    this->m_propertyValue = v.m_propertyValue;
    this->m_downPayment = v.m_downPayment;
  }

  return *this;
}

MortgageInstrument::~MortgageInstrument()
{

}

double MortgageInstrument::getPrincipal()
{
  return m_propertyValue - m_downPayment;
}

double MortgageInstrument::getMonthlyPayment()
{
  return m_monthlyPay;
}
