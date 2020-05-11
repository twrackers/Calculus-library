#ifndef _PID__H_
#define _PID__H_

#include "TimeStep.h"
#include "Integrator.h"
#include "Differentiator.h"

/**
 *  \headerfile PID.h
 *  \class PID
 *  \brief Arduino class to implement a PID controller from fixed-interval data points.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.1.0
 *  
 *  This class performs a numerical approximation to a PID (proportional-integral-derivative)
 *  controller, using data points sampled at equal time intervals.
 *  
 *  For more information on PID controllers, see
 *  <a href="https://en.wikipedia.org/wiki/PID_controller">
 *  en.wikipedia.org/wiki/PID_controller</a>.
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
 *  \sa Differentiator
 *  \sa TimeStep
 */
class PID
{
  private:
    double m_p;             //!< Gain factor for proportional term
    double m_i;             //!< Gain factor for integral term
    double m_d;             //!< Gain factor for derivative term
    bool m_useP;            //!< *true* if proportional term used (gain non-zero)
    bool m_useI;            //!< *true* if integral term used (gain non-zero)
    bool m_useD;            //!< *true* if derivative term used (gain non-zero)
    Integrator m_integ;     //!< Integrator object
    Differentiator m_deriv; //!< Differentiator object

  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor creates an instance of a PID controller object with
     *  a fixed time step used for its calculations.
     *  
     *  Any (but not all) of the gain factors can be set to zero.  To improve
     *  performance, only terms with non-zero gains will be calculated and summed.
     *  
     *  \param [in] dt Reference to TimeStep object
     *  \param [in] p Gain factor for proportional term
     *  \param [in] i Gain factor for integral term
     *  \param [in] d Gain factor for derivative term
     */
    PID(const TimeStep& dt, double p, double i, double d);
    
    /**
     *  \brief Calculates the controller output for the next time step.
     *  
     *  \details The PID controller output is calculated by passing to it a series of
     *  data samples, defined to be equally spaced in time.
     *  
     *  \param [in] u New data sample in time series
     *  \return Calculated controller output
     */
    double step(double u);
};

#endif
