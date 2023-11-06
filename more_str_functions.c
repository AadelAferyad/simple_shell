#include "main.h"


int _strcmp(char *src, char *dest)/* "exit" exit*/
{
	int i = 0;

	for (; src[i] && dest[i]; i++)
	{
		if (src[i] != dest[i])
			return (0);
	}
	return ((src[i] == dest[i]) ? 1 : 0);
}

