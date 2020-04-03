#include <stdio.h>

/*------------------------------------------

4 �� 3 �տ���ʵ�� 
�µ��� 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 

int classTestApr3rd(int argc, char** argv)
{
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	return 0;
}

/*��һ�� 
����һ������������ 12 ��ѧ���ĳɼ� {72,89,65,58,87,91,53,82,71,93,76,68}��
ͳ�Ƹ��ɼ��ȼ���90������Ϊ A��80~89��Ϊ B��70~79��Ϊ C��60~69��Ϊ D��60������Ϊ E��
��ѧ��������������� 
*/
#define LEVELS 5
static void taskOne()
{
	int grades[] = {72,89,65,58,87,91,53,82,71,93,76,68};
	int studentNum = sizeof(grades)/sizeof(int);
	int numInLevel[LEVELS] = {}; 
	int i = 0;
	for(i=0; i<studentNum; i++)
	{
		switch(grades[i]/10)
		{
			case 10:case 9:
				numInLevel[0] += 1;
			break;
			case 8:
				numInLevel[1] += 1;
			break;
			case 7:
				numInLevel[2] += 1;
			break;
			case 6:
				numInLevel[3] += 1;
			break;
			case 5:case 4:case 3:case 2:case 1:case 0:
				numInLevel[4] += 1;
			break;
			default:
				printf("��%d���ɼ���%d������0~100��",i+1,grades[i]);
			break;
		}
	}
	printf("A�ȼ�	B�ȼ�	C�ȼ�	D�ȼ�	E�ȼ�\n");
	for(i=0; i<LEVELS; i++)
	{
		printf("%-8d",numInLevel[i]); 
	}
	putchar('\n');
}

/*�ڶ���
����һ�� 3*3 �ľ��󣬽��������Խ���Ԫ�ص�ֵ�뷴�Խ��߶�Ӧλ����Ԫ�ص�ֵ���н�����
���磬���о���
1	2	3				3	2	1 
4	5	6	������Ϊ	4	5	6 
7	8	9 				9	8	7 
*/ 
static void taskTwo()
{
	double martix[3][3];
	double temp[3];
	int i,j;
	printf("������һ��3*3�ľ���\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%lf",&martix[i][j]);
		}
	}

	for(i=0,j=3-1; i<3,j>=0; i++,j--){
		temp[i] = martix[i][i];
		martix[i][i] = martix[i][j];
		martix[i][j] = temp[i];
	}
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%lf ",martix[i][j]);
		}
		putchar('\n');
	}
}
