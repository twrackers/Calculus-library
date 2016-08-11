#include <Arduino.h>
#include "TimeBase.h"

TimeBase::TimeBase() {}
TimeBase::TimeBase(const TimeBase&) {}
TimeBase& TimeBase::operator=(const TimeBase&) {}

double TimeBase::sm_timeStep = 0.0;
double TimeBase::sm_time = 0.0;

void TimeBase::setTimeStep(const double timeStep)
{
  sm_timeStep = timeStep;
}

