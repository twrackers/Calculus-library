#include <Arduino.h>
#include "PID.h"

PID::PID(const TimeStep& dt, double p, double i, double d) :
  m_p(p), m_i(i), m_d(d), 
  m_useP(p != 0.0), 
  m_useI(i != 0.0), 
  m_useD(d != 0.0),
  m_integ(dt),
  m_deriv(dt)
{
}

double PID::step(double u)
{
  double result = 0.0;
  if (m_useP) {
    result += m_p * u;
  }
  if (m_useI) {
    result += m_i * m_integ.step(u);
  }
  if (m_useD) {
    result += m_d * m_deriv.step(u);
  }
  return result;
}

