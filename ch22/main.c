#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
};
struct person {
	char name[20];
	char phonenum[20];
	int age;
};
int main(void) {
	struct point pos = { 10,20 };
	struct person man = { "¿Ã≥≤±«","010-1234-5678",24 };
	printf("%d %d\n", pos.xpos, pos.ypos);
	printf("%s %s %d", man.name, man.phonenum,man.age);
	return 0;
}