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

	vec target;

	uint_T N;
	vec *track;
	double *speed;
} QuadRotorInputs;

typedef struct
{
	vec Xe;
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
	TrackControlModelClass *_track;
	HoverControlModelClass *_hover;
	PositionControlModelClass *_position;
	AttitudeControlModelClass *_attitude;
	MotorDynamicsModelClass *_motor;
	RotorDynamics *_rotor;
	Kinetics *_kin;

	QuadRotorArgs *_args;
	QuadRotorInputs *_inputs;
	QuadRotorOutputs *_outputs;
	QuadRotorStates *_states;

	void resetPtrs();
	bool initialized;
	bool terminated;
};
