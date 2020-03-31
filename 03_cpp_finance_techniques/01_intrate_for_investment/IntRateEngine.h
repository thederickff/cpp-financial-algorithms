#ifndef __FinancialSamples_IntRateEngine__
#define __FinancialSamples_IntRateEngine__

template<class T>
class IntRateEngine
{
public:
  IntRateEngine();
  IntRateEngine(const IntRateEngine<T> &v);
  IntRateEngine<T> &operator=(const IntRateEngine<T> &v);
  ~IntRateEngine();

  void setInstrument(T &v);
  double getAnnualIntRate();

private:
  T m_instrument;
};

template<class T>
IntRateEngine<T>::IntRateEngine()
{

}

template<class T>
IntRateEngine<T>::IntRateEngine(const IntRateEngine<T> &v)
: m_instrument(v.m_instrument)
{

}

template<class T>
IntRateEngine<T> &IntRateEngine<T>::operator=(const IntRateEngine<T> &v)
{
  if (this != &v)
  {
    this->m_instrument = v.m_instrument;
  }

  return *this;
}

template<class T>
IntRateEngine<T>::~IntRateEngine()
{

}

template<class T>
void IntRateEngine<T>::setInstrument(T &v)
{
  m_instrument = v;
}

template<class T>
double IntRateEngine<T>::getAnnualIntRate()
{
  double payment = m_instrument.getMonthlyPayment();
  double principal = m_instrument.getPrincipal();

  return (payment * 12) / principal;
}

#endif /* defined(__FinancialSamples_IntRateEngine__) */