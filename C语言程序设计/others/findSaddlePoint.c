/*---------------------------------------
�����Ұ���
���������������С�ĵ�Ϊ���� 
---------------------------------------*/
#include <stdio.h>

#define DEBUG
const int num = 3;

int findSaddlePoint()
{
	//���� 
	int i,j;						//���� 
	int lineMax[num],rowMin[num];	//���
	int tempmax,tempmin;			//�ݴ� 
	bool exists=false;				//�Ƿ���� 
	
	//���� 
	#ifdef DEBUG
	int array[num][num] = {{1,2,3},{4,5,6},{7,8,9}};
	#else
	int array[num][num];
	printf("������ 3��3 �����飺\n");
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	#endif
	
	//��������� 
	for(i=0; i<num; i++)
	{
		tempmax = array[i][0];
		lineMax[i] = 0;
		for(j=0; j<num; j++)
		{
			if(array[i][j]>tempmax)
			{
				tempmax = array[i][j];
				lineMax[i] = j;
			}
		}
	}
	//��������С
	for(j=0; j<num; j++)
	{
		i=0;
		tempmin = array[i][j];
		rowMin[j] = i;
		for(i=0; i<num; i++)
		{
			if(array[i][j]<tempmin)
			{
				tempmin = array[i][j];
				lineMax[j] = i;
			}
		}
	}
	
	//�Ƚ����
	for(i=0; i<num; i++)
	{
		j = lineMax[i];
		if(rowMin[j] == i)
		{
			exists = true;
			printf("�� %d �У��� %d �д��ڰ��㣺%d\n",\
			 i+1, j+1, array[i][j]);
		}
	} 
	
	if(!exists)
	{
		printf("�����ڰ���");
	}
}

