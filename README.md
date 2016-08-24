# Calculus-library
Arduino library to provide basic calculus functions, including integral and derivative, for fixed-step sampled data.

## Basics
The classes in this repository are intended to perform basic calculus-like functions when a function defining data points is not available, only equally-spaced samples from either sensor inputs or calculations.  A variation of Simpson's Rule is used for the integral, fitting a quadratic to each sample point and the two points before it.  Once the quadratic is solved, both the area between the current and previous pair of points (integral), and the slope at the current point (derivative), are calculated directly.

## Classes
### Cache
### Differentiator
### Integrator
### LowPass
### PID
### Quadratic
### RateLimiter
### TimeBase
