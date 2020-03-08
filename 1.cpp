#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

/*---------------------------------- 

	������󣬴��� 1
	
----------------------------------*/

//������������������ 
#define LINE 15
#define ROW 15
 
 //ȫ�ֱ��������ڴ洢������Ϣ 
int show[LINE][ROW];

//�������� 
void setShow();
void showMap();
void showInfo();
void refreshShow();

//�ַ�������
extern char* str_one1; 

//������� 
int programOne(int argc, char** argv){
	char move = 'w';
	int temp[2] = {0,0};			//�ݴ浱ǰ����λ�� 

	setShow();						//��������ȫ��Ϊ 0
	show[temp[0]][temp[1]] = 1;		//��ǰλ���� 1 
	refreshShow();
	
	while(move != '0'){
		move = getchar();
		show[temp[0]][temp[1]] = 0;	//��ǰ����һ��ѭ�������õģ�λ���� 0 
		switch(move){				//������룬�޸ĵ�ǰλ�� 
			case 'w':
				if(temp[0]>0)
					temp[0] -= 1;
			break;
			case 'a':
				if(temp[1]>0)
					temp[1] -= 1;
			break;
			case 's':
				if(temp[0]<LINE-1)
					temp[0] += 1;
			break;
			case 'd':
				if(temp[1]<ROW-1)
					temp[1] +=1;
			break;
			default:break; 
		}
		show[temp[0]][temp[1]] = 1;	//��ǰλ���� 1 
		refreshShow();
		//Sleep(1000); 
	}
	
}

//��ʼ���������飬ȫ��ֵΪ 0
void setShow(){
	int i,j;
	for(i = 0; i < LINE; i ++){
		for(j = 0; j < ROW; j ++){
			show[i][j] = 0;
		}
	}
}

//��ʾ���� ����Ҫ����������ʹ�� 
void showMap(){
	int i,j;
	for(i = 0; i < LINE; i++){
		for(j = 0; j < ROW; j++){
			if(show[i][j])
				putchar('@');	//����Ϊ @
			else
				putchar('O');	//��Ϊ O
			putchar(' ');
		}
		putchar('\n');
	}
}

//�����ʾ ����Ҫ����������ʹ�� 
void showInfo(){
	puts(str_one1);
}

//ˢ������ҳ�� 
void refreshShow(){
	system("cls");
	showInfo();
	showMap(); 
}
