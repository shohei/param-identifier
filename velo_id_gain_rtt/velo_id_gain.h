/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_id_gain.h
 *
 * Code generated for Simulink model 'velo_id_gain'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Nov 18 22:33:04 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_velo_id_gain_h_
#define RTW_HEADER_velo_id_gain_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef velo_id_gain_COMMON_INCLUDES_
# define velo_id_gain_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* velo_id_gain_COMMON_INCLUDES_ */

#include "velo_id_gain_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T VectorConcatenate[2];         /* '<S1>/Vector Concatenate' */
  uint8_T DataTypeConversion;          /* '<S2>/Data Type Conversion' */
} B_velo_id_gain_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_velo_id_gain_T;

/* Parameters (auto storage) */
struct P_velo_id_gain_T_ {
  real_T u_ini;                        /* Variable: u_ini
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T u_ref;                        /* Variable: u_ref
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/5
                                        * Referenced by: '<S1>/Gain1'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_velo_id_gain_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_velo_id_gain_T velo_id_gain_P;

/* Block signals (auto storage) */
extern B_velo_id_gain_T velo_id_gain_B;

/* Block states (auto storage) */
extern DW_velo_id_gain_T velo_id_gain_DW;

/* Model entry point functions */
extern void velo_id_gain_initialize(void);
extern void velo_id_gain_output(void);
extern void velo_id_gain_update(void);
extern void velo_id_gain_terminate(void);

/* Real-time Model object */
extern RT_MODEL_velo_id_gain_T *const velo_id_gain_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'velo_id_gain'
 * '<S1>'   : 'velo_id_gain/MOTOR '
 * '<S2>'   : 'velo_id_gain/MOTOR /PWM'
 */
#endif                                 /* RTW_HEADER_velo_id_gain_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
