/**
 * AMCLIB_EstimRL_SF_FLT.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         AMCLIB_ESTIMRL_RET_T y1 = AMCLIB_EstimRL_w_FLT(SWLIBS_2Syst_FLT y2[1], single y3[1], single y4[1], single y5[1], single y6[1], single y7[3][p3+1], SWLIBS_2Syst_FLT u1[1], single u2, AMCLIB_ESTIMRL_T_FLT work1[1], single u3, single u4, single u5, uint16 u6, uint8 u7, uint16 p3, int32 p7)
 *
 *    Simulink version           : 9.3 (R2019a) 23-Nov-2018
 *    C source code generated on : 12-Sep-2023 09:22:32
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
#define S_FUNCTION_NAME  AMCLIB_EstimRL_SF_FLT
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
#include "AMCLIB_EstimRL_w.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"

/* Specific header file(s) required for data types declarations */
#include "SWLIBS_Typedefs.h"
#include "AMCLIB_EstimRL.h"
#include "GDFLIB_FilterMA.h"

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

        /* Parameter 3 must be numeric */
        if (!mxIsNumeric(ssGetSFcnParam(S, 2))) {
            ssSetErrorStatus(S,"Parameter 3 must be numeric");
            return;
        } /* if */

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
    ssSetNumSFcnParams(S, 7);

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
    ssSetSFcnParamTunable(S, 2, 0);
    ssSetSFcnParamTunable(S, 3, 1);
    ssSetSFcnParamTunable(S, 4, 1);
    ssSetSFcnParamTunable(S, 5, 1);
    ssSetSFcnParamTunable(S, 6, 1);

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
        ssSetDWorkWidth(S, 1, 10);
        ssSetDWorkComplexSignal(S, 1, COMPLEX_NO);

        /* Configure the dwork 3 (__dtBusInfo) */
        ssSetDWorkDataType(S, 2, SS_INT32);
        ssSetDWorkUsageType(S, 2, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 2, "dtBusInfo");
        ssSetDWorkWidth(S, 2, 180);
        ssSetDWorkComplexSignal(S, 2, COMPLEX_NO);
    } /* if */

    /* Configure the dwork 1 (work1) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "AMCLIB_ESTIMRL_T_FLT", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 0, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 0, "work1");
    ssSetDWorkWidth(S, 0, 1);
    ssSetDWorkComplexSignal(S, 0, COMPLEX_NO);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 7)) return;

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

    /* Configure the input port 3 */
    ssSetInputPortDataType(S, 2, SS_SINGLE);
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
    ssSetInputPortDataType(S, 3, SS_SINGLE);
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
    ssSetInputPortDataType(S, 4, SS_SINGLE);
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
    ssSetInputPortDataType(S, 6, SS_UINT8);
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

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 7)) return;

    /* Configure the output port 1 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "AMCLIB_ESTIMRL_RET_T", &dataTypeIdReg);
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

    /* Configure the output port 7 */
    ssSetOutputPortDataType(S, 6, SS_SINGLE);
    {
        int_T y7NumRows = 3;
        int_T y7NumCols = (int_T)mxGetScalar(ssGetSFcnParam(S, 2))+1;
        if (y7NumCols!=DYNAMICALLY_SIZED && y7NumCols < 1) { ssSetErrorStatus(S, "Output 7: the current number of columns is < 1"); return; }
        ssSetOutputPortMatrixDimensions(S, 6, y7NumRows, y7NumCols);
    }
    ssSetOutputPortComplexSignal(S, 6, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 6, 0);

    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_EstimRLInit_w_FLT", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "AMCLIB_EstimRL_w_FLT", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for wrappers */
        if (isSimulationTarget) {

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_EstimRLInit_w_FLT_wrapper_InitializeConditions", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "AMCLIB_EstimRL_w_FLT_wrapper_Output", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for allocating PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_EstimRL_SF_FLT_wrapper_allocmem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for freeing PWork for SimulationTarget */
            ssRegMdlInfo(S, "AMCLIB_EstimRL_SF_FLT_wrapper_freemem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
        } /* if */
    } /* if */

    /* This S-function can be used in referenced model simulating in normal mode */
    ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

    /* Set the number of sample time */
    ssSetNumSampleTimes(S, 1);

    /* Set the compliance for the operating point save/restore. */
    ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);

    ssSetArrayLayoutForCodeGen(S, SS_COLUMN_MAJOR);

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
    if (!ssSetNumRunTimeParams(S, 7)) return;

    /* Register the run-time parameter 1 */
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "p1", ssGetDataTypeId(S, "uint32"));

    /* Register the run-time parameter 2 */
    ssRegDlgParamAsRunTimeParam(S, 1, 1, "p2", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 3 */
    ssRegDlgParamAsRunTimeParam(S, 2, 2, "p3", ssGetDataTypeId(S, "uint16"));

    /* Register the run-time parameter 4 */
    ssRegDlgParamAsRunTimeParam(S, 3, 3, "p4", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 5 */
    ssRegDlgParamAsRunTimeParam(S, 4, 4, "p5", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 6 */
    ssRegDlgParamAsRunTimeParam(S, 5, 5, "p6", ssGetDataTypeId(S, "single"));

    /* Register the run-time parameter 7 */
    ssRegDlgParamAsRunTimeParam(S, 6, 6, "p7", ssGetDataTypeId(S, "int32"));
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
        DTypeId __AMCLIB_ESTIMRL_T_FLTId = ssGetDataTypeId(S, "AMCLIB_ESTIMRL_T_FLT");
        DTypeId __AMCLIB_ESTIMRL_INNERST_T_FLTId = ssGetDataTypeId(S, "AMCLIB_ESTIMRL_INNERST_T_FLT");
        DTypeId __AMCLIB_ESTIMRL_STATE_TId = ssGetDataTypeId(S, "AMCLIB_ESTIMRL_STATE_T");
        DTypeId __int32Id = ssGetDataTypeId(S, "int32");
        DTypeId __GDFLIB_FILTER_MA_T_FLTId = ssGetDataTypeId(S, "GDFLIB_FILTER_MA_T_FLT");
        DTypeId __uint32Id = ssGetDataTypeId(S, "uint32");
        DTypeId __uint16Id = ssGetDataTypeId(S, "uint16");
        DTypeId __uint8Id = ssGetDataTypeId(S, "uint8");

        /* Get common data type size */
        __dtSizeInfo[0] = ssGetDataTypeSize(S, __SWLIBS_2Syst_FLTId);
        __dtSizeInfo[1] = ssGetDataTypeSize(S, __singleId);
        __dtSizeInfo[2] = ssGetDataTypeSize(S, __AMCLIB_ESTIMRL_T_FLTId);
        __dtSizeInfo[3] = ssGetDataTypeSize(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId);
        __dtSizeInfo[4] = ssGetDataTypeSize(S, __AMCLIB_ESTIMRL_STATE_TId);
        __dtSizeInfo[5] = ssGetDataTypeSize(S, __int32Id);
        __dtSizeInfo[6] = ssGetDataTypeSize(S, __GDFLIB_FILTER_MA_T_FLTId);
        __dtSizeInfo[7] = ssGetDataTypeSize(S, __uint32Id);
        __dtSizeInfo[8] = ssGetDataTypeSize(S, __uint16Id);
        __dtSizeInfo[9] = ssGetDataTypeSize(S, __uint8Id);

        /* Get information for accessing SWLIBS_2Syst_FLT.fltArg1 */
        __dtBusInfo[0] = ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[1] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_2Syst_FLT.fltArg2 */
        __dtBusInfo[2] = ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[3] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.fltLd */
        __dtBusInfo[4] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 0);
        __dtBusInfo[5] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.fltLq */
        __dtBusInfo[6] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 1);
        __dtBusInfo[7] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.fltR */
        __dtBusInfo[8] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 2);
        __dtBusInfo[9] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.fltUdt */
        __dtBusInfo[10] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 3);
        __dtBusInfo[11] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pState */
        __dtBusInfo[12] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 0);
        __dtBusInfo[13] = __dtSizeInfo[4];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.f32FAc */
        __dtBusInfo[14] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 1);
        __dtBusInfo[15] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcMax */
        __dtBusInfo[16] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 2);
        __dtBusInfo[17] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcNegMax */
        __dtBusInfo[18] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 3);
        __dtBusInfo[19] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcMaxInv */
        __dtBusInfo[20] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 4);
        __dtBusInfo[21] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIAcReq */
        __dtBusInfo[22] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 5);
        __dtBusInfo[23] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIAcReqInv */
        __dtBusInfo[24] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 6);
        __dtBusInfo[25] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcDReq */
        __dtBusInfo[26] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 7);
        __dtBusInfo[27] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcDReqk_1 */
        __dtBusInfo[28] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 8);
        __dtBusInfo[29] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcQReq */
        __dtBusInfo[30] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 9);
        __dtBusInfo[31] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcQReqk_1 */
        __dtBusInfo[32] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 10);
        __dtBusInfo[33] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcReqStep */
        __dtBusInfo[34] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 11);
        __dtBusInfo[35] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIAlBeEstErr */
        __dtBusInfo[36] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 12);
        __dtBusInfo[37] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pIAlBeAc.fltArg1 */
        __dtBusInfo[38] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 13) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[39] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pIAlBeAc.fltArg2 */
        __dtBusInfo[40] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 13) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[41] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pSinCosEst.fltArg1 */
        __dtBusInfo[42] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 14) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[43] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pSinCosEst.fltArg2 */
        __dtBusInfo[44] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 14) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[45] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pIDQAcRaw.fltArg1 */
        __dtBusInfo[46] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 15) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[47] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pIDQAcRaw.fltArg2 */
        __dtBusInfo[48] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 15) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[49] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pIDQAcFilt.fltArg1 */
        __dtBusInfo[50] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 16) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[51] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pIDQAcFilt.fltArg2 */
        __dtBusInfo[52] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 16) + ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[53] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pDAxisFilter.fltAcc */
        __dtBusInfo[54] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 17) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[55] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pDAxisFilter.fltLambda */
        __dtBusInfo[56] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 17) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[57] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pQAxisFilter.fltAcc */
        __dtBusInfo[58] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 18) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[59] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pQAxisFilter.fltLambda */
        __dtBusInfo[60] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 18) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[61] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pDcFilter.fltAcc */
        __dtBusInfo[62] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 19) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[63] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pDcFilter.fltLambda */
        __dtBusInfo[64] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 19) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[65] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pStdFilter.fltAcc */
        __dtBusInfo[66] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 20) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 0);
        __dtBusInfo[67] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.pStdFilter.fltLambda */
        __dtBusInfo[68] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 20) + ssGetBusElementOffset(S, __GDFLIB_FILTER_MA_T_FLTId, 1);
        __dtBusInfo[69] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltPLLPropGain */
        __dtBusInfo[70] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 21);
        __dtBusInfo[71] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.f32ThAc */
        __dtBusInfo[72] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 22);
        __dtBusInfo[73] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.f32ThEst */
        __dtBusInfo[74] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 23);
        __dtBusInfo[75] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcD */
        __dtBusInfo[76] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 24);
        __dtBusInfo[77] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcQ */
        __dtBusInfo[78] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 25);
        __dtBusInfo[79] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcDAvg */
        __dtBusInfo[80] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 26);
        __dtBusInfo[81] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcDAvgk_1 */
        __dtBusInfo[82] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 27);
        __dtBusInfo[83] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltPhComp */
        __dtBusInfo[84] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 28);
        __dtBusInfo[85] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.s32ConvDetState */
        __dtBusInfo[86] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 29);
        __dtBusInfo[87] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.s32ConvDetStateLimL */
        __dtBusInfo[88] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 30);
        __dtBusInfo[89] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.s32ConvDetStateLimH */
        __dtBusInfo[90] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 31);
        __dtBusInfo[91] = __dtSizeInfo[5];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u32ConvDetToutCnt */
        __dtBusInfo[92] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 32);
        __dtBusInfo[93] = __dtSizeInfo[7];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u32ConvDetToutReload */
        __dtBusInfo[94] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 33);
        __dtBusInfo[95] = __dtSizeInfo[7];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u32AvgCnt */
        __dtBusInfo[96] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 34);
        __dtBusInfo[97] = __dtSizeInfo[7];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u32AvgN */
        __dtBusInfo[98] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 35);
        __dtBusInfo[99] = __dtSizeInfo[7];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltAvgNInv */
        __dtBusInfo[100] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 36);
        __dtBusInfo[101] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltAvgNInvMaxDelta */
        __dtBusInfo[102] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 37);
        __dtBusInfo[103] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u32AvgCntMax */
        __dtBusInfo[104] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 38);
        __dtBusInfo[105] = __dtSizeInfo[7];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltPhAvg */
        __dtBusInfo[106] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 39);
        __dtBusInfo[107] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIAcAvg */
        __dtBusInfo[108] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 40);
        __dtBusInfo[109] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUAcAvg */
        __dtBusInfo[110] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 41);
        __dtBusInfo[111] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltAvgMul */
        __dtBusInfo[112] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 42);
        __dtBusInfo[113] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltAvgMin */
        __dtBusInfo[114] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 43);
        __dtBusInfo[115] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u16LdqNumMeas */
        __dtBusInfo[116] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 44);
        __dtBusInfo[117] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u32TblCounter */
        __dtBusInfo[118] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 45);
        __dtBusInfo[119] = __dtSizeInfo[7];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u8RotorFixed */
        __dtBusInfo[120] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 46);
        __dtBusInfo[121] = __dtSizeInfo[9];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcRampCoef */
        __dtBusInfo[122] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 47);
        __dtBusInfo[123] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcRampCoefMax */
        __dtBusInfo[124] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 48);
        __dtBusInfo[125] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcDRampAcc */
        __dtBusInfo[126] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 49);
        __dtBusInfo[127] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcQRampAcc */
        __dtBusInfo[128] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 50);
        __dtBusInfo[129] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcDAcc */
        __dtBusInfo[130] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 51);
        __dtBusInfo[131] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcDAccAvg */
        __dtBusInfo[132] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 52);
        __dtBusInfo[133] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcDAccAvgk_1 */
        __dtBusInfo[134] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 53);
        __dtBusInfo[135] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcQAcc */
        __dtBusInfo[136] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 54);
        __dtBusInfo[137] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUAcAcc */
        __dtBusInfo[138] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 55);
        __dtBusInfo[139] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcKi */
        __dtBusInfo[140] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 56);
        __dtBusInfo[141] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUAcKi */
        __dtBusInfo[142] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 57);
        __dtBusInfo[143] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcKiNominal */
        __dtBusInfo[144] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 58);
        __dtBusInfo[145] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUAcKiNominal */
        __dtBusInfo[146] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 59);
        __dtBusInfo[147] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u16RampSteady */
        __dtBusInfo[148] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 60);
        __dtBusInfo[149] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u16DcbLimitFlag */
        __dtBusInfo[150] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 61);
        __dtBusInfo[151] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u16DcbLimitFlagk_1 */
        __dtBusInfo[152] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 62);
        __dtBusInfo[153] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u16DcbLimitCnt */
        __dtBusInfo[154] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 63);
        __dtBusInfo[155] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltPhaseShift */
        __dtBusInfo[156] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 64);
        __dtBusInfo[157] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUdcHalf */
        __dtBusInfo[158] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 65);
        __dtBusInfo[159] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltFsInv */
        __dtBusInfo[160] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 66);
        __dtBusInfo[161] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltImpConst */
        __dtBusInfo[162] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 67);
        __dtBusInfo[163] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltLdk_1 */
        __dtBusInfo[164] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 68);
        __dtBusInfo[165] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltLqk_1 */
        __dtBusInfo[166] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 69);
        __dtBusInfo[167] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcLd */
        __dtBusInfo[168] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 70);
        __dtBusInfo[169] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltIDcLq */
        __dtBusInfo[170] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 71);
        __dtBusInfo[171] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUdtAcc */
        __dtBusInfo[172] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 72);
        __dtBusInfo[173] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltRAcc */
        __dtBusInfo[174] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 73);
        __dtBusInfo[175] = __dtSizeInfo[1];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.u16LdqNumMeasR */
        __dtBusInfo[176] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 74);
        __dtBusInfo[177] = __dtSizeInfo[8];

        /* Get information for accessing AMCLIB_ESTIMRL_T_FLT.pInnerState.fltUDcBusMax */
        __dtBusInfo[178] = ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_T_FLTId, 4) + ssGetBusElementOffset(S, __AMCLIB_ESTIMRL_INNERST_T_FLTId, 75);
        __dtBusInfo[179] = __dtSizeInfo[1];


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
            AMCLIB_ESTIMRL_T_FLT* __work1BUS = (AMCLIB_ESTIMRL_T_FLT*)calloc(sizeof(AMCLIB_ESTIMRL_T_FLT), ssGetDWorkWidth(S, 0));
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
        uint32_T* p1 = (uint32_T*) ssGetRunTimeParamInfo(S, 0)->data;
        char* work1 = (char*) ssGetDWork(S, 0);
        real32_T* p2 = (real32_T*) ssGetRunTimeParamInfo(S, 1)->data;
        uint16_T* p3 = (uint16_T*) ssGetRunTimeParamInfo(S, 2)->data;
        real32_T* p4 = (real32_T*) ssGetRunTimeParamInfo(S, 3)->data;
        real32_T* p5 = (real32_T*) ssGetRunTimeParamInfo(S, 4)->data;
        real32_T* p6 = (real32_T*) ssGetRunTimeParamInfo(S, 5)->data;
        int32_T* p7 = (int32_T*) ssGetRunTimeParamInfo(S, 6)->data;

        AMCLIB_ESTIMRL_T_FLT* __work1BUS = (AMCLIB_ESTIMRL_T_FLT*) ssGetPWorkValue(S, 2);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].fltLd, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].fltLq, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);
        (void) memcpy(&__work1BUS[0].fltR, work1 +  __dtBusInfo[8],  __dtBusInfo[9]);
        (void) memcpy(&__work1BUS[0].fltUdt, work1 +  __dtBusInfo[10],  __dtBusInfo[11]);
        (void) memcpy(&__work1BUS[0].pInnerState.pState, work1 +  __dtBusInfo[12],  __dtBusInfo[13]);
        (void) memcpy(&__work1BUS[0].pInnerState.f32FAc, work1 +  __dtBusInfo[14],  __dtBusInfo[15]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcMax, work1 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcNegMax, work1 +  __dtBusInfo[18],  __dtBusInfo[19]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcMaxInv, work1 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAcReq, work1 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAcReqInv, work1 +  __dtBusInfo[24],  __dtBusInfo[25]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDReq, work1 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDReqk_1, work1 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQReq, work1 +  __dtBusInfo[30],  __dtBusInfo[31]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQReqk_1, work1 +  __dtBusInfo[32],  __dtBusInfo[33]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcReqStep, work1 +  __dtBusInfo[34],  __dtBusInfo[35]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAlBeEstErr, work1 +  __dtBusInfo[36],  __dtBusInfo[37]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIAlBeAc.fltArg1, work1 +  __dtBusInfo[38],  __dtBusInfo[39]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIAlBeAc.fltArg2, work1 +  __dtBusInfo[40],  __dtBusInfo[41]);
        (void) memcpy(&__work1BUS[0].pInnerState.pSinCosEst.fltArg1, work1 +  __dtBusInfo[42],  __dtBusInfo[43]);
        (void) memcpy(&__work1BUS[0].pInnerState.pSinCosEst.fltArg2, work1 +  __dtBusInfo[44],  __dtBusInfo[45]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcRaw.fltArg1, work1 +  __dtBusInfo[46],  __dtBusInfo[47]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcRaw.fltArg2, work1 +  __dtBusInfo[48],  __dtBusInfo[49]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcFilt.fltArg1, work1 +  __dtBusInfo[50],  __dtBusInfo[51]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcFilt.fltArg2, work1 +  __dtBusInfo[52],  __dtBusInfo[53]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDAxisFilter.fltAcc, work1 +  __dtBusInfo[54],  __dtBusInfo[55]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDAxisFilter.fltLambda, work1 +  __dtBusInfo[56],  __dtBusInfo[57]);
        (void) memcpy(&__work1BUS[0].pInnerState.pQAxisFilter.fltAcc, work1 +  __dtBusInfo[58],  __dtBusInfo[59]);
        (void) memcpy(&__work1BUS[0].pInnerState.pQAxisFilter.fltLambda, work1 +  __dtBusInfo[60],  __dtBusInfo[61]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDcFilter.fltAcc, work1 +  __dtBusInfo[62],  __dtBusInfo[63]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDcFilter.fltLambda, work1 +  __dtBusInfo[64],  __dtBusInfo[65]);
        (void) memcpy(&__work1BUS[0].pInnerState.pStdFilter.fltAcc, work1 +  __dtBusInfo[66],  __dtBusInfo[67]);
        (void) memcpy(&__work1BUS[0].pInnerState.pStdFilter.fltLambda, work1 +  __dtBusInfo[68],  __dtBusInfo[69]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPLLPropGain, work1 +  __dtBusInfo[70],  __dtBusInfo[71]);
        (void) memcpy(&__work1BUS[0].pInnerState.f32ThAc, work1 +  __dtBusInfo[72],  __dtBusInfo[73]);
        (void) memcpy(&__work1BUS[0].pInnerState.f32ThEst, work1 +  __dtBusInfo[74],  __dtBusInfo[75]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcD, work1 +  __dtBusInfo[76],  __dtBusInfo[77]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQ, work1 +  __dtBusInfo[78],  __dtBusInfo[79]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDAvg, work1 +  __dtBusInfo[80],  __dtBusInfo[81]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDAvgk_1, work1 +  __dtBusInfo[82],  __dtBusInfo[83]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPhComp, work1 +  __dtBusInfo[84],  __dtBusInfo[85]);
        (void) memcpy(&__work1BUS[0].pInnerState.s32ConvDetState, work1 +  __dtBusInfo[86],  __dtBusInfo[87]);
        (void) memcpy(&__work1BUS[0].pInnerState.s32ConvDetStateLimL, work1 +  __dtBusInfo[88],  __dtBusInfo[89]);
        (void) memcpy(&__work1BUS[0].pInnerState.s32ConvDetStateLimH, work1 +  __dtBusInfo[90],  __dtBusInfo[91]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32ConvDetToutCnt, work1 +  __dtBusInfo[92],  __dtBusInfo[93]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32ConvDetToutReload, work1 +  __dtBusInfo[94],  __dtBusInfo[95]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32AvgCnt, work1 +  __dtBusInfo[96],  __dtBusInfo[97]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32AvgN, work1 +  __dtBusInfo[98],  __dtBusInfo[99]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgNInv, work1 +  __dtBusInfo[100],  __dtBusInfo[101]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgNInvMaxDelta, work1 +  __dtBusInfo[102],  __dtBusInfo[103]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32AvgCntMax, work1 +  __dtBusInfo[104],  __dtBusInfo[105]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPhAvg, work1 +  __dtBusInfo[106],  __dtBusInfo[107]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAcAvg, work1 +  __dtBusInfo[108],  __dtBusInfo[109]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcAvg, work1 +  __dtBusInfo[110],  __dtBusInfo[111]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgMul, work1 +  __dtBusInfo[112],  __dtBusInfo[113]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgMin, work1 +  __dtBusInfo[114],  __dtBusInfo[115]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16LdqNumMeas, work1 +  __dtBusInfo[116],  __dtBusInfo[117]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32TblCounter, work1 +  __dtBusInfo[118],  __dtBusInfo[119]);
        (void) memcpy(&__work1BUS[0].pInnerState.u8RotorFixed, work1 +  __dtBusInfo[120],  __dtBusInfo[121]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcRampCoef, work1 +  __dtBusInfo[122],  __dtBusInfo[123]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcRampCoefMax, work1 +  __dtBusInfo[124],  __dtBusInfo[125]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDRampAcc, work1 +  __dtBusInfo[126],  __dtBusInfo[127]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQRampAcc, work1 +  __dtBusInfo[128],  __dtBusInfo[129]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcDAcc, work1 +  __dtBusInfo[130],  __dtBusInfo[131]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcDAccAvg, work1 +  __dtBusInfo[132],  __dtBusInfo[133]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcDAccAvgk_1, work1 +  __dtBusInfo[134],  __dtBusInfo[135]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcQAcc, work1 +  __dtBusInfo[136],  __dtBusInfo[137]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcAcc, work1 +  __dtBusInfo[138],  __dtBusInfo[139]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcKi, work1 +  __dtBusInfo[140],  __dtBusInfo[141]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcKi, work1 +  __dtBusInfo[142],  __dtBusInfo[143]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcKiNominal, work1 +  __dtBusInfo[144],  __dtBusInfo[145]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcKiNominal, work1 +  __dtBusInfo[146],  __dtBusInfo[147]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16RampSteady, work1 +  __dtBusInfo[148],  __dtBusInfo[149]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16DcbLimitFlag, work1 +  __dtBusInfo[150],  __dtBusInfo[151]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16DcbLimitFlagk_1, work1 +  __dtBusInfo[152],  __dtBusInfo[153]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16DcbLimitCnt, work1 +  __dtBusInfo[154],  __dtBusInfo[155]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPhaseShift, work1 +  __dtBusInfo[156],  __dtBusInfo[157]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUdcHalf, work1 +  __dtBusInfo[158],  __dtBusInfo[159]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltFsInv, work1 +  __dtBusInfo[160],  __dtBusInfo[161]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltImpConst, work1 +  __dtBusInfo[162],  __dtBusInfo[163]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltLdk_1, work1 +  __dtBusInfo[164],  __dtBusInfo[165]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltLqk_1, work1 +  __dtBusInfo[166],  __dtBusInfo[167]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcLd, work1 +  __dtBusInfo[168],  __dtBusInfo[169]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcLq, work1 +  __dtBusInfo[170],  __dtBusInfo[171]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUdtAcc, work1 +  __dtBusInfo[172],  __dtBusInfo[173]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltRAcc, work1 +  __dtBusInfo[174],  __dtBusInfo[175]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16LdqNumMeasR, work1 +  __dtBusInfo[176],  __dtBusInfo[177]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcBusMax, work1 +  __dtBusInfo[178],  __dtBusInfo[179]);

        /* Call the legacy code function */
        AMCLIB_EstimRLInit_w_FLT(*p1, __work1BUS, *p2, *p3, *p4, *p5, *p6, *p7);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].fltLd,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].fltLq,  __dtBusInfo[7]);
        (void) memcpy(work1 +  __dtBusInfo[8], &__work1BUS[0].fltR,  __dtBusInfo[9]);
        (void) memcpy(work1 +  __dtBusInfo[10], &__work1BUS[0].fltUdt,  __dtBusInfo[11]);
        (void) memcpy(work1 +  __dtBusInfo[12], &__work1BUS[0].pInnerState.pState,  __dtBusInfo[13]);
        (void) memcpy(work1 +  __dtBusInfo[14], &__work1BUS[0].pInnerState.f32FAc,  __dtBusInfo[15]);
        (void) memcpy(work1 +  __dtBusInfo[16], &__work1BUS[0].pInnerState.fltIDcMax,  __dtBusInfo[17]);
        (void) memcpy(work1 +  __dtBusInfo[18], &__work1BUS[0].pInnerState.fltIDcNegMax,  __dtBusInfo[19]);
        (void) memcpy(work1 +  __dtBusInfo[20], &__work1BUS[0].pInnerState.fltIDcMaxInv,  __dtBusInfo[21]);
        (void) memcpy(work1 +  __dtBusInfo[22], &__work1BUS[0].pInnerState.fltIAcReq,  __dtBusInfo[23]);
        (void) memcpy(work1 +  __dtBusInfo[24], &__work1BUS[0].pInnerState.fltIAcReqInv,  __dtBusInfo[25]);
        (void) memcpy(work1 +  __dtBusInfo[26], &__work1BUS[0].pInnerState.fltIDcDReq,  __dtBusInfo[27]);
        (void) memcpy(work1 +  __dtBusInfo[28], &__work1BUS[0].pInnerState.fltIDcDReqk_1,  __dtBusInfo[29]);
        (void) memcpy(work1 +  __dtBusInfo[30], &__work1BUS[0].pInnerState.fltIDcQReq,  __dtBusInfo[31]);
        (void) memcpy(work1 +  __dtBusInfo[32], &__work1BUS[0].pInnerState.fltIDcQReqk_1,  __dtBusInfo[33]);
        (void) memcpy(work1 +  __dtBusInfo[34], &__work1BUS[0].pInnerState.fltIDcReqStep,  __dtBusInfo[35]);
        (void) memcpy(work1 +  __dtBusInfo[36], &__work1BUS[0].pInnerState.fltIAlBeEstErr,  __dtBusInfo[37]);
        (void) memcpy(work1 +  __dtBusInfo[38], &__work1BUS[0].pInnerState.pIAlBeAc.fltArg1,  __dtBusInfo[39]);
        (void) memcpy(work1 +  __dtBusInfo[40], &__work1BUS[0].pInnerState.pIAlBeAc.fltArg2,  __dtBusInfo[41]);
        (void) memcpy(work1 +  __dtBusInfo[42], &__work1BUS[0].pInnerState.pSinCosEst.fltArg1,  __dtBusInfo[43]);
        (void) memcpy(work1 +  __dtBusInfo[44], &__work1BUS[0].pInnerState.pSinCosEst.fltArg2,  __dtBusInfo[45]);
        (void) memcpy(work1 +  __dtBusInfo[46], &__work1BUS[0].pInnerState.pIDQAcRaw.fltArg1,  __dtBusInfo[47]);
        (void) memcpy(work1 +  __dtBusInfo[48], &__work1BUS[0].pInnerState.pIDQAcRaw.fltArg2,  __dtBusInfo[49]);
        (void) memcpy(work1 +  __dtBusInfo[50], &__work1BUS[0].pInnerState.pIDQAcFilt.fltArg1,  __dtBusInfo[51]);
        (void) memcpy(work1 +  __dtBusInfo[52], &__work1BUS[0].pInnerState.pIDQAcFilt.fltArg2,  __dtBusInfo[53]);
        (void) memcpy(work1 +  __dtBusInfo[54], &__work1BUS[0].pInnerState.pDAxisFilter.fltAcc,  __dtBusInfo[55]);
        (void) memcpy(work1 +  __dtBusInfo[56], &__work1BUS[0].pInnerState.pDAxisFilter.fltLambda,  __dtBusInfo[57]);
        (void) memcpy(work1 +  __dtBusInfo[58], &__work1BUS[0].pInnerState.pQAxisFilter.fltAcc,  __dtBusInfo[59]);
        (void) memcpy(work1 +  __dtBusInfo[60], &__work1BUS[0].pInnerState.pQAxisFilter.fltLambda,  __dtBusInfo[61]);
        (void) memcpy(work1 +  __dtBusInfo[62], &__work1BUS[0].pInnerState.pDcFilter.fltAcc,  __dtBusInfo[63]);
        (void) memcpy(work1 +  __dtBusInfo[64], &__work1BUS[0].pInnerState.pDcFilter.fltLambda,  __dtBusInfo[65]);
        (void) memcpy(work1 +  __dtBusInfo[66], &__work1BUS[0].pInnerState.pStdFilter.fltAcc,  __dtBusInfo[67]);
        (void) memcpy(work1 +  __dtBusInfo[68], &__work1BUS[0].pInnerState.pStdFilter.fltLambda,  __dtBusInfo[69]);
        (void) memcpy(work1 +  __dtBusInfo[70], &__work1BUS[0].pInnerState.fltPLLPropGain,  __dtBusInfo[71]);
        (void) memcpy(work1 +  __dtBusInfo[72], &__work1BUS[0].pInnerState.f32ThAc,  __dtBusInfo[73]);
        (void) memcpy(work1 +  __dtBusInfo[74], &__work1BUS[0].pInnerState.f32ThEst,  __dtBusInfo[75]);
        (void) memcpy(work1 +  __dtBusInfo[76], &__work1BUS[0].pInnerState.fltIDcD,  __dtBusInfo[77]);
        (void) memcpy(work1 +  __dtBusInfo[78], &__work1BUS[0].pInnerState.fltIDcQ,  __dtBusInfo[79]);
        (void) memcpy(work1 +  __dtBusInfo[80], &__work1BUS[0].pInnerState.fltIDcDAvg,  __dtBusInfo[81]);
        (void) memcpy(work1 +  __dtBusInfo[82], &__work1BUS[0].pInnerState.fltIDcDAvgk_1,  __dtBusInfo[83]);
        (void) memcpy(work1 +  __dtBusInfo[84], &__work1BUS[0].pInnerState.fltPhComp,  __dtBusInfo[85]);
        (void) memcpy(work1 +  __dtBusInfo[86], &__work1BUS[0].pInnerState.s32ConvDetState,  __dtBusInfo[87]);
        (void) memcpy(work1 +  __dtBusInfo[88], &__work1BUS[0].pInnerState.s32ConvDetStateLimL,  __dtBusInfo[89]);
        (void) memcpy(work1 +  __dtBusInfo[90], &__work1BUS[0].pInnerState.s32ConvDetStateLimH,  __dtBusInfo[91]);
        (void) memcpy(work1 +  __dtBusInfo[92], &__work1BUS[0].pInnerState.u32ConvDetToutCnt,  __dtBusInfo[93]);
        (void) memcpy(work1 +  __dtBusInfo[94], &__work1BUS[0].pInnerState.u32ConvDetToutReload,  __dtBusInfo[95]);
        (void) memcpy(work1 +  __dtBusInfo[96], &__work1BUS[0].pInnerState.u32AvgCnt,  __dtBusInfo[97]);
        (void) memcpy(work1 +  __dtBusInfo[98], &__work1BUS[0].pInnerState.u32AvgN,  __dtBusInfo[99]);
        (void) memcpy(work1 +  __dtBusInfo[100], &__work1BUS[0].pInnerState.fltAvgNInv,  __dtBusInfo[101]);
        (void) memcpy(work1 +  __dtBusInfo[102], &__work1BUS[0].pInnerState.fltAvgNInvMaxDelta,  __dtBusInfo[103]);
        (void) memcpy(work1 +  __dtBusInfo[104], &__work1BUS[0].pInnerState.u32AvgCntMax,  __dtBusInfo[105]);
        (void) memcpy(work1 +  __dtBusInfo[106], &__work1BUS[0].pInnerState.fltPhAvg,  __dtBusInfo[107]);
        (void) memcpy(work1 +  __dtBusInfo[108], &__work1BUS[0].pInnerState.fltIAcAvg,  __dtBusInfo[109]);
        (void) memcpy(work1 +  __dtBusInfo[110], &__work1BUS[0].pInnerState.fltUAcAvg,  __dtBusInfo[111]);
        (void) memcpy(work1 +  __dtBusInfo[112], &__work1BUS[0].pInnerState.fltAvgMul,  __dtBusInfo[113]);
        (void) memcpy(work1 +  __dtBusInfo[114], &__work1BUS[0].pInnerState.fltAvgMin,  __dtBusInfo[115]);
        (void) memcpy(work1 +  __dtBusInfo[116], &__work1BUS[0].pInnerState.u16LdqNumMeas,  __dtBusInfo[117]);
        (void) memcpy(work1 +  __dtBusInfo[118], &__work1BUS[0].pInnerState.u32TblCounter,  __dtBusInfo[119]);
        (void) memcpy(work1 +  __dtBusInfo[120], &__work1BUS[0].pInnerState.u8RotorFixed,  __dtBusInfo[121]);
        (void) memcpy(work1 +  __dtBusInfo[122], &__work1BUS[0].pInnerState.fltIDcRampCoef,  __dtBusInfo[123]);
        (void) memcpy(work1 +  __dtBusInfo[124], &__work1BUS[0].pInnerState.fltIDcRampCoefMax,  __dtBusInfo[125]);
        (void) memcpy(work1 +  __dtBusInfo[126], &__work1BUS[0].pInnerState.fltIDcDRampAcc,  __dtBusInfo[127]);
        (void) memcpy(work1 +  __dtBusInfo[128], &__work1BUS[0].pInnerState.fltIDcQRampAcc,  __dtBusInfo[129]);
        (void) memcpy(work1 +  __dtBusInfo[130], &__work1BUS[0].pInnerState.fltUDcDAcc,  __dtBusInfo[131]);
        (void) memcpy(work1 +  __dtBusInfo[132], &__work1BUS[0].pInnerState.fltUDcDAccAvg,  __dtBusInfo[133]);
        (void) memcpy(work1 +  __dtBusInfo[134], &__work1BUS[0].pInnerState.fltUDcDAccAvgk_1,  __dtBusInfo[135]);
        (void) memcpy(work1 +  __dtBusInfo[136], &__work1BUS[0].pInnerState.fltUDcQAcc,  __dtBusInfo[137]);
        (void) memcpy(work1 +  __dtBusInfo[138], &__work1BUS[0].pInnerState.fltUAcAcc,  __dtBusInfo[139]);
        (void) memcpy(work1 +  __dtBusInfo[140], &__work1BUS[0].pInnerState.fltUDcKi,  __dtBusInfo[141]);
        (void) memcpy(work1 +  __dtBusInfo[142], &__work1BUS[0].pInnerState.fltUAcKi,  __dtBusInfo[143]);
        (void) memcpy(work1 +  __dtBusInfo[144], &__work1BUS[0].pInnerState.fltUDcKiNominal,  __dtBusInfo[145]);
        (void) memcpy(work1 +  __dtBusInfo[146], &__work1BUS[0].pInnerState.fltUAcKiNominal,  __dtBusInfo[147]);
        (void) memcpy(work1 +  __dtBusInfo[148], &__work1BUS[0].pInnerState.u16RampSteady,  __dtBusInfo[149]);
        (void) memcpy(work1 +  __dtBusInfo[150], &__work1BUS[0].pInnerState.u16DcbLimitFlag,  __dtBusInfo[151]);
        (void) memcpy(work1 +  __dtBusInfo[152], &__work1BUS[0].pInnerState.u16DcbLimitFlagk_1,  __dtBusInfo[153]);
        (void) memcpy(work1 +  __dtBusInfo[154], &__work1BUS[0].pInnerState.u16DcbLimitCnt,  __dtBusInfo[155]);
        (void) memcpy(work1 +  __dtBusInfo[156], &__work1BUS[0].pInnerState.fltPhaseShift,  __dtBusInfo[157]);
        (void) memcpy(work1 +  __dtBusInfo[158], &__work1BUS[0].pInnerState.fltUdcHalf,  __dtBusInfo[159]);
        (void) memcpy(work1 +  __dtBusInfo[160], &__work1BUS[0].pInnerState.fltFsInv,  __dtBusInfo[161]);
        (void) memcpy(work1 +  __dtBusInfo[162], &__work1BUS[0].pInnerState.fltImpConst,  __dtBusInfo[163]);
        (void) memcpy(work1 +  __dtBusInfo[164], &__work1BUS[0].pInnerState.fltLdk_1,  __dtBusInfo[165]);
        (void) memcpy(work1 +  __dtBusInfo[166], &__work1BUS[0].pInnerState.fltLqk_1,  __dtBusInfo[167]);
        (void) memcpy(work1 +  __dtBusInfo[168], &__work1BUS[0].pInnerState.fltIDcLd,  __dtBusInfo[169]);
        (void) memcpy(work1 +  __dtBusInfo[170], &__work1BUS[0].pInnerState.fltIDcLq,  __dtBusInfo[171]);
        (void) memcpy(work1 +  __dtBusInfo[172], &__work1BUS[0].pInnerState.fltUdtAcc,  __dtBusInfo[173]);
        (void) memcpy(work1 +  __dtBusInfo[174], &__work1BUS[0].pInnerState.fltRAcc,  __dtBusInfo[175]);
        (void) memcpy(work1 +  __dtBusInfo[176], &__work1BUS[0].pInnerState.u16LdqNumMeasR,  __dtBusInfo[177]);
        (void) memcpy(work1 +  __dtBusInfo[178], &__work1BUS[0].pInnerState.fltUDcBusMax,  __dtBusInfo[179]);
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
        AMCLIB_ESTIMRL_RET_T* y1 = (AMCLIB_ESTIMRL_RET_T*) ssGetOutputPortSignal(S, 0);
        char* y2 = (char*) ssGetOutputPortSignal(S, 1);
        real32_T* y3 = (real32_T*) ssGetOutputPortSignal(S, 2);
        real32_T* y4 = (real32_T*) ssGetOutputPortSignal(S, 3);
        real32_T* y5 = (real32_T*) ssGetOutputPortSignal(S, 4);
        real32_T* y6 = (real32_T*) ssGetOutputPortSignal(S, 5);
        real32_T* y7 = (real32_T*) ssGetOutputPortSignal(S, 6);
        char* u1 = (char*) ssGetInputPortSignal(S, 0);
        real32_T* u2 = (real32_T*) ssGetInputPortSignal(S, 1);
        char* work1 = (char*) ssGetDWork(S, 0);
        real32_T* u3 = (real32_T*) ssGetInputPortSignal(S, 2);
        real32_T* u4 = (real32_T*) ssGetInputPortSignal(S, 3);
        real32_T* u5 = (real32_T*) ssGetInputPortSignal(S, 4);
        uint16_T* u6 = (uint16_T*) ssGetInputPortSignal(S, 5);
        uint8_T* u7 = (uint8_T*) ssGetInputPortSignal(S, 6);
        uint16_T* p3 = (uint16_T*) ssGetRunTimeParamInfo(S, 2)->data;
        int32_T* p7 = (int32_T*) ssGetRunTimeParamInfo(S, 6)->data;

        SWLIBS_2Syst_FLT* __y2BUS = (SWLIBS_2Syst_FLT*) ssGetPWorkValue(S, 0);
        SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*) ssGetPWorkValue(S, 1);
        AMCLIB_ESTIMRL_T_FLT* __work1BUS = (AMCLIB_ESTIMRL_T_FLT*) ssGetPWorkValue(S, 2);

        /* Assign the Simulink structure u1 to user structure __u1BUS */
        (void) memcpy(&__u1BUS[0].fltArg1, u1 +  __dtBusInfo[0],  __dtBusInfo[1]);
        (void) memcpy(&__u1BUS[0].fltArg2, u1 +  __dtBusInfo[2],  __dtBusInfo[3]);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].fltLd, work1 +  __dtBusInfo[4],  __dtBusInfo[5]);
        (void) memcpy(&__work1BUS[0].fltLq, work1 +  __dtBusInfo[6],  __dtBusInfo[7]);
        (void) memcpy(&__work1BUS[0].fltR, work1 +  __dtBusInfo[8],  __dtBusInfo[9]);
        (void) memcpy(&__work1BUS[0].fltUdt, work1 +  __dtBusInfo[10],  __dtBusInfo[11]);
        (void) memcpy(&__work1BUS[0].pInnerState.pState, work1 +  __dtBusInfo[12],  __dtBusInfo[13]);
        (void) memcpy(&__work1BUS[0].pInnerState.f32FAc, work1 +  __dtBusInfo[14],  __dtBusInfo[15]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcMax, work1 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcNegMax, work1 +  __dtBusInfo[18],  __dtBusInfo[19]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcMaxInv, work1 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAcReq, work1 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAcReqInv, work1 +  __dtBusInfo[24],  __dtBusInfo[25]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDReq, work1 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDReqk_1, work1 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQReq, work1 +  __dtBusInfo[30],  __dtBusInfo[31]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQReqk_1, work1 +  __dtBusInfo[32],  __dtBusInfo[33]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcReqStep, work1 +  __dtBusInfo[34],  __dtBusInfo[35]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAlBeEstErr, work1 +  __dtBusInfo[36],  __dtBusInfo[37]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIAlBeAc.fltArg1, work1 +  __dtBusInfo[38],  __dtBusInfo[39]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIAlBeAc.fltArg2, work1 +  __dtBusInfo[40],  __dtBusInfo[41]);
        (void) memcpy(&__work1BUS[0].pInnerState.pSinCosEst.fltArg1, work1 +  __dtBusInfo[42],  __dtBusInfo[43]);
        (void) memcpy(&__work1BUS[0].pInnerState.pSinCosEst.fltArg2, work1 +  __dtBusInfo[44],  __dtBusInfo[45]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcRaw.fltArg1, work1 +  __dtBusInfo[46],  __dtBusInfo[47]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcRaw.fltArg2, work1 +  __dtBusInfo[48],  __dtBusInfo[49]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcFilt.fltArg1, work1 +  __dtBusInfo[50],  __dtBusInfo[51]);
        (void) memcpy(&__work1BUS[0].pInnerState.pIDQAcFilt.fltArg2, work1 +  __dtBusInfo[52],  __dtBusInfo[53]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDAxisFilter.fltAcc, work1 +  __dtBusInfo[54],  __dtBusInfo[55]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDAxisFilter.fltLambda, work1 +  __dtBusInfo[56],  __dtBusInfo[57]);
        (void) memcpy(&__work1BUS[0].pInnerState.pQAxisFilter.fltAcc, work1 +  __dtBusInfo[58],  __dtBusInfo[59]);
        (void) memcpy(&__work1BUS[0].pInnerState.pQAxisFilter.fltLambda, work1 +  __dtBusInfo[60],  __dtBusInfo[61]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDcFilter.fltAcc, work1 +  __dtBusInfo[62],  __dtBusInfo[63]);
        (void) memcpy(&__work1BUS[0].pInnerState.pDcFilter.fltLambda, work1 +  __dtBusInfo[64],  __dtBusInfo[65]);
        (void) memcpy(&__work1BUS[0].pInnerState.pStdFilter.fltAcc, work1 +  __dtBusInfo[66],  __dtBusInfo[67]);
        (void) memcpy(&__work1BUS[0].pInnerState.pStdFilter.fltLambda, work1 +  __dtBusInfo[68],  __dtBusInfo[69]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPLLPropGain, work1 +  __dtBusInfo[70],  __dtBusInfo[71]);
        (void) memcpy(&__work1BUS[0].pInnerState.f32ThAc, work1 +  __dtBusInfo[72],  __dtBusInfo[73]);
        (void) memcpy(&__work1BUS[0].pInnerState.f32ThEst, work1 +  __dtBusInfo[74],  __dtBusInfo[75]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcD, work1 +  __dtBusInfo[76],  __dtBusInfo[77]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQ, work1 +  __dtBusInfo[78],  __dtBusInfo[79]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDAvg, work1 +  __dtBusInfo[80],  __dtBusInfo[81]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDAvgk_1, work1 +  __dtBusInfo[82],  __dtBusInfo[83]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPhComp, work1 +  __dtBusInfo[84],  __dtBusInfo[85]);
        (void) memcpy(&__work1BUS[0].pInnerState.s32ConvDetState, work1 +  __dtBusInfo[86],  __dtBusInfo[87]);
        (void) memcpy(&__work1BUS[0].pInnerState.s32ConvDetStateLimL, work1 +  __dtBusInfo[88],  __dtBusInfo[89]);
        (void) memcpy(&__work1BUS[0].pInnerState.s32ConvDetStateLimH, work1 +  __dtBusInfo[90],  __dtBusInfo[91]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32ConvDetToutCnt, work1 +  __dtBusInfo[92],  __dtBusInfo[93]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32ConvDetToutReload, work1 +  __dtBusInfo[94],  __dtBusInfo[95]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32AvgCnt, work1 +  __dtBusInfo[96],  __dtBusInfo[97]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32AvgN, work1 +  __dtBusInfo[98],  __dtBusInfo[99]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgNInv, work1 +  __dtBusInfo[100],  __dtBusInfo[101]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgNInvMaxDelta, work1 +  __dtBusInfo[102],  __dtBusInfo[103]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32AvgCntMax, work1 +  __dtBusInfo[104],  __dtBusInfo[105]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPhAvg, work1 +  __dtBusInfo[106],  __dtBusInfo[107]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIAcAvg, work1 +  __dtBusInfo[108],  __dtBusInfo[109]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcAvg, work1 +  __dtBusInfo[110],  __dtBusInfo[111]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgMul, work1 +  __dtBusInfo[112],  __dtBusInfo[113]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltAvgMin, work1 +  __dtBusInfo[114],  __dtBusInfo[115]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16LdqNumMeas, work1 +  __dtBusInfo[116],  __dtBusInfo[117]);
        (void) memcpy(&__work1BUS[0].pInnerState.u32TblCounter, work1 +  __dtBusInfo[118],  __dtBusInfo[119]);
        (void) memcpy(&__work1BUS[0].pInnerState.u8RotorFixed, work1 +  __dtBusInfo[120],  __dtBusInfo[121]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcRampCoef, work1 +  __dtBusInfo[122],  __dtBusInfo[123]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcRampCoefMax, work1 +  __dtBusInfo[124],  __dtBusInfo[125]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcDRampAcc, work1 +  __dtBusInfo[126],  __dtBusInfo[127]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcQRampAcc, work1 +  __dtBusInfo[128],  __dtBusInfo[129]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcDAcc, work1 +  __dtBusInfo[130],  __dtBusInfo[131]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcDAccAvg, work1 +  __dtBusInfo[132],  __dtBusInfo[133]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcDAccAvgk_1, work1 +  __dtBusInfo[134],  __dtBusInfo[135]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcQAcc, work1 +  __dtBusInfo[136],  __dtBusInfo[137]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcAcc, work1 +  __dtBusInfo[138],  __dtBusInfo[139]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcKi, work1 +  __dtBusInfo[140],  __dtBusInfo[141]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcKi, work1 +  __dtBusInfo[142],  __dtBusInfo[143]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcKiNominal, work1 +  __dtBusInfo[144],  __dtBusInfo[145]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUAcKiNominal, work1 +  __dtBusInfo[146],  __dtBusInfo[147]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16RampSteady, work1 +  __dtBusInfo[148],  __dtBusInfo[149]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16DcbLimitFlag, work1 +  __dtBusInfo[150],  __dtBusInfo[151]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16DcbLimitFlagk_1, work1 +  __dtBusInfo[152],  __dtBusInfo[153]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16DcbLimitCnt, work1 +  __dtBusInfo[154],  __dtBusInfo[155]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltPhaseShift, work1 +  __dtBusInfo[156],  __dtBusInfo[157]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUdcHalf, work1 +  __dtBusInfo[158],  __dtBusInfo[159]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltFsInv, work1 +  __dtBusInfo[160],  __dtBusInfo[161]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltImpConst, work1 +  __dtBusInfo[162],  __dtBusInfo[163]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltLdk_1, work1 +  __dtBusInfo[164],  __dtBusInfo[165]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltLqk_1, work1 +  __dtBusInfo[166],  __dtBusInfo[167]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcLd, work1 +  __dtBusInfo[168],  __dtBusInfo[169]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltIDcLq, work1 +  __dtBusInfo[170],  __dtBusInfo[171]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUdtAcc, work1 +  __dtBusInfo[172],  __dtBusInfo[173]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltRAcc, work1 +  __dtBusInfo[174],  __dtBusInfo[175]);
        (void) memcpy(&__work1BUS[0].pInnerState.u16LdqNumMeasR, work1 +  __dtBusInfo[176],  __dtBusInfo[177]);
        (void) memcpy(&__work1BUS[0].pInnerState.fltUDcBusMax, work1 +  __dtBusInfo[178],  __dtBusInfo[179]);

        /* Call the legacy code function */
        *y1 = AMCLIB_EstimRL_w_FLT(__y2BUS, y3, y4, y5, y6, y7, __u1BUS, *u2, __work1BUS, *u3, *u4, *u5, *u6, *u7, *p3, *p7);

        /* Assign the user structure __y2BUS to the Simulink structure y2 */
        (void) memcpy(y2 +  __dtBusInfo[0], &__y2BUS[0].fltArg1,  __dtBusInfo[1]);
        (void) memcpy(y2 +  __dtBusInfo[2], &__y2BUS[0].fltArg2,  __dtBusInfo[3]);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[4], &__work1BUS[0].fltLd,  __dtBusInfo[5]);
        (void) memcpy(work1 +  __dtBusInfo[6], &__work1BUS[0].fltLq,  __dtBusInfo[7]);
        (void) memcpy(work1 +  __dtBusInfo[8], &__work1BUS[0].fltR,  __dtBusInfo[9]);
        (void) memcpy(work1 +  __dtBusInfo[10], &__work1BUS[0].fltUdt,  __dtBusInfo[11]);
        (void) memcpy(work1 +  __dtBusInfo[12], &__work1BUS[0].pInnerState.pState,  __dtBusInfo[13]);
        (void) memcpy(work1 +  __dtBusInfo[14], &__work1BUS[0].pInnerState.f32FAc,  __dtBusInfo[15]);
        (void) memcpy(work1 +  __dtBusInfo[16], &__work1BUS[0].pInnerState.fltIDcMax,  __dtBusInfo[17]);
        (void) memcpy(work1 +  __dtBusInfo[18], &__work1BUS[0].pInnerState.fltIDcNegMax,  __dtBusInfo[19]);
        (void) memcpy(work1 +  __dtBusInfo[20], &__work1BUS[0].pInnerState.fltIDcMaxInv,  __dtBusInfo[21]);
        (void) memcpy(work1 +  __dtBusInfo[22], &__work1BUS[0].pInnerState.fltIAcReq,  __dtBusInfo[23]);
        (void) memcpy(work1 +  __dtBusInfo[24], &__work1BUS[0].pInnerState.fltIAcReqInv,  __dtBusInfo[25]);
        (void) memcpy(work1 +  __dtBusInfo[26], &__work1BUS[0].pInnerState.fltIDcDReq,  __dtBusInfo[27]);
        (void) memcpy(work1 +  __dtBusInfo[28], &__work1BUS[0].pInnerState.fltIDcDReqk_1,  __dtBusInfo[29]);
        (void) memcpy(work1 +  __dtBusInfo[30], &__work1BUS[0].pInnerState.fltIDcQReq,  __dtBusInfo[31]);
        (void) memcpy(work1 +  __dtBusInfo[32], &__work1BUS[0].pInnerState.fltIDcQReqk_1,  __dtBusInfo[33]);
        (void) memcpy(work1 +  __dtBusInfo[34], &__work1BUS[0].pInnerState.fltIDcReqStep,  __dtBusInfo[35]);
        (void) memcpy(work1 +  __dtBusInfo[36], &__work1BUS[0].pInnerState.fltIAlBeEstErr,  __dtBusInfo[37]);
        (void) memcpy(work1 +  __dtBusInfo[38], &__work1BUS[0].pInnerState.pIAlBeAc.fltArg1,  __dtBusInfo[39]);
        (void) memcpy(work1 +  __dtBusInfo[40], &__work1BUS[0].pInnerState.pIAlBeAc.fltArg2,  __dtBusInfo[41]);
        (void) memcpy(work1 +  __dtBusInfo[42], &__work1BUS[0].pInnerState.pSinCosEst.fltArg1,  __dtBusInfo[43]);
        (void) memcpy(work1 +  __dtBusInfo[44], &__work1BUS[0].pInnerState.pSinCosEst.fltArg2,  __dtBusInfo[45]);
        (void) memcpy(work1 +  __dtBusInfo[46], &__work1BUS[0].pInnerState.pIDQAcRaw.fltArg1,  __dtBusInfo[47]);
        (void) memcpy(work1 +  __dtBusInfo[48], &__work1BUS[0].pInnerState.pIDQAcRaw.fltArg2,  __dtBusInfo[49]);
        (void) memcpy(work1 +  __dtBusInfo[50], &__work1BUS[0].pInnerState.pIDQAcFilt.fltArg1,  __dtBusInfo[51]);
        (void) memcpy(work1 +  __dtBusInfo[52], &__work1BUS[0].pInnerState.pIDQAcFilt.fltArg2,  __dtBusInfo[53]);
        (void) memcpy(work1 +  __dtBusInfo[54], &__work1BUS[0].pInnerState.pDAxisFilter.fltAcc,  __dtBusInfo[55]);
        (void) memcpy(work1 +  __dtBusInfo[56], &__work1BUS[0].pInnerState.pDAxisFilter.fltLambda,  __dtBusInfo[57]);
        (void) memcpy(work1 +  __dtBusInfo[58], &__work1BUS[0].pInnerState.pQAxisFilter.fltAcc,  __dtBusInfo[59]);
        (void) memcpy(work1 +  __dtBusInfo[60], &__work1BUS[0].pInnerState.pQAxisFilter.fltLambda,  __dtBusInfo[61]);
        (void) memcpy(work1 +  __dtBusInfo[62], &__work1BUS[0].pInnerState.pDcFilter.fltAcc,  __dtBusInfo[63]);
        (void) memcpy(work1 +  __dtBusInfo[64], &__work1BUS[0].pInnerState.pDcFilter.fltLambda,  __dtBusInfo[65]);
        (void) memcpy(work1 +  __dtBusInfo[66], &__work1BUS[0].pInnerState.pStdFilter.fltAcc,  __dtBusInfo[67]);
        (void) memcpy(work1 +  __dtBusInfo[68], &__work1BUS[0].pInnerState.pStdFilter.fltLambda,  __dtBusInfo[69]);
        (void) memcpy(work1 +  __dtBusInfo[70], &__work1BUS[0].pInnerState.fltPLLPropGain,  __dtBusInfo[71]);
        (void) memcpy(work1 +  __dtBusInfo[72], &__work1BUS[0].pInnerState.f32ThAc,  __dtBusInfo[73]);
        (void) memcpy(work1 +  __dtBusInfo[74], &__work1BUS[0].pInnerState.f32ThEst,  __dtBusInfo[75]);
        (void) memcpy(work1 +  __dtBusInfo[76], &__work1BUS[0].pInnerState.fltIDcD,  __dtBusInfo[77]);
        (void) memcpy(work1 +  __dtBusInfo[78], &__work1BUS[0].pInnerState.fltIDcQ,  __dtBusInfo[79]);
        (void) memcpy(work1 +  __dtBusInfo[80], &__work1BUS[0].pInnerState.fltIDcDAvg,  __dtBusInfo[81]);
        (void) memcpy(work1 +  __dtBusInfo[82], &__work1BUS[0].pInnerState.fltIDcDAvgk_1,  __dtBusInfo[83]);
        (void) memcpy(work1 +  __dtBusInfo[84], &__work1BUS[0].pInnerState.fltPhComp,  __dtBusInfo[85]);
        (void) memcpy(work1 +  __dtBusInfo[86], &__work1BUS[0].pInnerState.s32ConvDetState,  __dtBusInfo[87]);
        (void) memcpy(work1 +  __dtBusInfo[88], &__work1BUS[0].pInnerState.s32ConvDetStateLimL,  __dtBusInfo[89]);
        (void) memcpy(work1 +  __dtBusInfo[90], &__work1BUS[0].pInnerState.s32ConvDetStateLimH,  __dtBusInfo[91]);
        (void) memcpy(work1 +  __dtBusInfo[92], &__work1BUS[0].pInnerState.u32ConvDetToutCnt,  __dtBusInfo[93]);
        (void) memcpy(work1 +  __dtBusInfo[94], &__work1BUS[0].pInnerState.u32ConvDetToutReload,  __dtBusInfo[95]);
        (void) memcpy(work1 +  __dtBusInfo[96], &__work1BUS[0].pInnerState.u32AvgCnt,  __dtBusInfo[97]);
        (void) memcpy(work1 +  __dtBusInfo[98], &__work1BUS[0].pInnerState.u32AvgN,  __dtBusInfo[99]);
        (void) memcpy(work1 +  __dtBusInfo[100], &__work1BUS[0].pInnerState.fltAvgNInv,  __dtBusInfo[101]);
        (void) memcpy(work1 +  __dtBusInfo[102], &__work1BUS[0].pInnerState.fltAvgNInvMaxDelta,  __dtBusInfo[103]);
        (void) memcpy(work1 +  __dtBusInfo[104], &__work1BUS[0].pInnerState.u32AvgCntMax,  __dtBusInfo[105]);
        (void) memcpy(work1 +  __dtBusInfo[106], &__work1BUS[0].pInnerState.fltPhAvg,  __dtBusInfo[107]);
        (void) memcpy(work1 +  __dtBusInfo[108], &__work1BUS[0].pInnerState.fltIAcAvg,  __dtBusInfo[109]);
        (void) memcpy(work1 +  __dtBusInfo[110], &__work1BUS[0].pInnerState.fltUAcAvg,  __dtBusInfo[111]);
        (void) memcpy(work1 +  __dtBusInfo[112], &__work1BUS[0].pInnerState.fltAvgMul,  __dtBusInfo[113]);
        (void) memcpy(work1 +  __dtBusInfo[114], &__work1BUS[0].pInnerState.fltAvgMin,  __dtBusInfo[115]);
        (void) memcpy(work1 +  __dtBusInfo[116], &__work1BUS[0].pInnerState.u16LdqNumMeas,  __dtBusInfo[117]);
        (void) memcpy(work1 +  __dtBusInfo[118], &__work1BUS[0].pInnerState.u32TblCounter,  __dtBusInfo[119]);
        (void) memcpy(work1 +  __dtBusInfo[120], &__work1BUS[0].pInnerState.u8RotorFixed,  __dtBusInfo[121]);
        (void) memcpy(work1 +  __dtBusInfo[122], &__work1BUS[0].pInnerState.fltIDcRampCoef,  __dtBusInfo[123]);
        (void) memcpy(work1 +  __dtBusInfo[124], &__work1BUS[0].pInnerState.fltIDcRampCoefMax,  __dtBusInfo[125]);
        (void) memcpy(work1 +  __dtBusInfo[126], &__work1BUS[0].pInnerState.fltIDcDRampAcc,  __dtBusInfo[127]);
        (void) memcpy(work1 +  __dtBusInfo[128], &__work1BUS[0].pInnerState.fltIDcQRampAcc,  __dtBusInfo[129]);
        (void) memcpy(work1 +  __dtBusInfo[130], &__work1BUS[0].pInnerState.fltUDcDAcc,  __dtBusInfo[131]);
        (void) memcpy(work1 +  __dtBusInfo[132], &__work1BUS[0].pInnerState.fltUDcDAccAvg,  __dtBusInfo[133]);
        (void) memcpy(work1 +  __dtBusInfo[134], &__work1BUS[0].pInnerState.fltUDcDAccAvgk_1,  __dtBusInfo[135]);
        (void) memcpy(work1 +  __dtBusInfo[136], &__work1BUS[0].pInnerState.fltUDcQAcc,  __dtBusInfo[137]);
        (void) memcpy(work1 +  __dtBusInfo[138], &__work1BUS[0].pInnerState.fltUAcAcc,  __dtBusInfo[139]);
        (void) memcpy(work1 +  __dtBusInfo[140], &__work1BUS[0].pInnerState.fltUDcKi,  __dtBusInfo[141]);
        (void) memcpy(work1 +  __dtBusInfo[142], &__work1BUS[0].pInnerState.fltUAcKi,  __dtBusInfo[143]);
        (void) memcpy(work1 +  __dtBusInfo[144], &__work1BUS[0].pInnerState.fltUDcKiNominal,  __dtBusInfo[145]);
        (void) memcpy(work1 +  __dtBusInfo[146], &__work1BUS[0].pInnerState.fltUAcKiNominal,  __dtBusInfo[147]);
        (void) memcpy(work1 +  __dtBusInfo[148], &__work1BUS[0].pInnerState.u16RampSteady,  __dtBusInfo[149]);
        (void) memcpy(work1 +  __dtBusInfo[150], &__work1BUS[0].pInnerState.u16DcbLimitFlag,  __dtBusInfo[151]);
        (void) memcpy(work1 +  __dtBusInfo[152], &__work1BUS[0].pInnerState.u16DcbLimitFlagk_1,  __dtBusInfo[153]);
        (void) memcpy(work1 +  __dtBusInfo[154], &__work1BUS[0].pInnerState.u16DcbLimitCnt,  __dtBusInfo[155]);
        (void) memcpy(work1 +  __dtBusInfo[156], &__work1BUS[0].pInnerState.fltPhaseShift,  __dtBusInfo[157]);
        (void) memcpy(work1 +  __dtBusInfo[158], &__work1BUS[0].pInnerState.fltUdcHalf,  __dtBusInfo[159]);
        (void) memcpy(work1 +  __dtBusInfo[160], &__work1BUS[0].pInnerState.fltFsInv,  __dtBusInfo[161]);
        (void) memcpy(work1 +  __dtBusInfo[162], &__work1BUS[0].pInnerState.fltImpConst,  __dtBusInfo[163]);
        (void) memcpy(work1 +  __dtBusInfo[164], &__work1BUS[0].pInnerState.fltLdk_1,  __dtBusInfo[165]);
        (void) memcpy(work1 +  __dtBusInfo[166], &__work1BUS[0].pInnerState.fltLqk_1,  __dtBusInfo[167]);
        (void) memcpy(work1 +  __dtBusInfo[168], &__work1BUS[0].pInnerState.fltIDcLd,  __dtBusInfo[169]);
        (void) memcpy(work1 +  __dtBusInfo[170], &__work1BUS[0].pInnerState.fltIDcLq,  __dtBusInfo[171]);
        (void) memcpy(work1 +  __dtBusInfo[172], &__work1BUS[0].pInnerState.fltUdtAcc,  __dtBusInfo[173]);
        (void) memcpy(work1 +  __dtBusInfo[174], &__work1BUS[0].pInnerState.fltRAcc,  __dtBusInfo[175]);
        (void) memcpy(work1 +  __dtBusInfo[176], &__work1BUS[0].pInnerState.u16LdqNumMeasR,  __dtBusInfo[177]);
        (void) memcpy(work1 +  __dtBusInfo[178], &__work1BUS[0].pInnerState.fltUDcBusMax,  __dtBusInfo[179]);
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
            AMCLIB_ESTIMRL_T_FLT* __work1BUS = (AMCLIB_ESTIMRL_T_FLT*)ssGetPWorkValue(S, 2);
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

    /* Verify Enumerated Type 'AMCLIB_ESTIMRL_RET_T' specification */
    {
        uint32_T chk[] = {2319754610, 4165122193, 595969682, 1234715890};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_ESTIMRL_RET_T", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Enumerated type 'AMCLIB_ESTIMRL_RET_T'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Enumerated type 'AMCLIB_ESTIMRL_RET_T' definition has changed since the S-Function was generated");
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

    /* Verify Bus/StructType 'AMCLIB_ESTIMRL_T_FLT', specification */
    {
        uint32_T chk[] = {1311108560, 718579485, 1081454841, 3253942602};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_ESTIMRL_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'AMCLIB_ESTIMRL_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'AMCLIB_ESTIMRL_T_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'AMCLIB_ESTIMRL_INNERST_T_FLT', specification */
    {
        uint32_T chk[] = {1170116075, 2658977938, 3672398710, 984601224};
        int_T status;
        status = CheckDataTypeChecksum(S, "AMCLIB_ESTIMRL_INNERST_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'AMCLIB_ESTIMRL_INNERST_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'AMCLIB_ESTIMRL_INNERST_T_FLT' definition has changed since the S-Function was generated");
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

