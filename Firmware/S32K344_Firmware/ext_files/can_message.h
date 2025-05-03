/* Copyright 2008-2021 The MathWorks, Inc. */
/**
 * @file:       can_message.h
 *
 * Purpose:     Declare custom and register CAN datatype.
 *
 * $Authors:    Shankar Subramanian $
 *
 * $Copyright: 2008-2019 The MathWorks, Inc.$
 *
 */
#ifndef __CANMESSAGE__HEADER__
#define __CANMESSAGE__HEADER__

/* Use tmwtypes.h for non-codegen targets */
#if defined(MATLAB_MEX_FILE) || defined(SIMULINK_REAL_TIME)
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif
/* @DO NOT REMOVE: The following typedef is required for targets (FM5, C166 etc.) to actually
   use it for their code generation TLC file. Since their datatype is being
   discarded, this is being defined in our header which they will be referencing.*/
typedef enum {CAN_MESSAGE_STANDARD, CAN_MESSAGE_EXTENDED} CanFrameType;

/* Define invalid CAN Identifier value. This can be used to specify invalid CAN Message
   This represents a uint32_T value */
#define INVALID_CAN_ID 0xFFFFFFFFU

/*
  The CAN_DATATYPE structure has been structured so that it is tightly packed.
  Size of structure (without timestamp field) :16 bytes
  Size of structure (with timestamp field)    :24 bytes
*/
typedef struct
{

    /* Is Extended frame */
    uint8_T Extended;

    /* Length */
    uint8_T Length;

    /* RTR */
    uint8_T Remote;

    /* Error */
    uint8_T Error;

    /* CAN ID */
    uint32_T ID;

    /*
      TIMESTAMP_NOT_REQUIRED is a macro that will be defined by Target teams
      PIL, C166, FM5, xPC if they do not require the timestamp field during code
      generation. By default, timestamp is defined. If the targets do not require
      the timestamp field, they should define the macro TIMESTAMP_NOT_REQUIRED before
      including this header file for code generation.
    */
#ifndef TIMESTAMP_NOT_REQUIRED
    /* Timestamp */
    double Timestamp;
#endif

    /* Data field */
    uint8_T Data[8];

}  CAN_MESSAGE;

typedef CAN_MESSAGE CAN_DATATYPE;

/**
 * Initialize a CAN message.
 *
 * @param CAN_DATATYPE: CAN Message structure
 */
void initializeCANMessage(CAN_DATATYPE* canmsg, uint8_T Extended);

#endif
