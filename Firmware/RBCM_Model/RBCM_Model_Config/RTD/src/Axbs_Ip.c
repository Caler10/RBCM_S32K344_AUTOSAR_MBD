/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   @file Axbs_Ip.c
*
*   @addtogroup AXBS_IP AXBS IPV Driver
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
#include "Axbs_Ip.h"

#ifdef AXBS_IP_DEV_ERROR_DETECT
#if (AXBS_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT
        #ifndef USER_MODE_REG_PROT_ENABLED
        #define USER_MODE_REG_PROT_ENABLED (STD_ON)
        #include "RegLockMacros.h"
        #endif
    #endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_AXBS_IP_VENDOR_ID_C                      43
#define RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_AXBS_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RM_AXBS_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RM_AXBS_IP_SW_MAJOR_VERSION_C               5
#define RM_AXBS_IP_SW_MINOR_VERSION_C               0
#define RM_AXBS_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Axbs_Ip.h */
#if (RM_AXBS_IP_VENDOR_ID_C != RM_AXBS_IP_VENDOR_ID)
    #error "Axbs_Ip.c and Axbs_Ip.h have different vendor ids"
#endif
#if ((RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION_C    != RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_MINOR_VERSION_C    != RM_AXBS_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_REVISION_VERSION_C != RM_AXBS_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Axbs_Ip.c and Axbs_Ip.h are different"
#endif
#if ((RM_AXBS_IP_SW_MAJOR_VERSION_C != RM_AXBS_IP_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_SW_MINOR_VERSION_C != RM_AXBS_IP_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_SW_PATCH_VERSION_C != RM_AXBS_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip.c and Axbs_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef AXBS_IP_DEV_ERROR_DETECT
    #if (AXBS_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if the files Axbs_Ip.c and Devassert.h are of the same version */
        #if ((RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (RM_AXBS_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AUTOSAR Version Numbers of Axbs_Ip.c and Devassert.h are different"
        #endif
    #endif
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef RM_IP_ENABLE_AXBS
#if (RM_IP_ENABLE_AXBS == STD_ON)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define RM_START_SEC_CONST_32
#include "Rm_MemMap.h"

static const uint32 Axbs_Ip_InstanceAddress[AXBS_IP_INSTANCE_COUNT] = AXBS_IP_ARRAY_BASE_ADDRS;

#define RM_STOP_SEC_CONST_32
#include "Rm_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

void Axbs_Ip_Crs_Write(uint32 u32Addr,
                       uint32 value);

uint32 Axbs_Ip_Crs_Read(uint32 u32Addr);

#ifdef RM_CROSSBAR_PRS_READONLY
    #if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
void Axbs_Ip_Prs_Write(uint32 u32Addr,
                       uint32 value);

    #endif
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief        This function write into Crs register.
*
* @param[in]    u32Addr   The Crs register.
* @param[in]    value     The value will be written.
*/
void Axbs_Ip_Crs_Write(uint32 u32Addr,
                       uint32 value)
{
    /* Write value into the CRS register*/
    REG_WRITE32(u32Addr, value);
}

/**
* @brief        This function return the value of Crs register.
*
* @param[in]    u32Addr   The Crs register.
*
* @return       the value of Crs register.
*/
uint32 Axbs_Ip_Crs_Read(uint32 u32Addr)
{
    uint32 u32ret;

    /* Read the CRS register*/
    u32ret = REG_READ32(u32Addr);

    return u32ret;
}

#ifdef RM_CROSSBAR_PRS_READONLY
    #if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
    /**
    * @brief        This function write into Prs register.
    *
    */
    void Axbs_Ip_Prs_Write(uint32 u32Addr,
                           uint32 value)
    {
        /* Write value into the PRS register*/
        REG_RMW32(u32Addr, AXBS_PRS_MASK32, value);
    }

    #endif
#endif /* ifdef RM_CROSSBAR_PRS_READONLY */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief        The function initializes AXBS module.
 * @details      The function sets the internal module variables according to given
 *               configuration set.
 *
 * @param[in]     pAxbsConfig    Pointer of Configuration Axbs
 *
 * @return
 *
 * @api
 *
 * @pre
 *
 */

void Axbs_Ip_Init(const Axbs_Ip_ConfigType *pAxbsConfig)
{
#if (AXBS_IP_DEV_ERROR_DETECT == STD_ON)
    /* checking input parameters*/
    DevAssert(pAxbsConfig != NULL_PTR);
#endif
    /* Counter value used in loops */
    uint8 u8Counter;
    /* Pointer to initialize configuration */
    const Axbs_Ip_SlavePortConfigType *pSlavePortConfig = NULL_PTR;

    /* Configuring per Slave Port configured */
    for (u8Counter = 0x0U; u8Counter < pAxbsConfig->AxbsCrossbarIpNumPorts; u8Counter++)
    {
        pSlavePortConfig = &((*(pAxbsConfig->pAxbsCrossbarSlaveHwIpConfig))[u8Counter]);
#ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT
        if ((OsIf_Trusted_Call_Return1param(Axbs_Ip_Crs_Read,AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber)) & AXBS_LK_BIT_MASK32) == (uint32)0UL)
        {
    #ifdef RM_CROSSBAR_PRS_READONLY
        #if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
            OsIf_Trusted_Call2params(Axbs_Ip_Prs_Write,AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber,pSlavePortConfig->Axbs_InstanceNumber),  pSlavePortConfig->Axbs_PortPriorityConfig);
        #endif
    #endif
            OsIf_Trusted_Call2params(Axbs_Ip_Crs_Write, AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), pSlavePortConfig->Axbs_PortControlConfig);
        }
#else
        if ((Axbs_Ip_Crs_Read(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber)) & AXBS_LK_BIT_MASK32) == 0UL)
        {
    #ifdef RM_CROSSBAR_PRS_READONLY
        #if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
            Axbs_Ip_Prs_Write(AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber,pSlavePortConfig->Axbs_InstanceNumber), pSlavePortConfig->Axbs_PortPriorityConfig);
        #endif
    #endif
            Axbs_Ip_Crs_Write(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber),pSlavePortConfig->Axbs_PortControlConfig);
        }
#endif /* ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT */
    }

}

/**
* @brief        This function de-initializes the AXBS module.
* @details
*
* @param[in]    pAxbsConfig   Pointer to Axbs configuration structure
*/
void Axbs_Ip_DeInit(const Axbs_Ip_ConfigType *pAxbsConfig)
{
    /* Counter value used in loops */
    uint8 u8Counter;
    /* Pointer to initialize configuration */
    const Axbs_Ip_SlavePortConfigType *pSlavePortConfig = NULL_PTR;
    /* Array store PRS register default value of instances*/
    const uint32 s_PRSResetValueArray[]  = AXBS_IP_PRS_RESET_VALUE_ARRAY_U32;
    /* Array store CRS register default value of instances*/
    const uint32 s_CRSResetValueArray[]  = AXBS_IP_CRS_RESET_VALUE_ARRAY_U32;

#if (AXBS_IP_DEV_ERROR_DETECT == STD_ON)
    /* checking input parameters*/
    DevAssert(pAxbsConfig != NULL_PTR);
#endif

    /* Configuring per Slave Port configured when initializing to default value */
    for (u8Counter = 0x0U; u8Counter < pAxbsConfig->AxbsCrossbarIpNumPorts; u8Counter++)
    {
        pSlavePortConfig = &((*(pAxbsConfig->pAxbsCrossbarSlaveHwIpConfig))[u8Counter]);
#ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT
        if ((OsIf_Trusted_Call_Return1param(Axbs_Ip_Crs_Read,AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber)) & AXBS_LK_BIT_MASK32) == (uint32)0UL)
        {
    #ifdef RM_CROSSBAR_PRS_READONLY
        #if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
            OsIf_Trusted_Call2params(Axbs_Ip_Prs_Write,AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber,pSlavePortConfig->Axbs_InstanceNumber),  s_PRSResetValueArray[pSlavePortConfig->Axbs_InstanceNumber]);
        #endif
    #endif
            OsIf_Trusted_Call2params(Axbs_Ip_Crs_Write, AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), s_CRSResetValueArray[pSlavePortConfig->Axbs_InstanceNumber]);
        }
#else
        if ((REG_READ32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber)) & AXBS_LK_BIT_MASK32) == 0UL)
        {
    #ifdef RM_CROSSBAR_PRS_READONLY
        #if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
            REG_RMW32(AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), AXBS_PRS_MASK32, s_PRSResetValueArray[pSlavePortConfig->Axbs_InstanceNumber]);
        #endif
    #endif
            REG_WRITE32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), s_CRSResetValueArray[pSlavePortConfig->Axbs_InstanceNumber]);
        }
#endif /* ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT */
    }
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* RM_IP_ENABLE_AXBS == STD_ON */
#endif /* RM_IP_ENABLE_AXBS */

#ifdef __cplusplus
}
#endif

/** @} */
