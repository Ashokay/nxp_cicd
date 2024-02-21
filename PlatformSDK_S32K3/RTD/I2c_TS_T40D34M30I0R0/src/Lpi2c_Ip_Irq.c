/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Lpi2c_Ip.h"
#include "Lpi2c_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_IRQ_VENDOR_ID_C                      43
#define LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define LPI2C_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define LPI2C_IP_IRQ_SW_MAJOR_VERSION_C               3
#define LPI2C_IP_IRQ_SW_MINOR_VERSION_C               0
#define LPI2C_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpi2c_Ip.h */
#if ( LPI2C_IP_IRQ_VENDOR_ID_C != LPI2C_IP_VENDOR_ID)
    #error "Lpi2c_Ip_Irq.c and Lpi2c_Ip.h have different vendor ids"
#endif
#if (( LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LPI2C_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LPI2C_IP_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LPI2C_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_Irq.c and Lpi2c_Ip.h are different"
#endif
#if (( LPI2C_IP_IRQ_SW_MAJOR_VERSION_C != LPI2C_IP_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_IRQ_SW_MINOR_VERSION_C != LPI2C_IP_SW_MINOR_VERSION) || \
     ( LPI2C_IP_IRQ_SW_PATCH_VERSION_C != LPI2C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_Irq.c and Lpi2c_Ip.h are different"
#endif

/* Checks against Lpi2c_Ip_Irq.h */
#if ( LPI2C_IP_IRQ_VENDOR_ID_C != LPI2C_IP_IRQ_VENDOR_ID)
    #error "Lpi2c_Ip_Irq.c and Lpi2c_Ip_Irq.h have different vendor ids"
#endif
#if (( LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LPI2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LPI2C_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LPI2C_IP_IRQ_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_Irq.c and Lpi2c_Ip_Irq.h are different"
#endif
#if (( LPI2C_IP_IRQ_SW_MAJOR_VERSION_C != LPI2C_IP_IRQ_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_IRQ_SW_MINOR_VERSION_C != LPI2C_IP_IRQ_SW_MINOR_VERSION) || \
     ( LPI2C_IP_IRQ_SW_PATCH_VERSION_C != LPI2C_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_Irq.c and Lpi2c_Ip_Irq.h are different"
#endif

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/*******************************************************************************
 * Code
 ******************************************************************************/

#if defined (LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE)

#if (LPI2C_INSTANCE_COUNT > 0u)
/* Implementation of LPI2C0 master and slave handler named in startup code. */
ISR(LPI2C0_Master_Slave_IRQHandler)
{
    Lpi2c_Ip_ModuleIRQHandler(0);
    EXIT_INTERRUPT();
}

#if (LPI2C_INSTANCE_COUNT == 2u)
/* Implementation of LPI2C1 master and slave handler named in startup code. */
ISR(LPI2C1_Master_Slave_IRQHandler)
{
    Lpi2c_Ip_ModuleIRQHandler(1);
    EXIT_INTERRUPT();
}
#endif
#endif

#else
#if (LPI2C_INSTANCE_COUNT > 0u)
/* Implementation of LPI2C0 master handler named in startup code. */
ISR(LPI2C0_Master_IRQHandler)
{
    Lpi2c_Ip_MasterIRQHandler(0);
    EXIT_INTERRUPT();
}

/* Implementation of LPI2C0 slave handler named in startup code. */
ISR(LPI2C0_Slave_IRQHandler)
{
    Lpi2c_Ip_SlaveIRQHandler(0);
    EXIT_INTERRUPT();
}

#if(LPI2C_INSTANCE_COUNT == 2u)

/* Implementation of LPI2C1 master handler named in startup code. */
ISR(LPI2C1_Master_IRQHandler)
{
    Lpi2c_Ip_MasterIRQHandler(1U);
    EXIT_INTERRUPT();
}

/* Implementation of LPI2C1 slave handler named in startup code. */
ISR(LPI2C1_Slave_IRQHandler)
{
    Lpi2c_Ip_SlaveIRQHandler(1U);
    EXIT_INTERRUPT();
}

#endif

#endif

#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

