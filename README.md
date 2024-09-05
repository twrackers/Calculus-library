# Calculus #

The `Calculus` library provides basic calculus functions, including integral and derivative, for data values sampled periodically.  Because these are numerical methods for discrete data, the results are not exact but are fairly good approximations for most control applications.

## Overview ##

The classes in this library are intended to perform basic calculus-like functions when only values equally spaced in time are available, rather than a function defining the data points.  The typical use case is when the input values come from a sensor being sampled periodically.  A variation of Simpson's Rule is used for the integral, fitting a quadratic to each sample point and the two points before it.  Once the quadratic is solved, both the area between the two most recent points (integral), and the slope at the latest point (derivative), are calculated directly.

## Classes ##

This section briefly describes each of the classes in this library.

### TimeStep ###

The *TimeStep* class defines a time interval (in seconds) which is required by the following classes.

- *Differentiator*
- *Integrator*
- *LowPass* (uses *Integrator*)
- *PID* (uses *Integrator* and *Differentiator*)
- *RateLimiter*

A time step defined with the *TimeStep* class is *time in simulation-space*; it does not need to match real time.  You could set the simulation time step to 1 second, but use a *StateMachine* object to update the calculations at 0.1 second intervals, effectively running the simulation at 10 times its simulated speed.

However, if you *do* want to run the simulation in sync with real time, take a look at the `Calculus` sketch in the `examples` directory to see one way to do that.

### Cache ###

A *Cache* object maintains a history of the last *N* samples of an input variable, where *N* is specified when calling the constructor.  A *Cache* of size 3 is used internally by each *Differentiator* and *Integrator* object.  You can also use a *Cache* for other purposes, such as the basis for a running-average class.

### Differentiator ###

A *Differentiator* object approximates the time derivative of the input values presented to it.  A *TimeStep* must be created beforehand to set the sampling time interval.

### HighPass ###

A *HighPass* object performs a first-order high-pass filtering of the input values presented to it.  A *HighPass* object is constructed with a time constant, in the same units as the *TimeStep*.  A *TimeStep* must be created beforehand to set the sampling time interval.

### Integrator ###

An *Integrator* object approximates the time integral of the input values presented to it.  A *TimeStep* must be created beforehand to set the sampling time interval.

### LowPass ###

A *LowPass* object performs a first-order low-pass filtering of the input values presented to it.  A *LowPass* object is constructed with a time constant, in the same units as the *TimeStep*.  A *TimeStep* must be created beforehand to set the sampling time interval.

### PID ###

A *PID* object approximates a Proportional-Integral-Differential controller.  A *TimeStep* must be created beforehand to set the sampling time interval.

### Quadratic ###

A *Quadratic* object, when given three samples equally spaced in time, solves for the quadratic coefficients of a parabola which fits those samples.  From this the slope (derivative) at the latest point, and the area (integral) between the two latest points, can be retrieved.  This class is used internally by the *Differentiator* and *Integrator* classes.

### RateLimiter ###

A *RateLimiter* object echoes its input values to its output, with the restriction that the output's rate of change will be limited, rising and falling, to a rate specified when calling the constructor.  A *TimeStep* must be created beforehand to set the sampling time interval.

## Examples ##

The `examples` directory contains an example sketch, `Calculus`, which shows how some of the classes work with the *TimeStep* class.  This sketch requires the `Pulser` library ([https://github.com/twrackers/Pulser-library](https://github.com/twrackers/Pulser-library)) and the `StateMachine` library ([https://github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library)).

## Dependencies ##

The `Calculus` library has no dependencies on any other libraries.

## Installation ##

Instructions for installing the `Calculus` library can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/Calculus-library/blob/main/INSTALL.md](https://github.com/twrackers/Calculus-library/blob/main/INSTALL.md).
