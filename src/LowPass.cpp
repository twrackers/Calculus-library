#include <Arduino.h>
#include "LowPass.h"

LowPass::LowPass(const TimeStep& dt, double tau, double yInitial) :
  m_integ(Integrator(dt, yInitial)), m_gain(1.0 / tau)
{
}

double LowPass::step(double u)
{
  m_y = m_integ.step(m_gain * (u - m_y));
  return m_y;
}

