#ifndef _TIME_STEP__H_
#define _TIME_STEP__H_

#include <math.h>

/**
 *  \headerfile TimeStep.h
 *  \class TimeStep
 *  \brief Arduino class defining time interval, used by classes in Calculus library.
 *  \author Thomas W Rackers, Ph.D.
 *  \version 1.1.0
 *  
 *  This class defines a time interval which is required in several of the classes
 *  of the Calculus library.  The time interval is given in seconds, but is not
 *  necessarily connected to real clock time.  This allows calculations to be run
 *  faster or slower than time in the simulation.
 *  
 *  \sa Differentiator
 *  \sa Integrator
 *  \sa LowPass
 *  \sa PID
 *  \sa RateLimiter
 */
class TimeStep
{
  private:
    const double m_step;  //!< time step in seconds
    
  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor defines a time step object, which is required
     *  by several of the other classes in the Calculus library.
     *  
     *  \param [in] step Time step in seconds
     */
    TimeStep(const double step) : m_step(step)
    {
    }
    
    /**
     *  \brief Gets time step in seconds.
     *  
     *  \return Time step in seconds
     */
    const double getTimeStep() const
    {
      return m_step;
    }
    
    /**
     *  \brief Gets time step in milliseconds.
     *  
     *  \return Time step in milliseconds
     */
    const unsigned long getTimeMsec() const
    {
      return (unsigned long) round(m_step * 1.0e3);
    }
    
    /**
     *  \brief Gets time step in microseconds.
     *  
     *  \return Time step in microseconds
     */
    const unsigned long getTimeUsec() const
    {
      return (unsigned long) round(m_step * 1.0e6);
    }
};

#endif
