#include <stdio.h>
#include <math.h>

/*-------------------------------------

���������� ���� 2 

--------------------------------------*/

//�ַ�������
#include "..\\strings.h"

#define ADDTO 10 //����Ҫ�ӵ����� 

typedef struct {
	long long int up;
	long long int down;
}RationalNumber;

//�������� 
RationalNumber addRationalNumber(RationalNumber a, RationalNumber b);
RationalNumber simplifyRationalNumber(RationalNumber a);

//������� 
int programTwo(int argc, char** argv){
	int i = 0;
	int sign = 1;
	RationalNumber sum, toAdd;
	sum = simplifyRationalNumber(sum);
	for(i = 1; i < ADDTO; i++){
		toAdd.up = sign;
		toAdd.down = i;
		sum = addRationalNumber(sum, toAdd);
		sign = -sign;
	}
	puts(str_two1);
	printf("%d\n",sum.up);
	puts(str_two2);
	printf("%d\n",sum.down);
	return 0;
}

//Լ�� 
RationalNumber simplifyRationalNumber(RationalNumber s){
	int i;
	RationalNumber simp;
	simp.down = 1;
	simp.up = 0;
	if(s.down == 0)
		return simp;
	for(i = 2; i < sqrt(fmin(s.down, s.up)); i++){
		if(s.down % i == 0 && s.up % i == 0){
			s.down = s.down/i;
			s.up = s.up/i; 
		}
	}
	return s;
}

//�������ӷ� 
RationalNumber addRationalNumber(RationalNumber a, RationalNumber b){
	RationalNumber result;
	result.down = a.down * b.down;
	result.up = a.up * b.down + b.up * a.down;
	result = simplifyRationalNumber(result);
	return result;
}

