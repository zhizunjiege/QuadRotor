/*
 * MotorDynamics.cpp
 *
 * Code generation for model "MotorDynamics".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sat Mar 12 13:48:51 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorDynamics.h"
#include "MotorDynamics_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void MotorDynamicsModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si)
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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si, MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void)std::memcpy(y, x,
                    static_cast<uint_T>(nXc) * sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  MotorDynamics_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++)
  {
    x[i] = y[i] + (f0[i] * hB[0]);
  }

  rtsiSetT(si, t + h * rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  MotorDynamics_derivatives();

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
  MotorDynamics_derivatives();

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
void MotorDynamicsModelClass::step()
{
  int_T iy;
  boolean_T y;
  real_T rtb_Sum[4];
  real_T rtb_x_sat_idx_0;
  real_T rtb_x_sat_idx_1;
  real_T rtb_x_sat_idx_2;
  real_T rtb_x_sat_idx_3;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep((&MotorDynamics_M)))
  {
    /* set solver stop time */
    if (!((&MotorDynamics_M)->Timing.clockTick0 + 1))
    {
      rtsiSetSolverStopTime(&(&MotorDynamics_M)->solverInfo, (((&MotorDynamics_M)
                                                                   ->Timing.clockTickH0 +
                                                               1) *
                                                              (&MotorDynamics_M)->Timing.stepSize0 *
                                                              4294967296.0));
    }
    else
    {
      rtsiSetSolverStopTime(&(&MotorDynamics_M)->solverInfo, (((&MotorDynamics_M)
                                                                   ->Timing.clockTick0 +
                                                               1) *
                                                                  (&MotorDynamics_M)->Timing.stepSize0 +
                                                              (&MotorDynamics_M)->Timing.clockTickH0 * (&MotorDynamics_M)->Timing.stepSize0 * 4294967296.0));
    }
  } /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&MotorDynamics_M)))
  {
    (&MotorDynamics_M)->Timing.t[0] = rtsiGetT(&(&MotorDynamics_M)->solverInfo);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/��λת��'
   *  Inport: '<Root>/omega_h'
   *  TransferFcn: '<Root>/Transfer Fcn'
   *  TransferFcn: '<Root>/Transfer Fcn1'
   *  TransferFcn: '<Root>/Transfer Fcn2'
   *  TransferFcn: '<Root>/Transfer Fcn3'
   */
  rtb_Sum[0] = MotorDynamics_P.TransferFcn_C *
                   MotorDynamics_X.TransferFcn_CSTATE * MotorDynamics_P._Gain +
               MotorDynamics_U.omega_h;
  rtb_Sum[1] = MotorDynamics_P.TransferFcn1_C *
                   MotorDynamics_X.TransferFcn1_CSTATE * MotorDynamics_P._Gain +
               MotorDynamics_U.omega_h;
  rtb_Sum[2] = MotorDynamics_P.TransferFcn2_C *
                   MotorDynamics_X.TransferFcn2_CSTATE * MotorDynamics_P._Gain +
               MotorDynamics_U.omega_h;
  rtb_Sum[3] = MotorDynamics_P.TransferFcn3_C *
                   MotorDynamics_X.TransferFcn3_CSTATE * MotorDynamics_P._Gain +
               MotorDynamics_U.omega_h;

  /* MATLAB Function: '<Root>/���ͺ���' incorporates:
   *  Inport: '<Root>/rpm_max'
   *  Inport: '<Root>/rpm_min'
   */
  y = true;
  iy = 0;
  exitg1 = false;
  while ((!exitg1) && (iy < 4))
  {
    if (!(rtb_Sum[iy] > MotorDynamics_U.rpm_max))
    {
      y = false;
      exitg1 = true;
    }
    else
    {
      iy++;
    }
  }

  if (y)
  {
    rtb_x_sat_idx_0 = MotorDynamics_U.rpm_max;
    rtb_x_sat_idx_1 = MotorDynamics_U.rpm_max;
    rtb_x_sat_idx_2 = MotorDynamics_U.rpm_max;
    rtb_x_sat_idx_3 = MotorDynamics_U.rpm_max;
  }
  else
  {
    y = true;
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 4))
    {
      if (!(rtb_Sum[iy] < MotorDynamics_U.rpm_min))
      {
        y = false;
        exitg1 = true;
      }
      else
      {
        iy++;
      }
    }

    if (y)
    {
      rtb_x_sat_idx_0 = MotorDynamics_U.rpm_min;
      rtb_x_sat_idx_1 = MotorDynamics_U.rpm_min;
      rtb_x_sat_idx_2 = MotorDynamics_U.rpm_min;
      rtb_x_sat_idx_3 = MotorDynamics_U.rpm_min;
    }
    else
    {
      rtb_x_sat_idx_0 = rtb_Sum[0];
      rtb_x_sat_idx_1 = rtb_Sum[1];
      rtb_x_sat_idx_2 = rtb_Sum[2];
      rtb_x_sat_idx_3 = rtb_Sum[3];
    }
  }

  /* End of MATLAB Function: '<Root>/���ͺ���' */

  /* Math: '<Root>/Math Function' */
  rtb_x_sat_idx_0 *= rtb_x_sat_idx_0;

  /* Outport: '<Root>/F' incorporates:
   *  Inport: '<Root>/Kf'
   *  Product: '<Root>/Product'
   */
  MotorDynamics_Y.F[0] = MotorDynamics_U.Kf * rtb_x_sat_idx_0;

  /* Outport: '<Root>/M' incorporates:
   *  Inport: '<Root>/Km'
   *  Product: '<Root>/Product1'
   */
  MotorDynamics_Y.M[0] = rtb_x_sat_idx_0 * MotorDynamics_U.Km;

  /* Math: '<Root>/Math Function' */
  rtb_x_sat_idx_0 = rtb_x_sat_idx_1 * rtb_x_sat_idx_1;

  /* Outport: '<Root>/F' incorporates:
   *  Inport: '<Root>/Kf'
   *  Product: '<Root>/Product'
   */
  MotorDynamics_Y.F[1] = MotorDynamics_U.Kf * rtb_x_sat_idx_0;

  /* Outport: '<Root>/M' incorporates:
   *  Inport: '<Root>/Km'
   *  Product: '<Root>/Product1'
   */
  MotorDynamics_Y.M[1] = rtb_x_sat_idx_0 * MotorDynamics_U.Km;

  /* Math: '<Root>/Math Function' */
  rtb_x_sat_idx_0 = rtb_x_sat_idx_2 * rtb_x_sat_idx_2;

  /* Outport: '<Root>/F' incorporates:
   *  Inport: '<Root>/Kf'
   *  Product: '<Root>/Product'
   */
  MotorDynamics_Y.F[2] = MotorDynamics_U.Kf * rtb_x_sat_idx_0;

  /* Outport: '<Root>/M' incorporates:
   *  Inport: '<Root>/Km'
   *  Product: '<Root>/Product1'
   */
  MotorDynamics_Y.M[2] = rtb_x_sat_idx_0 * MotorDynamics_U.Km;

  /* Math: '<Root>/Math Function' */
  rtb_x_sat_idx_0 = rtb_x_sat_idx_3 * rtb_x_sat_idx_3;

  /* Outport: '<Root>/F' incorporates:
   *  Inport: '<Root>/Kf'
   *  Product: '<Root>/Product'
   */
  MotorDynamics_Y.F[3] = MotorDynamics_U.Kf * rtb_x_sat_idx_0;

  /* Outport: '<Root>/M' incorporates:
   *  Inport: '<Root>/Km'
   *  Product: '<Root>/Product1'
   */
  MotorDynamics_Y.M[3] = rtb_x_sat_idx_0 * MotorDynamics_U.Km;
  if (rtmIsMajorTimeStep((&MotorDynamics_M)))
  {
    rt_ertODEUpdateContinuousStates(&(&MotorDynamics_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&MotorDynamics_M)->Timing.clockTick0))
    {
      ++(&MotorDynamics_M)->Timing.clockTickH0;
    }

    (&MotorDynamics_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&MotorDynamics_M)->solverInfo);

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
      (&MotorDynamics_M)->Timing.clockTick1++;
      if (!(&MotorDynamics_M)->Timing.clockTick1)
      {
        (&MotorDynamics_M)->Timing.clockTickH1++;
      }
    }
  } /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void MotorDynamicsModelClass::MotorDynamics_derivatives()
{
  XDot_MotorDynamics_T *_rtXdot;
  _rtXdot = ((XDot_MotorDynamics_T *)(&MotorDynamics_M)->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' incorporates:
   *  Inport: '<Root>/omega1'
   */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += MotorDynamics_P.TransferFcn_A *
                                 MotorDynamics_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += MotorDynamics_U.omega1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' incorporates:
   *  Inport: '<Root>/omega2'
   */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += MotorDynamics_P.TransferFcn1_A *
                                  MotorDynamics_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += MotorDynamics_U.omega2;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' incorporates:
   *  Inport: '<Root>/omega3'
   */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += MotorDynamics_P.TransferFcn2_A *
                                  MotorDynamics_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += MotorDynamics_U.omega3;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' incorporates:
   *  Inport: '<Root>/omega4'
   */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += MotorDynamics_P.TransferFcn3_A *
                                  MotorDynamics_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += MotorDynamics_U.omega4;
}

/* Model initialize function */
void MotorDynamicsModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&MotorDynamics_M)->solverInfo, &(&MotorDynamics_M)
                                                                ->Timing.simTimeStep);
    rtsiSetTPtr(&(&MotorDynamics_M)->solverInfo, &rtmGetTPtr((&MotorDynamics_M)));
    rtsiSetStepSizePtr(&(&MotorDynamics_M)->solverInfo, &(&MotorDynamics_M)
                                                             ->Timing.stepSize0);
    rtsiSetdXPtr(&(&MotorDynamics_M)->solverInfo, &(&MotorDynamics_M)->derivs);
    rtsiSetContStatesPtr(&(&MotorDynamics_M)->solverInfo, (real_T **)&(&MotorDynamics_M)->contStates);
    rtsiSetNumContStatesPtr(&(&MotorDynamics_M)->solverInfo, &(&MotorDynamics_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&MotorDynamics_M)->solverInfo,
                                    &(&MotorDynamics_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&MotorDynamics_M)->solverInfo,
                                       &(&MotorDynamics_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&MotorDynamics_M)->solverInfo,
                                      &(&MotorDynamics_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&MotorDynamics_M)->solverInfo, (&rtmGetErrorStatus((
                                                               &MotorDynamics_M))));
    rtsiSetRTModelPtr(&(&MotorDynamics_M)->solverInfo, (&MotorDynamics_M));
  }

  rtsiSetSimTimeStep(&(&MotorDynamics_M)->solverInfo, MAJOR_TIME_STEP);
  (&MotorDynamics_M)->intgData.y = (&MotorDynamics_M)->odeY;
  (&MotorDynamics_M)->intgData.f[0] = (&MotorDynamics_M)->odeF[0];
  (&MotorDynamics_M)->intgData.f[1] = (&MotorDynamics_M)->odeF[1];
  (&MotorDynamics_M)->intgData.f[2] = (&MotorDynamics_M)->odeF[2];
  (&MotorDynamics_M)->contStates = ((X_MotorDynamics_T *)&MotorDynamics_X);
  rtsiSetSolverData(&(&MotorDynamics_M)->solverInfo, static_cast<void *>(&(&MotorDynamics_M)->intgData));
  rtsiSetSolverName(&(&MotorDynamics_M)->solverInfo, "ode3");
  rtmSetTPtr((&MotorDynamics_M), &(&MotorDynamics_M)->Timing.tArray[0]);
  (&MotorDynamics_M)->Timing.stepSize0 = 0.01;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  MotorDynamics_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  MotorDynamics_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  MotorDynamics_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  MotorDynamics_X.TransferFcn3_CSTATE = 0.0;
}

/* Model terminate function */
void MotorDynamicsModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
MotorDynamicsModelClass::MotorDynamicsModelClass() : MotorDynamics_X(), MotorDynamics_U(), MotorDynamics_Y(), MotorDynamics_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
MotorDynamicsModelClass::~MotorDynamicsModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_MotorDynamics_T *MotorDynamicsModelClass::getRTM()
{
  return (&MotorDynamics_M);
}
