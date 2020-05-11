#ifndef _DIFFERENTIATOR__H_
#define _DIFFERENTIATOR__H_

#include "TimeStep.h"
#include "Quadratic.h"
#include "Cache.h"

/** \headerfile Differentiator.h
 *  \class Differentiator
 *  \brief Arduino class to calculate derivative from fixed-interval data points.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.1.0
 *  
 *  This class performs a numerical derivative from data points which are sampled
 *  at equal intervals in time.  A Derivative object caches the 3 most recent data
 *  values passed to it, fits a quadratic to them, and returns the calculated
 *  slope at the most recent point.
 *  
 *  \note The TimeStep passed to the constructor has no connection to real time,
 *  so a calculation is not restricted to running according to the clock.  For
 *  example, an orbital dynamics simulation of a satellite could be performed
 *  at one-second intervals, but actually calculated much faster than that.  In
 *  real-time processing, however, the time step should be synchronized with the
 *  real-time sample rate.  Motion control of real hardware would be an example
 *  of this.
 *  
 *  \sa Integrator
 *  \sa TimeStep
 */
class Differentiator
{
  private:
    const TimeStep& m_dt;   //!< Reference to TimeStep object
    Cache m_cache;          //!< Cache object, holds 3 most recent samples
    Quadratic m_quad;       //!< Quadratic object to fit cached samples
    
  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor creates an instance of a Differentiator object with
     *  a fixed time step used for its calculations.
     *  
     *  \param [in] dt Reference to TimeStep object
     */
    Differentiator(const TimeStep& dt);
    
    /**
     *  \brief Calculates the derivative for the next time step.
     *  
     *  \details The derivative is calculated by passing to it a series
     *  of data samples, defined to be equally spaced in time.  Each time
     *  a new sample is passed to this method, that sample and the two most
     *  recent samples are used to calculate the slope (derivative) at
     *  this point.
     *  
     *  \param [in] y New data sample in time series
     *  \return Calculated derivative
     */
    double step(double y);
};

#endif

