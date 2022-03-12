#include"Kinetics.h"


KineticsBase::KineticsBase(arma::vec Xe, arma::vec Vb, arma::vec Omega, arma::vec Euler)
{
	ResetState(Xe, Vb, Omega, Euler);
}
//״̬��ʼ��
void KineticsBase::ResetState(arma::vec Xe_in, arma::vec Vb_in, arma::vec Omega_in, arma::vec Euler_in)
{
	Xe = Xe_in;
	Vb = Vb_in;
	Omega = Omega_in;
	Quaternion = EulerToQuaternion(Euler_in);
}
//״̬����
void KineticsBase::UpdateState(arma::vec Fb, arma::vec Mb, arma::mat Inertia, double Mass, double StepLength)
{

	//�������������
	arma::vec X1(13);
	X1.rows(0, 2) = Omega;
	X1.rows(3, 5) = Vb;
	X1.rows(6, 9) = Quaternion; 
	X1.rows(10, 12) = Xe;


	//�Ľ����������
	arma::vec K1 = CalX_dot(Fb, Mb, Inertia, Mass, X1.rows(0, 2), X1.rows(3, 5), X1.rows(6, 9));
	
	arma::vec X2 = X1 + K1 * StepLength*0.5;
	arma::vec K2 = CalX_dot(Fb, Mb, Inertia, Mass, X2.rows(0, 2), X2.rows(3, 5), X2.rows(6, 9));


	arma::vec X3 = X1 + K2 * StepLength*0.5;
	arma::vec K3 = CalX_dot(Fb, Mb, Inertia, Mass, X3.rows(0, 2), X3.rows(3, 5), X3.rows(6, 9));

	arma::vec X4 = X1 + K3 * StepLength;
	arma::vec K4 = CalX_dot(Fb, Mb, Inertia, Mass, X4.rows(0, 2), X4.rows(3, 5), X4.rows(6, 9));

	arma::vec X_next = X1 + (K1 + 2 * K2 + 2 * K3 + K4)*StepLength / 6;

	Omega = X_next.rows(0, 2);
	Vb = X_next.rows(3, 5);
	Quaternion = X_next.rows(6, 9);
	Xe = X_next.rows(10, 12);

}

arma::vec KineticsBase::CalX_dot(arma::vec Fb,arma::vec Mb,arma::mat Inertia,double Mass, arma::vec Omega_in, arma::vec Vb_in,arma::vec Quaternion_in)
{
	//Vb�仯��
	arma::vec Vb_dot = Fb / Mass - arma::cross(Omega_in, Vb_in);

	//Omega�仯��
	arma::vec Omega_dot = arma::inv(Inertia)*(Mb - arma::cross(Omega_in, (Inertia*Omega_in)));

	//Quaternion�仯��
	arma::vec Quaternion_dot(4);
	//���¼��㹫ʽ��Matlab����
	Quaternion_dot[0] = ((-Omega_in[0] * Quaternion_in[1] +
		-Omega_in[1] * Quaternion_in[2]) + -Omega_in[2] *
		Quaternion_in[3]) * 0.5;
	Quaternion_dot[1] = ((Omega_in[0] * Quaternion_in[0] +
		Omega_in[2] * Quaternion_in[2]) + -Omega_in[1] *
		Quaternion_in[3]) * 0.5;
	Quaternion_dot[2] = ((Quaternion_in[0] * Omega_in[1] +
		-Omega_in[2] * Quaternion_in[1]) + Omega_in[0] *
		Quaternion_in[3]) * 0.5;
	Quaternion_dot[3] = ((Quaternion_in[0] * Omega_in[2] +
		Omega_in[1] * Quaternion_in[1]) + -Omega_in[0] *
		Quaternion_in[2]) * 0.5;

	//Xe�仯��
	arma::vec Xe_dot = GetReb(QuaternionToEuler(Quaternion_in)).t()*Vb_in;//Reb�������������ת�þ���ȡ��

	arma::vec X_dot(13);
	X_dot.rows(0, 2) = Vb_dot;
	X_dot.rows(3, 5) = Omega_dot;
	X_dot.rows(6, 9) = Quaternion_dot;
	X_dot.rows(10, 12) = Xe_dot;

	return X_dot;
}

arma::vec KineticsBase::EulerToQuaternion(arma::vec Euler)
{
	//ƫ����
	double psi = Euler(0);
	//������
	double theta = Euler(1);
	//��ת��
	double phi = Euler(2);
	//������Ԫ�����

	arma::vec Quaternion(4);

	//���´����Ǵ�Matlab�������޸ĵ�
	double Q_tmp;
	double Q_tmp_0;
	double rtb_sincos_o1;
	double rtb_sincos_o1_idx_0;
	double rtb_sincos_o1_idx_1;
	double rtb_u2;
	double rtb_u2_h;
	double rtb_u2_l;

	rtb_u2 = 0.5 * psi;
	rtb_u2_h = cos(rtb_u2);
	rtb_sincos_o1_idx_0 = sin(rtb_u2);

	rtb_u2 = 0.5 * theta;

	rtb_u2_l = cos(rtb_u2);

	rtb_sincos_o1_idx_1 = sin(rtb_u2);

	rtb_u2 = 0.5 * phi;

	rtb_sincos_o1 = sin(rtb_u2);
	rtb_u2 = cos(rtb_u2);

	Q_tmp = rtb_u2_h * rtb_u2_l;
	Q_tmp_0 = rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1;

	Quaternion(0) = Q_tmp * rtb_u2 + Q_tmp_0 * rtb_sincos_o1;
	Quaternion(1) = Q_tmp * rtb_sincos_o1 - Q_tmp_0 * rtb_u2;


	rtb_sincos_o1_idx_0 *= rtb_u2_l;
	rtb_sincos_o1_idx_1 *= rtb_u2_h;


	Quaternion(2) = rtb_sincos_o1_idx_1 * rtb_u2 + rtb_sincos_o1_idx_0 *
		rtb_sincos_o1;
	Quaternion(3) = rtb_sincos_o1_idx_0 * rtb_u2 - rtb_sincos_o1_idx_1 *
		rtb_sincos_o1;

	return Quaternion;
}
arma::vec KineticsBase::QuaternionToEuler(arma::vec Quaternion)
{
	double q0 = Quaternion(0);
	double q1 = Quaternion(1);
	double q2 = Quaternion(2);
	double q3 = Quaternion(3);

	//һ�´����Matlab�������޸�
	double Output_tmp;
	double Output_tmp_0;
	double Output_tmp_1;
	double Output_tmp_2;
	double rtb_Product1;
	double rtb_Product2;
	double rtb_Product3;
	double rtb_fcn3;
	double rtb_fcn5;

	rtb_Product3 = sqrt(((Quaternion(0) * Quaternion(0) + Quaternion(1) *
		Quaternion(1)) + Quaternion(2) * Quaternion(2)) +
		Quaternion(3) * Quaternion(3));

	rtb_fcn5 = Quaternion(0) / rtb_Product3;

	rtb_Product1 = Quaternion(1) / rtb_Product3;

	rtb_Product2 = Quaternion(2) / rtb_Product3;

	rtb_Product3 = Quaternion(3) / rtb_Product3;

	Output_tmp = rtb_fcn5 * rtb_fcn5;
	Output_tmp_0 = rtb_Product1 * rtb_Product1;
	Output_tmp_1 = rtb_Product2 * rtb_Product2;
	Output_tmp_2 = rtb_Product3 * rtb_Product3;

	double psi = rt_atan2d_snf((rtb_Product1 * rtb_Product2 + rtb_fcn5 *
		rtb_Product3) * 2.0, ((Output_tmp + Output_tmp_0) - Output_tmp_1) -
		Output_tmp_2);
	rtb_fcn3 = (rtb_Product1 * rtb_Product3 - rtb_fcn5 * rtb_Product2) * -2.0;

	double phi = rt_atan2d_snf((rtb_Product2 * rtb_Product3 + rtb_fcn5 *
		rtb_Product1) * 2.0, ((Output_tmp - Output_tmp_0) - Output_tmp_1) +
		Output_tmp_2);
	if (rtb_fcn3 > 1.0) {
		rtb_fcn3 = 1.0;
	}
	else if (rtb_fcn3 < -1.0) {
		rtb_fcn3 = 1.0;
	}
	double theta = asin(rtb_fcn3);


	arma::vec Euler(3);
	Euler(0) = psi;
	Euler(1) = theta;
	Euler(2) = phi;

	return Euler;
}

double KineticsBase::rt_atan2d_snf(double u0, double u1)
{
	double y;
	int u0_0;
	int u1_0;
	if (isnan(u0) || isnan(u1)) {
		y = (NAN);
	}
	else if (isinf(u0) && isinf(u1)) {
		if (u0 > 0.0) {
			u0_0 = 1;
		}
		else {
			u0_0 = -1;
		}

		if (u1 > 0.0) {
			u1_0 = 1;
		}
		else {
			u1_0 = -1;
		}

		y = atan2(u0_0, u1_0);
	}
	else if (u1 == 0.0) {
		if (u0 > 0.0) {
			y = arma::datum::pi / 2.0;
		}
		else if (u0 < 0.0) {
			y = -(arma::datum::pi / 2.0);
		}
		else {
			y = 0.0;
		}
	}
	else {
		y = atan2(u0, u1);
	}

	return y;
}
arma::mat KineticsBase::GetReb()
{
	return GetReb(QuaternionToEuler(Quaternion));
}
arma::mat KineticsBase::GetReb(arma::vec Euler_in)
{
	arma::mat Rbe(3, 3);
	arma::vec Euler = Euler_in;

	double Rbe_tmp;
	double Rbe_tmp_0;
	double rtb_sincos_o1_idx_0;
	double rtb_sincos_o1_idx_1;
	double rtb_sincos_o1_idx_2;
	double rtb_sincos_o2_idx_0;
	double rtb_sincos_o2_idx_1;
	double rtb_sincos_o2_idx_2;
	rtb_sincos_o1_idx_0 = sin(Euler(0));
	rtb_sincos_o2_idx_0 = cos(Euler(0));
	rtb_sincos_o1_idx_1 = sin(Euler(1));
	rtb_sincos_o2_idx_1 = cos(Euler(1));
	rtb_sincos_o1_idx_2 = sin(Euler(2));
	rtb_sincos_o2_idx_2 = cos(Euler(2));
	Rbe(0,0) = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1;
	Rbe_tmp = rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_2;
	Rbe(0, 1) = Rbe_tmp * rtb_sincos_o2_idx_0 - rtb_sincos_o1_idx_0 *
		rtb_sincos_o2_idx_2;
	Rbe_tmp_0 = rtb_sincos_o1_idx_1 * rtb_sincos_o2_idx_2;
	Rbe(0, 2) = Rbe_tmp_0 * rtb_sincos_o2_idx_0 + rtb_sincos_o1_idx_0 *
		rtb_sincos_o1_idx_2;
	Rbe(1, 0) = rtb_sincos_o1_idx_0 * rtb_sincos_o2_idx_1;
	Rbe(1, 1) = Rbe_tmp * rtb_sincos_o1_idx_0 + rtb_sincos_o2_idx_0 *
		rtb_sincos_o2_idx_2;
	Rbe(1, 2) = Rbe_tmp_0 * rtb_sincos_o1_idx_0 - rtb_sincos_o2_idx_0 *
		rtb_sincos_o1_idx_2;
	Rbe(2, 0) = -rtb_sincos_o1_idx_1;
	Rbe(2, 1) = rtb_sincos_o2_idx_1 * rtb_sincos_o1_idx_2;
	Rbe(2, 2) = rtb_sincos_o2_idx_1 * rtb_sincos_o2_idx_2;


	return Rbe.t();//Rbe�������������ת�þ�����
}


Kinetics::Kinetics(arma::vec Xe, arma::vec Vb, arma::vec Omega, arma::vec Euler)
	:KineticsBase(Xe, Vb, Omega, Euler)
{
	
}

//��ȡ��������ϵ����
arma::vec Kinetics::GetXe()
{
	return Xe;
}
//��ȡ��������ϵ�ٶ�
arma::vec Kinetics::GetVe()
{
	return  GetReb().t()*Vb;//Reb�������������ת�þ���ȡ��
}
arma::vec Kinetics::GetVb()
{
	return Vb;
}
arma::vec Kinetics::GetOmega()
{
	return Omega;
}
arma::vec Kinetics::GetEuler()
{
	return QuaternionToEuler(Quaternion);
}
double Kinetics::GetAlpha()
{
	if (abs(Vb(0)) < 1e-8)
	{
		if (abs(Vb(2)) < 1e-8)
			return 0;
		else if (Vb(2) > 0)
			return arma::datum::pi / 2;
		else
			return -arma::datum::pi / 2;
	}
	else 
	{
		return atan(Vb(2) / Vb(0));
	}
}
double Kinetics::GetBeta()
{
	return Vb(1) / sqrt(arma::dot(Vb, Vb));
}