#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	// chapter 11
	// ���� 1
	int size;
	printf("�� ���� �л� ������ �Է��� ���ΰ���? : ");
	scanf("%d", &size);
	printf("\n");
	int* scores = (int*)malloc(sizeof(int) * size);
	for (int i = 1; i <= size; i++)
	{
		int score;
		printf("%d��° �л��� ������ �Է��ϼ��� : ", i);
		scanf("%d", &score);
		printf("\n");
		scores[i - 1] = score;
	}
	printf("�Է� ����\n");

	// ����
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (scores[i] > scores[j])
			{
				int temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;
			}
		}
	}
	// ���
	for (int i = 0; i < size; i++)
	{
		printf("%d ", scores[i]);
	}
	printf("\n");

	// ����2
	for (int i = 0; i < size; i++)
	{
		printf("%d�� �л�       ", i + 1);
		for (int j = 0; j < scores[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	free(scores);

	return 0;
}