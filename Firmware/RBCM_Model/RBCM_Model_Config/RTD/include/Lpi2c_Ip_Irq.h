/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
*   only be used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef LPI2C_IP_IRQ_H
#define LPI2C_IP_IRQ_H

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Lpi2c_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_IRQ_VENDOR_ID                      43
#define LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define LPI2C_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define LPI2C_IP_IRQ_SW_MAJOR_VERSION               5
#define LPI2C_IP_IRQ_SW_MINOR_VERSION               0
#define LPI2C_IP_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpi2c_Ip_CfgDefines.h */
#if (LPI2C_IP_IRQ_VENDOR_ID != LPI2C_IP_CFGDEFINES_VENDOR_ID)
    #error "Lpi2c_Ip_Irq.h and Lpi2c_Ip_CfgDefines.h have different vendor ids"
#endif
#if (( LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_IRQ_AR_RELEASE_REVISION_VERSION != LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_Irq.h and Lpi2c_Ip_CfgDefines.h are different"
#endif
#if (( LPI2C_IP_IRQ_SW_MAJOR_VERSION != LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_IRQ_SW_MINOR_VERSION != LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     ( LPI2C_IP_IRQ_SW_PATCH_VERSION != LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_Irq.h and Lpi2c_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ( (LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
          (LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Lpi2c_Ip_Irq.h and OsIf.h are different"
    #endif
#endif

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/*******************************************************************************
 * Code
 ******************************************************************************/

#if defined (LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE)


#if (LPI2C_INSTANCE_COUNT > 0u)

/* LPI2C0 master and slave handler named in startup code. */
ISR(LPI2C0_Master_Slave_IRQHandler);
#endif /* (LPI2C_INSTANCE_COUNT > -1u) */

#if (LPI2C_INSTANCE_COUNT > 1u)

/* LPI2C1 master and slave handler named in startup code. */
ISR(LPI2C1_Master_Slave_IRQHandler);
#endif /* (LPI2C_INSTANCE_COUNT > 0u) */

#else /*LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE*/

#if (LPI2C_INSTANCE_COUNT > 0u)
/* LPI2C0 master handler named in startup code. */
ISR(LPI2C0_Master_IRQHandler);

/* LPI2C0 slave handler named in startup code. */
ISR(LPI2C0_Slave_IRQHandler);

#if (LPI2C_INSTANCE_COUNT == 2u)
/* LPI2C1 master handler named in startup code. */
ISR(LPI2C1_Master_IRQHandler);

/* LPI2C1 slave handler named in startup code. */
ISR(LPI2C1_Slave_IRQHandler);

#endif /* LPI2C_INSTANCE_COUNT == 2u */
#endif /* LPI2C_INSTANCE_COUNT > 0u */

#endif /* LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* LPI2C_IP_IRQ_H */

