/*
 * Copyright 2023, The MathWorks Inc.
 */
/**
 * \file external_api.hpp
 * Provides an mxArray-free interface to core implementations.
 */

#ifndef MATHCNN_ALG_EXTERNAL_API_HPP_
#define MATHCNN_ALG_EXTERNAL_API_HPP_

/*
 * Includes from this module.
 */
#ifndef MATHCNN_ALG_ALG_COMMON_DEFS_HPP_
#define MATHCNN_ALG_ALG_COMMON_DEFS_HPP_



// #if defined(BUILDING_LIBMWMATHCNN_ALG)
// #define MATHCNN_ALG_API DLL_EXPORT_SYM
// #else
// #define MATHCNN_ALG_API DLL_IMPORT_SYM
// #endif

#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef MATHCNN_ALG_API
#define MATHCNN_ALG_API
#endif

#include <stdio.h>

// Double-precision convolution.
EXTERN_C MATHCNN_ALG_API void convolution_nd_double(size_t ndims,
    double* z,
    const double* x, const size_t* dimsx, size_t ndimsx,
    const double* w, const size_t* dimsw, size_t ndimsw,
    const double* bias, const size_t* padding, const size_t* stride);

// Single-precision convolution.
EXTERN_C MATHCNN_ALG_API void convolution_nd_float(size_t ndims,
    float* z,
    const float* x, const size_t* dimsx, size_t ndimsx,
    const float* w, const size_t* dimsw, size_t ndimsw,
    const float* bias, const size_t* padding, const size_t* stride);

#endif // MATHCNN_ALG_EXTERNAL_API_HPP_
