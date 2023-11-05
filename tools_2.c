#include "main.h"

void print_int(unsigned int n)
{
    if (n / 10)/*103 10 1  = 103*/
        print_int(n / 10);
    _putchar((n % 10) + 48);
}

void _putchar(char c)
{
    write(1, &c, 1);
}

void _puts(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        _putchar(str[i]);
}


void berror(int count, char *buffer)
{
    _puts("#cisfun$: ");
    print_int(count);
    _puts(": ");
    _puts(buffer);
    _puts(": not found\n");
}