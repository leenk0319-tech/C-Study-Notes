#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}

int main(void) {
	int a = 10, b = 20;
	Swap(&a,&b);
	printf("%d %d", a, b);
	return 0;
}
