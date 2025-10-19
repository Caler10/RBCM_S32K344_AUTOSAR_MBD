/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
* @file
*
* @brief FlexCAN Registers and Default Reg Values
* @details <File details>
*
* @addtogroup FlexCAN
* @{
*/
#ifndef FLEXCAN_IP_DEVICEREG_H_
#define FLEXCAN_IP_DEVICEREG_H_

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "FlexCAN_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_DEVICEREG_VENDOR_ID_H                      43
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H               5
#define FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same vendor */
#if (FLEXCAN_IP_DEVICEREG_VENDOR_ID_H != FLEXCAN_IP_CFGDEFINES_VENDOR_ID_H)
    #error "FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h are different"
#endif
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same Software version */
#if ((FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H    != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Default value for register */
/**
* @brief Default value for the MCR register
*/
#define FLEXCAN_IP_MCR_DEFAULT_VALUE_U32               ((uint32)0xD890000FU)

/**
* @brief Default value for the CTRL1 register
*/
#define FLEXCAN_IP_CTRL1_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the TIMER register
*/
#define FLEXCAN_IP_TIMER_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ECR register
*/
#define FLEXCAN_IP_ECR_DEFAULT_VALUE_U32               ((uint32)0x00000000U)

/**
* @brief Default value for the ESR1 register
*/
#define FLEXCAN_IP_ESR1_DEFAULT_VALUE_U32              ((uint32)0x0003B006U)

/**
* @brief Default value for the IMASK2 register
*/
#define FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the IFLAG4 register
*/
#define FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32             ((uint32)0xFFFFFFFFU)

/**
* @brief Default value for the CTRL2 register
*/
#define FLEXCAN_IP_CTRL2_DEFAULT_VALUE_U32             ((uint32)0x00100000U)

/**
* @brief Default value for the CTRL2 register
*/
#define FLEXCAN_IP_CBT_DEFAULT_VALUE_U32               ((uint32)0x00000000U)

/**
* @brief Default value for the MECR register
*/
#define FLEXCAN_IP_MECR_DEFAULT_VALUE_U32              ((uint32)0x000C0080U)

/**
* @brief Default value for the ERRIAR register
*/
#define FLEXCAN_IP_ERRIAR_DEFAULT_VALUE_U32            ((uint32)0x00000000U)

/**
* @brief Default value for the ERRIDPR register
*/
#define FLEXCAN_IP_ERRIDPR_DEFAULT_VALUE_U32           ((uint32)0x00000000U)

/**
* @brief Default value for the ERRIPPR register
*/
#define FLEXCAN_IP_ERRIPPR_DEFAULT_VALUE_U32           ((uint32)0x00000000U)

/**
* @brief Default value for the ERRSR register
*/
#define FLEXCAN_IP_ERRSR_DEFAULT_VALUE_U32             ((uint32)0x000D000DU)

/**
* @brief Default value for the FDCTRL register
*/
#define FLEXCAN_IP_FDCTRL_DEFAULT_VALUE_U32            ((uint32)0x80004100U)

/**
* @brief Default value for the FDCBT register
*/
#define FLEXCAN_IP_FDCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ERFCR register
*/
#define FLEXCAN_IP_ERFCR_DEFAULT_VALUE_U32            ((uint32)0x00000000U)

/**
* @brief Default value for the ERFIER register
*/
#define FLEXCAN_IP_ERFIER_DEFAULT_VALUE_U32            ((uint32)0x00000000U)

/**
* @brief Default value for the ERFSR register
*/
#define FLEXCAN_IP_ERFSR_DEFAULT_VALUE_U32             ((uint32)0xF8000000U)

/**
* @brief Default value for the EPRS register
*/
#define FLEXCAN_IP_EPRS_DEFAULT_VALUE_U32              ((uint32)0x00000000U)

/**
* @brief Default value for the ENCBT register
*/
#define FLEXCAN_IP_ENCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the EDCBT register
*/
#define FLEXCAN_IP_EDCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ETDC register
*/
#define FLEXCAN_IP_ETDC_DEFAULT_VALUE_U32              ((uint32)0x00000000U)

/* Workaround for consistency of naming between platforms */
/** Number of FLEXCAN instance */
#define FLEXCAN_IP_INSTANCE_COUNT                      FLEXCAN_INSTANCE_COUNT
/** Array initializer of FLEXCAN peripheral base pointers */
#define FLEXCAN_IP_BASE_PTRS                           IP_FLEXCAN_BASE_PTRS

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || \
     defined(S32K388))
    /* @brief number of CAN peripheral has Enhanced Rx FIFO mode */
    #define FLEXCAN_IP_FEATURE_ENHANCED_RX_FIFO_NUM            (3u)
    /** Array initializer of CAN peripheral base addresses has Enhanced Rx FIFO mode*/
    #define FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO       { IP_CAN_0, IP_CAN_1, IP_CAN_2 }
#else
    /* @brief number of CAN peripheral has Enhanced Rx FIFO mode */
    #define FLEXCAN_IP_FEATURE_ENHANCED_RX_FIFO_NUM            (1u)
    /** Array initializer of CAN peripheral base addresses has Enhanced Rx FIFO mode*/
    #define FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO       { IP_CAN_0 }
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || \
           defined(S32K388)) */

#define FLEXCAN_IP_FEATURE_BUSOFF_ERROR_INTERRUPT_UNIFIED      (STD_ON)

/* specifies if the Enhanced Fifo has separated ISR */
#define FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO_INT_SEPARATED    (STD_OFF)

/* This has not appeared in the errata of the S32K3 and S32M27 platform but was described in the reference manual.
   To ensure the hardware operates properly, the driver shall treat this as an errata. */
#if (defined(S32K344) || defined(S32K396) || defined(S32M274) || defined(S32M276))
    #ifndef ERR_IPV_FLEXCAN_E050630
        /* While using FlexCAN timestamp feature, the message buffers should be unlocked within each 20 CAN bits.
         * A failure to do so while using FlexCAN timestamp feature alongwith FlexCAN RX FIFO or enhanced RX FIFO
         * might result in timestamp information being missed. */
        #define ERR_IPV_FLEXCAN_E050630 (STD_ON)
    #endif
#endif /* (defined(S32K344) || defined(S32K396) || defined(S32M274) || defined(S32M276)) */

/* Workaround for difference base address naming defined in BASE */
/** Peripheral FLEXCAN_0 base address */
#define FLEXCAN_0_BASE IP_CAN_0_BASE
#if FLEXCAN_IP_INSTANCE_COUNT > 1U
/** Peripheral FLEXCAN_1 base address */
#define FLEXCAN_1_BASE IP_CAN_1_BASE
#endif
#if FLEXCAN_IP_INSTANCE_COUNT > 2U
/** Peripheral FLEXCAN_2 base address */
#define FLEXCAN_2_BASE IP_CAN_2_BASE
#endif
#if FLEXCAN_IP_INSTANCE_COUNT > 3U
/** Peripheral FLEXCAN_3 base address */
#define FLEXCAN_3_BASE IP_CAN_3_BASE
#endif
#if FLEXCAN_IP_INSTANCE_COUNT > 4U
/** Peripheral FLEXCAN_4 base address */
#define FLEXCAN_4_BASE IP_CAN_4_BASE
#endif
#if FLEXCAN_IP_INSTANCE_COUNT > 5U
/** Peripheral FLEXCAN_5 base address */
#define FLEXCAN_5_BASE IP_CAN_5_BASE
#endif
#if FLEXCAN_IP_INSTANCE_COUNT > 6U
/** Peripheral FLEXCAN_6 base address */
#define FLEXCAN_6_BASE IP_CAN_6_BASE
#endif
#if FLEXCAN_IP_INSTANCE_COUNT > 7U
/** Peripheral FLEXCAN_7 base address */
#define FLEXCAN_7_BASE IP_CAN_7_BASE
#endif

/* Registers used By Timestamp HR source in FlexCAN_ConfigTimestampModule */
#define FLEXCAN_IP_TIMESTAMP_REG IP_DCM_GPR->DCMRWF1
#define FLEXCAN_IP_TIMESTAMP_SEL(x) DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL(x)
#define FLEXCAN_IP_TIMESTAMP_EN_MASK DCM_GPR_DCMRWF1_CAN_TIMESTAMP_EN_MASK
#define FLEXCAN_IP_TIMESTAMP_SEL_MASK DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL_MASK

#endif /* FLEXCAN_IP_DEVICEREG_H_ */
/** @} */
