#include "main.h"

/**
 * clear_bit - Clears the value of a bit to 0 at a given index.
 * @n: Pointer to the unsigned long int where the bit will be cleared.
 * @index: The index of the bit to clear (0-based).
 *
 * Return: 1 if the bit was cleared successfully, or -1 if an error occurs.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n & ~(1UL << index);
	return (1);
}
