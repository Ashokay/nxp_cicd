/**
 * AMCLIB_FluxEstimAB_SF_F32.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         int32 y1 = AMCLIB_FluxEstimAB_w_F32(int32 u1, SWLIBS_2Syst_F32 u2[1], SWLIBS_2Syst_F32 u3[1], int32 u4, int32 u5, uint16 u6, int32 p1, AMCLIB_FLUXESTIMAB_T_F32 work1[1])
 *
 *    Simulink version           : 9.3 (R2019a) 23-Nov-2018
 *    C source code generated on : 12-Sep-2023 09:21:58
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
#define S_FUNCTION_NAME  AMCLIB_FluxEstimAB_SF_F32
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
#include "AMCLIB_FluxEstimAB_w.h"
#include "gflib.h"

/* Specific header file(s) required for data types declarations */
#include "SWLIBS_Typedefs.h"
#include "AMCLIB_FluxEstimAB.h"

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
    ssSetNumSFcnParams(S, 11);

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
        ssSetDWorkWidth(S, 1, 4);
        ssSetDWorkComplexSignal(S, 1, COMPLEX_NO);

        /* Configure the dwork 3 (__dtBusInfo) */
        ssSetDWorkDataType(S, 2, SS_INT32);
        ssSetDWorkUsageType(S, 2, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 2, "dtBusInfo");
        ssSetDWorkWidth(S, 2, 10);
        ssSetDWorkComplexSignal(S, 2, COMPLEX_NO);
    } /* if */

    /* Configure the dwork 1 (work1) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "AMCLIB_FLUXESTIMAB_T_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 0, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 0, "work1");
    ssSetDWorkWidth(S, 0, 1);
    ssSetDWorkComplexSignal(S, 0, COMPLEX_NO);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 6)) return;

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
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "SWLIBS_2Syst_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetInputPortDataType(S, 1, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusInputAsStruct(S, 1, 1);
    {
        int_T u2Width = 1;
        ssSetInputPortWidth(S, 1, u2Width);
    }
    ssSetInputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortAcceptExprInRTW(S, 1, 0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 1, 1);

    /* Configure the input port 3 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "SWLIBS_2Syst_F32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetInputPortDataType(S, 2, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusInputAsStruct(S, 2, 1);
    {
        int_T u3Width = 1;
        ssSetInputPortWidth(S, 2, u3Width);
    }
    ssSetInputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortAcceptExprInRTW(S, 2, 0);
    ssSetInputPortOverWritable(S, 2, 0);
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

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 1)) return;

    /* Configure the output port 1 */
    ssSetOutputPortDataType(S, 0, SS_INT32);
    {
        int_T y1Width = 1;
        ssSetOutputPortWidth(S, 0, y1Width);
    }
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 0, 1);

    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_FluxEstimABInit_w_F32", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_FluxEstimAB_w_F32", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for wrappers */
        if (isSimulationTarget) {

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_FluxEstimABInit_w_F32_wrapper_InitializeConditions", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_FluxEstimAB_w_F32_wrapper_Output", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for allocating PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_FluxEstimAB_SF_F32_wrapper_allocmem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for freeing PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_FluxEstimAB_SF_F32_wrapper_freemem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
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
    if (!ssSetNumRunTimeParams(S, 11)) return;

    /* Register the run-time parameter 1 */
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "p1", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 2 */
    ssRegDlgParamAsRunTimeParam(S, 1, 1, "p2", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 3 */
    ssRegDlgParamAsRunTimeParam(S, 2, 2, "p3", ssGetDataTypeId(S, "int32"));

    /* Register the run-time parameter 4 */
    ssRegDlgParamAsRunTimeParam(S, 3, 3, "p4", ssGetDataTypeId(S, "uint16"));

    /* Register the run-time parameter 5 */
    ssRegDlgParamAsRunTimeParam(S, 4, 4, "p5", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 6 */
    ssRegDlgParamAsRunTimeParam(S, 5, 5, "p6", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 7 */
    ssRegDlgParamAsRunTimeParam(S, 6, 6, "p7", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 8 */
    ssRegDlgParamAsRunTimeParam(S, 7, 7, "p8", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 9 */
    ssRegDlgParamAsRunTimeParam(S, 8, 8, "p9", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 10 */
    ssRegDlgParamAsRunTimeParam(S, 9, 9, "p10", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 11 */
    ssRegDlgParamAsRunTimeParam(S, 10, 10, "p11", ssGetDataTypeId(S, "int32"));
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
        DTypeId __SWLIBS_2Syst_F32Id = ssGetDataTypeId(S, "SWLIBS_2Syst_F32");
        DTypeId __int32Id = ssGetDataTypeId(S, "int32");
        DTypeId __AMCLIB_FLUXESTIMAB_T_F32Id = ssGetDataTypeId(S, "AMCLIB_FLUXESTIMAB_T_F32");
        DTypeId __uint16Id = ssGetDataTypeId(S, "uint16");

        /* Get common data type size */
        __dtSizeInfo[0] = ssGetDataTypeSize(S, __SWLIBS_2Syst_F32Id);
        __dtSizeInfo[1] = ssGetDataTypeSize(S, __int32Id);
        __dtSizeInfo[2] = ssGetDataTypeSize(S, __AMCLIB_FLUXESTIMAB_T_F32Id);
        __dtSizeInfo[3] = ssGetDataTypeSize(S, __uint16Id);

        /* Get information for accessing SWLIBS_2Syst_F32.f32Arg1 */
        __dtBusInfo[0] = ssGetBusElementOffset(S, __SWLIBS_2Syst_F32Id, 0);
        __dtBusInfo[1] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_2Syst_F32.f32Arg2 */
        __dtBusInfo[2] = ssGetBusElementOffset(S, __SWLIBS_2Syst_F32Id, 1);
        __dtBusInfo[3] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_FLUXESTIMAB_T_F32.f32KRs */
        __dtBusInfo[4] = ssGetBusElementOffset(S, __AMCLIB_FLUXESTIMAB_T_F32Id, 0);
        __dtBusInfo[5] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_FLUXESTIMAB_T_F32.f32KLs */
        __dtBusInfo[6] = ssGetBusElementOffset(S, __AMCLIB_FLUXESTIMAB_T_F32Id, 1);
        __dtBusInfo[7] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_FLUXESTIMAB_T_F32.u16NShift */
        __dtBusInfo[8] = ssGetBusElementOffset(S, __AMCLIB_FLUXESTIMAB_T_F32Id, 2);
        __dtBusInfo[9] = __dtSizeInfo[3];


        /* Alloc memory for the pwork 1 (__u2BUS) */
        {
            SWLIBS_2Syst_F32* __u2BUS = (SWLIBS_2Syst_F32*)calloc(sizeof(SWLIBS_2Syst_F32), ssGetInputPortWidth(S, 1));
            if (__u2BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __u2BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 0, __u2BUS);
        }

        /* Alloc memory for the pwork 2 (__u3BUS) */
        {
            SWLIBS_2Syst_F32* __u3BUS = (SWLIBS_2Syst_F32*)calloc(sizeof(SWLIBS_2Syst_F32), ssGetInputPortWidth(S, 2));
            if (__u3BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __u3BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 1, __u3BUS);
        }

        /* Alloc memory for the pwork 3 (__work1BUS) */
        {
            AMCLIB_FLUXESTIMAB_T_F32* __work1BUS = (AMCLIB_FLUXESTIMAB_T_F32*)calloc(sizeof(AMCLIB_FLUXESTIMAB_T_F32), ssGetDWorkWidth(S, 0));
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
        double wmax;
        double Rssc;
        double Lssc;
        double u16NShift_tmp;
        double u16NShift_tmp2;
        double f32KRs_tmp;
        double f32KLs_tmp;

        /* Access bus/struct information */
        int32_T* __dtSizeInfo = (int32_T*) ssGetDWork(S, 1);
        int32_T* __dtBusInfo = (int32_T*) ssGetDWork(S, 2);


        /* Get access to Parameter/Input/Output/DWork data */
        int32_T* p2 = (int32_T*) ssGetRunTimeParamInfo(S, 1)->data;
        int32_T* p3 = (int32_T*) ssGetRunTimeParamInfo(S, 2)->data;
        uint16_T* p4 = (uint16_T*) ssGetRunTimeParamInfo(S, 3)->data;
        char* work1 = (char*) ssGetDWork(S, 0);
        real_T* p5 = (real_T*) ssGetRunTimeParamInfo(S, 4)->data;
        real_T* p6 = (real_T*) ssGetRunTimeParamInfo(S, 5)->data;
        real_T* p7 = (real_T*) ssGetRunTimeParamInfo(S, 6)->data;
        real_T* p8 = (real_T*) ssGetRunTimeParamInfo(S, 7)->data;
        real_T* p9 = (real_T*) ssGetRunTimeParamInfo(S, 8)->data;
        real_T* p10 = (real_T*) ssGetRunTimeParamInfo(S, 9)->data;
        int32_T* p11 = (int32_T*) ssGetRunTimeParamInfo(S, 10)->data;

        AMCLIB_FLUXESTIMAB_T_F32* __work1BUS = (AMCLIB_FLUXESTIMAB_T_F32*) ssGetPWorkValue(S, 2);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].f32KRs, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].f32KLs, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);
        (void) memcpy(&__work1BUS[0].u16NShift, work1 +  __dtBusInfo[8],  __dtBusInfo[9]);

        /* Call the legacy code function */
        if((*p11) == 1) {
          wmax=(*p8)*(*p7)*1.047197551196598e-01;
          Rssc=(*p5)*(*p10)/(*p9);
          Lssc=(*p6)*wmax*(*p10)/(*p9);
          u16NShift_tmp=ceil(M_LOG2E*log(fabs((double)Rssc)));
          u16NShift_tmp2=ceil(M_LOG2E*log(fabs((double)Lssc)));
          if(u16NShift_tmp<u16NShift_tmp2) {
            u16NShift_tmp=u16NShift_tmp2;
          }
          if(u16NShift_tmp<0) {
            u16NShift_tmp=0;
          }
          if(u16NShift_tmp>31) {
            u16NShift_tmp=31;
          }
          *p4=(uint16_T)u16NShift_tmp;
          f32KRs_tmp=Rssc*2147483648.0/(double)(1UL << (*p4));
          if(f32KRs_tmp>2147483647.0) {
            f32KRs_tmp=2147483647.0;
          }
          if(f32KRs_tmp<-2147483648.0) {
            f32KRs_tmp=-2147483648.0;
          }
          *p2=(int32_T)f32KRs_tmp;
          f32KLs_tmp=Lssc*2147483648.0/(double)(1UL << (*p4));
          if(f32KLs_tmp>2147483647.0) {
            f32KLs_tmp=2147483647.0;
          }
          if(f32KLs_tmp<-2147483648.0) {
            f32KLs_tmp=-2147483648.0;
          }
          *p3=(int32_T)f32KLs_tmp;
        }
        AMCLIB_FluxEstimABInit_w_F32(*p2, *p3, *p4, __work1BUS, *p5, *p6, *p7, *p8, *p9, *p10, *p11);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].f32KRs,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].f32KLs,  __dtBusInfo[7]);
        (void) memcpy(work1 +  __dtBusInfo[8], &__work1BUS[0].u16NShift,  __dtBusInfo[9]);
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
        int32_T* y1 = (int32_T*) ssGetOutputPortSignal(S, 0);
        int32_T* u1 = (int32_T*) ssGetInputPortSignal(S, 0);
        char* u2 = (char*) ssGetInputPortSignal(S, 1);
        char* u3 = (char*) ssGetInputPortSignal(S, 2);
        int32_T* u4 = (int32_T*) ssGetInputPortSignal(S, 3);
        int32_T* u5 = (int32_T*) ssGetInputPortSignal(S, 4);
        uint16_T* u6 = (uint16_T*) ssGetInputPortSignal(S, 5);
        int32_T* p1 = (int32_T*) ssGetRunTimeParamInfo(S, 0)->data;
        char* work1 = (char*) ssGetDWork(S, 0);

        SWLIBS_2Syst_F32* __u2BUS = (SWLIBS_2Syst_F32*) ssGetPWorkValue(S, 0);
        SWLIBS_2Syst_F32* __u3BUS = (SWLIBS_2Syst_F32*) ssGetPWorkValue(S, 1);
        AMCLIB_FLUXESTIMAB_T_F32* __work1BUS = (AMCLIB_FLUXESTIMAB_T_F32*) ssGetPWorkValue(S, 2);

        /* Assign the Simulink structure u2 to user structure __u2BUS */
        (void) memcpy(&__u2BUS[0].f32Arg1, u2 +  __dtBusInfo[0],  __dtBusInfo[1]);
        (void) memcpy(&__u2BUS[0].f32Arg2, u2 +  __dtBusInfo[2],  __dtBusInfo[3]);

        /* Assign the Simulink structure u3 to user structure __u3BUS */
        (void) memcpy(&__u3BUS[0].f32Arg1, u3 +  __dtBusInfo[0],  __dtBusInfo[1]);
        (void) memcpy(&__u3BUS[0].f32Arg2, u3 +  __dtBusInfo[2],  __dtBusInfo[3]);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].f32KRs, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].f32KLs, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);
        (void) memcpy(&__work1BUS[0].u16NShift, work1 +  __dtBusInfo[8],  __dtBusInfo[9]);

        /* Call the legacy code function */
        *y1 = AMCLIB_FluxEstimAB_w_F32(*u1, __u2BUS, __u3BUS, *u4, *u5, *u6, *p1, __work1BUS);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].f32KRs,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].f32KLs,  __dtBusInfo[7]);
        (void) memcpy(work1 +  __dtBusInfo[8], &__work1BUS[0].u16NShift,  __dtBusInfo[9]);
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


        /* Free memory for the pwork 1 (__u2BUS) */
        {
            SWLIBS_2Syst_F32* __u2BUS = (SWLIBS_2Syst_F32*)ssGetPWorkValue(S, 0);
            if (__u2BUS!=NULL) {
                free(__u2BUS);
                ssSetPWorkValue(S, 0, NULL);
            } /* if */
        }

        /* Free memory for the pwork 2 (__u3BUS) */
        {
            SWLIBS_2Syst_F32* __u3BUS = (SWLIBS_2Syst_F32*)ssGetPWorkValue(S, 1);
            if (__u3BUS!=NULL) {
                free(__u3BUS);
                ssSetPWorkValue(S, 1, NULL);
            } /* if */
        }

        /* Free memory for the pwork 3 (__work1BUS) */
        {
            AMCLIB_FLUXESTIMAB_T_F32* __work1BUS = (AMCLIB_FLUXESTIMAB_T_F32*)ssGetPWorkValue(S, 2);
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

    /* Verify Bus/StructType 'AMCLIB_FLUXESTIMAB_T_F32', specification */
    {
        uint32_T chk[] = {713996352, 57711206, 4125609314, 36012768};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_FLUXESTIMAB_T_F32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'AMCLIB_FLUXESTIMAB_T_F32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'AMCLIB_FLUXESTIMAB_T_F32' definition has changed since the S-Function was generated");
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

