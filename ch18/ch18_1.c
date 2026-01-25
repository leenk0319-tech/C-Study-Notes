#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 2차원 배열 선언
	int arr1[2][2] = { {1,2}, {3,4} };
	int arr2[3][2] = { {1,2}, {3,4}, {5,6} };
	int arr3[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };

	// int(* ptr)[2]의 의미:
	// 1. ptr은 포인터이다.
	// 2. 가리키는 대상은 'int형 요소 2개를 가진 배열'이다.

	int(*ptr)[2];
	int i;

	// arr1의 이름은 첫 번째 행(정수 2개짜리 배열)의 시작 주소임
	ptr = arr1;
	printf("arr1출력 \n");
	for (i = 0; i < 2; i++)
		
		// ptr[i][0]의 동작 원리 (역참조 2단계)
		// 1단계: *(ptr + i) -> i번째 행의 시작 주소를 구함
		// 2단계: (*(ptr + i))[0] -> 해당 행의 0번째 열에 있는 실제 값을 꺼냄

		printf("%d  %d \n", ptr[i][0], ptr[i][1]);

	ptr = arr2;
	printf("arr2출력 \n");
	for (i = 0; i < 3; i++)
		// ptr[i]는 *(ptr + i)와 같으며, 이는 i행의 시작 '주소'를 의미함
		printf("%d  %d \n", ptr[i][0], ptr[i][1]);

	ptr = arr3;
	printf("arr3출력 \n");
	for (i = 0; i < 4; i++)
		// 포인터 연산으로 표현하면: *(*(ptr + i) + 0), *(*(ptr + i) + 1) ,(*(ptr + i))[0or 1]
		printf("%d  %d \n", ptr[i][0], ptr[i][1]);

	return 0;
}