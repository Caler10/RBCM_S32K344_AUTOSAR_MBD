/* Copyright 2018-2019 The MathWorks, Inc. */
#ifndef _KDTREE_
#define _KDTREE_

#ifndef LIBMWKDTREE_API
#define LIBMWKDTREE_API
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


EXTERN_C LIBMWKDTREE_API void kdtreeConstruct_single(void** ptr2ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeConstruct_double(void** ptr2ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeConstructRM_single(void** ptr2ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeConstructRM_double(void** ptr2ptrObj);

EXTERN_C LIBMWKDTREE_API boolean_T kdtreeNeedsReindex_single(void* ptrObj, void* pData);

EXTERN_C LIBMWKDTREE_API boolean_T kdtreeNeedsReindex_double(void* ptrObj, void* pData);

EXTERN_C LIBMWKDTREE_API boolean_T kdtreeNeedsReindexRM_single(void* ptrObj, void* pData);

EXTERN_C LIBMWKDTREE_API boolean_T kdtreeNeedsReindexRM_double(void* ptrObj, void* pData);

EXTERN_C LIBMWKDTREE_API void kdtreeIndex_single(void* ptrObj,
                                                 void* pData,
                                                 uint32_T dataSize,
                                                 uint32_T dims,
                                                 double numTrees,
                                                 double bucketSize,
                                                 double seed);

EXTERN_C LIBMWKDTREE_API void kdtreeIndex_double(void* ptrObj,
                                                 void* pData,
                                                 uint32_T dataSize,
                                                 uint32_T dims,
                                                 double numTrees,
                                                 double bucketSize,
                                                 double seed);

EXTERN_C LIBMWKDTREE_API void kdtreeIndexRM_single(void* ptrObj,
                                                   void* pData,
                                                   uint32_T dataSize,
                                                   uint32_T dims,
                                                   double numTrees,
                                                   double bucketSize,
                                                   double seed);

EXTERN_C LIBMWKDTREE_API void kdtreeIndexRM_double(void* ptrObj,
                                                   void* pData,
                                                   uint32_T dataSize,
                                                   uint32_T dims,
                                                   double numTrees,
                                                   double bucketSize,
                                                   double seed);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeBoxSearch_single(void* ptrObj,
                                                        void* roi,
                                                        void** resultIndices);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeBoxSearch_double(void* ptrObj,
                                                        void* roi,
                                                        void** resultIndices);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeBoxSearchRM_single(void* ptrObj,
                                                          void* roi,
                                                          void** resultIndices);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeBoxSearchRM_double(void* ptrObj,
                                                          void* roi,
                                                          void** resultIndices);

EXTERN_C LIBMWKDTREE_API void kdtreeBoxSearchSetOutputs(void* ptrIndices, uint32_T* location);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeKNNSearch_single(void* ptrObj,
                                                        void* queryData,
                                                        uint32_T numQueries,
                                                        uint32_T numQueryDims,
                                                        uint32_T knn,
                                                        double paramChecks,
                                                        float paramEps,
                                                        void* indices,
                                                        void* dists,
                                                        void* valid,
                                                        int32_T grainSize,
                                                        uint32_T tbbQueryThreshold);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeKNNSearch_double(void* ptrObj,
                                                        void* queryData,
                                                        uint32_T numQueries,
                                                        uint32_T numQueryDims,
                                                        uint32_T knn,
                                                        double paramChecks,
                                                        double paramEps,
                                                        void* indices,
                                                        void* dists,
                                                        void* valid,
                                                        int32_T grainSize,
                                                        uint32_T tbbQueryThreshold);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeKNNSearchRM_single(void* ptrObj,
                                                          void* queryData,
                                                          uint32_T numQueries,
                                                          uint32_T numQueryDims,
                                                          uint32_T knn,
                                                          double paramChecks,
                                                          float paramEps,
                                                          void* indices,
                                                          void* dists,
                                                          void* valid,
                                                          int32_T grainSize,
                                                          uint32_T tbbQueryThreshold);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeKNNSearchRM_double(void* ptrObj,
                                                          void* queryData,
                                                          uint32_T numQueries,
                                                          uint32_T numQueryDims,
                                                          uint32_T knn,
                                                          double paramChecks,
                                                          double paramEps,
                                                          void* indices,
                                                          void* dists,
                                                          void* valid,
                                                          int32_T grainSize,
                                                          uint32_T tbbQueryThresholds);


EXTERN_C LIBMWKDTREE_API int32_T kdtreeRadiusSearch_single(void* ptrObj,
                                                           void* queryData,
                                                           uint32_T numQueries,
                                                           uint32_T numQueryDims,
                                                           float radius,
                                                           double paramChecks,
                                                           float paramEps,
                                                           void** resultIndices,
                                                           void** resultDists,
                                                           uint32_T* valid,
                                                           int32_T grainSize,
                                                           uint32_T tbbQueryThresholds);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeRadiusSearch_double(void* ptrObj,
                                                           void* queryData,
                                                           uint32_T numQueries,
                                                           uint32_T numQueryDims,
                                                           double radius,
                                                           double paramChecks,
                                                           double paramEps,
                                                           void** resultIndices,
                                                           void** resultDists,
                                                           uint32_T* valid,
                                                           int32_T grainSize,
                                                           uint32_T tbbQueryThresholds);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeRadiusSearchRM_single(void* ptrObj,
                                                             void* queryData,
                                                             uint32_T numQueries,
                                                             uint32_T numQueryDims,
                                                             float radius,
                                                             double paramChecks,
                                                             float paramEps,
                                                             void** resultIndices,
                                                             void** resultDists,
                                                             uint32_T* valid,
                                                             int32_T grainSize,
                                                             uint32_T tbbQueryThresholds);

EXTERN_C LIBMWKDTREE_API int32_T kdtreeRadiusSearchRM_double(void* ptrObj,
                                                             void* queryData,
                                                             uint32_T numQueries,
                                                             uint32_T numQueryDims,
                                                             double radius,
                                                             double paramChecks,
                                                             double paramEps,
                                                             void** resultIndices,
                                                             void** resultDists,
                                                             uint32_T* valid,
                                                             int32_T grainSize,
                                                             uint32_T tbbQueryThresholds);

EXTERN_C LIBMWKDTREE_API void kdtreeRadiusSearchSetOutputs_single(void* ptrIndicesIn,
                                                                  void* ptrDistsIn,
                                                                  uint32_T* ptrIndicesOut,
                                                                  float* ptrDistsOut);

EXTERN_C LIBMWKDTREE_API void kdtreeRadiusSearchSetOutputs_double(void* ptrIndicesIn,
                                                                  void* ptrDistsIn,
                                                                  uint32_T* ptrIndicesOut,
                                                                  double* ptrDistsOut);

EXTERN_C LIBMWKDTREE_API void kdtreeDeleteObj_single(void* ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeDeleteObj_double(void* ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeDeleteObjRM_single(void* ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeDeleteObjRM_double(void* ptrObj);

EXTERN_C LIBMWKDTREE_API void kdtreeGetLocationDataPointer_single(void* locationData,
                                                                  uint32_T dataSize,
                                                                  uint32_T dims,
                                                                  void** ptr2locationDataPtr);

EXTERN_C LIBMWKDTREE_API void kdtreeGetLocationDataPointer_double(void* locationData,
                                                                  uint32_T dataSize,
                                                                  uint32_T dims,
                                                                  void** ptr2locationDataPtr);

EXTERN_C LIBMWKDTREE_API void kdtreeDeleteLocationDataPointer_single(void* locationPtr);

EXTERN_C LIBMWKDTREE_API void kdtreeDeleteLocationDataPointer_double(void* locationPtr);

#endif
