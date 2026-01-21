#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {    //*** NULL(\0)이 없으면 문자배열 NULL이 있으면 문자열이다. ( 끝이 존재 )
	char str[50];   // scanf로 문자열 입력시 %s사용, 
	int idx = 0;
	printf("문자열 입력: ");
	scanf("%s", &str);  //공백( 띄어쓰기가 있는 문장사용시) 띄어쓰기에서 끊김. 
	printf("입력 받은 문자열: %s\n", str); //scanf는 공백을 기준으로 데이터의 수를 구분한다.
	                                           // 공백을 포함하는 문자열을 한번의 scanf로 읽어오지는 못한다.
	printf("문자 단위출력: ");
	while (str[idx] != '\0') { //scanf로 사용시 입력 받은 문자열의 끝에도 널문자가 존재 (널문자일때까지 반복)
		printf("%c", str[idx]);
		idx++;
	}
	printf("\n");
	return 0;
}