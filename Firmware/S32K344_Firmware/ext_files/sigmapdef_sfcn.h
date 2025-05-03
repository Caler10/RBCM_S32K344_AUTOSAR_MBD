/*
 * Copyright 1990-2018 The MathWorks, Inc.
 *
 * MathWorks grants you the right to copy this file to other 
 * computer systems and embed this file within your products. You 
 * can make modifications for your application.
 *
 *  Data structures and access methods for sigmaps, siglists and sigregions.
 *
 *  Allows access to Simulink signals.  See matlab/simulink/src/barplot.c
 *  for example code and sfcndemo_barplot for an example model.  Note that direct
 *  access to these structures is not recommended as the structures may change
 *  in future releases.
 */

#ifndef sigmapdef_sfcn_h
#define sigmapdef_sfcn_h

#include "sigregdef.h"

typedef struct SL_SigInfo_tag {
    const void *portObj;
    const void *sigMap;  /* actual region map for this port */
} SL_SigInfo;

typedef struct SL_SigList_tag {  /* an array of sigInfos */
    int        nSigs;
    SL_SigInfo *sigInfos;
} SL_SigList;

/*
 * Signal selection option.
 */
#define SIGSET_GRAPH            (0) /* specified graph only */
#define SIGSET_GRAPH_N_CHILDREN (1) /* specified graph and all child graphs */

/*******************************************************************************
 *                  SIGLIST: PUBLIC DESCRIPTION                                *
 ******************************************************************************/

/*
 * A high-level overview of the signal list is provided here.  For more details,
 * feel free to examine the data structures defined above.  More information
 * is also provided for the individual access macros defined below.
 *
 * WARNING:
 *  DO NOT DIRECTLY ACCESS ANY OF THESE DATA STRUCTURES.  THEY MAY CHANGE
 *  IN FUTURE RELEASES.  USE THE ACCESS MACROS PROVIDED BELOW.  SEE
 *  <matlabroot>/simulink/src/barplot.c FOR A WORKING EXAMPLE OF DATA ACCESS
 *  VIA SIGNAL MAPS.
 *
 *
 * A signal list is an array of sigInfo structures:
 *  -----------------------------------
 *  | graphical port | graphical port |
 *  | signal map     | signal map     |
 *  -----------------------------------
 *
 *      graphical port:
 *          A pointer to the output port associated with a signal.  It is
 *          graphical in the sense that it may or may not map back to the
 *          actual outport from which the data originates.   Consider:
 *
 *          -----        --------
 *          | A |>------>|      |
 *          -----        |      |
 *          -----        |  C   |>---------->
 *          | B |>------>|      |
 *          -----        |------|
 *                         mux
 *
 *          For the mux block, the 'graphical' port is C.  The two 'actual'
 *          ports are A and B.
 *
 *      signal map:
 *          A linked list of contiguous regions of memory corresponding to
 *          the graphical signal.  Assuming that A and B above are 
 *          non-virtual blocks (e.g., gains, constants, etc, but not mux
 *          demux, etc), then the signal C has two contiguous regions.
 *
 *          The signal map looks like:
 *              
 *              ----------------   --> ----------------   --> NULL
 *              | region info A|   |   | region info B|   |
 *              | next region--|----   | next region--|----
 *              ----------------       ---------------- 
 *
 *          Note that if we create a signal list for A, the graphical port
 *          and the actual port are an identity mapping.  The resulting
 *          signal map consists would consist of only 1 region (assuming that
 *          the output of A is contiguous).
 *              
 *          The regions are essentially pointers into the Simulink memory areas
 *          that are used for block input and output.  Here is some of the info 
 *          contained in the regions.  Other info is also available.  See macro
 *          definitions at the bottom of this file.
 *
 *              data: a void pointer to the data in this region
 *              nEls: number of elements in region
 *              
 *              status: a flag that indicates whether or not the region is
 *                      available for access.  When regions are not available,
 *                      the 'data' field is NULL.  Status can take on the
 *                      following values:
 *                  
 *                          SLREG_AVAIL:
 *                              Data is available for access.
 *
 *                          ====================================================
 *                          The following types of regions are excluded by
 *                          default from the signal list.
 *                          ====================================================
 *
 *                          SLREG_REUSED:
 *                              The output memory area for this signal is being
 *                              shared with the output from another port.  This
 *                              signal can not be accessed (click 'Disable
 *                              optimized block I/O storage' on the Diagnostics
 *                              page of the Simulation Parameter Dialog box
 *                              to disable the sharing of block I/O memory).
 *
 *                          SLREG_FCNCALL:
 *                              The data corresponds to a fcn-call connection.
 *                              There is no data to view.
 *
 *                          SLREG_MERGE:
 *                              This signal is being merged.  This is a special
 *                               case of a buffer being re-used.  The
 *                               signal cannot be accessed.
 *
 *                          SLREG_ACTION:
 *                              The data corresponds to an action signal, this
 *                              data can not be viewed. 
 *                             
 *                          ====================================================
 *                          The following types of regions are optionally
 *                          excluded from the signal list.  See the excludeFlags
 *                          arg of ssCallSigListCreateFcn().
 *
 *                          If you are not excluding a given region type, the 
 *                          region status will be SLREG_AVAIL.  Otherwise, if
 *                          the excluded region type, SLREG_xxx, is encountered,
 *                          the region status will be SLREG_xxx.
 *                          ====================================================
 *
 *                          SLREG_FRAME:
 *                              The data region corresponds to a frame (a time
 *                              series of data points).  If your application
 *                              does not support frames, include SLREG_FRAME
 *                              as part of the excludeFlags to ensure that
 *                              all frame data is excluded from the sigList.
 *
 *                          SLREG_WIDE_FRAME:
 *                              The data region corresponds to a wide frame, 
 *                              size greated than 1. If your application
 *                              does not support wide frames, include 
 *                              SLREG_WIDE_FRAME as part of the excludeFlags to 
 *                              ensure that all wide frame data is excluded from the 
 *                              sigList.
 *
 *                          SLREG_MATRIX:
 *                              The data region corresponds to a matrix.  If
 *                              your application does not support matrices,
 *                              include SLREG_MATRIX as part of the 
 *                              excludeFlags to ensure that all matrices are
 *                              excluded from the sigList.
 *
 *                          SLREG_COMPLEX:
 *                              The data region corresponds to complex data.  If
 *                              your application does not support complex data,
 *                              include SLREG_COMPLEX as part of the 
 *                              excludeFlags to ensure that all complex data is
 *                              excluded from the sigList.
 *
 *                          ====================================================
 *                          The following overrides the default exclusions
 *                          of the specified type of regions.
 *                          ====================================================
 *
 *                          SLREG_ALLOW_REUSED
 *                              "un-exludes" reused regions (which are excluded
 *                              by default.  As described above in the
 *                              SLREG_REUSED section, this can lead to
 *                              unexpected results, unless the block that is
 *                              requesting the signal access is hardwired into
 *                              the diagram.
 *
 *                              In general, if a block has input ports, this
 *                              flag should be specified (assuming that the 
 *                              sigmaps being created correspond to its input
 *                              ports).
 *
 *              dType:      The Simulink data type id for the data.
 *              dTypeSize:  Number of bytes in 1 non-complex element.
 *              complexity: true if the data values are complex
 *              m:          if a matrix, the number of rows (-1 if not matrix)
 *              n:          if a matrix, the number of cols (-1 if not matrix)
 *
 *
 *  In general, the following snippet of code can be used to walk the elements
 *  of a signal:
 *      SL_SigRegion *sigReg = gsl_FirstReg(sigList,i);
 *       
 *      do {
 *         int nEls = gsr_nEls(sigReg);
 *
 *          if (nEls > 0) {
 *              int        el;
 *              int        dType   = gsr_DataType(sigReg);
 *              int        elSize  = gsr_DataTypeSize(sigReg);
 *              const char *data   = gsr_data(sigReg);
 *
 *              for (el=0; el<nEls; el++) {
 *                  data += elSize;
 *              }
 *          }
 *      } while((sigReg = gsr_NextReg(sigReg)) != NULL);
 */


/*******************************************************************************
 *                  SIGLIST: PUBLIC ACCESSORS                                  *
 ******************************************************************************/

/*
 * Number of signals in the signal list.
 */
#define gsl_nSigs(sigList) ((sigList)->nSigs)

/*
 * Number of regions comprising the 'listIdx-th' signal in the list.
 */
#define gsl_nSigRegions(S, sigList, lstIdx) \
    ssCallSigListGetNumRegionsFcn(S, sigList, lstIdx)

/*
 * A pointer to the first region of the 'listIdx-th' signal in the list.
 */
#define gsl_FirstReg(S, sigList, lstIdx) \
    (SL_SigRegion *)(ssCallSigListGetFirstRegFcn(S,(void *)sigList,lstIdx))

/*
 * The total number of elements comprising the 'listIdx-th' signal in the list.
 */
#define gsl_NumElements(S, sigList,lstIdx) \
    ssCallSigListGetNumElementsFcn(S, sigList, lstIdx)

/*
 * Returns true if the signal is a tie wrap.  This means that the signal map
 * consists of either:
 *  o one entire signal (i.e., the output of 1 non-virtual block)
 *  o a simple bundling together of multiple entire signals
 *
 *  Generally the only way to get a non-tie-wrapped signal is to mix the
 *  elements of existing signals or re-shuffle them via the use of the selector,
 *  mux and demux blocks.
 *
 *
 *      -----      -----                               --------
 *      | 1 | ---->|   |           -----               |      |
 *      -----      |   |           |   |        ------>|      |
 *     constant    |   | tie wrap  |   |------  |      |      |  not a tie wrap  
 *      -----      |   |---------->|   |     |  |      |      |--------------->
 *      | 1 | ---->|   |           |   |  ---|--|      |      | elements got 
 *      -----      |   |           |   |--|  |-------->|      |   shuffled
 *     constant    -----           |   |               |      |
 *                   mux           -----               --------
 *                                 demux                 mux
 *
 *
 */
#define gsl_TieWrap(S, sigList, lstIdx) \
    ssCallSigListGetIfTieWrapFcn(S, sigList, lstIdx)

/*
 * Get the pointer to the port associated with the 'listIdx-th' signal in the
 * list.
 */
#define gsl_PortObj(sigList,lstIdx) \
    (sigList->sigInfos[(lstIdx)].portObj)

#endif /* sigmapdef_sfcn_h */
