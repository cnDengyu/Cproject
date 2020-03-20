#include <stdio.h>
#include <string.h>

/*------------------------------------------

3��20����ҵ
�µ��� 

-------------------------------------------*/ 

static void taskOne();
static void taskTwo();
static void taskThree();
static void taskFour();
static void taskFive();
static void taskSix();
static void taskSeven();
static void taskEight();

//�������
int homeworkMar20th(int argc, char** argv)
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
	puts("\n-------------------------������-------------------------\n");
	taskSeven();
	puts("\n-------------------------�ڰ���-------------------------\n");
	taskEight();
	return 0; 
}

/*��һ�� 
�õ������� x = ��a ��ƽ�����ĵ�����ʽΪ
x[n+1] = 1/2 (x[n] + a/x[n])
Ҫ��ǰ����������� x �Ĳ�ľ���ֵС�� 10^-5 
*/
static void taskOne()
{
	double xn,xn1,a;
	do{
		printf("������a��ֵ��");
	}while(scanf("%lf",&a) != 1);
	
	xn1 = 5.0;
	do{
		xn = xn1;
		xn1 = 1.0/2.0*(xn+a/xn);
	}while(xn1 - xn >= 0.00001 || xn1 - xn <= -0.00001);
	
	printf("ƽ����Ϊ%.5lf��0.00001",xn);
}

/*�ڶ��� 
�� ��k (1~100) + ��k^2 (1~50) + ��1/k (1~10) 
*/
static void taskTwo()
{
	double sum = 0;
	int i = 0;
	for(i = 1; i <= 100; i++){
		sum += i;
	}
	for(i = 1; i <= 50; i++){
		sum += i*i;
	}
	for(i = 1; i<=10; i++){
		sum += 1.0/i;
	}
	printf("����ĺ�Ϊ%lf",sum);
}

/*������ 
��дһ��������ʾ�û�����һ�ܹ�����Сʱ����Ȼ���ӡ�����ܶ˰��;����롣�����¼��裺
	a. �������� = 1000 ��Ԫ/Сʱ
	b. �Ӱࣨ����40Сʱ�� = 1.5 ����ʱ��
	c. ˰�ʣ�	ǰ 300 ��ԪΪ 15%
				�� 150 ��ԪΪ 20%
				���µ�Ϊ 25% 
*/
static void taskThree()
{
	double hours,salary,tax,printSalary;
	const double timeStage = 40;
	const double basic = 1000;
	const double extraSalary = 1.5;
	const double taxStage1 = 300;
	const double taxStage2 = 150;
	const double taxRate1 = 0.15;
	const double taxRate2 = 0.2;
	const double taxRate3 = 0.25;
	do{
		printf("������һ�ܹ�����Сʱ����");
	}while(scanf("%lf",&hours)!=1 || hours < 0 || hours > 7*24);
	
	//���㹤���ܶ� 
	if(hours <= timeStage){
		salary = hours*basic;
	}else if((hours -= timeStage) > 0){
		salary = timeStage*basic;
		salary += hours*basic*extraSalary;
	}
	printSalary = salary;
	
	//����˰��
	if(salary <= taxStage1){
		tax = salary*taxRate1;
	} else if((salary -= taxStage1) <= taxStage2){
		tax = taxStage1*taxRate1;
		tax += salary*taxRate2;
	} else if((salary -= taxStage2) > 0){
		tax = taxStage1*taxRate1 + taxStage2*taxRate2;
		tax += salary*taxRate3;
	}
	//���
	printf("�����ܶ�%.2lf��˰��%.2lf��������%.2lf", printSalary, tax, printSalary-tax);
}

/*������ 
��дһ�������ȡ���룬���� # �ַ�ʱֹͣ������Ҫ��ӡÿ��������ַ��Լ���Ӧ�� ASCII �루10���ƣ���
һ�д�ӡ 8 ���ַ������飺ʹ���ַ���������ģ�������%����ÿ 8 ��ѭ������ʱ��ӡһ�����з� 
*/
static void taskFour()
{
	int i = 0;
	char c[256];
	printf("�����룬��#��ֹ��");
	scanf("%s",c);
	while(i<strlen(c) && c[i]!='#'){
		printf("%3d ",c[i]);
		if(++i%8 == 0){
			putchar('\n');
		}
	}
	fflush(stdin);
}

/*������ 
���ĸ�Բ����Բ�ķֱ�Ϊ (2,2) (-2,2) (-2,-2) (2,-2)��Բ�뾶Ϊ 1 
���ĸ����ĸ߶�Ϊ 10 m ���������޽������������һ������꣬��õ�Ľ����߶ȣ�����ĸ߶�Ϊ�㣩 
*/
static void taskFive()
{
	double x,y,h;
	do{
		printf("������һ������꣺");
	}while(scanf("(%lf,%lf)", &x, &y) != 2);
	
	if((x-2)*(x-2)+(y-2)*(y-2)>1 &&\
	(x+2)*(x+2)+(y-2)*(y-2)>1 &&\
	(x-2)*(x-2)+(y+2)*(y+2)>1 &&\
	(x+2)*(x+2)+(y+2)*(y+2)>1 ){
		h = 0;
	} else {
		h = 10;
	}
	printf("�õ�Ľ����߶�Ϊ%.0lf",h);
}

/*������ 
��һ����ѧ��ʽ AB*CD = BA*DC ��ʽ�е�һ����ĸ����һλ���֣����ҳ����з�������Ҫ��ĳ˻�ʽ����ӡ��� 
*/
static void taskSix()
{
	int i1,i2,i3,i4,count;
	for(i1=1; i1<10; i1++){
		for(i2=1; i2<10; i2++){
			for(i3=1; i3<10; i3++){
				for(i4=1; i4<10; i4++){
					if((i1*10+i2)*(i3*10+i4) == (i2*10+i1)*(i4*10+i3) &&\
					i1!=i2 && i2!=i3 && i3!=i4 && i1!=i3 && i1!=i4 && i2!=i4 && i3!=i4){
						printf("%d%d*%d%d = %d%d*%d%d  ",i1,i2,i3,i4,i2,i1,i4,i3);
						if(++count == 5){
							putchar('\n');
							count = 0;
						}
					}
				}
			}
		}
	} 
}

/*������ 
һ�ٸ�ͭǮ����һ��ֻ�������й���һֻ 5 Ǯ��ĸ��һֻ 3 Ǯ��С��һǮ 3 ֻ��
��һ��ֻ���й�����ĸ����С�������١� 
*/
static void taskSeven()
{
	int x,y,z;
	//5x + 3y + 1/3z = 100
	//x + y + z = 100
	for(x=0; x<=20; x++){
		for(y=0; y<34; y++){
			for(z=0; z<=100; z++){
				if(x+y+z == 100 && 5*x+3*y+(float)z/3.0 == 100.0){
					printf("���� %d ֻ��ĸ�� %d ֻ��С�� %d ֻ\n",x,y,z);
				}
			}
		}
	}
}

/*�ڰ��� 
��� 1000 �����ܱ� 3 �����Ҹ�λ��Ϊ 6 ���������� 
*/
static void taskEight()
{
	int i = 0;
	printf("1000�����ܱ�3�����Ҹ�λ��Ϊ6����������Ϊ\n");
	for(i = 1; i <= 1000; i++){
		if(i%3 == 0 && i%10 == 6){
			printf("%d ",i);
		}
	} 
}
