#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "strings.h"

//����Ĭ��ִ�е���ҵ��ȡ����������ִ����ѡ�� �� 
#define TARGET 12 
//�����Ƿ���Ҫѭ��
//#define LOOP 

//����������ҵ�� 
#include "homework/date.h"
#include "classTest/date.h"
#include "others/program.h"

//������� 
int main(int argc, char** argv) {
	int homework = 0;
	int returnValue = 0;
	
	#ifdef LOOP 
	do{
	#endif
	
	#ifdef TARGET
		homework = TARGET;
	#else
		system("cls");
		puts(str_main1);
		scanf("%d",&homework);
	#endif
	
		system("cls");
		switch(homework){
			
			case 0:break;
			
			case 1:
				returnValue = programOne(argc, argv);
			break;
			
			case 2:
				returnValue = programTwo(argc, argv);
			break;
			
			case 3:
				returnValue = programThree(argc, argv);
			break; 
			
			case 4:
				returnValue = homeworkMar6th(argc, argv);
			break;
			
			case 5:
				returnValue = homeworkMar13th(argc, argv);
			break;
			
			case 6:
				returnValue = homeworkMar20th(argc, argv);
			break;
			
			case 7:
				returnValue = homeworkMar27th(argc, argv);
			break;
			
			case 8:
				returnValue = classTestApr3rd(argc, argv);
			break;
			
			case 9:
				returnValue = homeworkApr4th(argc, argv); 
			break;
			
			case 10:
				returnValue = classTestApr10th(argc, argv);
			break;
			
			case 11:
				returnValue = homeworkApr10th(argc, argv);
			break;
			
			case 12:
				returnValue = classTestApr17th(argc, argv);
			break; 
			
			default:
				puts(str_main2); 
			break; 
		} 
		
	#ifdef LOOP
	}while(homework);
	#endif

	//puts(str_main3);
	return returnValue;
}
