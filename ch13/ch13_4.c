#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num1 = 10, num2 = 20, num3 = 30;

    // int형 변수를 가리키는 포인터들의 배열
    // arr은 "포인터 배열"이며, 각 원소는 int* 타입
    int* arr[3] = { &num1, &num2, &num3 };

    // arr[0], arr[1], arr[2]는 각각 num1, num2, num3의 주소
    // *arr[i]는 해당 주소가 가리키는 변수의 값
    printf("*arr[0]:%d *arr[1]:%d *arr[2]:%d \n",
        *arr[0], *arr[1], *arr[2]);

    // 문자열 리터럴의 시작 주소를 저장하는 포인터들의 배열
    // strArr 역시 포인터 배열이며, 각 원소는 char* 타입
    char* strArr[3] = { "simple", "strinng", "Array" };

    // strArr[i]는 문자열의 시작 주소(char*)
    // %s는 문자열의 시작 주소를 받아 '\0'까지 출력  -> %p하면 주소 출력함.
    // 따라서 역참조(*) 없이 그대로 사용
    printf("strArr[0]:%s strArr[1]:%s strArr[2]:%s \n",
        strArr[0], strArr[1], strArr[2]);

    return 0;
}
