#include <stdio.h>

/*------------------------------------------

5 �� 22 �տ�����ϰ 
�µ��� 	

��һ�������ڣ�52�� taskOne()
�ڶ��������ڣ�101�� taskTwo()
�����������ڣ�146�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int classTestMay22nd(int argc, char** argv)
{
	puts("\n----------------------5��22��ʵ���---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/* ��һ��
ppt 28 ҳ���Ӽ�������10��ѧ����������ݣ�
Ȼ�������ת�浽�����ļ���ȥ
*/
// ����ģʽ 
//#define DEBUG 
// �����ŵ��ļ��� 
#define DIR_DATA "student_data.csv"
// ����ѧ������ 
#define MAX_LEN_NAME 10
#define MAX_LEN_ADDR 15
typedef struct
{
	char name[MAX_LEN_NAME];
	int id;
	int age;
	char addr[MAX_LEN_ADDR];
}Student;
#define NUM_STU 10
static void taskOne()
{
	int i=0;
	#ifdef DEBUG
	// ���������� 
	Student stus[NUM_STU] = {{"Zhang",1001,19,"room_101"},\
	{"Sun",1002,20,"room_102"},{"Tan",1003,21,"room_103"},\
	{"Ling",1004,21,"room_104"},{"Li",1006,22,"room_105"},\
	{"Wang",1007,20,"room_106"},{"Zhen",1008,16,"room_107"},\
	{"Fu",1010,18,"room_108"},{"Qin",1012,19,"room_109"},\
	{"Liu",1014,21,"room_110"}};
	#else
	// ��Ļ����
	Student stus[NUM_STU];
	printf("������10��ѧ�������ݣ�\n");
	for(i=0; i<NUM_STU; i++)
	{
		scanf("%s", stus[i].name);
		scanf("%d", &stus[i].id);
		scanf("%d", &stus[i].age);
		scanf("%s", stus[i].addr);
	}
	#endif
	
	// д�ļ�
	FILE *fp;
	if((fp = fopen(DIR_DATA, "w")) == NULL)
	{
		printf("�޷��򿪻򴴽��ļ�\n");
		return;
	}
	else
	{
		for(i=0; i<NUM_STU; i++)
		{
			// ������ļ�������
			fprintf(fp, "%s ,%d ,%d ,%s\n", \
			stus[i].name, stus[i].id, stus[i].age, stus[i].addr);
		}
		
		// �ر��ļ�
		fclose(fp); 
	}
} 

/* �ڶ���
ppt 37 ҳ���ڴ����ϴ��� 10 ��ѧ����������ݣ�
Ҫ�󽫵� 1��3��5��7��9 ��ѧ����������� 
*/
static void taskTwo()
{
	// ���ļ�
	FILE *fp;
	Student stus[NUM_STU];
	int i;
	if((fp = fopen(DIR_DATA, "r")) == NULL)
	{
		printf("��ȡ�ļ�ʧ��\n");
		return;
	}
	else
	{
		for(i=0; i<NUM_STU; i++)
		{
			fscanf(fp, "%s ,%d ,%d ,%s", \
			stus[i].name, &stus[i].id, &stus[i].age, stus[i].addr); 
		}
		
		// ��� 
		printf("ѧ������Ϊ��\n");
		for(i=0; i<NUM_STU; i++)
		{
			printf("%-10s%4d%4d%15s\n",\
			stus[i].name, stus[i].id, stus[i].age, stus[i].addr);
		} 
	}
}

/* ������
�Ӽ�������һ���ַ����������е�Сд��ĸȫ��ת��Ϊ��д��ĸ��
Ȼ�����뵽һ�������ļ���test���н��б��档
*/
static void lowerToUpper(char* buffer, int max)
{
	char c; 
	while((c=*buffer)!='\0' && max-->0)
	{
		if('a'<=c && c<='z')
		{
			*buffer = c-32;
		}
		buffer++;
	}
} 
static void taskThree()
{
	// ��Ļ����
	char buffer[256];
	printf("������һ���ַ�����");
	scanf("%s", buffer);
	
	//����
	lowerToUpper(buffer, 256);
	
	//д�ļ�
	FILE *fp;
	if((fp=fopen("test.txt","w"))==NULL)
	{
		printf("�򿪻򴴽��ļ�ʧ��\n");
		return;
	} 
	else
	{
		fputs(buffer, fp);
		fclose(fp);
	} 
} 
