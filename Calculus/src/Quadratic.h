#ifndef _QUADRATIC__H_
#define _QUADRATIC__H_

/*
 * This class solves for the factors of a quadratic equation
 * of the form
 *    y = A * x^2 + B * x + C
 * given the three points
 *    (-2, ym2) (-1, ym1) (0, y0)
 * Once the equation is solved, you can retrieve the slope at
 * (0, y0) and the integral from x = -1 to x = 0.
 */

class Quadratic
{
  private:
    double m_A = 0.0; // x^2 term
    double m_B = 0.0; // x term
    double m_C = 0.0; // const term

  public:
    Quadratic();
    void solve(double ym2, double ym1, double y0);
    double deriv();
    double integ();
};

#endif

