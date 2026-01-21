#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int arr1[3] = { 1,2,3 };
	int* ptr = &arr1[0]; // 포인터를 배열의이름 처럼 사용하기
	printf("*arr1: %d, *ptr:%d \n", *arr1, *ptr); //배열이름의 포인터형
	printf("arr1[0]: %d, ptr[0]:%d \n ", arr1[0], ptr[0]);// 포인터를 배열의이름 처럼 사용하기
	*arr1 += 100;
	printf("*arr1:%d, arr[0]:%d = ptr[0]:%d ", *arr1,arr1[0],ptr[0]);
	return 0;
}