#include <Arduino.h>
#include "Cache.h"

Cache::Cache(const byte numSamples, const double initValue) : 
  m_NumSamples(numSamples), m_Samples(new double[numSamples])
{
  double* dp = m_Samples;
  for (byte i = 0; i < m_NumSamples; ++i) {
    *dp++ = initValue;
  }
}

Cache::~Cache()
{
  delete [] m_Samples;
}

double* Cache::getSamples() const
{
  return m_Samples;
}

const byte Cache::getNumSamples() const
{
  return m_NumSamples;
}

double* Cache::step(double yVal)
{
  // Point dp to last cached sample.
  double* dp = m_Samples + m_NumSamples - 1;
  // Point sp to second-last cached sample.
  double* sp = dp - 1;
  // Shift samples to back.
  // (No-op if m_NumSamples == 1.)
  for (byte i = 1; i < m_NumSamples; ++i) {
    *dp-- = *sp--;
  }
  // Cache current value.
  *dp = yVal;
  // Return cached values.
  return m_Samples;
}

