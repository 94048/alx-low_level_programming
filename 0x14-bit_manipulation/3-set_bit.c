#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long int where the bit will be set.
 * @index: The index of the bit to set (0-based).
 *
 * Return: 1 if the bit was set successfully, or -1 if an error occurs.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n | (1UL << index);
	return (1);
}
