/* Copyright 2012 The MathWorks, Inc. */

#ifndef _COMPUTEMETRIC_
#define _COMPUTEMETRIC_

#ifndef LIBMWCOMPUTEMETRIC_API
#    define LIBMWCOMPUTEMETRIC_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

/* SSD */
EXTERN_C LIBMWCOMPUTEMETRIC_API void ComputeMetric_ssd_double(real_T *f1, real_T *f2, real_T * scores,
			    uint32_T numFeatures1, uint32_T numFeatures2, uint32_T featureLength);
EXTERN_C LIBMWCOMPUTEMETRIC_API void ComputeMetric_ssd_single(real32_T *f1, real32_T *f2, real32_T * scores,
			    uint32_T numFeatures1, uint32_T numFeatures2, uint32_T featureLength);
/* SAD */
EXTERN_C LIBMWCOMPUTEMETRIC_API void ComputeMetric_sad_double(real_T *f1, real_T *f2, real_T * scores,
			    uint32_T numFeatures1, uint32_T numFeatures2, uint32_T featureLength);
EXTERN_C LIBMWCOMPUTEMETRIC_API void ComputeMetric_sad_single(real32_T *f1, real32_T *f2, real32_T * scores,
			    uint32_T numFeatures1, uint32_T numFeatures2, uint32_T featureLength);
/* HAMMING */
EXTERN_C LIBMWCOMPUTEMETRIC_API void ComputeMetric_hamming_single(uint8_T *f1, uint8_T *f2, real32_T * scores,
			    uint32_T numFeatures1, uint32_T numFeatures2, uint32_T featureLength);

#endif
