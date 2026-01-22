#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// int* param은 배열의 시작 주소를 받으며, param[i] = *(param + i)
// 배열의 이름: 포인터형 -> 호출이 배열의이름이면 함수 인자는 포인터여야한다. -> int * param
void ShowArayElem(int* param, int len) {
    int i;
    for (i = 0; i < len; i++) {
        // param은 주소값이므로 인덱스 연산([])을 통해 값에 접근 가능
        printf("%d ", param[i]);
    }
    printf("\n");
}

//  배열 값 수정 함수: Call by Address(주소에 의한 호출) 방식임.
// 배열의 이름: 포인터형 -> 호출이 배열의이름이면 함수 인자는 포인터여야한다. -> int * param
void AddArayElemm(int* param, int len, int add) {
    int i;
    for (i = 0; i < len; i++)
        param[i] += add; // 주소가 가리키는 실제 메모리 공간의 값을 수정합니다.
}

int main(void) {
    //  배열 선언: 메모리상에 int 3개가 연속적으로 배치됩니다.
    int arr[3] = { 1, 2, 3 };

    // sizeof(arr) / sizeof(int)
    //   - sizeof(arr): 배열 전체가 차지하는 메모리 크기 (12 byte)
    // - sizeof(int): 데이터 타입 하나의 크기 (4 byte)
    //  - 결과: 12 / 4 = 3 (배열의 전체 요소 개수 즉, len을 계산함)

    int length = sizeof(arr) / sizeof(int);

    // 함수 호출 시 배열 이름 arr은 첫 번째 요소의 주소임 
    // -> 함수 인자에서 param이라는 포인터 변수가 이 주소를 받아 작업을 수행합니다.
    AddArayElemm(arr, length, 1);
    ShowArayElem(arr, length); // 배열 전체 +1하고 그거 순서대로 출력

    AddArayElemm(arr, length, 2); //배열 전체 +1 된거에 +2하고 그거순서대로 출력
    ShowArayElem(arr, length);

    AddArayElemm(arr, length, 3);
    ShowArayElem(arr, length);

    return 0;
}