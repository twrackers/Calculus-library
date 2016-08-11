#ifndef _DIFFERENTIATOR__H_
#define _DIFFERENTIATOR__H_

#include "Quadratic.h"
#include "Cache.h"

class Differentiator
{
  private:
    Cache m_cache;
    Quadratic m_quad;
    
  public:
    Differentiator();
    double step(double y);
};

#endif

