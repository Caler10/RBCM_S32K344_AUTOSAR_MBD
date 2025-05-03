/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef OS_TYPES_COMMON_PUBLIC_H_
#define OS_TYPES_COMMON_PUBLIC_H_

/**
*   @file Os_types_common_public.h
*
*   @addtogroup [OS]
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif

#include "Os_types_basic.h"

#define OSFALSE         (0U)
#define OSTRUE          (1U)

/*
 *  types required by the Autosar API
 */

typedef OSBYTE OSAPPLICATIONTYPE;
typedef OSBYTE OSAPPLICATIONMASKTYPE;

/* avoid collision with MCAL */
#ifndef STATUSTYPEDEFINED
/* prescribed by OSEK/VDX */
#define STATUSTYPEDEFINED       /* required by OSEK/VDX Binding Specification */

#define E_OK                      ( (StatusType) 0 )   /* No error, successful completion  */
typedef unsigned char StatusType;       /* OSEK: Status type             */

#endif /* !defined(STATUSTYPEDEFINED) */


typedef OSWORD OSObjectType;            /* bits [15] - Core Id, bits [14..11] - ObjType, bits [10..0] - ObjId, */

typedef OSObjectType TaskType;          /* used in task, events api ... */

typedef OSDWORD TickType;               /* Type for timers ticks - use by counter, alarm, schedule table alarm */

typedef TickType  *TickRefType;         /* OSEK: Reference to counter value - use by counter and alarm */

typedef OSDWORD EventMaskType;          /* Used in event and alarm  */

typedef EventMaskType *EventMaskRefType;      /* Used in event and alarm  */

typedef OSObjectType ISRType;                 /* used both in memory and ISR */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OS_TYPES_COMMON_PUBLIC_H_ */
