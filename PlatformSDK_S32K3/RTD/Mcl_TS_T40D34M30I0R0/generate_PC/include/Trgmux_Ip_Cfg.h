/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_CFG_H_
#define TRGMUX_IP_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Trgmux_Ip_Types.h"
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#include "Trgmux_Ip_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!][!//
#include "Trgmux_Ip_PBcfg.h"
[!ENDIF!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_CFG_VENDOR_ID                    43
#define TRGMUX_IP_CFG_MODULE_ID                    255
#define TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_CFG_SW_MAJOR_VERSION             3
#define TRGMUX_IP_CFG_SW_MINOR_VERSION             0
#define TRGMUX_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Trgmux_Ip_Types.h file are of the same vendor */
#if (TRGMUX_IP_CFG_VENDOR_ID != TRGMUX_IP_TYPES_VENDOR_ID)
    #error "Trgmux_Ip_Cfg.h and Trgmux_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Types.h file are of the same Autosar version */
#if ((TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Cfg.h and Trgmux_Ip_Types.h are different"
#endif

/* Check if header file and Trgmux_Ip_Types.h file are of the same Software version */
#if ((TRGMUX_IP_CFG_SW_MAJOR_VERSION != TRGMUX_IP_TYPES_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_SW_MINOR_VERSION != TRGMUX_IP_TYPES_SW_MINOR_VERSION) || \
     (TRGMUX_IP_CFG_SW_PATCH_VERSION != TRGMUX_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Cfg.h and Trgmux_Ip_Types.h are different"
#endif
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if header file and Trgmux_Ip_[!"."!]_PBcfg.h file are of the same vendor */
#if (TRGMUX_IP_CFG_VENDOR_ID != TRGMUX_IP_[!"."!]_PBCFG_VENDOR_ID)
    #error "Trgmux_Ip_Cfg.h and Trgmux_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_[!"."!]_PBcfg.h file are of the same Autosar version */
#if ((TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Cfg.h and Trgmux_Ip_[!"."!]_PBcfg.h are different"
#endif

/* Check if header file and Trgmux_Ip_[!"."!]_PBcfg.h file are of the same Software version */
#if ((TRGMUX_IP_CFG_SW_MAJOR_VERSION != TRGMUX_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_SW_MINOR_VERSION != TRGMUX_IP_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     (TRGMUX_IP_CFG_SW_PATCH_VERSION != TRGMUX_IP_[!"."!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Cfg.h and Trgmux_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if header file and Trgmux_Ip_PBcfg.h file are of the same vendor */
#if (TRGMUX_IP_CFG_VENDOR_ID != TRGMUX_IP_PBCFG_VENDOR_ID)
    #error "Trgmux_Ip_Cfg.h and Trgmux_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_PBcfg.h file are of the same Autosar version */
#if ((TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Cfg.h and Trgmux_Ip_PBcfg.h are different"
#endif

/* Check if header file and Trgmux_Ip_PBcfg.h file are of the same Software version */
#if ((TRGMUX_IP_CFG_SW_MAJOR_VERSION != TRGMUX_IP_PBCFG_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_SW_MINOR_VERSION != TRGMUX_IP_PBCFG_SW_MINOR_VERSION) || \
     (TRGMUX_IP_CFG_SW_PATCH_VERSION != TRGMUX_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Cfg.h and Trgmux_Ip_PBcfg.h are different"
#endif
[!ENDIF!][!//

[!IF "node:value(./MclGeneral/MclTrgMux/MclEnableTrgMux)"!][!//
[!INCLUDE "Trgmux_Ip_RegOperations.m"!]
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define MCL_START_SEC_CONST_8
#include "Mcl_MemMap.h"

extern const uint8 Trgmux_Ip_InstanceArr[TRGMUX_IP_NOF_INSTANCE];

#define MCL_STOP_SEC_CONST_8
#include "Mcl_MemMap.h"

/* TRGMUX Init Configuration */
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
extern const Trgmux_Ip_InitType Trgmux_Ip_xTrgmuxInitPB_[!"."!];
[!ENDLOOP!][!//
[!ELSE!][!//
extern const Trgmux_Ip_InitType Trgmux_Ip_xTrgmuxInitPB;
[!ENDIF!][!//
[!ENDIF!][!//

#ifdef __cplusplus
}
#endif

#endif /* TRGMUX_IP_CFG_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
