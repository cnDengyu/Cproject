#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;

/*	���ݽṹ
�ܶȺ͸߶���ϼ���
*/
typedef struct{
	double h;		//x
	double rho;
	double lnRho;	//y
	double h_2;		//x��ƽ��
	double h_lnRho;	//y��ƽ��
} Rho_H_Item;


#define INFO_LEN 10
double calReentryVelocity(double t0, double v0, double step, double tx, double rho0, double h0);
int getRhoCoefficient(Rho_H_Item info[], int n, double* rho0, double* h0);
double calRho(double h, double rho0, double h0);
double f(double x, double v, double rho0, double h0);


int main()
{
	start = clock();



	//***********************************
	//*����д�³���ʵ��*
	//***********************************
	Rho_H_Item info[INFO_LEN] = {
		{ 30, 7394136673.0 },
		{ 40, 1858858651.0 },
		{ 50, 467310199.6 },
		{ 60, 117480058.3 },
		{ 80, 7424751.8 },
		{ 90, 1866555.2 },
		{ 100, 497400.3 },
		{ 110, 117966.5 },
		{ 120, 24900.2 },
		{ 130, 8377.1}
	};
	double rho0, h0;
	getRhoCoefficient(info, INFO_LEN, &rho0, &h0);
	printf("�ܶ�ϵ��\n��0 = %lf g/km^3\nH0 = %lf km\n\n", rho0, h0);

	double step = 0.01;
	double t0 = 0;
	double v0 = 11;
	double tx = 180;
	double v = calReentryVelocity(t0, v0, step, tx, rho0, h0);
	printf("ȡ����%lf����\nt = %lf s ʱ�� v(%lf) = %lf km/s\n\n", step, tx, tx, v);

	step = 0.001;
	v = calReentryVelocity(t0, v0, step, tx, rho0, h0);
	printf("ȡ����%lf����\nt = %lf s ʱ�� v(%lf) = %lf km/s\n\n", step, tx, tx, v);

	step = 0.0001;
	v = calReentryVelocity(t0, v0, step, tx, rho0, h0);
	printf("ȡ����%lf����\nt = %lf s ʱ�� v(%lf) = %lf km/s\n\n", step, tx, tx, v);

	step = 0.00001;
	v = calReentryVelocity(t0, v0, step, tx, rho0, h0);
	printf("ȡ����%lf����\nt = %lf s ʱ�� v(%lf) = %lf km/s\n\n", step, tx, tx, v);

	stop = clock();
	duration = (double)(stop - start) / CLK_TCK;
	printf("������������ʱ�䣺%f\n", duration);

	system("pause");
	return 0;
}


/*	���ݽṹ
	�Ľ�Runge-Kutta��������һ������
*/
typedef struct{
	double x;
	double K1;
	double K2;
	double K3;
	double K4;
	double v;
}Step;

int copyStep(Step* dst, Step src);


/*	�����ٶȼ��㺯��
	����ֵ�������ٶ�v
	���������
	���������
*/
double calReentryVelocity(double t0, double v0, double step, double tx, double rho0, double h0)
{
	Step stepN = {0, 0, 0, 0, 0, 11};
	Step stepN1;
	int i = 0;
	int n = (tx - t0) / step;
	for (i = 0; i < n; i++)
	{
		stepN1.x = stepN.x + step;
		stepN1.K1 = f(stepN.x, stepN.v, rho0, h0);
		stepN1.K2 = f(stepN.x + 0.5*step, stepN.v + 0.5*step*stepN.K1, rho0, h0);
		stepN1.K3 = f(stepN.x + 0.5*step, stepN.v + 0.5*step*stepN.K2, rho0, h0);
		stepN1.K4 = f(stepN.x + step, stepN.v + step * stepN.K3, rho0, h0);
		stepN1.v = stepN.v + step / 6 * (stepN1.K1 + 2 * stepN1.K2 + 2 * stepN1.K3 + stepN1.K4);
		copyStep(&stepN, stepN1);
	}

	return stepN.v;
}


/*	���ܶȵ���С����ϵ��
	����ֵ��0
	������������ݱ�info[]����n
	������������ϵ�� rho0, h0
*/
int getRhoCoefficient(Rho_H_Item info[], int n, double* rho0, double* h0)
{
	int i = 0;
	double sigmaX = 0;
	double sigmaY = 0;
	double sigmaX2 = 0;
	double sigmaXY = 0;

	for (i = 0; i < n; i++)
	{
		info[i].lnRho = log(info[i].rho);
		info[i].h_2 = info[i].h * info[i].h;
		info[i].h_lnRho = info[i].h * info[i].lnRho;

		sigmaX += info[i].h;
		sigmaY += info[i].lnRho;
		sigmaX2 += info[i].h_2;
		sigmaXY += info[i].h_lnRho;
	}

	double b = (sigmaXY - sigmaX * sigmaY / n) / (sigmaX2 - sigmaX * sigmaX / n );
	double a = (sigmaY - b * sigmaX) / n;

	*rho0 = exp(a);
	*h0 = -1 / b;
	return 0;
}


/*	�ܶȼ��㺯��
	����ֵ���ܶ�rho
	����������߶�h, ϵ��rho0,h0
*/
double calRho(double h, double rho0, double h0)
{
	return rho0 * exp(-h / h0)/1000000000;
}


/*	΢�ַ��̵Ⱥ��ұߵĺ���f(rho,v)
*/
double f(double x, double v, double rho0, double h0)
{
	double rho = calRho(70, rho0, h0);
	return -0.5 * 2 * 0.01 * rho * v * v;
}


/*	Runge-Kutta ���ݿ�������
*/
int copyStep(Step* dst, Step src)
{
	if (dst == NULL || &src == NULL)
	{
		return -1;
	}
	dst->x = src.x;
	dst->v = src.v;
	return 0;
}