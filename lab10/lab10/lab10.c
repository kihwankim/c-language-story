#include <stdio.h>

int cal_len(int num);
int nth_dighit(int num, int i, int length);
int is_pal_num(int num, int n, int length);

int main(void) {
	int num, choosenum;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &num, sizeof(num));
	printf("���° �� : ");
	scanf_s("%d", &choosenum, sizeof(choosenum));
	printf("���� : %d\n", cal_len(num));
	printf("%d ��° �� : %d\n", choosenum, nth_dighit(num, choosenum, cal_len(num)));
	int b = is_pal_num(num, cal_len(num), cal_len(num));
	if (b == 1)
		printf("ȸ���Դϴ�\n");
	else
		printf("ȸ���� �ƴմϴ�\n");
	return 0;
}

int cal_len(int num) {
	int count = 0;
	for (int k = num; k % 10 != 0; k = k / 10) {
		count++;
	}
	return count;
}

int nth_dighit(int num, int i, int lenght) {
	int realnum;
	int temp = num;
	for (int a = 0; a < i; a++) {
		realnum = temp % 10;
		temp = temp / 10;
	}
	return realnum;
}

int is_pal_num(int num, int n, int length) {
	if (nth_dighit(num, length - n + 1, length) != nth_dighit(num, n, length))
		return 0;
	else if (n == length / 2)
		return 1;
	else
		return is_pal_num(num, n - 1, length);
}