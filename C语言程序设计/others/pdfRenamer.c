#include <stdio.h>
#include <string.h>
#include <io.h>
#include <stdlib.h>
#include <stddef.h>

/*--------------------------------------------

pdfReader (programThree) ���� 3 

fgets û�и�����Ҫ�Ľ�������Ը�д�� myfgets

--------------------------------------------*/ 

char filenames[1000][30] = {}; //���ڴ洢����pdf�ļ����ļ��� 
int findFiles();	//���ڲ����ļ���������pdf�ļ� 
char *myfgets(char *s, int n,  FILE *stream); //��д fgets ����ʹ����Ϊ '\r' Ҳ���ڻ��� 

//������� ��ֲʱ���Ϊ main() 
int programThree(int argc, char** argv){
	int i;	//ѭ�����������ƶ�ȡ���ļ� 
	int fileNum = 0;	//�洢�ҵ������ļ����� 
	int state = 0;
	FILE *fp = NULL;
	char buff[256];
	char newName[30];
	long filePosition = 0L;
	char whetherRename = 'N';
	
	fileNum = findFiles();	//����Ŀ¼������pdf�ļ����ļ����洢��ȫ�ֱ���filenames�У��������ļ��� 
	
	for(i = 0; i <= fileNum; i++){	//ѭ��ÿһ���ļ� 
		printf("\n��ʼ�����ļ�%s\n",filenames[i]);
		fp = fopen(filenames[i], "r+");
		filePosition = 0L;		//����λ�ù��� 
		fseek(fp,filePosition,SEEK_SET);
		
		do{
			do{
			myfgets(buff,256,fp);
			filePosition = filePosition + (long)strlen(buff);

			//printf("%s",buff);		//����ʱ������ж������ַ��� 
			//putchar('\n');
			
			if(!strncmp(buff,"stream",6)){		//֮����Ҫ�� stream �����жϣ�����Ϊ 
				//puts("����ȥ���ı�����");		//���ı����к����ó�����Ϊ�ļ��Ѿ�������������� 
				while(strncmp(buff,"endstream",9)){	//�� endstream �������ı�����ֹ 
					fseek(fp, ++filePosition, SEEK_SET);
					myfgets(buff,256,fp);
				}
				//puts("endstream");
			}

		}while(strncmp(buff,"/Title (",6));		//�����ϣ�����һ����Ŀ¼�� pdf �ļ����ܶ�ȡ���ĵ�һ�� /Title () ��Ϊ���� 
		
		sscanf(buff, "/Title (%[^\t\n)]", newName);
		strcat(newName,".pdf");

		printf("\n���ڴ����ļ�%s\n\
\n��ȡ������%s���Ƿ�������������Yִ��������������N�������һ�����ܵı��⣬�����������ٴ�����ļ���\n\
��ע�⣺���û�ܼ�⵽��һ�����ܵı��⣬����������ѭ����\n",filenames[i],newName);
		scanf("%c",&whetherRename);
		getchar();		//����������������������Ļس� 
		
		}while(whetherRename == 'N');		//���� N ������ִ�м������ 
		
		fclose(fp);

		if(whetherRename == 'Y'){		//����Y��ִ�������� 
			if(rename(filenames[i], newName) < 0 ){ 
				printf("����������!\n");
				perror("rename");
			} 
			else{ 
				printf("�Ѿ���%s������Ϊ%s\n", filenames[i], newName);
				system("pause");
			} 
		}else{ 		//�����������ٴ�������ļ� 
			printf("û��������%s\n",filenames[i]);
		}
		
		printf("�ļ�%s�������\n",filenames[i]);

	} 
	puts("�����ļ��������");
	system("pause");
}

int findFiles(){
	int i = 0;
	long handle;                                                     //���ڲ��ҵľ��	
	struct _finddata_t fileinfo;                                     //�ļ���Ϣ�Ľṹ��
	
	handle=_findfirst("*.pdf",&fileinfo);                          //��һ�β��ң���pdf�ļ� 
	if(-1==handle){
		puts("û���ҵ�pdf�ļ�\n");
		return -1;
	}
	
	strcpy(filenames[0],fileinfo.name);	//����һ���ļ���д��ȫ������ 
	printf("�ҵ��ļ�%s\n", fileinfo.name);
	while(!_findnext(handle,&fileinfo))                              //ѭ�������������ϵ��ļ���ֱ���Ҳ���������Ϊֹ	
	{		
		i = i + 1;
		strcpy(filenames[i],fileinfo.name);	//��֮����ļ���д��ȫ������ 
		printf("�ҵ��ļ�%s\n", fileinfo.name);
	}	
	_findclose(handle);                                              //�رվ��		
	//printf("output done.\n");	
	//system("pause");
	return i;
}

//�� fgets() Ϊԭ�ͣ���������� || c == '\r'  ��� 
char *myfgets(char *s, int n,  FILE *stream)   
{  
    register int c;  
    register char *cs;  
    cs=s;  
    while(--n>0 &&(c = getc(stream))!=EOF)
    	if ((*cs++=  c) =='\n' || c == '\r')  //��������� || c == '\r' 
        	break;
    *cs ='\0';  
    return (c == EOF && cs == s) ?NULL :s ;  
}
