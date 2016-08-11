#include "RateLimiter.h"
#include "TimeBase.h"

RateLimiter::RateLimiter(double limit) :
  m_limit(limit), m_prev(0.0)
{
}

double RateLimiter::eval(double u)
{
  double dt = TimeBase::getTimeStep();
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

