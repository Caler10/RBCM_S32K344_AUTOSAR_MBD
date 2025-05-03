#ifndef SLSA_SIM_H
#define SLSA_SIM_H

/**
 * @file slsa_sim.h
 *
 * This file contains macros to control the scoping of the exported classes
 * and functions from this module. This file should be included by all the
 * in this module.
 *
 */

/* Copyright 2011-2022 The MathWorks, Inc. */

#ifdef BUILDING_LIBMWSLSA_SIM
/* being included from inside SLSA_SIM module */
#include "package.h"
#define SLSA_SIM_PUBLISHED_C extern "C" DLL_EXPORT_SYM
#else
/* being included from outside, such as raccel code */
#if defined(__cplusplus)
/* Needed for non-inlined C++ S-functions */
#define SLSA_SIM_PUBLISHED_C extern "C"
#else
#define SLSA_SIM_PUBLISHED_C extern
#endif
#endif

#endif // SLSA_SIM_H
