/*
 * AttitudeControl_data.cpp
 *
 * Code generation for model "AttitudeControl".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sat Mar 12 12:22:29 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AttitudeControl.h"
#include "AttitudeControl_private.h"

/* Block parameters (default storage) */
P_AttitudeControl_T AttitudeControlModelClass::AttitudeControl_P = {
  /* Mask Parameter: RollController_InitialCondition
   * Referenced by: '<S79>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchController_InitialConditio
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: YawController_InitialConditionF
   * Referenced by: '<S127>/Filter'
   */
  0.0,

  /* Mask Parameter: RollController_InitialConditi_f
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchController_InitialCondit_d
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: YawController_InitialConditio_h
   * Referenced by: '<S132>/Integrator'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Constant'
   */
  100.0,

  /* Expression: [1 0 1 -1;1 1 0 1;1 0 -1 -1;1 -1 0 1]
   * Referenced by: '<Root>/Gain'
   */
  { 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, -1.0, 0.0, -1.0, 1.0,
    -1.0, 1.0 }
};
