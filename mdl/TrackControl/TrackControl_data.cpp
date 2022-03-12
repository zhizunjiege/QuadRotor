/*
 * TrackControl_data.cpp
 *
 * Code generation for model "TrackControl".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sat Mar 12 10:27:31 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrackControl.h"
#include "TrackControl_private.h"

/* Block parameters (default storage) */
P_TrackControl_T TrackControlModelClass::TrackControl_P = {
  /* Variable: pid_limit
   * Referenced by:
   *   '<S47>/Saturation'
   *   '<S95>/Saturation'
   *   '<S192>/Saturation'
   *   '<S240>/Saturation'
   *   '<S288>/Saturation'
   *   '<S144>/Saturation'
   */
  1.0E+6,

  /* Mask Parameter: ect_x_InitialConditionForFilter
   * Referenced by: '<S180>/Filter'
   */
  0.0,

  /* Mask Parameter: eat_x_InitialConditionForFilter
   * Referenced by: '<S35>/Filter'
   */
  0.0,

  /* Mask Parameter: ect_y_InitialConditionForFilter
   * Referenced by: '<S228>/Filter'
   */
  0.0,

  /* Mask Parameter: eat_y_InitialConditionForFilter
   * Referenced by: '<S83>/Filter'
   */
  0.0,

  /* Mask Parameter: ect_z_InitialConditionForFilter
   * Referenced by: '<S276>/Filter'
   */
  0.0,

  /* Mask Parameter: eat_z_InitialConditionForFilter
   * Referenced by: '<S132>/Filter'
   */
  0.0,

  /* Mask Parameter: ect_x_InitialConditionForIntegr
   * Referenced by: '<S185>/Integrator'
   */
  0.0,

  /* Mask Parameter: eat_x_InitialConditionForIntegr
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: ect_y_InitialConditionForIntegr
   * Referenced by: '<S233>/Integrator'
   */
  0.0,

  /* Mask Parameter: eat_y_InitialConditionForIntegr
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: ect_z_InitialConditionForIntegr
   * Referenced by: '<S281>/Integrator'
   */
  0.0,

  /* Mask Parameter: eat_z_InitialConditionForIntegr
   * Referenced by: '<S137>/Integrator'
   */
  0.0,

  /* Mask Parameter: _InitialCount
   * Referenced by: '<Root>/���μ�����'
   */
  1U,

  /* Expression: 0.0
   * Referenced by: '<Root>/һ���ӳ�'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/��λ'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant'
   */
  100.0
};
