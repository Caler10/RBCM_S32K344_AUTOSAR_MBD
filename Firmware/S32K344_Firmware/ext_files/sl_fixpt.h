#ifndef __SL_FIXPT__
#define __SL_FIXPT__

/* Copyright 1990-2013 The MathWorks, Inc. */

/*
 * FixPt: Data type override options
 */
typedef enum {
    FIXPT_DATATYPE_LOCAL,
    FIXPT_DATATYPE_SCALED_DOUBLES,
    FIXPT_DATATYPE_TRUE_DOUBLES,
    FIXPT_DATATYPE_TRUE_SINGLES,
    FIXPT_DATATYPE_OFF,
    FIXPT_DATATYPE_OVERRIDE_IGNORE,
    FIXPT_DATATYPE_OVERRIDE_UNKNOWN
} FixPtDataTypeOverride;

/*
 * FixPt: Data type override applies to options
 */
typedef enum {
    FIXPT_DATATYPEOVERRIDE_NUMERIC_TYPES,
    FIXPT_DATATYPEOVERRIDE_FLOATING_POINT,
    FIXPT_DATATYPEOVERRIDE_FIXED_POINT
} FixPtDataTypeOverrideAppliesTo;

/*
 * FixPt: Min/Max logging options
 */
typedef enum {
    FIXPT_LOGGING_LOCAL,
    FIXPT_LOGGING_MIN_MAX_OVERFLOW,
    FIXPT_LOGGING_OVERFLOW_ONLY,
    FIXPT_LOGGING_OFF
} FixPtMinMaxOverflowLogging;

/*
 * FixPt: Min/Max logging mode options
 */
typedef enum {
    FIXPT_ARCHIVEMODE_OVERWRITE,
    FIXPT_ARCHIVEMODE_MERGE
} FixPtMinMaxOverflowArchiveMode;

#endif
