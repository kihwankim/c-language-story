#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define num 100

int wordcount(const char *s1, const char *s2);
void deleteword(const char *s1, const char *s2, const char *s3);

int main() {
	char *con = NULL;
	char a[num];	// ���ڸ� �޾Ƶ��̱� ���� ���� s1
	char tempa[num];// ������ ù�κ��� �޾Ƶ��̱� ���� ���� 
	char newa[num];	// ���ڸ� �����ϱ� ���� ���� ���� s2
	char *nextemp;	// ���ι� �������� NULL�� �ĺ��ϱ� ���� �ӽ÷� �����ϴ� ���ڿ�
	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%[^\n]", a, sizeof(a));
	strcpy(tempa, a);
	strcpy(newa, a);
	
	char *temp = strtok_s(tempa, " ,:\t", &con);	// ù��° ��ū ���� s3
	while(1) {
		con = NULL;	// ù��° ��ū�� ���� ���ڸ� �����ϰ� �������� ���ڿ��� �ڸ������� �ٽ� �ʱ�ȭ����
		printf("%s : %d\n", temp, wordcount(a, temp));	//���� ������ ���ڿ� �󵵼� ���
		strcpy(a, newa);// a ���ڿ� ����

/*		for (int i = 0; a[i] != '\0'; ++i) {
			if (*(a+i) == *(temp)) {
				int j;
				for (j = 0; *(temp + j) != '\0'; ++j) {
					if (*(a + i + j) != *(temp + j)) {
						i = j;
						break;
					}
				}
				memcpy()
			}
		}
		������ ���̵��*/
		deleteword(a, newa, temp);	//������ ��ū ����
		strcpy(newa, a);	//newa�� a�� ���Ͻ� token���� �ɰ��� ���� ��ȭ�Ƿ� ����ǰ�� �ʿ�
		temp = strtok_s(a, " ,:\t", &con);	//�ٽ� ù ������ ����
		strcpy(a, newa);
		if ((nextemp = strtok_s(NULL, " ,:\t", &con)) == NULL) {
			printf("%s : %d\n", temp, wordcount(a, temp));
			break;
		}	// ���� ��� �߻� �������� ���ο� �Ѱ��� �����ϳ� �տ� �ִ� ���� ������ �ٷ� �����Ⱚ�� ��µ�
		strcpy(a, newa);	//a�ʱ�ȭ
	}
	
	return 0;
}

int wordcount(const char *s1, const char *s2) {//s1 : ��ü ���� s2 : �ʿ��� ����(temp)
	int count = 0;
	char *con = NULL;
	char *temp = strtok_s(s1, " ,:\t", &con);
	if (strncmp(temp, s2, sizeof(temp)) == 0)
		count++;
	temp = strtok_s(NULL, " ,:\t", &con);
	while (temp != NULL) {
		if (strcmp(temp, s2) == 0)
			count++;
		temp = strtok_s(NULL, " ,:\t", &con);
	}
	return count;
}

void deleteword(char *s1, char *s2, const char *s3) { // s1 : ��ü����, s2 ����� �� ����, s3 ������� �ϴ� ���ڿ�
	char *con = NULL;
	char atemp[num];
	char other[num];
	char *a = " ";
	s2 = atemp;//s2�� �������� ����� ����
	for (char *temp = strtok_s(s1, " ,:\t", &con); temp != NULL; temp = strtok_s(NULL, " ,:\t", &con)) {
		if (strncmp(temp, s3, sizeof(s3)) != 0) {
			if(strncmp(s2, other, sizeof(s2)) == 0)
				strcpy(s2, temp);
			else {
				strcat(s2, a);
				strcat(s2, temp);
			}
		}
	}
/*	if (strcmp(s2, other) == 0) {
		s1 = NULL;
		return;
	}*/
	strcpy(s1, s2);
}// �� �Լ����� �Լ� ����� s1�� ���� ������ ���� �״�� ���� but s2�� ������ �ʱ�ȭ �ߴ°����� ���ư���
//���� abcd efg efg�̷� �����̸� ���� ������ s1�� �����Ⱚ�� ������ �迭�̵ȴ� ������ �����ؾ��Ѵ�.