#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>

int read_char(void* p, int byte);
int atoi(char* input)
{

    int result = 0;
    while (*input)
    {
        result = result * 10 + (*input - '0');
        input++;
    }

    return result;
}

int main(int argc, char** argv) {
    printf("���� ������ ���� : %d \n", argc);
    printf("�� ���α׷��� ��� : %s \n", argv[0]);
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    int result;
    char oper = argv[2][0];
    if (oper == '+') 
    {
        result = num1 + num2;
    }
    else if (oper == '-')
    {
        result = num1 - num2;
    }
    else if (oper == '*')
    {
        result = num1 * num2;
    }
    else
    {
        result = num1 / num2;
    }

    printf("����� : %d\n", result);

    return 0;
}

int read_char(void* p, int byte) {
    do {
        printf("%x \n", *(char*)p);
        byte--;

        p = (char*)p + 1;  // 1byte��ŭ �ּ� �̵�
    } while (p && byte);

    return 0;
}
