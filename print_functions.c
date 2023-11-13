#include "main.h"
/**
 * print_int - Print an unsigned integer.
 * @n: The unsigned integer to print.
 */
void print_int(unsigned int n)
{
	if (n / 10) /*103 10 1  = 103*/
		print_int(n / 10);
	_putchar((n % 10) + 48);
}
/**
 * _putchar - prints the character c
 * @c: char
 * Return: if success 1
 */
void _putchar(char c)
{
	write(2, &c, 1);
}
/**
 * _puts - print a string
 * @str: pointer to char
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
}
/**
 * berror - Print an error message for command not found.
 * @count: The line number or count where the error occurred.
 * @buffer: The command or buffer that resulted in the error.
 * @av: The program name or argv[0].
 * Return: 0 on success, 1 on failure.
 */
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
