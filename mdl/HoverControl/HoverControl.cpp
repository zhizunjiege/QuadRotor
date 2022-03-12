/*
 * HoverControl.cpp
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

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void HoverControlModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si)
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
      1.0 / 2.0, 3.0 / 4.0, 1.0};

  static const real_T rt_ODE3_B[3][3] = {
      {1.0 / 2.0, 0.0, 0.0},

      {0.0, 3.0 / 4.0, 0.0},

      {2.0 / 9.0, 1.0 / 3.0, 4.0 / 9.0}};

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
  rtsiSetSimTimeStep(si, MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void)std::memcpy(y, x,
                    static_cast<uint_T>(nXc) * sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  HoverControl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++)
  {
    x[i] = y[i] + (f0[i] * hB[0]);
  }

  rtsiSetT(si, t + h * rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  HoverControl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
  {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++)
  {
    x[i] = y[i] + (f0[i] * hB[0] + f1[i] * hB[1]);
  }

  rtsiSetT(si, t + h * rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  HoverControl_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++)
  {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++)
  {
    x[i] = y[i] + (f0[i] * hB[0] + f1[i] * hB[1] + f2[i] * hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si, MAJOR_TIME_STEP);
}

/* Model step function */
void HoverControlModelClass::step()
{
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Sum3;
  if (rtmIsMajorTimeStep((&HoverControl_M)))
  {
    /* set solver stop time */
    if (!((&HoverControl_M)->Timing.clockTick0 + 1))
    {
      rtsiSetSolverStopTime(&(&HoverControl_M)->solverInfo, (((&HoverControl_M)->Timing.clockTickH0 + 1) * (&HoverControl_M)->Timing.stepSize0 *
                                                             4294967296.0));
    }
    else
    {
      rtsiSetSolverStopTime(&(&HoverControl_M)->solverInfo, (((&HoverControl_M)->Timing.clockTick0 + 1) * (&HoverControl_M)->Timing.stepSize0 +
                                                             (&HoverControl_M)->Timing.clockTickH0 * (&HoverControl_M)->Timing.stepSize0 * 4294967296.0));
    }
  } /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&HoverControl_M)))
  {
    (&HoverControl_M)->Timing.t[0] = rtsiGetT(&(&HoverControl_M)->solverInfo);
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/act'
   *  Inport: '<Root>/des'
   */
  rtb_Sum1 = HoverControl_U.des[0] - HoverControl_U.act[0];

  /* Product: '<S39>/NProd Out' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/k_x_pid'
   *  Integrator: '<S31>/Filter'
   *  Product: '<S30>/DProd Out'
   *  Sum: '<S31>/SumD'
   */
  HoverControl_B.NProdOut = (rtb_Sum1 * HoverControl_U.k_x_pid[2] -
                             HoverControl_X.Filter_CSTATE) *
                            HoverControl_P.Constant_Value;

  /* Outport: '<Root>/ax' incorporates:
   *  Inport: '<Root>/k_x_pid'
   *  Integrator: '<S36>/Integrator'
   *  Product: '<S41>/PProd Out'
   *  Sum: '<S45>/Sum'
   */
  HoverControl_Y.ax = (rtb_Sum1 * HoverControl_U.k_x_pid[0] +
                       HoverControl_X.Integrator_CSTATE) +
                      HoverControl_B.NProdOut;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Inport: '<Root>/act'
   *  Inport: '<Root>/des'
   */
  rtb_Sum2 = HoverControl_U.des[1] - HoverControl_U.act[1];

  /* Product: '<S87>/NProd Out' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/k_y_pid'
   *  Integrator: '<S79>/Filter'
   *  Product: '<S78>/DProd Out'
   *  Sum: '<S79>/SumD'
   */
  HoverControl_B.NProdOut_h = (rtb_Sum2 * HoverControl_U.k_y_pid[2] -
                               HoverControl_X.Filter_CSTATE_i) *
                              HoverControl_P.Constant_Value;

  /* Outport: '<Root>/ay' incorporates:
   *  Inport: '<Root>/k_y_pid'
   *  Integrator: '<S84>/Integrator'
   *  Product: '<S89>/PProd Out'
   *  Sum: '<S93>/Sum'
   */
  HoverControl_Y.ay = (rtb_Sum2 * HoverControl_U.k_y_pid[0] +
                       HoverControl_X.Integrator_CSTATE_j) +
                      HoverControl_B.NProdOut_h;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Inport: '<Root>/act'
   *  Inport: '<Root>/des'
   */
  rtb_Sum3 = HoverControl_U.des[2] - HoverControl_U.act[2];

  /* Product: '<S135>/NProd Out' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/k_z_pid'
   *  Integrator: '<S127>/Filter'
   *  Product: '<S126>/DProd Out'
   *  Sum: '<S127>/SumD'
   */
  HoverControl_B.NProdOut_b = (rtb_Sum3 * HoverControl_U.k_z_pid[2] -
                               HoverControl_X.Filter_CSTATE_c) *
                              HoverControl_P.Constant_Value;

  /* Outport: '<Root>/az' incorporates:
   *  Inport: '<Root>/k_z_pid'
   *  Integrator: '<S132>/Integrator'
   *  Product: '<S137>/PProd Out'
   *  Sum: '<S141>/Sum'
   */
  HoverControl_Y.az = (rtb_Sum3 * HoverControl_U.k_z_pid[0] +
                       HoverControl_X.Integrator_CSTATE_l) +
                      HoverControl_B.NProdOut_b;

  /* Product: '<S33>/IProd Out' incorporates:
   *  Inport: '<Root>/k_x_pid'
   */
  HoverControl_B.IProdOut = rtb_Sum1 * HoverControl_U.k_x_pid[1];

  /* Product: '<S81>/IProd Out' incorporates:
   *  Inport: '<Root>/k_y_pid'
   */
  HoverControl_B.IProdOut_l = rtb_Sum2 * HoverControl_U.k_y_pid[1];

  /* Product: '<S129>/IProd Out' incorporates:
   *  Inport: '<Root>/k_z_pid'
   */
  HoverControl_B.IProdOut_m = rtb_Sum3 * HoverControl_U.k_z_pid[1];
  if (rtmIsMajorTimeStep((&HoverControl_M)))
  {
    rt_ertODEUpdateContinuousStates(&(&HoverControl_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&HoverControl_M)->Timing.clockTick0))
    {
      ++(&HoverControl_M)->Timing.clockTickH0;
    }

    (&HoverControl_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&HoverControl_M)
                                                                ->solverInfo);

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
      (&HoverControl_M)->Timing.clockTick1++;
      if (!(&HoverControl_M)->Timing.clockTick1)
      {
        (&HoverControl_M)->Timing.clockTickH1++;
      }
    }
  } /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void HoverControlModelClass::HoverControl_derivatives()
{
  XDot_HoverControl_T *_rtXdot;
  _rtXdot = ((XDot_HoverControl_T *)(&HoverControl_M)->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = HoverControl_B.IProdOut;

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = HoverControl_B.NProdOut;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = HoverControl_B.IProdOut_l;

  /* Derivatives for Integrator: '<S79>/Filter' */
  _rtXdot->Filter_CSTATE_i = HoverControl_B.NProdOut_h;

  /* Derivatives for Integrator: '<S132>/Integrator' */
  _rtXdot->Integrator_CSTATE_l = HoverControl_B.IProdOut_m;

  /* Derivatives for Integrator: '<S127>/Filter' */
  _rtXdot->Filter_CSTATE_c = HoverControl_B.NProdOut_b;
}

/* Model initialize function */
void HoverControlModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&HoverControl_M)->solverInfo, &(&HoverControl_M)
                                                               ->Timing.simTimeStep);
    rtsiSetTPtr(&(&HoverControl_M)->solverInfo, &rtmGetTPtr((&HoverControl_M)));
    rtsiSetStepSizePtr(&(&HoverControl_M)->solverInfo, &(&HoverControl_M)
                                                            ->Timing.stepSize0);
    rtsiSetdXPtr(&(&HoverControl_M)->solverInfo, &(&HoverControl_M)->derivs);
    rtsiSetContStatesPtr(&(&HoverControl_M)->solverInfo, (real_T **)&(&HoverControl_M)->contStates);
    rtsiSetNumContStatesPtr(&(&HoverControl_M)->solverInfo, &(&HoverControl_M)
                                                                 ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&HoverControl_M)->solverInfo,
                                    &(&HoverControl_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&HoverControl_M)->solverInfo,
                                       &(&HoverControl_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&HoverControl_M)->solverInfo,
                                      &(&HoverControl_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&HoverControl_M)->solverInfo, (&rtmGetErrorStatus((&HoverControl_M))));
    rtsiSetRTModelPtr(&(&HoverControl_M)->solverInfo, (&HoverControl_M));
  }

  rtsiSetSimTimeStep(&(&HoverControl_M)->solverInfo, MAJOR_TIME_STEP);
  (&HoverControl_M)->intgData.y = (&HoverControl_M)->odeY;
  (&HoverControl_M)->intgData.f[0] = (&HoverControl_M)->odeF[0];
  (&HoverControl_M)->intgData.f[1] = (&HoverControl_M)->odeF[1];
  (&HoverControl_M)->intgData.f[2] = (&HoverControl_M)->odeF[2];
  (&HoverControl_M)->contStates = ((X_HoverControl_T *)&HoverControl_X);
  rtsiSetSolverData(&(&HoverControl_M)->solverInfo, static_cast<void *>(&(&HoverControl_M)->intgData));
  rtsiSetSolverName(&(&HoverControl_M)->solverInfo, "ode3");
  rtmSetTPtr((&HoverControl_M), &(&HoverControl_M)->Timing.tArray[0]);
  (&HoverControl_M)->Timing.stepSize0 = 0.01;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  HoverControl_X.Integrator_CSTATE =
      HoverControl_P.XController_InitialConditionF_k;

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  HoverControl_X.Filter_CSTATE = HoverControl_P.XController_InitialConditionFor;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  HoverControl_X.Integrator_CSTATE_j =
      HoverControl_P.YController_InitialConditionF_h;

  /* InitializeConditions for Integrator: '<S79>/Filter' */
  HoverControl_X.Filter_CSTATE_i =
      HoverControl_P.YController_InitialConditionFor;

  /* InitializeConditions for Integrator: '<S132>/Integrator' */
  HoverControl_X.Integrator_CSTATE_l =
      HoverControl_P.ZController_InitialConditionF_k;

  /* InitializeConditions for Integrator: '<S127>/Filter' */
  HoverControl_X.Filter_CSTATE_c =
      HoverControl_P.ZController_InitialConditionFor;
}

/* Model terminate function */
void HoverControlModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
HoverControlModelClass::HoverControlModelClass() : HoverControl_B(), HoverControl_X(), HoverControl_U(), HoverControl_Y(), HoverControl_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
HoverControlModelClass::~HoverControlModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_HoverControl_T *HoverControlModelClass::getRTM()
{
  return (&HoverControl_M);
}
