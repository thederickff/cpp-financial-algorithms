#ifndef __FinancialSamples_InvestmentInstrument__
#define __FinancialSamples_InvestmentInstrument__

class BondInstrument
{
public:
  BondInstrument() {}
  BondInstrument(double principal, double monthlyPayment);
  BondInstrument(const BondInstrument &v);
  BondInstrument &operator=(const BondInstrument &v);
  ~BondInstrument();

  double getPrincipal();
  double getMonthlyPayment();
  
private:
  double m_principal;
  double m_monthlyPayment;
};

class MortgageInstrument
{
public:
  MortgageInstrument() {}
  MortgageInstrument(double monthlyPay, double propertyValue, double downPayment);
  MortgageInstrument(const MortgageInstrument &v);
  MortgageInstrument &operator=(const MortgageInstrument &v);
  ~MortgageInstrument();

  double getPrincipal();
  double getMonthlyPayment();
  
private:
  double m_monthlyPay;
  double m_propertyValue;
  double m_downPayment;
};

#endif /* defined(__FinancialSamples_InvestmentInstrument__) */