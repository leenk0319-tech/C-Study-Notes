/*
 * [Chapter 19: 드론 관제 시스템(Flight Control System)]
 * 1. Mission 1: 함수 포인터 변수 활용
 * - 함수의 이름이 메모리 주소임을 이해하고, 함수 포인터 변수(p)에 할당하여 실행.
 * 2. Mission 2: Jump Table (함수 포인터 배열)
 * - if/switch문 없이 배열의 인덱스만으로 사용자가 원하는 비행 모드를 즉시 실행.
 * 3. Mission 3: Callback 함수 구현 (ExecuteCommand)
 * - 함수를 인자로 전달받아 실행하는 구조를 통해 프로그램의 유연성을 높임.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Takeoff(void) {
	printf("드론이 이륙합니다.\n");
}
void Landing(void) {
	printf("드론이 착륙합니다.\n");
}
void Hovering(void) {
	printf("제자리 비행을 유지합니다.\n");
}


void ExecuteCommand(void (*command)(void)) { // 함수를 인자로 전달받으니깐 함수포인터로 받기/
	printf("[System] 명령을 전달받았습니다.\n");
	command(); // 전달받은 함수를 여기서 실행 (Callback)
}

int main(void) {
	void(*p)(void);//함수 포인터 선언 방법: 반환형 (*p) (매개변수) , (*p) 괄호 꼭 하기. 매개변수 2개면 (int int) 이런식으로

	p = Takeoff;
	p();
	p = Landing;
	p();
	p = Hovering;
	p();

	
	void (*FlightMode[3])(void) = { Takeoff, Landing, Hovering };

	int i;
	printf("\n비행 모드를 선택하세요 (0:이륙, 1:착륙, 2:제자리비행): ");
	scanf("%d", &i);
	FlightMode[i](); 



	printf("Callback 시스템 가동 \n");
	// 함수의 이름(Takeoff 등) 자체가 주소값이므로 인자로 바로 전달 가능
	ExecuteCommand(Takeoff);
	ExecuteCommand(Hovering);

	return 0;
}

/*
 * [Chapter 19 핵심 개념 정리]
 * 1. 함수 이름의 실체
 * - 함수 이름은 해당 함수가 저장된 Code Segment의 시작 주소를 의미함.
 * 2. 함수 포인터의 필요성
 * - 상황에 따라 실행할 함수가 달라질 때, 코드의 중복을 줄이고 유연한 설계가 가능함.
 * 3. Callback 기법
 * - 함수를 인자로 넘겨줌으로써, 호출되는 시점을 시스템이 결정하게 함.
 */