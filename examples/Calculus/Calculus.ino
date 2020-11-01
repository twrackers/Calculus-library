#include <math.h>

#include <Pulser.h>
#include <StateMachine.h>

#include "TimeStep.h"
#include "LowPass.h"
#include "RateLimiter.h"

const int sampleTime = 10;                        // msec
const double dt = (double) sampleTime / 1000.0;   // sec
//const double f = 2.0 / (2.0 * PI);                // Hz
//const double omega = 2.0 * PI * f;                // rad/sec
const double rateLimit = 5.0;                     // (y-units)/sec
const double tau = 1.0 / rateLimit;               // sec

Pulser pulser(1000, 2000);
TimeStep ts(dt);
LowPass lpf(ts, tau);
RateLimiter limiter(ts, rateLimit);
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
    double z = limiter.step(r);
    // Use 'Tools => Serial Plotter' to see the output.
    Serial.print(r);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z); 
  }
}

