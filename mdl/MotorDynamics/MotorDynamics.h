/*
 * MotorDynamics.h
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

#ifndef RTW_HEADER_MotorDynamics_h_
#define RTW_HEADER_MotorDynamics_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MotorDynamics_types.h"

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

/* Continuous states (default storage) */
typedef struct
{
  real_T TransferFcn_CSTATE;  /* '<Root>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE; /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE; /* '<Root>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE; /* '<Root>/Transfer Fcn3' */
} X_MotorDynamics_T;

/* State derivatives (default storage) */
typedef struct
{
  real_T TransferFcn_CSTATE;  /* '<Root>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE; /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE; /* '<Root>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE; /* '<Root>/Transfer Fcn3' */
} XDot_MotorDynamics_T;

/* State disabled  */
typedef struct
{
  boolean_T TransferFcn_CSTATE;  /* '<Root>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE; /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE; /* '<Root>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE; /* '<Root>/Transfer Fcn3' */
} XDis_MotorDynamics_T;

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
  real_T omega1;  /* '<Root>/omega1' */
  real_T omega2;  /* '<Root>/omega2' */
  real_T omega3;  /* '<Root>/omega3' */
  real_T omega4;  /* '<Root>/omega4' */
  real_T rpm_max; /* '<Root>/rpm_max' */
  real_T rpm_min; /* '<Root>/rpm_min' */
  real_T omega_h; /* '<Root>/omega_h' */
  real_T Kf;      /* '<Root>/Kf' */
  real_T Km;      /* '<Root>/Km' */
} ExtU_MotorDynamics_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct
{
  real_T F[4]; /* '<Root>/F' */
  real_T M[4]; /* '<Root>/M' */
} ExtY_MotorDynamics_T;

/* Parameters (default storage) */
struct P_MotorDynamics_T_
{
  real_T TransferFcn_A;  /* Computed Parameter: TransferFcn_A
                          * Referenced by: '<Root>/Transfer Fcn'
                          */
  real_T TransferFcn_C;  /* Computed Parameter: TransferFcn_C
                          * Referenced by: '<Root>/Transfer Fcn'
                          */
  real_T TransferFcn1_A; /* Computed Parameter: TransferFcn1_A
                          * Referenced by: '<Root>/Transfer Fcn1'
                          */
  real_T TransferFcn1_C; /* Computed Parameter: TransferFcn1_C
                          * Referenced by: '<Root>/Transfer Fcn1'
                          */
  real_T TransferFcn2_A; /* Computed Parameter: TransferFcn2_A
                          * Referenced by: '<Root>/Transfer Fcn2'
                          */
  real_T TransferFcn2_C; /* Computed Parameter: TransferFcn2_C
                          * Referenced by: '<Root>/Transfer Fcn2'
                          */
  real_T TransferFcn3_A; /* Computed Parameter: TransferFcn3_A
                          * Referenced by: '<Root>/Transfer Fcn3'
                          */
  real_T TransferFcn3_C; /* Computed Parameter: TransferFcn3_C
                          * Referenced by: '<Root>/Transfer Fcn3'
                          */
  real_T _Gain;          /* Expression: 30/3.1415926535
                          * Referenced by: '<Root>/��λת��'
                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_MotorDynamics_T
{
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_MotorDynamics_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
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

/* Class declaration for model MotorDynamics */
class MotorDynamicsModelClass
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
  MotorDynamicsModelClass();

  /* Destructor */
  ~MotorDynamicsModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_MotorDynamics_T *pExtU_MotorDynamics_T)
  {
    MotorDynamics_U = *pExtU_MotorDynamics_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_MotorDynamics_T &getExternalOutputs() const
  {
    return MotorDynamics_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_MotorDynamics_T *getRTM();

  /* private data and function members */
private:
  /* Tunable parameters */
  static P_MotorDynamics_T MotorDynamics_P;
  X_MotorDynamics_T MotorDynamics_X; /* Block continuous states */

  /* External inputs */
  ExtU_MotorDynamics_T MotorDynamics_U;

  /* External outputs */
  ExtY_MotorDynamics_T MotorDynamics_Y;

  /* Real-Time Model */
  RT_MODEL_MotorDynamics_T MotorDynamics_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si);

  /* Derivatives member function */
  void MotorDynamics_derivatives();
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
 * '<Root>' : 'MotorDynamics'
 * '<S1>'   : 'MotorDynamics/���ͺ���'
 */
#endif /* RTW_HEADER_MotorDynamics_h_ */
