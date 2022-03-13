#ifndef _KINETICS_H_
#define _KINETICS_H_

#include "armadillo"

//刚体六自由度动力学解算基类
//===================================
//地面坐标系：（假设地球是个平板）
//原点：地面上任意一点
// x轴：地面上任意方向
// z轴：与地面垂直向下
// z轴：x、z轴按右手定则确定
//==================================
//机体坐标系：
//原点：飞行器质心
// x轴：位于飞行器对称平面内，指向机头
// z轴：飞行器对称平面内，与x轴垂直，指向机体下方
// y轴：x、z轴按右手定则确定
//================================
//所有角度以弧度制表示
class KineticsBase
{
public:
	KineticsBase(arma::vec Xe /*地面坐标系内的坐标*/, arma::vec Vb /*机体坐标系内的速度*/, arma::vec Omega /*机体坐标系内的姿态角速度*/, arma::vec Euler /*机体坐标系内的姿态角*/);
	//状态初始化
	void ResetState(arma::vec Xe /*地面坐标系内的坐标*/, arma::vec Vb /*机体坐标系内的速度*/, arma::vec Omega /*机体坐标系内的姿态角速度*/, arma::vec Euler /*机体坐标系内的姿态角*/);
	//状态更新
	void UpdateState(arma::vec Fb /*机体坐标系内的合力*/, arma::vec Mb /*机体坐标系内的合力矩*/, arma::mat Inertia /*惯量矩阵*/, double Mass /*质量*/, double StepLength /*仿真步长*/);
	//获取地面坐标系到机体坐标系的转换矩阵。左乘到地面坐标系内的坐标，可得到机体坐标系内的坐标
	arma::mat GetReb();

protected:
	//姿态角转换为四元素。Euler(0)为偏航角psi，Euler(1)为俯仰角theta，Euler(2)为滚转角phi
	arma::vec EulerToQuaternion(arma::vec Euler);
	//四元数转换为姿态角
	arma::vec QuaternionToEuler(arma::vec Quaternion);
	//地面坐标系内的坐标
	arma::vec Xe;
	//机体坐标系内的速度
	arma::vec Vb;
	//机体坐标系内的姿态角速度
	arma::vec Omega;
	//机体坐标系内的姿态角的四元数
	arma::vec Quaternion;

private:
	//四元数转姿态角需要的函数
	double rt_atan2d_snf(double u0, double u1);
	//龙格库塔法需要的函数
	arma::vec CalX_dot(arma::vec Fb, arma::vec Mb, arma::mat Inertia, double Mass, arma::vec Omega_in, arma::vec Vb_in, arma::vec Quaternion_in);
	arma::mat GetReb(arma::vec Euler_in);
};

class Kinetics : public KineticsBase
{
public:
	Kinetics(arma::vec Xe /*地面坐标系内的坐标*/, arma::vec Vb /*机体坐标系内的速度*/, arma::vec Omega /*机体坐标系内的姿态角速度*/, arma::vec Euler /*机体坐标系内的姿态角*/);

	//获取地面坐标系内的坐标
	arma::vec GetXe();
	//获取地面坐标系内的速度
	arma::vec GetVe();
	//获取机体坐标系内的速度
	arma::vec GetVb();
	//获取机体坐标系内的姿态角速度
	arma::vec GetOmega();
	//获取机体坐标系内的姿态角
	arma::vec GetEuler();
	//获取攻角
	double GetAlpha();
	//获取侧滑角
	double GetBeta();
};

#endif // !_KINETICS_H_
