/*
 * TrackControl.h
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

#ifndef RTW_HEADER_TrackControl_h_
#define RTW_HEADER_TrackControl_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "TrackControl_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T u;                            /* '<Root>/一阶延迟' */
  real_T u_g;                          /* '<Root>/航段计数器' */
  real_T NProdOut;                     /* '<S188>/NProd Out' */
  real_T NProdOut_h;                   /* '<S43>/NProd Out' */
  real_T NProdOut_d;                   /* '<S236>/NProd Out' */
  real_T NProdOut_c;                   /* '<S91>/NProd Out' */
  real_T NProdOut_du;                  /* '<S284>/NProd Out' */
  real_T NProdOut_hy;                  /* '<S140>/NProd Out' */
  real_T IProdOut;                     /* '<S37>/IProd Out' */
  real_T IProdOut_o;                   /* '<S85>/IProd Out' */
  real_T IProdOut_g;                   /* '<S134>/IProd Out' */
  real_T IProdOut_m;                   /* '<S182>/IProd Out' */
  real_T IProdOut_k;                   /* '<S230>/IProd Out' */
  real_T IProdOut_n;                   /* '<S278>/IProd Out' */
  real_T trigger;                      /* '<Root>/数学计算' */
} B_TrackControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T _DSTATE;                      /* '<Root>/一阶延迟' */
  uint32_T _ClkEphState;               /* '<Root>/航段计数器' */
  uint32_T _RstEphState;               /* '<Root>/航段计数器' */
  uint8_T _Count;                      /* '<Root>/航段计数器' */
} DW_TrackControl_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S185>/Integrator' */
  real_T Filter_CSTATE;                /* '<S180>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S40>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S35>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S233>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S228>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S88>/Integrator' */
  real_T Filter_CSTATE_m;              /* '<S83>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S281>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S276>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S137>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S132>/Filter' */
} X_TrackControl_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S185>/Integrator' */
  real_T Filter_CSTATE;                /* '<S180>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S40>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S35>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S233>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S228>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S88>/Integrator' */
  real_T Filter_CSTATE_m;              /* '<S83>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S281>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S276>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S137>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S132>/Filter' */
} XDot_TrackControl_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S185>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S180>/Filter' */
  boolean_T Integrator_CSTATE_j;       /* '<S40>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S35>/Filter' */
  boolean_T Integrator_CSTATE_m;       /* '<S233>/Integrator' */
  boolean_T Filter_CSTATE_k;           /* '<S228>/Filter' */
  boolean_T Integrator_CSTATE_b;       /* '<S88>/Integrator' */
  boolean_T Filter_CSTATE_m;           /* '<S83>/Filter' */
  boolean_T Integrator_CSTATE_f;       /* '<S281>/Integrator' */
  boolean_T Filter_CSTATE_f;           /* '<S276>/Filter' */
  boolean_T Integrator_CSTATE_e;       /* '<S137>/Integrator' */
  boolean_T Filter_CSTATE_o;           /* '<S132>/Filter' */
} XDis_TrackControl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S185>/Integrator' */
  ZCSigState Filter_Reset_ZCE;         /* '<S180>/Filter' */
  ZCSigState Integrator_Reset_ZCE_h;   /* '<S40>/Integrator' */
  ZCSigState Filter_Reset_ZCE_k;       /* '<S35>/Filter' */
  ZCSigState Integrator_Reset_ZCE_g;   /* '<S233>/Integrator' */
  ZCSigState Filter_Reset_ZCE_j;       /* '<S228>/Filter' */
  ZCSigState Integrator_Reset_ZCE_b;   /* '<S88>/Integrator' */
  ZCSigState Filter_Reset_ZCE_g;       /* '<S83>/Filter' */
  ZCSigState Integrator_Reset_ZCE_a;   /* '<S281>/Integrator' */
  ZCSigState Filter_Reset_ZCE_h;       /* '<S276>/Filter' */
  ZCSigState Integrator_Reset_ZCE_p;   /* '<S137>/Integrator' */
  ZCSigState Filter_Reset_ZCE_o;       /* '<S132>/Filter' */
} PrevZCX_TrackControl_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T position[3];                  /* '<Root>/position' */
  real_T velocity[3];                  /* '<Root>/velocity' */
  real_T X[100];                       /* '<Root>/X' */
  real_T Y[100];                       /* '<Root>/Y' */
  real_T Z[100];                       /* '<Root>/Z' */
  real_T V[100];                       /* '<Root>/V' */
  real_T ect_x_pid[3];                 /* '<Root>/ect_x_pid' */
  real_T ect_y_pid[3];                 /* '<Root>/ect_y_pid' */
  real_T ect_z_pid[3];                 /* '<Root>/ect_z_pid' */
  real_T eat_x_pid[3];                 /* '<Root>/eat_x_pid' */
  real_T eat_y_pid[3];                 /* '<Root>/eat_y_pid' */
  real_T eat_z_pid[3];                 /* '<Root>/eat_z_pid' */
  real_T N;                            /* '<Root>/N' */
} ExtU_TrackControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ax;                           /* '<Root>/ax' */
  real_T ay;                           /* '<Root>/ay' */
  real_T az;                           /* '<Root>/az' */
} ExtY_TrackControl_T;

/* Parameters (default storage) */
struct P_TrackControl_T_ {
  real_T pid_limit;                    /* Variable: pid_limit
                                        * Referenced by:
                                        *   '<S47>/Saturation'
                                        *   '<S95>/Saturation'
                                        *   '<S192>/Saturation'
                                        *   '<S240>/Saturation'
                                        *   '<S288>/Saturation'
                                        *   '<S144>/Saturation'
                                        */
  real_T ect_x_InitialConditionForFilter;
                              /* Mask Parameter: ect_x_InitialConditionForFilter
                               * Referenced by: '<S180>/Filter'
                               */
  real_T eat_x_InitialConditionForFilter;
                              /* Mask Parameter: eat_x_InitialConditionForFilter
                               * Referenced by: '<S35>/Filter'
                               */
  real_T ect_y_InitialConditionForFilter;
                              /* Mask Parameter: ect_y_InitialConditionForFilter
                               * Referenced by: '<S228>/Filter'
                               */
  real_T eat_y_InitialConditionForFilter;
                              /* Mask Parameter: eat_y_InitialConditionForFilter
                               * Referenced by: '<S83>/Filter'
                               */
  real_T ect_z_InitialConditionForFilter;
                              /* Mask Parameter: ect_z_InitialConditionForFilter
                               * Referenced by: '<S276>/Filter'
                               */
  real_T eat_z_InitialConditionForFilter;
                              /* Mask Parameter: eat_z_InitialConditionForFilter
                               * Referenced by: '<S132>/Filter'
                               */
  real_T ect_x_InitialConditionForIntegr;
                              /* Mask Parameter: ect_x_InitialConditionForIntegr
                               * Referenced by: '<S185>/Integrator'
                               */
  real_T eat_x_InitialConditionForIntegr;
                              /* Mask Parameter: eat_x_InitialConditionForIntegr
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T ect_y_InitialConditionForIntegr;
                              /* Mask Parameter: ect_y_InitialConditionForIntegr
                               * Referenced by: '<S233>/Integrator'
                               */
  real_T eat_y_InitialConditionForIntegr;
                              /* Mask Parameter: eat_y_InitialConditionForIntegr
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T ect_z_InitialConditionForIntegr;
                              /* Mask Parameter: ect_z_InitialConditionForIntegr
                               * Referenced by: '<S281>/Integrator'
                               */
  real_T eat_z_InitialConditionForIntegr;
                              /* Mask Parameter: eat_z_InitialConditionForIntegr
                               * Referenced by: '<S137>/Integrator'
                               */
  uint8_T _InitialCount;               /* Mask Parameter: _InitialCount
                                        * Referenced by: '<Root>/航段计数器'
                                        */
  real_T _InitialCondition;            /* Expression: 0.0
                                        * Referenced by: '<Root>/一阶延迟'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<Root>/复位'
                                        */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrackControl_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_TrackControl_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
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

/* Class declaration for model TrackControl */
class TrackControlModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  TrackControlModelClass();

  /* Destructor */
  ~TrackControlModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_TrackControl_T* pExtU_TrackControl_T)
  {
    TrackControl_U = *pExtU_TrackControl_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_TrackControl_T & getExternalOutputs() const
  {
    return TrackControl_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_TrackControl_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_TrackControl_T TrackControl_P;

  /* Block signals */
  B_TrackControl_T TrackControl_B;

  /* Block states */
  DW_TrackControl_T TrackControl_DW;
  X_TrackControl_T TrackControl_X;     /* Block continuous states */
  PrevZCX_TrackControl_T TrackControl_PrevZCX;/* Triggered events */

  /* External inputs */
  ExtU_TrackControl_T TrackControl_U;

  /* External outputs */
  ExtY_TrackControl_T TrackControl_Y;

  /* Real-Time Model */
  RT_MODEL_TrackControl_T TrackControl_M;

  /* private member function(s) for subsystem '<Root>'*/
  real_T TrackControl_norm(const real_T x[3]);

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void TrackControl_derivatives();
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
 * '<Root>' : 'TrackControl'
 * '<S1>'   : 'TrackControl/eat_x'
 * '<S2>'   : 'TrackControl/eat_y'
 * '<S3>'   : 'TrackControl/eat_z'
 * '<S4>'   : 'TrackControl/ect_x'
 * '<S5>'   : 'TrackControl/ect_y'
 * '<S6>'   : 'TrackControl/ect_z'
 * '<S7>'   : 'TrackControl/数学计算'
 * '<S8>'   : 'TrackControl/生成索引'
 * '<S9>'   : 'TrackControl/eat_x/Anti-windup'
 * '<S10>'  : 'TrackControl/eat_x/D Gain'
 * '<S11>'  : 'TrackControl/eat_x/Filter'
 * '<S12>'  : 'TrackControl/eat_x/Filter ICs'
 * '<S13>'  : 'TrackControl/eat_x/I Gain'
 * '<S14>'  : 'TrackControl/eat_x/Ideal P Gain'
 * '<S15>'  : 'TrackControl/eat_x/Ideal P Gain Fdbk'
 * '<S16>'  : 'TrackControl/eat_x/Integrator'
 * '<S17>'  : 'TrackControl/eat_x/Integrator ICs'
 * '<S18>'  : 'TrackControl/eat_x/N Copy'
 * '<S19>'  : 'TrackControl/eat_x/N Gain'
 * '<S20>'  : 'TrackControl/eat_x/P Copy'
 * '<S21>'  : 'TrackControl/eat_x/Parallel P Gain'
 * '<S22>'  : 'TrackControl/eat_x/Reset Signal'
 * '<S23>'  : 'TrackControl/eat_x/Saturation'
 * '<S24>'  : 'TrackControl/eat_x/Saturation Fdbk'
 * '<S25>'  : 'TrackControl/eat_x/Sum'
 * '<S26>'  : 'TrackControl/eat_x/Sum Fdbk'
 * '<S27>'  : 'TrackControl/eat_x/Tracking Mode'
 * '<S28>'  : 'TrackControl/eat_x/Tracking Mode Sum'
 * '<S29>'  : 'TrackControl/eat_x/Tsamp - Integral'
 * '<S30>'  : 'TrackControl/eat_x/Tsamp - Ngain'
 * '<S31>'  : 'TrackControl/eat_x/postSat Signal'
 * '<S32>'  : 'TrackControl/eat_x/preSat Signal'
 * '<S33>'  : 'TrackControl/eat_x/Anti-windup/Passthrough'
 * '<S34>'  : 'TrackControl/eat_x/D Gain/External Parameters'
 * '<S35>'  : 'TrackControl/eat_x/Filter/Cont. Filter'
 * '<S36>'  : 'TrackControl/eat_x/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'TrackControl/eat_x/I Gain/External Parameters'
 * '<S38>'  : 'TrackControl/eat_x/Ideal P Gain/Passthrough'
 * '<S39>'  : 'TrackControl/eat_x/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'TrackControl/eat_x/Integrator/Continuous'
 * '<S41>'  : 'TrackControl/eat_x/Integrator ICs/Internal IC'
 * '<S42>'  : 'TrackControl/eat_x/N Copy/Disabled'
 * '<S43>'  : 'TrackControl/eat_x/N Gain/External Parameters'
 * '<S44>'  : 'TrackControl/eat_x/P Copy/Disabled'
 * '<S45>'  : 'TrackControl/eat_x/Parallel P Gain/External Parameters'
 * '<S46>'  : 'TrackControl/eat_x/Reset Signal/External Reset'
 * '<S47>'  : 'TrackControl/eat_x/Saturation/Enabled'
 * '<S48>'  : 'TrackControl/eat_x/Saturation Fdbk/Disabled'
 * '<S49>'  : 'TrackControl/eat_x/Sum/Sum_PID'
 * '<S50>'  : 'TrackControl/eat_x/Sum Fdbk/Disabled'
 * '<S51>'  : 'TrackControl/eat_x/Tracking Mode/Disabled'
 * '<S52>'  : 'TrackControl/eat_x/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'TrackControl/eat_x/Tsamp - Integral/Passthrough'
 * '<S54>'  : 'TrackControl/eat_x/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'TrackControl/eat_x/postSat Signal/Forward_Path'
 * '<S56>'  : 'TrackControl/eat_x/preSat Signal/Forward_Path'
 * '<S57>'  : 'TrackControl/eat_y/Anti-windup'
 * '<S58>'  : 'TrackControl/eat_y/D Gain'
 * '<S59>'  : 'TrackControl/eat_y/Filter'
 * '<S60>'  : 'TrackControl/eat_y/Filter ICs'
 * '<S61>'  : 'TrackControl/eat_y/I Gain'
 * '<S62>'  : 'TrackControl/eat_y/Ideal P Gain'
 * '<S63>'  : 'TrackControl/eat_y/Ideal P Gain Fdbk'
 * '<S64>'  : 'TrackControl/eat_y/Integrator'
 * '<S65>'  : 'TrackControl/eat_y/Integrator ICs'
 * '<S66>'  : 'TrackControl/eat_y/N Copy'
 * '<S67>'  : 'TrackControl/eat_y/N Gain'
 * '<S68>'  : 'TrackControl/eat_y/P Copy'
 * '<S69>'  : 'TrackControl/eat_y/Parallel P Gain'
 * '<S70>'  : 'TrackControl/eat_y/Reset Signal'
 * '<S71>'  : 'TrackControl/eat_y/Saturation'
 * '<S72>'  : 'TrackControl/eat_y/Saturation Fdbk'
 * '<S73>'  : 'TrackControl/eat_y/Sum'
 * '<S74>'  : 'TrackControl/eat_y/Sum Fdbk'
 * '<S75>'  : 'TrackControl/eat_y/Tracking Mode'
 * '<S76>'  : 'TrackControl/eat_y/Tracking Mode Sum'
 * '<S77>'  : 'TrackControl/eat_y/Tsamp - Integral'
 * '<S78>'  : 'TrackControl/eat_y/Tsamp - Ngain'
 * '<S79>'  : 'TrackControl/eat_y/postSat Signal'
 * '<S80>'  : 'TrackControl/eat_y/preSat Signal'
 * '<S81>'  : 'TrackControl/eat_y/Anti-windup/Passthrough'
 * '<S82>'  : 'TrackControl/eat_y/D Gain/External Parameters'
 * '<S83>'  : 'TrackControl/eat_y/Filter/Cont. Filter'
 * '<S84>'  : 'TrackControl/eat_y/Filter ICs/Internal IC - Filter'
 * '<S85>'  : 'TrackControl/eat_y/I Gain/External Parameters'
 * '<S86>'  : 'TrackControl/eat_y/Ideal P Gain/Passthrough'
 * '<S87>'  : 'TrackControl/eat_y/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'TrackControl/eat_y/Integrator/Continuous'
 * '<S89>'  : 'TrackControl/eat_y/Integrator ICs/Internal IC'
 * '<S90>'  : 'TrackControl/eat_y/N Copy/Disabled'
 * '<S91>'  : 'TrackControl/eat_y/N Gain/External Parameters'
 * '<S92>'  : 'TrackControl/eat_y/P Copy/Disabled'
 * '<S93>'  : 'TrackControl/eat_y/Parallel P Gain/External Parameters'
 * '<S94>'  : 'TrackControl/eat_y/Reset Signal/External Reset'
 * '<S95>'  : 'TrackControl/eat_y/Saturation/Enabled'
 * '<S96>'  : 'TrackControl/eat_y/Saturation Fdbk/Disabled'
 * '<S97>'  : 'TrackControl/eat_y/Sum/Sum_PID'
 * '<S98>'  : 'TrackControl/eat_y/Sum Fdbk/Disabled'
 * '<S99>'  : 'TrackControl/eat_y/Tracking Mode/Disabled'
 * '<S100>' : 'TrackControl/eat_y/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'TrackControl/eat_y/Tsamp - Integral/Passthrough'
 * '<S102>' : 'TrackControl/eat_y/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'TrackControl/eat_y/postSat Signal/Forward_Path'
 * '<S104>' : 'TrackControl/eat_y/preSat Signal/Forward_Path'
 * '<S105>' : 'TrackControl/eat_z/eat_z'
 * '<S106>' : 'TrackControl/eat_z/eat_z/Anti-windup'
 * '<S107>' : 'TrackControl/eat_z/eat_z/D Gain'
 * '<S108>' : 'TrackControl/eat_z/eat_z/Filter'
 * '<S109>' : 'TrackControl/eat_z/eat_z/Filter ICs'
 * '<S110>' : 'TrackControl/eat_z/eat_z/I Gain'
 * '<S111>' : 'TrackControl/eat_z/eat_z/Ideal P Gain'
 * '<S112>' : 'TrackControl/eat_z/eat_z/Ideal P Gain Fdbk'
 * '<S113>' : 'TrackControl/eat_z/eat_z/Integrator'
 * '<S114>' : 'TrackControl/eat_z/eat_z/Integrator ICs'
 * '<S115>' : 'TrackControl/eat_z/eat_z/N Copy'
 * '<S116>' : 'TrackControl/eat_z/eat_z/N Gain'
 * '<S117>' : 'TrackControl/eat_z/eat_z/P Copy'
 * '<S118>' : 'TrackControl/eat_z/eat_z/Parallel P Gain'
 * '<S119>' : 'TrackControl/eat_z/eat_z/Reset Signal'
 * '<S120>' : 'TrackControl/eat_z/eat_z/Saturation'
 * '<S121>' : 'TrackControl/eat_z/eat_z/Saturation Fdbk'
 * '<S122>' : 'TrackControl/eat_z/eat_z/Sum'
 * '<S123>' : 'TrackControl/eat_z/eat_z/Sum Fdbk'
 * '<S124>' : 'TrackControl/eat_z/eat_z/Tracking Mode'
 * '<S125>' : 'TrackControl/eat_z/eat_z/Tracking Mode Sum'
 * '<S126>' : 'TrackControl/eat_z/eat_z/Tsamp - Integral'
 * '<S127>' : 'TrackControl/eat_z/eat_z/Tsamp - Ngain'
 * '<S128>' : 'TrackControl/eat_z/eat_z/postSat Signal'
 * '<S129>' : 'TrackControl/eat_z/eat_z/preSat Signal'
 * '<S130>' : 'TrackControl/eat_z/eat_z/Anti-windup/Passthrough'
 * '<S131>' : 'TrackControl/eat_z/eat_z/D Gain/External Parameters'
 * '<S132>' : 'TrackControl/eat_z/eat_z/Filter/Cont. Filter'
 * '<S133>' : 'TrackControl/eat_z/eat_z/Filter ICs/Internal IC - Filter'
 * '<S134>' : 'TrackControl/eat_z/eat_z/I Gain/External Parameters'
 * '<S135>' : 'TrackControl/eat_z/eat_z/Ideal P Gain/Passthrough'
 * '<S136>' : 'TrackControl/eat_z/eat_z/Ideal P Gain Fdbk/Disabled'
 * '<S137>' : 'TrackControl/eat_z/eat_z/Integrator/Continuous'
 * '<S138>' : 'TrackControl/eat_z/eat_z/Integrator ICs/Internal IC'
 * '<S139>' : 'TrackControl/eat_z/eat_z/N Copy/Disabled'
 * '<S140>' : 'TrackControl/eat_z/eat_z/N Gain/External Parameters'
 * '<S141>' : 'TrackControl/eat_z/eat_z/P Copy/Disabled'
 * '<S142>' : 'TrackControl/eat_z/eat_z/Parallel P Gain/External Parameters'
 * '<S143>' : 'TrackControl/eat_z/eat_z/Reset Signal/External Reset'
 * '<S144>' : 'TrackControl/eat_z/eat_z/Saturation/Enabled'
 * '<S145>' : 'TrackControl/eat_z/eat_z/Saturation Fdbk/Disabled'
 * '<S146>' : 'TrackControl/eat_z/eat_z/Sum/Sum_PID'
 * '<S147>' : 'TrackControl/eat_z/eat_z/Sum Fdbk/Disabled'
 * '<S148>' : 'TrackControl/eat_z/eat_z/Tracking Mode/Disabled'
 * '<S149>' : 'TrackControl/eat_z/eat_z/Tracking Mode Sum/Passthrough'
 * '<S150>' : 'TrackControl/eat_z/eat_z/Tsamp - Integral/Passthrough'
 * '<S151>' : 'TrackControl/eat_z/eat_z/Tsamp - Ngain/Passthrough'
 * '<S152>' : 'TrackControl/eat_z/eat_z/postSat Signal/Forward_Path'
 * '<S153>' : 'TrackControl/eat_z/eat_z/preSat Signal/Forward_Path'
 * '<S154>' : 'TrackControl/ect_x/Anti-windup'
 * '<S155>' : 'TrackControl/ect_x/D Gain'
 * '<S156>' : 'TrackControl/ect_x/Filter'
 * '<S157>' : 'TrackControl/ect_x/Filter ICs'
 * '<S158>' : 'TrackControl/ect_x/I Gain'
 * '<S159>' : 'TrackControl/ect_x/Ideal P Gain'
 * '<S160>' : 'TrackControl/ect_x/Ideal P Gain Fdbk'
 * '<S161>' : 'TrackControl/ect_x/Integrator'
 * '<S162>' : 'TrackControl/ect_x/Integrator ICs'
 * '<S163>' : 'TrackControl/ect_x/N Copy'
 * '<S164>' : 'TrackControl/ect_x/N Gain'
 * '<S165>' : 'TrackControl/ect_x/P Copy'
 * '<S166>' : 'TrackControl/ect_x/Parallel P Gain'
 * '<S167>' : 'TrackControl/ect_x/Reset Signal'
 * '<S168>' : 'TrackControl/ect_x/Saturation'
 * '<S169>' : 'TrackControl/ect_x/Saturation Fdbk'
 * '<S170>' : 'TrackControl/ect_x/Sum'
 * '<S171>' : 'TrackControl/ect_x/Sum Fdbk'
 * '<S172>' : 'TrackControl/ect_x/Tracking Mode'
 * '<S173>' : 'TrackControl/ect_x/Tracking Mode Sum'
 * '<S174>' : 'TrackControl/ect_x/Tsamp - Integral'
 * '<S175>' : 'TrackControl/ect_x/Tsamp - Ngain'
 * '<S176>' : 'TrackControl/ect_x/postSat Signal'
 * '<S177>' : 'TrackControl/ect_x/preSat Signal'
 * '<S178>' : 'TrackControl/ect_x/Anti-windup/Passthrough'
 * '<S179>' : 'TrackControl/ect_x/D Gain/External Parameters'
 * '<S180>' : 'TrackControl/ect_x/Filter/Cont. Filter'
 * '<S181>' : 'TrackControl/ect_x/Filter ICs/Internal IC - Filter'
 * '<S182>' : 'TrackControl/ect_x/I Gain/External Parameters'
 * '<S183>' : 'TrackControl/ect_x/Ideal P Gain/Passthrough'
 * '<S184>' : 'TrackControl/ect_x/Ideal P Gain Fdbk/Disabled'
 * '<S185>' : 'TrackControl/ect_x/Integrator/Continuous'
 * '<S186>' : 'TrackControl/ect_x/Integrator ICs/Internal IC'
 * '<S187>' : 'TrackControl/ect_x/N Copy/Disabled'
 * '<S188>' : 'TrackControl/ect_x/N Gain/External Parameters'
 * '<S189>' : 'TrackControl/ect_x/P Copy/Disabled'
 * '<S190>' : 'TrackControl/ect_x/Parallel P Gain/External Parameters'
 * '<S191>' : 'TrackControl/ect_x/Reset Signal/External Reset'
 * '<S192>' : 'TrackControl/ect_x/Saturation/Enabled'
 * '<S193>' : 'TrackControl/ect_x/Saturation Fdbk/Disabled'
 * '<S194>' : 'TrackControl/ect_x/Sum/Sum_PID'
 * '<S195>' : 'TrackControl/ect_x/Sum Fdbk/Disabled'
 * '<S196>' : 'TrackControl/ect_x/Tracking Mode/Disabled'
 * '<S197>' : 'TrackControl/ect_x/Tracking Mode Sum/Passthrough'
 * '<S198>' : 'TrackControl/ect_x/Tsamp - Integral/Passthrough'
 * '<S199>' : 'TrackControl/ect_x/Tsamp - Ngain/Passthrough'
 * '<S200>' : 'TrackControl/ect_x/postSat Signal/Forward_Path'
 * '<S201>' : 'TrackControl/ect_x/preSat Signal/Forward_Path'
 * '<S202>' : 'TrackControl/ect_y/Anti-windup'
 * '<S203>' : 'TrackControl/ect_y/D Gain'
 * '<S204>' : 'TrackControl/ect_y/Filter'
 * '<S205>' : 'TrackControl/ect_y/Filter ICs'
 * '<S206>' : 'TrackControl/ect_y/I Gain'
 * '<S207>' : 'TrackControl/ect_y/Ideal P Gain'
 * '<S208>' : 'TrackControl/ect_y/Ideal P Gain Fdbk'
 * '<S209>' : 'TrackControl/ect_y/Integrator'
 * '<S210>' : 'TrackControl/ect_y/Integrator ICs'
 * '<S211>' : 'TrackControl/ect_y/N Copy'
 * '<S212>' : 'TrackControl/ect_y/N Gain'
 * '<S213>' : 'TrackControl/ect_y/P Copy'
 * '<S214>' : 'TrackControl/ect_y/Parallel P Gain'
 * '<S215>' : 'TrackControl/ect_y/Reset Signal'
 * '<S216>' : 'TrackControl/ect_y/Saturation'
 * '<S217>' : 'TrackControl/ect_y/Saturation Fdbk'
 * '<S218>' : 'TrackControl/ect_y/Sum'
 * '<S219>' : 'TrackControl/ect_y/Sum Fdbk'
 * '<S220>' : 'TrackControl/ect_y/Tracking Mode'
 * '<S221>' : 'TrackControl/ect_y/Tracking Mode Sum'
 * '<S222>' : 'TrackControl/ect_y/Tsamp - Integral'
 * '<S223>' : 'TrackControl/ect_y/Tsamp - Ngain'
 * '<S224>' : 'TrackControl/ect_y/postSat Signal'
 * '<S225>' : 'TrackControl/ect_y/preSat Signal'
 * '<S226>' : 'TrackControl/ect_y/Anti-windup/Passthrough'
 * '<S227>' : 'TrackControl/ect_y/D Gain/External Parameters'
 * '<S228>' : 'TrackControl/ect_y/Filter/Cont. Filter'
 * '<S229>' : 'TrackControl/ect_y/Filter ICs/Internal IC - Filter'
 * '<S230>' : 'TrackControl/ect_y/I Gain/External Parameters'
 * '<S231>' : 'TrackControl/ect_y/Ideal P Gain/Passthrough'
 * '<S232>' : 'TrackControl/ect_y/Ideal P Gain Fdbk/Disabled'
 * '<S233>' : 'TrackControl/ect_y/Integrator/Continuous'
 * '<S234>' : 'TrackControl/ect_y/Integrator ICs/Internal IC'
 * '<S235>' : 'TrackControl/ect_y/N Copy/Disabled'
 * '<S236>' : 'TrackControl/ect_y/N Gain/External Parameters'
 * '<S237>' : 'TrackControl/ect_y/P Copy/Disabled'
 * '<S238>' : 'TrackControl/ect_y/Parallel P Gain/External Parameters'
 * '<S239>' : 'TrackControl/ect_y/Reset Signal/External Reset'
 * '<S240>' : 'TrackControl/ect_y/Saturation/Enabled'
 * '<S241>' : 'TrackControl/ect_y/Saturation Fdbk/Disabled'
 * '<S242>' : 'TrackControl/ect_y/Sum/Sum_PID'
 * '<S243>' : 'TrackControl/ect_y/Sum Fdbk/Disabled'
 * '<S244>' : 'TrackControl/ect_y/Tracking Mode/Disabled'
 * '<S245>' : 'TrackControl/ect_y/Tracking Mode Sum/Passthrough'
 * '<S246>' : 'TrackControl/ect_y/Tsamp - Integral/Passthrough'
 * '<S247>' : 'TrackControl/ect_y/Tsamp - Ngain/Passthrough'
 * '<S248>' : 'TrackControl/ect_y/postSat Signal/Forward_Path'
 * '<S249>' : 'TrackControl/ect_y/preSat Signal/Forward_Path'
 * '<S250>' : 'TrackControl/ect_z/Anti-windup'
 * '<S251>' : 'TrackControl/ect_z/D Gain'
 * '<S252>' : 'TrackControl/ect_z/Filter'
 * '<S253>' : 'TrackControl/ect_z/Filter ICs'
 * '<S254>' : 'TrackControl/ect_z/I Gain'
 * '<S255>' : 'TrackControl/ect_z/Ideal P Gain'
 * '<S256>' : 'TrackControl/ect_z/Ideal P Gain Fdbk'
 * '<S257>' : 'TrackControl/ect_z/Integrator'
 * '<S258>' : 'TrackControl/ect_z/Integrator ICs'
 * '<S259>' : 'TrackControl/ect_z/N Copy'
 * '<S260>' : 'TrackControl/ect_z/N Gain'
 * '<S261>' : 'TrackControl/ect_z/P Copy'
 * '<S262>' : 'TrackControl/ect_z/Parallel P Gain'
 * '<S263>' : 'TrackControl/ect_z/Reset Signal'
 * '<S264>' : 'TrackControl/ect_z/Saturation'
 * '<S265>' : 'TrackControl/ect_z/Saturation Fdbk'
 * '<S266>' : 'TrackControl/ect_z/Sum'
 * '<S267>' : 'TrackControl/ect_z/Sum Fdbk'
 * '<S268>' : 'TrackControl/ect_z/Tracking Mode'
 * '<S269>' : 'TrackControl/ect_z/Tracking Mode Sum'
 * '<S270>' : 'TrackControl/ect_z/Tsamp - Integral'
 * '<S271>' : 'TrackControl/ect_z/Tsamp - Ngain'
 * '<S272>' : 'TrackControl/ect_z/postSat Signal'
 * '<S273>' : 'TrackControl/ect_z/preSat Signal'
 * '<S274>' : 'TrackControl/ect_z/Anti-windup/Passthrough'
 * '<S275>' : 'TrackControl/ect_z/D Gain/External Parameters'
 * '<S276>' : 'TrackControl/ect_z/Filter/Cont. Filter'
 * '<S277>' : 'TrackControl/ect_z/Filter ICs/Internal IC - Filter'
 * '<S278>' : 'TrackControl/ect_z/I Gain/External Parameters'
 * '<S279>' : 'TrackControl/ect_z/Ideal P Gain/Passthrough'
 * '<S280>' : 'TrackControl/ect_z/Ideal P Gain Fdbk/Disabled'
 * '<S281>' : 'TrackControl/ect_z/Integrator/Continuous'
 * '<S282>' : 'TrackControl/ect_z/Integrator ICs/Internal IC'
 * '<S283>' : 'TrackControl/ect_z/N Copy/Disabled'
 * '<S284>' : 'TrackControl/ect_z/N Gain/External Parameters'
 * '<S285>' : 'TrackControl/ect_z/P Copy/Disabled'
 * '<S286>' : 'TrackControl/ect_z/Parallel P Gain/External Parameters'
 * '<S287>' : 'TrackControl/ect_z/Reset Signal/External Reset'
 * '<S288>' : 'TrackControl/ect_z/Saturation/Enabled'
 * '<S289>' : 'TrackControl/ect_z/Saturation Fdbk/Disabled'
 * '<S290>' : 'TrackControl/ect_z/Sum/Sum_PID'
 * '<S291>' : 'TrackControl/ect_z/Sum Fdbk/Disabled'
 * '<S292>' : 'TrackControl/ect_z/Tracking Mode/Disabled'
 * '<S293>' : 'TrackControl/ect_z/Tracking Mode Sum/Passthrough'
 * '<S294>' : 'TrackControl/ect_z/Tsamp - Integral/Passthrough'
 * '<S295>' : 'TrackControl/ect_z/Tsamp - Ngain/Passthrough'
 * '<S296>' : 'TrackControl/ect_z/postSat Signal/Forward_Path'
 * '<S297>' : 'TrackControl/ect_z/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_TrackControl_h_ */
