/*
 * HoverControl.h
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

#ifndef RTW_HEADER_HoverControl_h_
#define RTW_HEADER_HoverControl_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "HoverControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
  real_T NProdOut;                     /* '<S39>/NProd Out' */
  real_T NProdOut_h;                   /* '<S87>/NProd Out' */
  real_T NProdOut_b;                   /* '<S135>/NProd Out' */
  real_T IProdOut;                     /* '<S33>/IProd Out' */
  real_T IProdOut_l;                   /* '<S81>/IProd Out' */
  real_T IProdOut_m;                   /* '<S129>/IProd Out' */
} B_HoverControl_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S84>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S79>/Filter' */
  real_T Integrator_CSTATE_l;          /* '<S132>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S127>/Filter' */
} X_HoverControl_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S84>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S79>/Filter' */
  real_T Integrator_CSTATE_l;          /* '<S132>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S127>/Filter' */
} XDot_HoverControl_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE_j;       /* '<S84>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S79>/Filter' */
  boolean_T Integrator_CSTATE_l;       /* '<S132>/Integrator' */
  boolean_T Filter_CSTATE_c;           /* '<S127>/Filter' */
} XDis_HoverControl_T;

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
  real_T des[3];                       /* '<Root>/des' */
  real_T act[3];                       /* '<Root>/act' */
  real_T k_x_pid[3];                   /* '<Root>/k_x_pid' */
  real_T k_y_pid[3];                   /* '<Root>/k_y_pid' */
  real_T k_z_pid[3];                   /* '<Root>/k_z_pid' */
} ExtU_HoverControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ax;                           /* '<Root>/ax' */
  real_T ay;                           /* '<Root>/ay' */
  real_T az;                           /* '<Root>/az' */
} ExtY_HoverControl_T;

/* Parameters (default storage) */
struct P_HoverControl_T_ {
  real_T XController_InitialConditionFor;
                              /* Mask Parameter: XController_InitialConditionFor
                               * Referenced by: '<S31>/Filter'
                               */
  real_T YController_InitialConditionFor;
                              /* Mask Parameter: YController_InitialConditionFor
                               * Referenced by: '<S79>/Filter'
                               */
  real_T ZController_InitialConditionFor;
                              /* Mask Parameter: ZController_InitialConditionFor
                               * Referenced by: '<S127>/Filter'
                               */
  real_T XController_InitialConditionF_k;
                              /* Mask Parameter: XController_InitialConditionF_k
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T YController_InitialConditionF_h;
                              /* Mask Parameter: YController_InitialConditionF_h
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T ZController_InitialConditionF_k;
                              /* Mask Parameter: ZController_InitialConditionF_k
                               * Referenced by: '<S132>/Integrator'
                               */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_HoverControl_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_HoverControl_T *contStates;
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

/* Class declaration for model HoverControl */
class HoverControlModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  HoverControlModelClass();

  /* Destructor */
  ~HoverControlModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_HoverControl_T* pExtU_HoverControl_T)
  {
    HoverControl_U = *pExtU_HoverControl_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_HoverControl_T & getExternalOutputs() const
  {
    return HoverControl_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_HoverControl_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_HoverControl_T HoverControl_P;

  /* Block signals */
  B_HoverControl_T HoverControl_B;
  X_HoverControl_T HoverControl_X;     /* Block continuous states */

  /* External inputs */
  ExtU_HoverControl_T HoverControl_U;

  /* External outputs */
  ExtY_HoverControl_T HoverControl_Y;

  /* Real-Time Model */
  RT_MODEL_HoverControl_T HoverControl_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void HoverControl_derivatives();
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
 * '<Root>' : 'HoverControl'
 * '<S1>'   : 'HoverControl/Subsystem'
 * '<S2>'   : 'HoverControl/Subsystem/X Controller'
 * '<S3>'   : 'HoverControl/Subsystem/Y Controller'
 * '<S4>'   : 'HoverControl/Subsystem/Z Controller'
 * '<S5>'   : 'HoverControl/Subsystem/X Controller/Anti-windup'
 * '<S6>'   : 'HoverControl/Subsystem/X Controller/D Gain'
 * '<S7>'   : 'HoverControl/Subsystem/X Controller/Filter'
 * '<S8>'   : 'HoverControl/Subsystem/X Controller/Filter ICs'
 * '<S9>'   : 'HoverControl/Subsystem/X Controller/I Gain'
 * '<S10>'  : 'HoverControl/Subsystem/X Controller/Ideal P Gain'
 * '<S11>'  : 'HoverControl/Subsystem/X Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'HoverControl/Subsystem/X Controller/Integrator'
 * '<S13>'  : 'HoverControl/Subsystem/X Controller/Integrator ICs'
 * '<S14>'  : 'HoverControl/Subsystem/X Controller/N Copy'
 * '<S15>'  : 'HoverControl/Subsystem/X Controller/N Gain'
 * '<S16>'  : 'HoverControl/Subsystem/X Controller/P Copy'
 * '<S17>'  : 'HoverControl/Subsystem/X Controller/Parallel P Gain'
 * '<S18>'  : 'HoverControl/Subsystem/X Controller/Reset Signal'
 * '<S19>'  : 'HoverControl/Subsystem/X Controller/Saturation'
 * '<S20>'  : 'HoverControl/Subsystem/X Controller/Saturation Fdbk'
 * '<S21>'  : 'HoverControl/Subsystem/X Controller/Sum'
 * '<S22>'  : 'HoverControl/Subsystem/X Controller/Sum Fdbk'
 * '<S23>'  : 'HoverControl/Subsystem/X Controller/Tracking Mode'
 * '<S24>'  : 'HoverControl/Subsystem/X Controller/Tracking Mode Sum'
 * '<S25>'  : 'HoverControl/Subsystem/X Controller/Tsamp - Integral'
 * '<S26>'  : 'HoverControl/Subsystem/X Controller/Tsamp - Ngain'
 * '<S27>'  : 'HoverControl/Subsystem/X Controller/postSat Signal'
 * '<S28>'  : 'HoverControl/Subsystem/X Controller/preSat Signal'
 * '<S29>'  : 'HoverControl/Subsystem/X Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'HoverControl/Subsystem/X Controller/D Gain/External Parameters'
 * '<S31>'  : 'HoverControl/Subsystem/X Controller/Filter/Cont. Filter'
 * '<S32>'  : 'HoverControl/Subsystem/X Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'HoverControl/Subsystem/X Controller/I Gain/External Parameters'
 * '<S34>'  : 'HoverControl/Subsystem/X Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'HoverControl/Subsystem/X Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'HoverControl/Subsystem/X Controller/Integrator/Continuous'
 * '<S37>'  : 'HoverControl/Subsystem/X Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'HoverControl/Subsystem/X Controller/N Copy/Disabled'
 * '<S39>'  : 'HoverControl/Subsystem/X Controller/N Gain/External Parameters'
 * '<S40>'  : 'HoverControl/Subsystem/X Controller/P Copy/Disabled'
 * '<S41>'  : 'HoverControl/Subsystem/X Controller/Parallel P Gain/External Parameters'
 * '<S42>'  : 'HoverControl/Subsystem/X Controller/Reset Signal/Disabled'
 * '<S43>'  : 'HoverControl/Subsystem/X Controller/Saturation/Passthrough'
 * '<S44>'  : 'HoverControl/Subsystem/X Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'HoverControl/Subsystem/X Controller/Sum/Sum_PID'
 * '<S46>'  : 'HoverControl/Subsystem/X Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'HoverControl/Subsystem/X Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'HoverControl/Subsystem/X Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'HoverControl/Subsystem/X Controller/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'HoverControl/Subsystem/X Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'HoverControl/Subsystem/X Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'HoverControl/Subsystem/X Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'HoverControl/Subsystem/Y Controller/Anti-windup'
 * '<S54>'  : 'HoverControl/Subsystem/Y Controller/D Gain'
 * '<S55>'  : 'HoverControl/Subsystem/Y Controller/Filter'
 * '<S56>'  : 'HoverControl/Subsystem/Y Controller/Filter ICs'
 * '<S57>'  : 'HoverControl/Subsystem/Y Controller/I Gain'
 * '<S58>'  : 'HoverControl/Subsystem/Y Controller/Ideal P Gain'
 * '<S59>'  : 'HoverControl/Subsystem/Y Controller/Ideal P Gain Fdbk'
 * '<S60>'  : 'HoverControl/Subsystem/Y Controller/Integrator'
 * '<S61>'  : 'HoverControl/Subsystem/Y Controller/Integrator ICs'
 * '<S62>'  : 'HoverControl/Subsystem/Y Controller/N Copy'
 * '<S63>'  : 'HoverControl/Subsystem/Y Controller/N Gain'
 * '<S64>'  : 'HoverControl/Subsystem/Y Controller/P Copy'
 * '<S65>'  : 'HoverControl/Subsystem/Y Controller/Parallel P Gain'
 * '<S66>'  : 'HoverControl/Subsystem/Y Controller/Reset Signal'
 * '<S67>'  : 'HoverControl/Subsystem/Y Controller/Saturation'
 * '<S68>'  : 'HoverControl/Subsystem/Y Controller/Saturation Fdbk'
 * '<S69>'  : 'HoverControl/Subsystem/Y Controller/Sum'
 * '<S70>'  : 'HoverControl/Subsystem/Y Controller/Sum Fdbk'
 * '<S71>'  : 'HoverControl/Subsystem/Y Controller/Tracking Mode'
 * '<S72>'  : 'HoverControl/Subsystem/Y Controller/Tracking Mode Sum'
 * '<S73>'  : 'HoverControl/Subsystem/Y Controller/Tsamp - Integral'
 * '<S74>'  : 'HoverControl/Subsystem/Y Controller/Tsamp - Ngain'
 * '<S75>'  : 'HoverControl/Subsystem/Y Controller/postSat Signal'
 * '<S76>'  : 'HoverControl/Subsystem/Y Controller/preSat Signal'
 * '<S77>'  : 'HoverControl/Subsystem/Y Controller/Anti-windup/Passthrough'
 * '<S78>'  : 'HoverControl/Subsystem/Y Controller/D Gain/External Parameters'
 * '<S79>'  : 'HoverControl/Subsystem/Y Controller/Filter/Cont. Filter'
 * '<S80>'  : 'HoverControl/Subsystem/Y Controller/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'HoverControl/Subsystem/Y Controller/I Gain/External Parameters'
 * '<S82>'  : 'HoverControl/Subsystem/Y Controller/Ideal P Gain/Passthrough'
 * '<S83>'  : 'HoverControl/Subsystem/Y Controller/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'HoverControl/Subsystem/Y Controller/Integrator/Continuous'
 * '<S85>'  : 'HoverControl/Subsystem/Y Controller/Integrator ICs/Internal IC'
 * '<S86>'  : 'HoverControl/Subsystem/Y Controller/N Copy/Disabled'
 * '<S87>'  : 'HoverControl/Subsystem/Y Controller/N Gain/External Parameters'
 * '<S88>'  : 'HoverControl/Subsystem/Y Controller/P Copy/Disabled'
 * '<S89>'  : 'HoverControl/Subsystem/Y Controller/Parallel P Gain/External Parameters'
 * '<S90>'  : 'HoverControl/Subsystem/Y Controller/Reset Signal/Disabled'
 * '<S91>'  : 'HoverControl/Subsystem/Y Controller/Saturation/Passthrough'
 * '<S92>'  : 'HoverControl/Subsystem/Y Controller/Saturation Fdbk/Disabled'
 * '<S93>'  : 'HoverControl/Subsystem/Y Controller/Sum/Sum_PID'
 * '<S94>'  : 'HoverControl/Subsystem/Y Controller/Sum Fdbk/Disabled'
 * '<S95>'  : 'HoverControl/Subsystem/Y Controller/Tracking Mode/Disabled'
 * '<S96>'  : 'HoverControl/Subsystem/Y Controller/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'HoverControl/Subsystem/Y Controller/Tsamp - Integral/Passthrough'
 * '<S98>'  : 'HoverControl/Subsystem/Y Controller/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'HoverControl/Subsystem/Y Controller/postSat Signal/Forward_Path'
 * '<S100>' : 'HoverControl/Subsystem/Y Controller/preSat Signal/Forward_Path'
 * '<S101>' : 'HoverControl/Subsystem/Z Controller/Anti-windup'
 * '<S102>' : 'HoverControl/Subsystem/Z Controller/D Gain'
 * '<S103>' : 'HoverControl/Subsystem/Z Controller/Filter'
 * '<S104>' : 'HoverControl/Subsystem/Z Controller/Filter ICs'
 * '<S105>' : 'HoverControl/Subsystem/Z Controller/I Gain'
 * '<S106>' : 'HoverControl/Subsystem/Z Controller/Ideal P Gain'
 * '<S107>' : 'HoverControl/Subsystem/Z Controller/Ideal P Gain Fdbk'
 * '<S108>' : 'HoverControl/Subsystem/Z Controller/Integrator'
 * '<S109>' : 'HoverControl/Subsystem/Z Controller/Integrator ICs'
 * '<S110>' : 'HoverControl/Subsystem/Z Controller/N Copy'
 * '<S111>' : 'HoverControl/Subsystem/Z Controller/N Gain'
 * '<S112>' : 'HoverControl/Subsystem/Z Controller/P Copy'
 * '<S113>' : 'HoverControl/Subsystem/Z Controller/Parallel P Gain'
 * '<S114>' : 'HoverControl/Subsystem/Z Controller/Reset Signal'
 * '<S115>' : 'HoverControl/Subsystem/Z Controller/Saturation'
 * '<S116>' : 'HoverControl/Subsystem/Z Controller/Saturation Fdbk'
 * '<S117>' : 'HoverControl/Subsystem/Z Controller/Sum'
 * '<S118>' : 'HoverControl/Subsystem/Z Controller/Sum Fdbk'
 * '<S119>' : 'HoverControl/Subsystem/Z Controller/Tracking Mode'
 * '<S120>' : 'HoverControl/Subsystem/Z Controller/Tracking Mode Sum'
 * '<S121>' : 'HoverControl/Subsystem/Z Controller/Tsamp - Integral'
 * '<S122>' : 'HoverControl/Subsystem/Z Controller/Tsamp - Ngain'
 * '<S123>' : 'HoverControl/Subsystem/Z Controller/postSat Signal'
 * '<S124>' : 'HoverControl/Subsystem/Z Controller/preSat Signal'
 * '<S125>' : 'HoverControl/Subsystem/Z Controller/Anti-windup/Passthrough'
 * '<S126>' : 'HoverControl/Subsystem/Z Controller/D Gain/External Parameters'
 * '<S127>' : 'HoverControl/Subsystem/Z Controller/Filter/Cont. Filter'
 * '<S128>' : 'HoverControl/Subsystem/Z Controller/Filter ICs/Internal IC - Filter'
 * '<S129>' : 'HoverControl/Subsystem/Z Controller/I Gain/External Parameters'
 * '<S130>' : 'HoverControl/Subsystem/Z Controller/Ideal P Gain/Passthrough'
 * '<S131>' : 'HoverControl/Subsystem/Z Controller/Ideal P Gain Fdbk/Disabled'
 * '<S132>' : 'HoverControl/Subsystem/Z Controller/Integrator/Continuous'
 * '<S133>' : 'HoverControl/Subsystem/Z Controller/Integrator ICs/Internal IC'
 * '<S134>' : 'HoverControl/Subsystem/Z Controller/N Copy/Disabled'
 * '<S135>' : 'HoverControl/Subsystem/Z Controller/N Gain/External Parameters'
 * '<S136>' : 'HoverControl/Subsystem/Z Controller/P Copy/Disabled'
 * '<S137>' : 'HoverControl/Subsystem/Z Controller/Parallel P Gain/External Parameters'
 * '<S138>' : 'HoverControl/Subsystem/Z Controller/Reset Signal/Disabled'
 * '<S139>' : 'HoverControl/Subsystem/Z Controller/Saturation/Passthrough'
 * '<S140>' : 'HoverControl/Subsystem/Z Controller/Saturation Fdbk/Disabled'
 * '<S141>' : 'HoverControl/Subsystem/Z Controller/Sum/Sum_PID'
 * '<S142>' : 'HoverControl/Subsystem/Z Controller/Sum Fdbk/Disabled'
 * '<S143>' : 'HoverControl/Subsystem/Z Controller/Tracking Mode/Disabled'
 * '<S144>' : 'HoverControl/Subsystem/Z Controller/Tracking Mode Sum/Passthrough'
 * '<S145>' : 'HoverControl/Subsystem/Z Controller/Tsamp - Integral/Passthrough'
 * '<S146>' : 'HoverControl/Subsystem/Z Controller/Tsamp - Ngain/Passthrough'
 * '<S147>' : 'HoverControl/Subsystem/Z Controller/postSat Signal/Forward_Path'
 * '<S148>' : 'HoverControl/Subsystem/Z Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_HoverControl_h_ */
