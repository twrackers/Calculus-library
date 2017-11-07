#ifndef _TIME_STEP__H_
#define _TIME_STEP__H_

class TimeStep
{
private:
  const double m_step;  // in seconds
  
public:
  TimeStep(const double step) : m_step(step)
  {
  }
  
  const double getTimeStep() const
  {
    return m_step;
  }
  
  const unsigned long getTimeMsec() const
  {
    return (unsigned long) (m_step * 1.0e3 + 0.5);
  }
  
  const unsigned long getTimeUsec() const
  {
    return (unsigned long) (m_step * 1.0e6 + 0.5);
  }
};

#endif