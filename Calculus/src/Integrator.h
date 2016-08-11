#ifndef _INTEGRATOR__H_
#define _INTEGRATOR__H_

#include "Quadratic.h"
#include "Cache.h"

class Integrator
{
  private:
    double m_yValue;
    Cache m_cache;
    Quadratic m_quad;
    
  public:
    Integrator(double yInitial = 0.0);
    double step(double y);
};

#endif

