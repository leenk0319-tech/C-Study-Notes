#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[20];
	int score;
}Student;
int main(void) {
	Student list[3];
	for (int i = 0; i < 3; i++) {
		printf("학생 3명 이름 성적 입력\n");
		scanf("%s %d", list[i].name, &list[i].score);
	}
	int max = list[0].score;
	char name1[20];
	strcpy(name1, list[0].name);
	for (int i = 0; i < 3; i++) {
		if (max < list[i].score) {
			max = list[i].score;
			strcpy(name1, list[i].name);// 문자열 복사 함수
		}
	}
	printf("%s %d", name1, max);

}