/* Copyright 2008-2022 The MathWorks, Inc. */

#ifndef FIXPOINT_SPEC_H
#define FIXPOINT_SPEC_H

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifdef BUILDING_LIBFIXEDPOINT

#define FIXPOINT_EXPORT_CLASS DLL_EXPORT_SYM
#define FIXPOINT_EXPORT_FCN DLL_EXPORT_SYM
#define FIXPOINT_EXPORT DLL_EXPORT_SYM
#define FIXPOINT_EXPORT_EXTERN_C extern "C" DLL_EXPORT_SYM

#elif defined(DLL_IMPORT_SYM)

#define FIXPOINT_EXPORT_CLASS DLL_IMPORT_SYM
#define FIXPOINT_EXPORT_FCN DLL_IMPORT_SYM
#define FIXPOINT_EXPORT DLL_IMPORT_SYM
#ifdef __cplusplus
#define FIXPOINT_EXPORT_EXTERN_C extern "C" DLL_IMPORT_SYM
#else
#define FIXPOINT_EXPORT_EXTERN_C extern DLL_IMPORT_SYM
#endif

#else

#ifdef __cplusplus
#define FIXPOINT_EXPORT_EXTERN_C extern "C"
#else
#define FIXPOINT_EXPORT_EXTERN_C extern
#endif

#define FIXPOINT_EXPORT_CLASS extern
#define FIXPOINT_EXPORT_FCN extern
#define FIXPOINT_EXPORT extern

#endif

#endif

