#ifndef _RATE_LIMITER__H_
#define _RATE_LIMITER__H_

#include "TimeStep.h"

/**
 *  \headerfile RateLimiter.h
 *  \class RateLimiter
 *  \brief Arduino class to implement a rate-limiter function on a time series of data.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.1.0
 *  
 *  This class performs a rate-limiting function on fixed-rate data values.
 *  
 *  A rate limiter outputs the same value that is input to it, *as long as the absolute
 *  value of the rate of change of the input value does not exceed a preset limit*.
 *  If the input value's rate of change exceeds the limit, either positive or negative,
 *  the output value will change in the direction that follows the input, but only at
 *  the preset rate.
 *  
 *  In electronics, the term *slew rate* is used to define the change in some signal
 *  per unit of time.  So the action of a RateLimiter object mimics that of slew
 *  rate limiting in a circuit.  More information on this can be found at
 *  <a href="https://en.wikipedia.org/wiki/Slew_rate">
 *  en.wikipedia.org/wiki/Slew_rate</a>.
 */
class RateLimiter
{
  private:
    const TimeStep& m_dt;   //!< reference to TimeStep object
    double m_limit;         //!< maximum allowed change of output per time step
    double m_prev;          //!< previous output value
    
  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor creates an instance of a RateLimiter object
     *  with a fixed time step used for its calculations.
     *  
     *  \param [in] dt Reference to TimeStep object
     *  \param [in] limit Maximum change in output per time step
     *  \return Rate-limited output
     */
    RateLimiter(const TimeStep& dt, double limit);
    
    /**
     *  \brief Calculates rate-limited form of input time series.
     *  
     *  \param [in] u Input data value
     *  \return Rate-limited output data value
     */
    double step(double u);
};

#endif

