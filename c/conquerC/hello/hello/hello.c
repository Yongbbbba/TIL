#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// chapter 13-3
// 생각해보기

// 배열 swap
void arr_swap(int* a, int* b);
// factorial
int fact(int num);
// calculator
int cal();

int main() {
	// 문제4
	// 숫자, +, -가 아닌 경우 다시 입력할 것
	// 지우기 기능
	// 계산 결과 누적
	cal();


	return 0;
}

int cal()
{
	printf("계산기 프로그램 시작\n");
	int now = 0;
	int input_num;
	int input_oper;
	printf("%d\n", now);
	while (1)
	{
		printf("\n숫자를 더하려면 1, 빼려면 2, 종료하려면 3을 눌러주세요 : ");
		int result = scanf("%d", &input_oper);
		if (!result)
		{
			printf("다시 입력해주세요\n");
			continue;
		}

		if (input_oper == 3)
		{
			printf("계산기 프로그램을 종료합니다\n");
			return 0;
		}			

		else
		{
			printf("숫자를 입력해주세요 : ");
			scanf("%d", &input_num);
			if (input_oper == 1)
			{
				now += input_num;
				printf("\n%d\n", now);
			}
			else
			{
				now -= input_num;
				printf("\n%d\n", now);
			}
		}
	}
}

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

// factorial
int fact(int num)
{
	if (num == 1)
	{
		return 1;
	}
	
	int result = num * fact(num - 1);

	return result;
}