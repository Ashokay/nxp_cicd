[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SDADC_IP_CFG_H
#define SDADC_IP_CFG_H

/**
*   @file Sdadc_Ip_Cfg.h
*
*   @addtogroup IP_SDADC
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

[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Sdadc_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Sdadc_Ip_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!]

[!INCLUDE "Adc_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SDADC_IP_VENDOR_ID_CFG                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFG       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_CFG       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_CFG    0
#define SDADC_IP_SW_MAJOR_VERSION_CFG               3
#define SDADC_IP_SW_MINOR_VERSION_CFG               0
#define SDADC_IP_SW_PATCH_VERSION_CFG               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]
/* Check if SDADC_Ip_Cfg.h file and SDADC_Ip_[!"."!]_PBcfg.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_CFG != SDADC_IP_VENDOR_ID_[!"text:toupper(.)"!]_PBCFG)
    #error "SDADC_Ip_Cfg.h and SDADC_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif

/* Check if SDADC_Ip_Cfg.h file and SDADC_Ip_[!"."!]_PBcfg.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFG != SDADC_IP_AR_RELEASE_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_CFG != SDADC_IP_AR_RELEASE_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_CFG != SDADC_IP_AR_RELEASE_REVISION_VERSION_[!"text:toupper(.)"!]_PBCFG) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Cfg.h and SDADC_Ip_[!"."!]_PBcfg.h are different"
#endif

/* Check if SDADC_Ip_Cfg.h file and SDADC_Ip_[!"."!]_PBcfg.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_CFG != SDADC_IP_SW_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (SDADC_IP_SW_MINOR_VERSION_CFG != SDADC_IP_SW_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (SDADC_IP_SW_PATCH_VERSION_CFG != SDADC_IP_SW_PATCH_VERSION_[!"text:toupper(.)"!]_PBCFG) \
    )
  #error "Software Version Numbers of SDADC_Ip_Cfg.h and SDADC_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]
/* Check if SDADC_Ip_Cfg.h file and SDADC_Ip_PBcfg.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_CFG != SDADC_IP_VENDOR_ID_PBCFG)
    #error "SDADC_Ip_Cfg.h and SDADC_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if SDADC_Ip_Cfg.h file and SDADC_Ip_PBcfg.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFG != SDADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_CFG != SDADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_CFG != SDADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Cfg.h and SDADC_Ip_PBcfg.h are different"
#endif

/* Check if SDADC_Ip_Cfg.h file and SDADC_Ip_PBcfg.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_CFG != SDADC_IP_SW_MAJOR_VERSION_PBCFG) || \
     (SDADC_IP_SW_MINOR_VERSION_CFG != SDADC_IP_SW_MINOR_VERSION_PBCFG) || \
     (SDADC_IP_SW_PATCH_VERSION_CFG != SDADC_IP_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of SDADC_Ip_Cfg.h and SDADC_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


/** @} */


#endif /* SDADC_IP_CFG_H */
[!ENDCODE!]
