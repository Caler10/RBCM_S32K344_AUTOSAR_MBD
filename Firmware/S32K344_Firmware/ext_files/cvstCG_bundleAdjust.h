#ifndef BUNDLEADJUST_
#define BUNDLEADJUST_

#ifndef LIBMWBUNDLEADJUST_API
#define LIBMWBUNDLEADJUST_API
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h" /* mwSize is defined here */
#else
#include "rtwtypes.h"
#endif

#include <stdint.h>

EXTERN_C LIBMWBUNDLEADJUST_API void visionbundleAdjust(const size_t, void*, void*, const size_t,
                                                     const size_t, void*, void*, const bool, 
                                                     const int*, const int*, const double, 
                                                     const double, const size_t, void*, 
                                                     const size_t, double*, double*, double*, 
                                                     void*, void*, const size_t, void*, void*, void*);
#endif