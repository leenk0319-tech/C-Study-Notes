/*
 * [11장~13장 종합 과제: 포인터와 메모리 구조 마스터]
 * * 1. 포인터 연산을 이용한 데이터 분석
 * - 조건: arr[i]와 같은 인덱스 접근 대신 반드시 *(ptr + i)를 사용할 것.
 * - 목표: 6개 온도 데이터의 합계와 평균 계산.
 * * 2. 포인터 배열을 이용한 명령어 관리
 * - 조건: %p 서식 지정자를 사용하여 각 문자열의 실제 메모리 주소 출력.
 * - 목표: "START", "STOP" 등 명령어의 주소와 내용을 동시에 확인.
 * * 3. 문자열 수정 가능 여부 검증 (Stack vs Data Segment)
 * - 조건: 배열 형태(char[])와 포인터 형태(char*)의 차이점을 코드로 증명.
 * - 목표: 읽기 전용(Read-Only) 영역에 대한 이해 및 런타임 에러 원인 분석.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h

int main(void) {
	// - 배열의 이름 (arr) 은 배열 시작점의 주소 (포인터 역할하는데 배열의이름은 바뀔 수 없음)
	int arr[6] = { 20, 25, 22, 30, 28, 24 };
	int* ptr = arr;
	int sum = 0;
	double avg;

	for (int i = 0; i < 6; i++) {
		// - *(ptr + i)= ptr[i] =arr[i] 
		// - 주소값에 i를 더하면 자료형(int: 4byte) 크기만큼 점프하여 참조.
		sum += *(ptr + i);
	}

	//  Type Casting (형 변환)
	// - (정수 / 정수)는 소수점을 버림. 실수 결과를 얻으려면 분모를 6.0(실수)으로 처리.
	avg = sum / 6.0;
	printf("평균: %.1f 합계: %d\n", avg, sum);

	//  Pointer Array (포인터 배열)
	// - 주소값(포인터)들을 모아놓은 배열. 각 요소가 문자열 상수의 주소를 가리킴.
	char* str[4] = { "START", "STOP", "PAUSE", "RESTART" };
	for (int i = 0; i < 4; i++) {
		// %p는 메모리 주소값을 16진수로 출력하는 서식 지정자.
		printf("[주소: %p], %s\n", str[i], str[i]);
	}

	// Stack vs Data Segment (메모리 영역 차이)
	// 1. 배열 형태: Stack 영역에 문자열을 '복사'함. 수정 가능한 영역(Read-Write).
	char str_arr[] = "Embedded";

	// 2. 포인터 형태: Read-only Data 구역에 있는 문자열의 '주소'만 가짐. 수정 불가(Read-Only).
	char* str_ptr = "Firmware";

	str_arr[0] = 'X'; // Stack 메모리는 값 변경 가능.

	// str_ptr[0] = 'Y'; 
	// Error: '읽기 전용' 메모리 영역을 수정하려 했기 때문에 Runtime Error 발생.

	printf("%s  %s ", str_arr, str_ptr);
	return 0;
}