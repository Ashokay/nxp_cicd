[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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

#ifndef FLEXIO_I2S_IP_CFGDEFINES_H
#define FLEXIO_I2S_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup flexio_i2s_config Flexio_I2s IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "OsIf.h"
[!NOCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
[!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
[!IF "GeneralConfiguration/I2sFlexioSupport/I2sFlexioI2sEnable"!][!//
[!IF "(contains($DerivativeName, 'S32K348') or contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338'))"!][!//  reused from S32K358
[!VAR "DerivativeName" = "'S32K358'"!][!//
[!ENDIF!][!//
[!IF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394')"!][!//
[!VAR "DerivativeName" = "'S32K39'"!][!//
[!ENDIF!][!//
[!IF "contains($DerivativeName, 'S32K310')"!][!//
[!VAR "DerivativeName" = "'S32K311'"!][!//
[!ENDIF!][!//
[!IF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
[!CODE!][!WS "0"!]#include "S32M27x_FLEXIO.h"[!CR!][!ENDCODE!][!//
[!ELSE!][!//
[!IF "contains($DerivativeName, 'S32M244') or contains($DerivativeName, 'S32M242')"!][!//
[!CODE!][!WS "0"!]#include "S32M24x_FLEXIO.h"[!CR!][!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FLEXIO.h"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!//INCLUDE "I2s_VersionCheck_Src.m"!][!// TODO: add version checking
[!INCLUDE "I2s_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2S_IP_CFGDEFINES_VENDOR_ID                    43
#define FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_I2S_IP_CFGDEFINES_SW_MAJOR_VERSION             3
#define FLEXIO_I2S_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define FLEXIO_I2S_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Flexio_I2s_Ip_CfgDefines.h and StandardTypes.h are different"
#endif

/* Check if current file and OsIf header file are of the same Autosar version */
#if ((FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Flexio_I2s_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

[!CALL "Flexio_I2s_Ip_ConfigDef"!][!//

[!CALL "Flexio_I2s_Ip_FlexioChannelRefDef"!][!//

[!CALL "Flexio_I2s_Ip_FlexioPinRefDef"!][!//

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2S_IP_CFGDEFINES_H */
[!ENDCODE!]