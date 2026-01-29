#include <stdio.h>

void ClearInputBuffer(void) {
    // 입력 버퍼에 남아있는 문자들을 \n을 만날 때까지 모두 읽어서 소멸시킴 
    while (getchar() != '\n');
}

int main(void) {
    char perID[7];
    char name[10];

    fputs("주민번호 앞 6자리를 입력하세요: ", stdout);
    // fgets는 \n을 만날 때까지 읽어오므로 버퍼 관리가 중요함 
    fgets(perID, sizeof(perID), stdin);

    // 입력 버퍼 비우기: 6자리를 넘게 입력했을 경우 남은 데이터를 지움 
    ClearInputBuffer();

    fputs("이름을 입력하세요: ", stdout);
    fgets(name, sizeof(name), stdin);

    printf("주민번호 앞자리: %s \n", perID);
    printf("이름: %s \n", name);

    return 0;
}