/*******************************************************************************
 * Piotr's Computer Vision Matlab Toolbox      Version 3.24
 * Copyright 2014 Piotr Dollar & Ron Appel.  [pdollar-at-gmail.com]
 * Licensed under the Simplified BSD License [see external/bsd.txt]
 *******************************************************************************/

#ifndef ACFOBJECTDETECTOR_
#define ACFOBJECTDETECTOR_

#ifndef LIBMWACFOBJECTDETECTOR_API
#    define LIBMWACFOBJECTDETECTOR_API
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

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void rgb2luv(const float *rgb, float *luv, const float *yTable,
	const size_t nPixelsPerChannel, const size_t nYTable);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void convTri(float *I, float *O, int h, int w, int d, int r, int s, float*T, int h0, int h1);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void convTri1(float *I, float *O, int h, int w, int d, float p, int s, float *T);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void gradient(const float *I, float *gMag, float *gDir, size_t h, size_t w, size_t d, float *M, float *Gx, float *Gy);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void gradientSSE(const float *I, float *gMag, float *gDir, size_t h, size_t w, size_t d, size_t hsse, float *M,
	float *Gx, float *Gy);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void noInterpolation(float *gradHist, float *gMag, float *gDir, int cellSize,
	int h, int w, int numberOfRowCells, int numberOfColumnCells,
	int numberOfCellsPerBin, int numBins, int useSignedOrientation, int *iO, float *iM);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void orientationInterpolation(float *gradHist, float *gMag, float *gDir, int cellSize,
	int h, int w, int numberOfRowCells, int numberOfColumnCells, int numberOfCellsPerBin,
	int numBins, int useSignedOrientation, int *iO, float *iM, int *iO2, float *iM2);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void spatialInterpolation(float *gradHist, float *gMag, float *gDir, int cellSize,
	int h, int w, int numberOfRowCells, int numberOfColumnCells, int numberOfCellsPerBin,
	int numBins, int useSignedOrientation, int *iO, float *iM);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void spatialOrientationInterpolation(float *gradHist, float *gMag, float *gDir, int cellSize,
	int h, int w, int numberOfRowCells, int numberOfColumnCells, int numberOfCellsPerBin,
	int numBins, int useSignedOrientation, int *iO, float *iM, int* iO2, float *iM2);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
int32_T  getNumberOfBoundingBoxes(float *chns, float *thrs, float *hs, uint32_T *fids, uint32_T *child,
	const int shrink, const int modelHt, const int modelWd, const int stride, const float cascThr,
	const int height, const int width, const int nChns, const int nTreeNodes, const int nTrees,
	const int height1, const int width1, const int treeDepth, void** rs_w, void** cs_w, void** hs1_w, unsigned char* flag);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void copyBoundingBox(void* rs_w, void* cs_w, void* hs1_w, double* bbs, const int stride, const int modelHt,
	const int modelWd, int m);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void resample_float(float *A, float *B, int ha, int hb, int wa, int wb, int d, float r);

EXTERN_C LIBMWACFOBJECTDETECTOR_API
void resample_double(double *A, double *B, int ha, int hb, int wa, int wb, int d, float r);


#endif
