#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ] 2차원 배열의 함수 전달
// 2차원 배열이 함수의 인자로 전달될 때는 가로 길이(열) 정보가 고정되어야 합니다.
// int (*arr)[4] 또는 int arr[][4] 형태로 선언하며, 세로 길이는 별도의 인자로 받습니다.
 
void ShowArr2DStyle(int(*arr)[4], int row) {
    int i, j;
    printf("--- 배열 요소 전체 출력 ---\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            // [개념 2] arr[i][j]는 포인터 연산으로 *(*(arr + i) + j)와 같다
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Sum2DArr(int arr[][4], int row) {
    int i, j, sum = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            sum += *(*(arr + i) + j); // 포인터 연산 방식 사용
        }
    }
    return sum;
}

int main(void) {
    // 가로 길이가 4인 2차원 배열 선언
    int arr1[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
    int arr2[3][4] = { {1, 1, 1, 1}, {3, 3, 3, 3}, {5, 5, 5, 5} };

    //배열의 세로 길이(row) 계산 방식
    // sizeof(arr) / sizeof(arr[0]) 공식을 사용합니다.
    // sizeof(arr): 배열 전체의 크기
    // sizeof(arr[0]): 배열 한 행(row)의 크기
    
    int row1 = sizeof(arr1) / sizeof(arr1[0]);
    int row2 = sizeof(arr2) / sizeof(arr2[0]);

    ShowArr2DStyle(arr1, row1);
    ShowArr2DStyle(arr2, row2);

    printf("arr1의 합: %d \n", Sum2DArr(arr1, row1));
    printf("arr2의 합: %d \n\n", Sum2DArr(arr2, row2));

    // 2차원 배열 요소 접근의 다양성 (image 2 핵심)
    // 아래 네 문장은 모두 동일한 결과(arr1[1][2]의 값인 7)를 나타냅니다.
    
    printf("--- 다양한 요소 접근 방식 (arr1[1][2] 출력) ---\n");
    printf("1. 인덱스 방식: %d\n", arr1[1][2]);                         // 표준 방식
    printf("2. 포인터+인덱스 혼합: %d\n", (*(arr1 + 1))[2]);            // *(arr + i) == arr[i]
    printf("3. 인덱스+포인터 혼합: %d\n", *(arr1[1] + 2));              // 행의 주소에 열 오프셋 더하기
    printf("4. 순수 포인터 연산: %d\n", *(*(arr1 + 1) + 2));            // 이중 역참조(double dereference)

    return 0;
}