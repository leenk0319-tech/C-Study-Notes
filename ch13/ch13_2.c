#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int arr[3] = { 11,22,33 }; 
	int* ptr = arr; // 배열의 첫 요소를 가리키는 포인터 
	// int형 이니깐 *(ptr+1) 은 (주소+4바이트) 한 주소가 가리키는값.
	printf("%d %d %d \n", arr[0], arr[1], arr[2]);
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2)); //arr[i] =*(ptr+i)
	printf("%d %d %d \n", *arr, *(arr + 1), *(arr + 2)); //arr[i] =*(arr+i) 
	return 0;
}