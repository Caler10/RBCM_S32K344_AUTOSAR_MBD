/*
 * Copyright 1994-2002 The MathWorks, Inc.
 *
 * File: bio_sig.h     
 *
 * Abstract:
 *	typedef for BlockIOSignals, included by *rt_main.c and MODEL.bio
 */

#ifndef _BIO_SIG_H_
# define _BIO_SIG_H_

typedef struct BlockIOSignals_tag {
  char_T   *blockName;    /* Block's full path name (RTW mangled version)     */
  char_T   *signalName;   /* Signal label (unmangled, or NULL if not present) */
  uint_T   portNumber;    /* Block output port number (starting at 0)         */
  uint_T   signalWidth;   /* Signal's width                                   */
  void     *signalAddr;   /* Signal's Address in the block I/O vector         */
  char_T   *dtName;       /* The C-language data type name                    */
  uint_T   dtSize;        /* The size in # of bytes for the data type         */
} BlockIOSignals;

#endif
