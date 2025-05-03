/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   (c) Copyright 2020 - 2024 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef LIN_IF_H
#define LIN_IF_H

/**
*   @file   LinIf.h
*
*   @addtogroup  LINIF
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Lin_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section Lin_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Lin_C_REF_3
* Violates MISRA 2004 Advisory Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStackTypes.h"
#include "Lin_GeneralTypes.h"
#include "EcuM.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           LinIf.h
* @requirements   LINIF383
*/
#define LINIF_VENDOR_ID                      43
#define LINIF_MODULE_ID                      62
#define LINIF_AR_RELEASE_MAJOR_VERSION       4
#define LINIF_AR_RELEASE_MINOR_VERSION       7
#define LINIF_AR_RELEASE_REVISION_VERSION    0
#define LINIF_SW_MAJOR_VERSION               5
#define LINIF_SW_MINOR_VERSION               0
#define LINIF_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/           
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Lin_GeneralTypes header file are of the same Autosar version */
    #if ((LINIF_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (LINIF_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LinIf.h and Lin_GeneralTypes.h are different"
    #endif
    /* Check if current file and EcuM header file are of the same version */
    #if ((LINIF_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
         (LINIF_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinIf.h and EcuM.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define LINIF_WAKEUP_SUPPORT (STD_ON)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource);
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType* PduPtr);
void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr);
void LinIf_TxConfirmation(NetworkHandleType Channel);
void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_IF_H */
