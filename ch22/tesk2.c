#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct student {
	char name[30];
	int age;
	int score;
}Student;
int main(void) {
	Student info1;
	Student *p=&info1;
	printf("이름   나이   성적 입력:\n");
	scanf("%s %d %d", info1.name, &info1.age, &info1.score);
	printf("이름 나이 성적 출력:%s %d %d\n",info1.name ,info1.age, info1.score);
	printf("포인터로나이 출력:%s %s\n",p->name,(*p).name);
	return 0;
}