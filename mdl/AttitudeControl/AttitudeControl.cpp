/*
 * AttitudeControl.cpp
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

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void AttitudeControlModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo
  *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AttitudeControl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  AttitudeControl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  AttitudeControl_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void AttitudeControlModelClass::step()
{
  real_T rtb_Sum_m;
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Gain[4];
  int32_T i;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T rtb_Gain_c;
  if (rtmIsMajorTimeStep((&AttitudeControl_M))) {
    /* set solver stop time */
    if (!((&AttitudeControl_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&AttitudeControl_M)->solverInfo,
                            (((&AttitudeControl_M)->Timing.clockTickH0 + 1) *
        (&AttitudeControl_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&AttitudeControl_M)->solverInfo,
                            (((&AttitudeControl_M)->Timing.clockTick0 + 1) *
        (&AttitudeControl_M)->Timing.stepSize0 + (&AttitudeControl_M)
        ->Timing.clockTickH0 * (&AttitudeControl_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&AttitudeControl_M))) {
    (&AttitudeControl_M)->Timing.t[0] = rtsiGetT(&(&AttitudeControl_M)
      ->solverInfo);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/act_Roll'
   *  Inport: '<Root>/des_Roll'
   */
  rtb_Sum_m = AttitudeControl_U.des_Roll - AttitudeControl_U.act_Roll;

  /* Product: '<S87>/NProd Out' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/k_roll_pid'
   *  Integrator: '<S79>/Filter'
   *  Product: '<S78>/DProd Out'
   *  Sum: '<S79>/SumD'
   */
  AttitudeControl_B.NProdOut = (rtb_Sum_m * AttitudeControl_U.k_roll_pid[2] -
    AttitudeControl_X.Filter_CSTATE) * AttitudeControl_P.Constant_Value;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/act_Pitch'
   *  Inport: '<Root>/des_Pitch'
   */
  rtb_Sum1 = AttitudeControl_U.des_Pitch - AttitudeControl_U.act_Pitch;

  /* Product: '<S39>/NProd Out' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/k_pitch_pid'
   *  Integrator: '<S31>/Filter'
   *  Product: '<S30>/DProd Out'
   *  Sum: '<S31>/SumD'
   */
  AttitudeControl_B.NProdOut_d = (rtb_Sum1 * AttitudeControl_U.k_pitch_pid[2] -
    AttitudeControl_X.Filter_CSTATE_f) * AttitudeControl_P.Constant_Value;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Inport: '<Root>/act_Yaw'
   *  Inport: '<Root>/des_Yaw'
   */
  rtb_Sum2 = AttitudeControl_U.des_Yaw - AttitudeControl_U.act_Yaw;

  /* Product: '<S135>/NProd Out' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/k_yaw_pid'
   *  Integrator: '<S127>/Filter'
   *  Product: '<S126>/DProd Out'
   *  Sum: '<S127>/SumD'
   */
  AttitudeControl_B.NProdOut_h = (rtb_Sum2 * AttitudeControl_U.k_yaw_pid[2] -
    AttitudeControl_X.Filter_CSTATE_l) * AttitudeControl_P.Constant_Value;

  /* SignalConversion generated from: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/k_pitch_pid'
   *  Inport: '<Root>/k_roll_pid'
   *  Inport: '<Root>/k_yaw_pid'
   *  Integrator: '<S132>/Integrator'
   *  Integrator: '<S36>/Integrator'
   *  Integrator: '<S84>/Integrator'
   *  Product: '<S137>/PProd Out'
   *  Product: '<S41>/PProd Out'
   *  Product: '<S89>/PProd Out'
   *  Sum: '<S141>/Sum'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S93>/Sum'
   */
  tmp = (rtb_Sum_m * AttitudeControl_U.k_roll_pid[0] +
         AttitudeControl_X.Integrator_CSTATE) + AttitudeControl_B.NProdOut;
  tmp_0 = (rtb_Sum1 * AttitudeControl_U.k_pitch_pid[0] +
           AttitudeControl_X.Integrator_CSTATE_f) + AttitudeControl_B.NProdOut_d;
  tmp_1 = (rtb_Sum2 * AttitudeControl_U.k_yaw_pid[0] +
           AttitudeControl_X.Integrator_CSTATE_fo) +
    AttitudeControl_B.NProdOut_h;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/delta_omega_F'
   */
  for (i = 0; i < 4; i++) {
    rtb_Gain_c = AttitudeControl_P.Gain_Gain[i + 12] * tmp_1 +
      (AttitudeControl_P.Gain_Gain[i + 8] * tmp_0 +
       (AttitudeControl_P.Gain_Gain[i + 4] * tmp + AttitudeControl_P.Gain_Gain[i]
        * AttitudeControl_U.delta_omega_F));
    rtb_Gain[i] = rtb_Gain_c;
  }

  /* End of Gain: '<Root>/Gain' */

  /* Outport: '<Root>/omega1' */
  AttitudeControl_Y.omega1 = rtb_Gain[0];

  /* Outport: '<Root>/omega2' */
  AttitudeControl_Y.omega2 = rtb_Gain[1];

  /* Outport: '<Root>/omega3' */
  AttitudeControl_Y.omega3 = rtb_Gain[2];

  /* Outport: '<Root>/omega4' */
  AttitudeControl_Y.omega4 = rtb_Gain[3];

  /* Product: '<S33>/IProd Out' incorporates:
   *  Inport: '<Root>/k_pitch_pid'
   */
  AttitudeControl_B.IProdOut = rtb_Sum1 * AttitudeControl_U.k_pitch_pid[1];

  /* Product: '<S81>/IProd Out' incorporates:
   *  Inport: '<Root>/k_roll_pid'
   */
  AttitudeControl_B.IProdOut_k = rtb_Sum_m * AttitudeControl_U.k_roll_pid[1];

  /* Product: '<S129>/IProd Out' incorporates:
   *  Inport: '<Root>/k_yaw_pid'
   */
  AttitudeControl_B.IProdOut_g = rtb_Sum2 * AttitudeControl_U.k_yaw_pid[1];
  if (rtmIsMajorTimeStep((&AttitudeControl_M))) {
    rt_ertODEUpdateContinuousStates(&(&AttitudeControl_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&AttitudeControl_M)->Timing.clockTick0)) {
      ++(&AttitudeControl_M)->Timing.clockTickH0;
    }

    (&AttitudeControl_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&AttitudeControl_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&AttitudeControl_M)->Timing.clockTick1++;
      if (!(&AttitudeControl_M)->Timing.clockTick1) {
        (&AttitudeControl_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void AttitudeControlModelClass::AttitudeControl_derivatives()
{
  XDot_AttitudeControl_T *_rtXdot;
  _rtXdot = ((XDot_AttitudeControl_T *) (&AttitudeControl_M)->derivs);

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE = AttitudeControl_B.IProdOut_k;

  /* Derivatives for Integrator: '<S79>/Filter' */
  _rtXdot->Filter_CSTATE = AttitudeControl_B.NProdOut;

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = AttitudeControl_B.IProdOut;

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE_f = AttitudeControl_B.NProdOut_d;

  /* Derivatives for Integrator: '<S132>/Integrator' */
  _rtXdot->Integrator_CSTATE_fo = AttitudeControl_B.IProdOut_g;

  /* Derivatives for Integrator: '<S127>/Filter' */
  _rtXdot->Filter_CSTATE_l = AttitudeControl_B.NProdOut_h;
}

/* Model initialize function */
void AttitudeControlModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&AttitudeControl_M)->solverInfo,
                          &(&AttitudeControl_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&AttitudeControl_M)->solverInfo, &rtmGetTPtr
                ((&AttitudeControl_M)));
    rtsiSetStepSizePtr(&(&AttitudeControl_M)->solverInfo, &(&AttitudeControl_M
                       )->Timing.stepSize0);
    rtsiSetdXPtr(&(&AttitudeControl_M)->solverInfo, &(&AttitudeControl_M)
                 ->derivs);
    rtsiSetContStatesPtr(&(&AttitudeControl_M)->solverInfo, (real_T **)
                         &(&AttitudeControl_M)->contStates);
    rtsiSetNumContStatesPtr(&(&AttitudeControl_M)->solverInfo,
      &(&AttitudeControl_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&AttitudeControl_M)->solverInfo,
      &(&AttitudeControl_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&AttitudeControl_M)->solverInfo,
      &(&AttitudeControl_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&AttitudeControl_M)->solverInfo,
      &(&AttitudeControl_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&AttitudeControl_M)->solverInfo, (&rtmGetErrorStatus
      ((&AttitudeControl_M))));
    rtsiSetRTModelPtr(&(&AttitudeControl_M)->solverInfo, (&AttitudeControl_M));
  }

  rtsiSetSimTimeStep(&(&AttitudeControl_M)->solverInfo, MAJOR_TIME_STEP);
  (&AttitudeControl_M)->intgData.y = (&AttitudeControl_M)->odeY;
  (&AttitudeControl_M)->intgData.f[0] = (&AttitudeControl_M)->odeF[0];
  (&AttitudeControl_M)->intgData.f[1] = (&AttitudeControl_M)->odeF[1];
  (&AttitudeControl_M)->intgData.f[2] = (&AttitudeControl_M)->odeF[2];
  (&AttitudeControl_M)->contStates = ((X_AttitudeControl_T *) &AttitudeControl_X);
  rtsiSetSolverData(&(&AttitudeControl_M)->solverInfo, static_cast<void *>
                    (&(&AttitudeControl_M)->intgData));
  rtsiSetSolverName(&(&AttitudeControl_M)->solverInfo,"ode3");
  rtmSetTPtr((&AttitudeControl_M), &(&AttitudeControl_M)->Timing.tArray[0]);
  (&AttitudeControl_M)->Timing.stepSize0 = 0.01;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  AttitudeControl_X.Integrator_CSTATE =
    AttitudeControl_P.RollController_InitialConditi_f;

  /* InitializeConditions for Integrator: '<S79>/Filter' */
  AttitudeControl_X.Filter_CSTATE =
    AttitudeControl_P.RollController_InitialCondition;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  AttitudeControl_X.Integrator_CSTATE_f =
    AttitudeControl_P.PitchController_InitialCondit_d;

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  AttitudeControl_X.Filter_CSTATE_f =
    AttitudeControl_P.PitchController_InitialConditio;

  /* InitializeConditions for Integrator: '<S132>/Integrator' */
  AttitudeControl_X.Integrator_CSTATE_fo =
    AttitudeControl_P.YawController_InitialConditio_h;

  /* InitializeConditions for Integrator: '<S127>/Filter' */
  AttitudeControl_X.Filter_CSTATE_l =
    AttitudeControl_P.YawController_InitialConditionF;
}

/* Model terminate function */
void AttitudeControlModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
AttitudeControlModelClass::AttitudeControlModelClass():
  AttitudeControl_B()
  ,AttitudeControl_X()
  ,AttitudeControl_U()
  ,AttitudeControl_Y()
  ,AttitudeControl_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
AttitudeControlModelClass::~AttitudeControlModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_AttitudeControl_T * AttitudeControlModelClass::getRTM()
{
  return (&AttitudeControl_M);
}
