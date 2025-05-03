/*
 * Copyright 1994-2002 The MathWorks, Inc.
 *
 * File: mem_mgr.h     
 *
 * Abstract:
 */

#ifndef __MEM_MGR__
#define __MEM_MGR__

struct MemBufHdr {
    struct MemBufHdr *memBufNext;
    struct MemBufHdr *memBufPrev;
    char   *MemBuf;
    int    size;
};

typedef struct MemBufHdr MemBufHdr;

extern void ExtModeFree(void *mem);

extern void *ExtModeMalloc(uint32_T size);

extern void *ExtModeCalloc(uint32_T number, uint32_T size);

#endif /* __MEM_MGR__ */

/* [EOF] mem_mgr.h */
