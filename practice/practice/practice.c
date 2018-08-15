#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define num 10

int main(void) {
	char a[num] = "abcd";
	char b[num] = "cddafadf";
	strcpy(b, a);
	for (int i = 0; i < 10; i++) {
		printf("%c", b[i]);
	}
	return 0;
}