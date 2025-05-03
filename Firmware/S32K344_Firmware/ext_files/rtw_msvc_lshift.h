#ifndef RTW_VS_LSHIFT_H
#define RTW_VS_LSHIFT_H

#ifdef SUPPORTS_PRAGMA_ONCE
 #pragma once
#endif

/*
 * Copyright 2013 The MathWorks, Inc.
 *
 * File: rtw_vs_lshift.h
 *
 * Abstract:
 * Left shifting a 64-bit variable/constant by more than 30 bits inside a loop 
 * generates wrong results in VS2005, VS2008 and VS2010 compilers, 
 * when O2 optimization is turned on. This issue is fixed in VS2012.  
 * LCC64 does not have the bug. 
 *  
 */

#include <stdio.h>
#if defined(__LCC__)
  #define INLINE inline
#elif defined(_WIN32)
  #define INLINE _inline
#else
  #define INLINE __inline__
#endif


INLINE long long VS_LShift_Signed64(long long Mask, unsigned int ShiftVal)
{
    volatile unsigned int Val = ShiftVal;
    return Mask << Val;
}

INLINE unsigned long long VS_LShift_Unsigned64(unsigned long long Mask, unsigned int ShiftVal)
{
    volatile unsigned int Val = ShiftVal;
    return Mask << Val;
}

INLINE int VS_LShift_Signed32(int Mask, unsigned int ShiftVal)
{
    volatile unsigned int Val = ShiftVal;
    return Mask << Val;
}

INLINE unsigned int VS_LShift_Unsigned32(unsigned int Mask, unsigned int ShiftVal)
{
    volatile unsigned int Val = ShiftVal;
    return Mask << Val;
}

#endif /* RTW_VS_LSHIFT_H */
