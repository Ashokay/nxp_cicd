/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_GDU_CFGDEFINES_H
#define CDD_GDU_CFGDEFINES_H

/**
*   @file    CDD_Gdu_CfgDefines.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - CDD_GDU configuration macros.
*
*   @addtogroup IPV_GDU
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_CFGDEFINES_VENDOR_ID                    43
#define GDU_CFGDEFINES_MODULE_ID                    123
#define GDU_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define GDU_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define GDU_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define GDU_CFGDEFINES_SW_MAJOR_VERSION             3
#define GDU_CFGDEFINES_SW_MINOR_VERSION             0
#define GDU_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** Switch between precompile/postbuild configurations */
#define GDU_PRECOMPILE_SUPPORT  [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** Toggle the availability of the Gdu_GetVersionInfo API */
#define GDU_VERSION_INFO_API    [!IF "GduGeneral/GduVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** Toggle the assertion of development errors */
#define GDU_DEV_ERROR_DETECT    [!IF "GduGeneral/GduDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_GDU_CFGDEFINES_H */