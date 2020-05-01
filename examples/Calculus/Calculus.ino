#include <StateMachine.h>
#include <Streaming.h>
#include <math.h>
#include "TimeStep.h"
#include "Pulser.h"
#include "LowPass.h"
#include "RateLimiter.h"

const int sampleTime = 10;                        // msec
const double dt = (double) sampleTime / 1000.0;   // sec
const double f = 2.0 / (2.0 * PI);                // Hz
const double omega = 2.0 * PI * f;                // rad/sec
const double tau = 0.25;

Pulser pulser(1000, 2000);
TimeStep ts(dt);
LowPass lpf(ts, tau);
RateLimiter limiter(ts, 3.0);
StateMachine updater(sampleTime, true);

void setup() 
{
  Serial.begin(115200);
}

void loop()
{
  if (updater.update()) {
    pulser.update();
    double r = pulser.read() ? 1.0 : 0.0;
    double y = lpf.step(r);
//    double y = limiter.step(r);
    Serial << r << " " << y << endl; 
  }
}
