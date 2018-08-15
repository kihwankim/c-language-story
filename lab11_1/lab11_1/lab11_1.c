#include <stdio.h>
#include <string.h>

int mystrlen(const char *p);
int mystrcmp(const char *s1, const char *s2);

int main(void) {
	char s1[100], s2[100];
	printf("����1�� �Է��ϼ��� : ");
	scanf_s("%s", s1, sizeof(s1));
	printf("����2�� �Է��ϼ��� : ");
	scanf_s("%s", s2, sizeof(s2));
	printf("������ ���̴� : %d\n", mystrlen(s1));
	int a = mystrcmp(s1, s2);
	if (a == 0)
		printf("������ ���ڿ��Դϴ�.\n");
	else if (a > 0)
		printf("����1�� ���� �����̰ų� ���� 1�� 2�� �ٸ� ���ڿ��Դϴ�.\n");
	else
		printf("���� 2�� �� �� ���ڿ��Դϴ�.\n");
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