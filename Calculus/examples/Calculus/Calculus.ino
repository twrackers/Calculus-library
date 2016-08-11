#include <StateMachine.h>
#include <Streaming.h>
#include <math.h>
#include "TimeBase.h"
#include "LowPass.h"
#include "RateLimiter.h"

const int sampleTime = 10;                        // msec
const double dt = (double) sampleTime / 1000.0;   // sec
const double f = 2.0 / (2.0 * PI);                // Hz
const double omega = 2.0 * PI * f;                // rad/sec
const double tau = 1.0;

//LowPass lpf(tau);
RateLimiter limiter(3.0);
StateMachine updater(sampleTime, true);

void setup() 
{
  TimeBase::setTimeStep(dt);
  Serial.begin(115200);
}

void loop()
{
  if (updater.update()) {
    TimeBase::update();
    double r = ((int) TimeBase::getTime() % 4) < 2 ? 0.0 : 1.0;
//      double r = 2.0 * sin(omega * TimeBase::getTime());
//    double y = lpf.step(r);
    double y = limiter.eval(r);
    Serial << r << " " << y << endl; 
  }
}
