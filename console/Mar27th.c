#include <stdio.h>
/*------------------------------------------

3�� 27����ҵ
�µ��� 

-------------------------------------------*/ 

static void taskTwo();
static void taskThree();
static void taskFour();
static void taskFive();

//������ڣ���ֲʱ�뽫��������Ϊ main 
int homeworkMar27th(int argc, char** argv)
{
	puts("\n-------------------------��һ��-------------------------\n");
	puts("����ƺ���min(x,y)��û�������");
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	puts("\n-------------------------������-------------------------\n");
	taskFour();
	puts("\n-------------------------������-------------------------\n");
	taskFive();
	return 0; 
}

/*��һ�� 
���һ������ min(x,y)���������� double ����ֵ�Ľ�Сֵ 
*/ 
static double min(double x, double y)
{
	return x>y?x:y;
}

/*�ڶ��� 
��Ƴ��򣬼��㲢�������������˵Ľ��
����ʾ�û����������������ֱ���Ϊ��һ��������������������ڶ�������������� 
*/ 
static void taskTwo()
{
	int m1line,m1row,m2row,i,j,k;
	printf("���Կո�ֿ��������һ������������������͵ڶ��������������"); 
	scanf("%d %d %d");
	float martix1[m1line][m1row], martix2[m1row][m2row],martixResult[m1line][m2row];
	printf("������x����\n");
	for(i=0; i<m1line; i++){
		for(j=0; j<m1row; j++){
			scanf("%d",martix1[i][j]);
		}
	}
	printf("������y����\n");
	for(i=0; i<m1row; i++){
		for(j=0; j<m2row; j++){
			scanf("%d",martix1[i][j]);
		}
	}
	for(i=0; i<m1line; i++){
		for(j=0; j<m2row; j++){
			martixResult[i][j]=0;
			for(k=0; k<m1row; k++){
				martixResult[i][j] += martix1[i][k]*martix2[k][j];
			}
		}
	}
	printf("����õ��ľ����ǣ�"); 
	for(i=0; i<m1line; i++){
		for(j=0; j<m2row; j++){
			printf("%5f",martixResult[i][j]);
		}
		putchar('\n');
	}
}

/*������ 
��һ���򣬽������ַ���������������Ҫ�� strcat ���� 
*/ 
static void myStrCat(char* str1, char* str2)
{
	char *p,*q;
	p = str1;
	q = str2;
	while(*p++ != '\0');
	p--;
	while((*p++ = *q++) != '\0');
}

#define MAX_STR 30
static void taskThree()
{
	char str1[MAX_STR], str2[MAX_STR];
	printf("�������һ���ַ�����");
	scanf("%s", str1);
	printf("������ڶ����ַ�����");
	scanf("%s", str2);
	myStrCat(str1, str2);
	printf("ƴ�Ӻ���ַ���Ϊ��%s",str1);
}

/*������ 
���� 10 ��ѧ�� 5 �ſγ̵ĳɼ����ֱ��ú���ʵ�����й��ܣ�
����ÿ��ѧ����ƽ����
����ÿ�ſε�ƽ����
�ҳ����� 50 ����������ߵķ�������Ӧ��ѧ���Ϳγ�
����ƽ���ַ������ʽ�ԣ� 
*/ 
#define NUM_STU 10
#define NUM_CLS 5
static void stuAverage(float grades[NUM_STU][NUM_CLS])
{
	int i,j;
	float sum = 0;
	for(i=0; i<NUM_STU; i++){
		sum = 0;
		for(j=0; j<NUM_CLS; j++){
			sum += grades[i][j];
		}
		printf("�� %d λͬѧ��ƽ����Ϊ %f\n", i, sum/NUM_CLS);
	}
}
static void clsAverage(float grades[NUM_STU][NUM_CLS])
{
	int i,j;
	float sum = 0;
	for(j=0; j<NUM_CLS; j++){
		sum = 0;
		for(i=0; i<NUM_STU; i++){
			sum += grades[i][j];
		}
		printf("�� %d �ſγ̵�ƽ����Ϊ %f\n", j, sum/NUM_STU);
	}
}
static void grdMax(float grades[NUM_STU][NUM_CLS])
{
	int i,j,x,y;
	float max = 0;;
	for(i=0; i<NUM_STU; i++){
		for(j=0; j<NUM_CLS; j++){
			if(grades[i][j]>max){
				x = i;
				y = j;
			}
		}
	}
	printf("��߷�Ϊ %f ���ǵ� %d λͬѧ�ڵ� %d �ſγ���ȡ�õġ�\n", max, i+1, j+1);
}
static void stuVariance(float grades[NUM_STU][NUM_CLS])
{
	int i,j;
	float sum = 0;
	float stuAverage[NUM_STU];
	float variance = 0;
	float temp;
	for(i=0; i<NUM_STU; i++){
		sum = 0;
		for(j=0; j<NUM_CLS; j++){
			sum += grades[i][j];
		}
		stuAverage[i] = sum/NUM_CLS;
	}
	for(i=0; i<NUM_STU; i++){
		variance += stuAverage[i]*stuAverage[i]/NUM_STU;
		temp += stuAverage[i];
	}
	variance += (temp/NUM_STU)*(temp/NUM_STU);
	printf("ƽ���ַ���Ϊ %f \n",variance);
}
static void taskFour()
{
	float grades[NUM_STU][NUM_CLS];
	int i,j;
	for(i=0; i<NUM_STU; i++){
		for(j=0; j<NUM_CLS; j++){
			printf("������� %d λͬѧ�ĵ� %d �ųɼ���", i+1, j+1);
			scanf("%f",&grades[i][j]);
		}
	}
	stuAverage(grades);
	clsAverage(grades);
	grdMax(grades);
	stuVariance(grades);
}

/*������ 
����һ���������� nums ��һ��Ŀ��ֵ target, 
�� nums �������ҳ���ΪĿ��ֵ�� ������������
���������ǵ������±ꡣ
�������� nums = {2, 7, 11, 15}, target = 9
��Ϊ nums[0] + nums[1] = 2+7 = 9
���Է��� [0,1] 
*/ 
static void taskFive()
{
	int nums[] = {2,7,11,15};
	int target = 9;
	int i,j;
	int returnValue[2];
	for(i=0; i<sizeof(nums)/sizeof(int); i++){
		for(j=0; j<sizeof(nums)/sizeof(int); j++){
			if(nums[i]+nums[j] == target){
				returnValue[0] = i;
				returnValue[1] = j;
			}
		}
	}
	printf("[%d,%d]",returnValue[0],returnValue[1]);
}

