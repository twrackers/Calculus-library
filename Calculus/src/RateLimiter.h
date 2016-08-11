#ifndef _RATE_LIMITER__H_
#define _RATE_LIMITER__H_

class RateLimiter
{
  private:
    double m_limit;
    double m_prev;
    
  public:
    RateLimiter(double limit);
    double eval(double u);
};

#endif

