#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int NumberCompare(int num1, int num2); // 함수 선언 : 순서대로 함수 진행해서,
//main함수에서 호출 하려면 위에서 함수 컴페어 함수 선언해줘야됨.
int main(void) {
	printf("3과 4중 큰수는 %d이다.\n", NumberCompare(3, 4)); //함수 호출
	printf("7과 2중 큰수는 %d이다.\n", NumberCompare(7, 2));
	return 0;
}
int NumberCompare(int num1, int num2) {  // 함수 정의
	if (num1 > num2)
		return num1;
	else
		return num2;
}
