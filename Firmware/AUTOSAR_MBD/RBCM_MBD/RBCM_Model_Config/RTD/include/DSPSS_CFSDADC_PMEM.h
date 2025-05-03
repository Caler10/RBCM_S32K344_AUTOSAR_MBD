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


#ifndef DSPSS_CFSDADC_PMEM_H
#define DSPSS_CFSDADC_PMEM_H

/** @cond DRIVER_INTERNAL_USE_ONLY */

/*
* @file     DSPSS_CFSDADC_PMEM.h
*
* @date     February-13-2023
*
* @brief    Header file containing the CFSDADC FW binary in byte array format that needs to be copied to PMEM
*
*   @addtogroup sd_adc_ip Sd Adc IPL
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
#include "StandardTypes.h"
#include "Sdadc_Ip_CfgDefines.h"


#if (SDADC_IP_DSPSS_ENABLED == STD_ON)

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DSPSS_VENDOR_ID_CFSADC_PMEM                      43
#define DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_PMEM       4
#define DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_PMEM       7
#define DSPSS_AR_RELEASE_REVISION_VERSION_CFSADC_PMEM    0
#define DSPSS_SW_MAJOR_VERSION_CFSADC_PMEM               5
#define DSPSS_SW_MINOR_VERSION_CFSADC_PMEM               0
#define DSPSS_SW_PATCH_VERSION_CFSADC_PMEM               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if DSPSS_CFSDADC_PMEM.h file and Sdadc_Ip_CfgDefines.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_CFSADC_PMEM != SDADC_IP_VENDOR_ID_CFGDEFINES)
    #error "DSPSS_CFSDADC_PMEM.h and Sdadc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if DSPSS_CFSDADC_PMEM.h file and Sdadc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_PMEM != SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_PMEM != SDADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_CFSADC_PMEM != SDADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of DSPSS_CFSDADC_PMEM.h and Sdadc_Ip_CfgDefines.h are different"
#endif

/* Check if DSPSS_CFSDADC_PMEM.h file and Sdadc_Ip_CfgDefines.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_CFSADC_PMEM != SDADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (DSPSS_SW_MINOR_VERSION_CFSADC_PMEM != SDADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (DSPSS_SW_PATCH_VERSION_CFSADC_PMEM != SDADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of DSPSS_CFSDADC_PMEM.h and Sdadc_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if DSPSS_CFSDADC_PMEM.h file and StandardTypes.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_PMEM != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_PMEM != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of DSPSS_CFSDADC_PMEM.h and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONST_32
#include "Adc_MemMap.h"


static const uint32 u32Pmem_NogapArray[] =
{
    0xfb200020U, 0xfb200008U, 0xfb200008U, 0xfb200008U,
    0xfcd80400U, 0xfcd80400U, 0xfcd80400U, 0xfcd80400U,
    0xfcd80400U, 0x29883e9cU, 0xfb62000eU, 0xfcc4000dU,
    0xcfa73e9cU, 0x3a803e41U, 0xfcd80300U, 0xcfa73e9cU,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0xfcd80502U, 0xf858000cU, 0xfb800255U, 0x00000000U,
    0xfc800000U, 0xfb200020U, 0x2988ba00U, 0xfb63002aU,
    0x5100c22eU, 0x2bd06006U, 0x29803e9cU, 0xfb62002fU,
    0xfcc0002eU, 0xcfa72289U, 0x3a803e51U, 0x2a807e9cU,
    0x298a2400U, 0x3a803648U, 0xfb620036U, 0xfcc50035U,
    0xcfa72289U, 0xc0144001U, 0x298c3e9cU, 0xfb62003cU,
    0x2a8a7e9cU, 0xfcc6003bU, 0xcd822400U, 0x3a803e41U,
    0xfcd80300U, 0xcfa73e9cU, 0x00000000U, 0x00000000U,
    0xfcd80502U, 0xf0400001U, 0xf8580154U, 0xfb800087U,
    0x00000000U, 0xfc800000U, 0xfb200040U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0xfcd80502U, 0xf0400002U, 0xf858029cU, 0xfb800087U,
    0x00000000U, 0xfc800000U, 0xfb200060U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0xfcd80502U, 0xf0400003U, 0xf85803e4U, 0xfb800087U,
    0x00000000U, 0xfc800000U, 0xfb200080U, 0xf0600148U,
    0x24ca3d3bU, 0xf0c00000U, 0xcde9a580U, 0xfaa60024U,
    0xfcd80500U, 0xfcd80601U, 0xfcd8050bU, 0xcef19756U,
    0xfab60010U, 0xcec18135U, 0xfa8e0008U, 0xfa81fff0U,
    0xc0e08085U, 0x3a800305U, 0x2b5c5149U, 0xc49fc108U,
    0xfab8ffeeU, 0xc435c039U, 0xfaaf001eU, 0xc08a4329U,
    0xfa8d0112U, 0xc0624089U, 0xc0401146U, 0x2b7453d8U,
    0xc0e253dcU, 0xfa91ffeaU, 0xc02450ceU, 0x29820088U,
    0x2df06d47U, 0x3e75d2d5U, 0x3bd1d1cfU, 0x290a12dbU,
    0xfa8a0016U, 0xc1cc0388U, 0xc06402a8U, 0xc6b413cbU,
    0xc0ee1cd1U, 0xc49651daU, 0xc4b4d761U, 0xfb4200c1U,
    0x2db053d4U, 0xfab9febcU, 0x28f5d706U, 0x2d7fe587U,
    0xc813b7b6U, 0x347e6582U, 0x2dfe2387U, 0x3a803776U,
    0xfaad0007U, 0x3a80208dU, 0x347e9752U, 0x3a802387U,
    0xfaac010cU, 0xc5d796ddU, 0xfa8e0008U, 0xfb0000c4U,
    0x3a8014c6U, 0xf0e00000U, 0xc5d796a1U, 0xc5d756d2U,
    0x2af85686U, 0x30dbf969U, 0x2afa614dU, 0x2c5b91dfU,
    0x298c6345U, 0xc5b82587U, 0xfb4300cfU, 0xc531b66eU,
    0x2de082a0U, 0x7ccf2629U, 0x3a80135fU, 0xf0500300U,
    0x2d901394U, 0x24de21c0U, 0x24ded33fU, 0x24da50fdU,
    0xc4a57a44U, 0x2aaa4179U, 0xf0504000U, 0x34aa93e2U,
    0x2df06902U, 0xf0200044U, 0x30a4d19cU, 0x69b5aad9U,
    0x2bd46985U, 0x2b586245U, 0xf0200048U, 0x30a414f5U,
    0x2ada7e9cU, 0x2bd452ecU, 0x32dfac05U, 0x2d851313U,
    0x375992e6U, 0x30805876U, 0x281bfaa8U, 0x309a90efU,
    0xf0500070U, 0x5570c2a8U, 0x2bd46583U, 0x375dec05U,
    0x383f91e3U, 0x2bf25877U, 0x2af66c07U, 0x2deff76eU,
    0x2bf053ebU, 0x2aec56eeU, 0x2dff2347U, 0x2afe5365U,
    0x28f513edU, 0x3d011878U, 0x2bee56f4U, 0xfab60004U,
    0x2c486c06U, 0xfaa40118U, 0xc5da5879U, 0xfa4dffe6U,
    0xfa49ffe4U, 0xc599d2e8U, 0xc69e9264U, 0xc79f1c7bU,
    0x3a800239U, 0x29885222U, 0xfb620236U, 0x2909d4b4U,
    0xf0403fffU, 0xfb63023fU, 0xb449b388U, 0x2af87e9cU,
    0x2dc06307U, 0xc8631109U, 0x37dc9315U, 0x290a1017U,
    0x3f5994b7U, 0x310a130bU, 0xfb64022eU, 0x290c3388U,
    0x2c6c5094U, 0x3eef3c80U, 0x298c537eU, 0x2de0127fU,
    0xfb63011dU, 0x2d80519bU, 0x29063e9cU, 0xfb620119U,
    0x3a803c80U, 0x29063a61U, 0xfb63011cU, 0x3a803ce0U,
    0x3a8011ffU, 0x2903d34dU, 0xfb620123U, 0xcc9214b6U,
    0xf0303fffU, 0x5524d059U, 0x3a8010cdU, 0x3d216302U,
    0x3c90ba6fU, 0x38365099U, 0x355350bbU, 0x3a803b5eU,
    0xfcd80604U, 0xfcc3012cU, 0x3a801abaU, 0x3324debcU,
    0x3a247e9cU, 0x290a2176U, 0x3fd9511fU, 0x2984a9e4U,
    0xcec7a824U, 0xfb420194U, 0x2b7a53caU, 0x2a9e57ccU,
    0x298450c8U, 0x3a803585U, 0xfb620156U, 0x29003e9cU,
    0xf0504000U, 0xfb63013bU, 0xc5c4921cU, 0x2a885213U,
    0xfa28ffc6U, 0xceffbbc2U, 0xfcc70153U, 0x34da100eU,
    0x2db02985U, 0xc0c9e3ccU, 0x3a8014a0U, 0xfcc40148U,
    0x3a80220cU, 0x2d900309U, 0x3a800287U, 0x2418c2bfU,
    0x24184309U, 0x3a800327U, 0x20322043U, 0x290060c3U,
    0xfb630152U, 0x20721091U, 0x20561a90U, 0x2032130fU,
    0x48589063U, 0x48589063U, 0x3a8001f7U, 0x2db000f7U,
    0xfb0001bbU, 0x3a801222U, 0x290012c8U, 0xf0604000U,
    0xfb63015aU, 0xc5c4921cU, 0x2af85224U, 0x29887bc2U,
    0xfa2effd8U, 0xfa28ffc6U, 0x3a80100eU, 0xfb420179U,
    0x34edd228U, 0x3a802986U, 0xfcc50176U, 0xcfa723ccU,
    0xc0cfe20cU, 0xc5280327U, 0xfcc4016bU, 0x2d903bfeU,
    0x2db0030bU, 0x3a8002bfU, 0x24184287U, 0x2418c30bU,
    0x3a802041U, 0x290060c3U, 0xfb630174U, 0x20721091U,
    0x20561a90U, 0x2032130fU, 0x48589063U, 0x48589063U,
    0xc03dc1f7U, 0xfa2effd8U, 0x3a8023ccU, 0xfb000191U,
    0x3a801208U, 0xfcc5018fU, 0x3a8023ccU, 0x2da02497U,
    0xc0cfe20cU, 0xc5280327U, 0xfcc40184U, 0x3a803bfeU,
    0x2d900289U, 0x3a800387U, 0x241c8309U, 0x3a8002bfU,
    0x24184289U, 0xc4c3a082U, 0x290c6041U, 0xfb63018dU,
    0x20721091U, 0x20541a90U, 0x2022130fU, 0x48589062U,
    0x48589062U, 0xc8f325d2U, 0x2da00177U, 0x3a8000f7U,
    0x3a801208U, 0x2ae85222U, 0xfb0001bbU, 0x3a801348U,
    0x290010c8U, 0x3a803585U, 0xfb430199U, 0xca286864U,
    0xc5c4921cU, 0x2ac8528eU, 0xfa28ffc6U, 0xf0604000U,
    0xc8933bc2U, 0xfcc701b9U, 0x34c9902fU, 0x3a802984U,
    0x2d900227U, 0xfa22ffd6U, 0x2da015a0U, 0xc8a3020fU,
    0xc50bbb22U, 0xc0e5c319U, 0xfcc001acU, 0x242c8201U,
    0x240c438fU, 0x240c8201U, 0x242c4397U, 0x240c4319U,
    0x242c838fU, 0x240c8210U, 0x242c4300U, 0x240884a7U,
    0x2408624cU, 0x3a802082U, 0x290a6041U, 0xfb6301b9U,
    0x20721091U, 0x20641a90U, 0x2022120fU, 0x48189022U,
    0x48189022U, 0xc03dc177U, 0x3a801222U, 0x2909d4b4U,
    0xf0403fffU, 0xfb630243U, 0x3a803388U, 0x34499709U,
    0x2ac87e9cU, 0xc4a2a18eU, 0x318d7e9cU, 0xfb6601caU,
    0x318d3a00U, 0xfb640247U, 0x31897e9cU, 0xfb640247U,
    0xfb0001cfU, 0x3a80131bU, 0x318d3a00U, 0x3a80131bU,
    0xfb6501cfU, 0x31897e9cU, 0xfb64024aU, 0x290c128bU,
    0xfb6201f6U, 0xc48fb585U, 0x298852cbU, 0xfb6201d5U,
    0x3a801721U, 0x2988531cU, 0x2dd0579dU, 0x3ee556a9U,
    0x2aec4239U, 0xf0504000U, 0x34db8329U, 0x240a5308U,
    0x3a8003b9U, 0x2b6c6845U, 0xc524911aU, 0xfa24ffcaU,
    0xfa2effdaU, 0xcec8951eU, 0xcef09429U, 0xfcc601f3U,
    0xc0aa29a1U, 0x2406c211U, 0x241c43b9U, 0x240c4215U,
    0x240cc2b9U, 0x2404420fU, 0x2404c2bdU, 0x24044251U,
    0x3a80038fU, 0x32128239U, 0x241cc3d5U, 0x3a802181U,
    0x240a43b9U, 0x242cc377U, 0x646d6a00U, 0xc0bde143U,
    0xc0ba0340U, 0xc4a2d31bU, 0x290a1208U, 0x3e5f13bfU,
    0x290c16a1U, 0xfb4301fcU, 0xc4b2e38dU, 0x3a801712U,
    0x290e3e9cU, 0xfb6301ffU, 0x3a803a80U, 0x2ad853beU,
    0x298e5792U, 0xfa4affe6U, 0x3e4525c5U, 0x2ad869e5U,
    0x290c04bfU, 0xc5f4a545U, 0xfb430209U, 0xc5b8432fU,
    0x3a801692U, 0x3a801314U, 0x290dd2bdU, 0xf0600040U,
    0xfb42021cU, 0x3049538dU, 0x3a80127dU, 0x34ec214eU,
    0x318f608dU, 0xfb660217U, 0x318ebe9cU, 0xfb64024cU,
    0x31857e9cU, 0xfb64024cU, 0xfb20021cU, 0x318ebe9cU,
    0xfb64021aU, 0xfb20021cU, 0x31857e9cU, 0xfb64024eU,
    0x29801318U, 0xfb630250U, 0x3109978cU, 0xfb64022fU,
    0x3a801314U, 0x290dd2bdU, 0xfb430228U, 0x2dc05318U,
    0x386b94b8U, 0xc489937dU, 0xfb00022fU, 0xf989060aU,
    0xac5a7348U, 0x298a7e9cU, 0xfb620228U, 0x3a803328U,
    0xfb00022fU, 0x3a80137dU, 0x3a802302U, 0x3a800238U,
    0x28c85649U, 0xc5ffc27aU, 0xfc800000U, 0x3a8017bfU,
    0xfb000100U, 0xfa48ffe4U, 0x3a801627U, 0xf140fec2U,
    0xc0a84321U, 0xc00943a1U, 0xcb41fe62U, 0xc4b3fe60U,
    0xc694134eU, 0xfb000103U, 0x3a801c51U, 0xcce214b5U,
    0x3449be9cU, 0xfb000108U, 0x2af87e9cU, 0xcce214b5U,
    0x3449be9cU, 0xfb0001c1U, 0x2ac85709U, 0xf0000020U,
    0xfb0001cfU, 0x3a80131bU, 0xfb0001cfU, 0xf0000020U,
    0xfb00021cU, 0x3a802006U, 0xfb00021cU, 0x3a802006U,
    0x2dd05716U, 0xc0ec14b9U, 0x81f853c7U, 0xfb00021eU,
    0x3a803368U, 0x2dc07d05U, 0xf1000148U, 0xf0800004U,
    0xc0914245U, 0xc0900245U, 0xfa80fc24U, 0xe004028fU,
    0xc892187fU, 0x3a800205U, 0x2c48547eU, 0x29883e9cU,
    0xf100010eU, 0xfb62028eU, 0xfa81001eU, 0x3a800205U,
    0xf100fefeU, 0x3a800285U, 0xf100ffd6U, 0x298a127bU,
    0xfb620279U, 0xfa910018U, 0x2dde0310U, 0x28cdd53bU,
    0x2d09e404U, 0xc822b690U, 0x3460a406U, 0xcda42286U,
    0xfa920007U, 0x3a80218aU, 0x345b947dU, 0xc53f2205U,
    0xfa900008U, 0xfb800009U, 0x2dc1157bU, 0xc52f143dU,
    0xf100ffd6U, 0x3a800285U, 0x298a147dU, 0xfb62028cU,
    0xfa810026U, 0x2dc04301U, 0x298c4303U, 0xfb630283U,
    0xfa890024U, 0x2dc08008U, 0x7c8e2601U, 0x2a8c54bbU,
    0x30817849U, 0x2aa06009U, 0x2c01a402U, 0xcda22240U,
    0xfb800026U, 0x3a80157bU, 0xfb00028dU, 0x2dc0943dU,
    0x2dc0943dU, 0x3a800240U, 0xc892143eU, 0xf1000148U,
    0xfc800000U, 0xf8080000U, 0x2c58ba80U, 0x298a3e9cU,
    0xfb620299U, 0xfb800087U, 0x3a803e9cU, 0xfb00029aU,
    0x3a80183fU, 0x3a80183fU, 0xfcd80300U, 0xcfa73d7bU
};


#define ADC_STOP_SEC_CONST_32
#include "Adc_MemMap.h"


#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */


#ifdef __cplusplus
}
#endif

/** @} */
/** @endcond */

#endif /* DSPSS_CFSDADC_PMEM_H */
