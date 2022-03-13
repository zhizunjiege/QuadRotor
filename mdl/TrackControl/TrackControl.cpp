/*
 * TrackControl.cpp
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

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void TrackControlModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si)
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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si, MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void)std::memcpy(y, x,
                    static_cast<uint_T>(nXc) * sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TrackControl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++)
  {
    x[i] = y[i] + (f0[i] * hB[0]);
  }

  rtsiSetT(si, t + h * rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  TrackControl_derivatives();

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
  TrackControl_derivatives();

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

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<Root>/航段计数器' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0)
  {
    curState = 2;
  }
  else
  {
    curState = !(evt < 0.0);
  }

  if (*sta == 5U)
  {
    newStateR = curState;
  }
  else
  {
    if (static_cast<uint32_T>(curState) != *sta)
    {
      if (*sta == 3U)
      {
        if (static_cast<uint32_T>(curState) == 1U)
        {
          newStateR = 1;
        }
        else
        {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U)
      {
        if (static_cast<uint32_T>(curState) == 1U)
        {
          newStateR = 1;
        }
        else
        {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && (static_cast<uint32_T>(curState) == 2U))
      {
        retVal = 2U;
      }

      if (previousState == 0U)
      {
        retVal = 2U;
      }

      if (retVal == static_cast<uint32_T>(lastzcevent))
      {
        retVal = 0U;
      }

      if ((static_cast<uint32_T>(curState) == 1U) && (retVal == 2U))
      {
        newState = 3;
      }
      else
      {
        newState = curState;
      }
    }
  }

  if (static_cast<uint32_T>(newStateR) != 5U)
  {
    *sta = static_cast<uint32_T>(newStateR);
    retVal = 0U;
  }

  if (static_cast<uint32_T>(newState) != 5U)
  {
    *sta = static_cast<uint32_T>(newState);
  }

  /* End of S-Function (sdspcount2): '<Root>/航段计数器' */
  return retVal;
}

/* Function for MATLAB Function: '<Root>/数学计算' */
real_T TrackControlModelClass::TrackControl_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170)
  {
    y = 1.0;
    scale = absxk;
  }
  else
  {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale)
  {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  }
  else
  {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale)
  {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  }
  else
  {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

/* Model step function */
void TrackControlModelClass::step()
{
  ZCEventType zcEvent;
  real_T traces[300];
  real_T dis01;
  real_T rtb_idx1;
  real_T rtb_idx0;
  real_T traces_0[3];
  real_T rtb_ect_idx_1;
  real_T rtb_eat_idx_1;
  real_T rtb_ect_idx_2;
  real_T rtb_eat_idx_2;
  real_T ti01_idx_0;
  real_T ti01_idx_1;
  real_T ti01_idx_2;
  int32_T rtb_idx1_tmp;
  int32_T rtb_idx0_tmp;
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    /* set solver stop time */
    if (!((&TrackControl_M)->Timing.clockTick0 + 1))
    {
      rtsiSetSolverStopTime(&(&TrackControl_M)->solverInfo, (((&TrackControl_M)->Timing.clockTickH0 + 1) * (&TrackControl_M)->Timing.stepSize0 *
                                                             4294967296.0));
    }
    else
    {
      rtsiSetSolverStopTime(&(&TrackControl_M)->solverInfo, (((&TrackControl_M)->Timing.clockTick0 + 1) * (&TrackControl_M)->Timing.stepSize0 +
                                                             (&TrackControl_M)->Timing.clockTickH0 * (&TrackControl_M)->Timing.stepSize0 * 4294967296.0));
    }
  } /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&TrackControl_M)))
  {
    (&TrackControl_M)->Timing.t[0] = rtsiGetT(&(&TrackControl_M)->solverInfo);
  }

  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    /* Delay: '<Root>/一阶延迟' */
    TrackControl_B.u = TrackControl_DW._DSTATE;

    /* S-Function (sdspcount2): '<Root>/航段计数器' incorporates:
     *  Constant: '<Root>/复位'
     */
    if (MWDSP_EPH_R_D(TrackControl_P._Value, &TrackControl_DW._RstEphState) !=
        0U)
    {
      TrackControl_DW._Count = TrackControl_P._InitialCount;
    }

    if (MWDSP_EPH_R_D(TrackControl_B.u, &TrackControl_DW._ClkEphState) != 0U)
    {
      if (TrackControl_DW._Count < 255)
      {
        TrackControl_DW._Count = static_cast<uint8_T>(TrackControl_DW._Count +
                                                      1U);
      }
      else
      {
        TrackControl_DW._Count = 0U;
      }
    }

    TrackControl_B.u_g = TrackControl_DW._Count;

    /* End of S-Function (sdspcount2): '<Root>/航段计数器' */
  }

  /* MATLAB Function: '<Root>/生成索引' incorporates:
   *  Inport: '<Root>/N'
   */
  if (TrackControl_B.u_g >= TrackControl_U.N - 1.0)
  {
    rtb_idx1 = TrackControl_U.N;
  }
  else
  {
    rtb_idx1 = TrackControl_B.u_g + 1.0;
  }

  if (TrackControl_B.u_g >= TrackControl_U.N)
  {
    rtb_idx0 = TrackControl_U.N;
  }
  else
  {
    rtb_idx0 = TrackControl_B.u_g;
  }

  /* End of MATLAB Function: '<Root>/生成索引' */

  /* MATLAB Function: '<Root>/数学计算' incorporates:
   *  Inport: '<Root>/V'
   *  Inport: '<Root>/X'
   *  Inport: '<Root>/Y'
   *  Inport: '<Root>/Z'
   *  Inport: '<Root>/position'
   *  Inport: '<Root>/velocity'
   */
  for (rtb_idx1_tmp = 0; rtb_idx1_tmp < 100; rtb_idx1_tmp++)
  {
    traces[rtb_idx1_tmp] = TrackControl_U.X[rtb_idx1_tmp];
    traces[rtb_idx1_tmp + 100] = TrackControl_U.Y[rtb_idx1_tmp];
    traces[rtb_idx1_tmp + 200] = TrackControl_U.Z[rtb_idx1_tmp];
  }

  rtb_idx1_tmp = static_cast<int32_T>(rtb_idx1);
  rtb_idx0_tmp = static_cast<int32_T>(rtb_idx0);
  traces_0[0] = traces[rtb_idx1_tmp - 1] - traces[rtb_idx0_tmp - 1];
  traces_0[1] = traces[rtb_idx1_tmp + 99] - traces[rtb_idx0_tmp + 99];
  traces_0[2] = traces[rtb_idx1_tmp + 199] - traces[rtb_idx0_tmp + 199];
  dis01 = TrackControl_norm(traces_0);
  if (rtb_idx1 > rtb_idx0)
  {
    ti01_idx_2 = (traces[rtb_idx1_tmp - 1] - traces[rtb_idx0_tmp - 1]) / dis01;
    rtb_eat_idx_1 = TrackControl_U.position[0] - traces[rtb_idx0_tmp - 1];
    rtb_eat_idx_2 = rtb_eat_idx_1 * ti01_idx_2;
    ti01_idx_0 = ti01_idx_2;
    rtb_idx1 = rtb_eat_idx_1;
    ti01_idx_2 = (traces[rtb_idx1_tmp + 99] - traces[rtb_idx0_tmp + 99]) / dis01;
    rtb_eat_idx_1 = TrackControl_U.position[1] - traces[rtb_idx0_tmp + 99];
    rtb_eat_idx_2 += rtb_eat_idx_1 * ti01_idx_2;
    ti01_idx_1 = ti01_idx_2;
    rtb_ect_idx_1 = rtb_eat_idx_1;
    ti01_idx_2 = (traces[rtb_idx1_tmp + 199] - traces[rtb_idx0_tmp + 199]) /
                 dis01;
    rtb_eat_idx_1 = TrackControl_U.position[2] - traces[rtb_idx0_tmp + 199];
    rtb_eat_idx_2 += rtb_eat_idx_1 * ti01_idx_2;
    rtb_ect_idx_2 = rtb_eat_idx_2 * ti01_idx_0 - rtb_idx1;
    traces_0[0] = (TrackControl_U.position[0] - traces[rtb_idx1_tmp - 1]) +
                  rtb_ect_idx_2;
    rtb_idx1 = rtb_ect_idx_2;
    rtb_ect_idx_2 = rtb_eat_idx_2 * ti01_idx_1 - rtb_ect_idx_1;
    traces_0[1] = (TrackControl_U.position[1] - traces[rtb_idx1_tmp + 99]) +
                  rtb_ect_idx_2;
    rtb_ect_idx_1 = rtb_ect_idx_2;
    rtb_ect_idx_2 = rtb_eat_idx_2 * ti01_idx_2 - rtb_eat_idx_1;
    traces_0[2] = (TrackControl_U.position[2] - traces[rtb_idx1_tmp + 199]) +
                  rtb_ect_idx_2;
    rtb_eat_idx_2 = TrackControl_U.V[static_cast<int32_T>(rtb_idx0) - 1];
    if (dis01 <= 3.0)
    {
      dis01 = 1.0;
    }
    else
    {
      dis01 = 1.3;
    }

    rtb_idx0 = dis01 * std::sqrt(TrackControl_norm(traces_0));
    if ((rtb_eat_idx_2 < rtb_idx0) || rtIsNaN(rtb_idx0))
    {
      rtb_idx0 = rtb_eat_idx_2;
    }

    dis01 = rtb_idx0 * ti01_idx_0;
    rtb_eat_idx_1 = rtb_idx0 * ti01_idx_1;
    rtb_eat_idx_2 = rtb_idx0 * ti01_idx_2;
  }
  else
  {
    ti01_idx_2 = TrackControl_U.position[0] - traces[rtb_idx1_tmp - 1];
    rtb_idx1 = -ti01_idx_2;
    dis01 = 0.0;
    ti01_idx_0 = ti01_idx_2;
    ti01_idx_2 = TrackControl_U.position[1] - traces[rtb_idx1_tmp + 99];
    rtb_ect_idx_1 = -ti01_idx_2;
    rtb_eat_idx_1 = 0.0;
    ti01_idx_1 = ti01_idx_2;
    ti01_idx_2 = TrackControl_U.position[2] - traces[rtb_idx1_tmp + 199];
    rtb_ect_idx_2 = -ti01_idx_2;
    rtb_eat_idx_2 = 0.0;
  }

  rtb_idx0 = (TrackControl_U.velocity[0] * ti01_idx_0 + TrackControl_U.velocity
                                                                [1] *
                                                            ti01_idx_1) +
             TrackControl_U.velocity[2] * ti01_idx_2;
  dis01 -= rtb_idx0 * ti01_idx_0;
  rtb_eat_idx_1 -= rtb_idx0 * ti01_idx_1;
  rtb_idx0 = rtb_eat_idx_2 - rtb_idx0 * ti01_idx_2;
  TrackControl_B.trigger = (((TrackControl_U.position[0] - traces[rtb_idx1_tmp -
                                                                  1]) *
                                 ti01_idx_0 +
                             (TrackControl_U.position[1] - traces[rtb_idx1_tmp + 99]) *
                                 ti01_idx_1) +
                                (TrackControl_U.position[2] - traces[rtb_idx1_tmp + 199]) *
                                    ti01_idx_2 >=
                            0.0);

  /* End of MATLAB Function: '<Root>/数学计算' */

  /* Integrator: '<S185>/Integrator' incorporates:
   *  Integrator: '<S180>/Filter'
   */
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Integrator_Reset_ZCE,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Integrator_CSTATE =
          TrackControl_P.ect_x_InitialConditionForIntegr;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Filter_Reset_ZCE,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Filter_CSTATE =
          TrackControl_P.ect_x_InitialConditionForFilter;
    }
  }

  /* Product: '<S188>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/ect_x_pid'
   *  Integrator: '<S180>/Filter'
   *  Product: '<S179>/DProd Out'
   *  Sum: '<S180>/SumD'
   */
  TrackControl_B.NProdOut = (rtb_idx1 * TrackControl_U.ect_x_pid[2] -
                             TrackControl_X.Filter_CSTATE) *
                            TrackControl_P.Constant_Value;

  /* Integrator: '<S40>/Integrator' incorporates:
   *  Integrator: '<S35>/Filter'
   */
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Integrator_Reset_ZCE_h,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Integrator_CSTATE_j =
          TrackControl_P.eat_x_InitialConditionForIntegr;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Filter_Reset_ZCE_k,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Filter_CSTATE_i =
          TrackControl_P.eat_x_InitialConditionForFilter;
    }
  }

  /* Product: '<S43>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/eat_x_pid'
   *  Integrator: '<S35>/Filter'
   *  Product: '<S34>/DProd Out'
   *  Sum: '<S35>/SumD'
   */
  TrackControl_B.NProdOut_h = (dis01 * TrackControl_U.eat_x_pid[2] -
                               TrackControl_X.Filter_CSTATE_i) *
                              TrackControl_P.Constant_Value;

  /* Sum: '<S194>/Sum' incorporates:
   *  Inport: '<Root>/ect_x_pid'
   *  Integrator: '<S185>/Integrator'
   *  Product: '<S190>/PProd Out'
   */
  rtb_eat_idx_2 = (rtb_idx1 * TrackControl_U.ect_x_pid[0] +
                   TrackControl_X.Integrator_CSTATE) +
                  TrackControl_B.NProdOut;

  /* Sum: '<S49>/Sum' incorporates:
   *  Inport: '<Root>/eat_x_pid'
   *  Integrator: '<S40>/Integrator'
   *  Product: '<S45>/PProd Out'
   */
  ti01_idx_0 = (dis01 * TrackControl_U.eat_x_pid[0] +
                TrackControl_X.Integrator_CSTATE_j) +
               TrackControl_B.NProdOut_h;

  /* Saturate: '<S192>/Saturation' */
  if (rtb_eat_idx_2 > TrackControl_P.pid_limit)
  {
    rtb_eat_idx_2 = TrackControl_P.pid_limit;
  }
  else
  {
    if (rtb_eat_idx_2 < -TrackControl_P.pid_limit)
    {
      rtb_eat_idx_2 = -TrackControl_P.pid_limit;
    }
  }

  /* End of Saturate: '<S192>/Saturation' */

  /* Saturate: '<S47>/Saturation' */
  if (ti01_idx_0 > TrackControl_P.pid_limit)
  {
    ti01_idx_0 = TrackControl_P.pid_limit;
  }
  else
  {
    if (ti01_idx_0 < -TrackControl_P.pid_limit)
    {
      ti01_idx_0 = -TrackControl_P.pid_limit;
    }
  }

  /* End of Saturate: '<S47>/Saturation' */

  /* Outport: '<Root>/ax' incorporates:
   *  Sum: '<Root>/Sum'
   */
  TrackControl_Y.ax = rtb_eat_idx_2 + ti01_idx_0;

  /* Integrator: '<S233>/Integrator' incorporates:
   *  Integrator: '<S228>/Filter'
   */
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Integrator_Reset_ZCE_g,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Integrator_CSTATE_m =
          TrackControl_P.ect_y_InitialConditionForIntegr;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Filter_Reset_ZCE_j,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Filter_CSTATE_k =
          TrackControl_P.ect_y_InitialConditionForFilter;
    }
  }

  /* Product: '<S236>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/ect_y_pid'
   *  Integrator: '<S228>/Filter'
   *  Product: '<S227>/DProd Out'
   *  Sum: '<S228>/SumD'
   */
  TrackControl_B.NProdOut_d = (rtb_ect_idx_1 * TrackControl_U.ect_y_pid[2] -
                               TrackControl_X.Filter_CSTATE_k) *
                              TrackControl_P.Constant_Value;

  /* Integrator: '<S88>/Integrator' incorporates:
   *  Integrator: '<S83>/Filter'
   */
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Integrator_Reset_ZCE_b,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Integrator_CSTATE_b =
          TrackControl_P.eat_y_InitialConditionForIntegr;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Filter_Reset_ZCE_g,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Filter_CSTATE_m =
          TrackControl_P.eat_y_InitialConditionForFilter;
    }
  }

  /* Product: '<S91>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/eat_y_pid'
   *  Integrator: '<S83>/Filter'
   *  Product: '<S82>/DProd Out'
   *  Sum: '<S83>/SumD'
   */
  TrackControl_B.NProdOut_c = (rtb_eat_idx_1 * TrackControl_U.eat_y_pid[2] -
                               TrackControl_X.Filter_CSTATE_m) *
                              TrackControl_P.Constant_Value;

  /* Sum: '<S242>/Sum' incorporates:
   *  Inport: '<Root>/ect_y_pid'
   *  Integrator: '<S233>/Integrator'
   *  Product: '<S238>/PProd Out'
   */
  rtb_eat_idx_2 = (rtb_ect_idx_1 * TrackControl_U.ect_y_pid[0] +
                   TrackControl_X.Integrator_CSTATE_m) +
                  TrackControl_B.NProdOut_d;

  /* Sum: '<S97>/Sum' incorporates:
   *  Inport: '<Root>/eat_y_pid'
   *  Integrator: '<S88>/Integrator'
   *  Product: '<S93>/PProd Out'
   */
  ti01_idx_0 = (rtb_eat_idx_1 * TrackControl_U.eat_y_pid[0] +
                TrackControl_X.Integrator_CSTATE_b) +
               TrackControl_B.NProdOut_c;

  /* Saturate: '<S240>/Saturation' */
  if (rtb_eat_idx_2 > TrackControl_P.pid_limit)
  {
    rtb_eat_idx_2 = TrackControl_P.pid_limit;
  }
  else
  {
    if (rtb_eat_idx_2 < -TrackControl_P.pid_limit)
    {
      rtb_eat_idx_2 = -TrackControl_P.pid_limit;
    }
  }

  /* End of Saturate: '<S240>/Saturation' */

  /* Saturate: '<S95>/Saturation' */
  if (ti01_idx_0 > TrackControl_P.pid_limit)
  {
    ti01_idx_0 = TrackControl_P.pid_limit;
  }
  else
  {
    if (ti01_idx_0 < -TrackControl_P.pid_limit)
    {
      ti01_idx_0 = -TrackControl_P.pid_limit;
    }
  }

  /* End of Saturate: '<S95>/Saturation' */

  /* Outport: '<Root>/ay' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  TrackControl_Y.ay = rtb_eat_idx_2 + ti01_idx_0;

  /* Integrator: '<S281>/Integrator' incorporates:
   *  Integrator: '<S276>/Filter'
   */
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Integrator_Reset_ZCE_a,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Integrator_CSTATE_f =
          TrackControl_P.ect_z_InitialConditionForIntegr;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Filter_Reset_ZCE_h,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Filter_CSTATE_f =
          TrackControl_P.ect_z_InitialConditionForFilter;
    }
  }

  /* Product: '<S284>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/ect_z_pid'
   *  Integrator: '<S276>/Filter'
   *  Product: '<S275>/DProd Out'
   *  Sum: '<S276>/SumD'
   */
  TrackControl_B.NProdOut_du = (rtb_ect_idx_2 * TrackControl_U.ect_z_pid[2] -
                                TrackControl_X.Filter_CSTATE_f) *
                               TrackControl_P.Constant_Value;

  /* Integrator: '<S137>/Integrator' incorporates:
   *  Integrator: '<S132>/Filter'
   */
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Integrator_Reset_ZCE_p,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Integrator_CSTATE_e =
          TrackControl_P.eat_z_InitialConditionForIntegr;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &TrackControl_PrevZCX.Filter_Reset_ZCE_o,
                       (TrackControl_B.u));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT)
    {
      TrackControl_X.Filter_CSTATE_o =
          TrackControl_P.eat_z_InitialConditionForFilter;
    }
  }

  /* Product: '<S140>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/eat_z_pid'
   *  Integrator: '<S132>/Filter'
   *  Product: '<S131>/DProd Out'
   *  Sum: '<S132>/SumD'
   */
  TrackControl_B.NProdOut_hy = (rtb_idx0 * TrackControl_U.eat_z_pid[2] -
                                TrackControl_X.Filter_CSTATE_o) *
                               TrackControl_P.Constant_Value;

  /* Sum: '<S290>/Sum' incorporates:
   *  Inport: '<Root>/ect_z_pid'
   *  Integrator: '<S281>/Integrator'
   *  Product: '<S286>/PProd Out'
   */
  rtb_eat_idx_2 = (rtb_ect_idx_2 * TrackControl_U.ect_z_pid[0] +
                   TrackControl_X.Integrator_CSTATE_f) +
                  TrackControl_B.NProdOut_du;

  /* Sum: '<S146>/Sum' incorporates:
   *  Inport: '<Root>/eat_z_pid'
   *  Integrator: '<S137>/Integrator'
   *  Product: '<S142>/PProd Out'
   */
  ti01_idx_0 = (rtb_idx0 * TrackControl_U.eat_z_pid[0] +
                TrackControl_X.Integrator_CSTATE_e) +
               TrackControl_B.NProdOut_hy;

  /* Saturate: '<S288>/Saturation' */
  if (rtb_eat_idx_2 > TrackControl_P.pid_limit)
  {
    rtb_eat_idx_2 = TrackControl_P.pid_limit;
  }
  else
  {
    if (rtb_eat_idx_2 < -TrackControl_P.pid_limit)
    {
      rtb_eat_idx_2 = -TrackControl_P.pid_limit;
    }
  }

  /* End of Saturate: '<S288>/Saturation' */

  /* Saturate: '<S144>/Saturation' */
  if (ti01_idx_0 > TrackControl_P.pid_limit)
  {
    ti01_idx_0 = TrackControl_P.pid_limit;
  }
  else
  {
    if (ti01_idx_0 < -TrackControl_P.pid_limit)
    {
      ti01_idx_0 = -TrackControl_P.pid_limit;
    }
  }

  /* End of Saturate: '<S144>/Saturation' */

  /* Outport: '<Root>/az' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  TrackControl_Y.az = rtb_eat_idx_2 + ti01_idx_0;

  /* Product: '<S37>/IProd Out' incorporates:
   *  Inport: '<Root>/eat_x_pid'
   */
  TrackControl_B.IProdOut = dis01 * TrackControl_U.eat_x_pid[1];

  /* Product: '<S85>/IProd Out' incorporates:
   *  Inport: '<Root>/eat_y_pid'
   */
  TrackControl_B.IProdOut_o = rtb_eat_idx_1 * TrackControl_U.eat_y_pid[1];

  /* Product: '<S134>/IProd Out' incorporates:
   *  Inport: '<Root>/eat_z_pid'
   */
  TrackControl_B.IProdOut_g = rtb_idx0 * TrackControl_U.eat_z_pid[1];

  /* Product: '<S182>/IProd Out' incorporates:
   *  Inport: '<Root>/ect_x_pid'
   */
  TrackControl_B.IProdOut_m = rtb_idx1 * TrackControl_U.ect_x_pid[1];

  /* Product: '<S230>/IProd Out' incorporates:
   *  Inport: '<Root>/ect_y_pid'
   */
  TrackControl_B.IProdOut_k = rtb_ect_idx_1 * TrackControl_U.ect_y_pid[1];

  /* Product: '<S278>/IProd Out' incorporates:
   *  Inport: '<Root>/ect_z_pid'
   */
  TrackControl_B.IProdOut_n = rtb_ect_idx_2 * TrackControl_U.ect_z_pid[1];
  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    if (rtmIsMajorTimeStep((&TrackControl_M)))
    {
      /* Update for Delay: '<Root>/一阶延迟' */
      TrackControl_DW._DSTATE = TrackControl_B.trigger;
    }
  } /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&TrackControl_M)))
  {
    rt_ertODEUpdateContinuousStates(&(&TrackControl_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&TrackControl_M)->Timing.clockTick0))
    {
      ++(&TrackControl_M)->Timing.clockTickH0;
    }

    (&TrackControl_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&TrackControl_M)
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
      (&TrackControl_M)->Timing.clockTick1++;
      if (!(&TrackControl_M)->Timing.clockTick1)
      {
        (&TrackControl_M)->Timing.clockTickH1++;
      }
    }
  } /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TrackControlModelClass::TrackControl_derivatives()
{
  XDot_TrackControl_T *_rtXdot;
  _rtXdot = ((XDot_TrackControl_T *)(&TrackControl_M)->derivs);

  /* Derivatives for Integrator: '<S185>/Integrator' */
  _rtXdot->Integrator_CSTATE = TrackControl_B.IProdOut_m;

  /* Derivatives for Integrator: '<S180>/Filter' */
  _rtXdot->Filter_CSTATE = TrackControl_B.NProdOut;

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = TrackControl_B.IProdOut;

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE_i = TrackControl_B.NProdOut_h;

  /* Derivatives for Integrator: '<S233>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = TrackControl_B.IProdOut_k;

  /* Derivatives for Integrator: '<S228>/Filter' */
  _rtXdot->Filter_CSTATE_k = TrackControl_B.NProdOut_d;

  /* Derivatives for Integrator: '<S88>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = TrackControl_B.IProdOut_o;

  /* Derivatives for Integrator: '<S83>/Filter' */
  _rtXdot->Filter_CSTATE_m = TrackControl_B.NProdOut_c;

  /* Derivatives for Integrator: '<S281>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = TrackControl_B.IProdOut_n;

  /* Derivatives for Integrator: '<S276>/Filter' */
  _rtXdot->Filter_CSTATE_f = TrackControl_B.NProdOut_du;

  /* Derivatives for Integrator: '<S137>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = TrackControl_B.IProdOut_g;

  /* Derivatives for Integrator: '<S132>/Filter' */
  _rtXdot->Filter_CSTATE_o = TrackControl_B.NProdOut_hy;
}

/* Model initialize function */
void TrackControlModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&TrackControl_M)->solverInfo, &(&TrackControl_M)
                                                               ->Timing.simTimeStep);
    rtsiSetTPtr(&(&TrackControl_M)->solverInfo, &rtmGetTPtr((&TrackControl_M)));
    rtsiSetStepSizePtr(&(&TrackControl_M)->solverInfo, &(&TrackControl_M)
                                                            ->Timing.stepSize0);
    rtsiSetdXPtr(&(&TrackControl_M)->solverInfo, &(&TrackControl_M)->derivs);
    rtsiSetContStatesPtr(&(&TrackControl_M)->solverInfo, (real_T **)&(&TrackControl_M)->contStates);
    rtsiSetNumContStatesPtr(&(&TrackControl_M)->solverInfo, &(&TrackControl_M)
                                                                 ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&TrackControl_M)->solverInfo,
                                    &(&TrackControl_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&TrackControl_M)->solverInfo,
                                       &(&TrackControl_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&TrackControl_M)->solverInfo,
                                      &(&TrackControl_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&TrackControl_M)->solverInfo, (&rtmGetErrorStatus((&TrackControl_M))));
    rtsiSetRTModelPtr(&(&TrackControl_M)->solverInfo, (&TrackControl_M));
  }

  rtsiSetSimTimeStep(&(&TrackControl_M)->solverInfo, MAJOR_TIME_STEP);
  (&TrackControl_M)->intgData.y = (&TrackControl_M)->odeY;
  (&TrackControl_M)->intgData.f[0] = (&TrackControl_M)->odeF[0];
  (&TrackControl_M)->intgData.f[1] = (&TrackControl_M)->odeF[1];
  (&TrackControl_M)->intgData.f[2] = (&TrackControl_M)->odeF[2];
  (&TrackControl_M)->contStates = ((X_TrackControl_T *)&TrackControl_X);
  rtsiSetSolverData(&(&TrackControl_M)->solverInfo, static_cast<void *>(&(&TrackControl_M)->intgData));
  rtsiSetSolverName(&(&TrackControl_M)->solverInfo, "ode3");
  rtmSetTPtr((&TrackControl_M), &(&TrackControl_M)->Timing.tArray[0]);
  (&TrackControl_M)->Timing.stepSize0 = 0.01;
  TrackControl_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Filter_Reset_ZCE = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Filter_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Integrator_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Filter_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Integrator_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Filter_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Filter_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Integrator_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  TrackControl_PrevZCX.Filter_Reset_ZCE_o = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Delay: '<Root>/一阶延迟' */
  TrackControl_DW._DSTATE = TrackControl_P._InitialCondition;

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/航段计数器' */
  TrackControl_DW._ClkEphState = 5U;
  TrackControl_DW._RstEphState = 5U;
  TrackControl_DW._Count = TrackControl_P._InitialCount;

  /* InitializeConditions for Integrator: '<S185>/Integrator' */
  TrackControl_X.Integrator_CSTATE =
      TrackControl_P.ect_x_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S180>/Filter' */
  TrackControl_X.Filter_CSTATE = TrackControl_P.ect_x_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  TrackControl_X.Integrator_CSTATE_j =
      TrackControl_P.eat_x_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  TrackControl_X.Filter_CSTATE_i =
      TrackControl_P.eat_x_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S233>/Integrator' */
  TrackControl_X.Integrator_CSTATE_m =
      TrackControl_P.ect_y_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S228>/Filter' */
  TrackControl_X.Filter_CSTATE_k =
      TrackControl_P.ect_y_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S88>/Integrator' */
  TrackControl_X.Integrator_CSTATE_b =
      TrackControl_P.eat_y_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S83>/Filter' */
  TrackControl_X.Filter_CSTATE_m =
      TrackControl_P.eat_y_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S281>/Integrator' */
  TrackControl_X.Integrator_CSTATE_f =
      TrackControl_P.ect_z_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S276>/Filter' */
  TrackControl_X.Filter_CSTATE_f =
      TrackControl_P.ect_z_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S137>/Integrator' */
  TrackControl_X.Integrator_CSTATE_e =
      TrackControl_P.eat_z_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S132>/Filter' */
  TrackControl_X.Filter_CSTATE_o =
      TrackControl_P.eat_z_InitialConditionForFilter;
}

/* Model terminate function */
void TrackControlModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
TrackControlModelClass::TrackControlModelClass() : TrackControl_B(), TrackControl_DW(), TrackControl_X(), TrackControl_PrevZCX(), TrackControl_U(), TrackControl_Y(), TrackControl_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
TrackControlModelClass::~TrackControlModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_TrackControl_T *TrackControlModelClass::getRTM()
{
  return (&TrackControl_M);
}
