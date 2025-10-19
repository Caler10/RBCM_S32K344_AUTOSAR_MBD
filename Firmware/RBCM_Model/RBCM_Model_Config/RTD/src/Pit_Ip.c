/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/**
*   @file       Pit_Ip.c
*
*   @addtogroup pit_ip Pit IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pit_Ip.h"

#if (defined(PIT_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PIT_IP_ENABLE_USER_MODE_SUPPORT))
   #define USER_MODE_REG_PROT_ENABLED   PIT_IP_ENABLE_USER_MODE_SUPPORT
   #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PIT_IP_VENDOR_ID_C                    43
#define PIT_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define PIT_IP_AR_RELEASE_MINOR_VERSION_C     7
#define PIT_IP_AR_RELEASE_REVISION_VERSION_C  0
#define PIT_IP_SW_MAJOR_VERSION_C             5
#define PIT_IP_SW_MINOR_VERSION_C             0
#define PIT_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (PIT_IP_VENDOR_ID != PIT_IP_VENDOR_ID_C)
    #error "Pit_Ip.h and Pit_Ip.c have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((PIT_IP_AR_RELEASE_MAJOR_VERSION != PIT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (PIT_IP_AR_RELEASE_MINOR_VERSION != PIT_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (PIT_IP_AR_RELEASE_REVISION_VERSION != PIT_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Pit_Ip.h and Pit_Ip.c are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((PIT_IP_SW_MAJOR_VERSION != PIT_IP_SW_MAJOR_VERSION_C) || \
     (PIT_IP_SW_MINOR_VERSION != PIT_IP_SW_MINOR_VERSION_C) || \
     (PIT_IP_SW_PATCH_VERSION != PIT_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Pit_Ip.h and Pit_Ip.c are different"
#endif

#if (defined(PIT_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PIT_IP_ENABLE_USER_MODE_SUPPORT))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != PIT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != PIT_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and Pit_Ip.c are different"
    #endif
#endif
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
#ifndef MCAL_PIT_REG_PROT_AVAILABLE
    #define MCAL_PIT_REG_PROT_AVAILABLE STD_OFF
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (PIT_IP_USED == STD_ON)

#if (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
#define GPT_START_SEC_VAR_CLEARED_BOOLEAN
#include "Gpt_MemMap.h"
/**
* @brief            Pit_Ip_bIsChangedTimeout
* @details          Local variable used to check that whether this channel called ChangeNextTimeout.
*/
static boolean Pit_Ip_bIsChangedTimeout;
#define GPT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Gpt_MemMap.h"
#endif /* (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) */
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
#define GPT_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Gpt_MemMap.h"
/**
* @brief            Pit_Ip_u32OldTargetValue
* @details          Local variable used to store the previous target time value after call ChangeNextTimeout.
*/
uint32 Pit_Ip_u32OldTargetValue = 0UL;
#define GPT_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Gpt_MemMap.h"
#endif /* (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) */

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (defined(CRS_FSS_AND_RTU_BASE_ADDR_OF_PIT_REGISTERS_CONCATENATED) && (CRS_FSS_AND_RTU_BASE_ADDR_OF_PIT_REGISTERS_CONCATENATED == STD_ON))
#define IP_PIT_BASE_PTRS_CONCATENATED   { IP_CRS__PIT_0, IP_CRS__PIT_1, IP_FSS__COSS_PIT_0, IP_FSS__COSS_PIT_1, IP_FSS__COSS_PIT_2, IP_FSS__COSS_PIT_3, IP_FSS__COSS_PIT_4, IP_FSS__COSS_PIT_5, IP_FSS__COSS_PIT_6, IP_FSS__HKI_PIT, IP_FSS__PIT, (PIT_Type *)IP_RTU0__RTU_PIT0_BASE, (PIT_Type *)IP_RTU0__RTU_PIT1_BASE, (PIT_Type *)IP_RTU1__RTU_PIT0_BASE, (PIT_Type *)IP_RTU1__RTU_PIT1_BASE, (PIT_Type *)IP_RTU2__RTU_PIT0_BASE, (PIT_Type *)IP_RTU2__RTU_PIT1_BASE, (PIT_Type *)IP_RTU3__RTU_PIT0_BASE, (PIT_Type *)IP_RTU3__RTU_PIT1_BASE }
/** @brief Table of base addresses for PIT instances. */
static PIT_Type * const pitBase[GPT_PIT_INSTANCE_COUNT] = IP_PIT_BASE_PTRS_CONCATENATED;
#elif (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
#define IP_PIT_BASE_PTRS_ALT               {IP_PIT_0, NULL_PTR, IP_PIT_2}
/** @brief Table of base addresses for PIT instances. */
static PIT_Type * const pitBase[GPT_PIT_INSTANCE_COUNT] = IP_PIT_BASE_PTRS_ALT;
#else
/** @brief Table of base addresses for PIT instances. */
static PIT_Type * const pitBase[GPT_PIT_INSTANCE_COUNT] = IP_PIT_BASE_PTRS;
#endif

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Gpt_MemMap.h"
#if (   defined(PIT_0_ISR_USED) || defined(PIT_1_ISR_USED) || defined(PIT_2_ISR_USED) || defined(PIT_4_ISR_USED) || defined(PIT_5_ISR_USED) || \
        defined(CE_PIT_0_CH_0_ISR_USED) || defined(CE_PIT_0_CH_1_ISR_USED) || \
        defined(CE_PIT_0_CH_2_ISR_USED) || defined(CE_PIT_0_CH_3_ISR_USED) || \
        defined(CE_PIT_1_CH_0_ISR_USED) || defined(CE_PIT_1_CH_1_ISR_USED) || \
        defined(CE_PIT_1_CH_2_ISR_USED) || defined(CE_PIT_1_CH_3_ISR_USED) || \
        defined(CE_PIT_2_CH_0_ISR_USED) || defined(CE_PIT_2_CH_1_ISR_USED) || \
        defined(CE_PIT_2_CH_2_ISR_USED) || defined(CE_PIT_2_CH_3_ISR_USED) || \
        defined(CE_PIT_3_CH_0_ISR_USED) || defined(CE_PIT_3_CH_1_ISR_USED) || \
        defined(CE_PIT_3_CH_2_ISR_USED) || defined(CE_PIT_3_CH_3_ISR_USED) || \
        defined(CE_PIT_4_CH_0_ISR_USED) || defined(CE_PIT_4_CH_1_ISR_USED) || \
        defined(CE_PIT_4_CH_2_ISR_USED) || defined(CE_PIT_4_CH_3_ISR_USED) || \
        defined(CE_PIT_5_CH_0_ISR_USED) || defined(CE_PIT_5_CH_1_ISR_USED) || \
        defined(CE_PIT_5_CH_2_ISR_USED) || defined(CE_PIT_5_CH_3_ISR_USED) || \
        defined(RTU0_PIT_0_ISR_USED) || defined(RTU0_PIT_1_ISR_USED) || \
        defined(RTU1_PIT_0_ISR_USED) || defined(RTU1_PIT_1_ISR_USED) || \
        defined(RTU2_PIT_0_ISR_USED) || defined(RTU2_PIT_1_ISR_USED) || \
        defined(RTU3_PIT_0_ISR_USED) || defined(RTU3_PIT_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_0_ISR_USED) || defined(CRS_PIT_0_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_1_ISR_USED) || defined(CRS_PIT_0_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_2_ISR_USED) || defined(CRS_PIT_0_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_3_ISR_USED) || defined(CRS_PIT_0_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_0_ISR_USED) || defined(CRS_PIT_1_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_1_ISR_USED) || defined(CRS_PIT_1_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_2_ISR_USED) || defined(CRS_PIT_1_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_3_ISR_USED) || defined(CRS_PIT_1_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_2_ISR_USED) || defined(FSS_COSS_PIT_3_ISR_USED) || \
        defined(FSS_COSS_PIT_4_ISR_USED) || defined(FSS_COSS_PIT_5_ISR_USED) || \
        defined(FSS_COSS_PIT_6_ISR_USED) || \
        defined(FSS_HKI_PIT_0_ISR_USED) || \
        defined(FSS_PIT_0_CH_0_ISR_USED) || defined(FSS_PIT_0_CH_1_ISR_USED) || defined(FSS_PIT_0_CH_2_ISR_USED) )
/** @brief Global array variable used to channel state for process common interrupt */
static Pit_Ip_State Pit_Ip_u32ChState[GPT_PIT_INSTANCE_COUNT][PIT_CHANNEL_COUNT] =  {
                                                                                    {
                                                                                        {
                                                                                            (boolean)FALSE,
                                                                                            NULL_PTR,
                                                                                            0U,
                                                                                            PIT_IP_CH_MODE_CONTINUOUS
                                                                                        }
                                                                                    }
                                                                                };
#endif
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if ((STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS))

#if defined(PIT_0_ISR_USED)
ISR(PIT_0_ISR);
#endif
#if defined(PIT_1_ISR_USED)
ISR(PIT_1_ISR);
#endif
#if defined(PIT_4_ISR_USED)
ISR(PIT_4_ISR);
#endif
#if defined(PIT_5_ISR_USED)
ISR(PIT_5_ISR);
#endif

#if (STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS)

#if defined(CE_PIT_0_CH_0_ISR_USED)
ISR(CE_PIT_0_CH_0_ISR);
#endif

#if defined(CE_PIT_0_CH_1_ISR_USED)
ISR(CE_PIT_0_CH_1_ISR);
#endif

#if defined(CE_PIT_0_CH_2_ISR_USED)
ISR(CE_PIT_0_CH_2_ISR);
#endif

#if defined(CE_PIT_0_CH_3_ISR_USED)
ISR(CE_PIT_0_CH_3_ISR);
#endif

#if defined(CE_PIT_1_CH_0_ISR_USED)
ISR(CE_PIT_1_CH_0_ISR);
#endif

#if defined(CE_PIT_1_CH_1_ISR_USED)
ISR(CE_PIT_1_CH_1_ISR);
#endif

#if defined(CE_PIT_1_CH_2_ISR_USED)
ISR(CE_PIT_1_CH_2_ISR);
#endif

#if defined(CE_PIT_1_CH_3_ISR_USED)
ISR(CE_PIT_1_CH_3_ISR);
#endif

#if defined(CE_PIT_2_CH_0_ISR_USED)
ISR(CE_PIT_2_CH_0_ISR);
#endif

#if defined(CE_PIT_2_CH_1_ISR_USED)
ISR(CE_PIT_2_CH_1_ISR);
#endif

#if defined(CE_PIT_2_CH_2_ISR_USED)
ISR(CE_PIT_2_CH_2_ISR);
#endif

#if defined(CE_PIT_2_CH_3_ISR_USED)
ISR(CE_PIT_2_CH_3_ISR);
#endif

#if defined(CE_PIT_3_CH_0_ISR_USED)
ISR(CE_PIT_3_CH_0_ISR);
#endif

#if defined(CE_PIT_3_CH_1_ISR_USED)
ISR(CE_PIT_3_CH_1_ISR);
#endif

#if defined(CE_PIT_3_CH_2_ISR_USED)
ISR(CE_PIT_3_CH_2_ISR);
#endif

#if defined(CE_PIT_3_CH_3_ISR_USED)
ISR(CE_PIT_3_CH_3_ISR);
#endif

#if defined(CE_PIT_4_CH_0_ISR_USED)
ISR(CE_PIT_4_CH_0_ISR);
#endif

#if defined(CE_PIT_4_CH_1_ISR_USED)
ISR(CE_PIT_4_CH_1_ISR);
#endif

#if defined(CE_PIT_4_CH_2_ISR_USED)
ISR(CE_PIT_4_CH_2_ISR);
#endif

#if defined(CE_PIT_4_CH_3_ISR_USED)
ISR(CE_PIT_4_CH_3_ISR);
#endif

#if defined(CE_PIT_5_CH_0_ISR_USED)
ISR(CE_PIT_5_CH_0_ISR);
#endif

#if defined(CE_PIT_5_CH_1_ISR_USED)
ISR(CE_PIT_5_CH_1_ISR);
#endif

#if defined(CE_PIT_5_CH_2_ISR_USED)
ISR(CE_PIT_5_CH_2_ISR);
#endif

#if defined(CE_PIT_5_CH_3_ISR_USED)
ISR(CE_PIT_5_CH_3_ISR);
#endif

#if defined(FSS_HKI_PIT_0_ISR_USED)
ISR(FSS_HKI_PIT_0_ISR);
#endif

#if defined(RTU0_PIT_0_ISR_USED)
ISR(RTU0_PIT_0_ISR);
#endif
#if defined(RTU0_PIT_1_ISR_USED)
ISR(RTU0_PIT_1_ISR);
#endif
#if defined(RTU1_PIT_0_ISR_USED)
ISR(RTU1_PIT_0_ISR);
#endif
#if defined(RTU1_PIT_1_ISR_USED)
ISR(RTU1_PIT_1_ISR);
#endif
#if defined(RTU2_PIT_0_ISR_USED)
ISR(RTU2_PIT_0_ISR);
#endif
#if defined(RTU2_PIT_1_ISR_USED)
ISR(RTU2_PIT_1_ISR);
#endif
#if defined(RTU3_PIT_0_ISR_USED)
ISR(RTU3_PIT_0_ISR);
#endif
#if defined(RTU3_PIT_1_ISR_USED)
ISR(RTU3_PIT_1_ISR);
#endif

#if defined(CRS_PIT_0_CH_0_ISR_USED)
ISR(CRS_PIT_0_CH_0_ISR);
#endif
#if defined(CRS_PIT_0_CH_1_ISR_USED)
ISR(CRS_PIT_0_CH_1_ISR);
#endif
#if defined(CRS_PIT_0_CH_2_ISR_USED)
ISR(CRS_PIT_0_CH_2_ISR);
#endif
#if defined(CRS_PIT_0_CH_3_ISR_USED)
ISR(CRS_PIT_0_CH_3_ISR);
#endif

#if defined(CRS_PIT_1_CH_0_ISR_USED)
ISR(CRS_PIT_1_CH_0_ISR);
#endif
#if defined(CRS_PIT_1_CH_1_ISR_USED)
ISR(CRS_PIT_1_CH_1_ISR);
#endif
#if defined(CRS_PIT_1_CH_2_ISR_USED)
ISR(CRS_PIT_1_CH_2_ISR);
#endif
#if defined(CRS_PIT_1_CH_3_ISR_USED)
ISR(CRS_PIT_1_CH_3_ISR);
#endif

#if defined(FSS_COSS_PIT_0_CH_0_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_0_ISR);
#endif
#if defined(FSS_COSS_PIT_0_CH_1_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_1_ISR);
#endif
#if defined(FSS_COSS_PIT_0_CH_2_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_2_ISR);
#endif
#if defined(FSS_COSS_PIT_0_CH_3_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_3_ISR);
#endif

#if defined(FSS_COSS_PIT_1_CH_0_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_0_ISR);
#endif
#if defined(FSS_COSS_PIT_1_CH_1_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_1_ISR);
#endif
#if defined(FSS_COSS_PIT_1_CH_2_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_2_ISR);
#endif
#if defined(FSS_COSS_PIT_1_CH_3_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_3_ISR);
#endif

#if defined(FSS_COSS_PIT_2_ISR_USED)
ISR(FSS_COSS_PIT_2_ISR);
#endif

#if defined(FSS_COSS_PIT_3_ISR_USED)
ISR(FSS_COSS_PIT_3_ISR);
#endif

#if defined(FSS_COSS_PIT_4_ISR_USED)
ISR(FSS_COSS_PIT_4_ISR);
#endif

#if defined(FSS_COSS_PIT_5_ISR_USED)
ISR(FSS_COSS_PIT_5_ISR);
#endif

#if defined(FSS_COSS_PIT_6_ISR_USED)
ISR(FSS_COSS_PIT_6_ISR);
#endif

#if defined(FSS_PIT_0_CH_0_ISR_USED)
ISR(FSS_PIT_0_CH_0_ISR);
#endif
#if defined(FSS_PIT_0_CH_1_ISR_USED)
ISR(FSS_PIT_0_CH_1_ISR);
#endif
#if defined(FSS_PIT_0_CH_2_ISR_USED)
ISR(FSS_PIT_0_CH_2_ISR);
#endif

#endif /* STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS */

#if (STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT)

#if defined(PIT_2_ISR_USED)
ISR(PIT_2_ISR);
#endif
#if defined(PIT_3_ISR_USED)
ISR(PIT_3_ISR);
#endif

#endif /* STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT */

#endif /* (STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS) */

#if (   defined(PIT_0_ISR_USED) || defined(PIT_1_ISR_USED) || defined(PIT_2_ISR_USED) || defined(PIT_4_ISR_USED) || defined(PIT_5_ISR_USED) || \
        defined(CE_PIT_0_CH_0_ISR_USED) || defined(CE_PIT_0_CH_1_ISR_USED) || \
        defined(CE_PIT_0_CH_2_ISR_USED) || defined(CE_PIT_0_CH_3_ISR_USED) || \
        defined(CE_PIT_1_CH_0_ISR_USED) || defined(CE_PIT_1_CH_1_ISR_USED) || \
        defined(CE_PIT_1_CH_2_ISR_USED) || defined(CE_PIT_1_CH_3_ISR_USED) || \
        defined(CE_PIT_2_CH_0_ISR_USED) || defined(CE_PIT_2_CH_1_ISR_USED) || \
        defined(CE_PIT_2_CH_2_ISR_USED) || defined(CE_PIT_2_CH_3_ISR_USED) || \
        defined(CE_PIT_3_CH_0_ISR_USED) || defined(CE_PIT_3_CH_1_ISR_USED) || \
        defined(CE_PIT_3_CH_2_ISR_USED) || defined(CE_PIT_3_CH_3_ISR_USED) || \
        defined(CE_PIT_4_CH_0_ISR_USED) || defined(CE_PIT_4_CH_1_ISR_USED) || \
        defined(CE_PIT_4_CH_2_ISR_USED) || defined(CE_PIT_4_CH_3_ISR_USED) || \
        defined(CE_PIT_5_CH_0_ISR_USED) || defined(CE_PIT_5_CH_1_ISR_USED) || \
        defined(CE_PIT_5_CH_2_ISR_USED) || defined(CE_PIT_5_CH_3_ISR_USED) || \
        defined(RTU0_PIT_0_ISR_USED) || defined(RTU0_PIT_1_ISR_USED) || \
        defined(RTU1_PIT_0_ISR_USED) || defined(RTU1_PIT_1_ISR_USED) || \
        defined(RTU2_PIT_0_ISR_USED) || defined(RTU2_PIT_1_ISR_USED) || \
        defined(RTU3_PIT_0_ISR_USED) || defined(RTU3_PIT_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_0_ISR_USED) || defined(CRS_PIT_0_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_1_ISR_USED) || defined(CRS_PIT_0_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_2_ISR_USED) || defined(CRS_PIT_0_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_3_ISR_USED) || defined(CRS_PIT_0_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_0_ISR_USED) || defined(CRS_PIT_1_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_1_ISR_USED) || defined(CRS_PIT_1_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_2_ISR_USED) || defined(CRS_PIT_1_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_3_ISR_USED) || defined(CRS_PIT_1_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_2_ISR_USED) || defined(FSS_COSS_PIT_3_ISR_USED) || \
        defined(FSS_COSS_PIT_4_ISR_USED) || defined(FSS_COSS_PIT_5_ISR_USED) || \
        defined(FSS_COSS_PIT_6_ISR_USED) || \
        defined(FSS_HKI_PIT_0_ISR_USED) || \
        defined(FSS_PIT_0_CH_0_ISR_USED) || defined(FSS_PIT_0_CH_1_ISR_USED) || defined(FSS_PIT_0_CH_2_ISR_USED) )
static void Pit_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel);
static inline boolean Pit_Ip_GetInterruptEnableFlag(uint8 instance, uint8 channel);
#endif
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
static inline void Pit_Ip_EnableModule(uint8 instance, uint8 timerType);
#endif
static inline void Pit_Ip_Reset(uint8 instance, uint8 channelNum, boolean available, boolean bitExists);
static inline void Pit_Ip_EnableTimer(uint8 instance, uint8 channel, boolean enable);
static inline void Pit_Ip_SetDebugMode(uint8 instance, boolean stopRun);
static inline void Pit_Ip_SetChainMode(uint8 instance, uint8 channel, boolean enable);
static inline boolean Pit_Ip_IsChannelRunning(uint8 instance, uint8 channel);
static inline void Pit_Ip_SetCounterValue(uint8 instance, uint8 channel, uint32 value);
static inline uint32 Pit_Ip_GetCounterValue(uint8 instance, uint8 channel);
static inline void Pit_Ip_SetEnableInterruptFlag(uint8 instance, uint8 channel, boolean enable);

static inline void Pit_Ip_ClearInterruptStatusFlag(uint8 instance, uint8 channel);
static inline uint32 Pit_Ip_GetUpperLifetimerValue(uint8 instance);
static inline uint32 Pit_Ip_GetLowerLifetimerValue(uint8 instance);
#if (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
static inline Pit_Ip_StatusType Pit_Ip_ValidateInstCall(uint8 instance);
#endif
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
static void Pit_Ip_StartTimeout(uint32 *startTimeOut,
                         uint32 *elapsedTimeOut,
                         uint32 *timeoutTicksOut,
                         uint32 timeoutUs);

static boolean Pit_Ip_TimeoutExpired(   uint32 *startTimeInOut,
                                        uint32 *elapsedTimeInOut,
                                        uint32 timeoutTicks );
static inline uint32 Pit_Ip_GetRtiStatusReg(uint8 instance);
#endif

#if (   (defined(PIT_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PIT_IP_ENABLE_USER_MODE_SUPPORT)) && \
        (   (defined(MCAL_PIT_REG_PROT_AVAILABLE) && (STD_ON == MCAL_PIT_REG_PROT_AVAILABLE)) || \
            (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))))
    void Pit_Ip_SetUserAccessAllowed(uint32 PitBaseAddr);
#endif

#if (   (defined(PIT_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PIT_IP_ENABLE_USER_MODE_SUPPORT)) && \
        (   (defined(MCAL_PIT_REG_PROT_AVAILABLE) && (STD_ON == MCAL_PIT_REG_PROT_AVAILABLE)) || \
            (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))))

    #define Call_Pit_Ip_SetUserAccessAllowed(PitBaseAddr) OsIf_Trusted_Call1param(Pit_Ip_SetUserAccessAllowed,(PitBaseAddr))

#else
    #define Call_Pit_Ip_SetUserAccessAllowed(PitBaseAddr)
#endif


#if (   (defined(PIT_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PIT_IP_ENABLE_USER_MODE_SUPPORT)) && \
        (   (defined(MCAL_PIT_REG_PROT_AVAILABLE) && (STD_ON == MCAL_PIT_REG_PROT_AVAILABLE)) || \
            (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))))
/**
* @brief        Enables PIT registers writing in User Mode by configuring REG_PROT
* @details      Sets the UAA (User Access Allowed) bit of the PIT IP allowing PIT registers writing in User Mode
*
* @param[in]    none
*
* @return       none
*
* @pre          Should be executed in supervisor mode
* @post         none
*/
void Pit_Ip_SetUserAccessAllowed (uint32 PitBaseAddr)
{
#if (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))
    SET_USER_ACCESS_ALLOWED(PitBaseAddr, PIT_AE_PROT_MEM_U32);
#else
    SET_USER_ACCESS_ALLOWED(PitBaseAddr, PIT_PROT_MEM_U32);
#endif
}
#endif /* MCAL_PIT_REG_PROT_AVAILABLE && PIT_IP_ENABLE_USER_MODE_SUPPORT */
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief         Pit_Ip_GetLoadValue
* @details       Support get load value PIT
*                This register is intended for Timer Load Value
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
*
* @return        periodValue
* @pre           The driver needs to be initialized.
*/
uint32 Pit_Ip_GetLoadValue(uint8 instance, uint8 channel)
{
    uint32 periodValue = 0U;

#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if (RTI == channel)
    {
       periodValue = pitBase[instance]->RTI_LDVAL;
    }
    else
    {
#endif
       periodValue = pitBase[instance]->TIMER[channel].LDVAL;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    }
#endif

    return periodValue;
}

#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
/**
* @brief         Pit_Ip_EnableModule
* @details       Support Pit enable module.
*                This register is intended for PIT Module Control.
*
* @param[in]     instance      PIT hw instance number
* @param[in]     channel       PIT hw instance number
* @param[in]     enable        TRUE/FALSE
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable chain mode.
*/
static inline void Pit_Ip_EnableModule(uint8 instance, uint8 timerType)
{
    if (0U == timerType)
    {
         pitBase[instance]->MCR &= ~PIT_MCR_MDIS_MASK;
    }
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    else
    {
        pitBase[instance]->MCR &= ~PIT_MCR_MDIS_RTI_MASK;
    }
#endif

}
#endif

/**
* @brief         Pit_Ip_EnableTimer
* @details       Support enable timer.
*                This register is intended for Timer Control
*
* @param[in]     instance      PIT hw instance number
* @param[in]     channel       PIT hw instance number
* @param[in]     enable        TRUE/FALSE
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable chain mode.
*/
static inline void Pit_Ip_EnableTimer(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    {
        if (TRUE == enable)
        {
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            if (RTI == channel)
            {
                pitBase[instance]->RTI_TCTRL |= PIT_RTI_TCTRL_TEN_MASK;
            }
            else
            {
#endif
                pitBase[instance]->TIMER[channel].TCTRL |= PIT_TCTRL_TEN_MASK;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            }
#endif
        }
        else
        {
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            if (RTI == channel)
            {
                pitBase[instance]->RTI_TCTRL &= ~PIT_RTI_TCTRL_TEN_MASK;
            }
            else
            {
#endif
                pitBase[instance]->TIMER[channel].TCTRL &= ~PIT_TCTRL_TEN_MASK;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            }
#endif
        }
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
/**
* @brief         Pit_Ip_SetDebugMode
* @details       This register enables or disables the PIT timer clocks and controls the timers
*                when the PIT enters the Debug mode.
*
* @param[in]     instance      PIT hw instance number
* @param[in]     channel       PIT hw instance number
* @param[in]     stopRun
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable debug mode.
*/
static inline void Pit_Ip_SetDebugMode(uint8 instance, boolean stopRun)
{
    if (TRUE == stopRun)
    {
        pitBase[instance]->MCR |= PIT_MCR_FRZ_MASK;
    }
    else
    {
        pitBase[instance]->MCR &= ~PIT_MCR_FRZ_MASK;
    }
}
/**
* @brief         Pit_Ip_SetChainMode
* @details       Support chain mode
*                This register is intended for Timer Control
*
* @param[in]     instance      PIT hw instance number
* @param[in]     channel       PIT hw instance number
* @param[in]     enable        TRUE/FALSE
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable chain mode.
*/
static inline void Pit_Ip_SetChainMode(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01();
    {
        if ((TRUE == enable) && (channel > 0U))
        {
            pitBase[instance]->TIMER[channel].TCTRL |= PIT_TCTRL_CHN_MASK;
        }
        else
        {
            pitBase[instance]->TIMER[channel].TCTRL &= ~PIT_TCTRL_CHN_MASK;
        }
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01();
}
/**
* @brief         Pit_Ip_Reset
* @details       Support reset
*                This register is intended for PIT Module Control
*
* @param[in]     instance      PIT hw instance number
* @param[in]     channelNum    PIT hw channel number
*
*
* @return        void
* @pre           The driver needs to be initialized.
*/
static inline void Pit_Ip_Reset(uint8 instance, uint8 channelNum, boolean available, boolean bitExists)
{
    uint32 mask = 0U;
    uint8 channelIndex = channelNum;

    if(TRUE == available)
    {
        channelIndex = channelIndex - 1U;
#ifdef PIT_IP_RTI_CHANNEL_EXISTS
        pitBase[instance]->RTI_TCTRL = PIT_RTI_TCTRL_TEN(0U) | PIT_RTI_TCTRL_TIE(0U);
        pitBase[instance]->RTI_LDVAL = PIT_RTI_LDVAL_TSV(0U);
        pitBase[instance]->RTI_TFLG = PIT_RTI_TFLG_TIF_MASK;
        if(FALSE == bitExists)
        {
            mask = PIT_MCR_FRZ(0U) | PIT_MCR_MDIS_RTI(1U);
        }
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
        else
        {
            mask = PIT_MCR_MDIS(1U) | PIT_MCR_FRZ(0U) | PIT_MCR_MDIS_RTI(1U);
        }
#endif
#endif
    }
    else
    {
        if(FALSE == bitExists)
        {
            mask = PIT_MCR_FRZ(0U);

        }
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
        else
        {
             mask = PIT_MCR_MDIS(1U) | PIT_MCR_FRZ(0U);
        }
#endif
    }

    for (uint8 i = 0U; i < channelIndex; i++)
    {
        pitBase[instance]->TIMER[i].TCTRL = PIT_TCTRL_TEN(0U) | PIT_TCTRL_TIE(0U) | PIT_TCTRL_CHN(0U);
        pitBase[instance]->TIMER[i].LDVAL = PIT_LDVAL_TSV(0U);
        pitBase[instance]->TIMER[i].TFLG = PIT_TFLG_TIF_MASK;
#if (   defined(PIT_0_ISR_USED) || defined(PIT_1_ISR_USED) || defined(PIT_2_ISR_USED) || defined(PIT_4_ISR_USED) || defined(PIT_5_ISR_USED) || \
        defined(CE_PIT_0_CH_0_ISR_USED) || defined(CE_PIT_0_CH_1_ISR_USED) || \
        defined(CE_PIT_0_CH_2_ISR_USED) || defined(CE_PIT_0_CH_3_ISR_USED) || \
        defined(CE_PIT_1_CH_0_ISR_USED) || defined(CE_PIT_1_CH_1_ISR_USED) || \
        defined(CE_PIT_1_CH_2_ISR_USED) || defined(CE_PIT_1_CH_3_ISR_USED) || \
        defined(CE_PIT_2_CH_0_ISR_USED) || defined(CE_PIT_2_CH_1_ISR_USED) || \
        defined(CE_PIT_2_CH_2_ISR_USED) || defined(CE_PIT_2_CH_3_ISR_USED) || \
        defined(CE_PIT_3_CH_0_ISR_USED) || defined(CE_PIT_3_CH_1_ISR_USED) || \
        defined(CE_PIT_3_CH_2_ISR_USED) || defined(CE_PIT_3_CH_3_ISR_USED) || \
        defined(CE_PIT_4_CH_0_ISR_USED) || defined(CE_PIT_4_CH_1_ISR_USED) || \
        defined(CE_PIT_4_CH_2_ISR_USED) || defined(CE_PIT_4_CH_3_ISR_USED) || \
        defined(CE_PIT_5_CH_0_ISR_USED) || defined(CE_PIT_5_CH_1_ISR_USED) || \
        defined(CE_PIT_5_CH_2_ISR_USED) || defined(CE_PIT_5_CH_3_ISR_USED) || \
        defined(RTU0_PIT_0_ISR_USED) || defined(RTU0_PIT_1_ISR_USED) || \
        defined(RTU1_PIT_0_ISR_USED) || defined(RTU1_PIT_1_ISR_USED) || \
        defined(RTU2_PIT_0_ISR_USED) || defined(RTU2_PIT_1_ISR_USED) || \
        defined(RTU3_PIT_0_ISR_USED) || defined(RTU3_PIT_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_0_ISR_USED) || defined(CRS_PIT_0_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_1_ISR_USED) || defined(CRS_PIT_0_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_2_ISR_USED) || defined(CRS_PIT_0_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_3_ISR_USED) || defined(CRS_PIT_0_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_0_ISR_USED) || defined(CRS_PIT_1_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_1_ISR_USED) || defined(CRS_PIT_1_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_2_ISR_USED) || defined(CRS_PIT_1_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_3_ISR_USED) || defined(CRS_PIT_1_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_2_ISR_USED) || defined(FSS_COSS_PIT_3_ISR_USED) || \
        defined(FSS_COSS_PIT_4_ISR_USED) || defined(FSS_COSS_PIT_5_ISR_USED) || \
        defined(FSS_COSS_PIT_6_ISR_USED) || \
        defined(FSS_HKI_PIT_0_ISR_USED) || \
        defined(FSS_PIT_0_CH_0_ISR_USED) || defined(FSS_PIT_0_CH_1_ISR_USED) || defined(FSS_PIT_0_CH_2_ISR_USED) )
        /* Set state variab values to default value */
        Pit_Ip_u32ChState[instance][i].chInit = FALSE;
        Pit_Ip_u32ChState[instance][i].callback = NULL_PTR;
        Pit_Ip_u32ChState[instance][i].callbackParam = 0;
        Pit_Ip_u32ChState[instance][i].channelMode = PIT_IP_CH_MODE_CONTINUOUS;
#endif
    }
    pitBase[instance]->MCR = mask;
}

/**
* @brief         Pit_Ip_IsChannelRunning
* @details       Support enable/disable Timer Enable
*                This register is intended for Timer Control Register
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
*
*
* @return        isRunning
* @pre           The driver needs to be initialized.
*
*/
static inline boolean Pit_Ip_IsChannelRunning(uint8 instance, uint8 channel)
{
    boolean isRunning = FALSE;

#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if (RTI == channel)
    {
        isRunning = ((pitBase[instance]->RTI_TCTRL & PIT_RTI_TCTRL_TEN_MASK) == PIT_RTI_TCTRL_TEN_MASK) ? TRUE : FALSE;
    }
    else
    {
#endif
        isRunning = ((pitBase[instance]->TIMER[channel].TCTRL & PIT_TCTRL_TEN_MASK) == PIT_TCTRL_TEN_MASK) ? TRUE : FALSE;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    }
#endif

    return isRunning;
}
/**
* @brief         Pit_Ip_SetCounterValue
* @details       Support set counter value PIT
*                This register is intended for Timer Load Value
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
* @param[in]     value        Value counter
*
* @return        void
* @pre           The driver needs to be initialized.
*/
static inline void Pit_Ip_SetCounterValue(uint8 instance, uint8 channel, uint32 value)
{

#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if (RTI == channel)
    {
        pitBase[instance]->RTI_LDVAL = value;
    }
    else
    {
#endif
        pitBase[instance]->TIMER[channel].LDVAL = value;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    }
#endif
}

/**
* @brief         Pit_Ip_GetCounterValue
* @details       Support get counter value PIT
*                This register is intended for Current Timer Value
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
*
* @return        counterValue
* @pre           The driver needs to be initialized.
*/
static inline uint32 Pit_Ip_GetCounterValue(uint8 instance, uint8 channel)
{
    uint32 counterValue = 0U;

#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if (RTI == channel)
    {
        counterValue = pitBase[instance]->RTI_CVAL;
    }
    else
    {
#endif
        counterValue = pitBase[instance]->TIMER[channel].CVAL;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    }
#endif

    return counterValue;
}
/**
* @brief         Pit_Ip_SetEnableInterruptFlag
* @details       Support PIT clear interrupt flags
*                This register is intended for Timer Interrupt Flag
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
* @param[in]     enable       Enable interrupt
* @return        void
* @pre           The driver needs to be initialized.
*/
static inline void Pit_Ip_SetEnableInterruptFlag(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02();
    {
        if (TRUE == enable)
        {
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            if (RTI == channel)
            {
                pitBase[instance]->RTI_TCTRL |= PIT_RTI_TCTRL_TIE_MASK;
            }
            else
            {
#endif
                pitBase[instance]->TIMER[channel].TCTRL |= PIT_TCTRL_TIE_MASK;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            }
#endif
        }
        else
        {
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            if (RTI == channel)
            {
                pitBase[instance]->RTI_TCTRL &= ~PIT_RTI_TCTRL_TIE_MASK;
            }
            else
            {
#endif
                pitBase[instance]->TIMER[channel].TCTRL &= ~PIT_TCTRL_TIE_MASK;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
            }
#endif
        }
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02();
}

/*!
 * @brief   Clear the Interrupt Status Flag of PIT peripheral timer channel.
 * @details Support clear of PIT interrupt status flag
 *          This register is intended for Timer interrupt status flag
 *
 * @param[in] instance - Instance number of PIT module
 * @param[in] channel - The channel in the PIT instance
 *
 * @return  void
 * @pre The driver needs to be initialized.
 *
 */
static inline void Pit_Ip_ClearInterruptStatusFlag(uint8 instance, uint8 channel)
{
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if (RTI == channel)
    {
        pitBase[instance]->RTI_TFLG |= PIT_RTI_TFLG_TIF_MASK;
    }
    else
    {
#endif
        pitBase[instance]->TIMER[channel].TFLG |= PIT_TFLG_TIF_MASK;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    }
#endif
}

/**
* @brief         Pit_Ip_GetUpperLifetimerValue
* @details       Support Get Upper life time value
*                This register is intended for applications that chain timer.
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
* @return        upperValue
* @pre           The driver needs to be initialized.
*/
static inline uint32 Pit_Ip_GetUpperLifetimerValue(uint8 instance)
{
    uint32 upperValue = 0U;
    upperValue = pitBase[instance]->LTMR64H;
    return upperValue;
}
/**
* @brief         Pit_Ip_GetLowerLifetimerValue
* @details       Support Get lower life time value
*                This register is intended for applications that chain timer.
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
* @return        lowerValue
* @pre           The driver needs to be initialized.
*/
static inline uint32 Pit_Ip_GetLowerLifetimerValue(uint8 instance)
{
    uint32 lowerValue = 0U;

    lowerValue = pitBase[instance]->LTMR64L;

    return lowerValue;
}
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
/**
* @brief         Pit_Ip_StartTimeout
* @details       Pit_Ip_StartTimeout
*
*
* @param[in]     *startTimeOut
* @param[in]     *elapsedTimeOut
* @param[in]     timeoutUs
* @return        void
* @pre           The driver needs to be initialized.
*/
static void Pit_Ip_StartTimeout(uint32 *startTimeOut,
                         uint32 *elapsedTimeOut,
                         uint32 *timeoutTicksOut,
                         uint32 timeoutUs)
{
    *startTimeOut    = OsIf_GetCounter(PIT_IP_TIMEOUT_TYPE);
    *elapsedTimeOut  = 0U;
    *timeoutTicksOut = OsIf_MicrosToTicks(timeoutUs, PIT_IP_TIMEOUT_TYPE);
}

/**
* @brief         Pit_Ip_TimeoutExpired
* @details       Pit_Ip_TimeoutExpired
*
*
* @param[in]     *startTimeInOut
* @param[in]     *elapsedTimeInOut
* @param[in]     timeoutTicks
* @return        TRUE/FALSE
* @pre           The driver needs to be initialized.
*/
static boolean Pit_Ip_TimeoutExpired(   uint32 *startTimeInOut,
                                        uint32 *elapsedTimeInOut,
                                        uint32 timeoutTicks )
{
    uint64 elapsedTime = OsIf_GetElapsed(startTimeInOut, PIT_IP_TIMEOUT_TYPE);
    boolean returnFlag = (elapsedTime >= timeoutTicks) ? TRUE : FALSE;

    elapsedTime += *elapsedTimeInOut;
    *elapsedTimeInOut = (uint32)elapsedTime;

    return returnFlag;
}
/**
* @brief         Pit_Ip_GetRtiStatusReg
* @details       Support gives the status of the new value loaded
*                This register gives the status of the new value loaded in the RTI timer load register.
*
* @param[in]     instance     PIT hw instance number
* @return        status
* @pre           The driver needs to be initialized.
*/
static inline uint32 Pit_Ip_GetRtiStatusReg(uint8 instance)
{
    uint32 status = ((pitBase[instance]->RTI_LDVAL_STAT & PIT_RTI_LDVAL_STAT_RT_STAT_MASK) >> PIT_RTI_LDVAL_STAT_RT_STAT_SHIFT);

    return status;
}
#endif

#if (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
static inline Pit_Ip_StatusType Pit_Ip_ValidateInstCall(uint8 instance)
{
    /* return success or error if PIT is initialized or not */
    return (NULL_PTR == pitBase[instance]) ? PIT_IP_ERROR : PIT_IP_SUCCESS;
}
#endif

/*================================================================================================*/
#if (   defined(PIT_0_ISR_USED) || defined(PIT_1_ISR_USED) || defined(PIT_2_ISR_USED) || defined(PIT_4_ISR_USED) || defined(PIT_5_ISR_USED) || \
        defined(CE_PIT_0_CH_0_ISR_USED) || defined(CE_PIT_0_CH_1_ISR_USED) || \
        defined(CE_PIT_0_CH_2_ISR_USED) || defined(CE_PIT_0_CH_3_ISR_USED) || \
        defined(CE_PIT_1_CH_0_ISR_USED) || defined(CE_PIT_1_CH_1_ISR_USED) || \
        defined(CE_PIT_1_CH_2_ISR_USED) || defined(CE_PIT_1_CH_3_ISR_USED) || \
        defined(CE_PIT_2_CH_0_ISR_USED) || defined(CE_PIT_2_CH_1_ISR_USED) || \
        defined(CE_PIT_2_CH_2_ISR_USED) || defined(CE_PIT_2_CH_3_ISR_USED) || \
        defined(CE_PIT_3_CH_0_ISR_USED) || defined(CE_PIT_3_CH_1_ISR_USED) || \
        defined(CE_PIT_3_CH_2_ISR_USED) || defined(CE_PIT_3_CH_3_ISR_USED) || \
        defined(CE_PIT_4_CH_0_ISR_USED) || defined(CE_PIT_4_CH_1_ISR_USED) || \
        defined(CE_PIT_4_CH_2_ISR_USED) || defined(CE_PIT_4_CH_3_ISR_USED) || \
        defined(CE_PIT_5_CH_0_ISR_USED) || defined(CE_PIT_5_CH_1_ISR_USED) || \
        defined(CE_PIT_5_CH_2_ISR_USED) || defined(CE_PIT_5_CH_3_ISR_USED) || \
        defined(RTU0_PIT_0_ISR_USED) || defined(RTU0_PIT_1_ISR_USED) || \
        defined(RTU1_PIT_0_ISR_USED) || defined(RTU1_PIT_1_ISR_USED) || \
        defined(RTU2_PIT_0_ISR_USED) || defined(RTU2_PIT_1_ISR_USED) || \
        defined(RTU3_PIT_0_ISR_USED) || defined(RTU3_PIT_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_0_ISR_USED) || defined(CRS_PIT_0_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_1_ISR_USED) || defined(CRS_PIT_0_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_2_ISR_USED) || defined(CRS_PIT_0_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_3_ISR_USED) || defined(CRS_PIT_0_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_0_ISR_USED) || defined(CRS_PIT_1_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_1_ISR_USED) || defined(CRS_PIT_1_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_2_ISR_USED) || defined(CRS_PIT_1_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_3_ISR_USED) || defined(CRS_PIT_1_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_2_ISR_USED) || defined(FSS_COSS_PIT_3_ISR_USED) || \
        defined(FSS_COSS_PIT_4_ISR_USED) || defined(FSS_COSS_PIT_5_ISR_USED) || \
        defined(FSS_COSS_PIT_6_ISR_USED) || \
        defined(FSS_HKI_PIT_0_ISR_USED) || \
        defined(FSS_PIT_0_CH_0_ISR_USED) || defined(FSS_PIT_0_CH_1_ISR_USED) || defined(FSS_PIT_0_CH_2_ISR_USED) )
/*!
 * @brief   Get the Interrupt Enable Flag of PIT peripheral timer channel.
 * @details Support PIT interrupt flags
 *          This register is intended for Timer Interrupt Flag
 *
 * @param[in] instance - Instance number of PIT module
 * @param[in] channel - The channel in the PIT instance
 *
 * @return Channel Interrupt Enable Flag
 *         - True : Channel interrupts are enabled
 *         - False : Channel interrupts are disabled
 * @pre The driver needs to be initialized.
 *
 */
static inline boolean Pit_Ip_GetInterruptEnableFlag(uint8 instance, uint8 channel)
{
    boolean returnFlag;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if (RTI == channel)
    {
        returnFlag = (0U != (pitBase[instance]->RTI_TCTRL & PIT_RTI_TCTRL_TIE_MASK)) ? TRUE : FALSE;
    }
    else
#endif
    {
        returnFlag = (0U != (pitBase[instance]->TIMER[channel].TCTRL & PIT_TCTRL_TIE_MASK)) ? TRUE : FALSE;
    }
    return returnFlag;
}

/**
* @brief         Driver routine to process all the interrupts of PIT.
* @details       Support function used by interrupt service routines to implement PIT specific operations
*                and call the upper layer handler to implement non-hardware specific operations.
*
* @param[in]     instance     PIT hw instance number
* @param[in]     channel      PIT hw channel number
* @return        void
* @pre           Enable interrupt service routines
* @implements    Pit_Ip_ProcessCommonInterrupt_Activity
*/
static void Pit_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel)
{
    boolean IsChEvEnabled;
    boolean HasChEvOccurred;

    boolean                 chInit;
    Pit_Ip_CallbackType     callback;
    uint8                   callbackParam;
    Pit_Ip_ChannelModeType  channelMode;

    if ((instance < GPT_PIT_INSTANCE_COUNT) && (channel < PIT_CHANNEL_COUNT))
    {
        /* get the driver status */
        chInit = Pit_Ip_u32ChState[instance][channel].chInit;

        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03();
        {
            /* check if channel event is enabled */
            IsChEvEnabled = Pit_Ip_GetInterruptEnableFlag(instance, channel);

            /* check if channel event has occurred */
            HasChEvOccurred = Pit_Ip_GetInterruptStatusFlag(instance, channel);

            /* Check if driver is initialized */
            if (TRUE == chInit)
            {
                /* Check for spurious interrupts */
                if (IsChEvEnabled && HasChEvOccurred)
                {
                    /* Clear pending interrupts */
                    Pit_Ip_ClearInterruptStatusFlag(instance, channel);
                }
            }
            else
            {
                /* Driver isn't initialized and just clear pending interrupts */
                if (HasChEvOccurred)
                {
                    /* Clear pending interrupts */
                    Pit_Ip_ClearInterruptStatusFlag(instance, channel);
                }
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03();

        /* Check if driver is initialized */
        if (TRUE == chInit)
        {
            /* Check for spurious interrupts */
            if (IsChEvEnabled && HasChEvOccurred)
            {
                callback        = Pit_Ip_u32ChState[instance][channel].callback;
                channelMode     = Pit_Ip_u32ChState[instance][channel].channelMode;
                callbackParam   = Pit_Ip_u32ChState[instance][channel].callbackParam;

                if(PIT_IP_CH_MODE_ONESHOT == channelMode)
                {
                    Pit_Ip_StopChannel(instance, channel);
                }

                /* Call GPT upper layer handler */
                if (NULL_PTR != callback)
                {
                    callback(callbackParam);
                }
            }
        }
    }
}
#endif
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief   Get the Interrupt Status Flag of PIT peripheral timer channel.
 * @details Support get of PIT interrupt status flag
 *          This register is intended for Timer interrupt status flag
 *
 * @param[in] instance - Instance number of PIT module
 * @param[in] channel - The channel in the PIT instance
 *
 * @return Channel Interrupt Status Flag
 *         - True : Channel interrupt has occurred
 *         - False: No channel interrupt has occurred
 * @pre The driver needs to be initialized.
 *
 */
boolean Pit_Ip_GetInterruptStatusFlag(uint8 instance, uint8 channel)
{
    boolean returnFlag;
#ifdef PIT_IP_RTI_CHANNEL_EXISTS
    if (RTI == channel)
    {
        returnFlag = (0U != (pitBase[instance]->RTI_TFLG & PIT_RTI_TFLG_TIF_MASK)) ? TRUE : FALSE;
    }
    else
#endif
    {
        returnFlag = (0U != (pitBase[instance]->TIMER[channel].TFLG & PIT_TFLG_TIF_MASK)) ? TRUE : FALSE;
    }
    return returnFlag;
}

/**
* @brief         Function Name : Pit_Ip_Init
* @details       Driver initialization function. This function is called for each PIT hw Instance and
*                   - enables the functional clock for PIT Instance or for RTI_PIT
*                   - Sets PIT operation in Debug mode
*
* @param[in]     instance     PIT hw instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
* @implements    Pit_Ip_Init_Activity
*/
void Pit_Ip_Init(uint8 instance, const Pit_Ip_InstanceConfigType *config)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != config);
#endif
#if (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
    /* Check if valid instance */
    Pit_Ip_StatusType status = Pit_Ip_ValidateInstCall(instance);
    if(PIT_IP_SUCCESS == status)
    {
#endif

    /* Enable register access from user mode, if enabled from configuration file */
#if (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))
    if(PIT_AE_IP_INSTANCE_NUMBER == instance)
    {
#endif
        Call_Pit_Ip_SetUserAccessAllowed((uint32)pitBase[instance]);
#if (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))
    }
#endif
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
#if (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))
    if(PIT_AE_IP_INSTANCE_NUMBER != instance)
    {
#endif
        /* Enables functional clock for standard timer */
        if (config->enableStandardTimers)
        {
            Pit_Ip_EnableModule(instance, 0U);
        }
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
        /* Enables functional clock for RTI timer */
        if (config->enableRTITimer)
        {
            Pit_Ip_EnableModule(instance, 1U);
        }
#endif
#if (defined(GPT_PIT_AE_REG_PROT_AVAILABLE) && (STD_ON == GPT_PIT_AE_REG_PROT_AVAILABLE))
    }
#endif
#endif /* PIT_IP_MDIS_BIT_EXISTS */
    /* Sets PIT operation in Debug mode*/
    Pit_Ip_SetDebugMode(instance, config->stopRunInDebug);
#if (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
    }
#endif
}

/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_InitChannel
* @details       Initializes the PIT channels. This function should be called for each PIT hw channel and:
*                   - stops channel
*                   - disable interrupts
*                   - clears pending interrupts
*                   - initializes the state sructure for common process interrupt
*
* @param[in]     instance      PIT hw instance number
* @param[in]     chnlConfig    Pointer to a selected configuration structure.
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver.
* @implements    Pit_Ip_InitChannel_Activity
*/
void Pit_Ip_InitChannel(uint8 instance, const Pit_Ip_ChannelConfigType *chnlConfig)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != chnlConfig);
    DevAssert(PIT_CHANNEL_COUNT > chnlConfig->hwChannel);
#endif

#if (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
    /* Check if valid instance */
    Pit_Ip_StatusType status = Pit_Ip_ValidateInstCall(instance);
    if(PIT_IP_SUCCESS == status)
    {
#endif

    /* Stop channel to configure channel */
    Pit_Ip_EnableTimer(instance, chnlConfig->hwChannel, FALSE);
    /* Disable Interrupts */
    Pit_Ip_SetEnableInterruptFlag(instance, chnlConfig->hwChannel, FALSE);
    /* Clear pending interrupts */
    Pit_Ip_ClearInterruptStatusFlag(instance, chnlConfig->hwChannel);
#if (   defined(PIT_0_ISR_USED) || defined(PIT_1_ISR_USED) || defined(PIT_2_ISR_USED) || defined(PIT_4_ISR_USED) || defined(PIT_5_ISR_USED) || \
        defined(CE_PIT_0_CH_0_ISR_USED) || defined(CE_PIT_0_CH_1_ISR_USED) || \
        defined(CE_PIT_0_CH_2_ISR_USED) || defined(CE_PIT_0_CH_3_ISR_USED) || \
        defined(CE_PIT_1_CH_0_ISR_USED) || defined(CE_PIT_1_CH_1_ISR_USED) || \
        defined(CE_PIT_1_CH_2_ISR_USED) || defined(CE_PIT_1_CH_3_ISR_USED) || \
        defined(CE_PIT_2_CH_0_ISR_USED) || defined(CE_PIT_2_CH_1_ISR_USED) || \
        defined(CE_PIT_2_CH_2_ISR_USED) || defined(CE_PIT_2_CH_3_ISR_USED) || \
        defined(CE_PIT_3_CH_0_ISR_USED) || defined(CE_PIT_3_CH_1_ISR_USED) || \
        defined(CE_PIT_3_CH_2_ISR_USED) || defined(CE_PIT_3_CH_3_ISR_USED) || \
        defined(CE_PIT_4_CH_0_ISR_USED) || defined(CE_PIT_4_CH_1_ISR_USED) || \
        defined(CE_PIT_4_CH_2_ISR_USED) || defined(CE_PIT_4_CH_3_ISR_USED) || \
        defined(CE_PIT_5_CH_0_ISR_USED) || defined(CE_PIT_5_CH_1_ISR_USED) || \
        defined(CE_PIT_5_CH_2_ISR_USED) || defined(CE_PIT_5_CH_3_ISR_USED) || \
        defined(RTU0_PIT_0_ISR_USED) || defined(RTU0_PIT_1_ISR_USED) || \
        defined(RTU1_PIT_0_ISR_USED) || defined(RTU1_PIT_1_ISR_USED) || \
        defined(RTU2_PIT_0_ISR_USED) || defined(RTU2_PIT_1_ISR_USED) || \
        defined(RTU3_PIT_0_ISR_USED) || defined(RTU3_PIT_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_0_ISR_USED) || defined(CRS_PIT_0_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_1_ISR_USED) || defined(CRS_PIT_0_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_2_ISR_USED) || defined(CRS_PIT_0_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_0_CH_3_ISR_USED) || defined(CRS_PIT_0_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_0_ISR_USED) || defined(CRS_PIT_1_CH_0_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_1_ISR_USED) || defined(CRS_PIT_1_CH_1_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_2_ISR_USED) || defined(CRS_PIT_1_CH_2_ISR_USED) || \
        defined(FSS_COSS_PIT_1_CH_3_ISR_USED) || defined(CRS_PIT_1_CH_3_ISR_USED) || \
        defined(FSS_COSS_PIT_2_ISR_USED) || defined(FSS_COSS_PIT_3_ISR_USED) || \
        defined(FSS_COSS_PIT_4_ISR_USED) || defined(FSS_COSS_PIT_5_ISR_USED) || \
        defined(FSS_COSS_PIT_6_ISR_USED) || \
        defined(FSS_HKI_PIT_0_ISR_USED) || \
        defined(FSS_PIT_0_CH_0_ISR_USED) || defined(FSS_PIT_0_CH_1_ISR_USED) || defined(FSS_PIT_0_CH_2_ISR_USED) )
    Pit_Ip_u32ChState[instance][chnlConfig->hwChannel].chInit = TRUE;
    Pit_Ip_u32ChState[instance][chnlConfig->hwChannel].callback = chnlConfig->callback;
    Pit_Ip_u32ChState[instance][chnlConfig->hwChannel].callbackParam = chnlConfig->callbackParam;
    Pit_Ip_u32ChState[instance][chnlConfig->hwChannel].channelMode = chnlConfig->channelMode;
#endif

#if (defined(PIT_IP_INSTANCE_GAP_EXISTS) && (PIT_IP_INSTANCE_GAP_EXISTS == STD_ON))
    }
#endif
}

/*================================================================================================*/
/**
* @brief         Pit_Ip_DeInit
* @details       De-Initializes the PIT instances. This functions is called for each PIT Instance and
*                    - resets all channels to default
*
* @param[in]     instance        Pit hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
* @implements    Pit_Ip_Deinit_Activity
*
*/
void Pit_Ip_Deinit(uint8 instance)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
#endif
    uint8 channelNum = 0U;
    boolean rtiChannelExists = FALSE;
    boolean mdisBitExists = FALSE;

    switch (instance)
    {
#ifdef PIT_0_IP_EXISTS
        case PIT_0_IP_INSTANCE_NUMBER:
            channelNum = PIT_0_IP_CHANNELS_NUMBER;
#ifdef PIT_IP_RTI_CHANNEL_EXISTS
            rtiChannelExists = TRUE;
#endif
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
            mdisBitExists = TRUE;
#endif
        break;
#endif
#ifdef PIT_1_IP_EXISTS
        case PIT_1_IP_INSTANCE_NUMBER:
            channelNum = PIT_1_IP_CHANNELS_NUMBER;
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
            mdisBitExists = TRUE;
#endif
        break;
#endif
#ifdef PIT_2_IP_EXISTS
        case PIT_2_IP_INSTANCE_NUMBER:
            channelNum = PIT_2_IP_CHANNELS_NUMBER;
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
            mdisBitExists = TRUE;
#endif
        break;
#endif
#ifdef PIT_3_IP_EXISTS
        case PIT_3_IP_INSTANCE_NUMBER:
            channelNum = PIT_3_IP_CHANNELS_NUMBER;
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
            mdisBitExists = TRUE;
#endif
        break;
#endif
#ifdef PIT_4_IP_EXISTS
        case PIT_4_IP_INSTANCE_NUMBER:
            channelNum = PIT_4_IP_CHANNELS_NUMBER;
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
            mdisBitExists = TRUE;
#endif
        break;
#endif
#ifdef PIT_5_IP_EXISTS
        case PIT_5_IP_INSTANCE_NUMBER:
            channelNum = PIT_5_IP_CHANNELS_NUMBER;
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
            mdisBitExists = TRUE;
#endif
        break;
#endif
#ifdef CE_PIT_0_IP_EXISTS
        case CE_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = CE_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CE_PIT_1_IP_EXISTS
        case CE_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = CE_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CE_PIT_2_IP_EXISTS
        case CE_PIT_2_IP_INSTANCE_NUMBER:
            channelNum = CE_PIT_2_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CE_PIT_3_IP_EXISTS
        case CE_PIT_3_IP_INSTANCE_NUMBER:
            channelNum = CE_PIT_3_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CE_PIT_4_IP_EXISTS
        case CE_PIT_4_IP_INSTANCE_NUMBER:
            channelNum = CE_PIT_4_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CE_PIT_5_IP_EXISTS
        case CE_PIT_5_IP_INSTANCE_NUMBER:
            channelNum = CE_PIT_5_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_0_IP_EXISTS
        case FSS_COSS_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_1_IP_EXISTS
        case FSS_COSS_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_2_IP_EXISTS
        case FSS_COSS_PIT_2_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_2_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_3_IP_EXISTS
        case FSS_COSS_PIT_3_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_3_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_4_IP_EXISTS
        case FSS_COSS_PIT_4_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_4_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_5_IP_EXISTS
        case FSS_COSS_PIT_5_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_5_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_COSS_PIT_6_IP_EXISTS
        case FSS_COSS_PIT_6_IP_INSTANCE_NUMBER:
            channelNum = FSS_COSS_PIT_6_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_HKI_PIT_0_IP_EXISTS
        case FSS_HKI_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = FSS_HKI_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef FSS_PIT_0_IP_EXISTS
        case FSS_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = FSS_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CRS_PIT_0_IP_EXISTS
        case CRS_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = CRS_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef CRS_PIT_1_IP_EXISTS
        case CRS_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = CRS_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU0_PIT_0_IP_EXISTS
        case RTU0_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = RTU0_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU0_PIT_1_IP_EXISTS
        case RTU0_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = RTU0_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU1_PIT_0_IP_EXISTS
        case RTU1_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = RTU1_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU1_PIT_1_IP_EXISTS
        case RTU1_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = RTU1_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU2_PIT_0_IP_EXISTS
        case RTU2_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = RTU2_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU2_PIT_1_IP_EXISTS
        case RTU2_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = RTU2_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU3_PIT_0_IP_EXISTS
        case RTU3_PIT_0_IP_INSTANCE_NUMBER:
            channelNum = RTU3_PIT_0_IP_CHANNELS_NUMBER;
        break;
#endif
#ifdef RTU3_PIT_1_IP_EXISTS
        case RTU3_PIT_1_IP_INSTANCE_NUMBER:
            channelNum = RTU3_PIT_1_IP_CHANNELS_NUMBER;
        break;
#endif
        default:
            /* This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }

    /* Set control, load, status registers to default value */
    Pit_Ip_Reset(instance, channelNum, rtiChannelExists, mdisBitExists);
}

/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_StartChannel
* @details      This function is called for starting the Pit timer channel.
*                    - sets the timeout value into the PIT timer channel register
*                    - enables the PIT channel
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
* @param[in]     countValue      channel timeout value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the Pit timer channel.
* @implements    Pit_Ip_StartChannel_Activity
*/
Pit_Ip_StatusType Pit_Ip_StartChannel(uint8 instance, uint8 channel, uint32 countValue)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif
    boolean isRunning = FALSE;
    Pit_Ip_StatusType status = PIT_IP_ERROR;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    uint32 startTime, elapsedTime, timeoutTicks;
    Pit_Ip_StartTimeout(&startTime, &elapsedTime, &timeoutTicks, PIT_IP_TIMEOUT_COUNTER);
#endif

    isRunning = Pit_Ip_IsChannelRunning(instance, channel);

    if(FALSE == isRunning)
    {
        Pit_Ip_SetCounterValue(instance, channel, (countValue - 1U));
#if (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
        Pit_Ip_bIsChangedTimeout = FALSE;
#endif
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
        if((0U == instance) && (RTI == channel))
        {
            do
            {
                if (1U == Pit_Ip_GetRtiStatusReg(instance))
                {
                    status = PIT_IP_SUCCESS;
                    break;
                }
            } while(!Pit_Ip_TimeoutExpired(&startTime, &elapsedTime, timeoutTicks));
            if(PIT_IP_SUCCESS == status)
            {
                Pit_Ip_EnableTimer(instance, channel, TRUE);
                status = PIT_IP_SUCCESS;
            }
        }
        else
        {
#endif
            Pit_Ip_EnableTimer(instance, channel, TRUE);
            status = PIT_IP_SUCCESS;
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
        }
#endif
    }

    return status;
}

/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_StopChannel
* @details       This function is called for stopping the Pit counter. This function disables the PIT channel and:
*                    - stops PIT counter
*                    - clears interrupt flag
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
* @return        void
* @pre           The driver needs to be initialized. Pit_Ip_StartChannel must be call before.
* @implements    Pit_Ip_StopChannel_Activity
*/
void Pit_Ip_StopChannel(uint8 instance, uint8 channel)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif
    Pit_Ip_EnableTimer(instance, channel, FALSE);
    /* Clear pending interrupts */
    Pit_Ip_ClearInterruptStatusFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_GetCurrentTimer
* @details       Gets counter value from CVAL Register.
*                The period range depends on the frequency of the PIT source clock
*
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
*
* @return        counterValue    counter value
* @pre           The driver needs to be initialized.
* @implements    Pit_Ip_GetCurrentTimer_Activity
*/
uint64 Pit_Ip_GetCurrentTimer(uint8 instance, uint8 channel)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif
    uint64 counterValue = 0U;

    counterValue = Pit_Ip_GetCounterValue(instance, channel);

    return counterValue;
}

/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_EnableChannelInterrupt
* @details      This function enables the IRQ corresponding to the Pit timer channel
*
*
* @param[in]    instance        Pit hw instance
* @param[in]    channel         Pit hw channel
* @return       void
* @pre          The driver needs to be initialized.
* @implements   Pit_Ip_EnableChannelInterrupt_Activity
*/
void Pit_Ip_EnableChannelInterrupt(uint8 instance, uint8 channel)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif
    /* Clear pending interrupts */
    Pit_Ip_ClearInterruptStatusFlag(instance, channel);
    /* Enable Interrupts */
    Pit_Ip_SetEnableInterruptFlag(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_DisableChannelInterrupt
* @details      This function disables the IRQ corresponding to the Pit timer channel
*
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Pit_Ip_DisableChannelInterrupt_Activity
*/
void Pit_Ip_DisableChannelInterrupt(uint8 instance, uint8 channel)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif
    /* Disable Interrupts */
    Pit_Ip_SetEnableInterruptFlag(instance, channel, FALSE);
    /* Clear pending interrupts */
    Pit_Ip_ClearInterruptStatusFlag(instance, channel);
}

/*================================================================================================*/
#if (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief      The function changes Pit Timer Load Value Register value.
* @details    This function:
*               - sets the next timeout value to PIT_RTI_LDVAL.
*
* @param[in]     u8HwChannel        Pit hw channel ID
* @param[in]     u32Value           channel timeout value
* @return        void
* @pre           The driver needs to be initialized. PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON
* @implements    Pit_Ip_ChangeNextTimeoutValue_Activity
*/
void Pit_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif

    if(FALSE == Pit_Ip_bIsChangedTimeout)
    {
        Pit_Ip_u32OldTargetValue = Pit_Ip_GetLoadValue(instance, channel) + 1U;
        Pit_Ip_bIsChangedTimeout = TRUE;
    }
    Pit_Ip_SetCounterValue(instance, channel, (value - 1U));

}
#endif /* PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */

/*================================================================================================*/
#if (PIT_IP_CHAIN_MODE == STD_ON)
/**
* @brief      The function Pit_Ip_EnableChainMode.
* @details    This function:
*               - Chains the timers.
* @param[in]     instance        Pit hw channel ID
* @param[in]     channel         channel timeout value
* @return        returnValue
* @pre           The driver needs to be initialized. PIT_IP_CHAIN_MODE == STD_ON
* @implements    Pit_Ip_ChainMode_Activity
*/
Pit_Ip_StatusType Pit_Ip_ChainMode(uint8 instance, uint8 channel, boolean enable)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
    DevAssert(PIT_CHANNEL_COUNT > channel);
#endif
    Pit_Ip_StatusType returnValue;

    /* Can not enable chain mode for PIT_RTI and CH_0 */
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    if(((uint8) 0x00 < channel) && (RTI != channel))
#else
    if((uint8) 0x00 < channel)
#endif
    {
        /* Enable Chain Mode*/
        Pit_Ip_SetChainMode(instance, channel, enable);
        returnValue = PIT_IP_SUCCESS;
    }
    else
    {
        returnValue = PIT_IP_ERROR;
    }

    return returnValue;
}
#endif /*(PIT_IP_CHAIN_MODE == STD_ON)*/

/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_SetLifetimeTimer
* @details      Build the 64-bit lifetimer.
*               The lifetime timer is a 64-bit timer which chains timer channel 0 and timer channel 1 together
*               with the start value of both channels is set to the maximum value(0xFFFFFFFF).
*               The period of lifetime timer is equal to the "period of
*               timer 0 * period of timer 1".
*
* @param[in]    instance        Pit hw instance
* @return       void
* @pre          The driver needs to be initialized.
* @implements   Pit_Ip_SetLifetimeTimerCount_Activity
*/
void Pit_Ip_SetLifetimeTimer(uint8 instance)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
#endif

    /* Setup timer channel 1 for maximum counting period */
    Pit_Ip_SetCounterValue(instance, 1U, PIT_MAX_VALUE);
    /* Disable timer channel 1 interrupt */
    Pit_Ip_SetEnableInterruptFlag(instance, 1U, FALSE);
    /* Chain timer channel 1 to timer channel 0 */
    Pit_Ip_SetChainMode(instance, 1U, TRUE);
    /* Start timer channel 1 */
    Pit_Ip_EnableTimer(instance, 1U, TRUE);
    /* Setup timer channel 0 for maximum counting period */
    Pit_Ip_SetCounterValue(instance, 0U, PIT_MAX_VALUE);
    /* Start timer channel 0 */
    Pit_Ip_EnableTimer(instance, 0U, TRUE);
}

/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_GetLifetimeTimer
* @details       Read current lifefime counter value.
*                The Lifetime timer is 64-bit timer which chains timer 0 and timer 1 together.
*                The period of lifetime timer equals to "period of timer 0 * period of timer 1".
*                This feature returns an absolute time stamp in count. The time stamp
*                value does not exceed the timer period. The timer is down-counting.
*
* @param[in]     instance        Pit hw instance
*
* @return        lifeTimeValue
* @pre           The driver needs to be initialized.
* @implements    Pit_Ip_GetLifetimeTimer_Activity
*/
uint64 Pit_Ip_GetLifetimeTimer(uint8 instance)
{
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_PIT_INSTANCE_COUNT > instance);
#endif

    uint64 lifeTimeValue = 0U;
    uint32 valueH = 0U;
    uint32 valueL = 0U;

SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09();
    /* LTMR64H should be read before LTMR64L */
    /* Read LTMR64H*/
    valueH = Pit_Ip_GetUpperLifetimerValue(instance);
    /* Read LTMR64L*/
    valueL = Pit_Ip_GetLowerLifetimerValue(instance);

    /* TODO: ERRATA versioning*/
#ifdef ERR_IPV_PIT_E050130
    /* If the read value of LTMR64L is equal to LDVAL */
    if (valueL == Pit_Ip_GetLoadValue(instance, 0U))
    {
        /* The errata's workaround: read both LTMR64H and LTMR64L
        registers one additional time to obtain the correct lifetime value */
        valueH = Pit_Ip_GetUpperLifetimerValue(instance);
        valueL = Pit_Ip_GetLowerLifetimerValue(instance);
    }
#endif
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09();

    lifeTimeValue = (((uint64)valueH << 32U) + (uint64)(valueL));

    return lifeTimeValue;
}
/*================================================================================================*/

#if ((STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS))

#if defined(PIT_0_ISR_USED)
/**
* @brief   Interrupt handler for PIT_0 channels.
* @details Interrupt Service Routine corresponding to PIT_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(PIT_0_ISR)
{
    uint8 channel;
#if defined(PIT_0_IP_EXISTS)
    uint8 instance = PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
#if (defined(PIT_IP_RTI_CHANNEL_EXISTS) && (PIT_IP_RTI_USED == STD_OFF))
    for (channel = 0U; channel < PIT_0_IP_CHANNELS_NUMBER - 1U; ++channel)
#else
    for (channel = 0U; channel < PIT_0_IP_CHANNELS_NUMBER; ++channel)
#endif
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(PIT_1_ISR_USED)
/**
* @brief   Interrupt handler for PIT_1 channels.
* @details Interrupt Service Routine corresponding to PIT_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(PIT_1_ISR)
{
    uint8 channel;
#if defined(PIT_1_IP_EXISTS)
    uint8 instance = PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < PIT_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(PIT_4_ISR_USED)
/**
* @brief   Interrupt handler for PIT_4 channels.
* @details Interrupt Service Routine corresponding to PIT_4 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(PIT_4_ISR)
{
    uint8 channel;
#if defined(PIT_4_IP_EXISTS)
    uint8 instance = PIT_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < PIT_4_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(PIT_5_ISR_USED)
/**
* @brief   Interrupt handler for PIT_5 channels.
* @details Interrupt Service Routine corresponding to PIT_5 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(PIT_5_ISR)
{
    uint8 channel;
#if defined(PIT_5_IP_EXISTS)
    uint8 instance = PIT_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < PIT_5_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if (STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS)

#if defined(CE_PIT_0_CH_0_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_0_CH_0 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_0_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_0_CH_0_ISR)
{
    uint8 channel = 0U;
#if defined(CE_PIT_0_IP_EXISTS)
    uint8 instance = CE_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_0_CH_1_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_0_CH_1 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_0_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_0_CH_1_ISR)
{
    uint8 channel = 1U;
#if defined(CE_PIT_0_IP_EXISTS)
    uint8 instance = CE_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_0_CH_2_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_0_CH_2 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_0_CH_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_0_CH_2_ISR)
{
    uint8 channel = 2U;
#if defined(CE_PIT_0_IP_EXISTS)
    uint8 instance = CE_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_0_CH_3_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_0_CH_3 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_0_CH_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_0_CH_3_ISR)
{
    uint8 channel = 3U;
#if defined(CE_PIT_0_IP_EXISTS)
    uint8 instance = CE_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_1_CH_0_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_1_CH_0 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_1_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_1_CH_0_ISR)
{
    uint8 channel = 0U;
#if defined(CE_PIT_1_IP_EXISTS)
    uint8 instance = CE_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_1_CH_1_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_1_CH_1 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_1_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_1_CH_1_ISR)
{
    uint8 channel = 1U;
#if defined(CE_PIT_1_IP_EXISTS)
    uint8 instance = CE_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_1_CH_2_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_1_CH_2 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_1_CH_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_1_CH_2_ISR)
{
    uint8 channel = 2U;
#if defined(CE_PIT_1_IP_EXISTS)
    uint8 instance = CE_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_1_CH_3_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_1_CH_3 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_1_CH_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_1_CH_3_ISR)
{
    uint8 channel = 3U;
#if defined(CE_PIT_1_IP_EXISTS)
    uint8 instance = CE_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_2_CH_0_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_2_CH_0 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_2_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_2_CH_0_ISR)
{
    uint8 channel = 0U;
#if defined(CE_PIT_2_IP_EXISTS)
    uint8 instance = CE_PIT_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_2_CH_1_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_2_CH_1 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_2_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_2_CH_1_ISR)
{
    uint8 channel = 1U;
#if defined(CE_PIT_2_IP_EXISTS)
    uint8 instance = CE_PIT_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_2_CH_2_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_2_CH_2 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_2_CH_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_2_CH_2_ISR)
{
    uint8 channel = 2U;
#if defined(CE_PIT_2_IP_EXISTS)
    uint8 instance = CE_PIT_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_2_CH_3_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_2_CH_3 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_2_CH_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_2_CH_3_ISR)
{
    uint8 channel = 3U;
#if defined(CE_PIT_2_IP_EXISTS)
    uint8 instance = CE_PIT_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_3_CH_0_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_3_CH_0 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_3_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_3_CH_0_ISR)
{
    uint8 channel = 0U;
#if defined(CE_PIT_3_IP_EXISTS)
    uint8 instance = CE_PIT_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_3_CH_1_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_3_CH_1 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_3_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_3_CH_1_ISR)
{
    uint8 channel = 1U;
#if defined(CE_PIT_3_IP_EXISTS)
    uint8 instance = CE_PIT_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_3_CH_2_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_3_CH_2 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_3_CH_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_3_CH_2_ISR)
{
    uint8 channel = 2U;
#if defined(CE_PIT_3_IP_EXISTS)
    uint8 instance = CE_PIT_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_3_CH_3_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_3_CH_3 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_3_CH_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_3_CH_3_ISR)
{
    uint8 channel = 3U;
#if defined(CE_PIT_3_IP_EXISTS)
    uint8 instance = CE_PIT_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_4_CH_0_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_4_CH_0 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_4_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_4_CH_0_ISR)
{
    uint8 channel = 0U;
#if defined(CE_PIT_4_IP_EXISTS)
    uint8 instance = CE_PIT_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_4_CH_1_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_4_CH_1 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_4_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_4_CH_1_ISR)
{
    uint8 channel = 1U;
#if defined(CE_PIT_4_IP_EXISTS)
    uint8 instance = CE_PIT_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_4_CH_2_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_4_CH_2 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_4_CH_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_4_CH_2_ISR)
{
    uint8 channel = 2U;
#if defined(CE_PIT_4_IP_EXISTS)
    uint8 instance = CE_PIT_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_4_CH_3_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_4_CH_3 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_4_CH_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_4_CH_3_ISR)
{
    uint8 channel = 3U;
#if defined(CE_PIT_4_IP_EXISTS)
    uint8 instance = CE_PIT_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_5_CH_0_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_5_CH_0 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_5_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_5_CH_0_ISR)
{
    uint8 channel = 0U;
#if defined(CE_PIT_5_IP_EXISTS)
    uint8 instance = CE_PIT_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_5_CH_1_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_5_CH_1 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_5_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_5_CH_1_ISR)
{
    uint8 channel = 1U;
#if defined(CE_PIT_5_IP_EXISTS)
    uint8 instance = CE_PIT_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_5_CH_2_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_5_CH_2 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_5_CH_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_5_CH_2_ISR)
{
    uint8 channel = 2U;
#if defined(CE_PIT_5_IP_EXISTS)
    uint8 instance = CE_PIT_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CE_PIT_5_CH_3_ISR_USED)
/**
* @brief   Interrupt handler for CE_PIT_5_CH_3 channel.
* @details Interrupt Service Routine corresponding to CE_PIT_5_CH_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(CE_PIT_5_CH_3_ISR)
{
    uint8 channel = 3U;
#if defined(CE_PIT_5_IP_EXISTS)
    uint8 instance = CE_PIT_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(FSS_HKI_PIT_0_ISR_USED)
ISR(FSS_HKI_PIT_0_ISR){
    uint8 channel;
#if defined(FSS_HKI_PIT_0_IP_EXISTS)
    uint8 instance = FSS_HKI_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < FSS_HKI_PIT_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU0_PIT_0_ISR_USED)
/**
* @brief   Interrupt handler for RTU0_PIT_0 channels.
* @details Interrupt Service Routine corresponding to RTU0_PIT_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(RTU0_PIT_0_ISR)
{
    uint8 channel;
#if defined(RTU0_PIT_0_IP_EXISTS)
    uint8 instance = RTU0_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU0_PIT_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU0_PIT_1_ISR_USED)
/**
* @brief   Interrupt handler for RTU0_PIT_1 channels.
* @details Interrupt Service Routine corresponding to RTU0_PIT_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU0_PIT_1_ISR)
{
    uint8 channel;
#if defined(RTU0_PIT_1_IP_EXISTS)
    uint8 instance = RTU0_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU0_PIT_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU1_PIT_0_ISR_USED)
/**
* @brief   Interrupt handler for RTU1_PIT_0 channels.
* @details Interrupt Service Routine corresponding to RTU1_PIT_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(RTU1_PIT_0_ISR)
{
    uint8 channel;
#if defined(RTU1_PIT_0_IP_EXISTS)
    uint8 instance = RTU1_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU1_PIT_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU1_PIT_1_ISR_USED)
/**
* @brief   Interrupt handler for RTU1_PIT_1 channels.
* @details Interrupt Service Routine corresponding to RTU1_PIT_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU1_PIT_1_ISR)
{
    uint8 channel;
#if defined(RTU1_PIT_1_IP_EXISTS)
    uint8 instance = RTU1_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU1_PIT_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU2_PIT_0_ISR_USED)
/**
* @brief   Interrupt handler for RTU2_PIT_0 channels.
* @details Interrupt Service Routine corresponding to RTU2_PIT_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(RTU2_PIT_0_ISR)
{
    uint8 channel;
#if defined(RTU2_PIT_0_IP_EXISTS)
    uint8 instance = RTU2_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU2_PIT_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU2_PIT_1_ISR_USED)
/**
* @brief   Interrupt handler for RTU2_PIT_1 channels.
* @details Interrupt Service Routine corresponding to RTU2_PIT_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU2_PIT_1_ISR)
{
    uint8 channel;
#if defined(RTU2_PIT_1_IP_EXISTS)
    uint8 instance = RTU2_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU2_PIT_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU3_PIT_0_ISR_USED)
/**
* @brief   Interrupt handler for RTU3_PIT_0 channels.
* @details Interrupt Service Routine corresponding to RTU3_PIT_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(RTU3_PIT_0_ISR)
{
    uint8 channel;
#if defined(RTU3_PIT_0_IP_EXISTS)
    uint8 instance = RTU3_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU3_PIT_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU3_PIT_1_ISR_USED)
/**
* @brief   Interrupt handler for RTU3_PIT_1 channels.
* @details Interrupt Service Routine corresponding to RTU3_PIT_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU3_PIT_1_ISR)
{
    uint8 channel;
#if defined(RTU3_PIT_1_IP_EXISTS)
    uint8 instance = RTU3_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < RTU3_PIT_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(CRS_PIT_0_CH_0_ISR_USED)
ISR(CRS_PIT_0_CH_0_ISR){
    uint8 channel = 0U;
#if defined(CRS_PIT_0_IP_EXISTS)
    uint8 instance = CRS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(CRS_PIT_0_CH_1_ISR_USED)
ISR(CRS_PIT_0_CH_1_ISR){
    uint8 channel = 1U;
#if defined(CRS_PIT_0_IP_EXISTS)
    uint8 instance = CRS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(CRS_PIT_0_CH_2_ISR_USED)
ISR(CRS_PIT_0_CH_2_ISR){
    uint8 channel = 2U;
#if defined(CRS_PIT_0_IP_EXISTS)
    uint8 instance = CRS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(CRS_PIT_0_CH_3_ISR_USED)
ISR(CRS_PIT_0_CH_3_ISR){
    uint8 channel = 3U;
#if defined(CRS_PIT_0_IP_EXISTS)
    uint8 instance = CRS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(CRS_PIT_1_CH_0_ISR_USED)
ISR(CRS_PIT_1_CH_0_ISR){
    uint8 channel = 0U;
#if defined(CRS_PIT_1_IP_EXISTS)
    uint8 instance = CRS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(CRS_PIT_1_CH_1_ISR_USED)
ISR(CRS_PIT_1_CH_1_ISR){
    uint8 channel = 1U;
#if defined(CRS_PIT_1_IP_EXISTS)
    uint8 instance = CRS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(CRS_PIT_1_CH_2_ISR_USED)
ISR(CRS_PIT_1_CH_2_ISR){
    uint8 channel = 2U;
#if defined(CRS_PIT_1_IP_EXISTS)
    uint8 instance = CRS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(CRS_PIT_1_CH_3_ISR_USED)
ISR(CRS_PIT_1_CH_3_ISR){
    uint8 channel = 3U;
#if defined(CRS_PIT_1_IP_EXISTS)
    uint8 instance = CRS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(FSS_COSS_PIT_0_CH_0_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_0_ISR){
    uint8 channel = 0U;
#if defined(FSS_COSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_COSS_PIT_0_CH_1_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_1_ISR){
    uint8 channel = 1U;
#if defined(FSS_COSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_COSS_PIT_0_CH_2_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_2_ISR){
    uint8 channel = 2U;
#if defined(FSS_COSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_COSS_PIT_0_CH_3_ISR_USED)
ISR(FSS_COSS_PIT_0_CH_3_ISR){
    uint8 channel = 3U;
#if defined(FSS_COSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(FSS_COSS_PIT_1_CH_0_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_0_ISR){
    uint8 channel = 0U;
#if defined(FSS_COSS_PIT_1_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_COSS_PIT_1_CH_1_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_1_ISR){
    uint8 channel = 1U;
#if defined(FSS_COSS_PIT_1_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_COSS_PIT_1_CH_2_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_2_ISR){
    uint8 channel = 2U;
#if defined(FSS_COSS_PIT_1_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_COSS_PIT_1_CH_3_ISR_USED)
ISR(FSS_COSS_PIT_1_CH_3_ISR){
    uint8 channel = 3U;
#if defined(FSS_COSS_PIT_1_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(FSS_COSS_PIT_2_ISR_USED)
ISR(FSS_COSS_PIT_2_ISR){
    uint8 channel = 0U;
#if defined(FSS_COSS_PIT_2_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif


#if defined(FSS_COSS_PIT_3_ISR_USED)
ISR(FSS_COSS_PIT_3_ISR){


    uint8 channel = 0U;
#if defined(FSS_COSS_PIT_3_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif




#if defined(FSS_COSS_PIT_4_ISR_USED)
ISR(FSS_COSS_PIT_4_ISR){
    uint8 channel = 0U;
#if defined(FSS_COSS_PIT_4_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif




#if defined(FSS_COSS_PIT_5_ISR_USED)
ISR(FSS_COSS_PIT_5_ISR){
    uint8 channel = 0U;
#if defined(FSS_COSS_PIT_5_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif




#if defined(FSS_COSS_PIT_6_ISR_USED)
ISR(FSS_COSS_PIT_6_ISR){
    uint8 channel = 0U;



#if defined(FSS_COSS_PIT_6_IP_EXISTS)
    uint8 instance = FSS_COSS_PIT_6_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#if defined(FSS_PIT_0_CH_0_ISR_USED)
ISR(FSS_PIT_0_CH_0_ISR){
    uint8 channel = 0U;
#if defined(FSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_PIT_0_CH_1_ISR_USED)
ISR(FSS_PIT_0_CH_1_ISR){
    uint8 channel = 1U;
#if defined(FSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif
#if defined(FSS_PIT_0_CH_2_ISR_USED)
ISR(FSS_PIT_0_CH_2_ISR){
    uint8 channel = 2U;
#if defined(FSS_PIT_0_IP_EXISTS)
    uint8 instance = FSS_PIT_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif

    Pit_Ip_ProcessCommonInterrupt(instance, channel);
}
#endif

#endif /* STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS */

#if (STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT)

#if defined(PIT_2_ISR_USED)
/**
* @brief   Interrupt handler for PIT_2 channels.
* @details Interrupt Service Routine corresponding to PIT_2 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(PIT_2_ISR)
{
    uint8 channel;
#if defined(PIT_2_IP_EXISTS)
    uint8 instance = PIT_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < PIT_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(PIT_3_ISR_USED)
/**
* @brief   Interrupt handler for PIT_3 channels.
* @details Interrupt Service Routine corresponding to PIT_3 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(PIT_3_ISR)
{
    uint8 channel;
#if defined(PIT_3_IP_EXISTS)
    uint8 instance = PIT_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined PIT instance number"
#endif
    for (channel = 0U; channel < PIT_3_IP_CHANNELS_NUMBER; ++channel)
    {
        Pit_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#endif /* STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT */

#endif /* (STD_ON == PIT_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS) */

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* PIT_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif /* PIT_IP_C */

/** @} */
