#include <Arduino.h>
#include "HighPass.h"

HighPass::HighPass(const TimeStep& dt, double tau, double yInitial) :
  m_integ(Integrator(dt, yInitial)), m_gain(1.0 / tau)
{
}

double HighPass::step(double u)
{
  m_y = u - m_gain * m_integ.step(m_y);
  return m_y;
}
