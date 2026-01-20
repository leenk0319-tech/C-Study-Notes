#include <stdio.h>

int main(void) {
    int menu;
    int input1, input2, input3;

    while (1) {
        printf("\n--- 메뉴 ---\n");
        printf("1. 홀수의 합 구하기\n2.소수판별\n3.짝수 구구단 출력\n4.종료\n");
        printf("숫자 입력: ");
        scanf("%d", &menu);
        switch (menu) {

        case 1: { // 홀수의 합
            int sum = 0;
            printf("숫자 입력: ");
            scanf("%d", &input1);

            for (int i = 1; i <= input1; i++) {
                if (i % 2 == 0) continue; // 짝수면 건너뜀
                sum += i;
            }
            printf("합: %d\n", sum);
            break;
        }

        case 2: { // 소수 판별
            int c = 1;
            printf("소수 판별하기, 숫자 입력: ");
            scanf("%d", &input2);

            if (input2 <= 1) //1이면 소수아님
                c = 0;
            else {
                for (int i = 2; i * i <= input2; i++) {
                    if (input2 % i == 0) {
                        c = 0;
                        break;
                    }
                }
            }

            if (c==0)
                printf("소수가 아니다.\n");
            else
                printf("소수이다.\n");
            break;
        }

        case 3: { // 짝수 구구단
            printf("짝수 구구단 원하는 단 입력: ");
            scanf("%d", &input3);

            for (int i = 1; i <= 9; i++) {
                if (i % 2 != 0) continue; // 홀수면 건너뜀
                printf("%d * %d = %d\n", input3, i, input3 * i);
            }
            break;
        }

        case 4: // 종료
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 입력입니다. 1~4 중에서 다시 입력하세요.\n");
            continue; // 메뉴 다시 출력
        }
    }
}