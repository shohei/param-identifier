/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "Arduino.h"
#include "io_wrappers.h"
#include <ext_work.h>                  /* External mode header files */
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
#define INIT_TIMER_VAL                 64911
#define SETUP_PRESCALER                TCCR5B |= ((1<<CS52)); TCCR5B &= ~((1<<CS51) | (1<<CS50))
#define INTERRUPT_VECTOR               TIMER5_OVF_vect
#define DISABLE_TIMER                  TIMSK5 &= ~(1<<TOIE5)
#define ENABLE_TIMER                   TIMSK5 |= (1<<TOIE5)
#define TIMER_NORMAL_MODE              TCCR5A &= ~((1<<WGM51) | (1<<WGM50)); TCCR5B &= ~((1<<WGM53) | (1<<WGM52))
#define RESET_TIMER                    TCNT5 = INIT_TIMER_VAL

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

/*
 * The timer interrupt handler (gets invoked on every counter overflow).
 */
ISR(INTERRUPT_VECTOR)
{
  RESET_TIMER;
  rt_OneStep();
}

/*
 * Configures the base rate interrupt timer
 */
static void arduino_Timer_Setup()
{
  // Sets up the timer overflow interrupt.
  RESET_TIMER;

  // Initially disable the overflow interrupt (before configuration).
  DISABLE_TIMER;

  // Set the timer to normal mode.
  TIMER_NORMAL_MODE;

  // Set the prescaler.
  SETUP_PRESCALER;

  // Everything configured, so enable the overflow interrupt.
  ENABLE_TIMER;
}

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  sei();

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  velo_id_gain_output();

  /* Get model outputs here */

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, velo_id_gain_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, ((velo_id_gain_M->Timing.clockTick1) * 0.01));
  }

  velo_id_gain_update();
  cli();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    sei();
    switch (1) {
     default:
      break;
    }

    cli();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

int_T main(void)
{
  init();

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 9600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 9600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 9600);

#endif

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  velo_id_gain_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(velo_id_gain_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(velo_id_gain_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(velo_id_gain_M, true);
    }
  }

  rtERTExtModeStartMsg();
  arduino_Timer_Setup();

  /* The main step loop */
  while ((rtmGetErrorStatus(velo_id_gain_M) == (NULL)) && !rtmGetStopRequested
         (velo_id_gain_M)) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(velo_id_gain_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(velo_id_gain_M, true);
      }
    }

    rtExtModeCheckEndTrigger();
  }

  rtExtModeShutdown(2);
  delay(1000);
  velo_id_gain_terminate();

  /* Disable Interrupts */
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
