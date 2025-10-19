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
*   @file Xbic_Ip.c
*
*   @addtogroup XBIC_IP XBIC IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Xbic_Ip.h"

#ifdef XBIC_IP_DEV_ERROR_DETECT
#if (XBIC_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
        #ifndef USER_MODE_REG_PROT_ENABLED
        #define USER_MODE_REG_PROT_ENABLED (STD_ON)
        #include "RegLockMacros.h"
        #endif
    #endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XBIC_IP_VENDOR_ID_C                      43
#define RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_XBIC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RM_XBIC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RM_XBIC_IP_SW_MAJOR_VERSION_C               5
#define RM_XBIC_IP_SW_MINOR_VERSION_C               0
#define RM_XBIC_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xbic_Ip.h */
#if (RM_XBIC_IP_VENDOR_ID_C !=  RM_XBIC_IP_VENDOR_ID)
    #error "Xbic_Ip.c and Xbic_Ip.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_AR_RELEASE_MINOR_VERSION_C    !=  RM_XBIC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_AR_RELEASE_REVISION_VERSION_C !=  RM_XBIC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip.c and Xbic_Ip.h are different"
#endif
#if ((RM_XBIC_IP_SW_MAJOR_VERSION_C !=  RM_XBIC_IP_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_SW_MINOR_VERSION_C !=  RM_XBIC_IP_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_SW_PATCH_VERSION_C !=  RM_XBIC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip.c and Xbic_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef XBIC_IP_DEV_ERROR_DETECT
    #if (XBIC_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if the files Xbic_Ip.c and Devassert.h are of the same version */
        #if ((RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (RM_XBIC_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AUTOSAR Version Numbers of Xbic_Ip.c and Devassert.h are different"
        #endif
    #endif
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#ifdef RM_IP_ENABLE_XBIC
#if (RM_IP_ENABLE_XBIC == STD_ON)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


#define RM_START_SEC_CONST_32
#include "Rm_MemMap.h"

static const uint32 s_xbicBase[XBIC_IP_INSTANCE_COUNT]  = XBIC_IP_ARRAY_BASE_ADDRS;

#define RM_STOP_SEC_CONST_32
#include "Rm_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

void Xbic_Ip_WriteRegister(uint32 address,
                           uint32 value);

uint32 Xbic_Ip_ReadRegister(uint32 address);

void Xbic_Ip_MasterFeedbackCheck(uint32 xbicInstance,
                                 uint8 masterPort,
                                 boolean bFeedbackCheckEnable);

void Xbic_Ip_SlaveEDCCheck(uint32 xbicInstance,
                           uint8 slavePort,
                           boolean bEDCCheckEnable);

void Xbic_Ip_LLD_IntegrityErrorInjectionConfig(uint32 xbicInstance,
                                                      uint8 slaveTarget,
                                                      uint8 masterTargetID,
                                                      uint8 synDecode);

void Xbic_Ip_LLD_IntegrityErrorInjectionDisable(uint32 xbicInstance);

static boolean Xbic_Ip_ConvertToBoolean(uint32 u32Val);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief        This function write into the register.
 *
 * @param[in]    address   The register address.
 * @param[in]    value     The value will be written.
 *
 * */
void Xbic_Ip_WriteRegister(uint32 address,
                           uint32 value)
{
    /* Write value into the register*/
    XBIC_REG_WRITE32(address,value);
}

/**
 * @brief        This function return the value of register.
 *
 * @param[in]    address   The register address.
 *
 * @return       uint32    The value of register.
 *
 * */
uint32 Xbic_Ip_ReadRegister(uint32 address)
{
    uint32 u32ret;

    /* Read the register*/
    u32ret = XBIC_REG_READ32(address);

    return u32ret;
}

/**
 * @brief         Enable/Disable feedback integrity checking for a specific master port.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     masterPort           : Master port number
 * @param[in]     bFeedbackCheckEnable : Specifies wheter the feedback integrity checking for the master port is enabled or disabled
 * @return        void
 *
 * */
void Xbic_Ip_MasterFeedbackCheck(uint32 xbicInstance,
                                 uint8 masterPort,
                                 boolean bFeedbackCheckEnable)
{
    uint32 u32temp = 0;

    SchM_Enter_Rm_RM_EXCLUSIVE_AREA_01();
    u32temp = XBIC_REG_READ32(s_xbicBase[xbicInstance]) & ~(XBIC_MCR_ME0_MASK >> masterPort);

    if (TRUE == bFeedbackCheckEnable)
    {
        /* Enable this masterPort feedback check */
        XBIC_REG_WRITE32(s_xbicBase[xbicInstance], u32temp|(XBIC_MCR_ME0_MASK >> masterPort));
    }
    else
    {
        /* Disable this masterPort feedback check */
        XBIC_REG_WRITE32(s_xbicBase[xbicInstance], u32temp);
    }

    SchM_Exit_Rm_RM_EXCLUSIVE_AREA_01();
}

/**
 * @brief         Enable/Disable attribute integrity checking for a specific slave port.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slavePort            : Slave port number
 * @param[in]     bEDCCheckEnable      : Specifies wheter the attribute integrity checking for the slave port is enabled or disabled
 * @return        void
 *
 * */
void Xbic_Ip_SlaveEDCCheck(uint32 xbicInstance,
                           uint8 slavePort,
                           boolean bEDCCheckEnable)
{
    uint32 u32temp = 0;

    SchM_Enter_Rm_RM_EXCLUSIVE_AREA_02();
    u32temp = XBIC_REG_READ32(s_xbicBase[xbicInstance]) & ~(XBIC_MCR_SE0_MASK >> slavePort);

    if (TRUE == bEDCCheckEnable)
    {
        /* Enable this slave EDC check */
        XBIC_REG_WRITE32(s_xbicBase[xbicInstance], u32temp|(XBIC_MCR_SE0_MASK >> slavePort));
    }
    else
    {
        /* Disable this slave EDC check */
        XBIC_REG_WRITE32(s_xbicBase[xbicInstance], u32temp);
    }

    SchM_Exit_Rm_RM_EXCLUSIVE_AREA_02();
}

/**
 * @brief         Inject an error into a master, a slave of a Xbic instance with a specific error code.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slaveTarget          : Slave port number injected error
 * @param[in]     masterTargetID       : Master tagget ID number injected error
 * @param[in]     synDecode            : Error Syndrome injected
 * @return        void
 *
 * */
void Xbic_Ip_LLD_IntegrityErrorInjectionConfig(uint32 xbicInstance,
                                               uint8 slaveTarget,
                                               uint8 masterTargetID,
                                               uint8 synDecode)
{
    uint32 u32RegValue;

    /* Calculate configuration value for EIR register */
    u32RegValue =  XBIC_EIR_SLV(slaveTarget) | XBIC_EIR_MST(masterTargetID) | XBIC_EIR_SYN(synDecode) | XBIC_EIR_EIE(1);

    /* Write configured value of Integrity error injection into the EIR register */
    XBIC_REG_WRITE32(XBIC_IP_EIR_ADDR32(xbicInstance), u32RegValue);
}

/**
 * @brief         Disable Inject error a specific Xbic instance.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_LLD_IntegrityErrorInjectionDisable(uint32 xbicInstance)
{
    /* Disable error injection */
    SchM_Enter_Rm_RM_EXCLUSIVE_AREA_03();
    XBIC_REG_RMW32(XBIC_IP_EIR_ADDR32(xbicInstance), XBIC_EIR_EIE_MASK, XBIC_EIR_EIE(0));
    SchM_Exit_Rm_RM_EXCLUSIVE_AREA_03();
}

/**
 * @brief         Convert a unsigned integer to boolean*
 *
 * */
static boolean Xbic_Ip_ConvertToBoolean(uint32 u32Val)
{
    boolean bVal = TRUE;

    /* Convert from uint32 to boolean*/
    if (0U == u32Val)
    {
        bVal = FALSE;
    }

    return bVal;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initialize Xbic with configuration of integrity checking for all of master/slave ports.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     pXbicConfig         : Pointer point to configuration of integrity checking for all of master/slave port.
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_Init(const Xbic_Ip_ConfigType *pXbicConfig)
{
    /* @brief Counter value used in loops */
    uint32 u32instance;

#if (XBIC_IP_DEV_ERROR_DETECT == STD_ON)
    /*check the input parameter*/
    DevAssert(pXbicConfig != NULL_PTR);
#endif
    for (u32instance = 0x0U; u32instance < XBIC_IP_INSTANCE_COUNT; u32instance++)
    {
#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Xbic_Ip_WriteRegister, XBIC_IP_MCR_ADDR32(u32instance), pXbicConfig->u32XbicTurnCheckOnPerPort[u32instance]);
#else
        Xbic_Ip_WriteRegister(XBIC_IP_MCR_ADDR32(u32instance), pXbicConfig->u32XbicTurnCheckOnPerPort[u32instance]);
#endif
    }
}

/**
 * @brief         Enable/Disable feedback integrity checking for a specific master port.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     masterPort           : Master port number
 * @param[in]     bFeedbackCheckEnable : Specifies wheter the feedback integrity checking for the master port is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_EnableMasterFeedbackCheck(uint32 xbicInstance,
                                       uint8 masterPort,
                                       boolean bFeedbackCheckEnable)
{
#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    /* Enable or disable this masterPort feedback check with user mode*/
    OsIf_Trusted_Call3params(Xbic_Ip_MasterFeedbackCheck, xbicInstance, masterPort, bFeedbackCheckEnable);
#else
    /* Enable or disable this masterPort feedback check with supervisor mode*/
    Xbic_Ip_MasterFeedbackCheck(xbicInstance, masterPort, bFeedbackCheckEnable);
#endif
}

/**
 * @brief         Enable/Disable attribute integrity checking for a specific slave port.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slavePort            : Slave port number
 * @param[in]     bEDCCheckEnable      : Specifies wheter the attribute integrity checking for the slave port is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_EnableSlaveEDCCheck(uint32 xbicInstance,
                                 uint8 slavePort,
                                 boolean bEDCCheckEnable)
{
#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    /* Enable or disable  this slave EDC check with user mode*/
    OsIf_Trusted_Call3params(Xbic_Ip_SlaveEDCCheck, xbicInstance, slavePort, bEDCCheckEnable);
#else
    /* Enable or disable  this slave EDC check with supervisor mode*/
    Xbic_Ip_SlaveEDCCheck(xbicInstance, slavePort, bEDCCheckEnable);
#endif
}

/**
 * @brief         Disable all of feedback integrity checking for the master ports and attribute integrity checking for slave ports.
 *
 * @details       This function is Reentrant.
 *
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_FeedbackCheckAndEDCCheckDisable(void)
{
    uint32 u32instance;
    uint32 u32valueDisable = 0U;

    for (u32instance = 0x0U; u32instance < XBIC_IP_INSTANCE_COUNT; u32instance++)
    {
#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
        /* Disable all check for the master/slave ports per Xbic instance in user mode*/
        OsIf_Trusted_Call2params(Xbic_Ip_WriteRegister, XBIC_IP_MCR_ADDR32(u32instance), u32valueDisable);
#else
        /* Disable all check for the master/slave ports per Xbic instance in supervisor mode*/
        Xbic_Ip_WriteRegister(XBIC_IP_MCR_ADDR32(u32instance), u32valueDisable);
#endif
    }
}

/**
 * @brief         Get error status of a Xbic instance.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     pErrorStatus         : Pointer points to the memory area containing the XBIC reports error information
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_IntegrityCheckerGetErrorStatus(uint32 xbicInstance,
                                            Xbic_Ip_ErrorStatusType *pErrorStatus)
{
    uint32 u32ErrValue;
    uint8 u8master;
    uint8 u8slave;

#if (XBIC_IP_DEV_ERROR_DETECT == STD_ON)
    /*checking input parameters*/
    DevAssert(xbicInstance < XBIC_IP_INSTANCE_COUNT);
#endif

#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    u32ErrValue = OsIf_Trusted_Call_Return1param(Xbic_Ip_ReadRegister,XBIC_IP_ESR_ADDR32(xbicInstance));
#else
    u32ErrValue = Xbic_Ip_ReadRegister(XBIC_IP_ESR_ADDR32(xbicInstance));
#endif
    /* No error detected/Error detected—all fields of the ESR and EAR registers are valid */
    pErrorStatus->bErrorStatusValid         = Xbic_Ip_ConvertToBoolean((u32ErrValue & XBIC_ESR_VLD_MASK) >> XBIC_ESR_VLD_SHIFT);
    /* Data Phase Slave Port Error */
    for (u8slave = 0U; u8slave < XBIC_IP_NUM_SLAVE; u8slave++)
    {
        pErrorStatus->aDataPhaseSlavePortError[u8slave] = Xbic_Ip_ConvertToBoolean(((u32ErrValue & (XBIC_ESR_DPSE0_MASK >> u8slave)) >> (XBIC_ESR_DPSE0_SHIFT - u8slave)));
    }

    /* Data Phase Master Port Error */
    for (u8master = 0U; u8master < XBIC_IP_NUM_MASTER; u8master++)
    {
        pErrorStatus->aDataPhaseMasterPortError[u8master] = Xbic_Ip_ConvertToBoolean(((u32ErrValue & (XBIC_ESR_DPME0_MASK >> u8master)) >> (XBIC_ESR_DPME0_SHIFT - u8master)));
    }

    pErrorStatus->masterID                  = (uint8)((u32ErrValue & XBIC_ESR_MST_MASK) >> XBIC_ESR_MST_SHIFT);
    pErrorStatus->slavePort                 = (uint8)((u32ErrValue & XBIC_ESR_SLV_MASK) >> XBIC_ESR_SLV_SHIFT);
    pErrorStatus->synError                  = (uint8)((u32ErrValue & XBIC_ESR_SYN_MASK) >> XBIC_ESR_SYN_SHIFT);

#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    pErrorStatus->errAddressDetect = OsIf_Trusted_Call_Return1param(Xbic_Ip_ReadRegister,XBIC_IP_EAR_ADDR32(xbicInstance));
#else
    pErrorStatus->errAddressDetect = Xbic_Ip_ReadRegister(XBIC_IP_EAR_ADDR32(xbicInstance));
#endif
}

/**
 * @brief         Inject an error into a master, a slave of a Xbic instance with a specific error code.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slaveTarget          : Slave port number injected error
 * @param[in]     masterTargetID       : Master tagget ID number injected error
 * @param[in]     synDecode            : Error Syndrome injected
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_IntegrityErrorInjectionConfig(uint32 xbicInstance,
                                           uint8  slaveTarget,
                                           uint8  masterTargetID,
                                           uint8  synDecode)
{
#if (XBIC_IP_DEV_ERROR_DETECT == STD_ON)
    /*checking input parameters*/
    DevAssert(xbicInstance < XBIC_IP_INSTANCE_COUNT);
    DevAssert(slaveTarget < XBIC_IP_NUM_SLAVE);
    DevAssert(masterTargetID <= XBIC_IP_MAX_SLOT_MASTER_ID);
#endif

#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    /* Configure integrity error injection in user mode */
    OsIf_Trusted_Call4params(Xbic_Ip_LLD_IntegrityErrorInjectionConfig, xbicInstance, slaveTarget, masterTargetID, synDecode);
#else
    /* Configure integrity error injection in supervisor mode */
    Xbic_Ip_LLD_IntegrityErrorInjectionConfig(xbicInstance,slaveTarget,masterTargetID,synDecode);
#endif
}

/**
 * @brief         Disable Inject error a specific Xbic instance.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_IntegrityErrorInjectionDisable(uint32 xbicInstance)
{
#if (XBIC_IP_DEV_ERROR_DETECT == STD_ON)
    /*checking input parameters*/
    DevAssert(xbicInstance < XBIC_IP_INSTANCE_COUNT);
#endif

#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    /* Disable Inject error a specific Xbic instance in user mode */
    OsIf_Trusted_Call1param(Xbic_Ip_LLD_IntegrityErrorInjectionDisable,xbicInstance);
#else
    /* Disable Inject error a specific Xbic instance in supervisor mode */
    Xbic_Ip_LLD_IntegrityErrorInjectionDisable(xbicInstance);
#endif
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* RM_IP_ENABLE_XBIC == STD_ON */
#endif /* RM_IP_ENABLE_XBIC */

#ifdef __cplusplus
}
#endif

/** @} */
