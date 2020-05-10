#include <stdio.h>

/*------------------------------------------

5 �� 8 ����ҵ 
�µ��� 	

��һ�������ڣ�61�� taskOne()
�ڶ��������ڣ�98�� taskTwo()
�����������ڣ�126�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int homeworkMay8th(int argc, char** argv)
{
	puts("\n----------------------5��8����ҵ---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ�� -------------------------------------
�� n ��������ʹǰ�����˳������� m ��λ�ã�
��� m ���������ǰ�� m ������
дһ����ʵ�����Ϲ��ܣ��������������� n ������������������ n ���� 
*/ 
static void moveArr(int *p, int m, int n)
{
	//���� 
	int temp[m],i;
	
	//�ݴ� 
	for(i=0; i<m; i++)
	{
		temp[i] = *(p+n-m+i);
	}
	
	//�������� 
	for(i=n-1; i>=m; i--)
	{
		*(p+i) = *(p+i-m);
	}
	
	//ȡ���ݴ���� 
	for(i=0; i<m; i++)
	{
		*(p+i) = temp[i];
	}
}
static void taskOne()	//main
{
	//���� 
	int input[9],i;
	
	//���� 
	printf("������9��������");
	for(i=0; i<9; i++)
	{
		scanf("%d",&input[i]);
	}
	
	//�任 
	moveArr(input, 3, 9);
	
	//��� 
	for(i=0; i<9; i++)
	{
		printf("%d ",input[i]);
	}
}

/*�ڶ��� -------------------------------------
��дһ����������һ���ַ����ĳ��ȡ�
�ַ����� main ���������루��ָ��ʵ�֣� 
*/ 
static int myStrLen(char* buff, int maxLen)
{
	//���� 
	int len = 0;
	
	//���� 
	while(*buff++!='\0' && len++<maxLen);
	
	//���� 
	return len;
} 
static void taskTwo()	//main
{
	//���� 
	char buffer[30];
	int len;
	
	//���� 
	printf("������һ���ַ�����");
	scanf("%s",buffer);
	
	//����
	len = myStrLen(buffer, 30);
	
	//���
	printf("�ַ����ĳ���Ϊ��%d\n", len); 
}

/*������ -------------------------------------
��һ�ַ��������� n ���ַ�����дһ��������
�����ַ����ӵ� m ���ַ���ʼ��ȫ���ַ����Ƴ�Ϊ��һ���ַ��� 
����ָ��ʵ�֣� 
*/ 
static void myStrCpy(char* inBuff, int n, int m, char* outBuff)
{
	inBuff = inBuff + m-1;
	n -= m-1;
	while((*outBuff++ = *inBuff++) != '\0' && n-->0);
}
static void taskThree()	//main
{
	//���� 
	char buffer[30],copy[30];
	int m;
	
	//����
	printf("������һ���ַ�����");
	scanf("%s", buffer);
	printf("�ӵڼ����ַ���ʼ������") ;
	scanf("%d", &m);
	
	//���� 	�˴��õ�����һ��ļ������� 
	myStrCpy(buffer, myStrLen(buffer,30), m, copy);
	
	//���
	printf("%s",copy); 
}
