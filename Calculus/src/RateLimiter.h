#ifndef _RATE_LIMITER__H_
#define _RATE_LIMITER__H_

#include "TimeStep.h"

class RateLimiter
{
  private:
    const TimeStep& m_dt;
    double m_limit;
    double m_prev;
    
  public:
    RateLimiter(const TimeStep& dt, double limit);
    double step(double u);
};

#endif

