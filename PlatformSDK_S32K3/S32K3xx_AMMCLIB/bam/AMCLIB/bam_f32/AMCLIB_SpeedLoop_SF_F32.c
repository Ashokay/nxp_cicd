/**
 * AMCLIB_SpeedLoop_SF_F32.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         void AMCLIB_SpeedLoop_w_F32(int32 u1, int32 u2, GDFLIB_FILTER_MA_T_F32 work1[1], GFLIB_CONTROLLER_PIAW_P_T_F32 work2[1], GFLIB_RAMP_T_F32 work3[1], int32 work4[1], int32 u3, int32 u4, int32 u5, uint16 u6, int32 u7, int32 u8, int16 u9, int16 u10, int32 u11, int32 u12, int32 u13, int32 u14, int32 u15, int32 u16, int32 u17, int32 u18, SWLIBS_2Syst_F32 y1[1], uint16 y2[1], int32 y3[1], int32 y4[1], int32 y5[1], int32 y6[1], int32 y7[1], int32 y8[1], int32 y9[1], int32 p1, int32 p2, int32 p3, int32 p23)
 *
 *    Simulink version           : 9.3 (R2019a) 23-Nov-2018
 *    C source code generated on : 12-Sep-2023 09:21:21
 *
 */

/*  Copyright 2019-2023 NXP
 * 
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
 *  used strictly in accordance with the applicable license terms.  By expressly accepting such
 *  terms or by downloading, installing, activating and/or otherwise using the software, you are
 *  agreeing that you have read, and that you agree to comply with and are bound by, such license
 *  terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
 *  install, activate or otherwise use the software. */ 

/* Must specify the S_FUNCTION_NAME as the name of the S-function */
#define S_FUNCTION_NAME  AMCLIB_SpeedLoop_SF_F32
#define S_FUNCTION_LEVEL 2

/**
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include <string.h>
#include <stdlib.h>

/* Specific header file(s) required by the legacy code function */
#include "amclib.h"
#include "AMCLIB_SpeedLoop_w.h"
#include "gflib.h"
#include "gdflib.h"

/* Specific header file(s) required for data types declarations */
#include "SWLIBS_Typedefs.h"
#include "GDFLIB_FilterMA.h"
#include "GFLIB_ControllerPIpAW.h"
#include "GFLIB_Ramp.h"

#define EDIT_OK(S, P_IDX) \
       (!((ssGetSimMode(S)==SS_SIMMODE_SIZES_CALL_ONLY) && mxIsEmpty(ssGetSFcnParam(S, P_IDX))))

#define IS_SIMULATION_TARGET(S) (ssRTWGenIsAccelerator(S) || ssIsRapidAcceleratorActive(S) || ssRTWGenIsModelReferenceSimTarget(S) || (ssGetSimMode(S)==SS_SIMMODE_NORMAL) || (ssGetSimMode(S)==SS_SIMMODE_SIZES_CALL_ONLY) || !((ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) && GetRTWEnvironmentMode(S)==0))


/* Utility function prototypes */
static void CheckDataTypes(SimStruct *S);
static int_T GetRTWEnvironmentMode(SimStruct *S);

#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlCheckParameters ===========================================
 * Abstract:
 *   mdlCheckParameters verifies new parameter settings whenever parameter
 *   change or are re-evaluated during a simulation. When a simulation is
 *   running, changes to S-function parameters can occur at any time during
 *   the simulation loop.
 */
static void mdlCheckParameters(SimStruct *S)
{
    /* Check the parameter 1 */
    if (EDIT_OK(S, 0)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 0, "P1", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 2 */
    if (EDIT_OK(S, 1)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 1, "P2", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 3 */
    if (EDIT_OK(S, 2)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 2, "P3", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 4 */
    if (EDIT_OK(S, 3)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 3, "P4", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 5 */
    if (EDIT_OK(S, 4)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 4, "P5", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 6 */
    if (EDIT_OK(S, 5)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 5, "P6", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 7 */
    if (EDIT_OK(S, 6)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 6, "P7", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 8 */
    if (EDIT_OK(S, 7)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 7, "P8", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 9 */
    if (EDIT_OK(S, 8)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 8, "P9", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 10 */
    if (EDIT_OK(S, 9)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 9, "P10", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 11 */
    if (EDIT_OK(S, 10)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 10, "P11", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 12 */
    if (EDIT_OK(S, 11)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 11, "P12", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 13 */
    if (EDIT_OK(S, 12)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 12, "P13", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 14 */
    if (EDIT_OK(S, 13)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 13, "P14", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 15 */
    if (EDIT_OK(S, 14)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 14, "P15", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 16 */
    if (EDIT_OK(S, 15)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 15, "P16", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 17 */
    if (EDIT_OK(S, 16)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 16, "P17", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 18 */
    if (EDIT_OK(S, 17)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 17, "P18", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 19 */
    if (EDIT_OK(S, 18)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 18, "P19", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 20 */
    if (EDIT_OK(S, 19)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 19, "P20", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 21 */
    if (EDIT_OK(S, 20)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 20, "P21", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 22 */
    if (EDIT_OK(S, 21)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 21, "P22", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 23 */
    if (EDIT_OK(S, 22)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 22, "P23", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 24 */
    if (EDIT_OK(S, 23)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 23, "P24", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

}
#endif

#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlProcessParameters =========================================
 * Abstract:
 *   Update run-time parameters.
 */
static void mdlProcessParameters(SimStruct *S)
{
    ssUpdateAllTunableParamsAsRunTimeParams(S);
}
#endif

/* Function: mdlInitializeSizes ===========================================
 * Abstract:
 *   The sizes information is used by Simulink to determine the S-function
 *   block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* Flag for detecting standalone or simulation target mode */
    boolean_T isSimulationTarget = IS_SIMULATION_TARGET(S);

    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 24);

    #if defined(MATLAB_MEX_FILE) 
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        /**
         * If the number of expected input parameters is not equal
         * to the number of parameters entered in the dialog box return.
         * Simulink will generate an error indicating that there is a
         * parameter mismatch.
         */
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) return;
    } else {
        /* Return if number of expected != number of actual parameters */
        return;
    } /* if */
    #endif 

    /* Set the parameter's tunability */
    ssSetSFcnParamTunable(S, 0, 1);
    ssSetSFcnParamTunable(S, 1, 1);
    ssSetSFcnParamTunable(S, 2, 1);
    ssSetSFcnParamTunable(S, 3, 1);
    ssSetSFcnParamTunable(S, 4, 1);
    ssSetSFcnParamTunable(S, 5, 1);
    ssSetSFcnParamTunable(S, 6, 1);
    ssSetSFcnParamTunable(S, 7, 1);
    ssSetSFcnParamTunable(S, 8, 1);
    ssSetSFcnParamTunable(S, 9, 1);
    ssSetSFcnParamTunable(S, 10, 1);
    ssSetSFcnParamTunable(S, 11, 1);
    ssSetSFcnParamTunable(S, 12, 1);
    ssSetSFcnParamTunable(S, 13, 1);
    ssSetSFcnParamTunable(S, 14, 1);
    ssSetSFcnParamTunable(S, 15, 1);
    ssSetSFcnParamTunable(S, 16, 1);
    ssSetSFcnParamTunable(S, 17, 1);
    ssSetSFcnParamTunable(S, 18, 1);
    ssSetSFcnParamTunable(S, 19, 1);
    ssSetSFcnParamTunable(S, 20, 1);
    ssSetSFcnParamTunable(S, 21, 1);
    ssSetSFcnParamTunable(S, 22, 1);
    ssSetSFcnParamTunable(S, 23, 1);

    /* Set the number of work vectors */
    if (!IS_SIMULATION_TARGET(S)) {
        ssSetNumPWork(S, 0);
        if (!ssSetNumDWork(S, 4)) return;
    } else {
        ssSetNumPWork(S, 4);
        if (!ssSetNumDWork(S, 6)) return;

        /* Configure the dwork 5 (__dtSizeInfo) */
        ssSetDWorkDataType(S, 4, SS_INT32);
        ssSetDWorkUsageType(S, 4, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 4, "dtSizeInfo");
        ssSetDWorkWidth(S, 4, 7);
        ssSetDWorkComplexSignal(S, 4, COMPLEX_NO);

        /* Configure the dwork 6 (__dtBusInfo) */
        ssSetDWorkDataType(S, 5, SS_INT32);
        ssSetDWorkUsageType(S, 5, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 5, "dtBusInfo");
        ssSetDWorkWidth(S, 5, 32);
        ssSetDWorkComplexSignal(S, 5, COMPLEX_NO);
    } /* if */

    /* Configure the dwork 1 (work1) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "GDFLIB_FILTER_MA_T_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 0, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 0, "work1");
    ssSetDWorkWidth(S, 0, 1);
    ssSetDWorkComplexSignal(S, 0, COMPLEX_NO);

    /* Configure the dwork 2 (work2) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "GFLIB_CONTROLLER_PIAW_P_T_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 1, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 1, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 1, "work2");
    ssSetDWorkWidth(S, 1, 1);
    ssSetDWorkComplexSignal(S, 1, COMPLEX_NO);

    /* Configure the dwork 3 (work3) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "GFLIB_RAMP_T_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 2, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 2, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 2, "work3");
    ssSetDWorkWidth(S, 2, 1);
    ssSetDWorkComplexSignal(S, 2, COMPLEX_NO);

    /* Configure the dwork 4 (work4) */
    ssSetDWorkDataType(S, 3, SS_INT32);
    ssSetDWorkUsageType(S, 3, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 3, "work4");
    ssSetDWorkWidth(S, 3, 1);
    ssSetDWorkComplexSignal(S, 3, COMPLEX_NO);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 18)) return;

    /* Configure the input port 1 */
    ssSetInputPortDataType(S, 0, SS_INT32);
    {
        int_T u1Width = 1;
        ssSetInputPortWidth(S, 0, u1Width);
    }
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortAcceptExprInRTW(S, 0, 1);
    ssSetInputPortOverWritable(S, 0, 1);
    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 0, 1);

    /* Configure the input port 2 */
    ssSetInputPortDataType(S, 1, SS_INT32);
    {
        int_T u2Width = 1;
        ssSetInputPortWidth(S, 1, u2Width);
    }
    ssSetInputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortAcceptExprInRTW(S, 1, 1);
    ssSetInputPortOverWritable(S, 1, 1);
    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 1, 1);

    /* Configure the input port 3 */
    ssSetInputPortDataType(S, 2, SS_INT32);
    {
        int_T u3Width = 1;
        ssSetInputPortWidth(S, 2, u3Width);
    }
    ssSetInputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortAcceptExprInRTW(S, 2, 1);
    ssSetInputPortOverWritable(S, 2, 1);
    ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 2, 1);

    /* Configure the input port 4 */
    ssSetInputPortDataType(S, 3, SS_INT32);
    {
        int_T u4Width = 1;
        ssSetInputPortWidth(S, 3, u4Width);
    }
    ssSetInputPortComplexSignal(S, 3, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortAcceptExprInRTW(S, 3, 1);
    ssSetInputPortOverWritable(S, 3, 1);
    ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 3, 1);

    /* Configure the input port 5 */
    ssSetInputPortDataType(S, 4, SS_INT32);
    {
        int_T u5Width = 1;
        ssSetInputPortWidth(S, 4, u5Width);
    }
    ssSetInputPortComplexSignal(S, 4, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortAcceptExprInRTW(S, 4, 1);
    ssSetInputPortOverWritable(S, 4, 1);
    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 4, 1);

    /* Configure the input port 6 */
    ssSetInputPortDataType(S, 5, SS_UINT16);
    {
        int_T u6Width = 1;
        ssSetInputPortWidth(S, 5, u6Width);
    }
    ssSetInputPortComplexSignal(S, 5, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortAcceptExprInRTW(S, 5, 1);
    ssSetInputPortOverWritable(S, 5, 1);
    ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 5, 1);

    /* Configure the input port 7 */
    ssSetInputPortDataType(S, 6, SS_INT32);
    {
        int_T u7Width = 1;
        ssSetInputPortWidth(S, 6, u7Width);
    }
    ssSetInputPortComplexSignal(S, 6, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortAcceptExprInRTW(S, 6, 1);
    ssSetInputPortOverWritable(S, 6, 1);
    ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 6, 1);

    /* Configure the input port 8 */
    ssSetInputPortDataType(S, 7, SS_INT32);
    {
        int_T u8Width = 1;
        ssSetInputPortWidth(S, 7, u8Width);
    }
    ssSetInputPortComplexSignal(S, 7, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortAcceptExprInRTW(S, 7, 1);
    ssSetInputPortOverWritable(S, 7, 1);
    ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 7, 1);

    /* Configure the input port 9 */
    ssSetInputPortDataType(S, 8, SS_INT16);
    {
        int_T u9Width = 1;
        ssSetInputPortWidth(S, 8, u9Width);
    }
    ssSetInputPortComplexSignal(S, 8, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortAcceptExprInRTW(S, 8, 1);
    ssSetInputPortOverWritable(S, 8, 1);
    ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 8, 1);

    /* Configure the input port 10 */
    ssSetInputPortDataType(S, 9, SS_INT16);
    {
        int_T u10Width = 1;
        ssSetInputPortWidth(S, 9, u10Width);
    }
    ssSetInputPortComplexSignal(S, 9, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 9, 1);
    ssSetInputPortAcceptExprInRTW(S, 9, 1);
    ssSetInputPortOverWritable(S, 9, 1);
    ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 9, 1);

    /* Configure the input port 11 */
    ssSetInputPortDataType(S, 10, SS_INT32);
    {
        int_T u11Width = 1;
        ssSetInputPortWidth(S, 10, u11Width);
    }
    ssSetInputPortComplexSignal(S, 10, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 10, 1);
    ssSetInputPortAcceptExprInRTW(S, 10, 1);
    ssSetInputPortOverWritable(S, 10, 1);
    ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 10, 1);

    /* Configure the input port 12 */
    ssSetInputPortDataType(S, 11, SS_INT32);
    {
        int_T u12Width = 1;
        ssSetInputPortWidth(S, 11, u12Width);
    }
    ssSetInputPortComplexSignal(S, 11, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 11, 1);
    ssSetInputPortAcceptExprInRTW(S, 11, 1);
    ssSetInputPortOverWritable(S, 11, 1);
    ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 11, 1);

    /* Configure the input port 13 */
    ssSetInputPortDataType(S, 12, SS_INT32);
    {
        int_T u13Width = 1;
        ssSetInputPortWidth(S, 12, u13Width);
    }
    ssSetInputPortComplexSignal(S, 12, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 12, 1);
    ssSetInputPortAcceptExprInRTW(S, 12, 1);
    ssSetInputPortOverWritable(S, 12, 1);
    ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 12, 1);

    /* Configure the input port 14 */
    ssSetInputPortDataType(S, 13, SS_INT32);
    {
        int_T u14Width = 1;
        ssSetInputPortWidth(S, 13, u14Width);
    }
    ssSetInputPortComplexSignal(S, 13, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 13, 1);
    ssSetInputPortAcceptExprInRTW(S, 13, 1);
    ssSetInputPortOverWritable(S, 13, 1);
    ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 13, 1);

    /* Configure the input port 15 */
    ssSetInputPortDataType(S, 14, SS_INT32);
    {
        int_T u15Width = 1;
        ssSetInputPortWidth(S, 14, u15Width);
    }
    ssSetInputPortComplexSignal(S, 14, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 14, 1);
    ssSetInputPortAcceptExprInRTW(S, 14, 1);
    ssSetInputPortOverWritable(S, 14, 1);
    ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 14, 1);

    /* Configure the input port 16 */
    ssSetInputPortDataType(S, 15, SS_INT32);
    {
        int_T u16Width = 1;
        ssSetInputPortWidth(S, 15, u16Width);
    }
    ssSetInputPortComplexSignal(S, 15, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 15, 1);
    ssSetInputPortAcceptExprInRTW(S, 15, 1);
    ssSetInputPortOverWritable(S, 15, 1);
    ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 15, 1);

    /* Configure the input port 17 */
    ssSetInputPortDataType(S, 16, SS_INT32);
    {
        int_T u17Width = 1;
        ssSetInputPortWidth(S, 16, u17Width);
    }
    ssSetInputPortComplexSignal(S, 16, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 16, 1);
    ssSetInputPortAcceptExprInRTW(S, 16, 1);
    ssSetInputPortOverWritable(S, 16, 1);
    ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 16, 1);

    /* Configure the input port 18 */
    ssSetInputPortDataType(S, 17, SS_INT32);
    {
        int_T u18Width = 1;
        ssSetInputPortWidth(S, 17, u18Width);
    }
    ssSetInputPortComplexSignal(S, 17, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 17, 1);
    ssSetInputPortAcceptExprInRTW(S, 17, 1);
    ssSetInputPortOverWritable(S, 17, 1);
    ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 17, 1);

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 9)) return;

    /* Configure the output port 1 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "SWLIBS_2Syst_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetOutputPortDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusOutputObjectName(S, 0, (void *)"SWLIBS_2Syst_F32");
    ssSetBusOutputAsStruct(S, 0, 1);
    {
        int_T y1Width = 1;
        ssSetOutputPortWidth(S, 0, y1Width);
    }
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 0, 0);

    /* Configure the output port 2 */
    ssSetOutputPortDataType(S, 1, SS_UINT16);
    {
        int_T y2Width = 1;
        ssSetOutputPortWidth(S, 1, y2Width);
    }
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 1, 0);

    /* Configure the output port 3 */
    ssSetOutputPortDataType(S, 2, SS_INT32);
    {
        int_T y3Width = 1;
        ssSetOutputPortWidth(S, 2, y3Width);
    }
    ssSetOutputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 2, 0);

    /* Configure the output port 4 */
    ssSetOutputPortDataType(S, 3, SS_INT32);
    {
        int_T y4Width = 1;
        ssSetOutputPortWidth(S, 3, y4Width);
    }
    ssSetOutputPortComplexSignal(S, 3, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 3, 0);

    /* Configure the output port 5 */
    ssSetOutputPortDataType(S, 4, SS_INT32);
    {
        int_T y5Width = 1;
        ssSetOutputPortWidth(S, 4, y5Width);
    }
    ssSetOutputPortComplexSignal(S, 4, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 4, 0);

    /* Configure the output port 6 */
    ssSetOutputPortDataType(S, 5, SS_INT32);
    {
        int_T y6Width = 1;
        ssSetOutputPortWidth(S, 5, y6Width);
    }
    ssSetOutputPortComplexSignal(S, 5, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 5, 0);

    /* Configure the output port 7 */
    ssSetOutputPortDataType(S, 6, SS_INT32);
    {
        int_T y7Width = 1;
        ssSetOutputPortWidth(S, 6, y7Width);
    }
    ssSetOutputPortComplexSignal(S, 6, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 6, 0);

    /* Configure the output port 8 */
    ssSetOutputPortDataType(S, 7, SS_INT32);
    {
        int_T y8Width = 1;
        ssSetOutputPortWidth(S, 7, y8Width);
    }
    ssSetOutputPortComplexSignal(S, 7, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 7, 0);

    /* Configure the output port 9 */
    ssSetOutputPortDataType(S, 8, SS_INT32);
    {
        int_T y9Width = 1;
        ssSetOutputPortWidth(S, 8, y9Width);
    }
    ssSetOutputPortComplexSignal(S, 8, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 8, 0);

    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_SpeedLoopInit_w_F32", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_SpeedLoop_w_F32", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for wrappers */
        if (isSimulationTarget) {

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_SpeedLoopInit_w_F32_wrapper_InitializeConditions", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_SpeedLoop_w_F32_wrapper_Output", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for allocating PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_SpeedLoop_SF_F32_wrapper_allocmem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for freeing PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_SpeedLoop_SF_F32_wrapper_freemem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
        } /* if */
    } /* if */

    /* This S-function can be used in referenced model simulating in normal mode */
    ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

    /* Set the number of sample time */
    ssSetNumSampleTimes(S, 1);

    /* Set the compliance for the operating point save/restore. */
    ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);

    ssSetArrayLayoutForCodeGen(S, SS_ALL);

    /* Set the Simulink version this S-Function has been generated in */
    ssSetSimulinkVersionGeneratedIn(S, "9.3");

    /**
     * All options have the form SS_OPTION_<name> and are documented in
     * matlabroot/simulink/include/simstruc.h. The options should be
     * bitwise or'd together as in
     *    ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
     */
    ssSetOptions(S,
        SS_OPTION_USE_TLC_WITH_ACCELERATOR |
        SS_OPTION_CAN_BE_CALLED_CONDITIONALLY |
        SS_OPTION_EXCEPTION_FREE_CODE |
        SS_OPTION_WORKS_WITH_CODE_REUSE |
        SS_OPTION_SFUNCTION_INLINED_FOR_RTW |
        SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME
    );

    /* Verify Data Type consistency with specification */
    #if defined(MATLAB_MEX_FILE)
    if ((ssGetSimMode(S)!=SS_SIMMODE_SIZES_CALL_ONLY)) {
        CheckDataTypes(S);
    } /* if */
    #endif
}

/* Function: mdlInitializeSampleTimes =====================================
 * Abstract:
 *   This function is used to specify the sample time(s) for your
 *   S-function. You must register the same number of sample times as
 *   specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);

    #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    #endif
}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)
/* Function: mdlSetWorkWidths =============================================
 * Abstract:
 *   The optional method, mdlSetWorkWidths is called after input port
 *   width, output port width, and sample times of the S-function have
 *   been determined to set any state and work vector sizes which are
 *   a function of the input, output, and/or sample times. 
 *   Run-time parameters are registered in this method using methods 
 *   ssSetNumRunTimeParams, ssSetRunTimeParamInfo, and related methods.
 */
static void mdlSetWorkWidths(SimStruct *S)
{
    #if defined(ssSupportsMultipleExecInstances)
    ssSupportsMultipleExecInstances(S, 1);
    #endif

    /* Set number of run-time parameters */
    if (!ssSetNumRunTimeParams(S, 24)) return;

    /* Register the run-time parameter 1 */
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "p1", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 2 */
    ssRegDlgParamAsRunTimeParam(S, 1, 1, "p2", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 3 */
    ssRegDlgParamAsRunTimeParam(S, 2, 2, "p3", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 4 */
    ssRegDlgParamAsRunTimeParam(S, 3, 3, "p4", ssGetDataTypeId(S, "uint16"));

    /* Register the run-time parameter 5 */
    ssRegDlgParamAsRunTimeParam(S, 4, 4, "p5", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 6 */
    ssRegDlgParamAsRunTimeParam(S, 5, 5, "p6", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 7 */
    ssRegDlgParamAsRunTimeParam(S, 6, 6, "p7", ssGetDataTypeId(S, "int16"));

    /* Register the run-time parameter 8 */
    ssRegDlgParamAsRunTimeParam(S, 7, 7, "p8", ssGetDataTypeId(S, "int16"));

    /* Register the run-time parameter 9 */
    ssRegDlgParamAsRunTimeParam(S, 8, 8, "p9", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 10 */
    ssRegDlgParamAsRunTimeParam(S, 9, 9, "p10", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 11 */
    ssRegDlgParamAsRunTimeParam(S, 10, 10, "p11", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 12 */
    ssRegDlgParamAsRunTimeParam(S, 11, 11, "p12", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 13 */
    ssRegDlgParamAsRunTimeParam(S, 12, 12, "p13", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 14 */
    ssRegDlgParamAsRunTimeParam(S, 13, 13, "p14", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 15 */
    ssRegDlgParamAsRunTimeParam(S, 14, 14, "p15", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 16 */
    ssRegDlgParamAsRunTimeParam(S, 15, 15, "p16", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 17 */
    ssRegDlgParamAsRunTimeParam(S, 16, 16, "p17", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 18 */
    ssRegDlgParamAsRunTimeParam(S, 17, 17, "p18", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 19 */
    ssRegDlgParamAsRunTimeParam(S, 18, 18, "p19", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 20 */
    ssRegDlgParamAsRunTimeParam(S, 19, 19, "p20", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 21 */
    ssRegDlgParamAsRunTimeParam(S, 20, 20, "p21", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 22 */
    ssRegDlgParamAsRunTimeParam(S, 21, 21, "p22", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 23 */
    ssRegDlgParamAsRunTimeParam(S, 22, 22, "p23", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 24 */
    ssRegDlgParamAsRunTimeParam(S, 23, 23, "p24", ssGetDataTypeId(S, "int32"));
}
#endif

#define MDL_START
#if defined(MDL_START)
/* Function: mdlStart =====================================================
 * Abstract:
 *   This function is called once at start of model execution. If you
 *   have states that should be initialized once, this is the place
 *   to do it.
 */
static void mdlStart(SimStruct *S)
{
    if (IS_SIMULATION_TARGET(S)) {

        /* Access bus/struct information */
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 4);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 5);


        /* Get common data type Id */
        DTypeId __SWLIBS_2Syst_F32Id = ssGetDataTypeId(S, "SWLIBS_2Syst_F32");
        DTypeId __int32Id = ssGetDataTypeId(S, "int32");
        DTypeId __GDFLIB_FILTER_MA_T_F32Id = ssGetDataTypeId(S, "GDFLIB_FILTER_MA_T_F32");
        DTypeId __uint16Id = ssGetDataTypeId(S, "uint16");
        DTypeId __GFLIB_CONTROLLER_PIAW_P_T_F32Id = ssGetDataTypeId(S, "GFLIB_CONTROLLER_PIAW_P_T_F32");
        DTypeId __int16Id = ssGetDataTypeId(S, "int16");
        DTypeId __GFLIB_RAMP_T_F32Id = ssGetDataTypeId(S, "GFLIB_RAMP_T_F32");

        /* Get common data type size */
        __dtSizeInfo[0] = ssGetDataTypeSize(S, __SWLIBS_2Syst_F32Id);
        __dtSizeInfo[1] = ssGetDataTypeSize(S, __int32Id);
        __dtSizeInfo[2] = ssGetDataTypeSize(S, __GDFLIB_FILTER_MA_T_F32Id);
        __dtSizeInfo[3] = ssGetDataTypeSize(S, __uint16Id);
        __dtSizeInfo[4] = ssGetDataTypeSize(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id);
        __dtSizeInfo[5] = ssGetDataTypeSize(S, __int16Id);
        __dtSizeInfo[6] = ssGetDataTypeSize(S, __GFLIB_RAMP_T_F32Id);

        /* Get information for accessing SWLIBS_2Syst_F32.f32Arg1 */
        __dtBusInfo[0] = ssGetBusElementOffset(S, __SWLIBS_2Syst_F32Id, 0);
        __dtBusInfo[1] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_2Syst_F32.f32Arg2 */
        __dtBusInfo[2] = ssGetBusElementOffset(S, __SWLIBS_2Syst_F32Id, 1);
        __dtBusInfo[3] = __dtSizeInfo[1];

        /* Get information for accessing GDFLIB_FILTER_MA_T_F32.f32Acc */
        __dtBusInfo[4] = ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_F32Id, 0);
        __dtBusInfo[5] = __dtSizeInfo[1];

        /* Get information for accessing GDFLIB_FILTER_MA_T_F32.u16NSamples */
        __dtBusInfo[6] = ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_F32Id, 1);
        __dtBusInfo[7] = __dtSizeInfo[3];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.f32PropGain */
        __dtBusInfo[8] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 0);
        __dtBusInfo[9] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.f32IntegGain */
        __dtBusInfo[10] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 1);
        __dtBusInfo[11] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.s16PropGainShift */
        __dtBusInfo[12] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 2);
        __dtBusInfo[13] = __dtSizeInfo[5];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.s16IntegGainShift */
        __dtBusInfo[14] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 3);
        __dtBusInfo[15] = __dtSizeInfo[5];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.f32LowerLimit */
        __dtBusInfo[16] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 4);
        __dtBusInfo[17] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.f32UpperLimit */
        __dtBusInfo[18] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 5);
        __dtBusInfo[19] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.f32IntegPartK_1 */
        __dtBusInfo[20] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 6);
        __dtBusInfo[21] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.f32InK_1 */
        __dtBusInfo[22] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 7);
        __dtBusInfo[23] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_CONTROLLER_PIAW_P_T_F32.u16LimitFlag */
        __dtBusInfo[24] = ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_F32Id, 8);
        __dtBusInfo[25] = __dtSizeInfo[3];

        /* Get information for accessing GFLIB_RAMP_T_F32.f32State */
        __dtBusInfo[26] = ssGetBusElementOffset(S, __GFLIB_RAMP_T_F32Id, 0);
        __dtBusInfo[27] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_RAMP_T_F32.f32RampUp */
        __dtBusInfo[28] = ssGetBusElementOffset(S, __GFLIB_RAMP_T_F32Id, 1);
        __dtBusInfo[29] = __dtSizeInfo[1];

        /* Get information for accessing GFLIB_RAMP_T_F32.f32RampDown */
        __dtBusInfo[30] = ssGetBusElementOffset(S, __GFLIB_RAMP_T_F32Id, 2);
        __dtBusInfo[31] = __dtSizeInfo[1];


        /* Alloc memory for the pwork 1 (__y1BUS) */
        {
            SWLIBS_2Syst_F32* __y1BUS = (SWLIBS_2Syst_F32*)calloc(sizeof(SWLIBS_2Syst_F32), ssGetOutputPortWidth(S, 0));
            if (__y1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __y1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 0, __y1BUS);
        }

        /* Alloc memory for the pwork 2 (__work1BUS) */
        {
            GDFLIB_FILTER_MA_T_F32* __work1BUS = (GDFLIB_FILTER_MA_T_F32*)calloc(sizeof(GDFLIB_FILTER_MA_T_F32), ssGetDWorkWidth(S, 0));
            if (__work1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __work1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 1, __work1BUS);
        }

        /* Alloc memory for the pwork 3 (__work2BUS) */
        {
            GFLIB_CONTROLLER_PIAW_P_T_F32* __work2BUS = (GFLIB_CONTROLLER_PIAW_P_T_F32*)calloc(sizeof(GFLIB_CONTROLLER_PIAW_P_T_F32), ssGetDWorkWidth(S, 1));
            if (__work2BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __work2BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 2, __work2BUS);
        }

        /* Alloc memory for the pwork 4 (__work3BUS) */
        {
            GFLIB_RAMP_T_F32* __work3BUS = (GFLIB_RAMP_T_F32*)calloc(sizeof(GFLIB_RAMP_T_F32), ssGetDWorkWidth(S, 2));
            if (__work3BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __work3BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 3, __work3BUS);
        }

    } /* if */
}
#endif

#define MDL_INITIALIZE_CONDITIONS
#if defined(MDL_INITIALIZE_CONDITIONS)
/* Function: mdlInitializeConditions ======================================
 * Abstract:
 *   In this function, you should initialize the states for your S-function block.
 *   You can also perform any other initialization activities that your
 *   S-function may require. Note, this routine will be called at the
 *   start of simulation and if it is present in an enabled subsystem
 *   configured to reset states, it will be call when the enabled subsystem
 *   restarts execution to reset the states.
 */
static void mdlInitializeConditions(SimStruct *S)
{
    if (IS_SIMULATION_TARGET(S)) {
        double SampleTime = (double)ssGetSampleTime(S, 0);
        double w0;
        double pgain;
        double igain;
        double wmax;
        double kpf;
        double s16PropGainShiftQ_tmp;
        double f32PropGainQ_tmp;
        double kif;
        double s16IntegGainShiftQ_tmp;
        double f32IntegGainQ_tmp;
        double u16NSamplesW_tmp;
        double rampsc;
        double f32RampUp_tmp;
        double f32RampDown_tmp;

        /* Access bus/struct information */
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 4);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 5);


        /* Get access to Parameter/Input/Output/DWork data */
        char* work1 = (char*) ssGetDWork(S, 0);
        char* work2 = (char*) ssGetDWork(S, 1);
        char* work3 = (char*) ssGetDWork(S, 2);
        int32_T* work4 = (int32_T*) ssGetDWork(S, 3);
        uint16_T* p4 = (uint16_T*) ssGetRunTimeParamInfo(S, 3)->data;
        int32_T* p5 = (int32_T*) ssGetRunTimeParamInfo(S, 4)->data;
        int32_T* p6 = (int32_T*) ssGetRunTimeParamInfo(S, 5)->data;
        int16_T* p7 = (int16_T*) ssGetRunTimeParamInfo(S, 6)->data;
        int16_T* p8 = (int16_T*) ssGetRunTimeParamInfo(S, 7)->data;
        int32_T* p9 = (int32_T*) ssGetRunTimeParamInfo(S, 8)->data;
        int32_T* p10 = (int32_T*) ssGetRunTimeParamInfo(S, 9)->data;
        int32_T* p11 = (int32_T*) ssGetRunTimeParamInfo(S, 10)->data;
        int32_T* p12 = (int32_T*) ssGetRunTimeParamInfo(S, 11)->data;
        int32_T* p1 = (int32_T*) ssGetRunTimeParamInfo(S, 0)->data;
        int32_T* p2 = (int32_T*) ssGetRunTimeParamInfo(S, 1)->data;
        int32_T* p3 = (int32_T*) ssGetRunTimeParamInfo(S, 2)->data;
        real_T* p13 = (real_T*) ssGetRunTimeParamInfo(S, 12)->data;
        real_T* p14 = (real_T*) ssGetRunTimeParamInfo(S, 13)->data;
        real_T* p15 = (real_T*) ssGetRunTimeParamInfo(S, 14)->data;
        real_T* p16 = (real_T*) ssGetRunTimeParamInfo(S, 15)->data;
        real_T* p17 = (real_T*) ssGetRunTimeParamInfo(S, 16)->data;
        real_T* p18 = (real_T*) ssGetRunTimeParamInfo(S, 17)->data;
        real_T* p19 = (real_T*) ssGetRunTimeParamInfo(S, 18)->data;
        real_T* p20 = (real_T*) ssGetRunTimeParamInfo(S, 19)->data;
        real_T* p21 = (real_T*) ssGetRunTimeParamInfo(S, 20)->data;
        real_T* p22 = (real_T*) ssGetRunTimeParamInfo(S, 21)->data;
        int32_T* p24 = (int32_T*) ssGetRunTimeParamInfo(S, 23)->data;

        GDFLIB_FILTER_MA_T_F32* __work1BUS = (GDFLIB_FILTER_MA_T_F32*) ssGetPWorkValue(S, 1);
        GFLIB_CONTROLLER_PIAW_P_T_F32* __work2BUS = (GFLIB_CONTROLLER_PIAW_P_T_F32*) ssGetPWorkValue(S, 2);
        GFLIB_RAMP_T_F32* __work3BUS = (GFLIB_RAMP_T_F32*) ssGetPWorkValue(S, 3);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].f32Acc, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].u16NSamples, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);

        /* Assign the Simulink structure work2 to user structure __work2BUS */
        (void) memcpy(&__work2BUS[0].f32PropGain, work2 +  __dtBusInfo[8],  __dtBusInfo[9]);
        (void) memcpy(&__work2BUS[0].f32IntegGain, work2 +  __dtBusInfo[10],  __dtBusInfo[11]);
        (void) memcpy(&__work2BUS[0].s16PropGainShift, work2 +  __dtBusInfo[12],  __dtBusInfo[13]);
        (void) memcpy(&__work2BUS[0].s16IntegGainShift, work2 +  __dtBusInfo[14],  __dtBusInfo[15]);
        (void) memcpy(&__work2BUS[0].f32LowerLimit, work2 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__work2BUS[0].f32UpperLimit, work2 +  __dtBusInfo[18],  __dtBusInfo[19]);
        (void) memcpy(&__work2BUS[0].f32IntegPartK_1, work2 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work2BUS[0].f32InK_1, work2 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work2BUS[0].u16LimitFlag, work2 +  __dtBusInfo[24],  __dtBusInfo[25]);

        /* Assign the Simulink structure work3 to user structure __work3BUS */
        (void) memcpy(&__work3BUS[0].f32State, work3 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work3BUS[0].f32RampUp, work3 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work3BUS[0].f32RampDown, work3 +  __dtBusInfo[30],  __dtBusInfo[31]);

        /* Call the legacy code function */
        if((*p24) == 1) {
          w0=6.283185307179586*(*p13);
          pgain=2.0*(*p14)*w0*(*p15)/(*p16);
          igain=w0*w0*(*p15)/(*p16);
          wmax=(*p20)*(*p19)*0.1047197551196598;
          kpf=pgain*wmax/(*p22);
          s16PropGainShiftQ_tmp=ceil(M_LOG2E*log(fabs((double)kpf)));
          if(s16PropGainShiftQ_tmp<-31) {
            s16PropGainShiftQ_tmp=-31;
          }
          if(s16PropGainShiftQ_tmp>31) {
            s16PropGainShiftQ_tmp=31;
          }
          *p7=(int16_T)s16PropGainShiftQ_tmp;
          if((*p7)<0) {
            f32PropGainQ_tmp=kpf*2147483648.0*(double)(1UL << (-(*p7)));
          } else {
            f32PropGainQ_tmp=kpf*2147483648.0/(double)(1UL << (*p7));
          }
          if(f32PropGainQ_tmp>2147483647.0) {
            f32PropGainQ_tmp=2147483647.0;
          }
          if(f32PropGainQ_tmp<-2147483648.0) {
            f32PropGainQ_tmp=-2147483648.0;
          }
          *p5=(int32_T)f32PropGainQ_tmp;
          kif=igain*SampleTime*0.5*wmax/(*p22);
          s16IntegGainShiftQ_tmp=ceil(M_LOG2E*log(fabs((double)kif)));
          if(s16IntegGainShiftQ_tmp<-31) {
            s16IntegGainShiftQ_tmp=-31;
          }
          if(s16IntegGainShiftQ_tmp>31) {
            s16IntegGainShiftQ_tmp=31;
          }
          *p8=(int16_T)s16IntegGainShiftQ_tmp;
          if((*p8)<0) {
            f32IntegGainQ_tmp=kif*2147483648.0*(double)(1UL << (-(*p8)));
          } else {
            f32IntegGainQ_tmp=kif*2147483648.0/(double)(1UL << (*p8));
          }
          if(f32IntegGainQ_tmp>2147483647.0) {
            f32IntegGainQ_tmp=2147483647.0;
          }
          if(f32IntegGainQ_tmp<-2147483648.0) {
            f32IntegGainQ_tmp=-2147483648.0;
          }
          *p6=(int32_T)f32IntegGainQ_tmp;
          *p9=-2147483648;
          *p10=2147483647;
          u16NSamplesW_tmp=round(M_LOG2E*log(1.0/fabs((*p17))));
          if(u16NSamplesW_tmp>31.0) {
            u16NSamplesW_tmp=31.0;
          }
          if(u16NSamplesW_tmp<0.0) {
            u16NSamplesW_tmp=0.0;
          }
          *p4=(uint16_T)u16NSamplesW_tmp;
          rampsc=(*p20)*fabs((*p18))*0.1047197551196598/wmax;
          f32RampUp_tmp=rampsc*2147483648.0;
          if(f32RampUp_tmp>2147483647.0) {
            f32RampUp_tmp=2147483647.0;
          }
          if(f32RampUp_tmp<-2147483648.0) {
            f32RampUp_tmp=-2147483648.0;
          }
          *p11=(int32_T)f32RampUp_tmp;
          f32RampDown_tmp=rampsc*2147483648.0;
          if(f32RampDown_tmp>2147483647.0) {
            f32RampDown_tmp=2147483647.0;
          }
          if(f32RampDown_tmp<-2147483648.0) {
            f32RampDown_tmp=-2147483648.0;
          }
          *p12=(int32_T)f32RampDown_tmp;
        }
        AMCLIB_SpeedLoopInit_w_F32(__work1BUS, __work2BUS, __work3BUS, work4, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p1, *p2, *p3, *p13, *p14, *p15, *p16, *p17, *p18, *p19, *p20, *p21, *p22, *p24);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].f32Acc,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].u16NSamples,  __dtBusInfo[7]);

        /* Assign the user structure __work2BUS to the Simulink structure work2 */
        (void) memcpy(work2 +  __dtBusInfo[8], &__work2BUS[0].f32PropGain,  __dtBusInfo[9]);
        (void) memcpy(work2 +  __dtBusInfo[10], &__work2BUS[0].f32IntegGain,  __dtBusInfo[11]);
        (void) memcpy(work2 +  __dtBusInfo[12], &__work2BUS[0].s16PropGainShift,  __dtBusInfo[13]);
        (void) memcpy(work2 +  __dtBusInfo[14], &__work2BUS[0].s16IntegGainShift,  __dtBusInfo[15]);
        (void) memcpy(work2 +  __dtBusInfo[16], &__work2BUS[0].f32LowerLimit,  __dtBusInfo[17]);
        (void) memcpy(work2 +  __dtBusInfo[18], &__work2BUS[0].f32UpperLimit,  __dtBusInfo[19]);
        (void) memcpy(work2 +  __dtBusInfo[20], &__work2BUS[0].f32IntegPartK_1,  __dtBusInfo[21]);
        (void) memcpy(work2 +  __dtBusInfo[22], &__work2BUS[0].f32InK_1,  __dtBusInfo[23]);
        (void) memcpy(work2 +  __dtBusInfo[24], &__work2BUS[0].u16LimitFlag,  __dtBusInfo[25]);

        /* Assign the user structure __work3BUS to the Simulink structure work3 */
        (void) memcpy(work3 +  __dtBusInfo[26], &__work3BUS[0].f32State,  __dtBusInfo[27]);
        (void) memcpy(work3 +  __dtBusInfo[28], &__work3BUS[0].f32RampUp,  __dtBusInfo[29]);
        (void) memcpy(work3 +  __dtBusInfo[30], &__work3BUS[0].f32RampDown,  __dtBusInfo[31]);
    } /* if */
}
#endif

/* Function: mdlOutputs ===================================================
 * Abstract:
 *   In this function, you compute the outputs of your S-function
 *   block. Generally outputs are placed in the output vector(s),
 *   ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    if (IS_SIMULATION_TARGET(S)) {

        /* Access bus/struct information */
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 4);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 5);


        /* Get access to Parameter/Input/Output/DWork data */
        int32_T* u1 = (int32_T*) ssGetInputPortSignal(S, 0);
        int32_T* u2 = (int32_T*) ssGetInputPortSignal(S, 1);
        char* work1 = (char*) ssGetDWork(S, 0);
        char* work2 = (char*) ssGetDWork(S, 1);
        char* work3 = (char*) ssGetDWork(S, 2);
        int32_T* work4 = (int32_T*) ssGetDWork(S, 3);
        int32_T* u3 = (int32_T*) ssGetInputPortSignal(S, 2);
        int32_T* u4 = (int32_T*) ssGetInputPortSignal(S, 3);
        int32_T* u5 = (int32_T*) ssGetInputPortSignal(S, 4);
        uint16_T* u6 = (uint16_T*) ssGetInputPortSignal(S, 5);
        int32_T* u7 = (int32_T*) ssGetInputPortSignal(S, 6);
        int32_T* u8 = (int32_T*) ssGetInputPortSignal(S, 7);
        int16_T* u9 = (int16_T*) ssGetInputPortSignal(S, 8);
        int16_T* u10 = (int16_T*) ssGetInputPortSignal(S, 9);
        int32_T* u11 = (int32_T*) ssGetInputPortSignal(S, 10);
        int32_T* u12 = (int32_T*) ssGetInputPortSignal(S, 11);
        int32_T* u13 = (int32_T*) ssGetInputPortSignal(S, 12);
        int32_T* u14 = (int32_T*) ssGetInputPortSignal(S, 13);
        int32_T* u15 = (int32_T*) ssGetInputPortSignal(S, 14);
        int32_T* u16 = (int32_T*) ssGetInputPortSignal(S, 15);
        int32_T* u17 = (int32_T*) ssGetInputPortSignal(S, 16);
        int32_T* u18 = (int32_T*) ssGetInputPortSignal(S, 17);
        char* y1 = (char*) ssGetOutputPortSignal(S, 0);
        uint16_T* y2 = (uint16_T*) ssGetOutputPortSignal(S, 1);
        int32_T* y3 = (int32_T*) ssGetOutputPortSignal(S, 2);
        int32_T* y4 = (int32_T*) ssGetOutputPortSignal(S, 3);
        int32_T* y5 = (int32_T*) ssGetOutputPortSignal(S, 4);
        int32_T* y6 = (int32_T*) ssGetOutputPortSignal(S, 5);
        int32_T* y7 = (int32_T*) ssGetOutputPortSignal(S, 6);
        int32_T* y8 = (int32_T*) ssGetOutputPortSignal(S, 7);
        int32_T* y9 = (int32_T*) ssGetOutputPortSignal(S, 8);
        int32_T* p1 = (int32_T*) ssGetRunTimeParamInfo(S, 0)->data;
        int32_T* p2 = (int32_T*) ssGetRunTimeParamInfo(S, 1)->data;
        int32_T* p3 = (int32_T*) ssGetRunTimeParamInfo(S, 2)->data;
        int32_T* p23 = (int32_T*) ssGetRunTimeParamInfo(S, 22)->data;

        GDFLIB_FILTER_MA_T_F32* __work1BUS = (GDFLIB_FILTER_MA_T_F32*) ssGetPWorkValue(S, 1);
        GFLIB_CONTROLLER_PIAW_P_T_F32* __work2BUS = (GFLIB_CONTROLLER_PIAW_P_T_F32*) ssGetPWorkValue(S, 2);
        GFLIB_RAMP_T_F32* __work3BUS = (GFLIB_RAMP_T_F32*) ssGetPWorkValue(S, 3);
        SWLIBS_2Syst_F32* __y1BUS = (SWLIBS_2Syst_F32*) ssGetPWorkValue(S, 0);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].f32Acc, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].u16NSamples, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);

        /* Assign the Simulink structure work2 to user structure __work2BUS */
        (void) memcpy(&__work2BUS[0].f32PropGain, work2 +  __dtBusInfo[8],  __dtBusInfo[9]);
        (void) memcpy(&__work2BUS[0].f32IntegGain, work2 +  __dtBusInfo[10],  __dtBusInfo[11]);
        (void) memcpy(&__work2BUS[0].s16PropGainShift, work2 +  __dtBusInfo[12],  __dtBusInfo[13]);
        (void) memcpy(&__work2BUS[0].s16IntegGainShift, work2 +  __dtBusInfo[14],  __dtBusInfo[15]);
        (void) memcpy(&__work2BUS[0].f32LowerLimit, work2 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__work2BUS[0].f32UpperLimit, work2 +  __dtBusInfo[18],  __dtBusInfo[19]);
        (void) memcpy(&__work2BUS[0].f32IntegPartK_1, work2 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work2BUS[0].f32InK_1, work2 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work2BUS[0].u16LimitFlag, work2 +  __dtBusInfo[24],  __dtBusInfo[25]);

        /* Assign the Simulink structure work3 to user structure __work3BUS */
        (void) memcpy(&__work3BUS[0].f32State, work3 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work3BUS[0].f32RampUp, work3 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work3BUS[0].f32RampDown, work3 +  __dtBusInfo[30],  __dtBusInfo[31]);

        /* Call the legacy code function */
        AMCLIB_SpeedLoop_w_F32(*u1, *u2, __work1BUS, __work2BUS, __work3BUS, work4, *u3, *u4, *u5, *u6, *u7, *u8, *u9, *u10, *u11, *u12, *u13, *u14, *u15, *u16, *u17, *u18, __y1BUS, y2, y3, y4, y5, y6, y7, y8, y9, *p1, *p2, *p3, *p23);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].f32Acc,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].u16NSamples,  __dtBusInfo[7]);

        /* Assign the user structure __work2BUS to the Simulink structure work2 */
        (void) memcpy(work2 +  __dtBusInfo[8], &__work2BUS[0].f32PropGain,  __dtBusInfo[9]);
        (void) memcpy(work2 +  __dtBusInfo[10], &__work2BUS[0].f32IntegGain,  __dtBusInfo[11]);
        (void) memcpy(work2 +  __dtBusInfo[12], &__work2BUS[0].s16PropGainShift,  __dtBusInfo[13]);
        (void) memcpy(work2 +  __dtBusInfo[14], &__work2BUS[0].s16IntegGainShift,  __dtBusInfo[15]);
        (void) memcpy(work2 +  __dtBusInfo[16], &__work2BUS[0].f32LowerLimit,  __dtBusInfo[17]);
        (void) memcpy(work2 +  __dtBusInfo[18], &__work2BUS[0].f32UpperLimit,  __dtBusInfo[19]);
        (void) memcpy(work2 +  __dtBusInfo[20], &__work2BUS[0].f32IntegPartK_1,  __dtBusInfo[21]);
        (void) memcpy(work2 +  __dtBusInfo[22], &__work2BUS[0].f32InK_1,  __dtBusInfo[23]);
        (void) memcpy(work2 +  __dtBusInfo[24], &__work2BUS[0].u16LimitFlag,  __dtBusInfo[25]);

        /* Assign the user structure __work3BUS to the Simulink structure work3 */
        (void) memcpy(work3 +  __dtBusInfo[26], &__work3BUS[0].f32State,  __dtBusInfo[27]);
        (void) memcpy(work3 +  __dtBusInfo[28], &__work3BUS[0].f32RampUp,  __dtBusInfo[29]);
        (void) memcpy(work3 +  __dtBusInfo[30], &__work3BUS[0].f32RampDown,  __dtBusInfo[31]);

        /* Assign the user structure __y1BUS to the Simulink structure y1 */
        (void) memcpy(y1 +  __dtBusInfo[0], &__y1BUS[0].f32Arg1,  __dtBusInfo[1]);
        (void) memcpy(y1 +  __dtBusInfo[2], &__y1BUS[0].f32Arg2,  __dtBusInfo[3]);
    } /* if */
}

/* Function: mdlTerminate =================================================
 * Abstract:
 *   In this function, you should perform any actions that are necessary
 *   at the termination of a simulation.
 */
static void mdlTerminate(SimStruct *S)
{
    if (IS_SIMULATION_TARGET(S)) {

        /* Access bus/struct information */
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 4);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 5);


        /* Free memory for the pwork 1 (__y1BUS) */
        {
            SWLIBS_2Syst_F32* __y1BUS = (SWLIBS_2Syst_F32*)ssGetPWorkValue(S, 0);
            if (__y1BUS!=NULL) {
                free(__y1BUS);
                ssSetPWorkValue(S, 0, NULL);
            } /* if */
        }

        /* Free memory for the pwork 2 (__work1BUS) */
        {
            GDFLIB_FILTER_MA_T_F32* __work1BUS = (GDFLIB_FILTER_MA_T_F32*)ssGetPWorkValue(S, 1);
            if (__work1BUS!=NULL) {
                free(__work1BUS);
                ssSetPWorkValue(S, 1, NULL);
            } /* if */
        }

        /* Free memory for the pwork 3 (__work2BUS) */
        {
            GFLIB_CONTROLLER_PIAW_P_T_F32* __work2BUS = (GFLIB_CONTROLLER_PIAW_P_T_F32*)ssGetPWorkValue(S, 2);
            if (__work2BUS!=NULL) {
                free(__work2BUS);
                ssSetPWorkValue(S, 2, NULL);
            } /* if */
        }

        /* Free memory for the pwork 4 (__work3BUS) */
        {
            GFLIB_RAMP_T_F32* __work3BUS = (GFLIB_RAMP_T_F32*)ssGetPWorkValue(S, 3);
            if (__work3BUS!=NULL) {
                free(__work3BUS);
                ssSetPWorkValue(S, 3, NULL);
            } /* if */
        }

    } /* if */
}

/* Function: CheckDataTypeChecksum ========================================
 * Abstract:
 *   CheckDataTypeChecksum invokes a MATLAB helper for checking the consistency
 *   between the data type definition used when this S-Function was generated
 *   and the data type used when calling the S-Function.
 */
static int_T CheckDataTypeChecksum(SimStruct *S, const char* dtypeName, uint32_T* chkRef)
{
    mxArray *plhs[1] = {NULL};
    mxArray *prhs[3];
    mxArray *err = NULL;
    const char *bpath = ssGetPath(S);
    int_T status = -1;

    prhs[0] = mxCreateString(bpath);
    prhs[1] = mxCreateString(dtypeName);
    prhs[2] = mxCreateDoubleMatrix(1, 4, mxREAL);
    mxGetPr(prhs[2])[0] = chkRef[0];
    mxGetPr(prhs[2])[1] = chkRef[1];
    mxGetPr(prhs[2])[2] = chkRef[2];
    mxGetPr(prhs[2])[3] = chkRef[3];

    err = mexCallMATLABWithTrap(1, plhs, 3, prhs, "legacycode.LCT.getOrCompareDataTypeChecksum");
    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
    mxDestroyArray(prhs[2]);

    if (err==NULL && plhs[0]!=NULL) {
        status = mxIsEmpty(plhs[0]) ? -1 : (int_T) (mxGetScalar(plhs[0]) != 0);
        mxDestroyArray(plhs[0]);
    } /* if */

    return status;
}

/* Function: CheckDataTypes ===============================================
 * Abstract:
 *   CheckDataTypes verifies data type consistency between the data type 
 *   definition used when this S-Function was generated and the data type
 *   used when calling the S-Function.
 */
static void CheckDataTypes(SimStruct *S)
{

    /* Verify Bus/StructType 'SWLIBS_2Syst_F32', specification */
    {
        uint32_T chk[] = {3762858902, 2362665888, 1175615379, 3916019594};
        int_T status;
        status = CheckDataTypeChecksum(S, "SWLIBS_2Syst_F32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'SWLIBS_2Syst_F32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'SWLIBS_2Syst_F32' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GDFLIB_FILTER_MA_T_F32', specification */
    {
        uint32_T chk[] = {245772742, 3358598488, 2066268664, 4077883599};
        int_T status;
        status = CheckDataTypeChecksum(S, "GDFLIB_FILTER_MA_T_F32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GDFLIB_FILTER_MA_T_F32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GDFLIB_FILTER_MA_T_F32' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_CONTROLLER_PIAW_P_T_F32', specification */
    {
        uint32_T chk[] = {696638771, 964756797, 1412229007, 3227378683};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_CONTROLLER_PIAW_P_T_F32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_CONTROLLER_PIAW_P_T_F32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_CONTROLLER_PIAW_P_T_F32' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_RAMP_T_F32', specification */
    {
        uint32_T chk[] = {3888959851, 2914561210, 3281404248, 258972047};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_RAMP_T_F32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_RAMP_T_F32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_RAMP_T_F32' definition has changed since the S-Function was generated");
        }
    }
}

/* Function: GetRTWEnvironmentMode ========================================
 * Abstract:
 *   Must be called when ssRTWGenIsCodeGen(S)==true. This function
 *   returns the code generation mode:
 *       -1 if an error occurred
 *        0 for standalone code generation target
 *        1 for simulation target (Accelerator, RTW-SFcn,...)
 */
static int_T GetRTWEnvironmentMode(SimStruct *S)
{
    int_T status;
    mxArray * err;
    mxArray *plhs[1];
    mxArray *prhs[1];

    /* Get the name of the Simulink block diagram */
    prhs[0] = mxCreateString(ssGetModelName(ssGetRootSS(S)));
    plhs[0] = NULL;

    /* Call "isSimulationTarget = rtwenvironmentmode(modelName)" in MATLAB */
    err = mexCallMATLABWithTrap(1, plhs, 1, prhs, "rtwenvironmentmode");

    mxDestroyArray(prhs[0]);

    /* Set the error status if an error occurred */
    if (err) {
        if (plhs[0]) {
            mxDestroyArray(plhs[0]);
            plhs[0] = NULL;
        } /* if: } */
        ssSetErrorStatus(S, "Unknown error during call to 'rtwenvironmentmode'.");
        return -1;
    } /* if */

    /* Get the value returned by rtwenvironmentmode(modelName) */
    if (plhs[0]) {
        status = (int_T) (mxGetScalar(plhs[0]) != 0);
        mxDestroyArray(plhs[0]);
        plhs[0] = NULL;
    } /* if */

    return status;
}

/* Required S-function trailer */
#ifdef    MATLAB_MEX_FILE
# include "simulink.c"
#else
# include "cg_sfun.h"
#endif

