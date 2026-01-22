#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num = 20; 
	const int* ptr = &num; // 가리키는 값의 상수화
	printf("*ptr: %d\n", *ptr);

	// 중요! *ptr=30; 하면 컴파일 오류 발생 const이므로 ptr이 가리키는 값 변경 불가.
	num = 40; // num에 지정된 값 자체의 변경은 가능. ptr을 통한 변경이 안될뿐이다!
	printf("*ptr: %d\n", *ptr);

	int num1 = 20;
	int num2 = 30;
	int* const pointer = &num1; //포인터 변수의 상수화 (num1의 주소를 저장하는 pointer을 상수화함)
	printf("*pointer: %d\n", *pointer);
	//pointer=&num2; 컴파일 에러 (pointer에 저장되는 주소 값을 바꿀 수 없음)
	*pointer= 40; // *Pointer 즉 가리키는 값은 바꿀 수 있음.
	printf("*pointer: %d\n", *pointer);
	return 0;
}
/* const위치           가리키는 대상의 값 수정,          포인터가 가리키는 주소 수정
const int* ptr,        불가능 (*ptr = 10; X),            가능 (ptr = &num; O)
int* const ptr,        가능 (*ptr = 10; O),              불가능 (ptr = &num; X)
const int* const ptr,  불가능,                           불가능
*/