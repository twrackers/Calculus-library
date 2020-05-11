#ifndef _QUADRATIC__H_
#define _QUADRATIC__H_

/**
 *  \headerfile Quadratic.h
 *  \class Quadratic
 *  \brief Arduino class to fit a quadratic equation to three equally spaced points.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.1.0
 *  
 *  This class fits a parabola to three data values equally spaced in time.
 *  From this, the derivative at the latest point and the integral between
 *  the two latest points can be calculated.
 *  
 *  A Quadratic solves for the factors of a quadratic equation of the form
 *  
 *    y = A * x^2 + B * x + C
 *  
 *  given the three points (-2, ym2), (-1, ym1), and (0, y0).
 *  
 *  Once the equation is solved, the slope at (0, y0) and the integral from x = -1
 *  to x = 0 can be retrieved by the deriv() and integ() methods respectively.
 *  
 *  This class is used internally by the Differentiator and Integrator classes.
 */
class Quadratic
{
  private:
    double m_A = 0.0; //!< x^2 term (A in formula above)
    double m_B = 0.0; //!< x term (B in formula above)
    double m_C = 0.0; //!< const term (C in formula above)

  public:
    /**
     *  \brief Constructor.
     *  
     *  \details The constructor creates an instance of a Quadratic object.
     *  The object only holds values after three y-values are passed to solve().
     *  After solve() has been called, deriv() and integ() can be called to
     *  fetch the derivative and integral values.
     */
    Quadratic();
    
    /**
     *  \brief Solves a quadratic fit to 3 equally spaced data values.
     *  
     *  \details A Quadratic object, when given three samples equally spaced
     *  in time, solves for the quadratic coefficients of a parabola which fits
     *  those samples.  From this the slope (derivative) at the last point (y0),
     *  and the area (integral) between the last two points (ym1 and y0), can be
     *  retrieved.
     *  
     *  \param [in] ym2 Earliest data point
     *  \param [in] ym1 Middle data point
     *  \param [in] y0 Latest data point
     */
    void solve(double ym2, double ym1, double y0);
    
    /**
     *  \brief Gets the slope (derivative).
     *  
     *  \details This method returns the slope at the right end of the parabola
     *  which was calculated by the last call to solve().
     *  
     *  \return Slope (derivative)
     */
    double deriv();
    
    /**
     *  \brief Gets the area (integral)
     *  
     *  \details This method returns the area under the right half of the
     *  parabola which was calculated by the last call to solve().
     *  
     *  \return Area (integral)
     */
    double integ();
};

#endif

