#ifndef _APRILTAGCORE_
#define _APRILTAGCORE_

#ifndef LIBMWREADAPRILTAG_API
#    define LIBMWREADAPRILTAG_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h" /* mwSize is defined here */
#else
#include "rtwtypes.h"
#endif

#include <stdint.h>

EXTERN_C LIBMWREADAPRILTAG_API 
        void initialiseOutput(void* id, void* locations, 
        void* familyLengths, void* familyNames, void* detectionObj,
        int detectionSize); 

EXTERN_C LIBMWREADAPRILTAG_API 
        void initialisePoses(void* rotMatrices, void* transVectors,
        void* detectionObj, void* posesObj, int posesSize);

EXTERN_C LIBMWREADAPRILTAG_API 
        int getAprilTagIdPoseDetections(void* imageData, void* inputTag, 
        boolean_T estimatePose, const float quadDecimate, const int32_t width, const int32_t height,
        void** detectionObj, int* familyLengths, const int numberTags, const int* tagLengths,
        double* focalLen, double* principalPoint, double tagSize, void** posesObj, int* detectionSize);
#endif