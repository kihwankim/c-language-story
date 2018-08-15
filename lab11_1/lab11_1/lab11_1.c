#include <stdio.h>
#include <string.h>

int mystrlen(const char *p);
int mystrcmp(const char *s1, const char *s2);

int main(void) {
	char s1[100], s2[100];
	printf("문자1를 입력하세요 : ");
	scanf_s("%s", s1, sizeof(s1));
	printf("문자2를 입력하세요 : ");
	scanf_s("%s", s2, sizeof(s2));
	printf("문자의 길이는 : %d\n", mystrlen(s1));
	int a = mystrcmp(s1, s2);
	if (a == 0)
		printf("동일한 문자열입니다.\n");
	else if (a > 0)
		printf("문자1일 더긴 문장이거나 문장 1과 2가 다른 문자열입니다.\n");
	else
		printf("문자 2가 더 긴 문자열입니다.\n");
	return 0;
}

int mystrlen(const char *p) {
	int count = 0;
	for (int i = 0; p[i] != '\0'; i++) {
		count++;
	}
	return count;
}

int mystrcmp(const char *s1, const char *s2) {
	if (mystrlen(s1) > mystrlen(s2))
		return 1;
	else if (mystrlen(s1) < mystrlen(s2))
		return -1;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] != s2[i])
			return 1;
	}
	return 0;
}