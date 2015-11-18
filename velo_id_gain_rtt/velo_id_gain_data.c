/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_id_gain_data.c
 *
 * Code generated for Simulink model 'velo_id_gain'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Nov 18 22:39:12 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "velo_id_gain.h"
#include "velo_id_gain_private.h"

/* Block parameters (auto storage) */
P_velo_id_gain_T velo_id_gain_P = {
  1.5,                                 /* Variable: u_ini
                                        * Referenced by: '<Root>/Constant1'
                                        */
  2.5,                                 /* Variable: u_ref
                                        * Referenced by: '<Root>/Constant'
                                        */
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  51.0,                                /* Expression: 255/5
                                        * Referenced by: '<S1>/Gain1'
                                        */
  5U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  41000U                               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
