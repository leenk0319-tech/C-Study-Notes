/*
   과제 내용
 * 1. 5개 온도 입력 및 평균/최대/최소 계산
 * 2. 문자열 길이 계산 (strlen 미사용) 및 역순 뒤집기
 * 3. 평균 온도에 따른 Warning 시스템 구현
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int tem[5];
	double avg;
	int sum = 0;
	int max, min;

	printf("5개의 온도를 입력하세요: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &tem[i]);
		sum += tem[i];
	}

	//  정수/실수 연산: 결과값이 실수(double)여야 하므로 분모를 5.0으로 처리
	avg = sum / 5.0;

	max = tem[0];
	min = tem[0];
	for (int j = 0; j < 5; j++) {
		if (max <= tem[j]) max = tem[j];
		if (min >= tem[j]) min = tem[j];
	}

	printf("최대값: %d, 최솟값: %d\n", max, min);
	printf("평균값: %.1f\n", avg);

	//  공간 vs 길이: NULL(\0) 자리를 위해 배열 크기는 '최대 길이 + 1'로 선언
	char str[21]; //20이 아닌 21 NULL
	char reverse[21];
	int strL = 0;

	printf("문자열 입력: ");
	scanf("%s", str); // 배열 이름 자체가 주소이므로 & 생략 관례, &붙여도 코드는 돌아가긴함.

	// String Termination: C언어 문자열의 끝은 항상 '\0'으로 판별
	while (str[strL] != '\0') {
		strL++;
	}

	printf("문자열 길이: %d\n", strL);

	//  Index 역순 계산: 마지막 인덱스는 길이 - 1 임에 주의 
	for (int k = 0; k < strL; k++) {
		reverse[k] = str[strL - 1 - k];  //reverse[0] =str[4] ,1 = 3 ,  2 = 2 . 3 = 1 , 4 = 0 
	}

	// 중요함!!! 문자열 완성: 배열에 역순으로 문자를 채운 뒤, 반드시 마지막에 널 문자를 찍어줘야 '문자열'이 됨
	reverse[strL] = '\0';

	if (avg > 30)
		printf("Warning: %s\n", reverse);
	else
		printf("Normal: %s\n", reverse);

	return 0;
}