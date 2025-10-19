/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : none
* Dependencies         : MemAcc
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 5.0.0
* Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
* in accordance with the applicable license terms.  By expressly accepting
* such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain,
* install, activate or otherwise use the software.
*
==================================================================================================*/

#ifndef FEE_CBK_H
#define FEE_CBK_H

/**
*   @file
*
*   @addtogroup FEE
*   @implements Fee_Cbk.h_Artifact
* 
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FEE_CBK_VENDOR_ID                       43
#define FEE_CBK_AR_RELEASE_MAJOR_VERSION        4
#define FEE_CBK_AR_RELEASE_MINOR_VERSION        7
#define FEE_CBK_AR_RELEASE_REVISION_VERSION     0
#define FEE_CBK_SW_MAJOR_VERSION                5
#define FEE_CBK_SW_MINOR_VERSION                0
#define FEE_CBK_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void Fee_JobEndNotification(MemAcc_AddressAreaIdType    AddressAreaId,
                                   MemAcc_JobResultType        JobResult);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _FEE_CBK_H_ */
