#ifndef _DIFFERENTIATOR__H_
#define _DIFFERENTIATOR__H_

#include "TimeStep.h"
#include "Quadratic.h"
#include "Cache.h"

class Differentiator
{
  private:
    const TimeStep& m_dt;
    Cache m_cache;
    Quadratic m_quad;
    
  public:
    Differentiator(const TimeStep& dt);
    double step(double y);
};

#endif

