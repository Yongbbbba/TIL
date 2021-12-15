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
// 문자열 역순 출력
int str_revere_print(char* str);
// 소문자 -> 대문자, 대문자 -> 소문자 출력
int str_upper_lower_print(char* str);
int str_find(char* str1, char* str2);

// 도서 관리 프로그램
int init(int checkbook[], int possible[], int row)
{
	for (int i = 0; i < row; i++)
	{
		checkbook[i] = 0;
		possible[i] = 0;
	}

	return 1;
}

// 책 새로 추가하기(책의 총 개수는 100권 - 정보는 제목, 저자 이름, 출판사)
int add_book(char* books[])
{
	char title[30];
	char author[30];
	char publisher[30];

	printf("책 제목을 입력해주세요 : ");
	scanf("%[^\n]s", title);
	getchar();
	printf("\n");
	printf("책 저자를 입력해주세요 : ");
	scanf("%[^\n]s", author);
	getchar();
	printf("\n");
	printf("책 출판사를 입력해주세요 : ");
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

// 책의 제목을 검색 (인자 : 제목, 반환: 인덱스)
int find_by_title(char* title);
// 정보를 출력하는 함수(인자: 책 인덱스, 반환 성공/실패)
int print_book(int idx);
// 저자, 출판사 검색 기능이 있어야함
// 책을 빌리는 기능(인자: 책 제목, 반환 : 성공/실패)
int borrow_book();
// 책을 반납하는 기능(인자 책 제목, 반환 : 성공/실패)


int bookmanager()
{
	int cnt = 0;
	int ptr = 0;
	int possible[100];  // 0은 소장, 1은 대출상태
	int checkbook[100];
	char* books[100][3]; // 제목, 저자이름, 출판사

	init(checkbook, possible, sizeof(possible) / sizeof(int));

	while (1)
	{
		int input;
		printf("1: 책 새로 추가하기 0: 프로그램 종료\n");
		printf("원하시는 기능을 입력해주세요 : ");
		scanf("%d", &input); 
		int test = getchar();
		printf("\n");

		if (input == 1)
		{
			if (cnt == 100)
			{
				printf("더 이상 책을 추가할 수 없습니다.\n");
				continue;
			}
				
			int result = add_book(books[ptr]);
			if (result)
			{
				cnt++;
				checkbook[ptr] = 1;
				ptr = find_empty(checkbook, sizeof(checkbook) / sizeof(int));
				printf("도서 추가가 성공하였습니다\n");
			}
			else
			{
				printf("도서 추가가 실패하였습니다\n");
			}
		}
		else if (input == 0)
		{
			printf("프로그램을 종료합니다\n");
			return 1;
		}

		else
		{
			printf("다시 입력해주세요\n");
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
		if (str[ptr] < 97) // 대문자
		{
			printf("%c", str[ptr] + 32);
		}
		else // 소문자
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