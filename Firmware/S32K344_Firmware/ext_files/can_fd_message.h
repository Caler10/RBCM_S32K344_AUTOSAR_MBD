/* Copyright 2017-2023 The MathWorks, Inc. */
/**
* @file:       can_fd_message.hpp
*
* Purpose:     Declare custom and register CAN FD datatype.
*
*
*/
#ifndef __CANFDMESSAGE__HEADER__
#define __CANFDMESSAGE__HEADER__

#ifdef RTWTYPES_H
#include "rtwtypes.h" /* Use rtwtypes.h if available */
#else
#include "tmwtypes.h"
#endif

/* Define invalid CAN Identifier value. This can be used to specify an invalid message
This represents a uint32_T value */
#define INVALID_CAN_ID 0xFFFFFFFFU

/*
The CAN_FD_DATATYPE structure has been structured so that it is tightly packed.
Size of structure (without timestamp field) :20 bytes
Size of structure (with timestamp field)    :28 bytes
*/
typedef struct
{
	/* Is this CAN (0) or CAN FD (1) */
	uint8_T ProtocolMode;

	/* Is Extended frame */
	uint8_T Extended;

	/* Length */
	uint8_T Length;

	/* RTR */
	uint8_T Remote;

	/* Error */
	uint8_T Error;

	/* Bit Rate Switch. Possible values 0 or 1. Valid only if ProtocolMode indicates CAN FD */
	uint8_T BRS;

	/* Error State Indicator.  Possible values 0 or 1. Valid only if ProtocolMode indicates CAN FD */
	uint8_T ESI;

	/* Data Length Code. Possible values 0-15. Valid only if ProtocolMode indicates CAN FD */
	uint8_T DLC;

	/* CAN ID */
	uint32_T ID;
            
    /* Reserved */
    uint32_T Reserved;

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

	/* Data field. Indices 8-63 (zero-based) are valid only if ProtocolMode indicates CAN FD */
	uint8_T Data[64];

}  CAN_FD_MESSAGE;

typedef CAN_FD_MESSAGE CAN_FD_DATATYPE;

/**
* Initialize a CAN FD message.
*
* @param CAN_FD_DATATYPE : CAN FD Message structure
*/
void initializeCANFDMessage(CAN_FD_DATATYPE* canfdmsg, uint8_T ProtocolMode, uint8_T Extended);

#endif