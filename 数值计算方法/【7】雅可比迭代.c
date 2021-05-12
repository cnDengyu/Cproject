#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "matrix/matrix.h"

clock_t start, stop;
double duration;

#define SCALE 9

Matrix* SolveByJacobi(Matrix* matA, Matrix* matb, double accurancy);
Matrix* SolveByGS(Matrix* matA, Matrix* matb, double accurancy);


int main()
{
	start = clock();



	//***********************************
	//*����д�³���ʵ��*
	//***********************************
	// �������
	double dataA[SCALE][SCALE] = {
		{ 31, -13, 0, 0, 0, -10, 0, 0, 0 },
		{ -13, 35, -9, 0, -11, 0, 0, 0, 0 },
		{ 0, -9, 31, -10, 0, 0, 0, 0, 0 },
		{ 0, 0, -10, 79, -30, 0, 0, 0, -9, },
		{ 0, 0, 0, -30, 57, -7, 0, -5, 0 },
		{ 0, 0, 0, 0, 7, 47, -30, 0, 0 },
		{ 0, 0, 0, 0, 0, -30, 41, 0, 0 },
		{ 0, 0, 0, 0, -5, 0, 0, 27, -2 },
		{ 0, 0, 0, -9, 0, 0, 0, -2, 29 },
	};
	double datab[SCALE] = {
		-15,
		27,
		-23,
		0,
		-20,
		12,
		-7,
		7,
		-10
	};
	// ���ؾ���
	Matrix* matA, * matb;
	Matrix* matResult = NULL;
	matA = MatrixBuildFromArray(dataA, SCALE, SCALE);
	matb = MatrixBuildFromArray(datab, SCALE, 1);
	// Jacobi ��������
	matResult = SolveByJacobi(matA, matb, 0.000001);
	puts("Jacobi�������Ϊ��");
	MatrixPrint(matResult);		// ���G-S���
	MatrixDelete(&matResult);	// �ͷ��ڴ�

	// G-S ��������
	matResult = SolveByGS(matA, matb, 0.000001);
	puts("G-S�������Ϊ��");
	MatrixPrint(matResult);		// ���G-S���
	MatrixDelete(&matResult);	// �ͷ��ڴ�

	// �ͷ��ڴ�
	MatrixDelete(&matA);
	MatrixDelete(&matb);

	// ����д��ҵ
	/*
	double dataA1[3][3] = {
		{5, 2, 1},
		{-1, 4, 2},
		{2, -3, 10} };
	double datab1[3] = { -12, 20, 3 };
	matA = MatrixBuildFromArray(dataA1, 3, 3);
	matb = MatrixBuildFromArray(datab1, 3, 1);
	matResult = SolveByJacobi(matA, matb, )
		*/

	stop = clock();
	duration = (double)(stop - start) / CLK_TCK;
	printf("������������ʱ�䣺%f\n", duration);

	system("pause");
	return 0;
}

/*	Jacobi�������㺯��
	����ֵ��������
	���������ϵ������A����������b�����̹�ģ
*/
Matrix* SolveByJacobi(Matrix* matA, Matrix* matb, double accurancy)
{
	double result = 0;

	Matrix* matD = NULL;
	Matrix* matL = NULL;
	Matrix* matU = NULL;
	// ��������ľ��� L��U��D
	MatrixGetLUD(matA, &matL, &matU, &matD);
	// puts("L����");
	// MatrixPrint(matL);
	// puts("U����");
	// MatrixPrint(matU);
	// puts("D����");
	// MatrixPrint(matD);

	// �������㣬�ݴ� L+U
	Matrix* matTemp = NULL;
	MatrixAdd(matL, matU, &matTemp);
	// puts("L+U����");
	// MatrixPrint(matTemp);
	// �������㣬�ݴ� D ����
	Matrix* matD_Inv = NULL;
	MatrixInverseByValue(matD, &matD_Inv);
	// puts("D�������");
	// MatrixPrint(matD_Inv);

	// �ͷŵ�����Ҫ���ڴ�
	MatrixDelete(&matD);
	MatrixDelete(&matL);
	MatrixDelete(&matU);

	// ����˷����õ�������ʽ M = D�� * (L+U)
	Matrix* matM = NULL;
	MatrixMultiply(matD_Inv, matTemp, &matM);
	puts("������ʽM");
	MatrixPrint(matM);

	// ���������ʽ M �� 1-����
	double normM = 0;
	MatrixOneNorm(matM, &normM);
	printf("M�ķ���Ϊ%lf\n", normM);

	// ���������ʽ f = D�� * b
	Matrix* matf = NULL;
	MatrixMultiply(matD_Inv, matb, &matf);
	// puts("������ʽf");
	// MatrixPrint(matf);

	MatrixDelete(&matD_Inv);	// �ͷŵ� D��

	// ��������ʼ���������� x
	Matrix* x = MatrixCreate(matb->rows, matb->cols);
	MatrixSetZeros(x);	// x ����
	// puts("��ʼx");
	// MatrixPrint(x);

	Matrix* x1 = NULL;
	Matrix* x1_x = NULL;
	double normX;	// ��Ų�ֵ��1-����||x(k+1)-x(k)||
	double eps = 0;
	int times = 0;

	do {
		// ���� x(k+1) = M * x(k) + f
		MatrixMultiply(matM, x, &matTemp);	// matTemp = matM * x(k)
		MatrixAdd(matTemp, matf, &x1);		// x(k+1) = matTemp + matf
		
		// ���� ||x(k+1) - x(k)||
		MatrixMinus(x1, x, &x1_x);			// x1_x = x1 - x
		MatrixOneNorm(x1_x, &normX);		// normX = ||x1_x||
		// printf("Xn+1-X �ķ���Ϊ%lf\n", normX);

		// �� = ||x(k+1) - x(k)||
		eps = normX;
		// printf("����Ϊ%lf\n", eps);

		// �� x1 ��ֵ������ x ��ȥ
		MatrixCopy(x1, &x);
		times++;	// �ƴ�
	} while (eps >= accurancy);	//��������

	printf("Jacobi ������ %d �Σ���= %.10lf\n", times, eps);
	// MatrixPrint(x1);

	// �ͷ��ڴ�
	MatrixDelete(&matTemp);
	MatrixDelete(&matM);
	MatrixDelete(&matf);
	MatrixDelete(&x);
	MatrixDelete(&x1_x);
	return x1;
}

/*
*	�������ƣ�G-S������⺯��
*	�������������matA������matb
*	����������������x1
*/
Matrix* SolveByGS(Matrix* matA, Matrix* matb, double accurancy)
{
	// �����ݴ����ֵ�ı���
	double dx, aii, bi, aij, xj_k, xj_k1;
	double sum1, sum2, xi_k, xi_k1;
	int i, j;

	// ��������ʼ������ֵ x(0) = 0
	Matrix* x = MatrixCreate(matb->rows, matb->cols);
	MatrixSetZeros(x);
	// ��������ֵ x(1)
	Matrix* x1 = MatrixCreate(matb->rows, matb->cols);
	Matrix* x1_x = NULL;

	// �ݴ淶��
	double normX;

	// �ݴ澫�Ⱥʹ���
	double eps = 0;
	int times = 0;

	do {
		for (i = 1; i <= matb->rows; i++)
		{
			// ����Ӧ�ľ�����ȡ�� aii, bi, xi(k) ��ֵ
			MatrixGetValue(matA, i, i, &aii);
			MatrixGetValue(matb, i, 1, &bi);
			MatrixGetValue(x, i, 1, &xi_k);

			// ���㦲aij*x(k+1)
			sum1 = 0;
			for (j = 1; j <= i - 1; j++)
			{
				MatrixGetValue(matA, i, j, &aij);
				MatrixGetValue(x1, j, 1, &xj_k1);
				sum1 += aij * xj_k1;
			}

			// ���㦲aij*x(k)
			sum2 = 0;
			for (j = i; j <= matA->cols; j++)
			{
				MatrixGetValue(matA, i, j, &aij);
				MatrixGetValue(x, j, 1, &xj_k);
				sum2 += aij * xj_k;
			}
			// ���� ��xi = 1/aii * (bi - ��aij*x(k+1) - ��aij*x(k))
			dx = 1.0 / aii * (bi - sum1 - sum2);
			// ���� xi(k+1) = xi(k) + ��xi
			xi_k1 = xi_k + dx;
			// ������õ��� xi(k+1) д�����
			MatrixSetValue(x1, i, 1, xi_k1);
		}

		// ���� || x(k + 1) - x(k) ||
		MatrixMinus(x1, x, &x1_x);		// x1_x = x1 - x
		MatrixOneNorm(x1_x, &normX);	// normX = ||x1_x||
		// �� x1 ��ֵ������ x ��ȥ
		MatrixCopy(x1, &x);
		// �� = ||x(k+1) - x(k)||
		eps = normX;
		times++;	// �ƴ�

		// printf("G-S������ %d �Σ����� ��= %.10lf\n", times, eps);

	} while (eps >= accurancy);

	printf("G-S������ %d �Σ����� ��= %.10lf\n", times, eps);

	// �ͷŲ���Ҫ���ڴ�
	MatrixDelete(&x);
	MatrixDelete(&x1_x);
	return x1;
}
