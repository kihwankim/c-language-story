#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define num 100

int wordcount(const char *s1, const char *s2);
void deleteword(const char *s1, const char *s2, const char *s3);

int main() {
	char *con = NULL;
	char a[num];	// 인자를 받아들이기 위한 변수 s1
	char tempa[num];// 인자의 첫부분을 받아들이기 위한 변수 
	char newa[num];	// 인자를 대입하기 위해 쓰는 변수 s2
	char *nextemp;	// 메인문 마지막에 NULL을 식별하기 위해 임시로 저장하는 문자열
	printf("문자를 입력하세요 : ");
	scanf_s("%[^\n]", a, sizeof(a));
	strcpy(tempa, a);
	strcpy(newa, a);
	
	char *temp = strtok_s(tempa, " ,:\t", &con);	// 첫번째 토큰 추출 s3
	while(1) {
		con = NULL;	// 첫번째 토큰과 같은 문자를 제거하고 나머지의 문자열을 자르기위해 다시 초기화했음
		printf("%s : %d\n", temp, wordcount(a, temp));	//내가 추출흔 문자와 빈도수 출력
		strcpy(a, newa);// a 문자열 복구

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
		혁진이 아이디어*/
		deleteword(a, newa, temp);	//추출한 토큰 제거
		strcpy(newa, a);	//newa를 a랑 동일시 token으로 쪼개면 값이 변화므로 복제품이 필요
		temp = strtok_s(a, " ,:\t", &con);	//다시 첫 문장을 추출
		strcpy(a, newa);
		if ((nextemp = strtok_s(NULL, " ,:\t", &con)) == NULL) {
			printf("%s : %d\n", temp, wordcount(a, temp));
			break;
		}	// 예외 경우 발생 마지막에 새로운 한개면 가능하나 앞에 있는 무언가 있으면 바로 쓰레기값이 출력됨
		strcpy(a, newa);	//a초기화
	}
	
	return 0;
}

int wordcount(const char *s1, const char *s2) {//s1 : 전체 문장 s2 : 필요한 문장(temp)
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

void deleteword(char *s1, char *s2, const char *s3) { // s1 : 전체문장, s2 지우고 난 문장, s3 지우고자 하는 문자열
	char *con = NULL;
	char atemp[num];
	char other[num];
	char *a = " ";
	s2 = atemp;//s2를 공백으로 만들기 실패
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
}// 이 함수에서 함수 종료시 s1은 내가 설정한 값이 그대로 유지 but s2는 원래의 초기화 했는값으로 돌아간다
//만약 abcd efg efg이런 형식이면 문장 종료후 s1이 쓰레기값인 공백의 배열이된다 이점을 보완해야한다.