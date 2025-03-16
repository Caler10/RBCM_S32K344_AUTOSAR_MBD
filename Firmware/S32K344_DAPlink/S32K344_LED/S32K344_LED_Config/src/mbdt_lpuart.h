/*
 * Copyright 2020-2024 NXP
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by
 * NXP and may only be used strictly in accordance with the applicable
 * license terms. By expressly accepting such terms or by downloading,
 * installing, activating and/or otherwise using the software, you are
 * agreeing that you have read, and that you agree to comply with and are
 * bound by, such license terms.  If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */
#ifndef _MBDT_LPUART_H_
#define _MBDT_LPUART_H_

#include "Clock_Ip_Types.h"
#include "Clock_Ip.h"
#include "Devassert.h"
#include "Lpuart_Uart_Ip_HwAccess.h"

#ifdef S32K312
    #include "S32K312_LPUART.h"
#endif

#ifdef S32K342
    #include "S32K342_LPUART.h"
#endif

#ifdef S32K344
    #include "S32K344_LPUART.h"
#endif

#ifdef S32K358
    #include "S32K358_LPUART.h"
#endif

#if defined(S32K374) || defined(S32K376)
    #include "S32K37_LPUART.h"
#endif

#ifdef S32K388
    #include "S32K388_LPUART.h"
#endif

#if defined(S32K394) || defined(S32K396)
    #include "S32K39_LPUART.h"
#endif

#ifdef LPUART_UART_IP_DEV_ERROR_DETECT
    #if (LPUART_UART_IP_DEV_ERROR_DETECT == STD_ON)
        #define LPUART_UART_DEV_ASSERT(x)      DevAssert(x)
    #else
        #define LPUART_UART_DEV_ASSERT(x)      (void)(x)
    #endif
#endif

/* Table of base addresses for LPUART instances. */

#if defined(S32K374) || defined(S32K376) || defined(S32K394) || defined(S32K396)
    static const Clock_Ip_NameType Lpuart_clkNames[LPUART_INSTANCE_COUNT] = {
        LPUART0_CLK,
        LPUART1_CLK,
        LPUART2_CLK,
        LPUART3_CLK};
#endif

#if defined(S32K344) || defined(S32K358) || defined(S32K388)
    static const Clock_Ip_NameType Lpuart_clkNames[LPUART_INSTANCE_COUNT] = {
        LPUART0_CLK,
        LPUART1_CLK,
        LPUART2_CLK,
        LPUART3_CLK,
        LPUART4_CLK,
        LPUART5_CLK,
        LPUART6_CLK,
        LPUART7_CLK,
        LPUART8_CLK,
        LPUART9_CLK,
        LPUART10_CLK,
        LPUART11_CLK,
        LPUART12_CLK,
        LPUART13_CLK,
        LPUART14_CLK,
        LPUART15_CLK};
#endif
    
#ifdef S32K342
    static const Clock_Ip_NameType Lpuart_clkNames[LPUART_INSTANCE_COUNT] = {
        LPUART0_CLK,
        LPUART1_CLK,
        LPUART2_CLK,
        LPUART3_CLK};
#endif
    
#ifdef S32K312
    static const Clock_Ip_NameType Lpuart_clkNames[LPUART_INSTANCE_COUNT] = {
        LPUART0_CLK,
        LPUART1_CLK,
        LPUART2_CLK,
        LPUART3_CLK,
        LPUART4_CLK,
        LPUART5_CLK,
        LPUART6_CLK,
        LPUART7_CLK};
#endif
    
static LPUART_Type * const Lpuart_apBases[LPUART_INSTANCE_COUNT] = IP_LPUART_BASE_PTRS;

#if defined(S32K374) || defined(S32K376) || defined(S32K394) || defined(S32K396)
    #define LPUART_IRQS { \
        LPUART0_IRQn, \
        LPUART1_IRQn, \
        LPUART2_IRQn, \
        LPUART3_IRQn }
#endif

#if defined(S32K344) || defined(S32K358) || defined(S32K388)
    #define LPUART_IRQS { \
        LPUART0_IRQn, \
        LPUART1_IRQn, \
        LPUART2_IRQn, \
        LPUART3_IRQn, \
        LPUART4_IRQn, \
        LPUART5_IRQn, \
        LPUART6_IRQn, \
        LPUART7_IRQn, \
        LPUART8_IRQn, \
        LPUART9_IRQn, \
        LPUART10_IRQn, \
        LPUART11_IRQn, \
        LPUART12_IRQn, \
        LPUART13_IRQn, \
        LPUART14_IRQn, \
        LPUART15_IRQn }
#endif

#ifdef S32K342
    #define LPUART_IRQS { \
        LPUART0_IRQn, \
        LPUART1_IRQn, \
        LPUART2_IRQn, \
        LPUART3_IRQn }
#endif

#ifdef S32K312
    #define LPUART_IRQS { \
        LPUART0_IRQn, \
        LPUART1_IRQn, \
        LPUART2_IRQn, \
        LPUART3_IRQn, \
        LPUART4_IRQn, \
        LPUART5_IRQn, \
        LPUART6_IRQn, \
        LPUART7_IRQn }
#endif

static const IRQn_Type Lpuart_RxTxIrqId[LPUART_INSTANCE_COUNT] = LPUART_IRQS;

void LPUART_Uart_SetBaudRate(uint32 instance, uint32 desiredBaudRate);

#endif  /* _MBDT_LPUART_H_ */
