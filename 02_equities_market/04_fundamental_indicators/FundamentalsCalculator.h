#ifndef __FinancialSamples_FundamentalsCalc__
#define __FinancialSamples_FundamentalsCalc__

#include <string>

class FundamentalsCalculator
{
public:
  FundamentalsCalculator(const std::string &ticker, double price, double dividend);
  FundamentalsCalculator(const FundamentalsCalculator &v);
  FundamentalsCalculator &operator=(const FundamentalsCalculator &v);
  ~FundamentalsCalculator();

  void setNumberOfShares(int n);
  void setEarnings(double val);
  void setExpectedEarnings(double val);
  void setBookValue(double val);
  void setAssets(double val);
  void setLiabilitiesAndIntangibles(double val);
  void setEpsGrowth(double val);
  void setNetIncome(double val);
  void setShareholdersEquity(double val);

  double PE();
  double forwardPE();
  double bookValue();
  double priceToBookRatio();
  double priceEarningsToGrowth();
  double returnOnEquity();
  double getDividend();

private:
  std::string m_ticker;
  double m_price;
  double m_dividend;
  int m_numberOfShares;
  double m_earnings;
  double m_expectedEarnings;
  double m_bookValue;
  double m_assets;
  double m_liabilitiesAndIntangibles;
  double m_epsGrowth;
  double m_netIncome;
  double m_shareholdersEquity;
};

#endif /* defined(__FinancialSamples_FundamentalsCalc__) */