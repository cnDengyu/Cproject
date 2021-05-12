#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//clock_tΪclock()�������صı�������
clock_t start, stop;
double duration;

int myProgram();

int main()
{
	start = clock();

	//******************************
	//*����д��ĳ��� * 
	myProgram();
	//******************************

	stop = clock();
	//CLK_TCKΪclock()������ʱ�䵥λ����ʱ�Ӵ��
	duration = (double)(stop - start) / CLK_TCK;
	printf("�ⷽ������ʱ�䣺%f\n", duration);
	system("pause");
}

//˵�������λ�õ�ʱ�Ӵ����֮��(stop-start)���ǳ������������ĵ�ʱ�Ӵ�������ٳ��Գ���CLK_TCK���͵õ�������Ϊ��λ������ʱ�䡣

// ���躯����ǰ������
int printMatrix(int lines, int rows, double* matrix);
int opScalarMultiplyLine(double* matrix, int lineMultiplicand, double multiplier, int lines, int rows);
int opLineSubLine(double* matrix, int lineMinute, int lineMinus, int lines, int rows);

#define MATRIX_N 5
#define DEBUG

int myProgram(){

	// ����ϵ������
	double points[5][2] = { \
	{-2.312, 0.5027}, \
	{2.061, -1.257}, \
	{-0.8545, -2.915}, \
	{-3.519, -1.156}, \
	{2.815, -2.815}		\
	};
	double matrixA[5][5];
	double b[MATRIX_N] = { 0,0,0,0,0 };

	// ��ʼ��ϵ������
	int i = 0;
	for (i = 0; i < MATRIX_N; i++){
		matrixA[i][0] = points[i][0] * points[i][1];
		matrixA[i][1] = points[i][1] * points[i][1];
		matrixA[i][2] = points[i][0];
		matrixA[i][3] = points[i][1];
		matrixA[i][4] = 1;
		b[i] = -points[i][0] * points[i][0];
	}
#ifdef DEBUG
	puts("ϵ������AΪ��\n");
	printMatrix(MATRIX_N, MATRIX_N, matrixA);
	puts("��������bΪ��\n");
	printMatrix(MATRIX_N, 1, b);
#endif

	// ��˹��Ԫ�õ������Ǿ���
	int j = 0;
	double m;
	for (j = 1; j < MATRIX_N; j++){
		// ����j��
		for (i = j; i < MATRIX_N; i++){
			// ����i+1��
			if (!matrixA[i][j-1]){
				continue;
			}
			m = matrixA[j - 1][j - 1] / matrixA[i][j - 1];
			opScalarMultiplyLine(matrixA, i + 1, m, MATRIX_N, MATRIX_N);
			b[i] *= m;
			opLineSubLine(matrixA, i + 1, j, MATRIX_N, MATRIX_N);
			b[i] -= b[j - 1];
		}
	}
#ifdef DEBUG
	puts("��˹��Ԫ��������Ǿ���Ϊ��\n");
	printMatrix(MATRIX_N, MATRIX_N, matrixA);
#endif

	// ���
	double x[MATRIX_N];
	double sum;
	for (i = MATRIX_N-1; i >= 0; i--){
		sum = 0;
		for (j = MATRIX_N - 1; j > i; j--) {
			sum += matrixA[i][j] * x[j];
		}
		x[i] = (b[i] - sum) / matrixA[i][i];
	}
#ifdef DEBUG
	puts("��ã�x=");
	printMatrix(MATRIX_N, 1, x);

	printf("��Բ����Ϊ��x*x + %10lf*x*y + %10lf*y*y + %10lf*x + %10lf*y + %10lf = 0 \n", x[0], x[1], x[2], x[3], x[4]);
#endif
	return 0;
}

/*
�����������
lines			��������
rows			��������
matrix			��������
*/
int printMatrix(int lines, int rows, double* matrix){
	int i = 0;
	int j = 0;
	putchar('\n');
	for (i = 0; i < lines; i++){
		for (j = 0; j < rows; j++){
			printf(" %10lf ", *matrix++);
		}
		putchar('\n');
	}
	putchar('\n');
}

/*
�����������ĳ�г���
matrix			��������
lineMultiplicand	���˵���
multiplier			����
lines			��������
rows			��������
*/
int opScalarMultiplyLine(double* matrix, int lineMultiplicand, double multiplier, int lines, int rows){
	// Խ����
	if (lineMultiplicand > lines){
		return -1;
	}

	int i = 0;
	for (i = 0; i < rows; i++){
		*(matrix + rows * (lineMultiplicand - 1) + i) *= multiplier;
	}
	return 0;
}

/*
�����������ĳ�м�ȥĳ��
matrix			��������
lineMinute		��������
lineMinus		��ȥ����
lines			��������
rows			��������
*/
int opLineSubLine(double* matrix, int lineMinute, int lineMinus, int lines, int rows){
	// Խ����
	if (max(lineMinus, lineMinute) > lines){
		return -1;
	}

	int i = 0;
	for (i = 0; i < rows; i++){
		*(matrix + rows * (lineMinute - 1) + i) -= *(matrix + rows * (lineMinus - 1) + i);
	}
	return 0;
}