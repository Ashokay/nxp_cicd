/**
 * GMCLIB_SvmStd6Ph_SF_FLT.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         void GMCLIB_SvmStd6Ph_w_FLT(SWLIBS_6Syst_FLT y1[1], SWLIBS_2Syst_U32 y2[1], SWLIBS_2Syst_FLT u1[1], GMCLIB_SVMSTD_6PH_T_FLT work1[1])
 *
 *    Simulink version           : 9.3 (R2019a) 23-Nov-2018
 *    C source code generated on : 12-Sep-2023 09:21:42
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
#define S_FUNCTION_NAME  GMCLIB_SvmStd6Ph_SF_FLT
#define S_FUNCTION_LEVEL 2

/**
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

#include <string.h>
#include <stdlib.h>

/* Specific header file(s) required by the legacy code function */
#include "gmclib.h"
#include "GMCLIB_SvmStd6Ph_w.h"
#include "gflib.h"

/* Specific header file(s) required for data types declarations */
#include "SWLIBS_Typedefs.h"
#include "GMCLIB_SvmStd6Ph.h"

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
    ssSetNumSFcnParams(S, 1);

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

    /* Set the number of work vectors */
    if (!IS_SIMULATION_TARGET(S)) {
        ssSetNumPWork(S, 0);
        if (!ssSetNumDWork(S, 1)) return;
    } else {
        ssSetNumPWork(S, 4);
        if (!ssSetNumDWork(S, 3)) return;

        /* Configure the dwork 2 (__dtSizeInfo) */
        ssSetDWorkDataType(S, 1, SS_INT32);
        ssSetDWorkUsageType(S, 1, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 1, "dtSizeInfo");
        ssSetDWorkWidth(S, 1, 6);
        ssSetDWorkComplexSignal(S, 1, COMPLEX_NO);

        /* Configure the dwork 3 (__dtBusInfo) */
        ssSetDWorkDataType(S, 2, SS_INT32);
        ssSetDWorkUsageType(S, 2, SS_DWORK_USED_AS_DWORK);
        ssSetDWorkName(S, 2, "dtBusInfo");
        ssSetDWorkWidth(S, 2, 32);
        ssSetDWorkComplexSignal(S, 2, COMPLEX_NO);
    } /* if */

    /* Configure the dwork 1 (work1) */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "GMCLIB_SVMSTD_6PH_T_FLT", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetDWorkDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetDWorkUsageType(S, 0, SS_DWORK_USED_AS_DWORK);
    ssSetDWorkName(S, 0, "work1");
    ssSetDWorkWidth(S, 0, 1);
    ssSetDWorkComplexSignal(S, 0, COMPLEX_NO);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 1)) return;

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

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 2)) return;

    /* Configure the output port 1 */
    #if defined(MATLAB_MEX_FILE) 
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;

        ssRegisterTypeFromNamedObject(S, "SWLIBS_6Syst_FLT", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetOutputPortDataType(S, 0, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusOutputObjectName(S, 0, (void *)"SWLIBS_6Syst_FLT");
    ssSetBusOutputAsStruct(S, 0, 1);
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

        ssRegisterTypeFromNamedObject(S, "SWLIBS_2Syst_U32", &dataTypeIdReg);
        if(dataTypeIdReg == INVALID_DTYPE_ID) return;

        ssSetOutputPortDataType(S, 1, dataTypeIdReg);
    } /* if */
    #endif
    ssSetBusOutputObjectName(S, 1, (void *)"SWLIBS_2Syst_U32");
    ssSetBusOutputAsStruct(S, 1, 1);
    {
        int_T y2Width = 1;
        ssSetOutputPortWidth(S, 1, y2Width);
    }
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 1, 0);

    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "GMCLIB_SvmStd6PhInit_w_FLT", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "GMCLIB_SvmStd6Ph_w_FLT", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

        /* Register reserved identifier for wrappers */
        if (isSimulationTarget) {

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "GMCLIB_SvmStd6PhInit_w_FLT_wrapper_InitializeConditions", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for  */
            ssRegMdlInfo(S, "GMCLIB_SvmStd6Ph_w_FLT_wrapper_Output", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for allocating PWork for SimulationTarget */
            ssRegMdlInfo(S, "GMCLIB_SvmStd6Ph_SF_FLT_wrapper_allocmem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

            /* Register reserved identifier for freeing PWork for SimulationTarget */
            ssRegMdlInfo(S, "GMCLIB_SvmStd6Ph_SF_FLT_wrapper_freemem", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
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
    if (!ssSetNumRunTimeParams(S, 1)) return;

    /* Register the run-time parameter 1 */
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "p1", ssGetDataTypeId(S, "single"));
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
        DTypeId __SWLIBS_6Syst_FLTId = ssGetDataTypeId(S, "SWLIBS_6Syst_FLT");
        DTypeId __singleId = ssGetDataTypeId(S, "single");
        DTypeId __SWLIBS_2Syst_U32Id = ssGetDataTypeId(S, "SWLIBS_2Syst_U32");
        DTypeId __uint32Id = ssGetDataTypeId(S, "uint32");
        DTypeId __SWLIBS_2Syst_FLTId = ssGetDataTypeId(S, "SWLIBS_2Syst_FLT");
        DTypeId __GMCLIB_SVMSTD_6PH_T_FLTId = ssGetDataTypeId(S, "GMCLIB_SVMSTD_6PH_T_FLT");

        /* Get common data type size */
        __dtSizeInfo[0] = ssGetDataTypeSize(S, __SWLIBS_6Syst_FLTId);
        __dtSizeInfo[1] = ssGetDataTypeSize(S, __singleId);
        __dtSizeInfo[2] = ssGetDataTypeSize(S, __SWLIBS_2Syst_U32Id);
        __dtSizeInfo[3] = ssGetDataTypeSize(S, __uint32Id);
        __dtSizeInfo[4] = ssGetDataTypeSize(S, __SWLIBS_2Syst_FLTId);
        __dtSizeInfo[5] = ssGetDataTypeSize(S, __GMCLIB_SVMSTD_6PH_T_FLTId);

        /* Get information for accessing SWLIBS_6Syst_FLT.fltArg1 */
        __dtBusInfo[0] = ssGetBusElementOffset(S, __SWLIBS_6Syst_FLTId, 0);
        __dtBusInfo[1] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_6Syst_FLT.fltArg2 */
        __dtBusInfo[2] = ssGetBusElementOffset(S, __SWLIBS_6Syst_FLTId, 1);
        __dtBusInfo[3] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_6Syst_FLT.fltArg3 */
        __dtBusInfo[4] = ssGetBusElementOffset(S, __SWLIBS_6Syst_FLTId, 2);
        __dtBusInfo[5] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_6Syst_FLT.fltArg4 */
        __dtBusInfo[6] = ssGetBusElementOffset(S, __SWLIBS_6Syst_FLTId, 3);
        __dtBusInfo[7] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_6Syst_FLT.fltArg5 */
        __dtBusInfo[8] = ssGetBusElementOffset(S, __SWLIBS_6Syst_FLTId, 4);
        __dtBusInfo[9] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_6Syst_FLT.fltArg6 */
        __dtBusInfo[10] = ssGetBusElementOffset(S, __SWLIBS_6Syst_FLTId, 5);
        __dtBusInfo[11] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_2Syst_U32.u32Arg1 */
        __dtBusInfo[12] = ssGetBusElementOffset(S, __SWLIBS_2Syst_U32Id, 0);
        __dtBusInfo[13] = __dtSizeInfo[3];

        /* Get information for accessing SWLIBS_2Syst_U32.u32Arg2 */
        __dtBusInfo[14] = ssGetBusElementOffset(S, __SWLIBS_2Syst_U32Id, 1);
        __dtBusInfo[15] = __dtSizeInfo[3];

        /* Get information for accessing SWLIBS_2Syst_FLT.fltArg1 */
        __dtBusInfo[16] = ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 0);
        __dtBusInfo[17] = __dtSizeInfo[1];

        /* Get information for accessing SWLIBS_2Syst_FLT.fltArg2 */
        __dtBusInfo[18] = ssGetBusElementOffset(S, __SWLIBS_2Syst_FLTId, 1);
        __dtBusInfo[19] = __dtSizeInfo[1];

        /* Get information for accessing GMCLIB_SVMSTD_6PH_T_FLT.fltAlphaD */
        __dtBusInfo[20] = ssGetBusElementOffset(S, __GMCLIB_SVMSTD_6PH_T_FLTId, 0);
        __dtBusInfo[21] = __dtSizeInfo[1];

        /* Get information for accessing GMCLIB_SVMSTD_6PH_T_FLT.fltAlphaE */
        __dtBusInfo[22] = ssGetBusElementOffset(S, __GMCLIB_SVMSTD_6PH_T_FLTId, 1);
        __dtBusInfo[23] = __dtSizeInfo[1];

        /* Get information for accessing GMCLIB_SVMSTD_6PH_T_FLT.fltAlphaF */
        __dtBusInfo[24] = ssGetBusElementOffset(S, __GMCLIB_SVMSTD_6PH_T_FLTId, 2);
        __dtBusInfo[25] = __dtSizeInfo[1];

        /* Get information for accessing GMCLIB_SVMSTD_6PH_T_FLT.fltBetaD */
        __dtBusInfo[26] = ssGetBusElementOffset(S, __GMCLIB_SVMSTD_6PH_T_FLTId, 3);
        __dtBusInfo[27] = __dtSizeInfo[1];

        /* Get information for accessing GMCLIB_SVMSTD_6PH_T_FLT.fltBetaE */
        __dtBusInfo[28] = ssGetBusElementOffset(S, __GMCLIB_SVMSTD_6PH_T_FLTId, 4);
        __dtBusInfo[29] = __dtSizeInfo[1];

        /* Get information for accessing GMCLIB_SVMSTD_6PH_T_FLT.fltBetaF */
        __dtBusInfo[30] = ssGetBusElementOffset(S, __GMCLIB_SVMSTD_6PH_T_FLTId, 5);
        __dtBusInfo[31] = __dtSizeInfo[1];


        /* Alloc memory for the pwork 1 (__y1BUS) */
        {
            SWLIBS_6Syst_FLT* __y1BUS = (SWLIBS_6Syst_FLT*)calloc(sizeof(SWLIBS_6Syst_FLT), ssGetOutputPortWidth(S, 0));
            if (__y1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __y1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 0, __y1BUS);
        }

        /* Alloc memory for the pwork 2 (__y2BUS) */
        {
            SWLIBS_2Syst_U32* __y2BUS = (SWLIBS_2Syst_U32*)calloc(sizeof(SWLIBS_2Syst_U32), ssGetOutputPortWidth(S, 1));
            if (__y2BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __y2BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 1, __y2BUS);
        }

        /* Alloc memory for the pwork 3 (__u1BUS) */
        {
            SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*)calloc(sizeof(SWLIBS_2Syst_FLT), ssGetInputPortWidth(S, 0));
            if (__u1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __u1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 2, __u1BUS);
        }

        /* Alloc memory for the pwork 4 (__work1BUS) */
        {
            GMCLIB_SVMSTD_6PH_T_FLT* __work1BUS = (GMCLIB_SVMSTD_6PH_T_FLT*)calloc(sizeof(GMCLIB_SVMSTD_6PH_T_FLT), ssGetDWorkWidth(S, 0));
            if (__work1BUS==NULL) {
                ssSetErrorStatus(S, "Unexpected error during the memory allocation for __work1BUS");
                return;
            } /* if */
            ssSetPWorkValue(S, 3, __work1BUS);
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
        char* work1 = (char*) ssGetDWork(S, 0);
        real32_T* p1 = (real32_T*) ssGetRunTimeParamInfo(S, 0)->data;

        GMCLIB_SVMSTD_6PH_T_FLT* __work1BUS = (GMCLIB_SVMSTD_6PH_T_FLT*) ssGetPWorkValue(S, 3);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].fltAlphaD, work1 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work1BUS[0].fltAlphaE, work1 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work1BUS[0].fltAlphaF, work1 +  __dtBusInfo[24],  __dtBusInfo[25]);
        (void) memcpy(&__work1BUS[0].fltBetaD, work1 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work1BUS[0].fltBetaE, work1 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work1BUS[0].fltBetaF, work1 +  __dtBusInfo[30],  __dtBusInfo[31]);

        /* Call the legacy code function */
        GMCLIB_SvmStd6PhInit_w_FLT(__work1BUS, *p1);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[20], &__work1BUS[0].fltAlphaD,  __dtBusInfo[21]);
        (void) memcpy(work1 +  __dtBusInfo[22], &__work1BUS[0].fltAlphaE,  __dtBusInfo[23]);
        (void) memcpy(work1 +  __dtBusInfo[24], &__work1BUS[0].fltAlphaF,  __dtBusInfo[25]);
        (void) memcpy(work1 +  __dtBusInfo[26], &__work1BUS[0].fltBetaD,  __dtBusInfo[27]);
        (void) memcpy(work1 +  __dtBusInfo[28], &__work1BUS[0].fltBetaE,  __dtBusInfo[29]);
        (void) memcpy(work1 +  __dtBusInfo[30], &__work1BUS[0].fltBetaF,  __dtBusInfo[31]);
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
        char* y1 = (char*) ssGetOutputPortSignal(S, 0);
        char* y2 = (char*) ssGetOutputPortSignal(S, 1);
        char* u1 = (char*) ssGetInputPortSignal(S, 0);
        char* work1 = (char*) ssGetDWork(S, 0);

        SWLIBS_6Syst_FLT* __y1BUS = (SWLIBS_6Syst_FLT*) ssGetPWorkValue(S, 0);
        SWLIBS_2Syst_U32* __y2BUS = (SWLIBS_2Syst_U32*) ssGetPWorkValue(S, 1);
        SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*) ssGetPWorkValue(S, 2);
        GMCLIB_SVMSTD_6PH_T_FLT* __work1BUS = (GMCLIB_SVMSTD_6PH_T_FLT*) ssGetPWorkValue(S, 3);

        /* Assign the Simulink structure u1 to user structure __u1BUS */
        (void) memcpy(&__u1BUS[0].fltArg1, u1 +  __dtBusInfo[16],  __dtBusInfo[17]);
        (void) memcpy(&__u1BUS[0].fltArg2, u1 +  __dtBusInfo[18],  __dtBusInfo[19]);

        /* Assign the Simulink structure work1 to user structure __work1BUS */
        (void) memcpy(&__work1BUS[0].fltAlphaD, work1 +  __dtBusInfo[20],  __dtBusInfo[21]);
        (void) memcpy(&__work1BUS[0].fltAlphaE, work1 +  __dtBusInfo[22],  __dtBusInfo[23]);
        (void) memcpy(&__work1BUS[0].fltAlphaF, work1 +  __dtBusInfo[24],  __dtBusInfo[25]);
        (void) memcpy(&__work1BUS[0].fltBetaD, work1 +  __dtBusInfo[26],  __dtBusInfo[27]);
        (void) memcpy(&__work1BUS[0].fltBetaE, work1 +  __dtBusInfo[28],  __dtBusInfo[29]);
        (void) memcpy(&__work1BUS[0].fltBetaF, work1 +  __dtBusInfo[30],  __dtBusInfo[31]);

        /* Call the legacy code function */
        GMCLIB_SvmStd6Ph_w_FLT(__y1BUS, __y2BUS, __u1BUS, __work1BUS);

        /* Assign the user structure __y1BUS to the Simulink structure y1 */
        (void) memcpy(y1 +  __dtBusInfo[0], &__y1BUS[0].fltArg1,  __dtBusInfo[1]);
        (void) memcpy(y1 +  __dtBusInfo[2], &__y1BUS[0].fltArg2,  __dtBusInfo[3]);
        (void) memcpy(y1 +  __dtBusInfo[4], &__y1BUS[0].fltArg3,  __dtBusInfo[5]);
        (void) memcpy(y1 +  __dtBusInfo[6], &__y1BUS[0].fltArg4,  __dtBusInfo[7]);
        (void) memcpy(y1 +  __dtBusInfo[8], &__y1BUS[0].fltArg5,  __dtBusInfo[9]);
        (void) memcpy(y1 +  __dtBusInfo[10], &__y1BUS[0].fltArg6,  __dtBusInfo[11]);

        /* Assign the user structure __y2BUS to the Simulink structure y2 */
        (void) memcpy(y2 +  __dtBusInfo[12], &__y2BUS[0].u32Arg1,  __dtBusInfo[13]);
        (void) memcpy(y2 +  __dtBusInfo[14], &__y2BUS[0].u32Arg2,  __dtBusInfo[15]);

        /* Assign the user structure __work1BUS to the Simulink structure work1 */
        (void) memcpy(work1 +  __dtBusInfo[20], &__work1BUS[0].fltAlphaD,  __dtBusInfo[21]);
        (void) memcpy(work1 +  __dtBusInfo[22], &__work1BUS[0].fltAlphaE,  __dtBusInfo[23]);
        (void) memcpy(work1 +  __dtBusInfo[24], &__work1BUS[0].fltAlphaF,  __dtBusInfo[25]);
        (void) memcpy(work1 +  __dtBusInfo[26], &__work1BUS[0].fltBetaD,  __dtBusInfo[27]);
        (void) memcpy(work1 +  __dtBusInfo[28], &__work1BUS[0].fltBetaE,  __dtBusInfo[29]);
        (void) memcpy(work1 +  __dtBusInfo[30], &__work1BUS[0].fltBetaF,  __dtBusInfo[31]);
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


        /* Free memory for the pwork 1 (__y1BUS) */
        {
            SWLIBS_6Syst_FLT* __y1BUS = (SWLIBS_6Syst_FLT*)ssGetPWorkValue(S, 0);
            if (__y1BUS!=NULL) {
                free(__y1BUS);
                ssSetPWorkValue(S, 0, NULL);
            } /* if */
        }

        /* Free memory for the pwork 2 (__y2BUS) */
        {
            SWLIBS_2Syst_U32* __y2BUS = (SWLIBS_2Syst_U32*)ssGetPWorkValue(S, 1);
            if (__y2BUS!=NULL) {
                free(__y2BUS);
                ssSetPWorkValue(S, 1, NULL);
            } /* if */
        }

        /* Free memory for the pwork 3 (__u1BUS) */
        {
            SWLIBS_2Syst_FLT* __u1BUS = (SWLIBS_2Syst_FLT*)ssGetPWorkValue(S, 2);
            if (__u1BUS!=NULL) {
                free(__u1BUS);
                ssSetPWorkValue(S, 2, NULL);
            } /* if */
        }

        /* Free memory for the pwork 4 (__work1BUS) */
        {
            GMCLIB_SVMSTD_6PH_T_FLT* __work1BUS = (GMCLIB_SVMSTD_6PH_T_FLT*)ssGetPWorkValue(S, 3);
            if (__work1BUS!=NULL) {
                free(__work1BUS);
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

    /* Verify Bus/StructType 'SWLIBS_6Syst_FLT', specification */
    {
        uint32_T chk[] = {1123431438, 698584254, 3406931590, 3692612341};
        int_T status;
        status = CheckDataTypeChecksum(S, "SWLIBS_6Syst_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'SWLIBS_6Syst_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'SWLIBS_6Syst_FLT' definition has changed since the S-Function was generated");
        }
    }

    /* Verify Bus/StructType 'SWLIBS_2Syst_U32', specification */
    {
        uint32_T chk[] = {3043584108, 2264765012, 2375428452, 3166939641};
        int_T status;
        status = CheckDataTypeChecksum(S, "SWLIBS_2Syst_U32", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'SWLIBS_2Syst_U32'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'SWLIBS_2Syst_U32' definition has changed since the S-Function was generated");
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

    /* Verify Bus/StructType 'GMCLIB_SVMSTD_6PH_T_FLT', specification */
    {
        uint32_T chk[] = {1476469853, 556454327, 178620435, 3984354648};
        int_T status;
        status = CheckDataTypeChecksum(S, "GMCLIB_SVMSTD_6PH_T_FLT", &chk[0]);
        if (status==-1) {
          ssSetErrorStatus(S, "Unexpected error when checking the validity of the Simulink Bus/StructType 'GMCLIB_SVMSTD_6PH_T_FLT'");
        } else if (status==0) {
          ssSetErrorStatus(S, "The Simulink Bus/StructType 'GMCLIB_SVMSTD_6PH_T_FLT' definition has changed since the S-Function was generated");
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

