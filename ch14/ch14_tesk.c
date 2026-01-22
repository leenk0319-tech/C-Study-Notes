/*
 * [14장 종합 과제: 함수와 포인터의 활용]
 * 1. Call-by-Reference를 이용한 데이터 교환 및 연산 (UpdateSystem)
 * - 두 변수의 값을 Swap하고 값을 2배로 증가시킴.
 * 2. const 포인터를 이용한 데이터 보호 (ShowVersion)
 * - 출력 전용 함수에서 원본 데이터 수정을 방지함.
 * 3. 포인터를 이용한 다중 값 반환 (GetSensorStatistics)
 * - return 대신 포인터 매개변수를 통해 최댓값과 최솟값을 동시에 전달.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 // Call-by-Reference: 주소값을 전달하여 함수 외부의 변수를 직접 수정함.
void UpdateSystem(int* volt, int* ampere) {
	int temp;
	temp = *volt;
	*volt = *ampere;
	*ampere = temp;

	// 주소에 저장된 실제 값에 접근하여 연산
	*volt *= 2;
	*ampere *= 2;
}

// const char*: 함수 내에서 문자열 내용을 변경할 수 없도록 보호한다.
void ShowVersion(const char* version) {
	// 중요 printf의 %s는 문자열의 '시작 주소'를 받아야 함. 
	// *version이라고 쓰면 글자 하나(char)만 넘어가서 오류가 발생하므로 주소값인 version을 그대로 사용해야됨/
	printf("%s\n", version);
}

//  C언어의 return은 한 개의 값만 반환하지만, 포인터를 쓰면 여러 데이터를 반환받는 효과를 냄.
int GetSensorStatistics(int* arr, int len, int* max, int* min) {
	*max = arr[0];
	*min = arr[0];

	for (int i = 1; i < len; i++) {
		// 현재 저장된 최댓값/최솟값(*max, *min)과 배열 요소를 비교하여 갱신
		if (*max < arr[i])
			*max = arr[i];
		if (*min > arr[i])
			*min = arr[i];
	}
}

int main(void) {
	int Volt, Ampere;
	printf("Volt입력: ");
	scanf("%d", &Volt);

	printf("Ampere입력: ");
	scanf("%d", &Ampere);

	// 변수의 주소(&) 넘겨줌
	UpdateSystem(&Volt, &Ampere);
	printf("결과 -> Volt:%d Ampere:%d\n", Volt, Ampere);

	char Version[] = "version 1";
	ShowVersion(Version);

	int arr[6] = { 31, 22, 36, 47, 58, 63 };
	int max, min;

	// max와 min의 주소전달, 배열의 이름 arr전달 -> call by reference 
	GetSensorStatistics(arr, 6, &max, &min);
	printf("통계 -> 최댓값: %d, 최솟값: %d\n", max, min);

	return 0;
}