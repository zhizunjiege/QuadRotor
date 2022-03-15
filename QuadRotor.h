#pragma once

#include "armadillo.h"

#include "mdl/AttitudeControl/AttitudeControl.h"
#include "mdl/HoverControl/HoverControl.h"
#include "mdl/KineticsDoF6/Kinetics.h"
#include "mdl/MotorDynamics/MotorDynamics.h"
#include "mdl/PositionControl/PositionControl.h"
#include "mdl/RotorDynamics/RotorDynamics.h"
#include "mdl/TrackControl/TrackControl.h"

using namespace arma;

typedef struct
{
	double p;
	double i;
	double d;
} PID;

typedef struct
{
	vec initXe;
	vec initVb;
	vec initOmega;
	vec initEuler;

	mat inertia;
	double arm;
	double mass;

	double Kf;
	double Km;
	double Kt;
	double rpmMax;
	double rpmMin;

	PID kRoll;
	PID kPitch;
	PID kYaw;
	PID kX;
	PID kY;
	PID kZ;

	PID kEctX;
	PID kEctY;
	PID kEctZ;
	PID kEatX;
	PID kEatY;
	PID kEatZ;

	double limitPID;
	double limitRollPitch;
} QuadRotorArgs;

enum FlightMode
{
	HOVER,
	TRACK,
};

typedef struct
{
	FlightMode mode;
	double desYaw;

	vec target;

	uint_T N;
	double *X;
	double *Y;
	double *Z;
	double *V;
} QuadRotorInputs;

typedef struct
{
	vec Xe;
	vec Ve;
	vec Vb;
	vec Omega;
	vec Euler;

	mat DCM;
	double alpha;
	double beta;
} QuadRotorOutputs;

typedef struct
{
	double omegaH;
	double azGain;
	vec Fb;
	vec Mb;
} QuadRotorStates;

class QuadRotor
{
public:
	QuadRotor();
	~QuadRotor();

	void initialize(QuadRotorArgs &args);
	void step(double stepSize);
	void terminate();
	void setInputs(QuadRotorInputs &inputs);
	const QuadRotorOutputs &getOutputs();

private:
	void internalStep(double stepSize);

	const static double maxStepSize;

	QuadRotorArgs *_args;
	QuadRotorInputs *_inputs;
	QuadRotorOutputs *_outputs;
	QuadRotorStates *_states;

	TrackControlModelClass *_track;
	HoverControlModelClass *_hover;
	PositionControlModelClass *_position;
	AttitudeControlModelClass *_attitude;
	MotorDynamicsModelClass *_motor;
	RotorDynamics *_rotor;
	Kinetics *_kin;

	void resetPtrs();
	bool initialized;
	bool terminated;

	ExtU_TrackControl_T *_trackInputs;
	ExtU_HoverControl_T *_hoverInputs;
	ExtU_PositionControl_T *_positionInputs;
	ExtU_AttitudeControl_T *_attitudeInputs;
	ExtU_MotorDynamics_T *_motorInputs;
	RotorDynamicsInputs *_rotorInputs;
};
