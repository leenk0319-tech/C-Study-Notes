#include <stdio.h>

int main(void) {
    char str[20];

    // 1. fputs & puts: 출력 함수의 차이점
    fputs("1. fputs 출력: ", stdout); // 자동 줄 바꿈 없음
    fputs("Hello C ", stdout);

    puts("\n2. puts 출력: ");         // 자동 줄 바꿈 포함
    puts("Hello C");
    puts("Programming");

    // 3. fgets: 안전한 문자열 입력
    printf("\n문자열을 입력하세요(최대 19자): ");

    // sizeof(str) 을 넘지 않게 읽어와 Buffer Overflow를 방지합니다. 
    fgets(str, sizeof(str), stdin); // fgets(저장소, 크기, stdin) 순

    // 4. 입력 결과 확인
    printf("입력받은 내용(fputs): ");
    fputs(str, stdout); // fgets는 엔터(\n)까지 문자열로 저장하므로 그대로 출력됨 

    printf("입력받은 내용(puts): \n");
    puts(str); // str 내부의 \n + puts 자체의 \n 때문에 두 번 줄 바꿈 발생

    return 0;
}