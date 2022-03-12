#pragma once
#ifndef QUAD_ROTOR_DYNAMICS_H
#define QUAD_ROTOR_DYNAMICS_H

#include "armadillo.h"

typedef struct {
	double arm;
	double mass;
} RotorDynamicsArgs;

typedef struct {
	double roll;
	double pitch;
	arma::vec FI;
	arma::vec MI;
} RotorDynamicsInputs;

typedef struct {
	arma::vec FO;
	arma::vec MO;
} RotorDynamicsOutputs;

typedef struct {
	/* Empty */
} RotorDynamicsStates;

class RotorDynamics {
public:
	RotorDynamics();
	~RotorDynamics();

	void initialize(RotorDynamicsArgs& args);
	void step(double stepSize);
	void terminate();
	void setInputs(RotorDynamicsInputs& inputs);
	const RotorDynamicsOutputs& getOutputs();

private:
	RotorDynamicsArgs* _args;
	RotorDynamicsInputs* _inputs;
	RotorDynamicsOutputs* _outputs;
	RotorDynamicsStates* _states;

	void resetPtrs();
	bool initialized;
	bool terminated;
};

#endif