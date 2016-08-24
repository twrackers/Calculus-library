# Calculus-library
Arduino library to provide basic calculus functions, including integral and derivative, for fixed-step sampled data.

## Basics
The classes in this repository are intended to perform basic calculus-like functions when a function defining data points is not available, only equally-spaced samples from either sensor inputs or calculations.  To calculate the integral over time or the derivative with time, each sample point and the two points before it are fitted to a quadratic, yielding a parabola on which those points lie.  With that quadratic, the slope (derivative) at the current sample point (rightmost point on parabola) and the area between the current point and the point before (integral) are directly computed.  Accuracy of the derivative and the integral improve with higher sample rates, as long as this doesn't produce excessive noise in the data series.
