#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num1 = 100, num2 = 100;
	int* pnum;
	pnum = &num1; //pnum이 num1을 가리킴. num1의 주소를 pnum에 저장.
	(*pnum) += 30; // pnum이 가리키는 변수(num1)의 값에 30을 더함
	pnum = &num2;
	(*pnum) -= 30;
	printf("num1:%d num2:%d \n", num1, num2);
	return 0;
}