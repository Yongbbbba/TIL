#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// chapter10
	// 소수점 둘째자리까지 출력
	double f;
	while (1)
	{
		printf("값을 입력하시오 : ");
		scanf("%lf", &f);
		printf("\n");
		printf("출력: %d\n", (int)(f * 100) % 100);
	}

	return 0;
}