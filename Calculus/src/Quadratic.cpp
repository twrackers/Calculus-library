#include <Arduino.h>
#include "Quadratic.h"

Quadratic::Quadratic() {}

void Quadratic::solve(double ym2, double ym1, double y0)
{
  m_A = (y0 + ym2) / 2.0 - ym1;
  m_B = (3.0 * y0 - 4.0 * ym1 + ym2) / 2.0;
  m_C = y0;
}

double Quadratic::deriv()
{
  return m_B;
}

double Quadratic::integ()
{
  return m_A / 3.0 - m_B / 2.0 + m_C;
}

