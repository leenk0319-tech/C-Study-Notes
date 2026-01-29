#include <stdio.h>
#include <string.h>   // strlen, strncpy, strncat, strcmp
#include <stdlib.h>   // atoi

int main(void) {
    char str1[20] = "12345";
    char str2[20] = "ABCDE";
    char str3[40];
    char ageStr[] = "25";
    int age;

    // strlen: 문자열 길이 계산 (널 문자 '\0'는 제외)
    printf("str1의 길이: %u\n", (unsigned int)strlen(str1));

    // strncpy: str1을 str3으로 복사
    // 지정한 길이만큼만 복사하므로 오버플로우를 방지할 수 있음
    strncpy(str3, str1, sizeof(str3) - 1);

    // strncpy는 널 문자를 보장하지 않으므로 직접 추가
    str3[sizeof(str3) - 1] = '\0';

    // strncat: str3 뒤에 str2의 앞 3글자만 이어 붙임
    strncat(str3, str2, 3);
    printf("복사 및 결합 결과: %s\n", str3);

    // strcmp: 두 문자열이 같으면 0을 반환
    if (strcmp(str1, "12345") == 0)
        puts("str1은 12345와 일치합니다.");

    // atoi: 문자열을 정수로 변환
    age = atoi(ageStr);
    printf("내년 나이: %d\n", age + 1);

    return 0;
}
