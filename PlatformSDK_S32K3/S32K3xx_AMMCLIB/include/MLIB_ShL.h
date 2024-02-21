/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
*   Copyright 2016-2023 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms.  By expressly accepting such
*   terms or by downloading, installing, activating and/or otherwise using the software, you are
*   agreeing that you have read, and that you agree to comply with and are bound by, such license
*   terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
******************************************************************************/
/**
*
* @file       MLIB_ShL.h
*
* @brief      Header file for MLIB_ShL function
*
******************************************************************************/
#ifndef MLIB_SHL_H
#define MLIB_SHL_H
/**
@if MLIB_GROUP
    @addtogroup MLIB_GROUP
@else
    @defgroup MLIB_GROUP   MLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif


#include "SWLIBS_Defines.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_ShL(...)     macro_dispatcher(MLIB_ShL, __VA_ARGS__)(__VA_ARGS__)     /* This function shifts the first parameter to left by number defined by second parameter. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00165 */
    #define MLIB_ShL_Dsptchr_2(In1,In2)     MLIB_ShL_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_ShL_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00165 */
    #define MLIB_ShL_Dsptchr_2(In1,In2)     MLIB_ShL_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_ShL_Dsptchr_2, do not modify!!! */
  #endif
   
  #define MLIB_ShL_Dsptchr_3(In1,In2,Impl)    MLIB_ShL_Dsptchr_(In1,In2,Impl)   /* Function dispatcher for MLIB_ShL_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00167 */
  #define MLIB_ShL_Dsptchr_(In1,In2,Impl)     MLIB_ShL_##Impl(In1,In2)          /* Function dispatcher for MLIB_ShL_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
/* MLIB_ShL_F32 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
INLINE tFrac32 ShL_F32_C(register tFrac32 f32In,register tU16 u16In)
{
  return((tFrac32)(f32In << u16In));
}

/* MLIB_ShL_F16 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
INLINE tFrac16 ShL_F16_C(register tFrac16 f16In,register tU16 u16In)
{
  return((tFrac16)(f16In << u16In));
}





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_ShL

@param[in]         f32In1     First value to be left shift.

@param[in]         u16In2     The shift amount value.

@return       32-bit fractional value shifted to left by the shift amount.
              The bits beyond the 32-bit boundary are discarded. 

*/
/**
@note         The shift amount cannot exceed in magnitude the bit-width of the
              shift value, that means must be within the range 0...31. Otherwise
              the result of the function is undefined.
              This function is implemented as inline,
              and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32Out;
tU16 u16In2;

void main(void)
{
    // first input = 0.25
    f32In1 = FRAC32(0.25);
    // second input = 1
    u16In2 = (tU16)1;

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_ShL_F32(f32In1, u16In2);

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_ShL(f32In1, u16In2, F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_ShL(f32In1, u16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00166, DMLIB00160, DMLIB00164 */
INLINE tFrac32 MLIB_ShL_F32(register tFrac32 f32In1,register tU16 u16In2)
{
  /* @remarks Implements DMLIB00162, DMLIB00163 */
  return(ShL_F32_C(f32In1,u16In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_ShL

@param[in]         f16In1     First value to be left shift.

@param[in]         u16In2     The shift amount value.

@return       16-bit fractional value shifted to left by the shift amount.
              The bits beyond the 16-bit boundary are discarded.

*/
/**
@note         The shift amount cannot exceed in magnitude the bit-width of the
              shift value, that means must be within the range 0...15. Otherwise
              the result of the function is undefined.
              This function is implemented as inline,
              and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16Out;
tU16 u16In2;

void main(void)
{
    // first input = 0.25
    f16In1 = FRAC16(0.25);
    // second input = 1
    u16In2 = (tU16)1;

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_ShL_F16(f16In1, u16In2);

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_ShL(f16In1, u16In2, F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_ShL(f16In1, u16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00166, DMLIB00160, DMLIB00164 */
INLINE tFrac16 MLIB_ShL_F16(register tFrac16 f16In1,register tU16 u16In2)
{
  /* @remarks Implements DMLIB00161, DMLIB00163 */
  return(ShL_F16_C(f16In1,u16In2));
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_SHL_H */
