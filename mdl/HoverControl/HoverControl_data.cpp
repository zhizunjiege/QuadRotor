/*
 * HoverControl_data.cpp
 *
 * Code generation for model "HoverControl".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sat Mar 12 14:03:04 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HoverControl.h"
#include "HoverControl_private.h"

/* Block parameters (default storage) */
P_HoverControl_T HoverControlModelClass::HoverControl_P = {
    /* Mask Parameter: XController_InitialConditionFor
     * Referenced by: '<S31>/Filter'
     */
    0.0,

    /* Mask Parameter: YController_InitialConditionFor
     * Referenced by: '<S79>/Filter'
     */
    0.0,

    /* Mask Parameter: ZController_InitialConditionFor
     * Referenced by: '<S127>/Filter'
     */
    0.0,

    /* Mask Parameter: XController_InitialConditionF_k
     * Referenced by: '<S36>/Integrator'
     */
    0.0,

    /* Mask Parameter: YController_InitialConditionF_h
     * Referenced by: '<S84>/Integrator'
     */
    0.0,

    /* Mask Parameter: ZController_InitialConditionF_k
     * Referenced by: '<S132>/Integrator'
     */
    0.0,

    /* Expression: 100
     * Referenced by: '<S1>/Constant'
     */
    100.0};
