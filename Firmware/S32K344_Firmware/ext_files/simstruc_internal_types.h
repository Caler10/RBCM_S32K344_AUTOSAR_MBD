/* Copyright 1990-2023 The MathWorks, Inc. */

/*
 *
 * File: simstruc_internal_types.h
 *
 * Abstract:
 *   Types used internally by SimStruct, but not published to external users.
 */

#ifndef __SIMSTRUC_INTERNAL_TYPES_H__
#define __SIMSTRUC_INTERNAL_TYPES_H__

#include "simstruc_types.h"

/* 32-bit and 64-bit exclusive typedefs */
typedef struct DimsInfo_tag DimsInfo_AsInt;
typedef struct DimsInfo_tag_SLSize DimsInfo_AsSLSize;
typedef struct SparseHeader_Tag SparseHeader_AsInt;
typedef struct SparseHeader_Tag_SLSize SparseHeader_AsSLSize;

/* Forward-declaration of type for which the full definition is not needed everywhere */
struct _ssMdlInfo;

/* Model info types */
typedef enum {
    MDL_INFO_ID_PARAM = 0,
    MDL_INFO_ID_SIGNAL,
    MDL_INFO_ID_STATE,
    MDL_INFO_ID_DSM,
    MDL_INFO_ID_GLOBAL_DSM,
    MDL_INFO_ID_DATA_TYPE,
    MDL_INFO_ID_CMPLX_DATA_TYPE,
    MDL_INFO_ID_MODEL,
    MDL_INFO_ID_FCNNAME,
    MDL_INFO_ID_GRPFCNNAME,
    MDL_INFO_ID_CSC,
    MDL_INFO_ID_IMPORTED_CSC,
    MDL_INFO_SUBSYS_FILENAME,
    MDL_INFO_MODEL_FILENAME,
    MDL_INFO_ID_MACHINE_EXPORTED,
    MDL_INFO_NAME_GLOBAL_DSM,
    MDL_INFO_NAME_MDLREF_DWORK,
    MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT,
    MDL_INFO_ID_ENUMTYPE_STRING,
    MDL_INFO_ID_MODEL_FCN_ARGNAME,
    MDL_INFO_ID_MODEL_FCN_NAME,
    MDL_INFO_ID_MODEL_CLASS_NAME,
    MDL_INFO_ID_MODEL_CLASS_NAMESPACE,
    MDL_INFO_ID_AUTOSAR_RTE_FCN_NAME,
    MDL_INFO_ID_SFCN_NAME,
    MDL_INFO_ID_RESERVED,
    MDL_INFO_ID_VARIANT,
    MDL_INFO_ID_SLFCNCALL,
    MDL_INFO_ID_OUTPORT_BLOCK_SIGNAL,
    MDL_INFO_ID_MDL_WKS_PARAM,
    MDL_INFO_ID_INPORT_SIGNAL,
    MDL_INFO_ID_BLOCK_PARAM,
    MDL_INFO_ID_NMV_VARIANT_PARAM,
    NumMdlInfoType
} MdlInfoType;

typedef enum { SIM_PAUSE, SIM_CONTINUE } ssSimStatusChangeType;

typedef struct PointerRec_t {
    DTypeId dataTypeId;
    const void* data;
    void* retData;
    size_t retWidth;
} PointerRec;

typedef enum {
    /*
     * Called when the user request the trigger to be armed (i.e., after
     * the 'arm trigger' button is pressed and the trigger arm message
     * has successfully been handed off to ext_comm).
     */
    EXTLOGTASK_TRIG_ARM,

    /*
     * Called when the first point of a one-shot arrives.
     */
    EXTLOGTASK_INIT_EVENT,

    /*
     * Definitions:
     *  one-shot:    one buffer of data collected when the trigger fires.
     *  normal-mode: a series of one-shots
     *
     * When in normal mode, each buffer in the series, except for the last
     * buffer is consider to be an 'intermediate' buffer.  When the final
     * point of an intermediate buffer has arrived on the host, the
     * EXTLOGTASK_TERM_INTERMEDIATE_ONESHOT method is called.  When the
     * final point of the last buffer of the series arrives, the
     * EXTLOGTASK_TERM_SESSION is called.
     *
     * Note that when not in normal mode, the
     * EXTLOGTASK_TERM_INTERMEDIATE_ONESHOT method is never called.
     *
     * Also see EXTLOGTASK_TERM_SESSION.
     */
    EXTLOGTASK_TERM_INTERMEDIATE_ONESHOT,

    /*
     * Called when:
     *  o In normal mode and the last point of the last buffer in a one-shot
     *    series has arrived (i.e., this is the end of the current log session).
     *
     *  o When in one-shot mode and the final point arrives (again this is the
     *    end of the logging session since the one and only buffer has been
     *    acquired).
     *
     *  See comments for: EXTLOGTASK_TERM_INTERMEDIATE_ONESHOT
     */
    EXTLOGTASK_TERM_SESSION

} ExtModeLogBlockMeth;


#endif /* __SIMSTRUC_INTERNAL_TYPES_H__ */
