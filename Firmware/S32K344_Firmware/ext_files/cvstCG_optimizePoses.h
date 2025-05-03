#ifndef OPTIMIZEPOSES_
#define OPTIMIZEPOSES_

#ifndef LIBMWOPTIMIZEPOSES_API
#define LIBMWOPTIMIZEPOSES_API
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

EXTERN_C LIBMWOPTIMIZEPOSES_API void tform2quatpose(void* mtform, double* mpose);
EXTERN_C LIBMWOPTIMIZEPOSES_API void quatpose2tform(const double* mtform, double* mpose);
EXTERN_C LIBMWOPTIMIZEPOSES_API void initializeVectors(const int numNodes,
                                                       const int poseDim,
                                                       void* mNodes,
                                                       void** nodesVec);
EXTERN_C LIBMWOPTIMIZEPOSES_API void poseOptimizer(const double blockSolverType,
                                                   const double maxIter,
                                                   const double funcTol,
                                                   const double verboseFlag,
                                                   const double maxTime,
                                                   void* mNodes,
                                                   void* mEdges,
                                                   void* mInfoMats,
                                                   double* mOptimNodes,
                                                   double* structValues);
#endif
