#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "human.h"
#include "str.h"
#include <string.h>
#include <errno.h>

int main()
{
	// chapter 23-1
	// �����غ��� ����1
	// ��� �Է¹ޱ�
    
    char filepath[50];

    printf("������ ��ο� �����̸��� �Է��ϼ���: ");
    scanf("%s", filepath);

    FILE* fp = fopen(filepath, "w");

    if (fp == NULL) {
        printf("��� ���� �߻� : %d\n", errno);
        return 0;
    }
    fputs("test!! \n", fp);
    printf("���� ���� �Ϸ�\n");

    fclose(fp);
    
	return 0;
}