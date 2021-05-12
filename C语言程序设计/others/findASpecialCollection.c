#include <stdio.h>
#include <math.h>

/*

����һ��������n���������������������������������������x[1],x[2]...x[n]:
1. x[1]+x[2]+...+x[n]=2n
2. ������һ�����ֽ����ϻ��ֳɺ���ȵ������֣�Ҳ����˵�����ϵ������Ӽ��;���Ϊn��
�밴�ռ�����Ԫ������������ֵ����С�����˳������𰸣��������������ļ����벻Ҫ����κ��ַ���

*/

static void traverse(int*, int, int);
static bool check(int* c, int n);

int findASpecialCollection()
{	
	// ����
	int n; 
	scanf("%d", &n);
	
	// ��ʼ��Ҫ�õ������� 
	int i;

	// ���� x[n] ��ȫ��Ϊ������������Ϊ 2n��
	// �Ȱ� n �� 1 ���䵽 x[n] �� 
	// ��ʣ�� n �� 1 ������䵽 x[n] ��
	// ��� k �� 1 ���䵽 c[k] ��
	// ��ʱ x[n] �� c[n] ��ȫȷ����ֻ��Ҫ���� c[n] 
	int c[n+1];
	
	// ���� c[n] 
	c[n]=n-1;
	traverse(c, n, n-1); 
	 
	return 0;
}

// �������п��ܵ����� 
static void traverse(int* c, int n, int i)
{
	int j;
	// �ݹ��˳�����
	if(i == 0)
	{
		// �������һ�� 1 ���䵽��λ�� 
		for(j=*(c+i+1); j>=0; j--)
		{
			*(c+i) = j;
			check(c, n);
		}
		return;
	}
	else
	{
		// ������ i �� 1 ���䵽��λ�� 
		for(j=*(c+i+1); j>=0; j--)
		{
			*(c+i) = j;
			traverse(c, n, i-1);
		}
	}
}

// �ж������Ƿ����Ҫ��
static bool check(int* c, int n)
{
	int j;				// �������� 
	int sum=0;			// �ݴ�� 
	int result = true;	// ��Ž�� 
	int x[n];			// ��Ű� c[n] ����������
	unsigned int child=0;		// ��Ŷ������Ӽ���Ϣ 
	int p,q;			// ���ڿ������� 
	
	// ��ʼ�� x[n]
	for(j=0; j<n; j++)
	{
		x[j] = 1;		// һ��ʼ������������ 1 
	} 
	// �� c[n] ��������
	for(j=0; j<n; j++)
	{
		x[*(c+j)] += 1;	// ���� c[n] �� x[n] ����� 1 
	} 
	
	// �������� child ���� 
	for(child=0; child<pow(2.0,n); child++)
	{
		sum=0;
		// ���� child ��ÿһλ 
		for(j=0; j<n; j++)
		{
			// ��ȡ������ j λ 
			if((child>>j)&0b01)
			{
				sum += x[j]; 
			}
		}
		if(sum == n)
		{
			result = false;
			break;
		}
	}
	
	if(result)
	{ 
		// �ж��Ƿ�˳��
		result=true;
		for(j=0; j<n-1; j++)
		{
			if(x[j]>x[j+1])
			{
				result = false;
			}
		} 
		
		if(result)
		{
			// ������� 
			for(j=0; j<n-1; j++)
			{
				printf("%d ",x[j]);
			}
			printf("%d\n",x[n-1]);
		}
	}
} 
