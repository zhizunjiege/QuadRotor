#include "QuadRotor.h"

const double QuadRotor::maxStepSize = 0.01;

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
	_inputs = new QuadRotorInputs({FlightMode::HOVER, 0.0, vec(3)});
	_outputs = new QuadRotorOutputs({vec(3), vec(3), vec(3), vec(3), vec(3), mat(3, 3)});
	_states = new QuadRotorStates();

	*_args = args;
	_states->omegaH = sqrt(args.mass * 9.8 / args.Kf / 4);
	_states->azGain = -args.mass / 8 / args.Kf * _states->omegaH;

	_track = new TrackControlModelClass();
	_track->initialize();
	_trackInputs = new ExtU_TrackControl_T({
		{},
		{},
		{},
		{},
		{},
		{},
		{args.kEctX.p, args.kEctX.i, args.kEctX.d},
		{args.kEctY.p, args.kEctY.i, args.kEctY.d},
		{args.kEctZ.p, args.kEctZ.i, args.kEctZ.d},
		{args.kEatX.p, args.kEatX.i, args.kEatX.d},
		{args.kEatY.p, args.kEatY.i, args.kEatY.d},
		{args.kEatZ.p, args.kEatZ.i, args.kEatZ.d},
		0.0,
	});

	_hover = new HoverControlModelClass();
	_hover->initialize();
	_hoverInputs = new ExtU_HoverControl_T({
		{},
		{},
		{args.kX.p, args.kX.i, args.kX.d},
		{args.kY.p, args.kY.i, args.kY.d},
		{args.kZ.p, args.kZ.i, args.kZ.d},
	});

	_position = new PositionControlModelClass();
	_position->initialize();
	_positionInputs = new ExtU_PositionControl_T({
		0.0,
		0.0,
		0.0,
		args.limitRollPitch,
		0.0,
		_states->azGain,
	});

	_attitude = new AttitudeControlModelClass();
	_attitude->initialize();
	_attitudeInputs = new ExtU_AttitudeControl_T({
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		{args.kRoll.p, args.kRoll.i, args.kRoll.d},
		{args.kPitch.p, args.kPitch.i, args.kPitch.d},
		{args.kYaw.p, args.kYaw.i, args.kYaw.d},
	});

	_motor = new MotorDynamicsModelClass();
	_motor->initialize();
	_motor->setKt(args.Kt);
	_motorInputs = new ExtU_MotorDynamics_T({
		0.0,
		0.0,
		0.0,
		0.0,
		args.rpmMax,
		args.rpmMin,
		_states->omegaH,
		args.Kf,
		args.Km,
	});

	_rotor = new RotorDynamics();
	_rotor->initialize({args.arm, args.mass});
	_rotorInputs = new RotorDynamicsInputs();

	_kin = new Kinetics(args.initXe, args.initVb, args.initOmega, args.initEuler);

	initialized = true;
}

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

	delete _trackInputs;
	delete _hoverInputs;
	delete _positionInputs;
	delete _attitudeInputs;
	delete _motorInputs;
	delete _rotorInputs;

	terminated = true;
}

void QuadRotor::setInputs(QuadRotorInputs &inputs)
{
	*_inputs = inputs;

	auto vel = _kin->GetVe();
	auto pos = _kin->GetXe();
	auto euler = _kin->GetEuler();
	if (inputs.mode == FlightMode::TRACK)
	{
		_trackInputs->position[0] = pos(0);
		_trackInputs->position[1] = pos(1);
		_trackInputs->position[2] = pos(2);
		_trackInputs->velocity[0] = vel(0);
		_trackInputs->velocity[1] = vel(1);
		_trackInputs->velocity[2] = vel(2);
		int preSize = sizeof(FlightMode) + sizeof(double) + sizeof(vec);
		int flag = memcmp(&inputs + preSize, _inputs + preSize, sizeof(QuadRotorInputs) - preSize);
		if (flag != 0)
		{
			// 无法严格断定是新航段
			_track->resetCounter();
			memcpy(_trackInputs->X, inputs.X, inputs.N);
			memcpy(_trackInputs->Y, inputs.Y, inputs.N);
			memcpy(_trackInputs->Z, inputs.Z, inputs.N);
			memcpy(_trackInputs->V, inputs.V, inputs.N);
			_trackInputs->N = inputs.N;
		}
		_track->setExternalInputs(_trackInputs);

		auto trackOutputs = _track->getExternalOutputs();
		_positionInputs->ax = trackOutputs.ax;
		_positionInputs->ay = trackOutputs.ay;
		_positionInputs->az = trackOutputs.az;
	}
	else
	{
		_hoverInputs->des[0] = inputs.target(0);
		_hoverInputs->des[1] = inputs.target(1);
		_hoverInputs->des[2] = inputs.target(2);
		_hoverInputs->act[0] = pos(0);
		_hoverInputs->act[1] = pos(1);
		_hoverInputs->act[2] = pos(2);
		_hover->setExternalInputs(_hoverInputs);

		auto hoverOutputs = _hover->getExternalOutputs();
		_positionInputs->ax = hoverOutputs.ax;
		_positionInputs->ay = hoverOutputs.ay;
		_positionInputs->az = hoverOutputs.az;
	}
	_positionInputs->des_yaw = inputs.desYaw;
	_position->setExternalInputs(_positionInputs);

	auto positionOutputs = _position->getExternalOutputs();
	_attitudeInputs->delta_omega_F = positionOutputs.delta_omega_F;
	_attitudeInputs->des_Roll = positionOutputs.des_Roll;
	_attitudeInputs->des_Pitch = positionOutputs.des_Pitch;
	_attitudeInputs->des_Yaw = inputs.desYaw;
	_attitudeInputs->act_Roll = euler(0);
	_attitudeInputs->act_Pitch = euler(1);
	_attitudeInputs->act_Yaw = euler(2);
	_attitude->setExternalInputs(_attitudeInputs);

	auto attitudeOutputs = _attitude->getExternalOutputs();
	_motorInputs->omega1 = attitudeOutputs.omega1;
	_motorInputs->omega2 = attitudeOutputs.omega2;
	_motorInputs->omega3 = attitudeOutputs.omega3;
	_motorInputs->omega4 = attitudeOutputs.omega4;
	_motor->setExternalInputs(_motorInputs);

	auto motorOutputs = _motor->getExternalOutputs();
	_rotorInputs->roll = euler(0);
	_rotorInputs->pitch = euler(1);
	(_rotorInputs->FI)(0) = motorOutputs.F[0];
	(_rotorInputs->FI)(1) = motorOutputs.F[1];
	(_rotorInputs->FI)(2) = motorOutputs.F[2];
	(_rotorInputs->FI)(3) = motorOutputs.F[3];
	(_rotorInputs->MI)(0) = motorOutputs.M[0];
	(_rotorInputs->MI)(1) = motorOutputs.M[1];
	(_rotorInputs->MI)(2) = motorOutputs.M[2];
	(_rotorInputs->MI)(3) = motorOutputs.M[3];
	_rotor->setInputs(*_rotorInputs);

	auto rotorOutputs = _rotor->getOutputs();
	_states->Fb = rotorOutputs.FO;
	_states->Mb = rotorOutputs.MO;
}

void QuadRotor::step(double stepSize)
{
	auto q = floor(stepSize / maxStepSize);
	auto r = stepSize - q * maxStepSize;

	for (auto i = 0; i < q; q++)
	{
		internalStep(maxStepSize);
	}
	if (r > 0)
	{
		internalStep(r);
	}
}

void QuadRotor::internalStep(double stepSize)
{
	auto trackRTM = _track->getRTM();
	trackRTM->Timing.stepSize0 = stepSize;
	_track->step();

	auto hoverRTM = _hover->getRTM();
	hoverRTM->Timing.stepSize0 = stepSize;
	_hover->step();

	_position->step();

	auto attitudeRTM = _attitude->getRTM();
	attitudeRTM->Timing.stepSize0 = stepSize;
	_attitude->step();

	auto motorRTM = _motor->getRTM();
	motorRTM->Timing.stepSize0 = stepSize;
	_motor->step();

	_rotor->step(stepSize);

	_kin->UpdateState(_states->Fb, _states->Mb, _args->inertia, _args->mass, stepSize);
}

const QuadRotorOutputs &QuadRotor::getOutputs()
{
	_outputs->Xe = _kin->GetXe();
	_outputs->Ve = _kin->GetVe();
	_outputs->Vb = _kin->GetVb();
	_outputs->Omega = _kin->GetOmega();
	_outputs->Euler = _kin->GetEuler();
	_outputs->DCM = _kin->GetReb();
	_outputs->alpha = _kin->GetAlpha();
	_outputs->beta = _kin->GetBeta();
	return *_outputs;
}

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

	_trackInputs = nullptr;
	_hoverInputs = nullptr;
	_positionInputs = nullptr;
	_attitudeInputs = nullptr;
	_motorInputs = nullptr;
	_rotorInputs = nullptr;
}
