/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_TYPES_H_
#define TRGMUX_IP_TYPES_H_

/**
*   @file    Trgmux_Ip_Types.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver header file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
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
#include "Std_Types.h"
#include "Mcal.h"
#include "Trgmux_Ip_Cfg_Defines.h"
#include "Trgmux_Ip_Cfg_DeviceRegisters.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_TYPES_VENDOR_ID                    43
#define TRGMUX_IP_TYPES_MODULE_ID                    255
#define TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_TYPES_SW_MAJOR_VERSION             5
#define TRGMUX_IP_TYPES_SW_MINOR_VERSION             0
#define TRGMUX_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types header file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Std_Types.h are different"
#endif

/* Check if header file and Mcal header file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same vendor */
#if (TRGMUX_IP_TYPES_VENDOR_ID != TRGMUX_IP_CFG_DEFINES_VENDOR_ID)
    #error "Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Software version */
#if ((TRGMUX_IP_TYPES_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_DeviceRegisters.h file are of the same vendor */
#if (TRGMUX_IP_TYPES_VENDOR_ID != TRGMUX_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_DeviceRegisters.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg_DeviceRegisters.h file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_DeviceRegisters.h file are of the same Software version */
#if ((TRGMUX_IP_TYPES_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_DeviceRegisters.h are different"
#endif

#if (STD_ON == TRGMUX_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
typedef enum{
    TRGMUX_IP_STATUS_SUCCESS = 0U,
    TRGMUX_IP_STATUS_LOCKED  = 1U,
#if (STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE)
    TRGMUX_IP_STATUS_WRONG_CORE   = 2U,
#endif /* STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE */
}Trgmux_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct{
    uint8 LogicChannel;
    uint8 Output;
    uint8 Input;
    uint8 HwInstId;
    boolean Lock;
#if (STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE)
    uint8 UserId;
#endif /* STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE */
}Trgmux_Ip_LogicTriggerType;

typedef struct{
    const Trgmux_Ip_LogicTriggerType * const paxLogicTrigger[TRGMUX_IP_NOF_CFG_LOGIC_TRIGGERS];
}Trgmux_Ip_InitType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* TRGMUX_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef TRGMUX_IP_TYPES_H_ */
