#ifndef _CACHE__H_
#define _CACHE__H_

#include <Arduino.h>

class Cache
{
  private:
    const byte m_NumSamples;
    double*    m_Samples;

  public:
    Cache(const byte numSamples, const double initValue = 0.0);
    virtual ~Cache();
    double* getSamples() const;
    const byte getNumSamples() const;
    double* step(double yVal);
};

#endif

