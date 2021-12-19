#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "human.h"
#include "str.h"

int main()
{
	struct Human Lee = Create_Human("¿Ã»£ºÆ", 23, MALE);
	
	Print_Human(&Lee);

	return 1;
}