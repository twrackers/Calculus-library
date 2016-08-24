# Calculus-library
Arduino library to provide basic calculus functions, including integral and derivative, for fixed-step sampled data.

## Basics
The classes in this repository are intended to perform basic calculus-like functions when a function defining data points is not available, only equally-spaced samples from either sensor inputs or calculations.  A variation of Simpson's Rule is used for the integral, fitting a quadratic to each sample point and the two points before it.  Once the quadratic is solved, both the area between the current and previous pair of points (integral), and the slope at the current point (derivative), are calculated directly.

## Classes
This section describes all the classes, listed in alphabetical order.  You will probably be most interested in:
- Differentiator
- Integrator
- RateLimiter
- TimeBase

### Cache
A Cache object maintains a history of the last N samples of an input variable, where N is specified when calling the constructor.  A Cache of 3 is used internally by each Differentiator or Integrator object.  You could also use a Cache as the basis for a running-average class.

### Differentiator
A Differentiator object approximates the time derivative of the input values presented to it.  A TimeBase must be created beforehand to set the sampling time interval.

### Integrator
An Integrator object approximates the time integral of the input values presented to it.  A TimeBase must be created beforehand to set the sampling time interval.

### LowPass
A LowPass object performs a first-order low-pass filtering of the input values presented to it.  A LowPass object is constructed with a time constant, in the same units as the TimeBase.

### PID
A PID object approximates a Proportional-Integral-Differential controller.

### Quadratic
A Quadratic object, when given three samples equally spaced in time, solves for the quadratic coefficients of a parabola which fits those samples.  From this the slope (derivative) at the latest point, and the area (integral) between the two latest points, can be retrieved.  This class is used internally by the Differentiator and Integrator classes.

### RateLimiter
A RateLimiter object echoes its input values to its output, with the restriction that the output's rate of change will be limited, rising and falling, to a rate specified when calling the constructor.

### TimeBase
The TimeBase class has all static (class-scope) methods and private constructors, so it's effectively a "singleton" where only one instance can exist.  This has the benefit of making the single TimeBase object accessible to all other objects which require it.  Classes which depend on the TimeBase are:
- Differentiator
- Integrator
- RateLimiter
