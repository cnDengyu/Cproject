#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------

5 �� 15 �տ�����ϰ 
�µ��� 	

��һ�������ڣ�46�� taskOne()
�ڶ�����������106�� deleteNode 
��������������160�� insertNode 

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int classTestMay15th(int argc, char** argv)
{
	puts("\n----------------------5��15��ʵ���---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ��
������ѧ���� ÿ��ѧ�������ݰ���ѧ�š����������ųɼ���
�Ӽ�������ѧ�������ݣ�Ҫ��������ſγ̵���ƽ���ɼ����Լ���߷�ѧ����ѧ�� 
*/
#define NAME_LEN 10
typedef struct
{
	int id;
	char name[NAME_LEN];
	int grade1;
	int grade2;
} student;
static void taskOne()
{
	//���� 
	student students[3];
	int i;
	
	//����
	for(i=0; i<3; i++)
	{
		printf("������� %d ��ѧ����ѧ�ţ�", i+1);
		scanf("%d", &students[i].id);
		printf("������� %d ��ѧ����������", i+1);
		scanf("%s", students[i].name);
		printf("������� %d ��ѧ���ĵ� 1 �ųɼ���", i+1);
		scanf("%d", &students[i].grade1);
		printf("������� %d ��ѧ���ĵ� 2 �ųɼ���", i+1);
		scanf("%d", &students[i].grade2);
	} 
	
	//����
	double average1,average2;
	int max, id;
	//����ƽ���ɼ�
	average1 = average2 = 0;
	for(i=0; i<3; i++)
	{
		average1 += (double)students[i].grade1;
		average2 += (double)students[i].grade2;
	}
	average1 = average1/3.0;
	average2 = average2/3.0;
	//������߷�ѧ��
	max = students[0].grade1 + students[0].grade2;
	id = students[0].id;
	for(i=1; i<3; i++)
	{
		if(students[i].grade1 + students[i].grade2 > max)
		{
			max = students[i].grade1 + students[i].grade2;
			id = students[i].id;
		}
	}
	
	//���
	printf("��һ�ſγ̵���ƽ���ɼ�Ϊ��%lf\n", average1);
	printf("�ڶ��ſγ̵���ƽ���ɼ�Ϊ��%lf\n", average2);
	printf("��߷�ѧ����ѧ��Ϊ��%d", id); 
} 

/*�ڶ���
��дһ������ delete, ����ɾ����̬�����е�ָ���� N ���ڵ� 
*/
//��������ڵ� 
typedef student listContent;	//��������洢������ 
typedef struct Example
{
	listContent content;
	struct Example* next;
} listNode;					//��������ڵ� 
//��Ŀ����� delete ���� 
static void deleteNode(listNode* head, int n)
{
	listNode* p = head;
	listNode* temp;
	
	//�ҵ��� n-1 ���ڵ� 
	int i;
	for(i=1; i<n-1; i++)
	{
		if(p!=NULL)	//�հ�ȫ 
		{ 
			if(p->next != NULL)
			{
				p = p->next;
			}
		}
		else
		{
			printf("û���ҵ���%d���ڵ㣬�����һ������\n");
		}
	}
	
	//ɾ���ڵ� 
	if(p == NULL)					//�����ͷ�ڵ�Ϊ�գ������в��� 
	{
		printf("�����ͷ�ڵ�Ϊ��\n");
	}
	else if(p->next == NULL)		//�� n ���ڵ�Ϊ�գ������в��� 
	{
		printf("Ҫɾ���Ľڵ�Ϊ��\n");
	}
	else if(p->next->next == NULL)	//Ҫɾ����ǡ�������һ���ڵ� 
	{
		free(p->next);
		p->next = NULL;
	}
	else							//ǰ����ڵ������ 
	{
		temp = p->next->next;
		free(p->next);
		p->next = temp; 
	}
}
static void taskTwo()
{
	puts("��д��ɾ������ڵ�ĺ���Ϊ\n static void deleteNode(listNode* head, int n)");
}

/*������
��дһ������ insert, ������һ����̬�������ڵ� 
*/
//����ڵ�Ķ�������һ���� 
//���������������Ŀ����� insert ���� 
//������ ͷ�ڵ㡢�ڼ���������ڵ�洢������ 
static listNode* insertNode(listNode* head, int n, listContent newContent)
{
	listNode* p = head;
	listNode *temp, *newNode;
 
	//�����½ڵ㣨�ݲ����ӣ� 
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->content = newContent;
	
	//�ҵ��� n-1 ���ڵ� 
	int i;
	for(i=1; i<n-1; i++)
	{
		if(p!=NULL)	//�հ�ȫ 
		{ 
			if(p->next != NULL)
			{
				p = p->next;
			}
		}
		else
		{
			printf("û���ҵ���%d���ڵ㣬�����һ������\n");
		}
	}
	//�����½ڵ� 
	if(p == NULL)				//�������ֻ�п���ͷ�ڵ�Ϊ�� 
	{
		head = newNode;			//�½ڵ�ֱ����Ϊ�µ�ͷ�ڵ� 
	}
	else if(p->next == NULL)	//�������������β�ڵ㣬ֻ��ǰ�ڵ�û�к�ڵ� 
	{
		head->next = newNode;
		newNode->next = NULL;
	}
	else						//����ǰ��ڵ� 
	{
		temp = p->next;
		newNode->next = temp;
		p->next = newNode;
	}
	return newNode;
}
static void taskThree()
{
	puts("��д�Ĳ�������ڵ�ĺ���Ϊ\n static void insertNode(listNode* head, int n, listContent newContent)");
}
