#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// chapter10
	// �Ҽ��� ��°�ڸ����� ���
	double f;
	while (1)
	{
		printf("���� �Է��Ͻÿ� : ");
		scanf("%lf", &f);
		printf("\n");
		printf("���: %d\n", (int)(f * 100) % 100);
	}

	return 0;
}