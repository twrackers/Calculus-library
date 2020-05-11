#ifndef _INTEGRATOR__H_
#define _INTEGRATOR__H_

#include "TimeStep.h"
#include "Quadratic.h"
#include "Cache.h"

/**
 *  \headerfile Integrator.h
 *  \class Integrator
 *  \brief Arduino class to calculate integral from fixed-interval data points.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.1.1
 *  
 *  This class performs a numerical integration from data points which are sampled
 *  at equal intervals in time.  An Integrator object caches the 3 most recent data
 *  values passed to it, fits a quadratic to them, and returns the calculated area
 *  between the current point and the preceding one.
 *  
 *  \note The TimeStep passed to the constructor has no connection to real time,
 *  so a calculation is not restricted to running according to the clock.  For
 *  example, an orbital dynamics simulation of a satellite could be performed
 *  at one-second intervals, but actually calculated much faster than that.  In
 *  real-time processing, however, the time step should be synchronized with the
 *  real-time sample rate.  Motion control of real hardware would be an example
 *  of this.
 *  
 *  \sa Differentiator
 *  \sa TimeStep
 */

class Integrator
{
  private:
    const TimeStep& m_dt;   //!< reference to TimeStep object
    double m_yValue;        //!< current integrated value (area under curve)
    Cache m_cache;          //!< Cache object, holds 3 most recent samples
    Quadratic m_quad;       //!< Quadratic object to fit cached samples
    
  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor creates an instance of an Integrator object with
     *  a fixed time step used for its calculations.
     *  
     *  \param [in] dt Reference to TimeStep object
     *  \param [in] yInitial Initial value for calculated integral (optional, default 0.0)
     */
    Integrator(const TimeStep& dt, double yInitial = 0.0);
    
    /**
     *  \brief Calculates the integral for the next time step.
     *  
     *  \details The integral is calculated by passing to it a series
     *  of data samples, defined to be equally spaced in time.  Each time
     *  a new sample is passed to this method, that sample and the two most
     *  recent samples are used to calculate the area under the curve (integral)
     *  between the two most recent points.
     *  
     *  \param [in] y New data sample in time series
     *  \return Calculated integral
     */
    double step(double y);
    
    /**
     *  \brief Resets the Integrator.
     *  
     *  \details This method clears the internal cache of data samples and resets the
     *  current integral value to zero.
     */
    void reset();
};

#endif

