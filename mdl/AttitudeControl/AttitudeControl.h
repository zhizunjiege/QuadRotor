/*
 * AttitudeControl.h
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

#ifndef RTW_HEADER_AttitudeControl_h_
#define RTW_HEADER_AttitudeControl_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "AttitudeControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm) ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm) ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val) ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm) ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val) ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm) ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val) ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm) ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val) ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm) ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm) ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val) ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm) ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm) (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm) (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm) ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct
{
  real_T NProdOut;   /* '<S87>/NProd Out' */
  real_T NProdOut_d; /* '<S39>/NProd Out' */
  real_T NProdOut_h; /* '<S135>/NProd Out' */
  real_T IProdOut;   /* '<S33>/IProd Out' */
  real_T IProdOut_k; /* '<S81>/IProd Out' */
  real_T IProdOut_g; /* '<S129>/IProd Out' */
} B_AttitudeControl_T;

/* Continuous states (default storage) */
typedef struct
{
  real_T Integrator_CSTATE;    /* '<S84>/Integrator' */
  real_T Filter_CSTATE;        /* '<S79>/Filter' */
  real_T Integrator_CSTATE_f;  /* '<S36>/Integrator' */
  real_T Filter_CSTATE_f;      /* '<S31>/Filter' */
  real_T Integrator_CSTATE_fo; /* '<S132>/Integrator' */
  real_T Filter_CSTATE_l;      /* '<S127>/Filter' */
} X_AttitudeControl_T;

/* State derivatives (default storage) */
typedef struct
{
  real_T Integrator_CSTATE;    /* '<S84>/Integrator' */
  real_T Filter_CSTATE;        /* '<S79>/Filter' */
  real_T Integrator_CSTATE_f;  /* '<S36>/Integrator' */
  real_T Filter_CSTATE_f;      /* '<S31>/Filter' */
  real_T Integrator_CSTATE_fo; /* '<S132>/Integrator' */
  real_T Filter_CSTATE_l;      /* '<S127>/Filter' */
} XDot_AttitudeControl_T;

/* State disabled  */
typedef struct
{
  boolean_T Integrator_CSTATE;    /* '<S84>/Integrator' */
  boolean_T Filter_CSTATE;        /* '<S79>/Filter' */
  boolean_T Integrator_CSTATE_f;  /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE_f;      /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE_fo; /* '<S132>/Integrator' */
  boolean_T Filter_CSTATE_l;      /* '<S127>/Filter' */
} XDis_AttitudeControl_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct
{
  real_T *y;    /* output */
  real_T *f[3]; /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct
{
  real_T delta_omega_F;  /* '<Root>/delta_omega_F' */
  real_T des_Roll;       /* '<Root>/des_Roll' */
  real_T des_Pitch;      /* '<Root>/des_Pitch' */
  real_T des_Yaw;        /* '<Root>/des_Yaw' */
  real_T act_Roll;       /* '<Root>/act_Roll' */
  real_T act_Pitch;      /* '<Root>/act_Pitch' */
  real_T act_Yaw;        /* '<Root>/act_Yaw' */
  real_T k_roll_pid[3];  /* '<Root>/k_roll_pid' */
  real_T k_pitch_pid[3]; /* '<Root>/k_pitch_pid' */
  real_T k_yaw_pid[3];   /* '<Root>/k_yaw_pid' */
} ExtU_AttitudeControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct
{
  real_T omega1; /* '<Root>/omega1' */
  real_T omega2; /* '<Root>/omega2' */
  real_T omega3; /* '<Root>/omega3' */
  real_T omega4; /* '<Root>/omega4' */
} ExtY_AttitudeControl_T;

/* Parameters (default storage) */
struct P_AttitudeControl_T_
{
  real_T RollController_InitialCondition;
  /* Mask Parameter: RollController_InitialCondition
   * Referenced by: '<S79>/Filter'
   */
  real_T PitchController_InitialConditio;
  /* Mask Parameter: PitchController_InitialConditio
   * Referenced by: '<S31>/Filter'
   */
  real_T YawController_InitialConditionF;
  /* Mask Parameter: YawController_InitialConditionF
   * Referenced by: '<S127>/Filter'
   */
  real_T RollController_InitialConditi_f;
  /* Mask Parameter: RollController_InitialConditi_f
   * Referenced by: '<S84>/Integrator'
   */
  real_T PitchController_InitialCondit_d;
  /* Mask Parameter: PitchController_InitialCondit_d
   * Referenced by: '<S36>/Integrator'
   */
  real_T YawController_InitialConditio_h;
  /* Mask Parameter: YawController_InitialConditio_h
   * Referenced by: '<S132>/Integrator'
   */
  real_T Constant_Value; /* Expression: 100
                          * Referenced by: '<S1>/Constant'
                          */
  real_T Gain_Gain[16];  /* Expression: [1 0 1 -1;1 1 0 1;1 0 -1 -1;1 -1 0 1]
                          * Referenced by: '<Root>/Gain'
                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_AttitudeControl_T
{
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_AttitudeControl_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct
  {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct
  {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model AttitudeControl */
class AttitudeControlModelClass
{
  /* public data and function members */
public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  AttitudeControlModelClass();

  /* Destructor */
  ~AttitudeControlModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_AttitudeControl_T *pExtU_AttitudeControl_T)
  {
    AttitudeControl_U = *pExtU_AttitudeControl_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_AttitudeControl_T &getExternalOutputs() const
  {
    return AttitudeControl_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_AttitudeControl_T *getRTM();

  /* private data and function members */
private:
  /* Tunable parameters */
  static P_AttitudeControl_T AttitudeControl_P;

  /* Block signals */
  B_AttitudeControl_T AttitudeControl_B;
  X_AttitudeControl_T AttitudeControl_X; /* Block continuous states */

  /* External inputs */
  ExtU_AttitudeControl_T AttitudeControl_U;

  /* External outputs */
  ExtY_AttitudeControl_T AttitudeControl_Y;

  /* Real-Time Model */
  RT_MODEL_AttitudeControl_T AttitudeControl_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si);

  /* Derivatives member function */
  void AttitudeControl_derivatives();
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AttitudeControl'
 * '<S1>'   : 'AttitudeControl/Subsystem'
 * '<S2>'   : 'AttitudeControl/Subsystem/Pitch Controller'
 * '<S3>'   : 'AttitudeControl/Subsystem/Roll Controller'
 * '<S4>'   : 'AttitudeControl/Subsystem/Yaw Controller'
 * '<S5>'   : 'AttitudeControl/Subsystem/Pitch Controller/Anti-windup'
 * '<S6>'   : 'AttitudeControl/Subsystem/Pitch Controller/D Gain'
 * '<S7>'   : 'AttitudeControl/Subsystem/Pitch Controller/Filter'
 * '<S8>'   : 'AttitudeControl/Subsystem/Pitch Controller/Filter ICs'
 * '<S9>'   : 'AttitudeControl/Subsystem/Pitch Controller/I Gain'
 * '<S10>'  : 'AttitudeControl/Subsystem/Pitch Controller/Ideal P Gain'
 * '<S11>'  : 'AttitudeControl/Subsystem/Pitch Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'AttitudeControl/Subsystem/Pitch Controller/Integrator'
 * '<S13>'  : 'AttitudeControl/Subsystem/Pitch Controller/Integrator ICs'
 * '<S14>'  : 'AttitudeControl/Subsystem/Pitch Controller/N Copy'
 * '<S15>'  : 'AttitudeControl/Subsystem/Pitch Controller/N Gain'
 * '<S16>'  : 'AttitudeControl/Subsystem/Pitch Controller/P Copy'
 * '<S17>'  : 'AttitudeControl/Subsystem/Pitch Controller/Parallel P Gain'
 * '<S18>'  : 'AttitudeControl/Subsystem/Pitch Controller/Reset Signal'
 * '<S19>'  : 'AttitudeControl/Subsystem/Pitch Controller/Saturation'
 * '<S20>'  : 'AttitudeControl/Subsystem/Pitch Controller/Saturation Fdbk'
 * '<S21>'  : 'AttitudeControl/Subsystem/Pitch Controller/Sum'
 * '<S22>'  : 'AttitudeControl/Subsystem/Pitch Controller/Sum Fdbk'
 * '<S23>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tracking Mode'
 * '<S24>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tracking Mode Sum'
 * '<S25>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tsamp - Integral'
 * '<S26>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tsamp - Ngain'
 * '<S27>'  : 'AttitudeControl/Subsystem/Pitch Controller/postSat Signal'
 * '<S28>'  : 'AttitudeControl/Subsystem/Pitch Controller/preSat Signal'
 * '<S29>'  : 'AttitudeControl/Subsystem/Pitch Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'AttitudeControl/Subsystem/Pitch Controller/D Gain/External Parameters'
 * '<S31>'  : 'AttitudeControl/Subsystem/Pitch Controller/Filter/Cont. Filter'
 * '<S32>'  : 'AttitudeControl/Subsystem/Pitch Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'AttitudeControl/Subsystem/Pitch Controller/I Gain/External Parameters'
 * '<S34>'  : 'AttitudeControl/Subsystem/Pitch Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'AttitudeControl/Subsystem/Pitch Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'AttitudeControl/Subsystem/Pitch Controller/Integrator/Continuous'
 * '<S37>'  : 'AttitudeControl/Subsystem/Pitch Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'AttitudeControl/Subsystem/Pitch Controller/N Copy/Disabled'
 * '<S39>'  : 'AttitudeControl/Subsystem/Pitch Controller/N Gain/External Parameters'
 * '<S40>'  : 'AttitudeControl/Subsystem/Pitch Controller/P Copy/Disabled'
 * '<S41>'  : 'AttitudeControl/Subsystem/Pitch Controller/Parallel P Gain/External Parameters'
 * '<S42>'  : 'AttitudeControl/Subsystem/Pitch Controller/Reset Signal/Disabled'
 * '<S43>'  : 'AttitudeControl/Subsystem/Pitch Controller/Saturation/Passthrough'
 * '<S44>'  : 'AttitudeControl/Subsystem/Pitch Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'AttitudeControl/Subsystem/Pitch Controller/Sum/Sum_PID'
 * '<S46>'  : 'AttitudeControl/Subsystem/Pitch Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'AttitudeControl/Subsystem/Pitch Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'AttitudeControl/Subsystem/Pitch Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'AttitudeControl/Subsystem/Pitch Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'AttitudeControl/Subsystem/Roll Controller/Anti-windup'
 * '<S54>'  : 'AttitudeControl/Subsystem/Roll Controller/D Gain'
 * '<S55>'  : 'AttitudeControl/Subsystem/Roll Controller/Filter'
 * '<S56>'  : 'AttitudeControl/Subsystem/Roll Controller/Filter ICs'
 * '<S57>'  : 'AttitudeControl/Subsystem/Roll Controller/I Gain'
 * '<S58>'  : 'AttitudeControl/Subsystem/Roll Controller/Ideal P Gain'
 * '<S59>'  : 'AttitudeControl/Subsystem/Roll Controller/Ideal P Gain Fdbk'
 * '<S60>'  : 'AttitudeControl/Subsystem/Roll Controller/Integrator'
 * '<S61>'  : 'AttitudeControl/Subsystem/Roll Controller/Integrator ICs'
 * '<S62>'  : 'AttitudeControl/Subsystem/Roll Controller/N Copy'
 * '<S63>'  : 'AttitudeControl/Subsystem/Roll Controller/N Gain'
 * '<S64>'  : 'AttitudeControl/Subsystem/Roll Controller/P Copy'
 * '<S65>'  : 'AttitudeControl/Subsystem/Roll Controller/Parallel P Gain'
 * '<S66>'  : 'AttitudeControl/Subsystem/Roll Controller/Reset Signal'
 * '<S67>'  : 'AttitudeControl/Subsystem/Roll Controller/Saturation'
 * '<S68>'  : 'AttitudeControl/Subsystem/Roll Controller/Saturation Fdbk'
 * '<S69>'  : 'AttitudeControl/Subsystem/Roll Controller/Sum'
 * '<S70>'  : 'AttitudeControl/Subsystem/Roll Controller/Sum Fdbk'
 * '<S71>'  : 'AttitudeControl/Subsystem/Roll Controller/Tracking Mode'
 * '<S72>'  : 'AttitudeControl/Subsystem/Roll Controller/Tracking Mode Sum'
 * '<S73>'  : 'AttitudeControl/Subsystem/Roll Controller/Tsamp - Integral'
 * '<S74>'  : 'AttitudeControl/Subsystem/Roll Controller/Tsamp - Ngain'
 * '<S75>'  : 'AttitudeControl/Subsystem/Roll Controller/postSat Signal'
 * '<S76>'  : 'AttitudeControl/Subsystem/Roll Controller/preSat Signal'
 * '<S77>'  : 'AttitudeControl/Subsystem/Roll Controller/Anti-windup/Passthrough'
 * '<S78>'  : 'AttitudeControl/Subsystem/Roll Controller/D Gain/External Parameters'
 * '<S79>'  : 'AttitudeControl/Subsystem/Roll Controller/Filter/Cont. Filter'
 * '<S80>'  : 'AttitudeControl/Subsystem/Roll Controller/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'AttitudeControl/Subsystem/Roll Controller/I Gain/External Parameters'
 * '<S82>'  : 'AttitudeControl/Subsystem/Roll Controller/Ideal P Gain/Passthrough'
 * '<S83>'  : 'AttitudeControl/Subsystem/Roll Controller/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'AttitudeControl/Subsystem/Roll Controller/Integrator/Continuous'
 * '<S85>'  : 'AttitudeControl/Subsystem/Roll Controller/Integrator ICs/Internal IC'
 * '<S86>'  : 'AttitudeControl/Subsystem/Roll Controller/N Copy/Disabled'
 * '<S87>'  : 'AttitudeControl/Subsystem/Roll Controller/N Gain/External Parameters'
 * '<S88>'  : 'AttitudeControl/Subsystem/Roll Controller/P Copy/Disabled'
 * '<S89>'  : 'AttitudeControl/Subsystem/Roll Controller/Parallel P Gain/External Parameters'
 * '<S90>'  : 'AttitudeControl/Subsystem/Roll Controller/Reset Signal/Disabled'
 * '<S91>'  : 'AttitudeControl/Subsystem/Roll Controller/Saturation/Passthrough'
 * '<S92>'  : 'AttitudeControl/Subsystem/Roll Controller/Saturation Fdbk/Disabled'
 * '<S93>'  : 'AttitudeControl/Subsystem/Roll Controller/Sum/Sum_PID'
 * '<S94>'  : 'AttitudeControl/Subsystem/Roll Controller/Sum Fdbk/Disabled'
 * '<S95>'  : 'AttitudeControl/Subsystem/Roll Controller/Tracking Mode/Disabled'
 * '<S96>'  : 'AttitudeControl/Subsystem/Roll Controller/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'AttitudeControl/Subsystem/Roll Controller/Tsamp - Integral/Passthrough'
 * '<S98>'  : 'AttitudeControl/Subsystem/Roll Controller/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'AttitudeControl/Subsystem/Roll Controller/postSat Signal/Forward_Path'
 * '<S100>' : 'AttitudeControl/Subsystem/Roll Controller/preSat Signal/Forward_Path'
 * '<S101>' : 'AttitudeControl/Subsystem/Yaw Controller/Anti-windup'
 * '<S102>' : 'AttitudeControl/Subsystem/Yaw Controller/D Gain'
 * '<S103>' : 'AttitudeControl/Subsystem/Yaw Controller/Filter'
 * '<S104>' : 'AttitudeControl/Subsystem/Yaw Controller/Filter ICs'
 * '<S105>' : 'AttitudeControl/Subsystem/Yaw Controller/I Gain'
 * '<S106>' : 'AttitudeControl/Subsystem/Yaw Controller/Ideal P Gain'
 * '<S107>' : 'AttitudeControl/Subsystem/Yaw Controller/Ideal P Gain Fdbk'
 * '<S108>' : 'AttitudeControl/Subsystem/Yaw Controller/Integrator'
 * '<S109>' : 'AttitudeControl/Subsystem/Yaw Controller/Integrator ICs'
 * '<S110>' : 'AttitudeControl/Subsystem/Yaw Controller/N Copy'
 * '<S111>' : 'AttitudeControl/Subsystem/Yaw Controller/N Gain'
 * '<S112>' : 'AttitudeControl/Subsystem/Yaw Controller/P Copy'
 * '<S113>' : 'AttitudeControl/Subsystem/Yaw Controller/Parallel P Gain'
 * '<S114>' : 'AttitudeControl/Subsystem/Yaw Controller/Reset Signal'
 * '<S115>' : 'AttitudeControl/Subsystem/Yaw Controller/Saturation'
 * '<S116>' : 'AttitudeControl/Subsystem/Yaw Controller/Saturation Fdbk'
 * '<S117>' : 'AttitudeControl/Subsystem/Yaw Controller/Sum'
 * '<S118>' : 'AttitudeControl/Subsystem/Yaw Controller/Sum Fdbk'
 * '<S119>' : 'AttitudeControl/Subsystem/Yaw Controller/Tracking Mode'
 * '<S120>' : 'AttitudeControl/Subsystem/Yaw Controller/Tracking Mode Sum'
 * '<S121>' : 'AttitudeControl/Subsystem/Yaw Controller/Tsamp - Integral'
 * '<S122>' : 'AttitudeControl/Subsystem/Yaw Controller/Tsamp - Ngain'
 * '<S123>' : 'AttitudeControl/Subsystem/Yaw Controller/postSat Signal'
 * '<S124>' : 'AttitudeControl/Subsystem/Yaw Controller/preSat Signal'
 * '<S125>' : 'AttitudeControl/Subsystem/Yaw Controller/Anti-windup/Passthrough'
 * '<S126>' : 'AttitudeControl/Subsystem/Yaw Controller/D Gain/External Parameters'
 * '<S127>' : 'AttitudeControl/Subsystem/Yaw Controller/Filter/Cont. Filter'
 * '<S128>' : 'AttitudeControl/Subsystem/Yaw Controller/Filter ICs/Internal IC - Filter'
 * '<S129>' : 'AttitudeControl/Subsystem/Yaw Controller/I Gain/External Parameters'
 * '<S130>' : 'AttitudeControl/Subsystem/Yaw Controller/Ideal P Gain/Passthrough'
 * '<S131>' : 'AttitudeControl/Subsystem/Yaw Controller/Ideal P Gain Fdbk/Disabled'
 * '<S132>' : 'AttitudeControl/Subsystem/Yaw Controller/Integrator/Continuous'
 * '<S133>' : 'AttitudeControl/Subsystem/Yaw Controller/Integrator ICs/Internal IC'
 * '<S134>' : 'AttitudeControl/Subsystem/Yaw Controller/N Copy/Disabled'
 * '<S135>' : 'AttitudeControl/Subsystem/Yaw Controller/N Gain/External Parameters'
 * '<S136>' : 'AttitudeControl/Subsystem/Yaw Controller/P Copy/Disabled'
 * '<S137>' : 'AttitudeControl/Subsystem/Yaw Controller/Parallel P Gain/External Parameters'
 * '<S138>' : 'AttitudeControl/Subsystem/Yaw Controller/Reset Signal/Disabled'
 * '<S139>' : 'AttitudeControl/Subsystem/Yaw Controller/Saturation/Passthrough'
 * '<S140>' : 'AttitudeControl/Subsystem/Yaw Controller/Saturation Fdbk/Disabled'
 * '<S141>' : 'AttitudeControl/Subsystem/Yaw Controller/Sum/Sum_PID'
 * '<S142>' : 'AttitudeControl/Subsystem/Yaw Controller/Sum Fdbk/Disabled'
 * '<S143>' : 'AttitudeControl/Subsystem/Yaw Controller/Tracking Mode/Disabled'
 * '<S144>' : 'AttitudeControl/Subsystem/Yaw Controller/Tracking Mode Sum/Passthrough'
 * '<S145>' : 'AttitudeControl/Subsystem/Yaw Controller/Tsamp - Integral/Passthrough'
 * '<S146>' : 'AttitudeControl/Subsystem/Yaw Controller/Tsamp - Ngain/Passthrough'
 * '<S147>' : 'AttitudeControl/Subsystem/Yaw Controller/postSat Signal/Forward_Path'
 * '<S148>' : 'AttitudeControl/Subsystem/Yaw Controller/preSat Signal/Forward_Path'
 */
#endif /* RTW_HEADER_AttitudeControl_h_ */
