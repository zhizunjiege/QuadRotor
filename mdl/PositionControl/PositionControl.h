/*
 * PositionControl.h
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

#ifndef RTW_HEADER_PositionControl_h_
#define RTW_HEADER_PositionControl_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "PositionControl_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<Root>/饱和函数_pitch' */
typedef struct
{
  real_T x_sat; /* '<Root>/饱和函数_pitch' */
} B__pitch_PositionControl_T;

/* Block signals (default storage) */
typedef struct
{
  B__pitch_PositionControl_T sf__roll;  /* '<Root>/饱和函数_roll' */
  B__pitch_PositionControl_T sf__pitch; /* '<Root>/饱和函数_pitch' */
} B_PositionControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct
{
  real_T ax;               /* '<Root>/ax' */
  real_T ay;               /* '<Root>/ay' */
  real_T az;               /* '<Root>/az' */
  real_T roll_pitch_limit; /* '<Root>/roll_pitch_limit' */
  real_T des_yaw;          /* '<Root>/des_yaw' */
  real_T az_gain;          /* '<Root>/az_gain' */
} ExtU_PositionControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct
{
  real_T delta_omega_F; /* '<Root>/delta_omega_F' */
  real_T des_Roll;      /* '<Root>/des_Roll' */
  real_T des_Pitch;     /* '<Root>/des_Pitch' */
} ExtY_PositionControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_PositionControl_T
{
  const char_T *errorStatus;
};

/* Class declaration for model PositionControl */
class PositionControlModelClass
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
  PositionControlModelClass();

  /* Destructor */
  ~PositionControlModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_PositionControl_T *pExtU_PositionControl_T)
  {
    PositionControl_U = *pExtU_PositionControl_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_PositionControl_T &getExternalOutputs() const
  {
    return PositionControl_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_PositionControl_T *getRTM();

  /* private data and function members */
private:
  /* Block signals */
  B_PositionControl_T PositionControl_B;

  /* External inputs */
  ExtU_PositionControl_T PositionControl_U;

  /* External outputs */
  ExtY_PositionControl_T PositionControl_Y;

  /* Real-Time Model */
  RT_MODEL_PositionControl_T PositionControl_M;

  /* private member function(s) for subsystem '<Root>/饱和函数_pitch'*/
  void PositionControl__pitch(real_T rtu_x, real_T rtu_limit,
                              B__pitch_PositionControl_T *localB);
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
 * '<Root>' : 'PositionControl'
 * '<S1>'   : 'PositionControl/交叉函数'
 * '<S2>'   : 'PositionControl/饱和函数_pitch'
 * '<S3>'   : 'PositionControl/饱和函数_roll'
 */
#endif /* RTW_HEADER_PositionControl_h_ */
