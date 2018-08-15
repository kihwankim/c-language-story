#include <stdio.h>
#include <string.h>
#define NUM 100

void reverse(const char *s1);
void revword(const char *s1);

int main(void) {
	char str[NUM];
	printf("입력하고 싶은 문자를 넣어주세요 : ");
	scanf_s("%[^\n]", str, sizeof(str));
	reverse(str);

	return 0;
}

void reverse(const char *s1) {
	char *con = NULL;
	char *a = strtok_s(s1, " ", &con);
	while(a != NULL){
		revword(a);
		printf(" ");
		a = strtok_s(NULL, " ", &con);
	}
}

void revword(const char *s1) {
	char a[NUM];
	int leng = strlen(s1);
	for (int i = leng; i != 0; i--) {
		a[leng - i] = s1[i - 1];
	}
	for (int i = 0; i < leng; i++) {
		printf("%c", a[i]);
	}
}