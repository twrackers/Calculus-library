#include "RateLimiter.h"
#include "TimeStep.h"

RateLimiter::RateLimiter(const TimeStep& dt, double limit) :
  m_dt(dt), m_limit(limit), m_prev(0.0)
{
}

double RateLimiter::step(double u)
{
  const double dt = m_dt.getTimeStep();
  double rate = (u - m_prev) / dt;
  double y;
  if (rate > m_limit) {
    y = m_prev + m_limit * dt;
  } else if (rate < -m_limit) {
    y = m_prev - m_limit * dt;
  } else {
    y = u;
  }
  m_prev = y;
  return y;
}

