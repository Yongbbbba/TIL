#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "human.h"
#include "str.h"
#include <string.h>
#include <errno.h>

bool findString(char* input, char* target)
{
    int input_len = strlen(input);
    int target_len = strlen(target);

    for (int i = 0; i < input_len; i++)
    {
        if (target[0] == input[i])
        {
            int result = 1;
            for (int j = 1; j < target_len; j++)
            {
                if (target[j] != input[i + j])
                {
                    result = 0;
                    break;
                }
            }
            if (result)
                return true;
        }
    }
    return false;
}

int main()
{
	// chapter 23-1
	// 생각해보기 문제1
	// 경로 입력받기
    
    char* filepath = "a.txt";

    FILE* fp = fopen(filepath, "r");

    if (fp == NULL) {
        printf("입력 오류 발생 : %d\n", errno);
        return 0;
    }
    
    char buf[100];
    fgets(buf, 100, fp);

    char* ptr = buf;
    
    fp = fopen("b.txt", "w");

    while (*ptr)
    {
        fputc(*ptr, fp);
        ptr++;
    }
    *ptr = '\0';
    

    fclose(fp);
    
	return 0;
}