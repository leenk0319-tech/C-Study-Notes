#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 1. 배열 형태의 문자열 (변수 성향 문자열)
	// - 메모리의 [Stack] 영역에 공간을 만들고 문자열을 '복사'해옴.
	// - str1이라는 이름은 배열의 시작 주소를 가리키는 '상수 포인터' (주소 변경 불가)
	char str1[] = "My String";

	// 2. 포인터 형태의 문자열 (상수 성향 문자열)
	// - 메모리의 [Data Segment(Read-Only)] 영역에 저장된 주소를 '참조'함.
	// - str2는 주소값을 담는 '포인터 변수' (가리키는 대상 변경 가능)
	char* str2 = "Your String";

	printf("%s %s \n", str1, str2);

	// [개념] 포인터 변수는 '변수'이므로 다른 주소값(다른 문자열)을 대입하는 것이 가능
	str2 = "Our String";
	printf("%s %s \n", str1, str2);

	// [개념] 배열은 내 소유의 메모리 공간(Stack)이므로 내부 '내용물' 수정이 가능
	str1[0] = 'X';

	// [주의] str2[0] = 'X'; 
	// - str2가 가리키는 곳은 '읽기 전용' 구역이므로 수정을 시도하면 Runtime Error(Crash) 발생

	printf("%s %s ", str1, str2);
	return 0;
}