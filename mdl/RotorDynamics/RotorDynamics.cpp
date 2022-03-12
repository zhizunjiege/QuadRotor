#include "RotorDynamics.h"


RotorDynamics::RotorDynamics() {
	resetPtrs();
	initialized = false;
	terminated = false;
}
RotorDynamics::~RotorDynamics() {
	if (!terminated)
		terminate();
	resetPtrs();
}

void RotorDynamics::initialize(RotorDynamicsArgs& args) {
	_args = new RotorDynamicsArgs();
	_inputs = new RotorDynamicsInputs({ 0,0,arma::vec(4),arma::vec(4) });
	_outputs = new RotorDynamicsOutputs({ arma::vec(3),arma::vec(3) });
	_states = new RotorDynamicsStates();

	*_args = args;

	initialized = true;
}

void RotorDynamics::step(double stepSize) {
	arma::vec tmp1 = { -_inputs->pitch,_inputs->roll,1 };
	arma::vec tmp2 = { 0,0,arma::sum(_inputs->FI) };
	_outputs->FO = _args->mass * 9.8 * tmp1 - tmp2;

	_outputs->MO(0) = _args->arm * (_inputs->FI(1) - _inputs->FI(3));
	_outputs->MO(1) = _args->arm * (_inputs->FI(0) - _inputs->FI(2));
	_outputs->MO(2) = _inputs->MI(1) - _inputs->MI(3) - _inputs->MI(0) - _inputs->MI(2);
}
void RotorDynamics::terminate() {
	delete _args;
	delete _inputs;
	delete _outputs;
	delete _states;
	resetPtrs();

	terminated = true;
}

void RotorDynamics::setInputs(RotorDynamicsInputs& inputs) {
	*_inputs = inputs;
}


const RotorDynamicsOutputs& RotorDynamics::getOutputs() {
	return *_outputs;
}

void RotorDynamics::resetPtrs()
{
	_args = nullptr;
	_inputs = nullptr;
	_outputs = nullptr;
	_states = nullptr;
}
