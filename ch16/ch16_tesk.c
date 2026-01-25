/*
* [Chapter 16:스마트 팩토리 불량률 분석 및 관리 시스템]
* 1. 2차원 배열(3x4)을 활용하여 3개 라인, 4개 공정의 불량률 데이터를 관리함.
* 2. 전체 데이터의 통계(합계, 평균) 및 평균을 상회하는 공정 개수를 산출함.
* 3. 배열 내 최댓값을 찾고, 해당 값의 위치(Row, Column Index)를 정확히 특정함.
* 4.[핵심] 배열 포인터(Array Pointer)와 포인터 연산을 사용하여 특정 행(Row)을 통째로 교체함.
*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 2차원 배열을 배열 포인터로 받음
void RowSwap(int(*arr)[4], int r1, int r2) {
	for (int i = 0; i < 4; i++) {
		// *(*(arr + r1) + i) 는 arr[r1][i]와 완벽히 같은 의미입니다.
		int temp = *(*(arr + r1) + i);
		*(*(arr + r1) + i) = *(*(arr + r2) + i);
		*(*(arr + r2) + i) = temp;
	}
}
int main(void) {
	int factory[3][4];
	int sum = 0;
	double avg;
	int count = 0;
	printf("12개의 불량률 데이터 입력하세요(0~100사이 정수)\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("factory[%d][%d] 의불랑률:",i,j);
			scanf("%d", &factory[i][j]); //&붙이는 이유 factory[i][j]는 값임 주소가 아니라. 주소일때만 &안붙임(예:factory)
		}	
	}
	printf("현재 공정 상태\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) printf("%d\t", factory[i][j]);
		printf("\n");
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			sum += factory[i][j];
	}
	avg = sum / 12.0;
	printf("sum: %d , avg: %.2f\n", sum, avg);


	int max = factory[0][0];
	int maxrow = 0, maxcolumn = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (max < factory[i][j]) {
				max = factory[i][j];
				maxcolumn = i;
				maxrow = j;
			}
		}
	}
	printf("불량률 최대인 경우: factory[%d][%d]: %d\n", maxcolumn, maxrow, max);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (avg < factory[i][j])
				count++;
		}
	}
	printf("평균보다 높은 불랑률의 개수: %d\n", count);

	;
	RowSwap(factory, 0, 2);
	printf("교체 후 공정 상태\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) printf("%d\t", factory[i][j]);
		printf("\n");
	}
	return 0;
}