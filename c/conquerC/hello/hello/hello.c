#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 배열 swap
void arr_swap(int* a, int* b);
// factorial
int fact(int num);
// calculator
int cal();
// 문자열 내의 총 문자의 수를 세는 함수
int str_length(char* str);
// 문자열을 복사하는 함수
char* str_copy(char* str1, char* str2);
// 문자열을 합치는 함수
char* str_append(char* str1, char* str2);
// 문자열을 비교하는 함수
bool str_compare(char* str1, char* str2);

int main() {
	char str[20] = "hello every1";
	char str2[20] = "hello everyone";
	char str3[20] = "hello every1 hi";
	char str4[20] = "hello every1";

	if (str_compare(str, str2)) {
		printf("%s 와 %s 는 같다 \n", str, str2);
	}
	else {
		printf("%s 와 %s 는 다르다 \n", str, str2);
	}

	if (str_compare(str, str3)) {
		printf("%s 와 %s 는 같다 \n", str, str3);
	}
	else {
		printf("%s 와 %s 는 다르다 \n", str, str3);
	}

	if (str_compare(str, str4)) {
		printf("%s 와 %s 는 같다 \n", str, str4);
	}
	else {
		printf("%s 와 %s 는 다르다 \n", str, str4);
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
	// str1에 str2 복사하기
	// str1의 길이가 str2의 길이보다 크거나 같아야함
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
	// str1와 str2의 길이를 합한 값이 str1 배열의 크기보다 작야아함
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