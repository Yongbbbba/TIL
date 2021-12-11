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

int main() {
	// 문제3
	int result = fact(5);
	

	return 0;
}