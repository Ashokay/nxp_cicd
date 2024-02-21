/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef EMIOS_ICU_IP_TRUSTEDFUNCTIONS_H
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file EMIOS_ICU_IP_TRUSTEDFUNCTIONS_H.h
*
*   @addtogroup emios_icu_ip EMIOS IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Icu_Ip_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                           43
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION            4
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION            7
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION         0
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                    3
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                    0
#define EMIOS_ICU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (EMIOS_ICU_IP_TRUSTEDFUNCTIONS_VENDOR_ID != EMIOS_ICU_IP_DEFINES_VENDOR_ID)
    #error "Emios_Icu_Ip_TrustedFunctions.h and Emios_Icu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((EMIOS_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != EMIOS_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_TrustedFunctions.h and Emios_Icu_Ip_Defines.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((EMIOS_ICU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != EMIOS_ICU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != EMIOS_ICU_IP_DEFINES_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != EMIOS_ICU_IP_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_TrustedFunctions.h and Emios_Icu_Ip_Defines.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h

/**
 * @brief      Emios_Icu_Ip_SetUserAccessAllowed
 * @details    This function is called externally by OS Application
 * @param[in]  EmiosBaseAddr - The base address of Emios.
 */
#if (STD_ON == EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT)
    extern void Emios_Icu_Ip_SetUserAccessAllowed(uint32 EmiosBaseAddr);
#endif 


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#if defined(__cplusplus)
}
#endif

/** @} */

#endif  /* EMIOS_IP_TRUSTEDFUNCTIONS_H */
