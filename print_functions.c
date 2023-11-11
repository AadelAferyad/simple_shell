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
	if (n / 10) /*103 10 1  = 103*/
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

int berror(int count, char *buffer, char *av)
{
	char *tmp = skip_space_tab_for_berror(buffer);

	if (!tmp)
		return (1);
	_puts(av);
	_puts(": ");
	print_int(count);
	_puts(": ");
	_puts(tmp);
	_puts(": not found\n");
	/*write(0, "\n", 1);*/
	free(tmp);
	return (0);
}
