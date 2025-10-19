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

/**
*   @file    Cache_Ip_HwAcc_ArmCoreMx.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Cache Ip driver header file.
*   @details
*
*   @addtogroup CACHE_IP_DRIVER CACHE IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cache_Ip_HwAcc_ArmCoreMx.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID_C                       43
#define CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION_C        4
#define CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION_C        7
#define CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION_C     0
#define CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION_C                5
#define CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION_C                0
#define CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Cache_Ip_HwAcc_ArmCoreMx.h file are of the same vendor */
#if (CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID_C != CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID)
    #error "Cache_Ip_HwAcc_ArmCoreMx.c and Cache_Ip_HwAcc_ArmCoreMx.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip_HwAcc_ArmCoreMx.h file are of the same Autosar version */
#if ((CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_HwAcc_ArmCoreMx.c and Cache_Ip_HwAcc_ArmCoreMx.h are different"
#endif

/* Check if header file and Cache_Ip_HwAcc_ArmCoreMx.h file are of the same Software version */
#if ((CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_HwAcc_ArmCoreMx.c and Cache_Ip_HwAcc_ArmCoreMx.h are different"
#endif

#if (STD_ON == CACHE_IP_IS_AVAILABLE)

#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/* Data Cache masks */
#define DCACHE_CCR_EN_MASK             ((uint32)1U << 16U)
#define DCACHE_CSSELR_EN(x)            ((uint32)((x) & (~1U)))
#define DCACHE_DCCXSW_SET_MASK         ((uint32)0x3FE0U)
#define DCACHE_DCCXSW_SET_SHIFT        ((uint32)5U)
#define DCACHE_DCCXSW_WAY_MASK         ((uint32)0xC0000000U)
#define DCACHE_DCCXSW_WAY_SHIFT        ((uint32)30U)
/* Instruction Cache masks */
#define ICACHE_CCR_EN_MASK             ((uint32)1U << 17U)
#define ICACHE_CSSELR_EN(x)            ((uint32)((x) | 1U))
/* Cache set, way and line size */
#define CACHE_CCSIDR_SET_MASK          ((uint32)0xFFFE000U)
#define CACHE_CCSIDR_SET_SHIFT         ((uint32)13U)
#define CACHE_CCSIDR_SET_SIZE(x)       ((uint32)((((uint32)(x) & CACHE_CCSIDR_SET_MASK) >> CACHE_CCSIDR_SET_SHIFT) + 1U))
#define CACHE_CCSIDR_WAY_MASK          ((uint32)0x1FF8U)
#define CACHE_CCSIDR_WAY_SHIFT         ((uint32)3U)
#define CACHE_CCSIDR_WAY_SIZE(x)       ((uint32)((((uint32)(x) & CACHE_CCSIDR_WAY_MASK) >> CACHE_CCSIDR_WAY_SHIFT) + 1U))
#define CACHE_CCSIDR_LINE_SIZE_MASK    ((uint32)0x7U)
#define CACHE_CCSIDR_LINE_SHIFT        ((uint32)0U)
#define CACHE_CCSIDR_LINE_SIZE(x)      ((uint32)((((((uint32)(x) & CACHE_CCSIDR_LINE_SIZE_MASK) >> CACHE_CCSIDR_LINE_SHIFT) + 1U) * 4U) * 4U))


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

void hwAcc_ArmCoreMx_InstructionCacheInvalidate(void)
{
    /* CACHE Type shall be selected before any other operation */
    S32_SCB->CSSELR = ICACHE_CSSELR_EN(S32_SCB->CSSELR);
    S32_SCB->ICIALLU = 0UL;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

void hwAcc_ArmCoreMx_DataCacheInvalidate(void)
{
    uint32 cacheSetSize;
    uint32 cacheWaySize;
    uint32 setIdx;
    uint32 wayIdx;
    uint32 invalidate;

    /* CACHE Type shall be selected before any other operation */
    S32_SCB->CSSELR = DCACHE_CSSELR_EN(S32_SCB->CSSELR);
    MCAL_DATA_SYNC_BARRIER();
    cacheSetSize = CACHE_CCSIDR_SET_SIZE(S32_SCB->CCSIDR);
    cacheWaySize = CACHE_CCSIDR_WAY_SIZE(S32_SCB->CCSIDR);
    for(setIdx = 0; setIdx < cacheSetSize; setIdx++)
    {
        for(wayIdx = 0; wayIdx < cacheWaySize; wayIdx++)
        {
            invalidate = ((setIdx << DCACHE_DCCXSW_SET_SHIFT) & DCACHE_DCCXSW_SET_MASK);
            invalidate |= ((wayIdx << DCACHE_DCCXSW_WAY_SHIFT) & DCACHE_DCCXSW_WAY_MASK);
            S32_SCB->DCISW = invalidate;
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
        }
    }
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

void hwAcc_ArmCoreMx_InstructionCacheClean(const boolean enInvalidate)
{
    if(TRUE == enInvalidate)
    {
        /* Invalidate instruction cache */
        hwAcc_ArmCoreMx_InstructionCacheInvalidate();
    }
}

void hwAcc_ArmCoreMx_DataCacheClean(const boolean enInvalidate)
{
    uint32 cacheSetSize;
    uint32 cacheWaySize;
    uint32 setIdx;
    uint32 wayIdx;
    uint32 clean;
    volatile uint32 * pDataCacheClean;

    /* CACHE Type shall be selected before any other operation */
    S32_SCB->CSSELR = DCACHE_CSSELR_EN(S32_SCB->CSSELR);
    MCAL_DATA_SYNC_BARRIER();
    cacheSetSize = CACHE_CCSIDR_SET_SIZE(S32_SCB->CCSIDR);
    cacheWaySize = CACHE_CCSIDR_WAY_SIZE(S32_SCB->CCSIDR);
    if(TRUE == enInvalidate)
    {
        pDataCacheClean = (volatile uint32*)&S32_SCB->DCCISW;
    }
    else
    {
        pDataCacheClean = (volatile uint32*)&S32_SCB->DCCSW;
    }
    for(setIdx = 0; setIdx < cacheSetSize; setIdx++)
    {
        for(wayIdx = 0; wayIdx < cacheWaySize; wayIdx++)
        {
            clean = ((setIdx << DCACHE_DCCXSW_SET_SHIFT) & DCACHE_DCCXSW_SET_MASK);
            clean |= ((wayIdx << DCACHE_DCCXSW_WAY_SHIFT) & DCACHE_DCCXSW_WAY_MASK);
            *pDataCacheClean = clean;
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
        }
    }
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

void hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr(const uint32 addr, const uint32 length)
{
    uint32 cacheLineSize;
    sint32 op_size;
    uint32 op_addr;
    uint32 tmp_size;

    cacheLineSize = CACHE_CCSIDR_LINE_SIZE(S32_SCB->CCSIDR);

    if (length > 0U) 
    {
        tmp_size = length + (((uint32)addr) & (cacheLineSize - 1U));
        op_size = (sint32)tmp_size;
        op_addr = (uint32)addr;

        MCAL_DATA_SYNC_BARRIER();

        do {
            S32_SCB->ICIMVAU = op_addr;      /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr += cacheLineSize;
            op_size -= (sint32)cacheLineSize;
        } while (op_size > 0);

      MCAL_DATA_SYNC_BARRIER();
      MCAL_INSTRUCTION_SYNC_BARRIER();
    }
}

void hwAcc_ArmCoreMx_DataCacheInvalidateByAddr(const uint32 addr, const uint32 length)
{
    uint32 cacheLineSize;
    sint32 op_size;
    uint32 op_addr;
    uint32 tmp_size;

    /* CACHE Type shall be selected before any other operation */
    S32_SCB->CSSELR = DCACHE_CSSELR_EN(S32_SCB->CSSELR);
    MCAL_DATA_SYNC_BARRIER();
    cacheLineSize = CACHE_CCSIDR_LINE_SIZE(S32_SCB->CCSIDR);

    if (length > 0U)
    {
        tmp_size = length + (((uint32)addr) & (cacheLineSize - 1U));
        op_size = (sint32)tmp_size;
        op_addr = (uint32)addr;

        MCAL_DATA_SYNC_BARRIER();

        do {
            S32_SCB->DCIMVAC = op_addr;      /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr += cacheLineSize;
            op_size -= (sint32)cacheLineSize;
        } while (op_size > 0);

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
}

void hwAcc_ArmCoreMx_InstructionCacheCleanByAddr(const boolean enInvalidate, const uint32 addr, const uint32 length)
{
    if(TRUE == enInvalidate)
    {
        /* Invalidate Instruction Cache By Address */
        hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr(addr, length);
    }
}

void hwAcc_ArmCoreMx_DataCacheCleanByAddr(const boolean enInvalidate, const uint32 addr, const uint32 length)
{
    uint32 cacheLineSize;
    sint32 op_size;
    uint32 op_addr;
    uint32 tmp_size;

    /* CACHE Type shall be selected before any other operation */
    S32_SCB->CSSELR = DCACHE_CSSELR_EN(S32_SCB->CSSELR);
    MCAL_DATA_SYNC_BARRIER();
    cacheLineSize = CACHE_CCSIDR_LINE_SIZE(S32_SCB->CCSIDR);

    if (length > 0U)
    {
        tmp_size = length + (((uint32)addr) & (cacheLineSize - 1U));
        op_size = (sint32)tmp_size;
        op_addr = (uint32)addr;

        MCAL_DATA_SYNC_BARRIER();

        do {
            if(TRUE == enInvalidate)
            {
                S32_SCB->DCCIMVAC = op_addr;    /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            }
            else
            {
                S32_SCB->DCCMVAC = op_addr;     /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            }
            op_addr += cacheLineSize;
            op_size -= (sint32)cacheLineSize;
        } while (op_size > 0);

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
}

void hwAcc_ArmCoreMx_InstructionCacheEnable(void)
{
    /* Enable Instruction Cache */
    S32_SCB->CCR |= ICACHE_CCR_EN_MASK;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

void hwAcc_ArmCoreMx_DataCacheEnable(void)
{
    /* Enable Data Cache */
    S32_SCB->CCR |= DCACHE_CCR_EN_MASK;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

void hwAcc_ArmCoreMx_InstructionCacheDisable(void)
{
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    /* Disable Instruction Cache */
    S32_SCB->CCR &= ~ICACHE_CCR_EN_MASK;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

void hwAcc_ArmCoreMx_DataCacheDisable(void)
{
    /* Disable Data Cache */
    S32_SCB->CCR &= ~DCACHE_CCR_EN_MASK;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#endif /* #if (CACHE_IP_ARMCOREMX_IS_AVAILABLE == STD_ON) */

#endif /* #if (CACHE_IP_IS_AVAILABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
