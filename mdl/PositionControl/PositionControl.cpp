/*
 * PositionControl.cpp
 *
 * Code generation for model "PositionControl".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sat Mar 12 11:50:29 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PositionControl.h"
#include "PositionControl_private.h"

/*
 * Output and update for atomic system:
 *    '<Root>/饱和函数_pitch'
 *    '<Root>/饱和函数_roll'
 */
void PositionControlModelClass::PositionControl__pitch(real_T rtu_x, real_T
  rtu_limit, B__pitch_PositionControl_T *localB)
{
  if (rtu_x > rtu_limit) {
    localB->x_sat = rtu_limit;
  } else if (rtu_x < -rtu_limit) {
    localB->x_sat = -rtu_limit;
  } else {
    localB->x_sat = rtu_x;
  }
}

/* Model step function */
void PositionControlModelClass::step()
{
  /* Outport: '<Root>/delta_omega_F' incorporates:
   *  Inport: '<Root>/az'
   *  Inport: '<Root>/az_gain'
   *  Product: '<Root>/Product'
   */
  PositionControl_Y.delta_omega_F = PositionControl_U.az *
    PositionControl_U.az_gain;

  /* MATLAB Function: '<Root>/饱和函数_roll' incorporates:
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/des_yaw'
   *  Inport: '<Root>/roll_pitch_limit'
   *  MATLAB Function: '<Root>/交叉函数'
   */
  PositionControl__pitch(-0.1020408163265306 * (PositionControl_U.ax * std::sin
    (PositionControl_U.des_yaw) - PositionControl_U.ay * std::cos
    (PositionControl_U.des_yaw)), PositionControl_U.roll_pitch_limit,
    &PositionControl_B.sf__roll);

  /* Outport: '<Root>/des_Roll' */
  PositionControl_Y.des_Roll = PositionControl_B.sf__roll.x_sat;

  /* MATLAB Function: '<Root>/饱和函数_pitch' incorporates:
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/des_yaw'
   *  Inport: '<Root>/roll_pitch_limit'
   *  MATLAB Function: '<Root>/交叉函数'
   */
  PositionControl__pitch(-0.1020408163265306 * (PositionControl_U.ax * std::cos
    (PositionControl_U.des_yaw) + PositionControl_U.ay * std::sin
    (PositionControl_U.des_yaw)), PositionControl_U.roll_pitch_limit,
    &PositionControl_B.sf__pitch);

  /* Outport: '<Root>/des_Pitch' */
  PositionControl_Y.des_Pitch = PositionControl_B.sf__pitch.x_sat;
}

/* Model initialize function */
void PositionControlModelClass::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void PositionControlModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
PositionControlModelClass::PositionControlModelClass():
  PositionControl_B()
  ,PositionControl_U()
  ,PositionControl_Y()
  ,PositionControl_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
PositionControlModelClass::~PositionControlModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_PositionControl_T * PositionControlModelClass::getRTM()
{
  return (&PositionControl_M);
}
