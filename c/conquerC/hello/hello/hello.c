#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int cnt;
	int total_score = 0;
	printf("�� ���� ���� ������ �Է� ���� ���ΰ���?");
	scanf("%d", &cnt);
	
	printf("\n");
	printf("�� ������ ������ �Է��� �ּ���\n");
	for (int i = 0; i < cnt; i++)
	{
		int score;
		printf("���� %d : ", i+1);
		scanf("%d", &score);
		printf("\n");
		total_score += score;
	}

	double result = (double)total_score / cnt;
	printf("��ü ������ ����� : %lf", result);


	return 0;
}