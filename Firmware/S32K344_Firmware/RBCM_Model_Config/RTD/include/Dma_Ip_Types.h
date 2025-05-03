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
#ifndef DMA_IP_TYPES_H_
#define DMA_IP_TYPES_H_

/**
*   @file    Dma_Ip_Types.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver header file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
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
#include "Dma_Ip_Cfg_Defines.h"
#include "Dma_Ip_Cfg_Devices.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_TYPES_VENDOR_ID                       43
#define DMA_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_TYPES_SW_MAJOR_VERSION                5
#define DMA_IP_TYPES_SW_MINOR_VERSION                0
#define DMA_IP_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same vendor */
#if (DMA_IP_TYPES_VENDOR_ID != DMA_IP_CFG_DEFINES_VENDOR_ID)
    #error "Dma_Ip_Types.h and Dma_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((DMA_IP_TYPES_AR_RELEASE_MAJOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_TYPES_AR_RELEASE_MINOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_TYPES_AR_RELEASE_REVISION_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Types.h and Dma_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same Software version */
#if ((DMA_IP_TYPES_SW_MAJOR_VERSION != DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (DMA_IP_TYPES_SW_MINOR_VERSION != DMA_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (DMA_IP_TYPES_SW_PATCH_VERSION != DMA_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Types.h and Dma_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Dma_Ip_Devices.h file are of the same vendor */
#if (DMA_IP_TYPES_VENDOR_ID != DMA_IP_CFG_DEVICES_VENDOR_ID)
    #error "Dma_Ip_Types.h and Dma_Ip_Devices.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Devices.h file are of the same Autosar version */
#if ((DMA_IP_TYPES_AR_RELEASE_MAJOR_VERSION != DMA_IP_CFG_DEVICES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_TYPES_AR_RELEASE_MINOR_VERSION != DMA_IP_CFG_DEVICES_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_TYPES_AR_RELEASE_REVISION_VERSION != DMA_IP_CFG_DEVICES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Types.h and Dma_Ip_Devices.h are different"
#endif

/* Check if header file and Dma_Ip_Devices.h file are of the same Software version */
#if ((DMA_IP_TYPES_SW_MAJOR_VERSION != DMA_IP_CFG_DEVICES_SW_MAJOR_VERSION) || \
     (DMA_IP_TYPES_SW_MINOR_VERSION != DMA_IP_CFG_DEVICES_SW_MINOR_VERSION) || \
     (DMA_IP_TYPES_SW_PATCH_VERSION != DMA_IP_CFG_DEVICES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Types.h and Dma_Ip_Devices.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief This type contains the Dma Ip Return Type.
 * @details The Return Type give information for the execution of interfaces.
 *
 * */
typedef enum{
    DMA_IP_STATUS_SUCCESS      = E_OK,
    DMA_IP_STATUS_ERROR        = E_NOT_OK,
    DMA_IP_STATUS_WRONG_STATE  = 2U,
#if (DMA_IP_MULTICORE_IS_AVAILABLE == STD_ON)
    DMA_IP_STATUS_WRONG_CORE   = 3U,
#endif /* DMA_IP_MULTICORE_IS_AVAILABLE == STD_ON */
}Dma_Ip_ReturnType;

/**
 * @brief This type contains the Dma Ip Channel State Value Type.
 * @details The Channel State type provides information about the channel's general state.
 *          The Reset State is present when the Dma Channel is uninitialized.
 *          The Ready State is present when the Dma Channel is initialized and without error.
 *          The Error State is present when the Dma Channel is initialized and with error.
 *
 * */
typedef enum{
    DMA_IP_CH_RESET_STATE         = 0U,
    DMA_IP_CH_READY_STATE         = 1U,
    DMA_IP_CH_TRANSFER_STATE      = 2U,
    DMA_IP_CH_SCATTERGATHER_STATE = 3U,
    DMA_IP_CH_ERROR_STATE         = 4U,
}Dma_Ip_HwChannelStateValueType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This type contains the Dma Ip Callback interface.
 * @details The Callback is defined by the user and installed by the driver in the corresponding IRQ.
 *
 * @return void
 *
 * @implements Dma_Ip_Callback_typedef
 * */
typedef void (*Dma_Ip_Callback)(void);

/**
 * @brief This type contains the Dma Ip Logic Channel Identification.
 * @details The Logic Channel is identified by the following structure:
 *          The Logic Channel Id contains the ID value.
 *          The Hardware Version Id contains the DMA Hardware Ip Block Version.
 *          The Hardware Instance Id contains the DMA Hardware Instance identification.
 *          The Hardware Channel Id contains the DMA Hardware Channel identification.
 *          The Hardware Crc Instance Id contains the DMA Hardware Crc Instance identification if CRC_IP is available.
 *          The Hardware Crc Channel Id contains the DMA Hardware Crc Channel identification if CRC_IP is available.
 *          The Interrupt Callback stores pointer to the user defined interrupt callback.
 *          The Error Interrupt Callback stores pointer to the user defined error interrupt callback.
 *
 * @implements Dma_Ip_LogicChannelIdType_struct
 * */
typedef struct{
    uint32 LogicChId;                  /**< @brief DMA logic channel number. */
    uint8 HwVersId;                    /**< @brief DMA hardware version. */
    uint8 HwInstId;                    /**< @brief DMA hardware instance number. */
    uint8 HwChId;                      /**< @brief DMA hardware channel number. */
    Dma_Ip_Callback IntCallback;       /**< @brief The channel callback is installed in the interrupt and is called automatically
                                                   from the interrupt every time it is triggered. */
    Dma_Ip_Callback ErrIntCallback;    /**< @brief The channel error callback is installed in the error interrupt and is called automatically
                                                   from the interrupt every time it is triggered. */
}Dma_Ip_LogicChannelIdType;

/**
 * @brief This type contains the Dma Ip Global Configuration.
 * @details The Global Configuration of an Logic Channel, contains all the information describing a
 *          channel, but are not present in the DMA TCD.
 *          It contains configuration split in four main areas:
 *          Control defines functionality covering the channel's bus control.
 *          Request defines functionality covering the channel's request interface
 *          Interrupt defines functionality covering special channel interrupts.
 *          Priority defines functionality covering the channel's priority mechanism.
 *
 * @implements Dma_Ip_GlobalConfigType_struct
 * */
typedef struct{
    struct{
        boolean EnMasterIdReplication;     /**< @brief The eDMA master ID replication field allows the eDMA to use the same protection level and system bus ID
                                                      of the master programming the eDMA's TCD. This forces MP_CSR[GMRC] = 1. */
        boolean EnBufferedWrites;          /**< @brief When buffered writes are enabled, all writes except for the last write sequence of the minor loop are
                                                      signaled by the eDMA as bufferable. */
    }Control;
    struct{
        boolean EnRequest;                 /**< @brief DMA: Enable/Disable the hardware request for the channel. */
    }Request;
    struct{
        boolean EnErrorInt;                /**< @brief Enable/Disable channel error interrupt. */
    }Interrupt;
    struct{
        uint8 SwapSize;                    /**< @brief Select the swap size */
    }Swap;
    struct{
        uint8 Group;                       /**< @brief The channel is assigned to a specific priority group. NOT available for scatter/gather. */
        uint8 Level;                       /**< @brief The channel is assigned a priority level inside the priority group. */
        boolean EnPreemption;              /**< @brief Allows the channel to be interrupted by a higher-priority channel. */
        boolean DisPreempt;                /**< @brief Allows the channel to interrupt a lower-priority channel. */
    }Priority;
}Dma_Ip_GlobalConfigType;

/**
 * @brief This type contains the Dma Ip Transfer Configuration.
 * @details The Transfer Configuration of an Logic Channel, contains all the information describing a
 *          channel transfer functionalities and are present in the DMA TCD.
 *          It contains configuration split in five main areas:
 *          Control defines functionality covering the channel control functions. It includes additionaly
 *          the Scatter/Gather Address and Destination Store Address.
 *
 * */
typedef struct{
    struct{
        uint32 ScatterGatherAddr;
        uint32 DestinationStoreAddr;    /**< @brief If destination store address is not 0(NULL), then the ESDA flag is set and the source adjustment
                                                    is disabled. */
        uint8 BandwidthControl;         /**< @brief Throttles the amount of bus bandwidth consumed by the eDMA. Generally, as the eDMA processes the
                                                    minor loop, it continuously generates read/write sequences until the minor count is exhausted. This field
                                                    forces eDMA to stall after the completion of each read/write access, to control the bus request bandwidth
                                                    seen by the system bus interconnect. */
        uint8 TransferModeControl;     /**< @brief Transfer Mode Control specifies the direction the DMA will transfer data */
        boolean EnStart;
        boolean EnMajorInt;
        boolean EnHalfMajorInt;
        boolean DisAutoHwRequest;       /**< @brief Enable/Disable automatic hardware request clear when the current major iteration count reaches 0.(DREQ) */
        boolean EnEndOfPacketSignal;    /**< @brief With an end-of-packet retirement, the current TCD destination address minus the software-saved
                                                    initial address (DADDR), the total amount of data transferred.*/
    }Control;
    struct{
        uint32 Addr;                    /**< @brief Source address for the data transfer. */
        sint32 LastAddrAdj;             /**< @brief Signed adjustment for the source address. If "storeAddr" configuration value is not 0(NULL),
                                                    then the ESDA flag is set and "destination store address" is enabled, thus "lastAddrAdj"
                                                    becomes unavailable. */
        sint16 SignedOffset;            /**< @brief Signed offset for the source address. */
        uint8 TransferSize;             /**< @brief Source number of bytes transferred per request. */
        uint8 Modulo;
    }Source;
    struct{
        uint32 Addr;                    /**< @brief Destination address for the data transfer. */
        sint32 LastAddrAdj;             /**< @brief Signed adjustment for the destination address. If Scatter/Gather configuration is loaded for
                                                    the channel, then the ESG(Enable Scatter/Gather) flag is set and this configuration is
                                                    NOT available. */
        sint16 SignedOffset;            /**< @brief Signed offset for the destination address. */
        uint8 TransferSize;             /**< @brief Destination number of bytes transferred per request. */
        uint8 Modulo;
    }Destination;
    struct{
        uint32 Size;                    /**< @brief Number of bytes transferred in a MinorLoop. */
        sint32 Offset;                  /**< @brief MinorLoop Offset value. */
        uint8 LogicLinkCh;              /**< @brief Set the minor loop link channel. */
        boolean EnLink;                 /**< @brief Enable/Disable minor loop link channel. */
        boolean EnSrcOffset;            /**< @brief Enable/Disable MinorLoop Source Offset. */
        boolean EnDstOffset;            /**< @brief Enable/Disable MinorLoop Destination Offset. */
    }MinorLoop;
    struct{
        uint32 Count;                   /**< @brief Set major loop count by configuring CITER and BITER. */
        uint8 LogicLinkCh;              /**< @brief Set the major loop link channel. */
        boolean EnLink;                 /**< @brief Enable/Disable major loop link channel. */
    }MajorLoop;
}Dma_Ip_TransferConfigType;

/**
 * @brief This type contains the Dma Ip Scatter/Gather Configuration.
 * @details The Scatter/Gather Configuration of a Logic Channel, contains all the information describing
 *          the channel's needed resources for a Scatter/Gather element.
 *          It contains a pointer to the transfer configuration, a pointer to a Software TCD, a pointer
 *          to the next Scatter/Gather configuration and a status flag for loading the transfer
 *          configuration into the Software TCD.
 *
 * */
typedef struct Dma_Ip_ScatterGatherConfigType{
    Dma_Ip_TransferConfigType * TransferConfig;      /**< @brief Configuration that shall be loaded into the Software TCD. */
    Dma_Ip_SwTcdRegType * Stcd;                      /**< @brief Software TCD shall be loaded with own TCD configuration. */
    boolean Loaded;
    struct Dma_Ip_ScatterGatherConfigType * NextConfig;    /**< @brief Next Logic Channel configuration.
                                                                       If the address is not NULL, then the ESG flag is enabled (Scatter/Gather address)
                                                                       and the destination adjustment is disabled. The next configuration address is stored. */
}Dma_Ip_ScatterGatherConfigType;


/**
 * @brief This type contains the Dma Ip Logic Channel Configuration.
 * @details The Logic Channel Configuration consists of the Logic Channel Identifier, pointer
 *          to the Global Configuration, pointer to the Transfer Configuration and pointer to
 *          the Scatter/Gather configuration.
 *          The Logic Channel Configuration contains all data needed to initialize a Logic
 *          Channel.
 *
 * */
typedef struct{
    Dma_Ip_LogicChannelIdType LogicChId;                           /**< @brief The Logic Channel ID contains configuration information and identification. */
    const Dma_Ip_GlobalConfigType * pxGlobalConfig;                /**< @brief The Global Configuration pointer shall contain the global data. */
    const Dma_Ip_TransferConfigType * pxTransferConfig;            /**< @brief The Transfer Configuration pointer shall contain the transfer data. */
    Dma_Ip_ScatterGatherConfigType ** ppxScatterGatherConfigArray; /**< @brief The Scatter/Gather Configuration pointer shall contain a pointer to an array
                                                                               containing all Scatter/Gather Logic Elements. */
}Dma_Ip_LogicChannelConfigType;

/**
 * @brief This type contains the Dma Ip Logic Instance Identification.
 * @details The Logic Instance is identified by the following structure:
 *          The Logic Instance Id contains the ID value.
 *          The Hardware Version Id contains the DMA Hardware Ip Block Version.
 *          The Hardware Instance Id contains the DMA Hardware Instance identification.
 *
 * */
typedef struct{
    uint32 LogicInstId;    /**< @brief DMA logic instance number. */
    uint8 HwVersId;        /**< @brief DMA hardware version number. */
    uint8 HwInstId;        /**< @brief DMA hardware instance number. */
}Dma_Ip_LogicInstanceIdType;

/**
 * @brief This type contains the Dma Ip Logic Instance Configuration.
 * @details The Logic Instance Configuration contains all the information describing
 *          an instance functionality.
 *
 * */
typedef struct{
    Dma_Ip_LogicInstanceIdType LogicInstId;     /**< @brief DMA logic instance number. */
    boolean EnDebug;                   /**< @brief When in debug mode, the DMA stalls the start of a new channel. Executing channels are allowed to
                                                   complete. DMA resumes channel execution when the system exits debug mode or clears the EDBG field to 0. */
    boolean EnRoundRobin;              /**< @brief Enable Round Robin Channel Arbitration */
    boolean EnHaltAfterError;          /**< @brief When this field is set to 1, any error causes the HALT field to be set to 1. Then all service requests are
                                                   ignored until the HALT field is cleared to 0. */
    boolean EnChLinking;               /**< @brief Global Channel Linking Control */
    boolean EnGlMasterIdReplication;   /**< @brief If master ID replication is disabled, the privileged protection level (Supervisor mode) for DMA transfers is used. */
}Dma_Ip_LogicInstanceConfigType;

/**
 * @brief This type contains the Dma Ip Hardware Channel State.
 * @details The Hardware Channel State contains the channel's state based on runtime
 *          actions. The structure links the hardware channel state with the Logic
 *          Channel.
 *
 * */
typedef struct{
    const Dma_Ip_LogicChannelIdType * LogicChId;
    Dma_Ip_HwChannelStateValueType StateValue;
    uint32 LogicChErrors;
}Dma_Ip_HwChannelStateType;

#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
/**
 * @brief  This type contains the Dma Ip Multicore configuration Type.
 *
 * */
typedef struct
{
    const uint8 pMultiCoreDmaChannelConfig[DMA_IP_DMA_TOTAL_NOF_LOGIC_CHANNEL];
    const uint8 pMultiCoreDmaInstanceConfig[DMA_IP_DMA_TOTAL_NOF_LOGIC_INST];
}Dma_Ip_MultiCoreConfigType;
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
/**
 * @brief  This type contains the Dma Ip Virtual memory section configuration Type.
 *
 * */
typedef struct
{
    const uint32 VirtualAddrStart;
    const uint32 VirtualAddrEnd;
    const uint32 PhysicalAddrStart;
    const uint32 PhysicalAddrEnd;
}Dma_Ip_VirtualSectionConfigType;

/**
 * @brief  This type contains the Dma Ip Virtual memory configuration Type.
 *
 * */
typedef struct
{
    const uint8 NumOfSection;
    const Dma_Ip_VirtualSectionConfigType (* const pSectionConfig)[];
}Dma_Ip_VirtualMemoryConfigType;
#endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */

/**
 * @brief This type contains the Dma Ip Initialization.
 * @details The Dma Ip Initialization contains all the information required to initialize the
 *          Dma Peripheral.
 *          Each pointer shall be loaded with a specific configuration used be the Dma.
 *
 * */
typedef struct{
    Dma_Ip_HwChannelStateType ** ppxChStateArray;
    const Dma_Ip_LogicChannelConfigType * const pxLogicChannelResetConfig;
    const Dma_Ip_LogicChannelConfigType * const * ppxLogicChannelConfigArray;
    const Dma_Ip_LogicInstanceConfigType * const pxLogicInstanceResetConfig;
    const Dma_Ip_LogicInstanceConfigType * const * ppxLogicInstConfigArray;
#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
    const Dma_Ip_MultiCoreConfigType * const pxMultiCoreConfig;
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
#if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
    const Dma_Ip_VirtualMemoryConfigType * const pxVirtualMemoryConfig;
#endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
}Dma_Ip_InitType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef DMA_IP_TYPES_H_ */

