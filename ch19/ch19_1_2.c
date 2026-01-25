#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void SosimpleFunc(void) {
	printf("I'm so simple");
}
int main(void) {
	int num = 20;
	void* ptr; //void 포인터는 형정보가 존재하지않음. 어떠한 주소값도 저장이 가능.
	ptr = &ptr;
	printf("%p \n", ptr); // 형 정보가 없어서 *ptr 역참조가 불가능하다!!!!!!!!!!!!!!!!!
	ptr = SosimpleFunc;
	printf("%p \n", ptr);
	return 0;
}