#ifndef _LOWPASS__H_
#define _LOWPASS__H_

#include "TimeStep.h"
#include "Integrator.h"

class LowPass
{
  private:
    Integrator m_integ;
    double m_gain;
    double m_y;
    
  public:
    LowPass(const TimeStep& dt, double tau, double yInitial = 0.0);
    double step(double u);
};

#endif

