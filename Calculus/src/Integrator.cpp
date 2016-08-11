#include <Arduino.h>
#include "Integrator.h"
#include "TimeBase.h"

Integrator::Integrator(double yInitial) : 
  m_yValue(yInitial), m_cache(Cache(3))
{
}

double Integrator::step(double y)
{
  m_cache.update(y);
  double* yv = m_cache.getSamples();
  double& y0 = *yv;
  double& ym1 = *(yv + 1);
  double& ym2 = *(yv + 2);
  m_quad.solve(ym2, ym1, y0);
  m_yValue += m_quad.integ() * TimeBase::getTimeStep();
  return m_yValue;
}

