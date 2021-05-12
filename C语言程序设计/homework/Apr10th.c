#include <stdio.h>
#include <string.h> 

/*------------------------------------------

4 �� 10 ����ҵ 
�µ��� 	

��һ�������ڣ�37�� taskOne()
�ڶ��������ڣ�75�� taskTwo()
�����������ڣ�91�� taskThree()

������ҵ�������룺
https://gitee.com/littlesunny2001/Cproject.git 

-------------------------------------------*/ 
static void taskOne();
static void taskTwo(); 
static void taskThree();

//������� 
int homeworkApr10th(int argc, char** argv)
{
	puts("\n--------------------4��10�տκ���ҵ---------------------\n");
	puts("\n-------------------------��һ��-------------------------\n");
	taskOne();
	puts("\n-------------------------�ڶ���-------------------------\n");
	taskTwo();
	puts("\n-------------------------������-------------------------\n");
	taskThree();
	return 0;
}

/*��һ��
����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ��� 
*/
static void taskOne()
{
	char buffer[256];
	char c;	//�ݴ�һ���ַ� 
	int i = 0;
	int num_letter = 0;
	int num_space = 0;
	int num_number = 0;
	int num_others = 0;
	printf("������һ���ַ���");
	fgets(buffer, 256, stdin);		//gets(buffer)�İ�ȫ���� 
	while((c=buffer[i++])!= '\n')	//����ַ�ֱ���ַ���β 
	{
		if( (c<='Z'&&c>='A') || (c<='z'&&c>='a') )
		{
			num_letter++;
			continue;
		}
		if( c>='0'&&c<='9')
		{
			num_number++;
			continue;
		}
		if( c == ' ' )
		{
			num_space++;
			continue;
		}
		num_others++;
	}
	printf("Ӣ����ĸ�� %d �����ո��� %d ���������� %d ���������ַ��� %d ����\n",\
	num_letter, num_space, num_number, num_others);
} 

/*�ڶ���
����һ���ַ�������䷴���ַ��� 
������ string ����� gnirts 
*/
static void taskTwo()
{
	char buffer[256];
	int i=0;
	printf("������һ���ַ���");
	fgets(buffer,256,stdin);	//gets(buffer)
	for(i=strlen(buffer)-1; i>=0; i--)
	{
		printf("%c",buffer[i]);
	}
}

/*������
����һ���ַ��������ʷ������������ĵ����ÿո�ֿ� 
������ see you later ����� later see you 
*/ 
static void taskThree()
{
//�����Կ�����ϰ-��ʼ----------------------------------- 
#define MAX_WORD_LENGTH 15
#define MAX_WORD_NUM 30
	char buffer[256];	//�洢������ַ��� 
	int i = 0;
	int j = 0;
	int num = 0;
	int indexStart = 0;	//�ݴ�һ�����ʵ���� 
	int indexEnd = 0; 	//�ݴ�һ�����ʵ��յ� 
	int length;			//�ݴ�һ�����ʵĳ���
	char words[MAX_WORD_NUM][MAX_WORD_LENGTH]; //������е��� 
	
	printf("������һ���ַ���");
	fgets(buffer,256,stdin);	//gets(buffer); 
	
	//��������ַ����ֽ�ɶ������ 
	while((buffer[i]) != '\0')//ѭ��ֱ����⵽�ַ���β 
	{ 
		if((buffer[i] == ' ' || buffer[i] == '\n'))
		//�����ǰ�ַ�Ϊ�ո���У�����ǰһ���ַ�����Ϊ���ַ�����ȡ������Ϊ�ո�
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
		i++;
	}
//�����Կ�����ϰ-����-------------------------------------------
	
	//���
	for(i=num-1; i>=0; i--)
	{
		printf("%s ",words[i]);
	} 
}
