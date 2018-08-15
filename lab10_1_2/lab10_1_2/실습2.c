#include<stdio.h>
#include<math.h>
#define PI 3.1415926535

int main(void) {
	for (int i = 0; i <= 360; i += 10) {
		double si = (i*PI) / 180;
		if (sin(si) >= 0) {
			for (int a = 0; a < 10; a++) {
				printf(" ");
			}
			for (int k = 0; k < 10 * sin(si); k++) {
				printf(" ");
			}
		}
		else
			for (int j = 0; j < (10 * (1 + sin(si))); j++) {
				printf(" ");
			}
		printf("*\n");
	}
	return 0;
}