#include "main.h"

/* Declare the _putchar function */
int _putchar(char c);

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long int to be printed.
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
