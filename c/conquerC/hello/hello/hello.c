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
	// 생각해보기 문제1
	// 경로 입력받기
    
    char filepath[50];

    printf("저장할 경로와 파일이름을 입력하세요: ");
    scanf("%s", filepath);

    FILE* fp = fopen(filepath, "w");

    if (fp == NULL) {
        printf("출력 오류 발생 : %d\n", errno);
        return 0;
    }
    fputs("test!! \n", fp);
    printf("파일 생성 완료\n");

    fclose(fp);
    
	return 0;
}