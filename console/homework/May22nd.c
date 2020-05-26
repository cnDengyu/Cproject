/*------------------------------------------

5 �� 22 ����ҵ 
�µ��� 	

�����������ڣ�92�� taskOne()
�����������ڣ�148�� taskSix()
�����������ڣ�199�� taskSeven()
�ڰ��������ڣ�264�� taskEight()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 

#include <stdio.h>

#define DEBUG

static void taskFive();
static void taskSix(); 
static void taskEleven();
static void taskEight();

//������� 
int homeworkMay22nd(int argc, char** argv)
{
	puts("\n----------------------5��22����ҵ---------------------\n");
	#ifdef DEBUG
	printf("����ģʽ������\n");
	#endif
	puts("\n-------------------------������-------------------------\n");
	taskFive();
	puts("\n-------------------------������-------------------------\n");
	taskSix();
	puts("\n-------------------------������-------------------------\n");
	taskEleven();
	puts("\n-------------------�ع���������ִ��ǰ-------------------\n");
	taskSix(); 
	puts("\n-------------------------�ڰ���-------------------------\n");
	taskEight();
	return 0;
}

/* ������
 �� 5 ��ѧ����ÿ��ѧ���� 3 �ǿγ̵ĳɼ����Ӽ�������ѧ������
 ������ѧ�ţ�������3 �ſγ̳ɼ����������ƽ���ɼ���
 ��ԭ�����ݺͼ������ƽ����������ڴ����ļ���stud���С� 
*/

// ����ѧ������
#define MAX_LEN_NAME 15
#define NUM_COURSE 3 
typedef struct 
{
	int id;
	char name[MAX_LEN_NAME];
	int grades[NUM_COURSE];
	double average;
}Student;

static double student_calcAverage(Student *stu)
{
	int i=0;
	int sum = 0;
	for(i=0; i<NUM_COURSE; i++)
	{
		sum += stu->grades[i];
	}
	
	stu->average = (double) sum / NUM_COURSE;
	return stu->average;
}

static void student_printToScreen(Student *stu)
{
	printf("%d %s %d %d %d %lf\n", stu->id, stu->name, 
	stu->grades[0], stu->grades[1], stu->grades[2], stu->average);
}

static void student_printToFile(Student *stu, FILE *fp)
{
	fprintf(fp, "%d , %s , %d , %d , %d , %lf \n", stu->id, stu->name, \ 
	stu->grades[0], stu->grades[1], stu->grades[2], stu->average);
	#ifdef DEBUG
	printf("д�룺");
	student_printToScreen(stu);
	#endif
}

#define NUM_STU 5
static void taskFive()
{
	int i;
	#ifdef DEBUG
	//����������
	Student stus[NUM_STU]={{1001,"Zhang",{99,98,78},0},\
	{1002,"Wang",{87,88,90},0},{1003,"Zhao",{89,82,77},0},\
	{1004,"Li",{100,69,75},0},{1005,"Wei",{83,92,81},0}};
	#else 
	// ��Ļ���� 
	Student stus[NUM_STU];
	Student *p;
	printf("������ 5 ��ѧ����ѧ�š�������3�ſγ̳ɼ���\n");
	for(i=0; i<NUM_STU; i++)
	{
		p = &stus[i];
		scanf("%d %s %d %d %d",\
		&p->id, p->name, &p->grades[0], &p->grades[1], &p->grades[2]);
	}
	#endif
	
	// ���ݴ���
	for(i=0; i<NUM_STU; i++)
	{
		student_calcAverage(&stus[i]);
	} 
	
	// д��
	FILE *fp;
	if((fp=fopen("stud.csv","w+"))==NULL)
	{
		printf("�޷��򿪻򴴽��ļ�\n");
		return;
	}
	for(i=0; i<NUM_STU; i++)
	{
		student_printToFile(&stus[i], fp);
	}
	fclose(fp);
}

/* ������
 ���� 5 �⡰stud���ļ��е�ѧ����֣���ƽ���ֽ���������
 ���������ѧ�����ݴ���һ�����ļ���stu_sort���С�
 */ 

static void student_readFromFile(Student* stu, FILE *fp)
{
	fscanf(fp, "%d , %s , %d , %d , %d , %lf \n", &stu->id, stu->name, \
	&stu->grades[0], &stu->grades[1], &stu->grades[2], &stu->average);
	#ifdef DEBUG
	printf("���룺");
	student_printToScreen(stu);
	#endif
}

static void taskSix()
{
	int i;
	// ���ļ� 
	Student stus[NUM_STU] = {};
	FILE *fp;
	if((fp=fopen("stud.csv","r+"))==NULL)
	{
		printf("��ȡ�ļ�ʧ��\n");
		return;
	}
	for(i=0; i<NUM_STU; i++)
	{
		student_readFromFile(&stus[i], fp);
	}
	fclose(fp);
	
	// ����
	int j;
	int order[NUM_STU] = {0,1,2,3,4};
	int temp;
	for(i=0; i<NUM_STU; i++)
	{
		for(j=i; j<NUM_STU; j++)
		{
			if(stus[order[j]].average>stus[order[i]].average)
			{
				temp = order[j];
				order[j] = order[i];
				order[i] = temp;
			}
		}
	} 
	
	// �������
	if((fp=fopen("stu_sort.csv", "w+"))==NULL)
	{
		printf("�޷��򿪻򴴽��ļ�\n");
		return;
	}
	for(i=0; i<NUM_STU; i++)
	{
		student_printToFile(&stus[order[i]], fp);
	}
	fclose(fp);
}

/* ������ 
���������������ѧ���ɼ��ļ����в��봦������һ��ѧ�������ſγ̳ɼ���
�����ȼ����²���ѧ����ƽ���ɼ���Ȼ�������ɼ��ߵ�˳����룬�������һ�����ļ���
*/ 
static void taskEleven()
{
	int i;
	// ���ļ�
	Student stus[NUM_STU];
	FILE *fp;
	if((fp=fopen("stu_sort.csv", "r"))==NULL)
	{
		printf("��ȡ�ļ�ʧ��\n");
		return;
	}
	for(i=0; i<NUM_STU; i++)
	{
		student_readFromFile(&stus[i], fp);
	}
	fclose(fp);
	 
	#ifdef DEBUG
	// ����������
	Student toInsert = {1021, "Cai", {85,86,87}, 0}; 
	#else 
	// ��Ļ����
	Student toInsert;
	printf("������Ҫ�����ѧ����ѧ�š����������ųɼ���\n");
	scanf("%d %s %d %d %d", &toInsert->id, toInsert->name, \
	&toInsert->grades[0], &toInsert->grades[1], &toInsert->grades[2]);
	#endif 
	
	// ��¼����λ�� 
	int insertIndex = NUM_STU;
	bool isFound = false;
	student_calcAverage(&toInsert);
	for(i=0; i<NUM_STU; i++)
	{
		if(stus[i].average<toInsert.average)
		{
			insertIndex = i;
			isFound = true;
			break;
		}
	}
	
	// д�ļ�
	if((fp=fopen("stu_sort_new.csv", "w+"))==NULL)
	{
		printf("�򿪻򴴽��ļ�ʧ��\n");
		return;
	} 
	for(i=0; i<NUM_STU; i++)
	{
		if(i == insertIndex)
		{
			student_printToFile(&toInsert, fp);
		}
		student_printToFile(&stus[i], fp);
	}
	if(NUM_STU == insertIndex)
	{
		student_printToFile(&toInsert, fp);
	}
	fclose(fp);
}
/* �ڰ��� 
���� 7 �����Դ���ԭ�еġ�stu_sort���ļ��������½��ļ��� 
*/
static void taskEight()
{
	int i;
	// ���ļ�
	Student stus[NUM_STU];
	FILE *fp;
	if((fp=fopen("stu_sort.csv", "r"))==NULL)
	{
		printf("��ȡ�ļ�ʧ��\n");
		return;
	}
	for(i=0; i<NUM_STU; i++)
	{
		student_readFromFile(&stus[i], fp);
	}
	fclose(fp);
	 
	#ifdef DEBUG
	// ����������
	Student toInsert = {1021, "Cai", {85,86,87}, 0}; 
	#else 
	// ��Ļ����
	Student toInsert;
	printf("������Ҫ�����ѧ����ѧ�š����������ųɼ���\n");
	scanf("%d %s %d %d %d", &toInsert->id, toInsert->name, \
	&toInsert->grades[0], &toInsert->grades[1], &toInsert->grades[2]);
	#endif 
	
	// ��¼����λ�� 
	int insertIndex = NUM_STU;
	bool isFound = false;
	student_calcAverage(&toInsert);
	for(i=0; i<NUM_STU; i++)
	{
		if(stus[i].average<toInsert.average)
		{
			insertIndex = i;
			isFound = true;
			break;
		}
	}
	
	// д�ļ�
	if((fp=fopen("stu_sort.csv", "w+"))==NULL)
	{
		printf("�򿪻򴴽��ļ�ʧ��\n");
		return;
	} 
	for(i=0; i<NUM_STU; i++)
	{
		if(i == insertIndex)
		{
			student_printToFile(&toInsert, fp);
		}
		student_printToFile(&stus[i], fp);
	}
	if(NUM_STU == insertIndex)
	{
		student_printToFile(&toInsert, fp);
	}
	fclose(fp);
}
