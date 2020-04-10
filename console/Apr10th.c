#include <stdio.h>
#include <string.h> 

/*------------------------------------------

4 �� 3 �տ���ʵ�� 
�µ��� 
���Ŀ�ʼ�ԣ�23�� 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 

int classTestApr10th(int argc, char** argv)
{
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	return 0;
}

/*��һ��
����һ���ַ���ͳ�������ж��ٸ����ʣ�����֮���ÿո�ֿ���
�����룺I am Chinese ��������� 3 �����ʡ� 
*/ 
static void taskOne()
{
	char buffer[256];//�洢������ַ��� 
	int i = 0;
	int num = 0;
	printf("������һ���ַ���");
	gets(buffer);//��ȫ���룺fgets(buffer,256,stdin);
	do
	{ 
		if((buffer[i] == ' ' || buffer[i] == '\0') && buffer[i>0?i-1:0] != ' ')
		//�����ǰ�ַ�Ϊ�ո���ַ���β������ǰһ���ַ�����Ϊ���ַ�����ȡ������Ϊ�ո�
		{
			num++;
		}
	}while((buffer[i++]) != '\0');//ѭ��ֱ����⵽�ַ���β 
	printf("�� %d ������",num); 
} 

/*�ڶ��� 
����һ���ַ����ҳ��������а���ĳ���ַ����ĵ��ʣ�����ĵ����ÿո�ֿ�
�����룺app �Լ� apple evil application sad �ȵ���
����������������ĵ����У�apple application 
*/
#define MAX_WORD_LENGTH 15
#define MAX_WORD_NUM 30
static void taskTwo()
{
	char buffer[256];	//�洢������ַ��� 
	int i = 0;
	int j = 0;
	int num = 0;
	int indexStart = 0;	//�ݴ�һ�����ʵ���� 
	int indexEnd = 0; 	//�ݴ�һ�����ʵ��յ� 
	int length;			//�ݴ�һ�����ʵĳ���
	char key[MAX_WORD_LENGTH] = "";	//��Źؼ��� 
	char keyLength = 0;
	bool patt[MAX_WORD_NUM] = {};	//���ÿ�����ʵ�ƥ��������ֵΪ�� 
	char words[MAX_WORD_NUM][MAX_WORD_LENGTH]; //������е��� 
	
	//��ʾ����ؼ��ʺ��ַ��� 
	printf("������ؼ���:");
	scanf("%s",key);
	getchar();		//�����س� 
	printf("������һ���ַ���");
	gets(buffer);	//��ȫ���룺fgets(buffer,256,stdin);
	
	//��������ַ����ֽ�ɶ������ 
	do
	{ 
		if((buffer[i] == ' ' || buffer[i] == '\0'))
		//�����ǰ�ַ�Ϊ�ո���ַ���β������ǰһ���ַ�����Ϊ���ַ�����ȡ������Ϊ�ո�
		{
			if(buffer[i>0?i-1:0] != ' ')
			{
				indexEnd = i-1;//�ո�ǰһ���ǿո��ַ�Ϊ�����յ� 
				if(num++ > MAX_WORD_NUM)
				{
					printf("�쳣�������������\n");
					return;
				}
				length = indexEnd-indexStart+1;
				if(length < MAX_WORD_LENGTH)
				{
					strncpy(words[j], &buffer[indexStart], length);
					words[j++][length] = '\0';
				}
				else
				{
					printf("�쳣�����ʳ������\n");
					return; 
				}
			}
			indexStart = i+1;//�ո��һ���ǿո��ַ�Ϊ������� 
		}
	}while((buffer[i++]) != '\0');//ѭ��ֱ����⵽�ַ���β 
	
	//�ֱ���ÿһ������ 
	keyLength = strlen(key);//�ؼ��ʳ��� 
	for(i=0; i<num; i++)
	{
		length = strlen(words[i])>keyLength?strlen(words[i])-keyLength+1:0; 
		for(j=0; j<length; j++)
		{
			if(!strncmp(&words[i][j], key, keyLength))
			//���ؼ���������ʵ�ÿ����ĸ�����󼸸���ĸ�Ƚ� 
			{
				patt[i] = true;
				break;
			}
		}
//		printf("%s",words[i]);
	}
	
	//���ƥ����
	printf("���������ĵ����У�");
	for(i=0; i<num; i++)
	{
		if(patt[i])
		{
			printf("%s ",words[i]);
		}
	} 
}
