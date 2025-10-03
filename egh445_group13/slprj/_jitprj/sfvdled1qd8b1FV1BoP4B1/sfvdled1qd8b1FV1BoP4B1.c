#define S_FUNCTION_NAME sf_sfun
#include "covrt.h"
#include "cgxert.h"
#include "emlrt.h"
#include "sfrtif/sfc_sf.h"
#include "sfrtif/MessageServiceLayer.h"
#include "sfrtif/DebuggerRuntimeInterface.h"
#include "sfrtif/sfc_mex.h"
#include "sfrtif/sf_runtime_errors.h"
#include "sfrtif/sf_partitioning_execution_bridge.h"
#include "rtwtypes.h"
#include "simtarget/slSimTgtClientServerAPIBridge.h"
#include "sfrtif/sfc_sdi.h"
#include "sfrtif/sf_test_language.h"
#include "simlogCIntrf.h"
#include "half_type.h"
#include "multiword_types.h"
#include "sfrtif/sfc_messages.h"
#include "slccrt.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"
#include "mwstringutil.h"
#include "blas.h"
#include "lapacke.h"
#include "sfvdled1qd8b1FV1BoP4B1.h"
#include "libmwbwdistEDT_tbb.h"

#define rtInf (mxGetInf())
#define rtMinusInf (-(mxGetInf()))
#define rtNaN (mxGetNaN())
#define rtInfF ((real32_T)mxGetInf())
#define rtMinusInfF (-(real32_T)mxGetInf())
#define rtNaNF ((real32_T)mxGetNaN())
#define rtIsNaN(X) ((int)mxIsNaN(X))
#define rtIsInf(X) ((int)mxIsInf(X))
#ifdef utFree
#undef utFree
#endif
#ifdef utMalloc
#undef utMalloc
#endif
#ifdef __cplusplus
extern "C" void* utMalloc(size_t size);
extern "C" void utFree(void*);
#else
extern void* utMalloc(size_t size);
extern void utFree(void*);
#endif


/* Type Definitions */
#ifndef c5_struct_c5_tag_sGaAmWJmK5HvPUvd2k3PkCG
#define c5_struct_c5_tag_sGaAmWJmK5HvPUvd2k3PkCG
struct c5_tag_sGaAmWJmK5HvPUvd2k3PkCG
{
    uint32_T nanflag;
    uint32_T ComparisonMethod;
};
#endif /* c5_struct_c5_tag_sGaAmWJmK5HvPUvd2k3PkCG */
#ifndef c5_typedef_c5_sGaAmWJmK5HvPUvd2k3PkCG
#define c5_typedef_c5_sGaAmWJmK5HvPUvd2k3PkCG
typedef struct c5_tag_sGaAmWJmK5HvPUvd2k3PkCG c5_sGaAmWJmK5HvPUvd2k3PkCG;
#endif /* c5_typedef_c5_sGaAmWJmK5HvPUvd2k3PkCG */
#ifndef c5_struct_c5_tag_smzGQHcQ1fZcSCW5rtLpn4F
#define c5_struct_c5_tag_smzGQHcQ1fZcSCW5rtLpn4F
struct c5_tag_smzGQHcQ1fZcSCW5rtLpn4F
{
    boolean_T CaseSensitivity;
    char_T PartialMatching[6];
    boolean_T StructExpand;
    boolean_T IgnoreNulls;
    boolean_T SupportOverrides;
};
#endif /* c5_struct_c5_tag_smzGQHcQ1fZcSCW5rtLpn4F */
#ifndef c5_typedef_c5_smzGQHcQ1fZcSCW5rtLpn4F
#define c5_typedef_c5_smzGQHcQ1fZcSCW5rtLpn4F
typedef struct c5_tag_smzGQHcQ1fZcSCW5rtLpn4F c5_smzGQHcQ1fZcSCW5rtLpn4F;
#endif /* c5_typedef_c5_smzGQHcQ1fZcSCW5rtLpn4F */
#ifndef c5_struct_c5_tag_a7TcNrdk5JZcy5uxGijaRG
#define c5_struct_c5_tag_a7TcNrdk5JZcy5uxGijaRG
struct c5_tag_a7TcNrdk5JZcy5uxGijaRG
{
    char_T f1[7];
    char_T f2[7];
};
#endif /* c5_struct_c5_tag_a7TcNrdk5JZcy5uxGijaRG */
#ifndef c5_typedef_c5_s_a7TcNrdk5JZcy5uxGijaRG
#define c5_typedef_c5_s_a7TcNrdk5JZcy5uxGijaRG
typedef struct c5_tag_a7TcNrdk5JZcy5uxGijaRG c5_s_a7TcNrdk5JZcy5uxGijaRG;
#endif /* c5_typedef_c5_s_a7TcNrdk5JZcy5uxGijaRG */
#ifndef c5_struct_c5_tag_hM979dQXCkO61ucestBfRE
#define c5_struct_c5_tag_hM979dQXCkO61ucestBfRE
struct c5_tag_hM979dQXCkO61ucestBfRE
{
    char_T f1[9];
    char_T f2[4];
};
#endif /* c5_struct_c5_tag_hM979dQXCkO61ucestBfRE */
#ifndef c5_typedef_c5_cell_1
#define c5_typedef_c5_cell_1
typedef struct c5_tag_hM979dQXCkO61ucestBfRE c5_cell_1;
#endif /* c5_typedef_c5_cell_1 */
#ifndef c5_struct_c5_tag_da2ldybm1RET4Gj5wcYfMF
#define c5_struct_c5_tag_da2ldybm1RET4Gj5wcYfMF
struct c5_tag_da2ldybm1RET4Gj5wcYfMF
{
    char_T f1[9];
    char_T f2[9];
    char_T f3[10];
    char_T f4[15];
};
#endif /* c5_struct_c5_tag_da2ldybm1RET4Gj5wcYfMF */
#ifndef c5_typedef_c5_cell_2
#define c5_typedef_c5_cell_2
typedef struct c5_tag_da2ldybm1RET4Gj5wcYfMF c5_cell_2;
#endif /* c5_typedef_c5_cell_2 */
#ifndef c5_struct_c5_tag_L5JvjW1A13FyCQi5N783sB
#define c5_struct_c5_tag_L5JvjW1A13FyCQi5N783sB
struct c5_tag_L5JvjW1A13FyCQi5N783sB
{
    char_T f1[7];
};
#endif /* c5_struct_c5_tag_L5JvjW1A13FyCQi5N783sB */
#ifndef c5_typedef_c5_cell_wrap_0
#define c5_typedef_c5_cell_wrap_0
typedef struct c5_tag_L5JvjW1A13FyCQi5N783sB c5_cell_wrap_0;
#endif /* c5_typedef_c5_cell_wrap_0 */
#ifndef c5_struct_c5_tag_6jR4RtbHdjyG00WYqgD5nF
#define c5_struct_c5_tag_6jR4RtbHdjyG00WYqgD5nF
struct c5_tag_6jR4RtbHdjyG00WYqgD5nF
{
    char_T f1[16];
};
#endif /* c5_struct_c5_tag_6jR4RtbHdjyG00WYqgD5nF */
#ifndef c5_typedef_c5_cell_wrap_3
#define c5_typedef_c5_cell_wrap_3
typedef struct c5_tag_6jR4RtbHdjyG00WYqgD5nF c5_cell_wrap_3;
#endif /* c5_typedef_c5_cell_wrap_3 */
#ifndef c5_struct_c5_tag_njgfiHhWBCqqqpWsKZxr7F
#define c5_struct_c5_tag_njgfiHhWBCqqqpWsKZxr7F
struct c5_tag_njgfiHhWBCqqqpWsKZxr7F
{
    char_T f1[15];
    char_T f2[15];
    char_T f3[12];
    char_T f4[11];
    char_T f5[16];
};
#endif /* c5_struct_c5_tag_njgfiHhWBCqqqpWsKZxr7F */
#ifndef c5_typedef_c5_cell_4
#define c5_typedef_c5_cell_4
typedef struct c5_tag_njgfiHhWBCqqqpWsKZxr7F c5_cell_4;
#endif /* c5_typedef_c5_cell_4 */
#ifndef c5_struct_c5_tag_tP4ysjhyvuYk36JuHDg8bD
#define c5_struct_c5_tag_tP4ysjhyvuYk36JuHDg8bD
struct c5_tag_tP4ysjhyvuYk36JuHDg8bD
{
    c5_s_a7TcNrdk5JZcy5uxGijaRG _data;
};
#endif /* c5_struct_c5_tag_tP4ysjhyvuYk36JuHDg8bD */
#ifndef c5_typedef_c5_s_tP4ysjhyvuYk36JuHDg8bD
#define c5_typedef_c5_s_tP4ysjhyvuYk36JuHDg8bD
typedef struct c5_tag_tP4ysjhyvuYk36JuHDg8bD c5_s_tP4ysjhyvuYk36JuHDg8bD;
#endif /* c5_typedef_c5_s_tP4ysjhyvuYk36JuHDg8bD */
#ifndef c5_struct_c5_tag_DW0cc1HShF0YblMAW5lXf
#define c5_struct_c5_tag_DW0cc1HShF0YblMAW5lXf
struct c5_tag_DW0cc1HShF0YblMAW5lXf
{
    c5_cell_1 _data;
};
#endif /* c5_struct_c5_tag_DW0cc1HShF0YblMAW5lXf */
#ifndef c5_typedef_c5_s_DW0cc1HShF0YblMAW5lXf
#define c5_typedef_c5_s_DW0cc1HShF0YblMAW5lXf
typedef struct c5_tag_DW0cc1HShF0YblMAW5lXf c5_s_DW0cc1HShF0YblMAW5lXf;
#endif /* c5_typedef_c5_s_DW0cc1HShF0YblMAW5lXf */
#ifndef c5_struct_c5_tag_4dKvvM1PltKbfMfZauPBNB
#define c5_struct_c5_tag_4dKvvM1PltKbfMfZauPBNB
struct c5_tag_4dKvvM1PltKbfMfZauPBNB
{
    c5_cell_2 _data;
};
#endif /* c5_struct_c5_tag_4dKvvM1PltKbfMfZauPBNB */
#ifndef c5_typedef_c5_s_4dKvvM1PltKbfMfZauPBNB
#define c5_typedef_c5_s_4dKvvM1PltKbfMfZauPBNB
typedef struct c5_tag_4dKvvM1PltKbfMfZauPBNB c5_s_4dKvvM1PltKbfMfZauPBNB;
#endif /* c5_typedef_c5_s_4dKvvM1PltKbfMfZauPBNB */
#ifndef c5_struct_c5_tag_HOps0FrfA6RiWumqewPwZD
#define c5_struct_c5_tag_HOps0FrfA6RiWumqewPwZD
struct c5_tag_HOps0FrfA6RiWumqewPwZD
{
    c5_cell_wrap_0 _data;
};
#endif /* c5_struct_c5_tag_HOps0FrfA6RiWumqewPwZD */
#ifndef c5_typedef_c5_s_HOps0FrfA6RiWumqewPwZD
#define c5_typedef_c5_s_HOps0FrfA6RiWumqewPwZD
typedef struct c5_tag_HOps0FrfA6RiWumqewPwZD c5_s_HOps0FrfA6RiWumqewPwZD;
#endif /* c5_typedef_c5_s_HOps0FrfA6RiWumqewPwZD */
#ifndef c5_struct_c5_tag_1nlLkVeIuST25DF6il3ApD
#define c5_struct_c5_tag_1nlLkVeIuST25DF6il3ApD
struct c5_tag_1nlLkVeIuST25DF6il3ApD
{
    c5_cell_wrap_3 _data;
};
#endif /* c5_struct_c5_tag_1nlLkVeIuST25DF6il3ApD */
#ifndef c5_typedef_c5_s_1nlLkVeIuST25DF6il3ApD
#define c5_typedef_c5_s_1nlLkVeIuST25DF6il3ApD
typedef struct c5_tag_1nlLkVeIuST25DF6il3ApD c5_s_1nlLkVeIuST25DF6il3ApD;
#endif /* c5_typedef_c5_s_1nlLkVeIuST25DF6il3ApD */
#ifndef c5_struct_c5_tag_uzuPWHtc1cM7ZRTfbsKeiF
#define c5_struct_c5_tag_uzuPWHtc1cM7ZRTfbsKeiF
struct c5_tag_uzuPWHtc1cM7ZRTfbsKeiF
{
    c5_cell_4 _data;
};
#endif /* c5_struct_c5_tag_uzuPWHtc1cM7ZRTfbsKeiF */
#ifndef c5_typedef_c5_s_uzuPWHtc1cM7ZRTfbsKeiF
#define c5_typedef_c5_s_uzuPWHtc1cM7ZRTfbsKeiF
typedef struct c5_tag_uzuPWHtc1cM7ZRTfbsKeiF c5_s_uzuPWHtc1cM7ZRTfbsKeiF;
#endif /* c5_typedef_c5_s_uzuPWHtc1cM7ZRTfbsKeiF */

/* Named Constants */
#define CALL_EVENT (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void initialize_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    emlrtStack c5_st = { NULL,     /* site */
NULL,     /* tls */
NULL    /* prev */
 };
    c5_st.tls = ptr_gvar_instance->c5_fEmlrtCtx;
    emlrtLicenseCheckR2022a(&c5_st, "EMLRT:runTime:MexFunctionNeedsLicense", "image_toolbox", 2);
    sim_mode_is_external(S);
    sf_get_time(S);
}

void initialize_params_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void mdl_start_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)ptr_gvar_instance;
    sim_mode_is_external(S);
}

void mdl_terminate_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void mdl_setup_runtime_resources_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    sfSetAnimationVectors(S, &ptr_gvar_instance->c5_JITStateAnimation[0], &ptr_gvar_instance->c5_JITTransitionAnimation[0]);
}

void mdl_cleanup_runtime_resources_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void enable_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)ptr_gvar_instance;
    sf_get_time(S);
}

void disable_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)ptr_gvar_instance;
    sf_get_time(S);
}

void sf_gateway_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    static char_T c5_varargin_1[20] = { 'W', 'a', 'y', 'p', 'o', 'i', 'n', 't', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', '3', 'x', '1' };
    emlrtStack c5_b_st;
    emlrtStack c5_st = { NULL,     /* site */
NULL,     /* tls */
NULL    /* prev */
 };
    const mxArray *c5_y = NULL;
    c5_st.tls = ptr_gvar_instance->c5_fEmlrtCtx;
    c5_b_st.prev = &c5_st;
    c5_b_st.tls = c5_st.tls;
    sf_get_time(S);
    ptr_gvar_instance->c5_JITTransitionAnimation[0] = 0U;
    c5_b_st.site = &ptr_gvar_instance->c5_emlrtRSI;
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_varargin_1, 10, 0U, 1, 0U, 2, 1, 20), false);
    sf_mex_call(&c5_b_st, &ptr_gvar_instance->c5_emlrtMCI, "error", 0U, 1U, 14, c5_y);
}

void ext_mode_exec_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

const mxArray *get_sim_state_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    const mxArray *c5_b_y = NULL;
    const mxArray *c5_st = NULL;
    const mxArray *c5_y = NULL;
    (void)S;
    c5_st = NULL;
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_createcellmatrix(1, 1), false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", *ptr_gvar_instance->c5_global_cost_map, 0, 0U, 1, 0U, 2, 82, 104), false);
    sf_mex_setcell(c5_y, 0, c5_b_y);
    sf_mex_assign(&c5_st, c5_y, false);
    return c5_st;
}

void set_sim_state_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c5_st)
{
    const mxArray *c5_u;
    real_T c5_b[8528];
    int32_T c5_c;
    c5_u = sf_mex_dup(c5_st);
    c5_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "global_cost_map", c5_b);
    for (c5_c = 0; c5_c < 8528; c5_c++) {
        (*ptr_gvar_instance->c5_global_cost_map)[c5_c] = c5_b[c5_c];
    }
    sf_mex_destroy(&c5_u);
    sf_mex_destroy(&c5_st);
}

void c5_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c5_nullptr, const char_T *c5_identifier, real_T c5_y[8528])
{
    emlrtMsgIdentifier c5_thisId;
    c5_thisId.fIdentifier = (const char_T *)c5_identifier;
    c5_thisId.fParent = NULL;
    c5_thisId.bParentIsCell = false;
    c5_b_emlrt_marshallIn(S, ptr_gvar_instance, sf_mex_dup(c5_nullptr), &c5_thisId, c5_y);
    sf_mex_destroy(&c5_nullptr);
}

void c5_b_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[8528])
{
    real_T c5_b[8528];
    int32_T c5_c;
    (void)S;
    (void)ptr_gvar_instance;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_b, 1, 0, 0U, 1, 0U, 2, 82, 104);
    for (c5_c = 0; c5_c < 8528; c5_c++) {
        c5_y[c5_c] = c5_b[c5_c];
    }
    sf_mex_destroy(&c5_u);
}

void init_dsm_address_info(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    (void)S;
    (void)ptr_gvar_instance;
}

void init_simulink_io_address(SimStruct *S, gvar_instance *ptr_gvar_instance)
{
    ptr_gvar_instance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(S);
    ptr_gvar_instance->c5_map = (real_T (*)[8528])ssGetInputPortSignal_wrapper(S, 0);
    ptr_gvar_instance->c5_global_cost_map = (real_T (*)[8528])ssGetOutputPortSignal_wrapper(S, 1);
    ptr_gvar_instance->c5_pose = (real_T (*)[3])ssGetInputPortSignal_wrapper(S, 1);
    ptr_gvar_instance->c5_waypoint = (real_T (*)[2])ssGetInputPortSignal_wrapper(S, 2);
    ptr_gvar_instance->c5_show_map = (real_T *)ssGetInputPortSignal_wrapper(S, 3);
}

void JIT_release_mem_fcn(gvar_instance *ptr_gvar_instance)
{
    free(ptr_gvar_instance);
}

gvar_instance *JIT_init_mem_fcn(void)
{
    gvar_instance *ptr_gvar_instance;
    ptr_gvar_instance = (gvar_instance *)calloc((size_t)1U, sizeof(gvar_instance));
    ptr_gvar_instance->c5_b_emlrtMCI.lineNo = 13;
    ptr_gvar_instance->c5_b_emlrtMCI.colNo = 9;
    ptr_gvar_instance->c5_b_emlrtMCI.fName = "sqrt";
    ptr_gvar_instance->c5_b_emlrtMCI.pName = "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m";
    ptr_gvar_instance->c5_b_emlrtRSI.lineNo = 98;
    ptr_gvar_instance->c5_b_emlrtRSI.fcnName = "bwdist";
    ptr_gvar_instance->c5_b_emlrtRSI.pathName = "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\bwdist.m";
    ptr_gvar_instance->c5_c_emlrtMCI.lineNo = 87;
    ptr_gvar_instance->c5_c_emlrtMCI.colNo = 33;
    ptr_gvar_instance->c5_c_emlrtMCI.fName = "eml_int_forloop_overflow_check";
    ptr_gvar_instance->c5_c_emlrtMCI.pName = "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m";
    ptr_gvar_instance->c5_c_emlrtRSI.lineNo = 101;
    ptr_gvar_instance->c5_c_emlrtRSI.fcnName = "bwdist";
    ptr_gvar_instance->c5_c_emlrtRSI.pathName = "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\bwdist.m";
    ptr_gvar_instance->c5_d_emlrtMCI.lineNo = 13;
    ptr_gvar_instance->c5_d_emlrtMCI.colNo = 13;
    ptr_gvar_instance->c5_d_emlrtMCI.fName = "toLogicalCheck";
    ptr_gvar_instance->c5_d_emlrtMCI.pName = "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m";
    ptr_gvar_instance->c5_emlrtMCI.lineNo = 27;
    ptr_gvar_instance->c5_emlrtMCI.colNo = 5;
    ptr_gvar_instance->c5_emlrtMCI.fName = "error";
    ptr_gvar_instance->c5_emlrtMCI.pName = "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\lang\\error.m";
    ptr_gvar_instance->c5_emlrtRSI.lineNo = 32;
    ptr_gvar_instance->c5_emlrtRSI.fcnName = "MATLAB Function2";
    ptr_gvar_instance->c5_emlrtRSI.pathName = "#sl_groundvehicleDynamics_test:6433";
    return ptr_gvar_instance;
}


