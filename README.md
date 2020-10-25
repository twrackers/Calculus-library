# Calculus #

This library provides basic calculus functions, including integral and derivative, for fixed-step sampled data.

## Overview ##

The classes in this library are intended to perform basic calculus-like functions when only values equally spaced in time are available, rather than a function defining the data points.  The typical use case is when the input values come from a sensor being sampled periodically.  A variation of Simpson's Rule is used for the integral, fitting a quadratic to each sample point and the two points before it.  Once the quadratic is solved, both the area between the two most recent points (integral), and the slope at the latest point (derivative), are calculated directly.

## Classes ##

This section briefly describes each of the classes in this library.

### TimeStep ###

The TimeStep class defines a time interval (in seconds) which is required by the following classes.

* Differentiator
* Integrator
* LowPass (uses Integrator)
* PID (uses Integrator and Differentiator)
* RateLimiter

### Cache ###

A Cache object maintains a history of the last *N* samples of an input variable, where *N* is specified when calling the constructor.  A Cache of size 3 is used internally by each Differentiator and Integrator object.  You can also use a Cache for other purposes, such as the basis for a running-average class.

### Differentiator ###

A Differentiator object approximates the time derivative of the input values presented to it.  A TimeStep must be created beforehand to set the sampling time interval.

### Integrator ###

An Integrator object approximates the time integral of the input values presented to it.  A TimeStep must be created beforehand to set the sampling time interval.

### LowPass ###

A LowPass object performs a first-order low-pass filtering of the input values presented to it.  A LowPass object is constructed with a time constant, in the same units as the TimeStep.  A TimeStep must be created beforehand to set the sampling time interval.

### PID ###

A PID object approximates a Proportional-Integral-Differential controller.  A TimeStep must be created beforehand to set the sampling time interval.

### Quadratic ###

A Quadratic object, when given three samples equally spaced in time, solves for the quadratic coefficients of a parabola which fits those samples.  From this the slope (derivative) at the latest point, and the area (integral) between the two latest points, can be retrieved.  This class is used internally by the Differentiator and Integrator classes.

### RateLimiter ###

A RateLimiter object echoes its input values to its output, with the restriction that the output's rate of change will be limited, rising and falling, to a rate specified when calling the constructor.  A TimeStep must be created beforehand to set the sampling time interval.

## Dependencies ##

The Calculus library has no dependencies on any other libraries.

## Installation ##

To install the Calculus library:

1. Find where your Arduino IDE stores libraries you install.  To do this, in the IDE click *File -> Preferences*.  The "Sketchbook location" tells you where the IDE looks for sketches.  For example, on a Windows system the sketchbook may be located at `C:\Arduino\sketches`.  In that case, your libraries should be found at `C:\Arduino\libraries`.
2. From the top page of this repository, [https://github.com/twrackers/Calculus-library](https://github.com/twrackers/Calculus-library), click the green `Code` button, then click `Download ZIP`.
3. Open the downloaded `.zip` file.  You will see a single directory named `Calculus-library-main`.  Do an `Extract all` into your `libraries` directory.
4. Rename the directory you just created to simply `Calculus`.
5. Restart the Arduino IDE.  You should now be able to include the Calculus classes in your codes.
