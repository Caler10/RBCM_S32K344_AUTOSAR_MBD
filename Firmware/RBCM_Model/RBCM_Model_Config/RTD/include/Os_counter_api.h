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

#ifndef OS_COUNTER_API_H
#define OS_COUNTER_API_H

/**
*   @file Os_counter_api.h
*
*   @addtogroup [OS]
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "Os_counter_types.h"   /* for StatusType and counter specific types */

extern StatusType GetCounterValue (CounterType ctrId, TickRefType tickRef);

extern StatusType GetElapsedValue (CounterType ctrId, TickRefType valueRef, TickRefType tickRef);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OS_COUNTER_API_H */
