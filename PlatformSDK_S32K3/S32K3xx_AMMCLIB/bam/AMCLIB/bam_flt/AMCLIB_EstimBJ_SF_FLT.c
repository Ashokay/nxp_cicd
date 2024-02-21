/**
 * AMCLIB_EstimBJ_SF_FLT.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         AMCLIB_ESTIMBJ_RET_T y1 = AMCLIB_EstimBJ_w_FLT(SWLIBS_2Syst_FLT y2[1], single y3[1], single y4[1], single y5[1], single y6[1], SWLIBS_2Syst_FLT u1[1], single u2, AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT work1[1])
 *
 *    Simulink version           : 9.3 (R2019a) 23-Nov-2018
 *    C source code generated on : 12-Sep-2023 09:22:41
 *
 */

/*  Copyright 2021-2023 NXP
 * 
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
 *  used strictly in accordance with the applicable license terms.  By expressly accepting such
 *  terms or by downloading, installing, activating and/or otherwise using the software, you are
 *  agreeing that you have read, and that you agree to comply with and are bound by, such license
 *  terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
 *  install, activate or otherwise use the software. */ 

/* Must specify the S_FUNCTION_NAME as the name of the S-function */
#define S_FUNCTION_NAME  AMCLIB_EstimBJ_SF_FLT
#define S_FUNCTION_LEVEL 2

/**
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

#include <string.h>
#include <stdlib.h>

/* Specific header file(s) required by the legacy code function */
#include "amclib.h"
#include "AMCLIB_EstimBJ_w.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"

/* Specific header file(s) required for data types declarations */
#include "AMCLIB_EstimBJ.h"
#include "SWLIBS_Typedefs.h"
#include "GFLIB_Ramp.h"
#include "GFLIB_IntegratorTR.h"
#include "GDFLIB_FilterMA.h"
#include "GFLIB_ControllerPIpAW.h"
#include "GFLIB_ControllerPIrAW.h"
#include "AMCLIB_FluxEstimAB.h"
#include "AMCLIB_TrackObsrv.h"

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
    ssSetNumSFcnParams(S, 18);

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

    /* Set the number of work vectors */
    if (!IS_SIMULATION_TARGET(S)) {
        ssSetNumPWork(S, 0);
        if (!ssSetNumDWork(S, 1)) return;
    } else {
        ssSetNumPWork(S, 3);
        if (!ssSetNumDWork(S, 3)) return;

        /* Configure the dwork 2 (__dtSizeInfo) */
        ssSetDWorkDataType(S, 1, SS_INT32);
        ssSetDWorkUsageType(S, 1, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 1, "dtSizeInfo");
        ssSetDWorkWidth(S, 1, 16);
        ssSetDWorkComplexSignal(S, 1, COMPLEX_NO);

        /* Configure the dwork 3 (__dtBusInfo) */
        ssSetDWorkDataType(S, 2, SS_INT32);
        ssSetDWorkUsageType(S, 2, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 2, "dtBusInfo");
        ssSetDWorkWidth(S, 2, 268);
        ssSetDWorkComplexSignal(S, 2, COMPLEX_NO);
    } /* if */

    /* Configure the dwork 1 (work1) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 0, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 0, "work1");
    ssSetDWorkWidth(S, 0, 1);
    ssSetDWorkComplexSignal(S, 0, COMPLEX_NO);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 2)) return;

    /* Configure the input port 1 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "SWLIBS_2Syst_FLT", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetInputPortDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusInputAsStruct(S, 0, 1);
    {
        int_T u1Width = 1;
        ssSetInputPortWidth(S, 0, u1Width);
    }
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortAcceptExprInRTW(S, 0, 0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 0, 1);

    /* Configure the input port 2 */
    ssSetInputPortDataType(S, 1, SS_SINGLE);
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

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 6)) return;

    /* Configure the output port 1 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "AMCLIB_ESTIMBJ_RET_T", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetOutputPortDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    {
        int_T y1Width = 1;
        ssSetOutputPortWidth(S, 0, y1Width);
    }
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 0, 0);

    /* Configure the output port 2 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "SWLIBS_2Syst_FLT", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetOutputPortDataType(S, 1, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusOutputObjectName(S, 1, (void *)"SWLIBS_2Syst_FLT");
    ssSetBusOutputAsStruct(S, 1, 1);
    {
        int_T y2Width = 1;
        ssSetOutputPortWidth(S, 1, y2Width);
    }
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 1, 0);

    /* Configure the output port 3 */
    ssSetOutputPortDataType(S, 2, SS_SINGLE);
    {
        int_T y3Width = 1;
        ssSetOutputPortWidth(S, 2, y3Width);
    }
    ssSetOutputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 2, 0);

    /* Configure the output port 4 */
    ssSetOutputPortDataType(S, 3, SS_SINGLE);
    {
        int_T y4Width = 1;
        ssSetOutputPortWidth(S, 3, y4Width);
    }
    ssSetOutputPortComplexSignal(S, 3, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 3, 0);

    /* Configure the output port 5 */
    ssSetOutputPortDataType(S, 4, SS_SINGLE);
    {
        int_T y5Width = 1;
        ssSetOutputPortWidth(S, 4, y5Width);
    }
    ssSetOutputPortComplexSignal(S, 4, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 4, 0);

    /* Configure the output port 6 */
    ssSetOutputPortDataType(S, 5, SS_SINGLE);
    {
        int_T y6Width = 1;
        ssSetOutputPortWidth(S, 5, y6Width);
    }
    ssSetOutputPortComplexSignal(S, 5, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 5, 0);

    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_EstimBJInit_w_FLT", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_EstimBJ_w_FLT", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for wrappers */
        if (isSimulationTarget) {

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_EstimBJInit_w_FLT_wrapper_InitializeConditions", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_EstimBJ_w_FLT_wrapper_Output", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for allocating PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_EstimBJ_SF_FLT_wrapper_allocmem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for freeing PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_EstimBJ_SF_FLT_wrapper_freemem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
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
    if (!ssSetNumRunTimeParams(S, 18)) return;

    /* Register the run-time parameter 1 */
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "p1", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 2 */
    ssRegDlgParamAsRunTimeParam(S, 1, 1, "p2", ssGetDataTypeId(S, "uint32"));

    /* Register the run-time parameter 3 */
    ssRegDlgParamAsRunTimeParam(S, 2, 2, "p3", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 4 */
    ssRegDlgParamAsRunTimeParam(S, 3, 3, "p4", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 5 */
    ssRegDlgParamAsRunTimeParam(S, 4, 4, "p5", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 6 */
    ssRegDlgParamAsRunTimeParam(S, 5, 5, "p6", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 7 */
    ssRegDlgParamAsRunTimeParam(S, 6, 6, "p7", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 8 */
    ssRegDlgParamAsRunTimeParam(S, 7, 7, "p8", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 9 */
    ssRegDlgParamAsRunTimeParam(S, 8, 8, "p9", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 10 */
    ssRegDlgParamAsRunTimeParam(S, 9, 9, "p10", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 11 */
    ssRegDlgParamAsRunTimeParam(S, 10, 10, "p11", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 12 */
    ssRegDlgParamAsRunTimeParam(S, 11, 11, "p12", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 13 */
    ssRegDlgParamAsRunTimeParam(S, 12, 12, "p13", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 14 */
    ssRegDlgParamAsRunTimeParam(S, 13, 13, "p14", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 15 */
    ssRegDlgParamAsRunTimeParam(S, 14, 14, "p15", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 16 */
    ssRegDlgParamAsRunTimeParam(S, 15, 15, "p16", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 17 */
    ssRegDlgParamAsRunTimeParam(S, 16, 16, "p17", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 18 */
    ssRegDlgParamAsRunTimeParam(S, 17, 17, "p18", ssGetDataTypeId(S, "single"));
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
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 1);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 2);


        /* Get common data type Id */
        DTypeId __SWLIBS_2Syst_FLTId = ssGetDataTypeId(S, "SWLIBS_2Syst_FLT");
        DTypeId __singleId = ssGetDataTypeId(S, "single");
        DTypeId __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId = ssGetDataTypeId(S, "AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT");
        DTypeId __AMCLIB_ESTIMBJ_STATE_TId = ssGetDataTypeId(S, "AMCLIB_ESTIMBJ_STATE_T");
        DTypeId __tBoolId = ssGetDataTypeId(S, "tBool");
        DTypeId __uint32Id = ssGetDataTypeId(S, "uint32");
        DTypeId __GFLIB_RAMP_T_FLTId = ssGetDataTypeId(S, "GFLIB_RAMP_T_FLT");
        DTypeId __GFLIB_INTEGRATOR_TR_T_F32Id = ssGetDataTypeId(S, "GFLIB_INTEGRATOR_TR_T_F32");
        DTypeId __int32Id = ssGetDataTypeId(S, "int32");
        DTypeId __uint16Id = ssGetDataTypeId(S, "uint16");
        DTypeId __GDFLIB_FILTER_MA_T_FLTId = ssGetDataTypeId(S, "GDFLIB_FILTER_MA_T_FLT");
        DTypeId __GFLIB_CONTROLLER_PIAW_P_T_FLTId = ssGetDataTypeId(S, "GFLIB_CONTROLLER_PIAW_P_T_FLT");
        DTypeId __GFLIB_CONTROLLER_PIAW_R_T_FLTId = ssGetDataTypeId(S, "GFLIB_CONTROLLER_PIAW_R_T_FLT");
        DTypeId __AMCLIB_FLUXESTIMAB_T_FLTId = ssGetDataTypeId(S, "AMCLIB_FLUXESTIMAB_T_FLT");
        DTypeId __AMCLIB_TRACK_OBSRV_T_FLTId = ssGetDataTypeId(S, "AMCLIB_TRACK_OBSRV_T_FLT");
        DTypeId __GFLIB_INTEGRATOR_TR_T_FLTId = ssGetDataTypeId(S, "GFLIB_INTEGRATOR_TR_T_FLT");

        /* Get common data type size */
        __dtSizeInfo[0] = ssGetDataTypeSize(S, __SWLIBS_2Syst_FLTId);
        __dtSizeInfo[1] = ssGetDataTypeSize(S, __singleId);
        __dtSizeInfo[2] = ssGetDataTypeSize(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId);
        __dtSizeInfo[3] = ssGetDataTypeSize(S, __AMCLIB_ESTIMBJ_STATE_TId);
        __dtSizeInfo[4] = ssGetDataTypeSize(S, __tBoolId);
        __dtSizeInfo[5] = ssGetDataTypeSize(S, __uint32Id);
        __dtSizeInfo[6] = ssGetDataTypeSize(S, __GFLIB_RAMP_T_FLTId);
        __dtSizeInfo[7] = ssGetDataTypeSize(S, __GFLIB_INTEGRATOR_TR_T_F32Id);
        __dtSizeInfo[8] = ssGetDataTypeSize(S, __int32Id);
        __dtSizeInfo[9] = ssGetDataTypeSize(S, __uint16Id);
        __dtSizeInfo[10] = ssGetDataTypeSize(S, __GDFLIB_FILTER_MA_T_FLTId);
        __dtSizeInfo[11] = ssGetDataTypeSize(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId);
        __dtSizeInfo[12] = ssGetDataTypeSize(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId);
        __dtSizeInfo[13] = ssGetDataTypeSize(S, __AMCLIB_FLUXESTIMAB_T_FLTId);
        __dtSizeInfo[14] = ssGetDataTypeSize(S, __AMCLIB_TRACK_OBSRV_T_FLTId);
        __dtSizeInfo[15] = ssGetDataTypeSize(S, __GFLIB_INTEGRATOR_TR_T_FLTId);

        /* Get information for accessing SWLIBS_2Syst_FLT.fltArg1 */
        __dtBusInfo[0] = ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[1] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_2Syst_FLT.fltArg2 */
        __dtBusInfo[2] = ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[3] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pState */
        __dtBusInfo[4] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 0);
        __dtBusInfo[5] = __dtSizeInfo[3];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.bTwoPointMeas */
        __dtBusInfo[6] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 1);
        __dtBusInfo[7] = __dtSizeInfo[4];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u32AlignTimer */
        __dtBusInfo[8] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 2);
        __dtBusInfo[9] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u32TimerPreset */
        __dtBusInfo[10] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 3);
        __dtBusInfo[11] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltIReq */
        __dtBusInfo[12] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 4);
        __dtBusInfo[13] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltDCWReq1 */
        __dtBusInfo[14] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 5);
        __dtBusInfo[15] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltDCWReq2 */
        __dtBusInfo[16] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 6);
        __dtBusInfo[17] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltACWReq */
        __dtBusInfo[18] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 7);
        __dtBusInfo[19] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWMax */
        __dtBusInfo[20] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 8);
        __dtBusInfo[21] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltPP */
        __dtBusInfo[22] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 9);
        __dtBusInfo[23] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWOl */
        __dtBusInfo[24] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 10);
        __dtBusInfo[25] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltThOl */
        __dtBusInfo[26] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 11);
        __dtBusInfo[27] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLRamp.fltState */
        __dtBusInfo[28] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 12) + ssGetBusElementOffset(S, __GFLIB_RAMP_T_FLTId, 0);
        __dtBusInfo[29] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLRamp.fltRampUp */
        __dtBusInfo[30] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 12) + ssGetBusElementOffset(S, __GFLIB_RAMP_T_FLTId, 1);
        __dtBusInfo[31] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLRamp.fltRampDown */
        __dtBusInfo[32] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 12) + ssGetBusElementOffset(S, __GFLIB_RAMP_T_FLTId, 2);
        __dtBusInfo[33] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLInteg.f32State */
        __dtBusInfo[34] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 13) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_F32Id, 0);
        __dtBusInfo[35] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLInteg.f32InK1 */
        __dtBusInfo[36] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 13) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_F32Id, 1);
        __dtBusInfo[37] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLInteg.f32C1 */
        __dtBusInfo[38] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 13) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_F32Id, 2);
        __dtBusInfo[39] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pOLInteg.u16NShift */
        __dtBusInfo[40] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 13) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_F32Id, 3);
        __dtBusInfo[41] = __dtSizeInfo[9];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIqMAFilter.fltAcc */
        __dtBusInfo[42] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 14) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[43] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIqMAFilter.fltLambda */
        __dtBusInfo[44] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 14) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[45] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pThRealTransform.fltArg1 */
        __dtBusInfo[46] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 15) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[47] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pThRealTransform.fltArg2 */
        __dtBusInfo[48] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 15) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[49] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIDQRealFbck.fltArg1 */
        __dtBusInfo[50] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 16) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[51] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIDQRealFbck.fltArg2 */
        __dtBusInfo[52] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 16) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[53] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWDcReq */
        __dtBusInfo[54] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 17);
        __dtBusInfo[55] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWAcMaxReq */
        __dtBusInfo[56] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 18);
        __dtBusInfo[57] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltIqDcReq */
        __dtBusInfo[58] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 19);
        __dtBusInfo[59] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltIqAcReq */
        __dtBusInfo[60] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 20);
        __dtBusInfo[61] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltIqAcMaxReq */
        __dtBusInfo[62] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 21);
        __dtBusInfo[63] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcReqMAFilter.fltAcc */
        __dtBusInfo[64] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 22) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[65] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcReqMAFilter.fltLambda */
        __dtBusInfo[66] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 22) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[67] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxReqMAFilter.fltAcc */
        __dtBusInfo[68] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 23) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[69] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxReqMAFilter.fltLambda */
        __dtBusInfo[70] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 23) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[71] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.fltPropGain */
        __dtBusInfo[72] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 0);
        __dtBusInfo[73] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.fltIntegGain */
        __dtBusInfo[74] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 1);
        __dtBusInfo[75] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.fltLowerLimit */
        __dtBusInfo[76] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 2);
        __dtBusInfo[77] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.fltUpperLimit */
        __dtBusInfo[78] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 3);
        __dtBusInfo[79] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.fltIntegPartK_1 */
        __dtBusInfo[80] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 4);
        __dtBusInfo[81] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.fltInK_1 */
        __dtBusInfo[82] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 5);
        __dtBusInfo[83] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWDcPI.u16LimitFlag */
        __dtBusInfo[84] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 24) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 6);
        __dtBusInfo[85] = __dtSizeInfo[9];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.fltPropGain */
        __dtBusInfo[86] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 0);
        __dtBusInfo[87] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.fltIntegGain */
        __dtBusInfo[88] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 1);
        __dtBusInfo[89] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.fltLowerLimit */
        __dtBusInfo[90] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 2);
        __dtBusInfo[91] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.fltUpperLimit */
        __dtBusInfo[92] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 3);
        __dtBusInfo[93] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.fltIntegPartK_1 */
        __dtBusInfo[94] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 4);
        __dtBusInfo[95] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.fltInK_1 */
        __dtBusInfo[96] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 5);
        __dtBusInfo[97] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWAcMaxPI.u16LimitFlag */
        __dtBusInfo[98] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 25) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_P_T_FLTId, 6);
        __dtBusInfo[99] = __dtSizeInfo[9];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWAcMaxErr */
        __dtBusInfo[100] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 26);
        __dtBusInfo[101] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWDcErr2 */
        __dtBusInfo[102] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 27);
        __dtBusInfo[103] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.f32Theta */
        __dtBusInfo[104] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 28);
        __dtBusInfo[105] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pUDQReq.fltArg1 */
        __dtBusInfo[106] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 29) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[107] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pUDQReq.fltArg2 */
        __dtBusInfo[108] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 29) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[109] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopDPI.fltCC1sc */
        __dtBusInfo[110] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 30) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 0);
        __dtBusInfo[111] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopDPI.fltCC2sc */
        __dtBusInfo[112] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 30) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 1);
        __dtBusInfo[113] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopDPI.fltAcc */
        __dtBusInfo[114] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 30) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 2);
        __dtBusInfo[115] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopDPI.fltInErrK1 */
        __dtBusInfo[116] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 30) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 3);
        __dtBusInfo[117] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopDPI.fltUpperLimit */
        __dtBusInfo[118] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 30) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 4);
        __dtBusInfo[119] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopDPI.fltLowerLimit */
        __dtBusInfo[120] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 30) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 5);
        __dtBusInfo[121] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopQPI.fltCC1sc */
        __dtBusInfo[122] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 31) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 0);
        __dtBusInfo[123] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopQPI.fltCC2sc */
        __dtBusInfo[124] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 31) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 1);
        __dtBusInfo[125] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopQPI.fltAcc */
        __dtBusInfo[126] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 31) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 2);
        __dtBusInfo[127] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopQPI.fltInErrK1 */
        __dtBusInfo[128] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 31) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 3);
        __dtBusInfo[129] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopQPI.fltUpperLimit */
        __dtBusInfo[130] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 31) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 4);
        __dtBusInfo[131] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pCloopQPI.fltLowerLimit */
        __dtBusInfo[132] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 31) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 5);
        __dtBusInfo[133] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIDQReqCLoop.fltArg1 */
        __dtBusInfo[134] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 32) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[135] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIDQReqCLoop.fltArg2 */
        __dtBusInfo[136] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 32) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[137] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIDQFbckCLoop.fltArg1 */
        __dtBusInfo[138] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 33) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[139] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pIDQFbckCLoop.fltArg2 */
        __dtBusInfo[140] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 33) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[141] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltThEl */
        __dtBusInfo[142] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 34);
        __dtBusInfo[143] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pThTransform.fltArg1 */
        __dtBusInfo[144] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 35) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[145] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pThTransform.fltArg2 */
        __dtBusInfo[146] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 35) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[147] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltDcRaw */
        __dtBusInfo[148] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 36);
        __dtBusInfo[149] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWABAcRaw.fltArg1 */
        __dtBusInfo[150] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 37) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[151] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pWABAcRaw.fltArg2 */
        __dtBusInfo[152] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 37) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[153] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllSinCosEst.fltArg1 */
        __dtBusInfo[154] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 38) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[155] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllSinCosEst.fltArg2 */
        __dtBusInfo[156] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 38) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[157] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltDcFilt */
        __dtBusInfo[158] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 39);
        __dtBusInfo[159] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltAcFilt */
        __dtBusInfo[160] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 40);
        __dtBusInfo[161] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWABEstErr */
        __dtBusInfo[162] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 41);
        __dtBusInfo[163] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllDMAFilter.fltAcc */
        __dtBusInfo[164] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 42) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[165] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllDMAFilter.fltLambda */
        __dtBusInfo[166] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 42) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[167] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllQMAFilter.fltAcc */
        __dtBusInfo[168] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 43) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[169] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllQMAFilter.fltLambda */
        __dtBusInfo[170] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 43) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[171] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllDcMAFilter.fltAcc */
        __dtBusInfo[172] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 44) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[173] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pPllDcMAFilter.fltLambda */
        __dtBusInfo[174] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 44) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[175] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltPllPiPropGain */
        __dtBusInfo[176] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 45);
        __dtBusInfo[177] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.f32ThAcEst */
        __dtBusInfo[178] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 46);
        __dtBusInfo[179] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.f32ThAcInc */
        __dtBusInfo[180] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 47);
        __dtBusInfo[181] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pFluxEstim.fltRs */
        __dtBusInfo[182] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 48) + ssGetBusElementOffset(S, __AMCLIB_FLUXESTIMAB_T_FLTId, 0);
        __dtBusInfo[183] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pFluxEstim.fltLs */
        __dtBusInfo[184] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 48) + ssGetBusElementOffset(S, __AMCLIB_FLUXESTIMAB_T_FLTId, 1);
        __dtBusInfo[185] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltLd */
        __dtBusInfo[186] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 49);
        __dtBusInfo[187] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltLq */
        __dtBusInfo[188] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 50);
        __dtBusInfo[189] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWEl */
        __dtBusInfo[190] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 51);
        __dtBusInfo[191] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltThErr */
        __dtBusInfo[192] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 52);
        __dtBusInfo[193] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltThEstim */
        __dtBusInfo[194] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 53);
        __dtBusInfo[195] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWEstim */
        __dtBusInfo[196] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 54);
        __dtBusInfo[197] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamPI.fltCC1sc */
        __dtBusInfo[198] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 0) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 0);
        __dtBusInfo[199] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamPI.fltCC2sc */
        __dtBusInfo[200] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 0) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 1);
        __dtBusInfo[201] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamPI.fltAcc */
        __dtBusInfo[202] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 0) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 2);
        __dtBusInfo[203] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamPI.fltInErrK1 */
        __dtBusInfo[204] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 0) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 3);
        __dtBusInfo[205] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamPI.fltUpperLimit */
        __dtBusInfo[206] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 0) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 4);
        __dtBusInfo[207] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamPI.fltLowerLimit */
        __dtBusInfo[208] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 0) + ssGetBusElementOffset(S, __GFLIB_CONTROLLER_PIAW_R_T_FLTId, 5);
        __dtBusInfo[209] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamInteg.fltState */
        __dtBusInfo[210] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 1) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_FLTId, 0);
        __dtBusInfo[211] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamInteg.fltInK1 */
        __dtBusInfo[212] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 1) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_FLTId, 1);
        __dtBusInfo[213] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pTrackObsrv.pParamInteg.fltC1 */
        __dtBusInfo[214] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 55) + ssGetBusElementOffset(S, __AMCLIB_TRACK_OBSRV_T_FLTId, 1) + ssGetBusElementOffset(S, __GFLIB_INTEGRATOR_TR_T_FLTId, 2);
        __dtBusInfo[215] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltPsiRaw */
        __dtBusInfo[216] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 56);
        __dtBusInfo[217] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltPsiFilt */
        __dtBusInfo[218] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 57);
        __dtBusInfo[219] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltDtVDrop */
        __dtBusInfo[220] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 58);
        __dtBusInfo[221] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pFluxMAFilter.fltAcc */
        __dtBusInfo[222] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 59) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[223] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pFluxMAFilter.fltLambda */
        __dtBusInfo[224] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 59) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[225] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u32SSTimeoutCnt */
        __dtBusInfo[226] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 60);
        __dtBusInfo[227] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u32SSBandCnt */
        __dtBusInfo[228] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 61);
        __dtBusInfo[229] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u32SSTimeoutTime */
        __dtBusInfo[230] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 62);
        __dtBusInfo[231] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u32SSTime */
        __dtBusInfo[232] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 63);
        __dtBusInfo[233] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltSSBandHalfMax */
        __dtBusInfo[234] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 64);
        __dtBusInfo[235] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltSSBandHalf */
        __dtBusInfo[236] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 65);
        __dtBusInfo[237] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltInFilt */
        __dtBusInfo[238] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 66);
        __dtBusInfo[239] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pSSMAFilter.fltAcc */
        __dtBusInfo[240] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 67) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[241] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.pSSMAFilter.fltLambda */
        __dtBusInfo[242] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 67) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[243] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.u16MeasNum */
        __dtBusInfo[244] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 68);
        __dtBusInfo[245] = __dtSizeInfo[9];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltMeDcArr */
        __dtBusInfo[246] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 69);
        __dtBusInfo[247] = 2*__dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWDcArr */
        __dtBusInfo[248] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 70);
        __dtBusInfo[249] = 2*__dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltInertiaArr */
        __dtBusInfo[250] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 71);
        __dtBusInfo[251] = 2*__dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltWDcErr */
        __dtBusInfo[252] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 72);
        __dtBusInfo[253] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltGainFOC */
        __dtBusInfo[254] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 73);
        __dtBusInfo[255] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltInvGainATO */
        __dtBusInfo[256] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 74);
        __dtBusInfo[257] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltPhShiftCorr */
        __dtBusInfo[258] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 75);
        __dtBusInfo[259] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltKt */
        __dtBusInfo[260] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 76);
        __dtBusInfo[261] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltJ */
        __dtBusInfo[262] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 77);
        __dtBusInfo[263] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltA */
        __dtBusInfo[264] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 78);
        __dtBusInfo[265] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT.fltB */
        __dtBusInfo[266] = ssGetBusElementOffset(S, __AMCLIB_ESTIMBJ_INNERST_SIM_T_FLTId, 79);
        __dtBusInfo[267] = __dtSizeInfo[1];


        /* Alloc memory for the pwork 1 (__y2BUS) */
        {
            SWLIBS_2Syst_FLT* __y2BUS = (SWLIBS_2Syst_FLT*)calloc(sizeof(SWLIBS_2Syst_FLT), ssGetOutputPortWidth(S, 1));
            if (__y2BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __y2BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 0, __y2BUS);
        }

        /* Alloc memory for the pwork 2 (__u1BUS) */
        {
            SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*)calloc(sizeof(SWLIBS_2Syst_FLT), ssGetInputPortWidth(S, 0));
            if (__u1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __u1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 1, __u1BUS);
        }

        /* Alloc memory for the pwork 3 (__work1BUS) */
        {
            AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT* __work1BUS = (AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT*)calloc(sizeof(AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT), ssGetDWorkWidth(S, 0));
            if (__work1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __work1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 2, __work1BUS);
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

        /* Access bus/struct information */
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 1);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 2);


        /* Get access to Parameter/Input/Output/DWork data */
        int32_T* p1 = (int32_T*) ssGetRunTimeParamInfo(S, 0)->data;
        uint32_T* p2 = (uint32_T*) ssGetRunTimeParamInfo(S, 1)->data;
        real32_T* p3 = (real32_T*) ssGetRunTimeParamInfo(S, 2)->data;
        real32_T* p4 = (real32_T*) ssGetRunTimeParamInfo(S, 3)->data;
        real32_T* p5 = (real32_T*) ssGetRunTimeParamInfo(S, 4)->data;
        real32_T* p6 = (real32_T*) ssGetRunTimeParamInfo(S, 5)->data;
        real32_T* p7 = (real32_T*) ssGetRunTimeParamInfo(S, 6)->data;
        real32_T* p8 = (real32_T*) ssGetRunTimeParamInfo(S, 7)->data;
        real32_T* p9 = (real32_T*) ssGetRunTimeParamInfo(S, 8)->data;
        real32_T* p10 = (real32_T*) ssGetRunTimeParamInfo(S, 9)->data;
        real32_T* p11 = (real32_T*) ssGetRunTimeParamInfo(S, 10)->data;
        real32_T* p12 = (real32_T*) ssGetRunTimeParamInfo(S, 11)->data;
        real32_T* p13 = (real32_T*) ssGetRunTimeParamInfo(S, 12)->data;
        real32_T* p14 = (real32_T*) ssGetRunTimeParamInfo(S, 13)->data;
        real32_T* p15 = (real32_T*) ssGetRunTimeParamInfo(S, 14)->data;
        real32_T* p16 = (real32_T*) ssGetRunTimeParamInfo(S, 15)->data;
        real32_T* p17 = (real32_T*) ssGetRunTimeParamInfo(S, 16)->data;
        real32_T* p18 = (real32_T*) ssGetRunTimeParamInfo(S, 17)->data;
        char* work1 = (char*) ssGetDWork(S, 0);

        AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT* __work1BUS = (AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT*) ssGetPWorkValue(S, 2);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].pState, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].bTwoPointMeas, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);
        (void) memcpy(&__work1BUS[0].u32AlignTimer, work1 +  __dtBusInfo[8],  __dtBusInfo[9]);
        (void) memcpy(&__work1BUS[0].u32TimerPreset, work1 +  __dtBusInfo[10],  __dtBusInfo[11]);
        (void) memcpy(&__work1BUS[0].fltIReq, work1 +  __dtBusInfo[12],  __dtBusInfo[13]);
        (void) memcpy(&__work1BUS[0].fltDCWReq1, work1 +  __dtBusInfo[14],  __dtBusInfo[15]);
        (void) memcpy(&__work1BUS[0].fltDCWReq2, work1 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__work1BUS[0].fltACWReq, work1 +  __dtBusInfo[18],  __dtBusInfo[19]);
        (void) memcpy(&__work1BUS[0].fltWMax, work1 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work1BUS[0].fltPP, work1 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work1BUS[0].fltWOl, work1 +  __dtBusInfo[24],  __dtBusInfo[25]);
        (void) memcpy(&__work1BUS[0].fltThOl, work1 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work1BUS[0].pOLRamp.fltState, work1 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work1BUS[0].pOLRamp.fltRampUp, work1 +  __dtBusInfo[30],  __dtBusInfo[31]);
        (void) memcpy(&__work1BUS[0].pOLRamp.fltRampDown, work1 +  __dtBusInfo[32],  __dtBusInfo[33]);
        (void) memcpy(&__work1BUS[0].pOLInteg.f32State, work1 +  __dtBusInfo[34],  __dtBusInfo[35]);
        (void) memcpy(&__work1BUS[0].pOLInteg.f32InK1, work1 +  __dtBusInfo[36],  __dtBusInfo[37]);
        (void) memcpy(&__work1BUS[0].pOLInteg.f32C1, work1 +  __dtBusInfo[38],  __dtBusInfo[39]);
        (void) memcpy(&__work1BUS[0].pOLInteg.u16NShift, work1 +  __dtBusInfo[40],  __dtBusInfo[41]);
        (void) memcpy(&__work1BUS[0].pIqMAFilter.fltAcc, work1 +  __dtBusInfo[42],  __dtBusInfo[43]);
        (void) memcpy(&__work1BUS[0].pIqMAFilter.fltLambda, work1 +  __dtBusInfo[44],  __dtBusInfo[45]);
        (void) memcpy(&__work1BUS[0].pThRealTransform.fltArg1, work1 +  __dtBusInfo[46],  __dtBusInfo[47]);
        (void) memcpy(&__work1BUS[0].pThRealTransform.fltArg2, work1 +  __dtBusInfo[48],  __dtBusInfo[49]);
        (void) memcpy(&__work1BUS[0].pIDQRealFbck.fltArg1, work1 +  __dtBusInfo[50],  __dtBusInfo[51]);
        (void) memcpy(&__work1BUS[0].pIDQRealFbck.fltArg2, work1 +  __dtBusInfo[52],  __dtBusInfo[53]);
        (void) memcpy(&__work1BUS[0].fltWDcReq, work1 +  __dtBusInfo[54],  __dtBusInfo[55]);
        (void) memcpy(&__work1BUS[0].fltWAcMaxReq, work1 +  __dtBusInfo[56],  __dtBusInfo[57]);
        (void) memcpy(&__work1BUS[0].fltIqDcReq, work1 +  __dtBusInfo[58],  __dtBusInfo[59]);
        (void) memcpy(&__work1BUS[0].fltIqAcReq, work1 +  __dtBusInfo[60],  __dtBusInfo[61]);
        (void) memcpy(&__work1BUS[0].fltIqAcMaxReq, work1 +  __dtBusInfo[62],  __dtBusInfo[63]);
        (void) memcpy(&__work1BUS[0].pWDcReqMAFilter.fltAcc, work1 +  __dtBusInfo[64],  __dtBusInfo[65]);
        (void) memcpy(&__work1BUS[0].pWDcReqMAFilter.fltLambda, work1 +  __dtBusInfo[66],  __dtBusInfo[67]);
        (void) memcpy(&__work1BUS[0].pWAcMaxReqMAFilter.fltAcc, work1 +  __dtBusInfo[68],  __dtBusInfo[69]);
        (void) memcpy(&__work1BUS[0].pWAcMaxReqMAFilter.fltLambda, work1 +  __dtBusInfo[70],  __dtBusInfo[71]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltPropGain, work1 +  __dtBusInfo[72],  __dtBusInfo[73]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltIntegGain, work1 +  __dtBusInfo[74],  __dtBusInfo[75]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltLowerLimit, work1 +  __dtBusInfo[76],  __dtBusInfo[77]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltUpperLimit, work1 +  __dtBusInfo[78],  __dtBusInfo[79]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltIntegPartK_1, work1 +  __dtBusInfo[80],  __dtBusInfo[81]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltInK_1, work1 +  __dtBusInfo[82],  __dtBusInfo[83]);
        (void) memcpy(&__work1BUS[0].pWDcPI.u16LimitFlag, work1 +  __dtBusInfo[84],  __dtBusInfo[85]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltPropGain, work1 +  __dtBusInfo[86],  __dtBusInfo[87]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltIntegGain, work1 +  __dtBusInfo[88],  __dtBusInfo[89]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltLowerLimit, work1 +  __dtBusInfo[90],  __dtBusInfo[91]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltUpperLimit, work1 +  __dtBusInfo[92],  __dtBusInfo[93]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltIntegPartK_1, work1 +  __dtBusInfo[94],  __dtBusInfo[95]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltInK_1, work1 +  __dtBusInfo[96],  __dtBusInfo[97]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.u16LimitFlag, work1 +  __dtBusInfo[98],  __dtBusInfo[99]);
        (void) memcpy(&__work1BUS[0].fltWAcMaxErr, work1 +  __dtBusInfo[100],  __dtBusInfo[101]);
        (void) memcpy(&__work1BUS[0].fltWDcErr2, work1 +  __dtBusInfo[102],  __dtBusInfo[103]);
        (void) memcpy(&__work1BUS[0].f32Theta, work1 +  __dtBusInfo[104],  __dtBusInfo[105]);
        (void) memcpy(&__work1BUS[0].pUDQReq.fltArg1, work1 +  __dtBusInfo[106],  __dtBusInfo[107]);
        (void) memcpy(&__work1BUS[0].pUDQReq.fltArg2, work1 +  __dtBusInfo[108],  __dtBusInfo[109]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltCC1sc, work1 +  __dtBusInfo[110],  __dtBusInfo[111]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltCC2sc, work1 +  __dtBusInfo[112],  __dtBusInfo[113]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltAcc, work1 +  __dtBusInfo[114],  __dtBusInfo[115]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltInErrK1, work1 +  __dtBusInfo[116],  __dtBusInfo[117]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltUpperLimit, work1 +  __dtBusInfo[118],  __dtBusInfo[119]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltLowerLimit, work1 +  __dtBusInfo[120],  __dtBusInfo[121]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltCC1sc, work1 +  __dtBusInfo[122],  __dtBusInfo[123]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltCC2sc, work1 +  __dtBusInfo[124],  __dtBusInfo[125]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltAcc, work1 +  __dtBusInfo[126],  __dtBusInfo[127]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltInErrK1, work1 +  __dtBusInfo[128],  __dtBusInfo[129]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltUpperLimit, work1 +  __dtBusInfo[130],  __dtBusInfo[131]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltLowerLimit, work1 +  __dtBusInfo[132],  __dtBusInfo[133]);
        (void) memcpy(&__work1BUS[0].pIDQReqCLoop.fltArg1, work1 +  __dtBusInfo[134],  __dtBusInfo[135]);
        (void) memcpy(&__work1BUS[0].pIDQReqCLoop.fltArg2, work1 +  __dtBusInfo[136],  __dtBusInfo[137]);
        (void) memcpy(&__work1BUS[0].pIDQFbckCLoop.fltArg1, work1 +  __dtBusInfo[138],  __dtBusInfo[139]);
        (void) memcpy(&__work1BUS[0].pIDQFbckCLoop.fltArg2, work1 +  __dtBusInfo[140],  __dtBusInfo[141]);
        (void) memcpy(&__work1BUS[0].fltThEl, work1 +  __dtBusInfo[142],  __dtBusInfo[143]);
        (void) memcpy(&__work1BUS[0].pThTransform.fltArg1, work1 +  __dtBusInfo[144],  __dtBusInfo[145]);
        (void) memcpy(&__work1BUS[0].pThTransform.fltArg2, work1 +  __dtBusInfo[146],  __dtBusInfo[147]);
        (void) memcpy(&__work1BUS[0].fltDcRaw, work1 +  __dtBusInfo[148],  __dtBusInfo[149]);
        (void) memcpy(&__work1BUS[0].pWABAcRaw.fltArg1, work1 +  __dtBusInfo[150],  __dtBusInfo[151]);
        (void) memcpy(&__work1BUS[0].pWABAcRaw.fltArg2, work1 +  __dtBusInfo[152],  __dtBusInfo[153]);
        (void) memcpy(&__work1BUS[0].pPllSinCosEst.fltArg1, work1 +  __dtBusInfo[154],  __dtBusInfo[155]);
        (void) memcpy(&__work1BUS[0].pPllSinCosEst.fltArg2, work1 +  __dtBusInfo[156],  __dtBusInfo[157]);
        (void) memcpy(&__work1BUS[0].fltDcFilt, work1 +  __dtBusInfo[158],  __dtBusInfo[159]);
        (void) memcpy(&__work1BUS[0].fltAcFilt, work1 +  __dtBusInfo[160],  __dtBusInfo[161]);
        (void) memcpy(&__work1BUS[0].fltWABEstErr, work1 +  __dtBusInfo[162],  __dtBusInfo[163]);
        (void) memcpy(&__work1BUS[0].pPllDMAFilter.fltAcc, work1 +  __dtBusInfo[164],  __dtBusInfo[165]);
        (void) memcpy(&__work1BUS[0].pPllDMAFilter.fltLambda, work1 +  __dtBusInfo[166],  __dtBusInfo[167]);
        (void) memcpy(&__work1BUS[0].pPllQMAFilter.fltAcc, work1 +  __dtBusInfo[168],  __dtBusInfo[169]);
        (void) memcpy(&__work1BUS[0].pPllQMAFilter.fltLambda, work1 +  __dtBusInfo[170],  __dtBusInfo[171]);
        (void) memcpy(&__work1BUS[0].pPllDcMAFilter.fltAcc, work1 +  __dtBusInfo[172],  __dtBusInfo[173]);
        (void) memcpy(&__work1BUS[0].pPllDcMAFilter.fltLambda, work1 +  __dtBusInfo[174],  __dtBusInfo[175]);
        (void) memcpy(&__work1BUS[0].fltPllPiPropGain, work1 +  __dtBusInfo[176],  __dtBusInfo[177]);
        (void) memcpy(&__work1BUS[0].f32ThAcEst, work1 +  __dtBusInfo[178],  __dtBusInfo[179]);
        (void) memcpy(&__work1BUS[0].f32ThAcInc, work1 +  __dtBusInfo[180],  __dtBusInfo[181]);
        (void) memcpy(&__work1BUS[0].pFluxEstim.fltRs, work1 +  __dtBusInfo[182],  __dtBusInfo[183]);
        (void) memcpy(&__work1BUS[0].pFluxEstim.fltLs, work1 +  __dtBusInfo[184],  __dtBusInfo[185]);
        (void) memcpy(&__work1BUS[0].fltLd, work1 +  __dtBusInfo[186],  __dtBusInfo[187]);
        (void) memcpy(&__work1BUS[0].fltLq, work1 +  __dtBusInfo[188],  __dtBusInfo[189]);
        (void) memcpy(&__work1BUS[0].fltWEl, work1 +  __dtBusInfo[190],  __dtBusInfo[191]);
        (void) memcpy(&__work1BUS[0].fltThErr, work1 +  __dtBusInfo[192],  __dtBusInfo[193]);
        (void) memcpy(&__work1BUS[0].fltThEstim, work1 +  __dtBusInfo[194],  __dtBusInfo[195]);
        (void) memcpy(&__work1BUS[0].fltWEstim, work1 +  __dtBusInfo[196],  __dtBusInfo[197]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltCC1sc, work1 +  __dtBusInfo[198],  __dtBusInfo[199]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltCC2sc, work1 +  __dtBusInfo[200],  __dtBusInfo[201]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltAcc, work1 +  __dtBusInfo[202],  __dtBusInfo[203]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltInErrK1, work1 +  __dtBusInfo[204],  __dtBusInfo[205]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltUpperLimit, work1 +  __dtBusInfo[206],  __dtBusInfo[207]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltLowerLimit, work1 +  __dtBusInfo[208],  __dtBusInfo[209]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamInteg.fltState, work1 +  __dtBusInfo[210],  __dtBusInfo[211]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamInteg.fltInK1, work1 +  __dtBusInfo[212],  __dtBusInfo[213]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamInteg.fltC1, work1 +  __dtBusInfo[214],  __dtBusInfo[215]);
        (void) memcpy(&__work1BUS[0].fltPsiRaw, work1 +  __dtBusInfo[216],  __dtBusInfo[217]);
        (void) memcpy(&__work1BUS[0].fltPsiFilt, work1 +  __dtBusInfo[218],  __dtBusInfo[219]);
        (void) memcpy(&__work1BUS[0].fltDtVDrop, work1 +  __dtBusInfo[220],  __dtBusInfo[221]);
        (void) memcpy(&__work1BUS[0].pFluxMAFilter.fltAcc, work1 +  __dtBusInfo[222],  __dtBusInfo[223]);
        (void) memcpy(&__work1BUS[0].pFluxMAFilter.fltLambda, work1 +  __dtBusInfo[224],  __dtBusInfo[225]);
        (void) memcpy(&__work1BUS[0].u32SSTimeoutCnt, work1 +  __dtBusInfo[226],  __dtBusInfo[227]);
        (void) memcpy(&__work1BUS[0].u32SSBandCnt, work1 +  __dtBusInfo[228],  __dtBusInfo[229]);
        (void) memcpy(&__work1BUS[0].u32SSTimeoutTime, work1 +  __dtBusInfo[230],  __dtBusInfo[231]);
        (void) memcpy(&__work1BUS[0].u32SSTime, work1 +  __dtBusInfo[232],  __dtBusInfo[233]);
        (void) memcpy(&__work1BUS[0].fltSSBandHalfMax, work1 +  __dtBusInfo[234],  __dtBusInfo[235]);
        (void) memcpy(&__work1BUS[0].fltSSBandHalf, work1 +  __dtBusInfo[236],  __dtBusInfo[237]);
        (void) memcpy(&__work1BUS[0].fltInFilt, work1 +  __dtBusInfo[238],  __dtBusInfo[239]);
        (void) memcpy(&__work1BUS[0].pSSMAFilter.fltAcc, work1 +  __dtBusInfo[240],  __dtBusInfo[241]);
        (void) memcpy(&__work1BUS[0].pSSMAFilter.fltLambda, work1 +  __dtBusInfo[242],  __dtBusInfo[243]);
        (void) memcpy(&__work1BUS[0].u16MeasNum, work1 +  __dtBusInfo[244],  __dtBusInfo[245]);
        (void) memcpy(__work1BUS[0].fltMeDcArr, work1 +  __dtBusInfo[246],  __dtBusInfo[247]);
        (void) memcpy(__work1BUS[0].fltWDcArr, work1 +  __dtBusInfo[248],  __dtBusInfo[249]);
        (void) memcpy(__work1BUS[0].fltInertiaArr, work1 +  __dtBusInfo[250],  __dtBusInfo[251]);
        (void) memcpy(&__work1BUS[0].fltWDcErr, work1 +  __dtBusInfo[252],  __dtBusInfo[253]);
        (void) memcpy(&__work1BUS[0].fltGainFOC, work1 +  __dtBusInfo[254],  __dtBusInfo[255]);
        (void) memcpy(&__work1BUS[0].fltInvGainATO, work1 +  __dtBusInfo[256],  __dtBusInfo[257]);
        (void) memcpy(&__work1BUS[0].fltPhShiftCorr, work1 +  __dtBusInfo[258],  __dtBusInfo[259]);
        (void) memcpy(&__work1BUS[0].fltKt, work1 +  __dtBusInfo[260],  __dtBusInfo[261]);
        (void) memcpy(&__work1BUS[0].fltJ, work1 +  __dtBusInfo[262],  __dtBusInfo[263]);
        (void) memcpy(&__work1BUS[0].fltA, work1 +  __dtBusInfo[264],  __dtBusInfo[265]);
        (void) memcpy(&__work1BUS[0].fltB, work1 +  __dtBusInfo[266],  __dtBusInfo[267]);

        /* Call the legacy code function */
        AMCLIB_EstimBJInit_w_FLT(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p13, *p14, *p15, *p16, *p17, *p18, __work1BUS);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].pState,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].bTwoPointMeas,  __dtBusInfo[7]);
        (void) memcpy(work1 +  __dtBusInfo[8], &__work1BUS[0].u32AlignTimer,  __dtBusInfo[9]);
        (void) memcpy(work1 +  __dtBusInfo[10], &__work1BUS[0].u32TimerPreset,  __dtBusInfo[11]);
        (void) memcpy(work1 +  __dtBusInfo[12], &__work1BUS[0].fltIReq,  __dtBusInfo[13]);
        (void) memcpy(work1 +  __dtBusInfo[14], &__work1BUS[0].fltDCWReq1,  __dtBusInfo[15]);
        (void) memcpy(work1 +  __dtBusInfo[16], &__work1BUS[0].fltDCWReq2,  __dtBusInfo[17]);
        (void) memcpy(work1 +  __dtBusInfo[18], &__work1BUS[0].fltACWReq,  __dtBusInfo[19]);
        (void) memcpy(work1 +  __dtBusInfo[20], &__work1BUS[0].fltWMax,  __dtBusInfo[21]);
        (void) memcpy(work1 +  __dtBusInfo[22], &__work1BUS[0].fltPP,  __dtBusInfo[23]);
        (void) memcpy(work1 +  __dtBusInfo[24], &__work1BUS[0].fltWOl,  __dtBusInfo[25]);
        (void) memcpy(work1 +  __dtBusInfo[26], &__work1BUS[0].fltThOl,  __dtBusInfo[27]);
        (void) memcpy(work1 +  __dtBusInfo[28], &__work1BUS[0].pOLRamp.fltState,  __dtBusInfo[29]);
        (void) memcpy(work1 +  __dtBusInfo[30], &__work1BUS[0].pOLRamp.fltRampUp,  __dtBusInfo[31]);
        (void) memcpy(work1 +  __dtBusInfo[32], &__work1BUS[0].pOLRamp.fltRampDown,  __dtBusInfo[33]);
        (void) memcpy(work1 +  __dtBusInfo[34], &__work1BUS[0].pOLInteg.f32State,  __dtBusInfo[35]);
        (void) memcpy(work1 +  __dtBusInfo[36], &__work1BUS[0].pOLInteg.f32InK1,  __dtBusInfo[37]);
        (void) memcpy(work1 +  __dtBusInfo[38], &__work1BUS[0].pOLInteg.f32C1,  __dtBusInfo[39]);
        (void) memcpy(work1 +  __dtBusInfo[40], &__work1BUS[0].pOLInteg.u16NShift,  __dtBusInfo[41]);
        (void) memcpy(work1 +  __dtBusInfo[42], &__work1BUS[0].pIqMAFilter.fltAcc,  __dtBusInfo[43]);
        (void) memcpy(work1 +  __dtBusInfo[44], &__work1BUS[0].pIqMAFilter.fltLambda,  __dtBusInfo[45]);
        (void) memcpy(work1 +  __dtBusInfo[46], &__work1BUS[0].pThRealTransform.fltArg1,  __dtBusInfo[47]);
        (void) memcpy(work1 +  __dtBusInfo[48], &__work1BUS[0].pThRealTransform.fltArg2,  __dtBusInfo[49]);
        (void) memcpy(work1 +  __dtBusInfo[50], &__work1BUS[0].pIDQRealFbck.fltArg1,  __dtBusInfo[51]);
        (void) memcpy(work1 +  __dtBusInfo[52], &__work1BUS[0].pIDQRealFbck.fltArg2,  __dtBusInfo[53]);
        (void) memcpy(work1 +  __dtBusInfo[54], &__work1BUS[0].fltWDcReq,  __dtBusInfo[55]);
        (void) memcpy(work1 +  __dtBusInfo[56], &__work1BUS[0].fltWAcMaxReq,  __dtBusInfo[57]);
        (void) memcpy(work1 +  __dtBusInfo[58], &__work1BUS[0].fltIqDcReq,  __dtBusInfo[59]);
        (void) memcpy(work1 +  __dtBusInfo[60], &__work1BUS[0].fltIqAcReq,  __dtBusInfo[61]);
        (void) memcpy(work1 +  __dtBusInfo[62], &__work1BUS[0].fltIqAcMaxReq,  __dtBusInfo[63]);
        (void) memcpy(work1 +  __dtBusInfo[64], &__work1BUS[0].pWDcReqMAFilter.fltAcc,  __dtBusInfo[65]);
        (void) memcpy(work1 +  __dtBusInfo[66], &__work1BUS[0].pWDcReqMAFilter.fltLambda,  __dtBusInfo[67]);
        (void) memcpy(work1 +  __dtBusInfo[68], &__work1BUS[0].pWAcMaxReqMAFilter.fltAcc,  __dtBusInfo[69]);
        (void) memcpy(work1 +  __dtBusInfo[70], &__work1BUS[0].pWAcMaxReqMAFilter.fltLambda,  __dtBusInfo[71]);
        (void) memcpy(work1 +  __dtBusInfo[72], &__work1BUS[0].pWDcPI.fltPropGain,  __dtBusInfo[73]);
        (void) memcpy(work1 +  __dtBusInfo[74], &__work1BUS[0].pWDcPI.fltIntegGain,  __dtBusInfo[75]);
        (void) memcpy(work1 +  __dtBusInfo[76], &__work1BUS[0].pWDcPI.fltLowerLimit,  __dtBusInfo[77]);
        (void) memcpy(work1 +  __dtBusInfo[78], &__work1BUS[0].pWDcPI.fltUpperLimit,  __dtBusInfo[79]);
        (void) memcpy(work1 +  __dtBusInfo[80], &__work1BUS[0].pWDcPI.fltIntegPartK_1,  __dtBusInfo[81]);
        (void) memcpy(work1 +  __dtBusInfo[82], &__work1BUS[0].pWDcPI.fltInK_1,  __dtBusInfo[83]);
        (void) memcpy(work1 +  __dtBusInfo[84], &__work1BUS[0].pWDcPI.u16LimitFlag,  __dtBusInfo[85]);
        (void) memcpy(work1 +  __dtBusInfo[86], &__work1BUS[0].pWAcMaxPI.fltPropGain,  __dtBusInfo[87]);
        (void) memcpy(work1 +  __dtBusInfo[88], &__work1BUS[0].pWAcMaxPI.fltIntegGain,  __dtBusInfo[89]);
        (void) memcpy(work1 +  __dtBusInfo[90], &__work1BUS[0].pWAcMaxPI.fltLowerLimit,  __dtBusInfo[91]);
        (void) memcpy(work1 +  __dtBusInfo[92], &__work1BUS[0].pWAcMaxPI.fltUpperLimit,  __dtBusInfo[93]);
        (void) memcpy(work1 +  __dtBusInfo[94], &__work1BUS[0].pWAcMaxPI.fltIntegPartK_1,  __dtBusInfo[95]);
        (void) memcpy(work1 +  __dtBusInfo[96], &__work1BUS[0].pWAcMaxPI.fltInK_1,  __dtBusInfo[97]);
        (void) memcpy(work1 +  __dtBusInfo[98], &__work1BUS[0].pWAcMaxPI.u16LimitFlag,  __dtBusInfo[99]);
        (void) memcpy(work1 +  __dtBusInfo[100], &__work1BUS[0].fltWAcMaxErr,  __dtBusInfo[101]);
        (void) memcpy(work1 +  __dtBusInfo[102], &__work1BUS[0].fltWDcErr2,  __dtBusInfo[103]);
        (void) memcpy(work1 +  __dtBusInfo[104], &__work1BUS[0].f32Theta,  __dtBusInfo[105]);
        (void) memcpy(work1 +  __dtBusInfo[106], &__work1BUS[0].pUDQReq.fltArg1,  __dtBusInfo[107]);
        (void) memcpy(work1 +  __dtBusInfo[108], &__work1BUS[0].pUDQReq.fltArg2,  __dtBusInfo[109]);
        (void) memcpy(work1 +  __dtBusInfo[110], &__work1BUS[0].pCloopDPI.fltCC1sc,  __dtBusInfo[111]);
        (void) memcpy(work1 +  __dtBusInfo[112], &__work1BUS[0].pCloopDPI.fltCC2sc,  __dtBusInfo[113]);
        (void) memcpy(work1 +  __dtBusInfo[114], &__work1BUS[0].pCloopDPI.fltAcc,  __dtBusInfo[115]);
        (void) memcpy(work1 +  __dtBusInfo[116], &__work1BUS[0].pCloopDPI.fltInErrK1,  __dtBusInfo[117]);
        (void) memcpy(work1 +  __dtBusInfo[118], &__work1BUS[0].pCloopDPI.fltUpperLimit,  __dtBusInfo[119]);
        (void) memcpy(work1 +  __dtBusInfo[120], &__work1BUS[0].pCloopDPI.fltLowerLimit,  __dtBusInfo[121]);
        (void) memcpy(work1 +  __dtBusInfo[122], &__work1BUS[0].pCloopQPI.fltCC1sc,  __dtBusInfo[123]);
        (void) memcpy(work1 +  __dtBusInfo[124], &__work1BUS[0].pCloopQPI.fltCC2sc,  __dtBusInfo[125]);
        (void) memcpy(work1 +  __dtBusInfo[126], &__work1BUS[0].pCloopQPI.fltAcc,  __dtBusInfo[127]);
        (void) memcpy(work1 +  __dtBusInfo[128], &__work1BUS[0].pCloopQPI.fltInErrK1,  __dtBusInfo[129]);
        (void) memcpy(work1 +  __dtBusInfo[130], &__work1BUS[0].pCloopQPI.fltUpperLimit,  __dtBusInfo[131]);
        (void) memcpy(work1 +  __dtBusInfo[132], &__work1BUS[0].pCloopQPI.fltLowerLimit,  __dtBusInfo[133]);
        (void) memcpy(work1 +  __dtBusInfo[134], &__work1BUS[0].pIDQReqCLoop.fltArg1,  __dtBusInfo[135]);
        (void) memcpy(work1 +  __dtBusInfo[136], &__work1BUS[0].pIDQReqCLoop.fltArg2,  __dtBusInfo[137]);
        (void) memcpy(work1 +  __dtBusInfo[138], &__work1BUS[0].pIDQFbckCLoop.fltArg1,  __dtBusInfo[139]);
        (void) memcpy(work1 +  __dtBusInfo[140], &__work1BUS[0].pIDQFbckCLoop.fltArg2,  __dtBusInfo[141]);
        (void) memcpy(work1 +  __dtBusInfo[142], &__work1BUS[0].fltThEl,  __dtBusInfo[143]);
        (void) memcpy(work1 +  __dtBusInfo[144], &__work1BUS[0].pThTransform.fltArg1,  __dtBusInfo[145]);
        (void) memcpy(work1 +  __dtBusInfo[146], &__work1BUS[0].pThTransform.fltArg2,  __dtBusInfo[147]);
        (void) memcpy(work1 +  __dtBusInfo[148], &__work1BUS[0].fltDcRaw,  __dtBusInfo[149]);
        (void) memcpy(work1 +  __dtBusInfo[150], &__work1BUS[0].pWABAcRaw.fltArg1,  __dtBusInfo[151]);
        (void) memcpy(work1 +  __dtBusInfo[152], &__work1BUS[0].pWABAcRaw.fltArg2,  __dtBusInfo[153]);
        (void) memcpy(work1 +  __dtBusInfo[154], &__work1BUS[0].pPllSinCosEst.fltArg1,  __dtBusInfo[155]);
        (void) memcpy(work1 +  __dtBusInfo[156], &__work1BUS[0].pPllSinCosEst.fltArg2,  __dtBusInfo[157]);
        (void) memcpy(work1 +  __dtBusInfo[158], &__work1BUS[0].fltDcFilt,  __dtBusInfo[159]);
        (void) memcpy(work1 +  __dtBusInfo[160], &__work1BUS[0].fltAcFilt,  __dtBusInfo[161]);
        (void) memcpy(work1 +  __dtBusInfo[162], &__work1BUS[0].fltWABEstErr,  __dtBusInfo[163]);
        (void) memcpy(work1 +  __dtBusInfo[164], &__work1BUS[0].pPllDMAFilter.fltAcc,  __dtBusInfo[165]);
        (void) memcpy(work1 +  __dtBusInfo[166], &__work1BUS[0].pPllDMAFilter.fltLambda,  __dtBusInfo[167]);
        (void) memcpy(work1 +  __dtBusInfo[168], &__work1BUS[0].pPllQMAFilter.fltAcc,  __dtBusInfo[169]);
        (void) memcpy(work1 +  __dtBusInfo[170], &__work1BUS[0].pPllQMAFilter.fltLambda,  __dtBusInfo[171]);
        (void) memcpy(work1 +  __dtBusInfo[172], &__work1BUS[0].pPllDcMAFilter.fltAcc,  __dtBusInfo[173]);
        (void) memcpy(work1 +  __dtBusInfo[174], &__work1BUS[0].pPllDcMAFilter.fltLambda,  __dtBusInfo[175]);
        (void) memcpy(work1 +  __dtBusInfo[176], &__work1BUS[0].fltPllPiPropGain,  __dtBusInfo[177]);
        (void) memcpy(work1 +  __dtBusInfo[178], &__work1BUS[0].f32ThAcEst,  __dtBusInfo[179]);
        (void) memcpy(work1 +  __dtBusInfo[180], &__work1BUS[0].f32ThAcInc,  __dtBusInfo[181]);
        (void) memcpy(work1 +  __dtBusInfo[182], &__work1BUS[0].pFluxEstim.fltRs,  __dtBusInfo[183]);
        (void) memcpy(work1 +  __dtBusInfo[184], &__work1BUS[0].pFluxEstim.fltLs,  __dtBusInfo[185]);
        (void) memcpy(work1 +  __dtBusInfo[186], &__work1BUS[0].fltLd,  __dtBusInfo[187]);
        (void) memcpy(work1 +  __dtBusInfo[188], &__work1BUS[0].fltLq,  __dtBusInfo[189]);
        (void) memcpy(work1 +  __dtBusInfo[190], &__work1BUS[0].fltWEl,  __dtBusInfo[191]);
        (void) memcpy(work1 +  __dtBusInfo[192], &__work1BUS[0].fltThErr,  __dtBusInfo[193]);
        (void) memcpy(work1 +  __dtBusInfo[194], &__work1BUS[0].fltThEstim,  __dtBusInfo[195]);
        (void) memcpy(work1 +  __dtBusInfo[196], &__work1BUS[0].fltWEstim,  __dtBusInfo[197]);
        (void) memcpy(work1 +  __dtBusInfo[198], &__work1BUS[0].pTrackObsrv.pParamPI.fltCC1sc,  __dtBusInfo[199]);
        (void) memcpy(work1 +  __dtBusInfo[200], &__work1BUS[0].pTrackObsrv.pParamPI.fltCC2sc,  __dtBusInfo[201]);
        (void) memcpy(work1 +  __dtBusInfo[202], &__work1BUS[0].pTrackObsrv.pParamPI.fltAcc,  __dtBusInfo[203]);
        (void) memcpy(work1 +  __dtBusInfo[204], &__work1BUS[0].pTrackObsrv.pParamPI.fltInErrK1,  __dtBusInfo[205]);
        (void) memcpy(work1 +  __dtBusInfo[206], &__work1BUS[0].pTrackObsrv.pParamPI.fltUpperLimit,  __dtBusInfo[207]);
        (void) memcpy(work1 +  __dtBusInfo[208], &__work1BUS[0].pTrackObsrv.pParamPI.fltLowerLimit,  __dtBusInfo[209]);
        (void) memcpy(work1 +  __dtBusInfo[210], &__work1BUS[0].pTrackObsrv.pParamInteg.fltState,  __dtBusInfo[211]);
        (void) memcpy(work1 +  __dtBusInfo[212], &__work1BUS[0].pTrackObsrv.pParamInteg.fltInK1,  __dtBusInfo[213]);
        (void) memcpy(work1 +  __dtBusInfo[214], &__work1BUS[0].pTrackObsrv.pParamInteg.fltC1,  __dtBusInfo[215]);
        (void) memcpy(work1 +  __dtBusInfo[216], &__work1BUS[0].fltPsiRaw,  __dtBusInfo[217]);
        (void) memcpy(work1 +  __dtBusInfo[218], &__work1BUS[0].fltPsiFilt,  __dtBusInfo[219]);
        (void) memcpy(work1 +  __dtBusInfo[220], &__work1BUS[0].fltDtVDrop,  __dtBusInfo[221]);
        (void) memcpy(work1 +  __dtBusInfo[222], &__work1BUS[0].pFluxMAFilter.fltAcc,  __dtBusInfo[223]);
        (void) memcpy(work1 +  __dtBusInfo[224], &__work1BUS[0].pFluxMAFilter.fltLambda,  __dtBusInfo[225]);
        (void) memcpy(work1 +  __dtBusInfo[226], &__work1BUS[0].u32SSTimeoutCnt,  __dtBusInfo[227]);
        (void) memcpy(work1 +  __dtBusInfo[228], &__work1BUS[0].u32SSBandCnt,  __dtBusInfo[229]);
        (void) memcpy(work1 +  __dtBusInfo[230], &__work1BUS[0].u32SSTimeoutTime,  __dtBusInfo[231]);
        (void) memcpy(work1 +  __dtBusInfo[232], &__work1BUS[0].u32SSTime,  __dtBusInfo[233]);
        (void) memcpy(work1 +  __dtBusInfo[234], &__work1BUS[0].fltSSBandHalfMax,  __dtBusInfo[235]);
        (void) memcpy(work1 +  __dtBusInfo[236], &__work1BUS[0].fltSSBandHalf,  __dtBusInfo[237]);
        (void) memcpy(work1 +  __dtBusInfo[238], &__work1BUS[0].fltInFilt,  __dtBusInfo[239]);
        (void) memcpy(work1 +  __dtBusInfo[240], &__work1BUS[0].pSSMAFilter.fltAcc,  __dtBusInfo[241]);
        (void) memcpy(work1 +  __dtBusInfo[242], &__work1BUS[0].pSSMAFilter.fltLambda,  __dtBusInfo[243]);
        (void) memcpy(work1 +  __dtBusInfo[244], &__work1BUS[0].u16MeasNum,  __dtBusInfo[245]);
        (void) memcpy(work1 +  __dtBusInfo[246], __work1BUS[0].fltMeDcArr,  __dtBusInfo[247]);
        (void) memcpy(work1 +  __dtBusInfo[248], __work1BUS[0].fltWDcArr,  __dtBusInfo[249]);
        (void) memcpy(work1 +  __dtBusInfo[250], __work1BUS[0].fltInertiaArr,  __dtBusInfo[251]);
        (void) memcpy(work1 +  __dtBusInfo[252], &__work1BUS[0].fltWDcErr,  __dtBusInfo[253]);
        (void) memcpy(work1 +  __dtBusInfo[254], &__work1BUS[0].fltGainFOC,  __dtBusInfo[255]);
        (void) memcpy(work1 +  __dtBusInfo[256], &__work1BUS[0].fltInvGainATO,  __dtBusInfo[257]);
        (void) memcpy(work1 +  __dtBusInfo[258], &__work1BUS[0].fltPhShiftCorr,  __dtBusInfo[259]);
        (void) memcpy(work1 +  __dtBusInfo[260], &__work1BUS[0].fltKt,  __dtBusInfo[261]);
        (void) memcpy(work1 +  __dtBusInfo[262], &__work1BUS[0].fltJ,  __dtBusInfo[263]);
        (void) memcpy(work1 +  __dtBusInfo[264], &__work1BUS[0].fltA,  __dtBusInfo[265]);
        (void) memcpy(work1 +  __dtBusInfo[266], &__work1BUS[0].fltB,  __dtBusInfo[267]);
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
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 1);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 2);


        /* Get access to Parameter/Input/Output/DWork data */
        AMCLIB_ESTIMBJ_RET_T* y1 = (AMCLIB_ESTIMBJ_RET_T*) ssGetOutputPortSignal(S, 0);
        char* y2 = (char*) ssGetOutputPortSignal(S, 1);
        real32_T* y3 = (real32_T*) ssGetOutputPortSignal(S, 2);
        real32_T* y4 = (real32_T*) ssGetOutputPortSignal(S, 3);
        real32_T* y5 = (real32_T*) ssGetOutputPortSignal(S, 4);
        real32_T* y6 = (real32_T*) ssGetOutputPortSignal(S, 5);
        char* u1 = (char*) ssGetInputPortSignal(S, 0);
        real32_T* u2 = (real32_T*) ssGetInputPortSignal(S, 1);
        char* work1 = (char*) ssGetDWork(S, 0);

        SWLIBS_2Syst_FLT* __y2BUS = (SWLIBS_2Syst_FLT*) ssGetPWorkValue(S, 0);
        SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*) ssGetPWorkValue(S, 1);
        AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT* __work1BUS = (AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT*) ssGetPWorkValue(S, 2);

        /* Assign the Simulink structure u1 to user structure __u1BUS */
        (void) memcpy(&__u1BUS[0].fltArg1, u1 +  __dtBusInfo[0],  __dtBusInfo[1]);
        (void) memcpy(&__u1BUS[0].fltArg2, u1 +  __dtBusInfo[2],  __dtBusInfo[3]);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].pState, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].bTwoPointMeas, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);
        (void) memcpy(&__work1BUS[0].u32AlignTimer, work1 +  __dtBusInfo[8],  __dtBusInfo[9]);
        (void) memcpy(&__work1BUS[0].u32TimerPreset, work1 +  __dtBusInfo[10],  __dtBusInfo[11]);
        (void) memcpy(&__work1BUS[0].fltIReq, work1 +  __dtBusInfo[12],  __dtBusInfo[13]);
        (void) memcpy(&__work1BUS[0].fltDCWReq1, work1 +  __dtBusInfo[14],  __dtBusInfo[15]);
        (void) memcpy(&__work1BUS[0].fltDCWReq2, work1 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__work1BUS[0].fltACWReq, work1 +  __dtBusInfo[18],  __dtBusInfo[19]);
        (void) memcpy(&__work1BUS[0].fltWMax, work1 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work1BUS[0].fltPP, work1 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work1BUS[0].fltWOl, work1 +  __dtBusInfo[24],  __dtBusInfo[25]);
        (void) memcpy(&__work1BUS[0].fltThOl, work1 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work1BUS[0].pOLRamp.fltState, work1 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work1BUS[0].pOLRamp.fltRampUp, work1 +  __dtBusInfo[30],  __dtBusInfo[31]);
        (void) memcpy(&__work1BUS[0].pOLRamp.fltRampDown, work1 +  __dtBusInfo[32],  __dtBusInfo[33]);
        (void) memcpy(&__work1BUS[0].pOLInteg.f32State, work1 +  __dtBusInfo[34],  __dtBusInfo[35]);
        (void) memcpy(&__work1BUS[0].pOLInteg.f32InK1, work1 +  __dtBusInfo[36],  __dtBusInfo[37]);
        (void) memcpy(&__work1BUS[0].pOLInteg.f32C1, work1 +  __dtBusInfo[38],  __dtBusInfo[39]);
        (void) memcpy(&__work1BUS[0].pOLInteg.u16NShift, work1 +  __dtBusInfo[40],  __dtBusInfo[41]);
        (void) memcpy(&__work1BUS[0].pIqMAFilter.fltAcc, work1 +  __dtBusInfo[42],  __dtBusInfo[43]);
        (void) memcpy(&__work1BUS[0].pIqMAFilter.fltLambda, work1 +  __dtBusInfo[44],  __dtBusInfo[45]);
        (void) memcpy(&__work1BUS[0].pThRealTransform.fltArg1, work1 +  __dtBusInfo[46],  __dtBusInfo[47]);
        (void) memcpy(&__work1BUS[0].pThRealTransform.fltArg2, work1 +  __dtBusInfo[48],  __dtBusInfo[49]);
        (void) memcpy(&__work1BUS[0].pIDQRealFbck.fltArg1, work1 +  __dtBusInfo[50],  __dtBusInfo[51]);
        (void) memcpy(&__work1BUS[0].pIDQRealFbck.fltArg2, work1 +  __dtBusInfo[52],  __dtBusInfo[53]);
        (void) memcpy(&__work1BUS[0].fltWDcReq, work1 +  __dtBusInfo[54],  __dtBusInfo[55]);
        (void) memcpy(&__work1BUS[0].fltWAcMaxReq, work1 +  __dtBusInfo[56],  __dtBusInfo[57]);
        (void) memcpy(&__work1BUS[0].fltIqDcReq, work1 +  __dtBusInfo[58],  __dtBusInfo[59]);
        (void) memcpy(&__work1BUS[0].fltIqAcReq, work1 +  __dtBusInfo[60],  __dtBusInfo[61]);
        (void) memcpy(&__work1BUS[0].fltIqAcMaxReq, work1 +  __dtBusInfo[62],  __dtBusInfo[63]);
        (void) memcpy(&__work1BUS[0].pWDcReqMAFilter.fltAcc, work1 +  __dtBusInfo[64],  __dtBusInfo[65]);
        (void) memcpy(&__work1BUS[0].pWDcReqMAFilter.fltLambda, work1 +  __dtBusInfo[66],  __dtBusInfo[67]);
        (void) memcpy(&__work1BUS[0].pWAcMaxReqMAFilter.fltAcc, work1 +  __dtBusInfo[68],  __dtBusInfo[69]);
        (void) memcpy(&__work1BUS[0].pWAcMaxReqMAFilter.fltLambda, work1 +  __dtBusInfo[70],  __dtBusInfo[71]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltPropGain, work1 +  __dtBusInfo[72],  __dtBusInfo[73]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltIntegGain, work1 +  __dtBusInfo[74],  __dtBusInfo[75]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltLowerLimit, work1 +  __dtBusInfo[76],  __dtBusInfo[77]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltUpperLimit, work1 +  __dtBusInfo[78],  __dtBusInfo[79]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltIntegPartK_1, work1 +  __dtBusInfo[80],  __dtBusInfo[81]);
        (void) memcpy(&__work1BUS[0].pWDcPI.fltInK_1, work1 +  __dtBusInfo[82],  __dtBusInfo[83]);
        (void) memcpy(&__work1BUS[0].pWDcPI.u16LimitFlag, work1 +  __dtBusInfo[84],  __dtBusInfo[85]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltPropGain, work1 +  __dtBusInfo[86],  __dtBusInfo[87]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltIntegGain, work1 +  __dtBusInfo[88],  __dtBusInfo[89]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltLowerLimit, work1 +  __dtBusInfo[90],  __dtBusInfo[91]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltUpperLimit, work1 +  __dtBusInfo[92],  __dtBusInfo[93]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltIntegPartK_1, work1 +  __dtBusInfo[94],  __dtBusInfo[95]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.fltInK_1, work1 +  __dtBusInfo[96],  __dtBusInfo[97]);
        (void) memcpy(&__work1BUS[0].pWAcMaxPI.u16LimitFlag, work1 +  __dtBusInfo[98],  __dtBusInfo[99]);
        (void) memcpy(&__work1BUS[0].fltWAcMaxErr, work1 +  __dtBusInfo[100],  __dtBusInfo[101]);
        (void) memcpy(&__work1BUS[0].fltWDcErr2, work1 +  __dtBusInfo[102],  __dtBusInfo[103]);
        (void) memcpy(&__work1BUS[0].f32Theta, work1 +  __dtBusInfo[104],  __dtBusInfo[105]);
        (void) memcpy(&__work1BUS[0].pUDQReq.fltArg1, work1 +  __dtBusInfo[106],  __dtBusInfo[107]);
        (void) memcpy(&__work1BUS[0].pUDQReq.fltArg2, work1 +  __dtBusInfo[108],  __dtBusInfo[109]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltCC1sc, work1 +  __dtBusInfo[110],  __dtBusInfo[111]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltCC2sc, work1 +  __dtBusInfo[112],  __dtBusInfo[113]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltAcc, work1 +  __dtBusInfo[114],  __dtBusInfo[115]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltInErrK1, work1 +  __dtBusInfo[116],  __dtBusInfo[117]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltUpperLimit, work1 +  __dtBusInfo[118],  __dtBusInfo[119]);
        (void) memcpy(&__work1BUS[0].pCloopDPI.fltLowerLimit, work1 +  __dtBusInfo[120],  __dtBusInfo[121]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltCC1sc, work1 +  __dtBusInfo[122],  __dtBusInfo[123]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltCC2sc, work1 +  __dtBusInfo[124],  __dtBusInfo[125]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltAcc, work1 +  __dtBusInfo[126],  __dtBusInfo[127]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltInErrK1, work1 +  __dtBusInfo[128],  __dtBusInfo[129]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltUpperLimit, work1 +  __dtBusInfo[130],  __dtBusInfo[131]);
        (void) memcpy(&__work1BUS[0].pCloopQPI.fltLowerLimit, work1 +  __dtBusInfo[132],  __dtBusInfo[133]);
        (void) memcpy(&__work1BUS[0].pIDQReqCLoop.fltArg1, work1 +  __dtBusInfo[134],  __dtBusInfo[135]);
        (void) memcpy(&__work1BUS[0].pIDQReqCLoop.fltArg2, work1 +  __dtBusInfo[136],  __dtBusInfo[137]);
        (void) memcpy(&__work1BUS[0].pIDQFbckCLoop.fltArg1, work1 +  __dtBusInfo[138],  __dtBusInfo[139]);
        (void) memcpy(&__work1BUS[0].pIDQFbckCLoop.fltArg2, work1 +  __dtBusInfo[140],  __dtBusInfo[141]);
        (void) memcpy(&__work1BUS[0].fltThEl, work1 +  __dtBusInfo[142],  __dtBusInfo[143]);
        (void) memcpy(&__work1BUS[0].pThTransform.fltArg1, work1 +  __dtBusInfo[144],  __dtBusInfo[145]);
        (void) memcpy(&__work1BUS[0].pThTransform.fltArg2, work1 +  __dtBusInfo[146],  __dtBusInfo[147]);
        (void) memcpy(&__work1BUS[0].fltDcRaw, work1 +  __dtBusInfo[148],  __dtBusInfo[149]);
        (void) memcpy(&__work1BUS[0].pWABAcRaw.fltArg1, work1 +  __dtBusInfo[150],  __dtBusInfo[151]);
        (void) memcpy(&__work1BUS[0].pWABAcRaw.fltArg2, work1 +  __dtBusInfo[152],  __dtBusInfo[153]);
        (void) memcpy(&__work1BUS[0].pPllSinCosEst.fltArg1, work1 +  __dtBusInfo[154],  __dtBusInfo[155]);
        (void) memcpy(&__work1BUS[0].pPllSinCosEst.fltArg2, work1 +  __dtBusInfo[156],  __dtBusInfo[157]);
        (void) memcpy(&__work1BUS[0].fltDcFilt, work1 +  __dtBusInfo[158],  __dtBusInfo[159]);
        (void) memcpy(&__work1BUS[0].fltAcFilt, work1 +  __dtBusInfo[160],  __dtBusInfo[161]);
        (void) memcpy(&__work1BUS[0].fltWABEstErr, work1 +  __dtBusInfo[162],  __dtBusInfo[163]);
        (void) memcpy(&__work1BUS[0].pPllDMAFilter.fltAcc, work1 +  __dtBusInfo[164],  __dtBusInfo[165]);
        (void) memcpy(&__work1BUS[0].pPllDMAFilter.fltLambda, work1 +  __dtBusInfo[166],  __dtBusInfo[167]);
        (void) memcpy(&__work1BUS[0].pPllQMAFilter.fltAcc, work1 +  __dtBusInfo[168],  __dtBusInfo[169]);
        (void) memcpy(&__work1BUS[0].pPllQMAFilter.fltLambda, work1 +  __dtBusInfo[170],  __dtBusInfo[171]);
        (void) memcpy(&__work1BUS[0].pPllDcMAFilter.fltAcc, work1 +  __dtBusInfo[172],  __dtBusInfo[173]);
        (void) memcpy(&__work1BUS[0].pPllDcMAFilter.fltLambda, work1 +  __dtBusInfo[174],  __dtBusInfo[175]);
        (void) memcpy(&__work1BUS[0].fltPllPiPropGain, work1 +  __dtBusInfo[176],  __dtBusInfo[177]);
        (void) memcpy(&__work1BUS[0].f32ThAcEst, work1 +  __dtBusInfo[178],  __dtBusInfo[179]);
        (void) memcpy(&__work1BUS[0].f32ThAcInc, work1 +  __dtBusInfo[180],  __dtBusInfo[181]);
        (void) memcpy(&__work1BUS[0].pFluxEstim.fltRs, work1 +  __dtBusInfo[182],  __dtBusInfo[183]);
        (void) memcpy(&__work1BUS[0].pFluxEstim.fltLs, work1 +  __dtBusInfo[184],  __dtBusInfo[185]);
        (void) memcpy(&__work1BUS[0].fltLd, work1 +  __dtBusInfo[186],  __dtBusInfo[187]);
        (void) memcpy(&__work1BUS[0].fltLq, work1 +  __dtBusInfo[188],  __dtBusInfo[189]);
        (void) memcpy(&__work1BUS[0].fltWEl, work1 +  __dtBusInfo[190],  __dtBusInfo[191]);
        (void) memcpy(&__work1BUS[0].fltThErr, work1 +  __dtBusInfo[192],  __dtBusInfo[193]);
        (void) memcpy(&__work1BUS[0].fltThEstim, work1 +  __dtBusInfo[194],  __dtBusInfo[195]);
        (void) memcpy(&__work1BUS[0].fltWEstim, work1 +  __dtBusInfo[196],  __dtBusInfo[197]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltCC1sc, work1 +  __dtBusInfo[198],  __dtBusInfo[199]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltCC2sc, work1 +  __dtBusInfo[200],  __dtBusInfo[201]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltAcc, work1 +  __dtBusInfo[202],  __dtBusInfo[203]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltInErrK1, work1 +  __dtBusInfo[204],  __dtBusInfo[205]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltUpperLimit, work1 +  __dtBusInfo[206],  __dtBusInfo[207]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamPI.fltLowerLimit, work1 +  __dtBusInfo[208],  __dtBusInfo[209]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamInteg.fltState, work1 +  __dtBusInfo[210],  __dtBusInfo[211]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamInteg.fltInK1, work1 +  __dtBusInfo[212],  __dtBusInfo[213]);
        (void) memcpy(&__work1BUS[0].pTrackObsrv.pParamInteg.fltC1, work1 +  __dtBusInfo[214],  __dtBusInfo[215]);
        (void) memcpy(&__work1BUS[0].fltPsiRaw, work1 +  __dtBusInfo[216],  __dtBusInfo[217]);
        (void) memcpy(&__work1BUS[0].fltPsiFilt, work1 +  __dtBusInfo[218],  __dtBusInfo[219]);
        (void) memcpy(&__work1BUS[0].fltDtVDrop, work1 +  __dtBusInfo[220],  __dtBusInfo[221]);
        (void) memcpy(&__work1BUS[0].pFluxMAFilter.fltAcc, work1 +  __dtBusInfo[222],  __dtBusInfo[223]);
        (void) memcpy(&__work1BUS[0].pFluxMAFilter.fltLambda, work1 +  __dtBusInfo[224],  __dtBusInfo[225]);
        (void) memcpy(&__work1BUS[0].u32SSTimeoutCnt, work1 +  __dtBusInfo[226],  __dtBusInfo[227]);
        (void) memcpy(&__work1BUS[0].u32SSBandCnt, work1 +  __dtBusInfo[228],  __dtBusInfo[229]);
        (void) memcpy(&__work1BUS[0].u32SSTimeoutTime, work1 +  __dtBusInfo[230],  __dtBusInfo[231]);
        (void) memcpy(&__work1BUS[0].u32SSTime, work1 +  __dtBusInfo[232],  __dtBusInfo[233]);
        (void) memcpy(&__work1BUS[0].fltSSBandHalfMax, work1 +  __dtBusInfo[234],  __dtBusInfo[235]);
        (void) memcpy(&__work1BUS[0].fltSSBandHalf, work1 +  __dtBusInfo[236],  __dtBusInfo[237]);
        (void) memcpy(&__work1BUS[0].fltInFilt, work1 +  __dtBusInfo[238],  __dtBusInfo[239]);
        (void) memcpy(&__work1BUS[0].pSSMAFilter.fltAcc, work1 +  __dtBusInfo[240],  __dtBusInfo[241]);
        (void) memcpy(&__work1BUS[0].pSSMAFilter.fltLambda, work1 +  __dtBusInfo[242],  __dtBusInfo[243]);
        (void) memcpy(&__work1BUS[0].u16MeasNum, work1 +  __dtBusInfo[244],  __dtBusInfo[245]);
        (void) memcpy(__work1BUS[0].fltMeDcArr, work1 +  __dtBusInfo[246],  __dtBusInfo[247]);
        (void) memcpy(__work1BUS[0].fltWDcArr, work1 +  __dtBusInfo[248],  __dtBusInfo[249]);
        (void) memcpy(__work1BUS[0].fltInertiaArr, work1 +  __dtBusInfo[250],  __dtBusInfo[251]);
        (void) memcpy(&__work1BUS[0].fltWDcErr, work1 +  __dtBusInfo[252],  __dtBusInfo[253]);
        (void) memcpy(&__work1BUS[0].fltGainFOC, work1 +  __dtBusInfo[254],  __dtBusInfo[255]);
        (void) memcpy(&__work1BUS[0].fltInvGainATO, work1 +  __dtBusInfo[256],  __dtBusInfo[257]);
        (void) memcpy(&__work1BUS[0].fltPhShiftCorr, work1 +  __dtBusInfo[258],  __dtBusInfo[259]);
        (void) memcpy(&__work1BUS[0].fltKt, work1 +  __dtBusInfo[260],  __dtBusInfo[261]);
        (void) memcpy(&__work1BUS[0].fltJ, work1 +  __dtBusInfo[262],  __dtBusInfo[263]);
        (void) memcpy(&__work1BUS[0].fltA, work1 +  __dtBusInfo[264],  __dtBusInfo[265]);
        (void) memcpy(&__work1BUS[0].fltB, work1 +  __dtBusInfo[266],  __dtBusInfo[267]);

        /* Call the legacy code function */
        *y1 = AMCLIB_EstimBJ_w_FLT(__y2BUS, y3, y4, y5, y6, __u1BUS, *u2, __work1BUS);

        /* Assign the user structure __y2BUS to the Simulink structure y2 */
        (void) memcpy(y2 +  __dtBusInfo[0], &__y2BUS[0].fltArg1,  __dtBusInfo[1]);
        (void) memcpy(y2 +  __dtBusInfo[2], &__y2BUS[0].fltArg2,  __dtBusInfo[3]);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].pState,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].bTwoPointMeas,  __dtBusInfo[7]);
        (void) memcpy(work1 +  __dtBusInfo[8], &__work1BUS[0].u32AlignTimer,  __dtBusInfo[9]);
        (void) memcpy(work1 +  __dtBusInfo[10], &__work1BUS[0].u32TimerPreset,  __dtBusInfo[11]);
        (void) memcpy(work1 +  __dtBusInfo[12], &__work1BUS[0].fltIReq,  __dtBusInfo[13]);
        (void) memcpy(work1 +  __dtBusInfo[14], &__work1BUS[0].fltDCWReq1,  __dtBusInfo[15]);
        (void) memcpy(work1 +  __dtBusInfo[16], &__work1BUS[0].fltDCWReq2,  __dtBusInfo[17]);
        (void) memcpy(work1 +  __dtBusInfo[18], &__work1BUS[0].fltACWReq,  __dtBusInfo[19]);
        (void) memcpy(work1 +  __dtBusInfo[20], &__work1BUS[0].fltWMax,  __dtBusInfo[21]);
        (void) memcpy(work1 +  __dtBusInfo[22], &__work1BUS[0].fltPP,  __dtBusInfo[23]);
        (void) memcpy(work1 +  __dtBusInfo[24], &__work1BUS[0].fltWOl,  __dtBusInfo[25]);
        (void) memcpy(work1 +  __dtBusInfo[26], &__work1BUS[0].fltThOl,  __dtBusInfo[27]);
        (void) memcpy(work1 +  __dtBusInfo[28], &__work1BUS[0].pOLRamp.fltState,  __dtBusInfo[29]);
        (void) memcpy(work1 +  __dtBusInfo[30], &__work1BUS[0].pOLRamp.fltRampUp,  __dtBusInfo[31]);
        (void) memcpy(work1 +  __dtBusInfo[32], &__work1BUS[0].pOLRamp.fltRampDown,  __dtBusInfo[33]);
        (void) memcpy(work1 +  __dtBusInfo[34], &__work1BUS[0].pOLInteg.f32State,  __dtBusInfo[35]);
        (void) memcpy(work1 +  __dtBusInfo[36], &__work1BUS[0].pOLInteg.f32InK1,  __dtBusInfo[37]);
        (void) memcpy(work1 +  __dtBusInfo[38], &__work1BUS[0].pOLInteg.f32C1,  __dtBusInfo[39]);
        (void) memcpy(work1 +  __dtBusInfo[40], &__work1BUS[0].pOLInteg.u16NShift,  __dtBusInfo[41]);
        (void) memcpy(work1 +  __dtBusInfo[42], &__work1BUS[0].pIqMAFilter.fltAcc,  __dtBusInfo[43]);
        (void) memcpy(work1 +  __dtBusInfo[44], &__work1BUS[0].pIqMAFilter.fltLambda,  __dtBusInfo[45]);
        (void) memcpy(work1 +  __dtBusInfo[46], &__work1BUS[0].pThRealTransform.fltArg1,  __dtBusInfo[47]);
        (void) memcpy(work1 +  __dtBusInfo[48], &__work1BUS[0].pThRealTransform.fltArg2,  __dtBusInfo[49]);
        (void) memcpy(work1 +  __dtBusInfo[50], &__work1BUS[0].pIDQRealFbck.fltArg1,  __dtBusInfo[51]);
        (void) memcpy(work1 +  __dtBusInfo[52], &__work1BUS[0].pIDQRealFbck.fltArg2,  __dtBusInfo[53]);
        (void) memcpy(work1 +  __dtBusInfo[54], &__work1BUS[0].fltWDcReq,  __dtBusInfo[55]);
        (void) memcpy(work1 +  __dtBusInfo[56], &__work1BUS[0].fltWAcMaxReq,  __dtBusInfo[57]);
        (void) memcpy(work1 +  __dtBusInfo[58], &__work1BUS[0].fltIqDcReq,  __dtBusInfo[59]);
        (void) memcpy(work1 +  __dtBusInfo[60], &__work1BUS[0].fltIqAcReq,  __dtBusInfo[61]);
        (void) memcpy(work1 +  __dtBusInfo[62], &__work1BUS[0].fltIqAcMaxReq,  __dtBusInfo[63]);
        (void) memcpy(work1 +  __dtBusInfo[64], &__work1BUS[0].pWDcReqMAFilter.fltAcc,  __dtBusInfo[65]);
        (void) memcpy(work1 +  __dtBusInfo[66], &__work1BUS[0].pWDcReqMAFilter.fltLambda,  __dtBusInfo[67]);
        (void) memcpy(work1 +  __dtBusInfo[68], &__work1BUS[0].pWAcMaxReqMAFilter.fltAcc,  __dtBusInfo[69]);
        (void) memcpy(work1 +  __dtBusInfo[70], &__work1BUS[0].pWAcMaxReqMAFilter.fltLambda,  __dtBusInfo[71]);
        (void) memcpy(work1 +  __dtBusInfo[72], &__work1BUS[0].pWDcPI.fltPropGain,  __dtBusInfo[73]);
        (void) memcpy(work1 +  __dtBusInfo[74], &__work1BUS[0].pWDcPI.fltIntegGain,  __dtBusInfo[75]);
        (void) memcpy(work1 +  __dtBusInfo[76], &__work1BUS[0].pWDcPI.fltLowerLimit,  __dtBusInfo[77]);
        (void) memcpy(work1 +  __dtBusInfo[78], &__work1BUS[0].pWDcPI.fltUpperLimit,  __dtBusInfo[79]);
        (void) memcpy(work1 +  __dtBusInfo[80], &__work1BUS[0].pWDcPI.fltIntegPartK_1,  __dtBusInfo[81]);
        (void) memcpy(work1 +  __dtBusInfo[82], &__work1BUS[0].pWDcPI.fltInK_1,  __dtBusInfo[83]);
        (void) memcpy(work1 +  __dtBusInfo[84], &__work1BUS[0].pWDcPI.u16LimitFlag,  __dtBusInfo[85]);
        (void) memcpy(work1 +  __dtBusInfo[86], &__work1BUS[0].pWAcMaxPI.fltPropGain,  __dtBusInfo[87]);
        (void) memcpy(work1 +  __dtBusInfo[88], &__work1BUS[0].pWAcMaxPI.fltIntegGain,  __dtBusInfo[89]);
        (void) memcpy(work1 +  __dtBusInfo[90], &__work1BUS[0].pWAcMaxPI.fltLowerLimit,  __dtBusInfo[91]);
        (void) memcpy(work1 +  __dtBusInfo[92], &__work1BUS[0].pWAcMaxPI.fltUpperLimit,  __dtBusInfo[93]);
        (void) memcpy(work1 +  __dtBusInfo[94], &__work1BUS[0].pWAcMaxPI.fltIntegPartK_1,  __dtBusInfo[95]);
        (void) memcpy(work1 +  __dtBusInfo[96], &__work1BUS[0].pWAcMaxPI.fltInK_1,  __dtBusInfo[97]);
        (void) memcpy(work1 +  __dtBusInfo[98], &__work1BUS[0].pWAcMaxPI.u16LimitFlag,  __dtBusInfo[99]);
        (void) memcpy(work1 +  __dtBusInfo[100], &__work1BUS[0].fltWAcMaxErr,  __dtBusInfo[101]);
        (void) memcpy(work1 +  __dtBusInfo[102], &__work1BUS[0].fltWDcErr2,  __dtBusInfo[103]);
        (void) memcpy(work1 +  __dtBusInfo[104], &__work1BUS[0].f32Theta,  __dtBusInfo[105]);
        (void) memcpy(work1 +  __dtBusInfo[106], &__work1BUS[0].pUDQReq.fltArg1,  __dtBusInfo[107]);
        (void) memcpy(work1 +  __dtBusInfo[108], &__work1BUS[0].pUDQReq.fltArg2,  __dtBusInfo[109]);
        (void) memcpy(work1 +  __dtBusInfo[110], &__work1BUS[0].pCloopDPI.fltCC1sc,  __dtBusInfo[111]);
        (void) memcpy(work1 +  __dtBusInfo[112], &__work1BUS[0].pCloopDPI.fltCC2sc,  __dtBusInfo[113]);
        (void) memcpy(work1 +  __dtBusInfo[114], &__work1BUS[0].pCloopDPI.fltAcc,  __dtBusInfo[115]);
        (void) memcpy(work1 +  __dtBusInfo[116], &__work1BUS[0].pCloopDPI.fltInErrK1,  __dtBusInfo[117]);
        (void) memcpy(work1 +  __dtBusInfo[118], &__work1BUS[0].pCloopDPI.fltUpperLimit,  __dtBusInfo[119]);
        (void) memcpy(work1 +  __dtBusInfo[120], &__work1BUS[0].pCloopDPI.fltLowerLimit,  __dtBusInfo[121]);
        (void) memcpy(work1 +  __dtBusInfo[122], &__work1BUS[0].pCloopQPI.fltCC1sc,  __dtBusInfo[123]);
        (void) memcpy(work1 +  __dtBusInfo[124], &__work1BUS[0].pCloopQPI.fltCC2sc,  __dtBusInfo[125]);
        (void) memcpy(work1 +  __dtBusInfo[126], &__work1BUS[0].pCloopQPI.fltAcc,  __dtBusInfo[127]);
        (void) memcpy(work1 +  __dtBusInfo[128], &__work1BUS[0].pCloopQPI.fltInErrK1,  __dtBusInfo[129]);
        (void) memcpy(work1 +  __dtBusInfo[130], &__work1BUS[0].pCloopQPI.fltUpperLimit,  __dtBusInfo[131]);
        (void) memcpy(work1 +  __dtBusInfo[132], &__work1BUS[0].pCloopQPI.fltLowerLimit,  __dtBusInfo[133]);
        (void) memcpy(work1 +  __dtBusInfo[134], &__work1BUS[0].pIDQReqCLoop.fltArg1,  __dtBusInfo[135]);
        (void) memcpy(work1 +  __dtBusInfo[136], &__work1BUS[0].pIDQReqCLoop.fltArg2,  __dtBusInfo[137]);
        (void) memcpy(work1 +  __dtBusInfo[138], &__work1BUS[0].pIDQFbckCLoop.fltArg1,  __dtBusInfo[139]);
        (void) memcpy(work1 +  __dtBusInfo[140], &__work1BUS[0].pIDQFbckCLoop.fltArg2,  __dtBusInfo[141]);
        (void) memcpy(work1 +  __dtBusInfo[142], &__work1BUS[0].fltThEl,  __dtBusInfo[143]);
        (void) memcpy(work1 +  __dtBusInfo[144], &__work1BUS[0].pThTransform.fltArg1,  __dtBusInfo[145]);
        (void) memcpy(work1 +  __dtBusInfo[146], &__work1BUS[0].pThTransform.fltArg2,  __dtBusInfo[147]);
        (void) memcpy(work1 +  __dtBusInfo[148], &__work1BUS[0].fltDcRaw,  __dtBusInfo[149]);
        (void) memcpy(work1 +  __dtBusInfo[150], &__work1BUS[0].pWABAcRaw.fltArg1,  __dtBusInfo[151]);
        (void) memcpy(work1 +  __dtBusInfo[152], &__work1BUS[0].pWABAcRaw.fltArg2,  __dtBusInfo[153]);
        (void) memcpy(work1 +  __dtBusInfo[154], &__work1BUS[0].pPllSinCosEst.fltArg1,  __dtBusInfo[155]);
        (void) memcpy(work1 +  __dtBusInfo[156], &__work1BUS[0].pPllSinCosEst.fltArg2,  __dtBusInfo[157]);
        (void) memcpy(work1 +  __dtBusInfo[158], &__work1BUS[0].fltDcFilt,  __dtBusInfo[159]);
        (void) memcpy(work1 +  __dtBusInfo[160], &__work1BUS[0].fltAcFilt,  __dtBusInfo[161]);
        (void) memcpy(work1 +  __dtBusInfo[162], &__work1BUS[0].fltWABEstErr,  __dtBusInfo[163]);
        (void) memcpy(work1 +  __dtBusInfo[164], &__work1BUS[0].pPllDMAFilter.fltAcc,  __dtBusInfo[165]);
        (void) memcpy(work1 +  __dtBusInfo[166], &__work1BUS[0].pPllDMAFilter.fltLambda,  __dtBusInfo[167]);
        (void) memcpy(work1 +  __dtBusInfo[168], &__work1BUS[0].pPllQMAFilter.fltAcc,  __dtBusInfo[169]);
        (void) memcpy(work1 +  __dtBusInfo[170], &__work1BUS[0].pPllQMAFilter.fltLambda,  __dtBusInfo[171]);
        (void) memcpy(work1 +  __dtBusInfo[172], &__work1BUS[0].pPllDcMAFilter.fltAcc,  __dtBusInfo[173]);
        (void) memcpy(work1 +  __dtBusInfo[174], &__work1BUS[0].pPllDcMAFilter.fltLambda,  __dtBusInfo[175]);
        (void) memcpy(work1 +  __dtBusInfo[176], &__work1BUS[0].fltPllPiPropGain,  __dtBusInfo[177]);
        (void) memcpy(work1 +  __dtBusInfo[178], &__work1BUS[0].f32ThAcEst,  __dtBusInfo[179]);
        (void) memcpy(work1 +  __dtBusInfo[180], &__work1BUS[0].f32ThAcInc,  __dtBusInfo[181]);
        (void) memcpy(work1 +  __dtBusInfo[182], &__work1BUS[0].pFluxEstim.fltRs,  __dtBusInfo[183]);
        (void) memcpy(work1 +  __dtBusInfo[184], &__work1BUS[0].pFluxEstim.fltLs,  __dtBusInfo[185]);
        (void) memcpy(work1 +  __dtBusInfo[186], &__work1BUS[0].fltLd,  __dtBusInfo[187]);
        (void) memcpy(work1 +  __dtBusInfo[188], &__work1BUS[0].fltLq,  __dtBusInfo[189]);
        (void) memcpy(work1 +  __dtBusInfo[190], &__work1BUS[0].fltWEl,  __dtBusInfo[191]);
        (void) memcpy(work1 +  __dtBusInfo[192], &__work1BUS[0].fltThErr,  __dtBusInfo[193]);
        (void) memcpy(work1 +  __dtBusInfo[194], &__work1BUS[0].fltThEstim,  __dtBusInfo[195]);
        (void) memcpy(work1 +  __dtBusInfo[196], &__work1BUS[0].fltWEstim,  __dtBusInfo[197]);
        (void) memcpy(work1 +  __dtBusInfo[198], &__work1BUS[0].pTrackObsrv.pParamPI.fltCC1sc,  __dtBusInfo[199]);
        (void) memcpy(work1 +  __dtBusInfo[200], &__work1BUS[0].pTrackObsrv.pParamPI.fltCC2sc,  __dtBusInfo[201]);
        (void) memcpy(work1 +  __dtBusInfo[202], &__work1BUS[0].pTrackObsrv.pParamPI.fltAcc,  __dtBusInfo[203]);
        (void) memcpy(work1 +  __dtBusInfo[204], &__work1BUS[0].pTrackObsrv.pParamPI.fltInErrK1,  __dtBusInfo[205]);
        (void) memcpy(work1 +  __dtBusInfo[206], &__work1BUS[0].pTrackObsrv.pParamPI.fltUpperLimit,  __dtBusInfo[207]);
        (void) memcpy(work1 +  __dtBusInfo[208], &__work1BUS[0].pTrackObsrv.pParamPI.fltLowerLimit,  __dtBusInfo[209]);
        (void) memcpy(work1 +  __dtBusInfo[210], &__work1BUS[0].pTrackObsrv.pParamInteg.fltState,  __dtBusInfo[211]);
        (void) memcpy(work1 +  __dtBusInfo[212], &__work1BUS[0].pTrackObsrv.pParamInteg.fltInK1,  __dtBusInfo[213]);
        (void) memcpy(work1 +  __dtBusInfo[214], &__work1BUS[0].pTrackObsrv.pParamInteg.fltC1,  __dtBusInfo[215]);
        (void) memcpy(work1 +  __dtBusInfo[216], &__work1BUS[0].fltPsiRaw,  __dtBusInfo[217]);
        (void) memcpy(work1 +  __dtBusInfo[218], &__work1BUS[0].fltPsiFilt,  __dtBusInfo[219]);
        (void) memcpy(work1 +  __dtBusInfo[220], &__work1BUS[0].fltDtVDrop,  __dtBusInfo[221]);
        (void) memcpy(work1 +  __dtBusInfo[222], &__work1BUS[0].pFluxMAFilter.fltAcc,  __dtBusInfo[223]);
        (void) memcpy(work1 +  __dtBusInfo[224], &__work1BUS[0].pFluxMAFilter.fltLambda,  __dtBusInfo[225]);
        (void) memcpy(work1 +  __dtBusInfo[226], &__work1BUS[0].u32SSTimeoutCnt,  __dtBusInfo[227]);
        (void) memcpy(work1 +  __dtBusInfo[228], &__work1BUS[0].u32SSBandCnt,  __dtBusInfo[229]);
        (void) memcpy(work1 +  __dtBusInfo[230], &__work1BUS[0].u32SSTimeoutTime,  __dtBusInfo[231]);
        (void) memcpy(work1 +  __dtBusInfo[232], &__work1BUS[0].u32SSTime,  __dtBusInfo[233]);
        (void) memcpy(work1 +  __dtBusInfo[234], &__work1BUS[0].fltSSBandHalfMax,  __dtBusInfo[235]);
        (void) memcpy(work1 +  __dtBusInfo[236], &__work1BUS[0].fltSSBandHalf,  __dtBusInfo[237]);
        (void) memcpy(work1 +  __dtBusInfo[238], &__work1BUS[0].fltInFilt,  __dtBusInfo[239]);
        (void) memcpy(work1 +  __dtBusInfo[240], &__work1BUS[0].pSSMAFilter.fltAcc,  __dtBusInfo[241]);
        (void) memcpy(work1 +  __dtBusInfo[242], &__work1BUS[0].pSSMAFilter.fltLambda,  __dtBusInfo[243]);
        (void) memcpy(work1 +  __dtBusInfo[244], &__work1BUS[0].u16MeasNum,  __dtBusInfo[245]);
        (void) memcpy(work1 +  __dtBusInfo[246], __work1BUS[0].fltMeDcArr,  __dtBusInfo[247]);
        (void) memcpy(work1 +  __dtBusInfo[248], __work1BUS[0].fltWDcArr,  __dtBusInfo[249]);
        (void) memcpy(work1 +  __dtBusInfo[250], __work1BUS[0].fltInertiaArr,  __dtBusInfo[251]);
        (void) memcpy(work1 +  __dtBusInfo[252], &__work1BUS[0].fltWDcErr,  __dtBusInfo[253]);
        (void) memcpy(work1 +  __dtBusInfo[254], &__work1BUS[0].fltGainFOC,  __dtBusInfo[255]);
        (void) memcpy(work1 +  __dtBusInfo[256], &__work1BUS[0].fltInvGainATO,  __dtBusInfo[257]);
        (void) memcpy(work1 +  __dtBusInfo[258], &__work1BUS[0].fltPhShiftCorr,  __dtBusInfo[259]);
        (void) memcpy(work1 +  __dtBusInfo[260], &__work1BUS[0].fltKt,  __dtBusInfo[261]);
        (void) memcpy(work1 +  __dtBusInfo[262], &__work1BUS[0].fltJ,  __dtBusInfo[263]);
        (void) memcpy(work1 +  __dtBusInfo[264], &__work1BUS[0].fltA,  __dtBusInfo[265]);
        (void) memcpy(work1 +  __dtBusInfo[266], &__work1BUS[0].fltB,  __dtBusInfo[267]);
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
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 1);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 2);


        /* Free memory for the pwork 1 (__y2BUS) */
        {
            SWLIBS_2Syst_FLT* __y2BUS = (SWLIBS_2Syst_FLT*)ssGetPWorkValue(S, 0);
            if (__y2BUS!=NULL) {
                free(__y2BUS);
                ssSetPWorkValue(S, 0, NULL);
            } /* if */
        }

        /* Free memory for the pwork 2 (__u1BUS) */
        {
            SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*)ssGetPWorkValue(S, 1);
            if (__u1BUS!=NULL) {
                free(__u1BUS);
                ssSetPWorkValue(S, 1, NULL);
            } /* if */
        }

        /* Free memory for the pwork 3 (__work1BUS) */
        {
            AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT* __work1BUS = (AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT*)ssGetPWorkValue(S, 2);
            if (__work1BUS!=NULL) {
                free(__work1BUS);
                ssSetPWorkValue(S, 2, NULL);
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

    /* Verify Enumerated Type 'AMCLIB_ESTIMBJ_RET_T' specification */
    {
        uint32_T chk[] = {1257722262, 1317676545, 1071610836, 736097264};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_ESTIMBJ_RET_T", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Enumerated type 'AMCLIB_ESTIMBJ_RET_T'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Enumerated type 'AMCLIB_ESTIMBJ_RET_T' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'SWLIBS_2Syst_FLT', specification */
    {
        uint32_T chk[] = {1910970754, 866280756, 1155391210, 492100123};
        int_T status;
        status = CheckDataTypeChecksum(S, "SWLIBS_2Syst_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'SWLIBS_2Syst_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'SWLIBS_2Syst_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT', specification */
    {
        uint32_T chk[] = {3901901878, 4028070029, 980429687, 2314631813};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_RAMP_T_FLT', specification */
    {
        uint32_T chk[] = {2764681142, 1036667672, 1090823954, 2059373002};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_RAMP_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_RAMP_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_RAMP_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_INTEGRATOR_TR_T_F32', specification */
    {
        uint32_T chk[] = {2252501790, 3199583997, 3951228551, 1550748748};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_INTEGRATOR_TR_T_F32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_INTEGRATOR_TR_T_F32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_INTEGRATOR_TR_T_F32' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GDFLIB_FILTER_MA_T_FLT', specification */
    {
        uint32_T chk[] = {632753118, 3494441743, 2076841188, 725156089};
        int_T status;
        status = CheckDataTypeChecksum(S, "GDFLIB_FILTER_MA_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GDFLIB_FILTER_MA_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GDFLIB_FILTER_MA_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_CONTROLLER_PIAW_P_T_FLT', specification */
    {
        uint32_T chk[] = {1746609610, 338858303, 532619239, 2586278313};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_CONTROLLER_PIAW_P_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_CONTROLLER_PIAW_P_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_CONTROLLER_PIAW_P_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_CONTROLLER_PIAW_R_T_FLT', specification */
    {
        uint32_T chk[] = {1134103077, 708184969, 200444125, 813311757};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_CONTROLLER_PIAW_R_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_CONTROLLER_PIAW_R_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_CONTROLLER_PIAW_R_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'AMCLIB_FLUXESTIMAB_T_FLT', specification */
    {
        uint32_T chk[] = {3106990860, 1145893148, 4092595363, 1350050941};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_FLUXESTIMAB_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'AMCLIB_FLUXESTIMAB_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'AMCLIB_FLUXESTIMAB_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'AMCLIB_TRACK_OBSRV_T_FLT', specification */
    {
        uint32_T chk[] = {320775342, 3729480857, 3870288394, 3195411923};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_TRACK_OBSRV_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'AMCLIB_TRACK_OBSRV_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'AMCLIB_TRACK_OBSRV_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'GFLIB_INTEGRATOR_TR_T_FLT', specification */
    {
        uint32_T chk[] = {1680389040, 1616532443, 1481721023, 1581628045};
        int_T status;
        status = CheckDataTypeChecksum(S, "GFLIB_INTEGRATOR_TR_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GFLIB_INTEGRATOR_TR_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GFLIB_INTEGRATOR_TR_T_FLT' definition has changed since the S-Function was generated");
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

