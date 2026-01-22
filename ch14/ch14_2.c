#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap(int* ptr1, int* ptr2) { // call by reference: 함수 외부의 값 수정가능. 인자 포인터!
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
int main(void) {
	int num1 = 10;
	int num2 = 20;
	printf("num1: %d num2: %d \n", num1,num2);
	Swap(&num1, &num2); // call by reference: 호출시 배열의이름이나 주소값 사용하기!
	printf("num1: %d num2: %d \n", num1,num2);
	return 0;
