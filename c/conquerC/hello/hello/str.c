// str.c 
#include "str.h"

char copy_str(char* dest, char* src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return 1;
}