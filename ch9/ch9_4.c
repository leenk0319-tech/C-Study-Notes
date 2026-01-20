#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//재귀 함수 Factorial
// 자기 자신을 다시 호출하는 함수로  함수 호출 정보는 스택(Stack)에 쌓임
int Factorial(int n) {
    // 함수가 "호출될 때" 실행되는 부분 (스택에 쌓이는 순서 확인용)
    printf(" 호출: Factorial(%d)\n", n);
    // 재귀 종료 조건 (Base Case) 더 이상 자기 자신을 호출하지 않고 값을 반환함
    if (n == 1) {
        printf(" 반환: Factorial(%d) = 1\n", n);
        return 1;
    }
    int result = n * Factorial(n - 1); // 재귀 호출 부분
    // 가장 깊은 호출부터 차례대로 되돌아오며 실행됨 (역방향)
    printf("← 반환: Factorial(%d) = %d\n", n, result);
    return result;
}
int main(void) {
        //main에서 Factorial(1) ~ Factorial(4) 호출
    for (int i = 1; i <= 4; i++) {
        printf("\n%d! 계산 시작\n", i);
        int result = Factorial(i);
        printf("%d! 최종 결과 = %d\n", i, result);
    }

    return 0;
}
