#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이중 포인터를 이용한 포인터 값(주소) 교환 함수
void SwapIntPtr(int** dp1, int** dp2) {
    // *dp1은 main의 ptr1(num1주소) , *dp2는  ptr2(num2의주소)를 직접 지칭함
    int* temp = *dp1;  
    *dp1 = *dp2;      
    *dp2 = temp;      
}

int main(void) {
    int num1 = 10, num2 = 20;
    int* ptr1 = &num1, * ptr2 = &num2;
    printf("*ptr1:%d *ptr2:%d \n", *ptr1, *ptr2);

    SwapIntPtr(&ptr1, &ptr2); // 포인터가 가리키는 대상을 바꾸기 위해 포인터의 '주소'를 전달 (Call by reference)
    printf("*ptr1:%d *ptr2:%d \n", *ptr1, *ptr2);


    // --- 포인터 배열과 이중 포인터의 관계 ---
    int num3 = 30, num4 = 40;
    int* ptr3 = &num3, * ptr4 = &num4;
    int* ptrarr[] = { ptr3, ptr4 }; //포인터 배열
    int** dptr = ptrarr; // 배열의 이름은 첫 번째 요소(int*)의 주소임 ( 배열의 이름 -> 이중포인터 )

    // 1. 배열 인덱스 활용
    printf("%d %d \n", *(ptrarr[0]), *(ptrarr[1]));
    // 2. 배열 이름(포인터) 연산과 이중 역참조(double dereference)
    printf("%d %d \n", **(ptrarr), **(ptrarr + 1));
    // 3. 이중 포인터 변수와 인덱스 활용 (dptr[i] == *(dptr + i))
    printf("%d %d \n", *(dptr[0]), *(dptr[1]));
    // 4. 이중 포인터 변수 연산 활용
    printf("%d %d \n", **dptr, **(dptr + 1));

    return 0;
}