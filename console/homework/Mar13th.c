#include <stdio.h>
#include <math.h>
#include <string.h>
/*------------------------------------------

3��13����ҵ
�µ��� 

-------------------------------------------*/ 

static void taskOne();
static void taskTwo();
static void taskThree();
static void taskFour();
static void taskFive();
static void taskSix();

//������ڣ���ֲʱ�뽫��������Ϊ main 
int homeworkMar13th(int argc, char** argv)
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

/*��һ��
�Ӽ�������һ��С�� 1000 ��������Ҫ���������ƽ����
����ƽ����������������������������֣� 
Ҫ�����������ݺ��ȶ�����м���Ƿ�ΪС�� 1000 ��������
�����ǣ���Ҫ���������� 
*/ 

static void taskOne()
{
	int n = 0;
	int result = 0;
	do{
		printf("������һ��С�� 1000 ��������");
		scanf("%d",&n); 
	}while(0 >= n || n >= 1000);
	
	result = (int)sqrt((double)n);
	printf("ƽ����Ϊ %d \n",result);
} 

/*�ڶ���
�� ��n! (1 ~ 20)
*/
static void taskTwo()
{
	int result = 0;
	int stage = 1;
	int i,n;
	for(n = 1; n <= 20; n++){
		for(i = 1; i <= n; i ++){
			stage = stage * i;
		}
		result = result + stage;
		stage = 1;
	}
	printf("%d", result);
} 

/*������
����һЩ�����������㸺������Ŀ��ռ�ٷֱȣ����ʾ����
���������֣�12 5 -2.5 1 0 5 -5 6 7 -10
�ܹ� 10 �����֣�����ռ�� 30 % 
*/ 
static void taskThree()
{
	char numberBuff[20] = "";	//�ݴ� stdin �н�ȡ�Ķ�Ӧһ�����ֵ��ַ��� 
	char buff = ' ';
	int num = 0;			//ͳ������������ 
	int minusNum = 0;		//ͳ�Ƹ������� 
	float currentNumber;	//�ݴ� numberBuff �н���ĸ����� 
	char *pNumber;			//���ڶ�д numberBuffer��ָ�� 
	bool ifLoop = true;
	
	fflush(stdin);		//��������� 
	
	pNumber = numberBuff;
	printf("���������֣�");

	while(ifLoop){	//�����ж� stdin �е��ַ���ֱ���ַ������� 
		buff=getc(stdin);
		if(buff == '\0' || buff == '\n'){	//�˳�ѭ������ 
			ifLoop = false;
		}

		if(buff == ' ' || buff == '\n'){	//�ÿո�ָ�������� 
			*pNumber++ = '\0';			//��������˿ո���� numberBuffer ��β 
			currentNumber = atof(numberBuff);	//�����ݴ�İ����������ֵ��ַ��� 
			if(currentNumber < 0){
				minusNum++;			//���С�������¼ 
			}
			num ++;					//��������������¼ 
			pNumber = numberBuff;	//ָ�����õ���� 
		}else if(buff == '\b'){
			*pNumber--;				//��������˸���д�룬����ָ��Ҫ���� 
		}else if(buff>31){			//��ȥ���п����ַ� 
			*pNumber++ = buff;		//���û�ж����ո���д�� numberBuffer 
		}
	}

	printf("�ܹ� %d �����֣�����ռ�� %.0f%%",num,100.0*(float)minusNum/num);
	
	fflush(stdin);		//��������� 
} 

/*������
���������� a, b, c���ɼ������룬������������� 
*/ 
static void taskFour()
{
	int a,b,c;
	int max;

	printf("���Կո�ֿ�����������������");
	scanf("%d %d %d",&a,&b,&c);

	max = a;
	if(b>max){
		max = b;
	}
	if(c>max){
		max = c;
	}
	printf("������Ϊ %d",max);
}

/*������
ʹ��Ƕ��ѭ����������ĸ�ʽ��ӡ��ĸ 
F
FE
FED
FEDC
FEDCB
FEDCBA
*/

static void taskFive()
{
	char letter = 'F';
	int i,j;
	for(i = 1; i <= 6; i ++){
		for(j = 0; j < i; j++){
			putchar(letter - j);
		}
		putchar('\n');
	}
}

/*������
��дһ��������ʾ�û������д��ĸ��ʹ��Ƕ��ѭ��������Ľ������͵ĸ�ʽ��ӡ��ĸ
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA 
��ӡ������ͼ�Σ�Ҫ�����û��������ĸ�����������磬�����ͼ�������û�����E��Ĵ�ӡ��� 
*/ 

static void taskSix()
{
	char c;
	int i,j,n;
	do{
		printf("������һ����д��ĸ��");
		scanf("%c", &c);
	}while(c < 'A' || c > 'Z');
	n = c - 'A' + 1;
	for(i = 0; i < n ; i ++) {
		for(j = 0; j < n - i - 1; j++){
			putchar(' ');
		}
		for(j = 0; j < i; j++){
			putchar('A'+j);
		}
		putchar('A'+i);
		for(j = i-1; j >= 0; j--){
			putchar('A'+j);
		}
		putchar('\n');
	}
}
