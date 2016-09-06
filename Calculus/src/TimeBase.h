#ifndef _TIMEBASE__H_
#define _TIMEBASE__H_

#include <Arduino.h>
#include <StateMachine.h>

namespace TimeBase
{
	void setTimeStep(int);
	void setTimeStep(double);
	bool update();
	double getTime();
	double getTimeStep();
};

#endif

