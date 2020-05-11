#ifndef _CACHE__H_
#define _CACHE__H_

#include <Arduino.h>

/** \headerfile Cache.h
 *  \class Cache
 *  \brief Arduino class to cache a fixed number of values in order.
 *  \author Thomas W. Rackers, Ph.D.
 *  \version 1.1.0
 *
 *  This class allows an Arduino sketch to preserve the last *N* values of
 *  some variable, where *N* is specified by the constructor.  All samples are 
 *  accessible to the calling routine at any time.  This class can be used to
 *  implement algorithms such as computing a running average or performing
 *  filtering of a data source.
 */
class Cache
{
  private:
    const byte m_NumSamples;  //!< number of values to be cached
    double*    m_Samples;     //!< pointer to array of cached values

  public:
    /**
     *  \brief Constructor.
     *  
     *  The constructor creates an instance of a Cache object of fixed size.
     *  An initial value to fill the Cache samples can also be specified.
     *  
     *  The constructor allocates an array of *double* values to 
     *  hold the cached samples.  Because Arduino code never deallocates
     *  memory that has been allocated at runtime, there is no destructor 
     *  defined.
     *  
     *  \param [in] numSamples Number of samples to be cached
     *  \param [in] initValue Initial value to be stored in samples (default 0.0)
     */
    Cache(const byte numSamples, const double initValue = 0.0);
    
    /**
     *  \brief Gets the address of the array of stored data values.
     *  
     *  \return Pointer to data array
     */
    double* getSamples() const;
    
    /**
     *  \brief Gets the size of the stored data array.
     *  
     *  This method returns the number of data values that the Cache object 
     *  can hold.
     *  
     *  \return Number of values in data array
     */
    const byte getNumSamples() const;
    
    /**
     *  \brief Adds a new value to the cache.
     *  
     *  This method adds a new value to the cache object, which causes the
     *  oldest value to be discarded.
     *  
     *  \param [in] yVal New data value being cached
     *  \return Pointer to data array (same as returned by getSamples())
     */
    double* step(double yVal);
};

#endif

