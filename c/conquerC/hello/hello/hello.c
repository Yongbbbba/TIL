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
	// ����2
	int a = 136, b = 736;
	while (a)
	{
		int temp = b % a; 
		b = a;
		a = temp;
	}
	

	return 0;
}