/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

#ifndef DSPSS_CFSDADC_MEMORY_MAP_H
#define DSPSS_CFSDADC_MEMORY_MAP_H

/** @cond DRIVER_INTERNAL_USE_ONLY */

/**
*   @file    DSPSS_CFSDADC_MemoryMap.h
*
*   @addtogroup sd_adc_ip Sd Adc IPL
*   @{
*/


#if (defined __cplusplus)
extern "C"
{
#endif
#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DSPSS_VENDOR_ID_CFSADC_MEMORYMAP                      43
#define DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_MEMORYMAP       4
#define DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_MEMORYMAP       7
#define DSPSS_AR_RELEASE_REVISION_VERSION_CFSADC_MEMORYMAP    0
#define DSPSS_SW_MAJOR_VERSION_CFSADC_MEMORYMAP               5
#define DSPSS_SW_MINOR_VERSION_CFSADC_MEMORYMAP               0
#define DSPSS_SW_PATCH_VERSION_CFSADC_MEMORYMAP               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*
                   PMEM DEFAULT MEMORY MAP
*/
/* Thread 0 PC init address */
#define DSPSS_PC_INIT_TH0                       0x0020U
/* Thread 1 PC init address */
#define DSPSS_PC_INIT_TH1                       0x0040U
#if (DSPSS_THREAD_NUM > 2U)
/* Thread 2 PC init address */
#define DSPSS_PC_INIT_TH2                       0x0060U
/* Thread 3 PC init address */
#define DSPSS_PC_INIT_TH3                       0x0080U
#endif /* (DSPSS_THREAD_NUM > 2U) */


/*
                   XMEM DEFAULT MEMORY MAP
I. Fixed address area
______________________________________________________________
|     Area name      |    Buffer name     | Address | Length |
|____________________|____________________|_________|________|
| Thread descriptors | threadDescriptors  |  0000h  |  5D0h  |
|____________________|____________________|_________|________|
| Firmware build tag | CFSDADCFwBuildTag  |  05D0h  |  030h  |
|____________________|____________________|_________|________|

II. Configurable address area
______________________________________________________________
|     Area name      |    Buffer name     | Address | Length |
|____________________|____________________|_________|________|
| Thread 0 area      | bufferInput        |  0600h  |  200h  |
|                    | bufferOutput       |  0800h  |  200h  |
|                    | threadCoreMsgQueue |  0A00h  |  200h  |
|                    | threadWorkArea     |  0C00h  |  800h  |
|                    | stack              |  1400h  |  200h  |
|____________________|____________________|_________|________|
| Thread 1 area      | bufferInput        |  1600h  |  200h  |
|                    | bufferOutput       |  1800h  |  200h  |
|                    | threadCoreMsgQueue |  1A00h  |  200h  |
|                    | threadWorkArea     |  1C00h  |  800h  |
|                    | stack              |  2400h  |  200h  |
|____________________|____________________|_________|________|
| Thread 2 area      | bufferInput        |  2600h  |  200h  |
|                    | bufferOutput       |  2800h  |  200h  |
|                    | threadCoreMsgQueue |  2A00h  |  200h  |
|                    | threadWorkArea     |  2C00h  |  800h  |
|                    | stack              |  3400h  |  200h  |
|____________________|____________________|_________|________|
| Thread 3 area      | bufferInput        |  3600h  |  200h  |
|                    | bufferOutput       |  3800h  |  200h  |
|                    | threadCoreMsgQueue |  3A00h  |  200h  |
|                    | threadWorkArea     |  3C00h  |  800h  |
|                    | stack              |  4400h  |  200h  |
|____________________|____________________|_________|________|
*/

/* Thread descriptors default address */
#define DSPSS_START_ADDRESS_THREAD_DESCRIPTORS          0x0000U
#define DSPSS_MAX_AREA_SIZE_DESCRIPTORS                 0x05D0U

/* CFSDADC firmware build tag address */
#define DSPSS_START_ADDRESS_FIRMWARE_BUILD_TAG          0x05D0U
#define DSPSS_FIRMWARE_BUILD_TAG_SIZE                   0x0030U

/* Thread 0 default address */
#define DSPSS_START_ADDRESS_TH0                         0x0600U
#define DSPSS_MEM_AREA_SIZE_TH0                         0x1000U
#define DSPSS_INPUT_BUFFER_SIZE_TH0                     0x0200U
#define DSPSS_OUTPUT_BUFFER_SIZE_TH0                    0x0200U
#define DSPSS_MSG_QUEUE_BUFFER_SIZE_TH0                 0x0200U
#define DSPSS_WORK_AREA_BUFFER_SIZE_TH0                 0x0800U
#define DSPSS_STACK_START_TH0                           0x1400U
#define DSPSS_STACK_SIZE_TH0                            0x0200U
#if (DSPSS_MEM_AREA_SIZE_TH0 < (DSPSS_INPUT_BUFFER_SIZE_TH0 + DSPSS_OUTPUT_BUFFER_SIZE_TH0 + \
    DSPSS_MSG_QUEUE_BUFFER_SIZE_TH0 + DSPSS_WORK_AREA_BUFFER_SIZE_TH0 + DSPSS_STACK_SIZE_TH0))
    #error Memory area size of thread 0 is too small
#endif

/* Thread 1 default address */
#define DSPSS_START_ADDRESS_TH1                         0x1600U
#define DSPSS_MEM_AREA_SIZE_TH1                         0x1000U
#define DSPSS_INPUT_BUFFER_SIZE_TH1                     0x0200U
#define DSPSS_OUTPUT_BUFFER_SIZE_TH1                    0x0200U
#define DSPSS_MSG_QUEUE_BUFFER_SIZE_TH1                 0x0200U
#define DSPSS_WORK_AREA_BUFFER_SIZE_TH1                 0x0800U
#define DSPSS_STACK_START_TH1                           0x2400U
#define DSPSS_STACK_SIZE_TH1                            0x0200U
#if (DSPSS_MEM_AREA_SIZE_TH1 < (DSPSS_INPUT_BUFFER_SIZE_TH1 + DSPSS_OUTPUT_BUFFER_SIZE_TH1 + \
    DSPSS_MSG_QUEUE_BUFFER_SIZE_TH1 + DSPSS_WORK_AREA_BUFFER_SIZE_TH1 + DSPSS_STACK_SIZE_TH1))
    #error Memory area size of thread 1 is too small
#endif

#if (DSPSS_THREAD_NUM > 2U)
/* Thread 2 default address */
#define DSPSS_START_ADDRESS_TH2                         0x2600U
#define DSPSS_MEM_AREA_SIZE_TH2                         0x1000U
#define DSPSS_INPUT_BUFFER_SIZE_TH2                     0x0200U
#define DSPSS_OUTPUT_BUFFER_SIZE_TH2                    0x0200U
#define DSPSS_MSG_QUEUE_BUFFER_SIZE_TH2                 0x0200U
#define DSPSS_WORK_AREA_BUFFER_SIZE_TH2                 0x0800U
#define DSPSS_STACK_START_TH2                           0x3400U
#define DSPSS_STACK_SIZE_TH2                            0x0200U
#if (DSPSS_MEM_AREA_SIZE_TH2 < (DSPSS_INPUT_BUFFER_SIZE_TH2 + DSPSS_OUTPUT_BUFFER_SIZE_TH2 + \
    DSPSS_MSG_QUEUE_BUFFER_SIZE_TH2 + DSPSS_WORK_AREA_BUFFER_SIZE_TH2 + DSPSS_STACK_SIZE_TH2))
    #error Memory area size of thread 2 is too small
#endif

/* Thread 3 default address */
#define DSPSS_START_ADDRESS_TH3                         0x3600U
#define DSPSS_MEM_AREA_SIZE_TH3                         0x1000U
#define DSPSS_INPUT_BUFFER_SIZE_TH3                     0x0200U
#define DSPSS_OUTPUT_BUFFER_SIZE_TH3                    0x0200U
#define DSPSS_MSG_QUEUE_BUFFER_SIZE_TH3                 0x0200U
#define DSPSS_WORK_AREA_BUFFER_SIZE_TH3                 0x0800U
#define DSPSS_STACK_START_TH3                           0x4400U
#define DSPSS_STACK_SIZE_TH3                            0x0200U
#if (DSPSS_MEM_AREA_SIZE_TH3 < (DSPSS_INPUT_BUFFER_SIZE_TH3 + DSPSS_OUTPUT_BUFFER_SIZE_TH3 + \
    DSPSS_MSG_QUEUE_BUFFER_SIZE_TH3 + DSPSS_WORK_AREA_BUFFER_SIZE_TH3 + DSPSS_STACK_SIZE_TH3))
    #error Memory area size of thread 3 is too small
#endif
#endif /* (DSPSS_THREAD_NUM > 2U) */

/* Memory sizes defines */
#define SIZE_8K                               8192U
#define SIZE_16K                              16384U
#define SIZE_32K                              32768U

/* PMEM Defines: Pmem memory size is 32Kb , and its accessible IPS slot .. so it has 2 IPS slot on AIPS3 */
#define PMEM_SIZE                             SIZE_32K
#define PMEM_0_BASEADDRESS                    0x406E0000U   /* Ips Slot first*/
#define PMEM_0_MIDADDRESS                     0x406E2000U   /* Ips Slot first*/
#define PMEM_0_ENDADDRESS                     0x406E3FFCU
#define PMEM_1_BASEADDRESS                    0x406E4000U   /* IPS slot second*/
#define PMEM_1_MIDADDRESS                     0x406E6000U   /* IPS slot second*/
#define PMEM_1_ENDADDRESS                     0x406E7FFCU

/* XMEM Defines: Xmem memory size is 24Kb , and its accessible IPS slot .. so it has 2 IPS slot on AIPS3 */
#define XMEM_SIZE                             (SIZE_16K + SIZE_8K)
#define XMEM_0_BASEADDRESS                    0x406E8000U   /* Ips Slot first*/
#define XMEM_0_MIDADDRESS                     0x406EA000U   /* Ips Slot first*/
#define XMEM_0_ENDADDRESS                     0x406EBFFCU
#define XMEM_1_BASEADDRESS                    0x406EC000U   /* IPS slot second ; Only 8Kb is used*/
#define XMEM_1_MIDADDRESS                     0x406ED000U   /* IPS slot second ; Only 8Kb is used*/
#define XMEM_1_ENDADDRESS                     0x406EDFFCU

#define XMEM_1_UNUSED_BASEADDRESS             0x406EE000U   /* 8 kb out of 16kb is reserved ; so using these defines to access reserved spaces*/
#define XMEM_1_UNUSED_ENDADDRESS              0x406EFFFCU

/* DMA Defines */
#define DMA_DSPSS_TH0                         0x20404000U
#define DMA_DSPSS_TH1                         0x20404100U
#if (DSPSS_THREAD_NUM > 2U)
#define DMA_DSPSS_TH2                         0x20404200U
#define DMA_DSPSS_TH3                         0x20404300U
#endif /* (DSPSS_THREAD_NUM > 2U) */
#define DMA_DSPSS_SF0                         0x20404400U
#define DMA_DSPSS_SF1                         0x20404500U
#endif /* SDADC_IP_DSPSS_ENABLED == STD_ON */

#if (defined __cplusplus)
}
#endif

/** @} */
/** @endcond */

#endif /* DSPSS_CFSDADC_MEMORY_MAP_H */

