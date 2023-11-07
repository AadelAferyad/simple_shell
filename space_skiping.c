#include "main.h"


char *skip_space_tab_for_berror(char *buffer)
{
	int i = 0, count = 0, is = -1, j, k = 0;
	char *temp = NULL;

	for (; buffer[i]; i++)/*"   d          d   "*/
	{
		if (buffer[i] != 32 && buffer[i] != 9)
		{
			if (is < 0)
				is = i;
			count++; 
		}
		else if (is > 0 || is == 0)
			break;
	}
	if (count == 0)
		return (NULL);
	temp = malloc(count + 1);
	if (!temp)
		return (NULL);
	j = is;
	while (k < count)
	{
		temp[k] = buffer[j];
		j++;
		k++;
	}
	temp[k] = '\0';
	return (temp);
}