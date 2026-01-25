#define _CRT_SECURE_NO_WARNINSG
#include <stdio.h>
int main(void) {
	int num = 10;
	int* ptr = &num;
	int** dptr = &ptr;
	int*** tptr = &dptr;
	printf("%d %d \n",**dptr,***tptr);
	return 0;
}