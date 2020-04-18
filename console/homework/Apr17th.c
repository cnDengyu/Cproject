#include <stdio.h>

/*------------------------------------------

4 �� 17 ����ҵ 
�µ��� 	

��һ�������ڣ�51�� taskOne()
�ڶ��������ڣ�77�� taskTwo()
�����������ڣ�133�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int homeworkApr17th(int argc, char** argv)
{
	puts("\n--------------------4��17�տκ���ҵ---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ��
��дһ������������3��������һ���ַ�������������
�ַ������Ǵ���ӡ���ַ�����һ������ָ��һ���д�ӡ�ַ��Ĵ�����
�ڶ�������ָ����ӡָ���ַ�����������дһ�����øú����ĳ��� 
*/
static void myPrint(char toPrint, int rows, int lines)
{
	int i,j;
	for(i=0; i<lines; i++)
	{
		for(j=0; j<rows; j++)
		{
			putchar(toPrint);
		}
		putchar('\n');
	}
}

static void taskOne()	//void main()
{
	myPrint('$',3,4);
} 

/*�ڶ���
дһ��������ʹ������һ�� 3��3 �Ķ�ά��������ת�á� 
*/
#define LINE 3
#define ROW 3 
static void transformMartix(int m[LINE][ROW])
{
	int temp,i,j;
	if(LINE == ROW)
	{
		for(i=0; i<LINE; i++)
		{
			for(j=0; j<i; j++)
			{
				temp = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = temp;
			}
		}
	}
}
static void taskTwo()	//void main()
{
	int m[LINE][ROW];
	int i,j;
	printf("������һ�� 3��3 ����������\n");
	for(i=0; i<LINE; i++)
	{
		for(j=0; j<ROW; j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	
	transformMartix(m);
	
	printf("ת�ú�ľ���Ϊ��\n");
	for(i=0; i<LINE; i++)
	{
		for(j=0; j<ROW; j++)
		{
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}
} 

/*������
д�����������ֱ����������������Լ������С��������
�������������������������������������������ɼ������� 
*/
static unsigned int fGCD(unsigned int a, unsigned int b)	//greatest common divisor
{
	unsigned int i,returnValue;
	for(returnValue=i=1; i<=(a<b?a:b); i++)
	{
		if(a%i == 0 && b%i == 0)
		{
			returnValue = i;
		} 
	}
	return returnValue;
} 

static int fLCM(int a, int b)	//least/lowest common multipe
{
	unsigned int i;
	for(i=(a>b?a:b); i<=a*b; i++)
	{
		if(i%a == 0 && i%b == 0)
		{
			return i;
		}
	}
	//return a*b;
}

static void taskThree()
{
	unsigned int a, b;
	do{
		printf("��������������");
		scanf("%u", &a);
		scanf("%u", &b);
	}while(a==0 || b==0);		//��ȥ 0 
	
	printf("���������Լ��Ϊ��%d\n", fGCD(a,b));
	printf("��������С������Ϊ��%d\n", fLCM(a,b));
} 
