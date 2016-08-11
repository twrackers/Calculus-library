#ifndef _TIMEBASE__H_
#define _TIMEBASE__H_

#include <Arduino.h>

class TimeBase
{
  private:
    static double sm_timeStep;
    static double sm_time;
    
    TimeBase();
    TimeBase(const TimeBase&);
    TimeBase& operator=(const TimeBase&);

  public:
    static void setTimeStep(const double timeStep);
    inline static double getTimeStep()
    {
      return sm_timeStep;
    }
    inline static double getTime()
    {
      return sm_time;
    }
    inline static void update()
    {
      sm_time += sm_timeStep;
    }
};

#endif

