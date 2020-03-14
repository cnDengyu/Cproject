#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*------------------------------------------

3��6����ҵ
�µ��� 

-------------------------------------------*/ 

static void taskOne();//��һ�� 
static void taskTwo();//�ڶ��� 
static void taskThree();//������ 
static void taskFour();//������ 
static void taskFive();//������ 
static void taskSix();//������ 

//������ڣ���ֲʱ�뽫��������Ϊ main 
int homeworkMar6th(int argc, char** argv)
{
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	puts("\n-------------------------������-------------------------\n");
	taskFour();
	puts("\n-------------------------������-------------------------\n");
	taskFive();
	puts("\n-------------------------������-------------------------\n");
	taskSix();
	return 0; 
}

//��һ��
//�����ҹ�����������ֵ����������Ϊ9%������10����ҹ�����������ֵ����������������ٰٷֱȡ����㹫ʽΪ
//p = (1+r)^n
//rΪ�������ʣ�nΪ������pΪ��������ȵı���

static void taskOne()
{
	const double r = 0.09;
	const int n = 10;
	int i = 0;
	double p = 1.0;
	for(i = 0; i < n; i ++){
		p = p * ( 1.0 + r ) ;
	}
	printf("%lf\n",p);
}

//�ڶ��� 
//��Բ�뾶 r = 1.5��Բ���� h = 3����Բ�ܳ���Բ�����Բ��������Բ�������Բ�������
//��scanf�������ݣ���������������ʱҪ��������˵����ȡС�������λ���֡� 

static void taskTwo()
{
	const float pi = 3.1415926;
	float r = 1.5;
	float h = 3.0;
	float c,s,sr,vr,vh;//Բ�ܳ���Բ�����Բ��������Բ�������Բ�����
	c = s = sr = vr = vh = 0;
	printf("��Բ�뾶 r = 1.5��Բ����h = 3 ʱ��\n");
	c = 2.0*pi*r ;
	s = pi*r*r ;
	sr = 4.0*pi*r*r ;
	vr = 4.0/3.0*pi*r*r*r ;
	vh = s*h ;
	printf("Բ�ܳ���%.2f\nԲ�����%.2f\nԲ��������%.2f\nԲ�������%.2f\nԲ�������%.2f\n", c,s,sr,vr,vh);
	printf("���Կո�ֿ�������Բ�뾶��Բ���ߣ�");
	scanf("%f %f", &r, &h);
	c = 2.0*pi*r ;
	s = pi*r*r ;
	sr = 4.0*pi*r*r ;
	vr = 4.0/3.0*pi*r*r*r ;
	vh = s*h ;
	printf("Բ�ܳ���%.2f\nԲ�����%.2f\nԲ��������%.2f\nԲ�������%.2f\nԲ�������%.2f\n", c,s,sr,vr,vh);
}

//������
//��дһ������Ҫ����ʾ����һ�� ASCII ��ֵ���磬66����Ȼ���ӡ������ַ�

static void taskThree()
{
	char c;
	printf("������һ��ASCII��ֵ��");
	scanf("%d", &c);
	printf("������ַ�Ϊ%c\n", c);
} 

//������
//��дһ��������ʾ�û�����һ��������Ȼ���ӡ�Ӹ������ȸ����� 10 ����������
//���磺�û����� 5�����ӡ 5~15 ���������������� 5 �� 15
//Ҫ���ӡ�ĸ�ֵ֮����һ���ո��Ʊ�����з��ֿ�

static void taskFour()
{
	int d = 0;
	int n = 0;
	printf("������һ��������");
	scanf("%d",&d); 
	n = d + 10;
	for(; d <= n; d++){
		printf("%d ",d);
	}
	putchar('\n'); 
} 
 
//������ 
//��дһ��������ʾ�û�����������Ȼ����ת����������������
//���磺�û����� 18����ת���� 2 �� 4 �졣������ĸ�ʽ��ʾ�����
//18 days are 2 weeks, 4 days.
//ͨ�� while ѭ�����û��ظ��������������û�����һ������ֵʱ��ѭ��������
 
static void taskFive()
{
	int days = 1;
	while(1){
		printf("������������");
		scanf("%d",&days);
		if(days <= 0) break;
		printf("%d days are %d weeks, %d days.\n",days,days/7,days%7);
	}
	getchar();
}

//������ 
//��дһ����������ʾ�û������û�����Ȼ����ʾ�û������ա�
//��һ�д�ӡ�û�����������գ���һ�зֱ��ӡ�����յ���ĸ������ĸ��Ҫ����Ӧ�����յĽ�β���룬������ʾ
//Melissa Honeybee
//      7        8
//���������ٴ�ӡ��ͬ����Ϣ��������ĸ��������Ӧ�����յĿ�ͷ���룬������ʾ��
//Melissa Honeybee
//7       8

static void taskSix()
{
	int i = 0;
	char lastname[10],firstname[10];
	char format[24]; 
	printf("�������û�����");
	scanf("%s",firstname);
	printf("�������գ�");
	scanf("%s",lastname);
	
	printf("%s %s\n", firstname, lastname);
	sprintf(format, "%%%dd %%%dd\n", strlen(firstname), strlen(lastname));
	printf(format, strlen(firstname), strlen(lastname));
	
	printf("%s %s\n", firstname, lastname);
	sprintf(format, "%%-%dd %%-%dd\n", strlen(firstname), strlen(lastname));
	printf(format, strlen(firstname), strlen(lastname));
} 
