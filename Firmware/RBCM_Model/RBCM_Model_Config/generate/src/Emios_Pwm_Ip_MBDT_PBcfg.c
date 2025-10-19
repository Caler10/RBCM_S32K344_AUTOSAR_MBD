/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm eTpu
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file       Emios_Pwm_Ip_MBDT_PBcfg.c
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Pwm_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_MBDT_PB_CFG_VENDOR_ID_C                       43
#define EMIOS_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION_C                5
#define EMIOS_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION_C                0
#define EMIOS_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Emios_Pwm_Ip_Cfg.h file are of the same vendor */
#if (EMIOS_PWM_IP_MBDT_PB_CFG_VENDOR_ID_C != EMIOS_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_MBDT_PBcfg.c and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_Cfg.h file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_MBDT_PBcfg.c and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_Cfg.h file are of the same Software version */
#if ((EMIOS_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION)  || \
     (EMIOS_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION_C != EMIOS_PWM_IP_CFG_SW_MINOR_VERSION)  || \
     (EMIOS_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION_C != EMIOS_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_MBDT_PBcfg.c and Emios_Pwm_Ip_Cfg.h are different."
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @brief  Prototypes of Emios channels User Notifications */
extern void Pwm_Ipw_EmiosNotification(uint8 Channel);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#ifndef EMIOS_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*******************************************************************************
 * Emios_0 initialization configuration structures
 ******************************************************************************/

/* Emios PWM mode configuration structure for PwmEmios_0/PwmEmiosChannels_9 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I0_Ch9 =
{
    /* .ChannelId */            9U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)9U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            1000U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/* Emios PWM mode configuration structure for PwmEmios_0/PwmEmiosChannels_17 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I0_Ch17 =
{
    /* .ChannelId */            17U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_2,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)17U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            1000U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/*******************************************************************************
 * Emios_1 initialization configuration structures
 ******************************************************************************/

/* Emios PWM mode configuration structure for PwmEmios_1/PwmEmiosChannels_19 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I1_Ch19 =
{
    /* .ChannelId */            19U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)43U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/* Emios PWM mode configuration structure for PwmEmios_1/PwmEmiosChannels_20 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I1_Ch20 =
{
    /* .ChannelId */            20U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)44U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/* Emios PWM mode configuration structure for PwmEmios_1/PwmEmiosChannels_0 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I1_Ch0 =
{
    /* .ChannelId */            0U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)24U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/* Emios PWM mode configuration structure for PwmEmios_1/PwmEmiosChannels_1 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I1_Ch1 =
{
    /* .ChannelId */            1U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)25U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/* Emios PWM mode configuration structure for PwmEmios_1/PwmEmiosChannels_21 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I1_Ch21 =
{
    /* .ChannelId */            21U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)45U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/* Emios PWM mode configuration structure for PwmEmios_1/PwmEmiosChannels_22 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I1_Ch22 =
{
    /* .ChannelId */            22U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_1,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)46U
                                },
    /* .PeriodCount */          16000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};

/*******************************************************************************
 * Emios_2 initialization configuration structures
 ******************************************************************************/

/* Emios PWM mode configuration structure for PwmEmios_2/PwmEmiosChannels_7 */
const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_MBDT_I2_Ch7 =
{
    /* .ChannelId */            7U,
    /* .Mode */                 EMIOS_PWM_IP_MODE_OPWMB_FLAG,
    /* .Timebase */             EMIOS_PWM_IP_BUS_A,
    /* .DebugMode */            (boolean)FALSE,
    /* .OutputDisableSource */  EMIOS_PWM_IP_OUTPUT_DISABLE_NONE,
    /* .InternalPs */           EMIOS_PWM_IP_CLOCK_DIV_2,
    /* .InternalPsAlternate */  EMIOS_PWM_IP_CLOCK_DIV_2,
    /* .InternalPsSrc */        EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK,
    /* .OutputPolarity */       EMIOS_PWM_IP_ACTIVE_HIGH,
    /* .IrqMode */              EMIOS_PWM_IP_INTERRUPT_REQUEST,
    /* .UserCallback */         {
            /* .CbFunction */       &Pwm_Ipw_EmiosNotification,
            /* .CbParameter */      (uint8)55U
                                },
    /* .PeriodCount */          40000U,
    /* .DutyCycle */            0U,
    /* .PhaseShift */           0U,
    /* .DeadTime */             0U,
    /* .TriggerPosition */      0U
};


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* EMIOS_PWM_IP_PRECOMPILE_SUPPORT */

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

