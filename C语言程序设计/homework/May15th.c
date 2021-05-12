#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------------------------

5 �� 15 ����ҵ 
�µ��� 	

��һ�������ڣ�45�� taskOne()
�ڶ�����������104�� find()
�����������ڣ�205�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int homeworkMay15th(int argc, char** argv)
{
	puts("\n----------------------5��15����ҵ---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ�� 
����һ��ö������ level����ö��Ԫ�ش���ɼ��ġ��ȼ���
�磺90������Ϊ�ţ�excellent����80-90��֮��Ϊ����good����
60-70��֮��Ϊ�У�general����60������Ϊ�fail����
ͨ����������һ��ѧ���ĳɼ���Ȼ����������ɼ��ĵȼ��� 
*/
enum level
{
	excellent,good,general,fail
};
static void taskOne()
{
	//����
	int input;
	printf("������һ��ѧ���ĳɼ���");
	scanf("%d",&input);
	
	//����
	enum level lev;
	switch(input/10)
	{
		case 10: case 9:
			lev = excellent;
		break;
		case 8:
			lev = good;
		break;
		case 7: case 6:
			lev = general;
		break;
		case 5: case 4: case 3: case 2: case 1: case 0:
			lev = fail;
		break;
		default:
			printf("����������\n");
		break;
	} 
	
	//���
	switch(lev)
	{
		case excellent:
			printf("�ɼ�Ϊ��\n");
		break;
		case good:
			printf("�ɼ�Ϊ��\n");
		break;
		case general:
			printf("�ɼ�Ϊ��\n");
		break;
		case fail:
			printf("�ɼ�Ϊ��\n");
		break;
	} 
}

/*�ڶ��� 
��дһ������ find�������������в���һ�������Ƿ���ڡ�
������ڣ�����ǵڼ����ڵ� 
*/
//��������洢����������
typedef int listContent;
//��������ڵ� 
typedef struct listNode
{
	listContent content;
	listNode* next;
} listNode;

static int find(listNode* head, listContent toFind)
{
	int i = 0;
	while((head = head->next) != NULL)
	{
		i++;
		if(head->content == toFind)
		{
			printf("��%d���ڵ㼴Ϊ����\n");
			return i;
		}
	}
	return 0;
}
static void taskTwo()
{
	puts("��д�ĺ���Ϊstatic int find(listNode* head, listContent toFind)");
}

/*������ 
������������ a, b�������Ⱦ�����Ϊ 3������ڵ��а���ѧ�š�������
Ҫ�����������ϲ�����ѧ���������� 
*/
//��������ڵ�
#define MAX_LEN 10
typedef struct studentListNode 
{
	int id;
	char name[MAX_LEN];
	studentListNode* next;
} studentListNode;
//��������ĳ�ڵ�֮�����Ԫ�� 
static studentListNode* insertNext(studentListNode* toInsert, int id, char* name)
{
	studentListNode *newNode, *temp;
	newNode = (studentListNode*) malloc(sizeof(studentListNode));
	newNode->id = id;
	strncpy(newNode->name,name,MAX_LEN); 
	if(toInsert == NULL)
	{
		newNode->next = NULL;
	}
	else if(toInsert->next == NULL)
	{
		toInsert->next = newNode;
		newNode->next = NULL;
	}
	else
	{
		temp = toInsert->next;
		toInsert->next = newNode;
		newNode->next = temp;
	}
	return newNode;
}

static studentListNode* mergeById(studentListNode* headA, studentListNode* headB)
{
	//������� A ��˳��
	int checkId = headA->id;
	studentListNode *pA = headA;
	do{
		if(pA->id < checkId)
		{
			printf("����aû�а�˳�����У���ʱ�޷��ϲ�\n");
			return NULL;
		}
	}while((pA=pA->next)!=NULL);
	
	//�ں��ʵ�λ�ð����� b �нڵ��������a
	studentListNode* pB = headB;
	studentListNode* last = NULL;
	studentListNode* newStart;
	do{
		pA = headA;
		while(pA!=NULL && pA->id < pB->id)
		{
			last = pA;
			pA=pA->next; 
		}
		if(last == NULL)	//��ͷ������ 
		{
			newStart = (studentListNode*) malloc(sizeof(studentListNode));
			newStart->id = pB->id;
			strncpy(newStart->name, pB->name, MAX_LEN);
			newStart->next = headA; 
			headA = newStart;
		}
		else
		{
			insertNext(last, pB->id, pB->name);
		}
	}while((pB=pB->next) != NULL);
	return headA;
}
static void print(studentListNode* head)
{
	do{
		printf("%d   %s\n", head->id, head->name);
	}while((head=head->next)!=NULL);
}
static void taskThree()
{
	//�������� a �� b 
	studentListNode *headA, *headB, *pA, *pB;
	headA = headB = NULL;
	headA = pA = insertNext(headA, 1, "ѧ��1");
	pA = insertNext(pA, 2, "ѧ��2");
	pA = insertNext(pA, 3, "ѧ��3");
	headB = pB = insertNext(headB, 5, "ѧ��5");
	pB = insertNext(pB, 4, "ѧ��4");
	pB = insertNext(pB, 6, "ѧ��6");
	
	//���ԭ��
	print(headA);
	print(headB); 
	
	//�ϲ����� a �� b
	headA = mergeById(headA, headB);
	
	//����±� 
	print(headA);
}
