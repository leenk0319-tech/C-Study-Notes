#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int SumOdd(int n) {
    int sum = 0;;
	for (int a = 1; a <= n; a++) {
		if (a % 2 == 0)
			continue;
		sum += a;
	}
	return sum;
}
int IsPrime(int n) { //0이면 소수 아님 1이면 소수.
    int c;
    if (n == 1)
        return 0;
    for (int a = 2; a * a <= n; a++) {
        if (n % a == 0)
            return 0; // 소수 아님
    }
    return 1; //소수임
}
void PrintGugudan(int dan) {
    for (int gugu = 2; gugu < 10; gugu += 2) {
        printf("%d * %d =%d\n", dan, gugu, dan * gugu);
    }
}
int Factorial(int n) {
    if (n == 1 || n==0) {
        return 1;
    }
    int result = n * Factorial(n - 1);
    return result;

}
void ShowUsageCount(void) {
    int static i = 0;
    i++;
    printf("menu 사용 횟수:%d\n", i);
}

int main(void) {
    int menu;
    int n;

    while (1) {
        printf("\n--- 메뉴 ---\n");
        printf("1. 홀수의 합 구하기\n2.소수판별\n3.짝수 구구단 출력\n4.팩토리얼\n5.종료\n");
        printf("숫자 입력: ");
        scanf("%d", &menu);
        switch (menu) {

        case 1: { // 홀수의 합
            int sum = 0;
            printf("숫자 입력: ");
            scanf("%d", &n);
            printf("홀수 합: %d\n", SumOdd(n));
            ShowUsageCount();
            break;
        }

        case 2: { // 소수 판별
            printf("소수 판별하기, 숫자 입력: ");
            scanf("%d", &n);
            if (IsPrime(n) == 0)
                printf("소수가 아닙니다.");
            else
                printf("소수 입니다.");
            ShowUsageCount();
            break;
        }

        case 3: { // 짝수 구구단
            printf("짝수 구구단 원하는 단 입력: ");
            scanf("%d", &n);
            PrintGugudan(n);
            ShowUsageCount();
            break;
        }
        case 4: { // 팩토리얼
            printf("팩토리얼 숫자 입력: ");
            scanf("%d", &n);
            printf("%d!: %d \n", n, Factorial(n));
            ShowUsageCount(); 
            break; }

        case 5: // 종료
            printf("프로그램을 종료합니다.\n");
            return 0;

        default: {
            printf("잘못된 입력입니다. 1~5 중에서 다시 입력하세요.\n");
            continue; // 메뉴 다시 출력
        }
        }
    }
}