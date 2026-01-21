#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>
int main(void) {
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,5,6,7 }; //컴파일러가 길이정보를 채운다. 7로
	int arr3[5] = { 1,2 }; // 빈 배열은 컴파일러가 0으로 채운다. 1 2 0 0 0
	int arrL1, arrL2, arrL3, i;
	printf("arr1 배열의 크기: %d \n", sizeof(arr1)); // 배열의 크기 (길이 * 4바이트-int)
	printf("arr2 배열의 크기: %d \n", sizeof(arr2));
	printf("arr3 배열의 크기: %d \n", sizeof(arr3));
	arrL1 = sizeof(arr1) / sizeof(int); //배열의 길이 계산
	arrL2 = sizeof(arr2) / sizeof(int);
	arrL3 = sizeof(arr3) / sizeof(int);
	for (i = 0; i < arrL1; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < arrL2; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < arrL3; i++) {
		printf("%d ", arr3[i]);
	}
	printf("\n");
}