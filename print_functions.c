#include "main.h"


int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

void print_int(unsigned int n)
{
    if (n / 10)/*103 10 1  = 103*/
        print_int(n / 10);
    _putchar((n % 10) + 48);
}

void _putchar(char c)
{
    write(2, &c, 1);
}
/*BE AWARE CHANGED STDOUT TO STDERR*/
void _puts(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        _putchar(str[i]);
}

void berror(int count, char *buffer)
{
	char *tmp = skip_space_tab_for_berror(buffer);

	if (!tmp)
		return;
	_puts("#cisfun$: ");
	print_int(count);
	_puts(": ");
	_puts(tmp);
	_puts(": not found\n");
	free(tmp);
}
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