/* Copyright 2018 The MathWorks, Inc. */

#ifndef _SEARCHORGANIZEDPOINTCLOUD_
#define _SEARCHORGANIZEDPOINTCLOUD_

#ifndef LIBMWSEARCHORGANIZEDPOINTCLOUD_API
#    define LIBMWSEARCHORGANIZEDPOINTCLOUD_API
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


// knn search for different classes (single/double)
EXTERN_C LIBMWSEARCHORGANIZEDPOINTCLOUD_API
        uint32_T searchOrganizedPointCloud_knnsearch_single(float* location,
        uint32_T height,
        uint32_T width,
        float *point,
        double kValue,
        float *pointProjection,
        float *KRKRT,
        void** resultIndices,
        void** resultDistances);
EXTERN_C LIBMWSEARCHORGANIZEDPOINTCLOUD_API
        uint32_T searchOrganizedPointCloud_knnsearch_double(double* location,
        uint32_T height,
        uint32_T width,
        double *point,
        double kValue,
        double *pointProjection,
        double *KRKRT,
        void** resultIndices,
        void** resultDistances);
// radius search for different classes (single/double)
EXTERN_C LIBMWSEARCHORGANIZEDPOINTCLOUD_API
        uint32_T searchOrganizedPointCloud_radiussearch_single(float* location,
        uint32_T height,
        uint32_T width,
        float *point,
        double kValue,
        float *pointProjection,
        float *KRKRT,
        void** resultIndices,
        void** resultDistances);
EXTERN_C LIBMWSEARCHORGANIZEDPOINTCLOUD_API
        uint32_T searchOrganizedPointCloud_radiussearch_double(double* location,
        uint32_T height,
        uint32_T width,
        double *point,
        double kValue,
        double *pointProjection,
        double *KRKRT,
        void** resultIndices,
        void** resultDistances);
// Assign outputs for different classes (single/double)
EXTERN_C LIBMWSEARCHORGANIZEDPOINTCLOUD_API
        void searchOrganizedPointCloudAssignOutputs_single(void* ptrIndices,
        void* ptrDists,
        uint32_T* indicesPtr,
        float* distancePtr);
EXTERN_C LIBMWSEARCHORGANIZEDPOINTCLOUD_API
        void searchOrganizedPointCloudAssignOutputs_double(void* ptrIndices,
        void* ptrDists,
        uint32_T* indicesPtr,
        double* distancePtr);


#endif
