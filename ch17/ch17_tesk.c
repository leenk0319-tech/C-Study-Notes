/*
 * [Chapter 17 과제: 스마트 보안 구역 감시 시스템]
 * 1. Mission 1: 배열 포인터를 이용한 전용 출력 함수 구현.
 * 2. Mission 2: 특정 구역의 위험도 분석 (90점 초과 시 Warning).
 * 3. Mission 3: int *ptr[4]와 int (*ptr)[4]의 차이점 정리.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // 1. 센서 데이터를 출력하는 함수
void DisplayZoneData(int(*ptr)[4]) { // 2차원배열은 배열포인터로 받는다.
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *(*(ptr + i) + j));  //  ptr[i][j]랑 같음.
        }
        printf("\n");
    }
}

// 2. 센서 데이터를 분석하는 함수
void AnalyzeZone(int(*ptr)[4]) {
    int k = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (*(*(ptr + i) + j) > 90) //  ptr[i][j]랑 같음.
                k++;
        }
    }

    if (k > 1)
        printf("Warning\n");
    else
        printf("safe\n");
}

int main(void) {
    int security[2][4];

    printf("security 값 입력\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("security[%d][%d]: ", i, j);
            scanf("%d", &security[i][j]);
        }
    }

    // 출력 함수 호출
    DisplayZoneData(security);
    // 분석 함수 호출
    AnalyzeZone(security);

    return 0;
}

/*
 * [Mission 3: 핵심 개념 정리]
 * 1. int *ptr[4] (포인터 배열)
 * - 핵심은 '배열'. 정수형 주소(int *) 4개를 저장하는 공간입니다.
 * 2. int (*ptr)[4] (배열 포인터)
 * - 핵심은 '포인터'. 가로가 4인 배열 한 줄을 통째로 가리키는 지시봉입니다.
 * - 2차원 배열을 함수 매개변수로 받을 때 "가로가 4칸이다"라고 알려주기 위해 사용합니다.
 */