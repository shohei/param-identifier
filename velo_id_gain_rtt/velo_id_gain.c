/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_id_gain.c
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
#include "velo_id_gain_dt.h"

/* Block signals (auto storage) */
B_velo_id_gain_T velo_id_gain_B;

/* Block states (auto storage) */
DW_velo_id_gain_T velo_id_gain_DW;

/* Real-time model */
RT_MODEL_velo_id_gain_T velo_id_gain_M_;
RT_MODEL_velo_id_gain_T *const velo_id_gain_M = &velo_id_gain_M_;

/* Model output function */
void velo_id_gain_output(void)
{
  uint16_T rtb_AnalogInput_0;
  real_T rtb_Gain1;

  /* Step: '<Root>/Step' */
  if (velo_id_gain_M->Timing.t[0] < velo_id_gain_P.Step_Time) {
    rtb_Gain1 = velo_id_gain_P.Step_Y0;
  } else {
    rtb_Gain1 = velo_id_gain_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (rtb_Gain1 > velo_id_gain_P.Switch_Threshold) {
    rtb_Gain1 = velo_id_gain_P.u_ref;
  } else {
    rtb_Gain1 = velo_id_gain_P.u_ini;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  velo_id_gain_B.VectorConcatenate[0] = rtb_Gain1;

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(velo_id_gain_P.AnalogInput_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Gain: '<S1>/Gain'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
   */
  velo_id_gain_B.VectorConcatenate[1] = (real_T)((uint32_T)
    velo_id_gain_P.Gain_Gain * rtb_AnalogInput_0) * 1.1920928955078125E-7;

  /* Gain: '<S1>/Gain1' */
  rtb_Gain1 *= velo_id_gain_P.Gain1_Gain;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_Gain1 < 256.0) {
    if (rtb_Gain1 >= 0.0) {
      velo_id_gain_B.DataTypeConversion = (uint8_T)rtb_Gain1;
    } else {
      velo_id_gain_B.DataTypeConversion = 0U;
    }
  } else {
    velo_id_gain_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(velo_id_gain_P.PWM_pinNumber, velo_id_gain_B.DataTypeConversion);
}

/* Model update function */
void velo_id_gain_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(velo_id_gain_M)!=-1) &&
        !((rtmGetTFinal(velo_id_gain_M)-velo_id_gain_M->Timing.t[0]) >
          velo_id_gain_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(velo_id_gain_M, "Simulation finished");
    }

    if (rtmGetStopRequested(velo_id_gain_M)) {
      rtmSetErrorStatus(velo_id_gain_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  velo_id_gain_M->Timing.t[0] =
    (++velo_id_gain_M->Timing.clockTick0) * velo_id_gain_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    velo_id_gain_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void velo_id_gain_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)velo_id_gain_M, 0,
                sizeof(RT_MODEL_velo_id_gain_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&velo_id_gain_M->solverInfo,
                          &velo_id_gain_M->Timing.simTimeStep);
    rtsiSetTPtr(&velo_id_gain_M->solverInfo, &rtmGetTPtr(velo_id_gain_M));
    rtsiSetStepSizePtr(&velo_id_gain_M->solverInfo,
                       &velo_id_gain_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&velo_id_gain_M->solverInfo, (&rtmGetErrorStatus
      (velo_id_gain_M)));
    rtsiSetRTModelPtr(&velo_id_gain_M->solverInfo, velo_id_gain_M);
  }

  rtsiSetSimTimeStep(&velo_id_gain_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&velo_id_gain_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(velo_id_gain_M, &velo_id_gain_M->Timing.tArray[0]);
  rtmSetTFinal(velo_id_gain_M, 5.0);
  velo_id_gain_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  velo_id_gain_M->Sizes.checksums[0] = (1795816491U);
  velo_id_gain_M->Sizes.checksums[1] = (2818471415U);
  velo_id_gain_M->Sizes.checksums[2] = (1756905730U);
  velo_id_gain_M->Sizes.checksums[3] = (962554928U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    velo_id_gain_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(velo_id_gain_M->extModeInfo,
      &velo_id_gain_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(velo_id_gain_M->extModeInfo,
                        velo_id_gain_M->Sizes.checksums);
    rteiSetTPtr(velo_id_gain_M->extModeInfo, rtmGetTPtr(velo_id_gain_M));
  }

  /* block I/O */
  (void) memset(((void *) &velo_id_gain_B), 0,
                sizeof(B_velo_id_gain_T));

  /* states (dwork) */
  (void) memset((void *)&velo_id_gain_DW, 0,
                sizeof(DW_velo_id_gain_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    velo_id_gain_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(velo_id_gain_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(velo_id_gain_P.PWM_pinNumber);
}

/* Model terminate function */
void velo_id_gain_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
