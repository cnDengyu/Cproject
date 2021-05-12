#include <stdio.h>

/*------------------------------------------

5 �� 8 �տ�����ϰ 
�µ��� 	

��һ�������ڣ�37�� taskOne()
�ڶ��������ڣ�97�� taskTwo()
�����������ڣ�137�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int classTestMay8th(int argc, char** argv)
{
	puts("\n----------------------5��8��ʵ���---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/* ��һ�� 
��дһ������������ 3 ������������С�����˳���������ָ��ķ������� 
*/
//�����������ݸ��� 
static void taskOne()	//main
{
	//������� 
	int i=0,j=0; 		//�������� 
	int input[3]; 		//��������
	int *p=input;		//����ָ�� 
	int *o1,*o2,*o3,*temp;	//��� 
	 
	//����
	printf("������ 3 ��������");
	for(i=0; i<3; i++) 
	{
		scanf("%d",p++);
	}
	o1 = input;
	o2 = &input[1];
	o3 = &input[2];
	
	//�Ƚ� 
	if(*o1>*o2)
	{
		temp = o1;
		o1 = o2;
		o2 = temp;
		
	}
	if(*o1>*o3)
	{
		temp = o1;
		o1 = o3;
		o3 = temp;
	}
	if(*o2>*o3)
	{
		temp = o2;
		o2 = o3;
		o3 = temp;
	}
	
	//���
	printf("%d %d %d",*o1,*o2,*o3); 
	
}

/* �ڶ��� 
��һ������ a ��ͨ�������������� 5 ��Ԫ�ء�
����һ��ָ����� p��ָ�������׵�ַ��Ȼ����ú��� void inv(int *x, int n)
������Ԫ���෴��ţ�Ȼ������Ļ����෴˳���ŵ�����Ԫ�ء� 
*/
static void inv(int *x,int n)
{
	int temp,i;
	n--; 
	for(i=0; i<n/2; i++)
	{
		temp = *(x+i);
		*(x+i) = *(x+n-i);
		*(x+n-i) = temp;
	}
}
static void taskTwo()	//main
{ 
	//���� 
	int i;					//�������� 
	int a[5] = {1,2,3,4,5};	//����
	
	//����
	printf("������5������"); 
	for(i=0; i<5; i++)
	{
		scanf("%d", &a[i]);
	} 
	 
	//���� 
	inv(a,5);
	
	//��� 
	for(i=0; i<5; i++)
	{
		printf("%d ",a[i]);
	}
}

/* ������ 
�Ӽ������� n���������ޣ����������֣��ŵ����� PArray �У�Ȼ���д����
int *Calc(int *PA, int Num); ���������������Ԫ�صĺͷ��ظ� main����
��������������õ��䳤���飩 
*/
static int Calc(int *PA, int Num)
{
	int i;	//�������� 
	int sum=0;
	
	for(i=0; i<Num; i++)
	{
		sum += *(PA+i);
	}
	
	return sum;
}
static void taskThree()	//main
{
	//����
	int i,n = 1;
	
	//����
	printf("������Ҫ��������ָ�����");
	scanf("%d",&n);
	
	//�䳤����
	int PArray[n];
	
	//����
	printf("������%d������:",n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &PArray[i]);
	} 
	
	//���
	printf("��Ϊ��%d",Calc(PArray,n)); 
}
