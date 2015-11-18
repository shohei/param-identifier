/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: timerInterrupt.h
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

#ifndef RTW_HEADER_timerInterrupt_h_
#define RTW_HEADER_timerInterrupt_h_
#include "Arduino.h"
#define disable_Timer_Interrupt        TIMSK5 &= ~(1<<TOIE5)
#define enable_Timer_Interrupt         TIMSK5 |= (1<<TOIE5)
#endif                                 /* RTW_HEADER_timerInterrupt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
