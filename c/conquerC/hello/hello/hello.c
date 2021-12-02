#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	// chapter 11
	// 문제 1
	int size;
	printf("몇 명의 학생 성적을 입력할 것인가요? : ");
	scanf("%d", &size);
	printf("\n");
	int* scores = (int*)malloc(sizeof(int) * size);
	for (int i = 1; i <= size; i++)
	{
		int score;
		printf("%d번째 학생의 성적을 입력하세요 : ", i);
		scanf("%d", &score);
		printf("\n");
		scores[i - 1] = score;
	}
	printf("입력 종료\n");

	// 정렬
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
	// 출력
	for (int i = 0; i < size; i++)
	{
		printf("%d ", scores[i]);
	}
	printf("\n");

	// 문제2
	for (int i = 0; i < size; i++)
	{
		printf("%d번 학생       ", i + 1);
		for (int j = 0; j < scores[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	free(scores);

	return 0;
}