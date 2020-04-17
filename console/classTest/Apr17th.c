#include <stdio.h>

/*------------------------------------------

4 �� 17 �տ�����ϰ 
�µ��� 	

��һ�������ڣ�41�� taskOne()
�ڶ��������ڣ�70�� taskTwo()
�����������ڣ�95�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int classTestApr17th(int argc, char** argv)
{
	puts("\n----------------------4��17��ʵ���---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ�� 
���һ������ min(x,y)���������� float ���ͱ����еĽ�Сֵ������ main �����в��ԡ� 
*/
static float min(float x, float y)
{
	return x>y?x:y;
}

static void taskOne()	//void main() 
{
	float x,y;
	printf("��������������");
	scanf("%f", &x);
	scanf("%f", &y); 
	printf("��С����Ϊ��%f", min(x,y));
}

/*�ڶ��� 
�ú����ݹ�ķ�������׳� 
*/
static int factorial(int n)
{
	if(n < 0)
	{
		printf("�����ֵ����ȷ");
		return -1;
	}
	else if(n == 0)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}

static void taskTwo()	//void main()
{
	int n = 0;
	printf("������һ���Ǹ�������");
	scanf("%d", &n);
	printf("%d �Ľ׳�Ϊ��%d", n, factorial(n));
}

/*������ 
�������༶���ֱ��� 20 ���� 15 ��ѧ������Ʋ����� average ������
�ֱ����������༶��ƽ���ɼ� 
99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80
99 98 97 95 93 92 91 88 87 86 85 84 82 81 80
*/
static double average(double grades[], int num)
{
	double sum = 0;
	int i = 0;
	for(i=0; i<num; i++)
	{
		sum += grades[i];
	}
	return sum/(double)num;
}

static void taskThree()	//void main()
{
	int i=0;
	double grades[20];
	printf("�������һ���༶��20�˵ĳɼ���\n");
	for(i=0; i<20; i++)
	{
		scanf("%lf", &grades[i]);
	}
	printf("��һ���༶��ƽ����Ϊ��%lf\n", average(grades, 20));
	printf("������ڶ����༶��15�˵ĳɼ���\n");
	for(i=0; i<15; i++)
	{
		scanf("%lf", &grades[i]);
	}
	printf("��һ���༶��ƽ����Ϊ��%lf\n", average(grades, 15));
}
