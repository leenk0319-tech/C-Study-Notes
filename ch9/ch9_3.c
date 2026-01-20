#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void SimpleFunc(void) {
	static int num1 = 0; //static변수는 선언된함수내에서만 접근가능 딱 한번만 초기화됨.프로그램종료시까지 메모리공간에존재
	int num2 = 0; // 지역변수
	num1++, num2++;
	printf("static: %d, local:%d \n", num1, num2);// 지역변수 num2는 호출할때마다 0으로 초기화됨
}// static.변수 num1은 한번 0으로 초기화 되고 값 계속 기억해서 메모리공간에 존재함.
int main(void) {
	int i;
	for (i = 0; i < 3; i++) {
		SimpleFunc();   // 결과 1 ,1 -> 2,1 -> 3,1 
	}
	return 0;
} 