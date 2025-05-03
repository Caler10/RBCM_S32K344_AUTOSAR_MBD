/* Copyright 1990-2021 The MathWorks, Inc. */

/*
 * MathWorks grants you the right to copy this file to other
 * computer systems and embed this file within your products. You
 * can make modifications for your application.
 *
 *  Data structures and access methods for sigregions.
 *
 *  Allows access to Simulink signals.  See matlab/simulink/src/barplot.c
 *  for example code and sfcndemo_barplot for an example model.  Note that direct
 *  access to these structures is not recommended as the structures may change
 *  in future releases.
 */

#ifndef sigregdef_h
#define sigregdef_h

#define SLREG_NO_FLAGS (0)

#define SLREG_AVAIL (1U << 0)
#define SLREG_REUSED (1U << 1)
#define SLREG_FCNCALL (1U << 2)
#define SLREG_MERGE (1U << 3)
#define SLREG_GROUND (1U << 4)
#define SLREG_FRAME (1U << 5)        /* opt exclude flag-see below          */
#define SLREG_WIDE_FRAME (1U << 6)   /* opt exclude flag-see below          */
#define SLREG_MATRIX (1U << 7)       /* opt exclude flag-see below          */
#define SLREG_COMPLEX (1U << 8)      /* opt exclude flag-see below          */
#define SLREG_ALLOW_REUSED (1U << 9) /* opt un-exclude flag - see below     */
#define SLREG_ACTION (1U << 10)
#define SLREG_CONDEXEC (1U << 11)        /* signal is only conditional executed */
#define SLREG_EXTMODE_UNAVAIL (1U << 12) /* signal is not available in extmode  */
#define SLREG_ELIMINATED (1U << 13)      /* dead branch elimination             */
#define SLREG_INCLUDE_GRND (1U << 14)    /* opt include ground regions          */
#define SLREG_VIRTSIGCNV                              \
    (1U << 15) /* signal connected to signal type     \
                * conversion such as frame conversion \
                */
#define SLREG_VARDIMS (1U << 16)
#define SLREG_MESSAGES (1U << 17)
#define SLREG_DES_STAT (1U << 18)
#define SLREG_STRING (1U << 19)

#define IS_BIT_SET(uword32, bit) ((uword32 & bit) != 0)

#ifdef __cplusplus
class slPort;
#else
struct slPort;
#endif

/* region node */
typedef struct SL_SigRegion_tag {
#if !defined(S_FUNCTION_NAME) && !defined(BUILDING_SL_LOGGING)
    slPort* portObj; /* output port associated with reg */
#else
    void* portObj;
#endif
    void* data;          /* pointer to the data              */
    int startIdx;        /* starting element of the region (i.e., 'data'
                          * points to the 'startIdx' element of the port)
                          */
    int nEls;            /* number of elements in region     */
    bool entireSig;      /* is this region the whole sig?    */
    unsigned int status; /* bit field: see SLREG_* status
                          * vals above */

    int index; /* The i'th region in the original map.  So, if a mux
                * has three sigs coming in, a,b,c, a is index 0, b 1,
                * and c 3.  If the regions were an array instead of
                * a linked list this would be the array index.
                * BE CAREFUL: If regions are removed due to being
                * duplicate or unavailable, the index field is not
                * touched up, so the index field always remains what
                * the original signal map for the composite signal
                * represented.  I'm not sure if this is good behavior
                * or not, but this is how it currently works:
                * 1/16/04 HJT
                */

    int workInt; /* A work integer.  Temp mem location for use when
                  * shuffling regions.
                  */

    /*
     * The following can be derived from the port, but since s-functions
     * do not currently have direct access to the internal slPort *,
     * we must put a copy of the required info directly into this struct.
     */
    int dType;
    int dTypeSize;
    int complexity;
    int frameSize;

    /*
     *
     */
    bool discrete; /*true if discrete in time or value (draw as stair)*/

    /*
     * Dimensions
     *
     * o Notes:
     *    If not a frame (frameSize == 0)
     *       dims[0...numDims], numDims = 1 for a scalar signal
     *    If frame
     *       dims[0] = frameSize
     *       dims[1] = number of columns
     *    basically, the frame is treated as a matrix.
     *
     */
    int numDims;
    int* dims;

    /* Cache var dims info in the sig region */
    int* currDims;

    struct SL_SigRegion_tag* next;
    struct SL_SigRegion_tag* prev;

    const char* name;

    int unitId;

} SL_SigRegion;


/*******************************************************************************
 *                  SIGREGION: PUBLIC ACCESSORS                                *
 ******************************************************************************/

/*
 * The number of elements in the region.
 */
#define gsr_nEls(reg) ((reg)->nEls)

/*
 * A pointer to the next region in the linked list. NULL if at the end of
 * the list.
 */
#define gsr_NextReg(reg) ((reg)->next)

/*
 * A const char * pointer into the data.
 */
#define gsr_data(reg) ((char*)((reg)->data))

/*
 * Starting element of the region (i.e., 'data' points to the 'startIdx'
 * element of the port)
 */
#define gsr_startIdx(reg) ((reg)->startIdx)

/*
 * Output port associated with region.
 */
#define gsr_portObj(reg) ((reg)->portObj)

/*
 * The Simulink data type identifier for the region.
 */
#define gsr_DataType(reg) ((reg)->dType)

/*
 * The number of bytes in one, non-complex data value.
 */
#define gsr_DataTypeSize(reg) ((reg)->dTypeSize)

/*
 * The Simulink unit identifier for the region.
 */
#define gsr_Unit(reg) ((reg)->unitId)

/*
 * True if the data region contains complex elements.
 */
#define gsr_Complex(reg) ((reg)->complexity)

/*
 * The number of rows.  If not matrix, -1.
 * NOTE:
 *  This access macro is deprecated and will only work correctly if
 *  gsr_NumDims <= 2 (i.e.: this macro does not support N-D signals N >2)
 */
#define gsr_M(reg) (((reg)->numDims <= 1) ? -1 : (reg)->dims[0])

/*
 * The number of cols.  If not matrix, the sig width of the corresponding
 * region.
 * NOTE:
 *  This access macro is deprecated and will only work correctly if
 *  gsr_NumDims <= 2 (i.e.: this macro does not support N-D signals N >2)
 */
#define gsr_N(reg) (((reg)->numDims <= 1) ? (reg)->nEls : (reg)->dims[1])

/*
 * The number of dimensions. Can be greater than 2 for N-dimensional signals.
 */
#define gsr_NumDims(reg) ((reg)->numDims)

/*
 * An integer pointer to the dimensions vector. Use gsr_NumDims to determine
 * the length of the dimensions array.
 */
#define gsr_Dims(reg) ((reg)->dims)

/*
 * The availability status of the region (SLREG_AVAIL if avail, else one
 * of the status described above in the "Public Description" section.
 */
#define gsr_status(reg) ((reg)->status)

/*
 * Variable-dimensions info - int pointer to current dims
 */
#define gsr_currDims(reg) ((reg)->currDims)


#endif /* sigregdef_h */
