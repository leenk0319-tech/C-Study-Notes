#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int SimpleFuncOne(void) {
	int num = 10; // 지역변수 선언: 지역 변수는 해당 함수 내에서만 유효
	num++;
	printf("SimpleFuncOne num: %d\n", num);
	return 0; // num이 여기까지만 유효
}
int SimpleFuncTwo(void) {
	int num1 = 20; //지역변수
	int num2 = 30; //지역 변수
	num1++, num2--;
	printf("num1 & num2 : %d %dn \n", num1, num2);
	return 0; //num1 num2 여기까지만 유효
}
int main(void) {
	int num = 17; // 위에 있는 함수에서 사용했던 지역변수 num ,다른 함수에서 똑같은 이름으로 사용가능
	SimpleFuncOne(); //함수호출
	SimpleFuncTwo(); //함수 호출
	printf("main num: %d \n", num);
	return 0; // main함수의 num여기까지 유효
}