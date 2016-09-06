#include "TimeBase.h"

namespace TimeBase
{
	static StateMachine* s_pUpdater = NULL;
	static double s_timeStep = 0.0;
	static unsigned long s_timeRef = 0;

	void setTimeStep(int msec)
	{
		if (s_pUpdater != NULL) {
			delete s_pUpdater;
		}
		s_pUpdater = new StateMachine(msec, true);
		s_timeStep = (double) msec / 1000.0;
		s_timeRef = millis();
	}
	
	void setTimeStep(double sec)
	{
		if (s_pUpdater != NULL) {
			delete s_pUpdater;
		}
		s_pUpdater = new StateMachine((int) (sec * 1000.0), true);
		s_timeStep = sec;
		s_timeRef = millis();
	}
	
	bool update()
	{
		return s_pUpdater->update();
	}
	
	double getTime()
	{
		return (double) (millis() - s_timeRef) / 1000.0;
	}
	
	double getTimeStep()
	{
		return s_timeStep;
	}
};
