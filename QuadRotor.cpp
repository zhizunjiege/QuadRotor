#include "QuadRotor.h"

QuadRotor::QuadRotor()
{
	resetPtrs();
	initialized = false;
	terminated = false;
}

QuadRotor::~QuadRotor()
{
	if (!terminated)
		terminate();
	resetPtrs();
}

void QuadRotor::initialize(QuadRotorArgs &args)
{
	_args = new QuadRotorArgs({vec(3), vec(3), vec(3), vec(3), mat(3, 3)});
	_inputs = new QuadRotorInputs({FlightMode::HOVER, vec(3)});
	_outputs = new QuadRotorOutputs({vec(3), vec(3), vec(3), vec(3), mat(3, 3)});
	_states = new QuadRotorStates();

	*_args = args;

	_kin = new Kinetics(args.initXe, args.initVb, args.initOmega, args.initEuler);

	_rotor = new RotorDynamics();
	_rotor->initialize({args.arm, args.mass});

	_motor = new MotorDynamicsModelClass();
	_motor->initialize();
	_motor->setKt(args.Kt);

	_attitude = new AttitudeControlModelClass();
	_attitude->initialize();

	_position = new PositionControlModelClass();
	_position->initialize();

	_hover = new HoverControlModelClass();
	_hover->initialize();

	_track = new TrackControlModelClass();
	_track->initialize();

	initialized = true;
}

void QuadRotor::step(double stepSize) {}

void QuadRotor::terminate()
{
	delete _args;
	delete _inputs;
	delete _outputs;
	delete _states;

	_track->terminate();
	_hover->terminate();
	_position->terminate();
	_attitude->terminate();
	_motor->terminate();
	_rotor->terminate();
	delete _track;
	delete _hover;
	delete _position;
	delete _attitude;
	delete _motor;
	delete _rotor;
	delete _kin;

	terminated = true;
}

void QuadRotor::setInputs(QuadRotorInputs &inputs)
{
	*_inputs = inputs;
	// TODO
}

const QuadRotorOutputs &QuadRotor::getOutputs() {}

void QuadRotor::resetPtrs()
{
	_args = nullptr;
	_inputs = nullptr;
	_outputs = nullptr;
	_states = nullptr;

	_track = nullptr;
	_hover = nullptr;
	_position = nullptr;
	_attitude = nullptr;
	_motor = nullptr;
	_rotor = nullptr;
	_kin = nullptr;
}
