#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// chapter 13-3
// �����غ���

// �迭 swap
void arr_swap(int* a, int* b);
// factorial
int fact(int num);
// calculator
int cal();

int main() {
	// ����4
	// ����, +, -�� �ƴ� ��� �ٽ� �Է��� ��
	// ����� ���
	// ��� ��� ����
	cal();


	return 0;
}

int cal()
{
	printf("���� ���α׷� ����\n");
	int now = 0;
	int input_num;
	int input_oper;
	printf("%d\n", now);
	while (1)
	{
		printf("\n���ڸ� ���Ϸ��� 1, ������ 2, �����Ϸ��� 3�� �����ּ��� : ");
		int result = scanf("%d", &input_oper);
		if (!result)
		{
			printf("�ٽ� �Է����ּ���\n");
			continue;
		}

		if (input_oper == 3)
		{
			printf("���� ���α׷��� �����մϴ�\n");
			return 0;
		}			

		else
		{
			printf("���ڸ� �Է����ּ��� : ");
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