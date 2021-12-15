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
// ���ڿ� ���� ���
int str_revere_print(char* str);
// �ҹ��� -> �빮��, �빮�� -> �ҹ��� ���
int str_upper_lower_print(char* str);
int str_find(char* str1, char* str2);

// ���� ���� ���α׷�
int init(int checkbook[], int possible[], int row)
{
	for (int i = 0; i < row; i++)
	{
		checkbook[i] = 0;
		possible[i] = 0;
	}

	return 1;
}

// å ���� �߰��ϱ�(å�� �� ������ 100�� - ������ ����, ���� �̸�, ���ǻ�)
int add_book(char* books[])
{
	char title[30];
	char author[30];
	char publisher[30];

	printf("å ������ �Է����ּ��� : ");
	scanf("%[^\n]s", title);
	getchar();
	printf("\n");
	printf("å ���ڸ� �Է����ּ��� : ");
	scanf("%[^\n]s", author);
	getchar();
	printf("\n");
	printf("å ���ǻ縦 �Է����ּ��� : ");
	scanf("%[^\n]s", publisher);
	getchar();
	printf("\n");


	books[0] = title;
	books[1] = author;
	books[2] = publisher;

	return 1;
}

int find_empty(int checkbook[], int row)
{
	for (int i = 0; i < row; i++)
	{
		if (checkbook[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

// å�� ������ �˻� (���� : ����, ��ȯ: �ε���)
int find_by_title(char* title);
// ������ ����ϴ� �Լ�(����: å �ε���, ��ȯ ����/����)
int print_book(int idx);
// ����, ���ǻ� �˻� ����� �־����
// å�� ������ ���(����: å ����, ��ȯ : ����/����)
int borrow_book();
// å�� �ݳ��ϴ� ���(���� å ����, ��ȯ : ����/����)


int bookmanager()
{
	int cnt = 0;
	int ptr = 0;
	int possible[100];  // 0�� ����, 1�� �������
	int checkbook[100];
	char* books[100][3]; // ����, �����̸�, ���ǻ�

	init(checkbook, possible, sizeof(possible) / sizeof(int));

	while (1)
	{
		int input;
		printf("1: å ���� �߰��ϱ� 0: ���α׷� ����\n");
		printf("���Ͻô� ����� �Է����ּ��� : ");
		scanf("%d", &input); 
		int test = getchar();
		printf("\n");

		if (input == 1)
		{
			if (cnt == 100)
			{
				printf("�� �̻� å�� �߰��� �� �����ϴ�.\n");
				continue;
			}
				
			int result = add_book(books[ptr]);
			if (result)
			{
				cnt++;
				checkbook[ptr] = 1;
				ptr = find_empty(checkbook, sizeof(checkbook) / sizeof(int));
				printf("���� �߰��� �����Ͽ����ϴ�\n");
			}
			else
			{
				printf("���� �߰��� �����Ͽ����ϴ�\n");
			}
		}
		else if (input == 0)
		{
			printf("���α׷��� �����մϴ�\n");
			return 1;
		}

		else
		{
			printf("�ٽ� �Է����ּ���\n");
			continue;
		}
	}
}



int main() {
	
 bookmanager();

	return 0;
}

int str_find(char* str1, char* str2)
{
	int str1_length = str_length(str1);
	int str2_length = str_length(str2);

	for (int i = 0; i < str1_length; i++)
	{
		if (str1[i] == str2[0])
		{
			int find = 1;
			for (int j = 1; j < str2_length; j++)
			{
				if (str1[i + j] != str2[j])
				{
					find = 0;
					break;
				}
			}
			if (find)
				return i;
		}
	}
	return -1;
}

int str_upper_lower_print(char* str)
{
	int ptr = 0;
	while (str[ptr])
	{
		if (str[ptr] < 97) // �빮��
		{
			printf("%c", str[ptr] + 32);
		}
		else // �ҹ���
		{
			printf("%c", str[ptr] - 32);
		}
		ptr++;
	}

	return 1;
}

int str_revere_print(char* str)
{
	int ptr = str_length(str) - 1;
	while (ptr != -1)
	{
		printf("%c", str[ptr--]);
	}
	printf("\n");
	return 1;
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