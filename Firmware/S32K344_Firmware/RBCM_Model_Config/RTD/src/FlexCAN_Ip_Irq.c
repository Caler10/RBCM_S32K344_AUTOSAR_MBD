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
 *  @file FlexCAN_Ip_Irq.c
 *
 *  @brief FlexCAN Interrupts
 *
 *  @addtogroup FlexCAN
 *  @{
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexCAN_Ip_Irq.h"
#include "FlexCAN_Ip_HwAccess.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_IRQ_VENDOR_ID_C                      43
#define FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_C               5
#define FLEXCAN_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXCAN_IP_IRQ_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_Irq header file are of the same vendor */
#if (FLEXCAN_IP_IRQ_VENDOR_ID_C != FLEXCAN_IP_IRQ_VENDOR_ID_H)
    #error "FlexCAN_Ip_Irq.c and FlexCAN_Ip_Irq.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_Irq header file are of the same Autosar version */
#if ((FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_Irq.h are different"
#endif
/* Check if current file and FlexCAN_Ip_Irq header file are of the same Software version */
#if ((FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_C != FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_MINOR_VERSION_C != FLEXCAN_IP_IRQ_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_PATCH_VERSION_C != FLEXCAN_IP_IRQ_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_Irq.h are different"
#endif

/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same vendor */
#if (FLEXCAN_IP_IRQ_VENDOR_ID_C != FLEXCAN_IP_HWACCESS_VENDOR_ID_H)
    #error "FlexCAN_Ip_Irq.c and FlexCAN_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same Autosar version */
#if ((FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_HwAccess.h are different"
#endif
/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same Software version */
#if ((FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_C != FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_MINOR_VERSION_C != FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_PATCH_VERSION_C != FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_HwAccess.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

ISR(CAN0_ORED_IRQHandler);

ISR(CAN0_ORED_0_31_MB_IRQHandler);

ISR(CAN0_ORED_32_63_MB_IRQHandler);

#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U)
ISR(CAN0_ORED_64_95_MB_IRQHandler);
#endif /* (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 1U)
ISR(CAN1_ORED_IRQHandler);

ISR(CAN1_ORED_0_31_MB_IRQHandler);

ISR(CAN1_ORED_32_63_MB_IRQHandler);

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
ISR(CAN1_ORED_64_95_MB_IRQHandler);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 1U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 2U)
ISR(CAN2_ORED_IRQHandler);

ISR(CAN2_ORED_0_31_MB_IRQHandler);

ISR(CAN2_ORED_32_63_MB_IRQHandler);

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
ISR(CAN2_ORED_64_95_MB_IRQHandler);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 2U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 3U)
ISR(CAN3_ORED_IRQHandler);

ISR(CAN3_ORED_0_31_MB_IRQHandler);

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
ISR(CAN3_ORED_32_63_MB_IRQHandler);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 3U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 4U)
ISR(CAN4_ORED_IRQHandler);

ISR(CAN4_ORED_0_31_MB_IRQHandler);

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
ISR(CAN4_ORED_32_63_MB_IRQHandler);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 4U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 5U)
ISR(CAN5_ORED_IRQHandler);

ISR(CAN5_ORED_0_31_MB_IRQHandler);

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
ISR(CAN5_ORED_32_63_MB_IRQHandler);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 5U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 6U)
ISR(CAN6_ORED_IRQHandler);

ISR(CAN6_ORED_0_31_MB_IRQHandler);

ISR(CAN6_ORED_32_63_MB_IRQHandler);
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 6U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 7U)
ISR(CAN7_ORED_IRQHandler);

ISR(CAN7_ORED_0_31_MB_IRQHandler);

ISR(CAN7_ORED_32_63_MB_IRQHandler);
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 7U) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Implementation of CAN0 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN0_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(0U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(0U);
#endif
}

/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN0_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 0U, 31U, TRUE);
}

/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN0_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 32U, 63U, FALSE);
}

#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U)
/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 64-95. */
ISR(CAN0_ORED_64_95_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 64U, 95U, FALSE);
}
#endif /* #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 1U)
/* Implementation of CAN1 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN1_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(1U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(1U);
#endif
}

/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN1_ORED_0_31_MB_IRQHandler)
{
#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
    FlexCAN_IRQHandler(1U, 0U, 31U, TRUE);
#else
    FlexCAN_IRQHandler(1U, 0U, 31U, FALSE);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
}

/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN1_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(1U, 32U, 63U, FALSE);
}

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 64-95. */
ISR(CAN1_ORED_64_95_MB_IRQHandler)
{
    FlexCAN_IRQHandler(1U, 64U, 95U, FALSE);
}
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 1U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 2U)
/* Implementation of CAN2 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN2_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(2U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(2U);
#endif
}

/* Implementation of CAN2 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN2_ORED_0_31_MB_IRQHandler)
{
#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
    FlexCAN_IRQHandler(2U, 0U, 31U, TRUE);
#else
    FlexCAN_IRQHandler(2U, 0U, 31U, FALSE);
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
}

/* Implementation of CAN2 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN2_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(2U, 32U, 63U, FALSE);
}

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
/* Implementation of CAN2 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 64-95. */
ISR(CAN2_ORED_64_95_MB_IRQHandler)
{
    FlexCAN_IRQHandler(2U, 64U, 95U, FALSE);
}
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 2U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 3U)
/* Implementation of CAN3 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN3_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(3U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(3U);
#endif
}

/* Implementation of CAN3 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN3_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(3U, 0U, 31U, FALSE);
}

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
/* Implementation of CAN3 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN3_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(3U, 32U, 63U, FALSE);
}
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 3U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 4U)
/* Implementation of CAN4 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN4_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(4U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(4U);
#endif
}

/* Implementation of CAN4 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN4_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(4U, 0U, 31U, FALSE);
}

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
/* Implementation of CAN4 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN4_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(4U, 32U, 63U, FALSE);
}
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 4U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 5U)
/* Implementation of CAN5 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN5_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(5U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(5U);
#endif
}

/* Implementation of CAN5 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN5_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(5U, 0U, 31U, FALSE);
}

#if (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
     defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376))
/* Implementation of CAN5 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN5_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(5U, 32U, 63U, FALSE);
}
#endif /* (defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358) || defined(S32K388) || \
           defined(S32K364) || defined(S32K366) || defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376)) */
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 5U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 6U)
/* Implementation of CAN6 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN6_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(6U);
    #if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(6U);
#endif
}

/* Implementation of CAN6 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN6_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(6U, 0U, 31U, FALSE);
}

/* Implementation of CAN6 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN6_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(6U, 32U, 63U, FALSE);
}
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 6U) */

#if (FLEXCAN_IP_INSTANCE_COUNT > 7U)
/* Implementation of CAN7 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN7_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(7U);
#if (FLEXCAN_IP_FEATURE_MEM_ERR_DET_ENABLED == STD_ON)
    FlexCAN_MemError_IRQHandler(7U);
#endif
}

/* Implementation of CAN7 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. */
ISR(CAN7_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(7U, 0U, 31U, FALSE);
}

/* Implementation of CAN7 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-63. */
ISR(CAN7_ORED_32_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(7U, 32U, 63U, FALSE);
}
#endif /* (FLEXCAN_IP_INSTANCE_COUNT > 7U) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

/** @} */
