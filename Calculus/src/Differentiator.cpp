#include <Arduino.h>
#include "Differentiator.h"
#include "TimeStep.h"

Differentiator::Differentiator(const TimeStep& dt) : m_dt(dt), m_cache(Cache(3))
{
}

double Differentiator::step(double y)
{
  double* yv = m_cache.step(y);
  double& y0 = *yv;
  double& ym1 = *(yv + 1);
  double& ym2 = *(yv + 2);
  m_quad.solve(ym2, ym1, y0);
  return m_quad.deriv() / m_dt.getTimeStep();
}
