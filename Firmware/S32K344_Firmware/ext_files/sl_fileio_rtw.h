#ifdef SUPPORTS_PRAGMA_ONCE
# pragma once
#endif
#ifndef sl_fileio_rtw_h
#define sl_fileio_rtw_h
/*
 *
 * Copyright 2008-2016 The MathWorks, Inc.
 *
 * This header is the interface to the sl_fileio module. It is used by the
 * RTW-RSim and Rapid Accelerator targets.
 *
 * 
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

extern const char *rtwMATFileLoaderCreateInstance(
    const char  *fileName,
    int          errorXMLMode,
    const int    extrapolationBeforeFirstDataPointInt,
    const int    interpolationWithinTimeRangeInt,
    const int    extrapolationAfterLastDataPointInt,
    const unsigned char *ground,
    const int    iZeroCrossingSwitch,
    int          fxpDiagnosticOverflow,
    int          fxpDiagnosticSaturation,
    const char  *fxpBlockPath,
    void        **outMATFileLoader
    );

extern const char *rtwMATFileLoaderDestroyInstance(
    int  errorXMLMode,
    void *pMATFileLoader
    );

extern const char *rtwMATFileLoaderGetOutput(
    int            errorXMLMode,
    void          *pMATFileLoader,
    const double   t,
    const int      iMajorTimeStep,
    void         **outOutputValue
    );

extern const char *rtwMATFileLoaderGetZeroCrossingSignal(
    void         *pMATFileLoader,
    const double  t,
    const int     iMajorTimeStep,
    void         *outZeroCrossingSignal
    );


extern const char *rtwMATFileLoaderCheckMATFileConsistency(
    void           *pMATFileLoader,
    const char     *MATFileName,
    int             errorXMLMode,
    const char     *expDTypeName,
    const int       expNDims,
    const int      *expDims,
    const int       expComplexity,
    const int       isFixedPoint,
    const int       dataTypeMode,
    const int       isSigned,
    const int       wordLength,
    const double    slopeAdjustmentFactor,
    const int       fixedExponent,
    const double    bias,
    const int       expEnumNStrings,
    const char    **expEnumStrings,
    const int      *expEnumValues);

#ifdef __cplusplus
}
#endif

#endif /* sl_fileio_rtw_h */

/* LocalWords:  RSim
 */
