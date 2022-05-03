//#include <math.h>

#include <Pulser.h>
#include <StateMachine.h>

#include <TimeStep.h>
#include <LowPass.h>
#include <RateLimiter.h>

const int sampleTime = 10;                        // msec
const double dt = (double) sampleTime / 1000.0;   // sec
//const double f = 2.0 / (2.0 * PI);                // Hz
//const double omega = 2.0 * PI * f;                // rad/sec
const double rateLimit = 3.0;                     // (y-units)/sec
const double tau = 0.4 / rateLimit;               // sec

// 'pulser' will return true for 1 sec, false for 2 sec.
Pulser pulser(1000, 2000);
// 'updater' sets pace of output.
StateMachine updater(sampleTime, true);

// Define time step for LowPass and RateLimiter objects.
TimeStep ts(dt);
// Low-pass filter object
LowPass lpf(ts, tau);
// Rate-limiter object
RateLimiter limiter(ts, rateLimit);

void setup() 
{
  // Start Serial output, setting baud rate.
  // This must match setting in Serial Monitor
  // or Serial Plotter (both under Tools menu).
  Serial.begin(115200);
}

void loop()
{
  // Update the pulser object which generates the
  // input signal.
  pulser.update();
  // Time to iterate and output?
  if (updater.update()) {
    // Input to following steps, toggles between 0 and 1.
    double r = pulser.read() ? 1.0 : 0.0;
    // Do a low-pass filter on the input.
    double y = lpf.step(r);
    // Do a rate-limiter on the input.
    double z = limiter.step(r);
    // Print the results.
    // Use 'Tools => Serial Plotter' or
    // 'Tools => Serial Plotter' to see the output.
    Serial.print(r);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z); 
  }
}
