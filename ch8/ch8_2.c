#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int number, abs;
	printf("정수 입력:");
	scanf("%d", &number);
	abs = number > 0 ? number : number * (-1);
	printf("출력: %d", abs);
	return 0;
}