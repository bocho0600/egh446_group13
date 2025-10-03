#pragma once

#ifdef __cplusplus
#define EXTERN_C_CC extern "C"
#else
#define EXTERN_C_CC
#endif

#if defined _WIN32
#define DLL_EXPORT_CC EXTERN_C_CC __declspec(dllexport)
#elif __GNUC__ >= 4
#define DLL_EXPORT_CC EXTERN_C_CC  __attribute__ ((visibility ("default")))
#else
#define DLL_EXPORT_CC EXTERN_C_CC
#endif


/* Type Definitions */
#ifndef typedef_gvar_instance
#define typedef_gvar_instance
typedef struct
{
    uint8_T c5_JITStateAnimation[1];
    real_T (*c5_map)[8528];
    real_T (*c5_global_cost_map)[8528];
    real_T (*c5_pose)[3];
    real_T *c5_show_map;
    real_T (*c5_waypoint)[2];
    uint8_T c5_JITTransitionAnimation[1];
    emlrtMCInfo c5_b_emlrtMCI;
    emlrtRSInfo c5_b_emlrtRSI;
    emlrtMCInfo c5_c_emlrtMCI;
    emlrtRSInfo c5_c_emlrtRSI;
    emlrtMCInfo c5_d_emlrtMCI;
    emlrtMCInfo c5_emlrtMCI;
    emlrtRSInfo c5_emlrtRSI;
    void *c5_fEmlrtCtx;
} gvar_instance;
#endif /* typedef_gvar_instance */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC void initialize_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void initialize_params_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_start_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_terminate_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_setup_runtime_resources_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void mdl_cleanup_runtime_resources_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void enable_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void disable_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void sf_gateway_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void ext_mode_exec_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC const mxArray *get_sim_state_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void set_sim_state_c5_sl_groundvehicleDynamics_test(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c5_st);
DLL_EXPORT_CC void c5_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c5_nullptr, const char_T *c5_identifier, real_T c5_y[8528]);
DLL_EXPORT_CC void c5_b_emlrt_marshallIn(SimStruct *S, gvar_instance *ptr_gvar_instance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[8528]);
DLL_EXPORT_CC void init_dsm_address_info(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void init_simulink_io_address(SimStruct *S, gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC void JIT_release_mem_fcn(gvar_instance *ptr_gvar_instance);
DLL_EXPORT_CC gvar_instance *JIT_init_mem_fcn(void);

/* Function Definitions */

