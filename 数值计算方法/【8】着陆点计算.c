#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;

#define DEBUG
#define y0 y_0	// ���в���ɾ����Ϊ math.h ���Ѿ������� y0 �����ﲻ�����Ļ�������

static double a = 5319725.3894;
static double b = 5193654.3001;
static double y0 = 1151274.6106;
static double R = 6371000;

// ��Բ���̶�Ӧ���� f(y)
double fEllipse(double y)
{
	return (R*R - y*y) / b / b + (y - y0)*(y - y0) / a / a - 1;
}

// f(y) �ĵ����� f'(y)
double dEllipse(double y)
{
	return -2 * y / b / b + 2 * (y - y0) / a / a;
}

// �ر�Բ��ͨ�� y ��� x
double GetXfromEllipse(double y)
{
	return sqrt(R*R - y*y);
}

/*	������ţ�ٵ���
���������	��������Ӧ�ĺ��� f(x)���Լ��ú����ĵ����� f'(x)��
������� start���������� accuracy
����ֵ���������
*/
double NewtonIteration(double(*f)(double x), double(*df)(double x), double start, double accuracy)
{
	double x = start;
	double x1 = x - f(x) / df(x);
	double delta = fabs(x1 - x);
	int n = 1;

	while (delta > accuracy)
	{
		x = x1;
		x1 = x - f(x) / df(x);
		delta = fabs(x1 - x);
		n++;
	}

#ifdef DEBUG
	printf("����������%d\n\n", n);
#endif

	return x1;
}


int main()
{
	start = clock();


	//***********************************
	//*����д�³���ʵ��*
	//***********************************

	
	double pos[2] = { 0 };
	double y = NewtonIteration(fEllipse, dEllipse, 100, 0.00000001);
	printf("y��ֵΪ��%lf\n\n", y);
	pos[1] = y;
	pos[0] = GetXfromEllipse(y);
	printf("��������Ϊ��(%lf,%lf)\n\n", pos[0], pos[1]);


	stop = clock();
	duration = (double)(stop - start) / CLK_TCK;
	printf("������������ʱ�䣺%f\n", duration);

	system("pause");
	return 0;
}

