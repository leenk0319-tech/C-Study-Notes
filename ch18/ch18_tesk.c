/*
 * [Chapter 18 과제: 이중 포인터를 이용한 시스템 로그 및 상태 관리]
 * 1. Mission 1: SwapLogAddress 함수 구현
 * - 함수 외부(main)에 선언된 두 '포인터 변수'의 주소값을 서로 교체함.
 * - 이중 포인터(char**)를 사용하여 포인터 자체의 값을 변경하는 Call-by-Reference를 실습.
 * 2. Mission 2: UpdateStatus 함수 구현
 * - 포인터를 통해 함수 외부의 변수에 새로운 문자열 상수의 주소를 할당함.
 * 3. Mission 3: 메모리 구조 이해
 * - 포인터와 문자열 상수의 관계, 그리고 다중 역참조의 원리를 파악함.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void SwapLogAddress(char** a, char**b) { // 바꾸고 싶은게 뭐야 -> 문자열 시작의 주소(문자열의 주소)
	char* temp = *a; //a = p1의 주소   * a = E의주소   **a = E
	*a = *b;  
	*b = temp; // temp이 문자열의시작주소(E의주소)   *temp는 *a의 역참조니깐 E임

}
void UpdateStatus(char** update) {
	char* running = "running";
	*update = running;
}
int main(void) {
	char* p1 = "Error: High Temperature"; // p1은 문자열의 주소(첫 주소 즉 E의 주소)
	char* p2 = "Status: Fan cooling";
	SwapLogAddress(&p1, &p2); // p1=E의주소 p2=S의 주소, p1과 p2의 주소를 바꿔야지 main 함수에서도 swap효과 적용됨
	printf("%s\n", p1);
	printf("%s\n", p2);
	char* current_status;
	UpdateStatus(&current_status);
	printf("%s", current_status);
	return 0;
}
/*
 * [Chapter 18 핵심 개념 정리]
 * 1. 이중 포인터(char**)가 필요한 이유
 * - 싱글 포인터(char*)를 함수 인자로 넘기면 '주소값의 복사본'이 전달됨.
 * - 따라서 함수 내에서 값을 바꿔도 main의 원본 포인터는 변하지 않음.
 * - 원본 포인터 변수 자체를 바꾸려면 '포인터의 주소'를 넘겨야 하므로 이중 포인터가 필수임.
 * * 2. 역참조의 단계
 * - a (char**): 포인터 변수 p1의 주소
 * - *a (char*): p1이 가지고 있는 주소 (문자열의 시작 위치) -> printf %s가 필요로 하는 값
 * - **a (char): 문자열의 첫 번째 글자 'E' 그 자체
 */