#ifndef _INTEGRATOR__H_
#define _INTEGRATOR__H_

#include "TimeStep.h"
#include "Quadratic.h"
#include "Cache.h"

class Integrator
{
  private:
    const TimeStep& m_dt;
    double m_yValue;
    Cache m_cache;
    Quadratic m_quad;
    
  public:
    Integrator(const TimeStep& dt, double yInitial = 0.0);
    double step(double y);
    void reset();
};

#endif

