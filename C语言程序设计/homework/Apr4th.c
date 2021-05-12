#include <stdio.h>

/*------------------------------------------

4 �� 4 ����ҵ 
�µ��� 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

int homeworkApr4th(int argc, char** argv)
{
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ��
��дһ�����������������������Ӧ��Ԫ����ӣ�Ȼ��ѽ�����浽�����������С�
Ҳ����˵��������� 1 �а�����ֵ�� 2��4��5��8������ 2 �а�����ֵ�� 1��0��4��6��
��ô�ú����� 3��4��9��10 �������������顣
�������� 3 ����������һ�������С����һ���򵥵ĳ����в��Ըú�����
*/
#define ARRAY_TYPE int
static void copyArray(ARRAY_TYPE a[], ARRAY_TYPE b[], ARRAY_TYPE c[], int length)
{
	int i;

	for(i=0; i<length; i++){
		c[i] = a[i] + b[i];
	}
}
static void taskOne()
{
	ARRAY_TYPE a[4] = {2,4,5,8};
	ARRAY_TYPE b[4] = {1,0,4,6};
	ARRAY_TYPE c[4];
	int i;
	copyArray(a,b,c,4);
	printf("c�е�ֵΪ��");
	for(i=0; i<4; i++){
		printf("%5d",c[i]);
	}
	putchar('\n');
}

/*�ڶ���
����һ�� N*N �ľ��� (N Ϊ�û�����ֵ����
���������Խ���Ԫ�ص�ֵ�뷴�Խ��߶�Ӧλ����Ԫ�ص�ֵ���н�����
���磬�� N=4 ʱ�����о��� 
1	2	3	4				4	3	2	1 
5	6	7	8	������Ϊ��	5	7	6	8 
9	10	11	12				9	11	10	12 
13	14	15	16 				16	14	15	13 
*/
#define MARTIX_TYPE int
#define MARTIX_TYPE_INPUT "%d"
#define MARTIX_TYPE_OUTPUT "%5d"
static void taskTwo()
{
	int i,j,n;
	printf("������N��");
	scanf("%d",&n);
	MARTIX_TYPE martix[n][n];
	MARTIX_TYPE temp[n];
	printf("������һ��%d*%d�ľ���\n",n,n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf(MARTIX_TYPE_INPUT,&martix[i][j]);
		}
	}
	for(i=0,j=n-1; i<n,j>=0; i++,j--){
		temp[i] = martix[i][i];
		martix[i][i] = martix[i][j];
		martix[i][j] = temp[i];
	}
	printf("�滻��ľ���Ϊ:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(MARTIX_TYPE_OUTPUT,martix[i][j]);
		}
		putchar('\n');
	}
} 

/*������
����һ���������飬��Ƴ����ȡ�������ڵ����ֵ����Сֵ
*/
static void taskThree()
{
	int a[] = {1,2,5,4,3};
	int length = sizeof(a)/sizeof(int);
	int i,max,min;
	max = min = a[0];
	for(i=0; i<length; i++){
		max = a[i]>max?a[i]:max;
		min = a[i]<min?a[i]:min;
	}
	printf("���ֵΪ��%d����СֵΪ��%d\n",max,min);
} 
