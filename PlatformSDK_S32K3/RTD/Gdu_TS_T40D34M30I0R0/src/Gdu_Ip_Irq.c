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

/**
*   @file    Gdu_Ip_Irq.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - implementation for interrupt handling.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_IRQ_VENDOR_ID_C                      43
#define GDU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define GDU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define GDU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define GDU_IP_IRQ_SW_MAJOR_VERSION_C               3
#define GDU_IP_IRQ_SW_MINOR_VERSION_C               0
#define GDU_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP_IRQ_VENDOR_ID_C != GDU_IP_IRQ_VENDOR_ID)
    #error "Gdu_Ip_Irq.c and Gdu_Ip_Irq.h have different vendor ids"
#endif
#if ((GDU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != GDU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != GDU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != GDU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gdu_Ip_Irq.c and Gdu_Ip_Irq.h are different"
#endif
#if ((GDU_IP_IRQ_SW_MAJOR_VERSION_C != GDU_IP_IRQ_SW_MAJOR_VERSION) || \
     (GDU_IP_IRQ_SW_MINOR_VERSION_C != GDU_IP_IRQ_SW_MINOR_VERSION) || \
     (GDU_IP_IRQ_SW_PATCH_VERSION_C != GDU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gdu_Ip_Irq.c and Gdu_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
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

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

ISR(Gdu_Ip_Irq_ISR)
{
    Gdu_Ip_ISR();
}

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
