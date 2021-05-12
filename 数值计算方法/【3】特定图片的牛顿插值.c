#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop, linear_bg, linear_ed, cubic_ed;
double duration, duration_linear, duration_cubic;

// ���躯����ǰ������
double NewtonThreeTimesInterpolation
	(double x, double x0, double x1, double x2, double x3,
	double fx0, double fx1, double fx2, double fx3);
double NewtonLinearInterpolation
	(double x, double x0, double x1, double fx0, double fx1);

int main()
{
	start = clock();

	FILE *read = NULL;
	FILE *write1 = NULL;
	FILE *write2 = NULL;
	//��.txt�ļ�
	//��ԭʼ���ݵ��ļ�
	fopen_s(&read, "image_data/1.txt", "r");
	if (!read)
	{
		perror("fail to read !");
		exit(-1);
	}
	//�����������Բ�ֵ������ļ�
	fopen_s(&write1, "image_data/1_linear.txt", "w");
	if (!write1)
	{
		perror("fail to write1 !");
		exit(-2);
	}
	//�����������β�ֵ������ļ�
	fopen_s(&write2, "image_data/1_cubic.txt", "w");
	if (!write2)
	{
		perror("fail to write1 !");
		exit(-3);
	}
	//����.txt�ļ�����
	int img[50][50];
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			fscanf(read, "%d", &img[i][j]);
		}
	}
	fclose(read);
	linear_bg = clock();
	// ==========================���Բ�ֵ==========================
	//��ʾ��������ͼ������Ϊimg[50][50]��
	int linear[491][491] = { 0 }; //���Բ�ֵ���ս�����浽�������

	//***********************************
	//*����д�³���ʵ��ţ�����Բ�ֵ*
	//***********************************


	// �ݴ� x
	int x0, x1, x2, x3, i, j;
	// �ݴ� f(x)
	double fx0, fx1, fx2, fx3;

	// �����ֵ
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 491 - 1; j++)
		{
			x0 = j - j % 10;
			x1 = x0 + 10;
			fx0 = img[i][x0 / 10];
			fx1 = img[i][x1 / 10];
			linear[i * 10][j] = NewtonLinearInterpolation(j, x0, x1, fx0, fx1);
		}
		linear[i * 10][490] = img[i][49];
	}
	// �����ֵ
	for (j = 0; j < 491; j++)
	{

		for (i = 0; i < 491 - 1; i++)
		{
			x0 = i - i % 10;
			x1 = x0 + 10;
			fx0 = linear[x0][j];
			fx1 = linear[x1][j];
			linear[i][j] = NewtonLinearInterpolation(i, x0, x1, fx0, fx1);
		}
	}


	//���Բ�ֵ���д��.txt
	for (int i = 0; i < 491; i++)
	{
		for (int j = 0; j < 491; j++)
		{
			fprintf(write1, "%3d  ", linear[i][j]);
		}
		fprintf(write1, "\n");
	}
	linear_ed = clock();


	// ==========================���β�ֵ==========================
	//��ʾ��������ͼ������Ϊimg[50][50]
	int cubic[491][491] = { 0 }; //���β�ֵ���ս�����浽�������

	//***********************************
	//*����д�³���ʵ��ţ�����β�ֵ*
	//***********************************


	// �����ֵ
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 491 - 1; j++)
		{
			if (0 <= j && j<10)
			{
				x0 = j - j % 10;
			}
			else if (480 <= j && j<490)
			{
				x0 = j - j % 10 - 20;
			}
			else
			{
				x0 = j - j % 10 - 10;
			}
			x1 = x0 + 10;
			x2 = x0 + 20;
			x3 = x0 + 30;
			fx0 = img[i][x0 / 10];
			fx1 = img[i][x1 / 10];
			fx2 = img[i][x2 / 10];
			fx3 = img[i][x3 / 10];
			cubic[i * 10][j] = NewtonThreeTimesInterpolation
				(j, x0, x1, x2, x3, fx0, fx1, fx2, fx3);
		}
		cubic[i * 10][490] = img[i][49];
	}
	// �����ֵ
	for (j = 0; j < 491; j++)
	{

		for (i = 0; i < 491 - 1; i++)
		{
			if (0 <= i && i < 10)
			{
				x0 = i - i % 10;
			}
			else if (480 <= i && i < 490)
			{
				x0 = i - i % 10 - 20;
			}
			else
			{
				x0 = i - i % 10 - 10;
			}
			x1 = x0 + 10;
			x2 = x0 + 20;
			x3 = x0 + 30;
			fx0 = cubic[x0][j];
			fx1 = cubic[x1][j];
			fx2 = cubic[x2][j];
			fx3 = cubic[x3][j];
			cubic[i][j] = NewtonThreeTimesInterpolation
				(i, x0, x1, x2, x3, fx0, fx1, fx2, fx3);
		}
	}



	//���β�ֵ���д��.txt
	for (int i = 0; i < 491; i++)
	{
		for (int j = 0; j < 491; j++)
		{
			fprintf(write2, "%3d  ", cubic[i][j]);
		}
		fprintf(write2, "\n");
	}
	cubic_ed = clock();
	//�رղ�ֵ����ļ�
	fclose(write1);
	fclose(write2);

	stop = clock();
	duration_linear = (double)(linear_ed - linear_bg) / CLK_TCK;
	duration_cubic = (double)(cubic_ed - linear_ed) / CLK_TCK;
	duration = (double)(stop - start) / CLK_TCK;
	printf("ţ�����Բ�ֵ����ʱ�䣺%f\n", duration_linear);
	printf("ţ�����β�ֵ����ʱ�䣺%f\n", duration_cubic);
	printf("������������ʱ�䣺%f\n", duration);

	system("pause");
	return 0;
}


/*
*	�������ܣ�	ţ�����β�ֵ���㺯��
*	���������	x,x0,x1,x2,x3
				fx0,fx1,fx2,fx3
	����ֵ��	y
*/
double NewtonThreeTimesInterpolation
(	double x, double x0, double x1, double x2, double x3, 
	double fx0, double fx1, double fx2, double fx3)
{
	double y;
	// ����
	double diff01, diff12, diff23, diff012, diff123, diff0123;
	diff01 = (fx0 - fx1) / (x0 - x1);
	diff12 = (fx1 - fx2) / (x1 - x2);
	diff23 = (fx2 - fx3) / (x2 - x3);
	diff012 = (diff01 - diff12) / (x0 - x2);
	diff123 = (diff12 - diff23) / (x1 - x3);
	diff0123 = (diff012 - diff123) / (x0 - x3);
	y = diff0123 * (x - x2);
	y = (y + diff012) * (x - x1);
	y = (y + diff01) * (x - x0);
	y = (y + fx0) * 1;
	return y;
}

/*
*	�������ܣ�	ţ�����Բ�ֵ���㺯��
*	���������	x,x0,x1
				fx0,fx1
*	����ֵ��	y
*/
double NewtonLinearInterpolation
(double x, double x0, double x1, double fx0, double fx1)
{
	double diff01;
	double y;
	diff01 = (fx1 - fx0) / (x1 - x0);
	y = fx0 + diff01 * (x - x0);
	return y;
}

