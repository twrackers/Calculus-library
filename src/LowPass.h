#ifndef _LOWPASS__H_
#define _LOWPASS__H_

#include "TimeStep.h"
#include "Integrator.h"

/**
 *  \headerfile LowPass.h
 *  \class LowPass
 *  \brief Arduino class to implement 1<sup>st</sup>-order low-pass filter.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.2.0
 *  
 *  This class performs a numerical first-order low-pass filtering of data
 *  points which are sampled at equal intervals in time.
 *  
 *  \note The TimeStep passed to the constructor has no connection to real time,
 *  so a calculation is not restricted to running according to the clock.  For
 *  example, an orbital dynamics simulation of a satellite could be performed
 *  at one-second intervals, but actually calculated much faster than that.  In
 *  real-time processing, however, the time step should be synchronized with the
 *  real-time sample rate.  Motion control of real hardware would be an example
 *  of this.
 *  
 *  \sa TimeStep
 */
class LowPass
{
  private:
    Integrator m_integ;   //!< Integrator object used in calculations
    double m_gain;        //!< Gain value, defined as 1 / tau
    double m_y;           //!< Most recent filtered value
    
  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor creates an instance of a LowPass object with
     *  a fixed time step used for its calculations.
     *  
     *  \param [in] dt Reference to TimeStep object
     *  \param [in] tau Time constant in seconds
     *  \param [in] yInitial Initial value (optional, default 0.0)
     */
    LowPass(const TimeStep& dt, double tau, double yInitial = 0.0);
    
    /**
     *  \brief Calculates the next filtered value.
     *  
     *  \details This method calculates the next filtered value based upon
     *  the current value and the preceding values, all defined to be equally spaced
     *  in time.
     *  
     *  \param [in] u New data sample in time series of data to be filtered
     *  \return Filter output
     */
    double step(double u);
};

#endif

