/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
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

#ifndef SWT_43_INSTANCE1_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define SWT_43_INSTANCE1_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file
*
*   @addtogroup Swt
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
#include "Swt_Ip_Cfg_Defines.h"
#include "Swt_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SWT_43_INSTANCE1_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG                    43
#define SWT_43_INSTANCE1_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG     4
#define SWT_43_INSTANCE1_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG     7
#define SWT_43_INSTANCE1_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG  0
#define SWT_43_INSTANCE1_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG             3
#define SWT_43_INSTANCE1_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG             0
#define SWT_43_INSTANCE1_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same vendor */
#if (SWT_43_INSTANCE1_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_CFG_DEFINES_VENDOR_ID)
#error "Swt_43_Instance1_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Swt_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same Autosar version */
#if ((SWT_43_INSTANCE1_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG    != SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG    != SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_43_Instance1_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same software version */
#if ((SWT_43_INSTANCE1_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_43_Instance1_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Swt_Ip_Types.h header file are of the same vendor */
#if (SWT_43_INSTANCE1_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_TYPES_VENDOR_ID)
#error "Swt_43_Instance1_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Swt_Ip_Types.h have different vendor ids"
#endif

#if ((SWT_43_INSTANCE1_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG    != SWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG    != SWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_43_Instance1_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Swt_Ip_Types.h are different"
#endif

#if ((SWT_43_INSTANCE1_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_TYPES_SW_MAJOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_TYPES_SW_MINOR_VERSION) || \
     (SWT_43_INSTANCE1_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG != SWT_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_43_Instance1_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Swt_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

[!NOCODE!]
[!INDENT "0"!]

[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance','1','_','TS_T40D34M30I0R0/Wdg')"!][!//
[!IF "node:exists($xPathModule)"!][!//
[!CODE!]extern const Swt_Ip_ConfigType Swt_Ip_OffModeSettings_1[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!ENDCODE!][!CR!]

[!CODE!]extern const Swt_Ip_ConfigType Swt_Ip_SlowModeSettings_1[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!ENDCODE!][!CR!]

[!CODE!]extern const Swt_Ip_ConfigType Swt_Ip_FastModeSettings_1[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!ENDCODE!][!CR!]
[!ENDIF!][!//

[!ENDINDENT!][!//
[!ENDNOCODE!]

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SWT_43_INSTANCE'1`_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H*/

