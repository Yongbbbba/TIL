#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int cnt;
	int total_score = 0;
	printf("몇 개의 과목 점수를 입력 받을 것인가요?");
	scanf("%d", &cnt);
	
	printf("\n");
	printf("각 과목의 점수를 입력해 주세요\n");
	for (int i = 0; i < cnt; i++)
	{
		int score;
		printf("과목 %d : ", i+1);
		scanf("%d", &score);
		printf("\n");
		total_score += score;
	}

	double result = (double)total_score / cnt;
	printf("전체 과목의 평균은 : %lf", result);


	return 0;
}