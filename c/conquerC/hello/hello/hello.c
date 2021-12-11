#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// chapter 13-3
// 생각해보기

// 배열 swap
void arr_swap(int *a, int *b)
{
	int temp[4];
	for (int i = 0; i < 4; i++)
	{
		temp[i] = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = temp[i];
	}
}

int main() {
	// 문제1
	int scores[5][4];
	int total_average = 0;
	
	//// 입력받기
	for (int i = 0; i < 5; i++)
	{
		char* subjects[3] = { "수학", "국어", "영어" };
		int average = 0;
		for (int j = 0; j < 3; j++)
		{
			printf("%d번 학생의 %s 점수를 입력 하세요 : ", i+1, subjects[j]);
			int score;
			scanf("%d", &score);
			printf("\n");
			scores[i][j] = score;
			average += score;
		}
		scores[i][3] = average / 3;
		total_average += scores[i][3];
	}

	total_average /= 5;

	//// 정렬하기   - 버블
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (scores[i][3] > scores[j][3])
			{
				arr_swap(scores[i], scores[j]);
			}
		}
	}

	//// 출력하기
	for (int i = 0; i < 5; i++)
	{
		char* result;
		if (scores[i][3] >= total_average)
			result = "합격";
		else
			result = "불합격";

		printf("%d번 학생의 평균은 %d입니다 -> %s\n", i + 1, scores[i][3], result);
	}
	
	return 0;
}