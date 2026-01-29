#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    // char 대신 int를 쓰는 이유는 EOF(-1)를 정확히 판별하기 위해서입니다. 
    int ch1, ch2;

    // getchar()는 fgetc(stdin)과 기능적으로 동일하며, 
    // \n(엔터)도 하나의 문자로 간주하여 입력 스트림에 저장됩니다. 
    ch1 = getchar();
    ch2 = fgetc(stdin);  // stdin은 키보드 입력을 의미하는 표준 입력 스트림(Standard Input Stream)이다.

    // putchar(ch1)은 fputc(ch1, stdout)과 동일
    putchar(ch1);
    // fputc의 'f'는 function 또는 file을, 'st'는 stream을 의미합니다. 
    fputc(ch2, stdout);

    return 0;
}