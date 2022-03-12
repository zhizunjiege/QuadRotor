#ifndef _KINETICS_H_
#define _KINETICS_H_

#include "armadillo.h"

//���������ɶȶ���ѧ�������
//===================================
//��������ϵ������������Ǹ�ƽ�壩
//ԭ�㣺����������һ��
// x�᣺���������ⷽ��
// z�᣺����洹ֱ����
// z�᣺x��z�ᰴ���ֶ���ȷ��
//==================================
//��������ϵ��
//ԭ�㣺����������
// x�᣺λ�ڷ������Գ�ƽ���ڣ�ָ���ͷ
// z�᣺�������Գ�ƽ���ڣ���x�ᴹֱ��ָ������·�
// y�᣺x��z�ᰴ���ֶ���ȷ��
//================================
//���нǶ��Ի����Ʊ�ʾ
class KineticsBase
{
public:
	KineticsBase(arma::vec Xe /*��������ϵ�ڵ�����*/, arma::vec Vb /*��������ϵ�ڵ��ٶ�*/, arma::vec Omega /*��������ϵ�ڵ���̬���ٶ�*/, arma::vec Euler /*��������ϵ�ڵ���̬��*/);
	//״̬��ʼ��
	void ResetState(arma::vec Xe /*��������ϵ�ڵ�����*/, arma::vec Vb /*��������ϵ�ڵ��ٶ�*/, arma::vec Omega /*��������ϵ�ڵ���̬���ٶ�*/, arma::vec Euler /*��������ϵ�ڵ���̬��*/);
	//״̬����
	void UpdateState(arma::vec Fb /*��������ϵ�ڵĺ���*/, arma::vec Mb /*��������ϵ�ڵĺ�����*/, arma::mat Inertia /*��������*/, double Mass /*����*/, double StepLength /*���沽��*/);
	//��ȡ��������ϵ����������ϵ��ת��������˵���������ϵ�ڵ����꣬�ɵõ���������ϵ�ڵ�����
	arma::mat GetReb();

protected:
	//��̬��ת��Ϊ��Ԫ�ء�Euler(0)Ϊƫ����psi��Euler(1)Ϊ������theta��Euler(2)Ϊ��ת��phi
	arma::vec EulerToQuaternion(arma::vec Euler);
	//��Ԫ��ת��Ϊ��̬��
	arma::vec QuaternionToEuler(arma::vec Quaternion);
	//��������ϵ�ڵ�����
	arma::vec Xe;
	//��������ϵ�ڵ��ٶ�
	arma::vec Vb;
	//��������ϵ�ڵ���̬���ٶ�
	arma::vec Omega;
	//��������ϵ�ڵ���̬�ǵ���Ԫ��
	arma::vec Quaternion;

private:
	//��Ԫ��ת��̬����Ҫ�ĺ���
	double rt_atan2d_snf(double u0, double u1);
	//�����������Ҫ�ĺ���
	arma::vec CalX_dot(arma::vec Fb, arma::vec Mb, arma::mat Inertia, double Mass, arma::vec Omega_in, arma::vec Vb_in, arma::vec Quaternion_in);
	arma::mat GetReb(arma::vec Euler_in);
};

class Kinetics : public KineticsBase
{
public:
	Kinetics(arma::vec Xe /*��������ϵ�ڵ�����*/, arma::vec Vb /*��������ϵ�ڵ��ٶ�*/, arma::vec Omega /*��������ϵ�ڵ���̬���ٶ�*/, arma::vec Euler /*��������ϵ�ڵ���̬��*/);

	//��ȡ��������ϵ�ڵ�����
	arma::vec GetXe();
	//��ȡ��������ϵ�ڵ��ٶ�
	arma::vec GetVe();
	//��ȡ��������ϵ�ڵ��ٶ�
	arma::vec GetVb();
	//��ȡ��������ϵ�ڵ���̬���ٶ�
	arma::vec GetOmega();
	//��ȡ��������ϵ�ڵ���̬��
	arma::vec GetEuler();
	//��ȡ����
	double GetAlpha();
	//��ȡ�໬��
	double GetBeta();
};

#endif // !_KINETICS_H_
