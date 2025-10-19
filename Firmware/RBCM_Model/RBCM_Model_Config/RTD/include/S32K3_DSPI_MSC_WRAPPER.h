/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
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

#ifndef S32K3_DSPI_MSC_WRAPPER_H
#define S32K3_DSPI_MSC_WRAPPER_H

/**
*   @file    S32K3_DSPI_MSC_WRAPPER.h
*
*   @brief   DSPI IP driver types header file.
*   @details DSPI IP driver types header file.

*   @addtogroup DSPI_DRIVER Dspi Driver
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
#include "S32K39_DSPI_MSC.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DSPI_MCR_FCPCS_MASK                      (0x4U)
#define DSPI_MCR_FCPCS_SHIFT                     (2U)
#define DSPI_MCR_FCPCS_WIDTH                     (1U)
#define DSPI_MCR_FCPCS(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_FCPCS_SHIFT)) & DSPI_MCR_FCPCS_MASK)

#define DSPI_MCR_SMPL_PT_MASK                    (0x300U)
#define DSPI_MCR_SMPL_PT_SHIFT                   (8U)
#define DSPI_MCR_SMPL_PT_WIDTH                   (2U)
#define DSPI_MCR_SMPL_PT(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_SMPL_PT_SHIFT)) & DSPI_MCR_SMPL_PT_MASK)

#define DSPI_MCR_MTFE_MASK                       (0x4000000U)
#define DSPI_MCR_MTFE_SHIFT                      (26U)
#define DSPI_MCR_MTFE_WIDTH                      (1U)
#define DSPI_MCR_MTFE(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_MTFE_SHIFT)) & DSPI_MCR_MTFE_MASK)

#define DSPI_PUSHR_PP_MCSC_MASK                  DSPI_PUSHR_PP_MASK
#define DSPI_PUSHR_PP_MCSC_SHIFT                 DSPI_PUSHR_PP_SHIFT
#define DSPI_PUSHR_PP_MCSC_WIDTH                 DSPI_PUSHR_PP_WIDTH
#define DSPI_PUSHR_PP_MCSC(x)                    DSPI_PUSHR_PP(x)

#define DSPI_PUSHR_PE_MASC_MASK                  DSPI_PUSHR_PE_MASK
#define DSPI_PUSHR_PE_MASC_SHIFT                 DSPI_PUSHR_PE_SHIFT
#define DSPI_PUSHR_PE_MASC_WIDTH                 DSPI_PUSHR_PE_WIDTH
#define DSPI_PUSHR_PE_MASC(x)                    DSPI_PUSHR_PE(x)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*S32K3_DSPI_MSC_WRAPPER*/
