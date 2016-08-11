#ifndef _PID__H_
#define _PID__H_

#include "Integrator.h"
#include "Differentiator.h"

class PID
{
  private:
    double m_p;
    double m_i;
    double m_d;
    bool m_useP;
    bool m_useI;
    bool m_useD;
    Integrator integ;
    Differentiator deriv;

  public:
    PID(double p, double i, double d);
    double step(double u);
};

#endif
