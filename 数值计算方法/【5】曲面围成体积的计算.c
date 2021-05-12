#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;

#define SIZE 101
double calVolume(double surface[SIZE][SIZE]);
int getMatrixLine(double data[SIZE][SIZE], int index, double output[]);
double calSimpson(double f[], int n, double a, double b);

int main()
{
	start = clock();

	FILE *read = NULL;
	//���������ݵ��ļ�
	fopen_s(&read, "surface_data.txt", "r");
	if (!read)
	{
		perror("fail to read !");
		exit(-1);
	}
	//����.txt�ļ�����
	double surface[101][101];
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			fscanf(read, "%lf", &surface[i][j]);
		}
	}
	fclose(read);

	//��ʾ����������Ϊsurface[101][101]��
	//***********************************
	//*����д�³���ʵ��Simpson���*

	double volume = calVolume(surface);
	printf("���Ϊ��%lf\n", volume);

	//***********************************


	stop = clock();
	duration = (double)(stop - start) / CLK_TCK;
	printf("������������ʱ�䣺%f\n", duration);

	system("pause");
	return 0;
}

/*	��������������Χ�ɵ����
	����ֵ����� volume
	�������������ĵ� surface[SIZE][SIZE]
*/
double calVolume(double surface[SIZE][SIZE])
{
	double volume = 0;
	double area[SIZE] = {0};
	double f[SIZE];
	int i = 0;

	for (i = 0; i < SIZE; i++)
	{
		getMatrixLine(surface, i, f);
		area[i] = calSimpson(f, 50, 2, -2);
	}

	volume = calSimpson(area, 50, 2, -2);
	
	return volume;
}


/*	����������Simpson����
	����ֵ��Simpson����ֵ
	���������f[],n,a,b
*/
double calSimpson(double f[], int n, double a, double b)
{
	if (n < 2){
		return 0;
	}

	double result = 0;

	// ������ĩ��
	result = f[0] + f[2*n];

	// ����4*f(2k-1)�����
	double temp2k_1 = 0;
	int k;
	for (k = 1; k <= n; k++)
	{
		temp2k_1 += f[2 * k - 1];
	}
	temp2k_1 = temp2k_1 * 4;
	result += temp2k_1;

	// ����2*f(2k)�����
	double temp2k = 0;
	for (k = 1; k <= n-1; k++)
	{
		temp2k += f[2 * k];
	}
	temp2k = temp2k * 2;
	result += temp2k;

	// ����ϵ��
	result *= (b - a) / 6 / n;

	return result;
}


/*	��������ȡ����һ��
	����ֵ��0Ϊ�ɹ�
	���������data[][], index
	���������output[]
*/
int getMatrixLine(double data[SIZE][SIZE], int index, double output[])
{
	if (index >= SIZE || index < 0)
	{
		puts("��ȡ���쳣\n");
		return -1;
	}

	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		output[i] = data[index][i];
	}
}
