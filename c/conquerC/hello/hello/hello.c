#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// chapter 13-3
// �����غ���

// �迭 swap
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
	// ����1
	int scores[5][4];
	int total_average = 0;
	
	//// �Է¹ޱ�
	for (int i = 0; i < 5; i++)
	{
		char* subjects[3] = { "����", "����", "����" };
		int average = 0;
		for (int j = 0; j < 3; j++)
		{
			printf("%d�� �л��� %s ������ �Է� �ϼ��� : ", i+1, subjects[j]);
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

	//// �����ϱ�   - ����
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

	//// ����ϱ�
	for (int i = 0; i < 5; i++)
	{
		char* result;
		if (scores[i][3] >= total_average)
			result = "�հ�";
		else
			result = "���հ�";

		printf("%d�� �л��� ����� %d�Դϴ� -> %s\n", i + 1, scores[i][3], result);
	}
	
	return 0;
}