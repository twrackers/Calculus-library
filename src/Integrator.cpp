#include <Arduino.h>
#include "Integrator.h"

Integrator::Integrator(const TimeStep& dt, double yInitial) : 
  m_dt(dt), m_yInit(yInitial), m_yValue(yInitial), m_cache(Cache(3))
{
}

double Integrator::step(double y)
{
  double* yv = m_cache.step(y);
  double& y0 = *yv;
  double& ym1 = *(yv + 1);
  double& ym2 = *(yv + 2);
  m_quad.solve(ym2, ym1, y0);
  m_yValue += m_quad.integ() * m_dt.getTimeStep();
  return m_yValue;
}

void Integrator::reset()
{
  m_yValue = m_yInit;
  for (byte i = 0; i < m_cache.getNumSamples(); ++i) {
    m_cache.step(m_yInit);
  }
}
