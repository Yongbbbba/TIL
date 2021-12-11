#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �迭 swap
void arr_swap(int* a, int* b);
// factorial
int fact(int num);
// calculator
int cal();
// ���ڿ� ���� �� ������ ���� ���� �Լ�
int str_length(char* str);
// ���ڿ��� �����ϴ� �Լ�
char* str_copy(char* str1, char* str2);
// ���ڿ��� ��ġ�� �Լ�
char* str_append(char* str1, char* str2);
// ���ڿ��� ���ϴ� �Լ�
bool str_compare(char* str1, char* str2);

int main() {
	char str[20] = "hello every1";
	char str2[20] = "hello everyone";
	char str3[20] = "hello every1 hi";
	char str4[20] = "hello every1";

	if (str_compare(str, str2)) {
		printf("%s �� %s �� ���� \n", str, str2);
	}
	else {
		printf("%s �� %s �� �ٸ��� \n", str, str2);
	}

	if (str_compare(str, str3)) {
		printf("%s �� %s �� ���� \n", str, str3);
	}
	else {
		printf("%s �� %s �� �ٸ��� \n", str, str3);
	}

	if (str_compare(str, str4)) {
		printf("%s �� %s �� ���� \n", str, str4);
	}
	else {
		printf("%s �� %s �� �ٸ��� \n", str, str4);
	}

	return 0;
}

int str_length(char* str)
{
	int cnt = 0;

	while (str[cnt])
	{
		cnt++;
	}

	return cnt;
}

char* str_copy(char* str1, char* str2)
{
	// str1�� str2 �����ϱ�
	// str1�� ���̰� str2�� ���̺��� ũ�ų� ���ƾ���
	int str1_length = str_length(str1);
	int str2_length = str_length(str2);

	if (str1_length < str2_length)
		return str1;

	int ptr = 0;
	while (str2[ptr])
	{
		*(str1 + ptr) = str2[ptr++];
	}

	str1[ptr] = 0;

	return str1;
}

char* str_append(char* str1, char* str2)
{
	// str1�� str2�� ���̸� ���� ���� str1 �迭�� ũ�⺸�� �۾߾���
	int ptr = str_length(str1);
	while (*str2)
	{
		str1[ptr++] = *str2;
		str2++;
	}
	str1[ptr] = 0;
	return str1;
}

bool str_compare(char* str1, char* str2)
{
	int ptr = 0;
	while (str1[ptr] || str2[ptr])
	{
		if (str1[ptr] != str2[ptr])
			return false;
		ptr++;
	}
	return true;
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