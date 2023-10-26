#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to the binary string (0 and 1 chars).
 *
 * Return: The converted unsigned int, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;

if (b == NULL)
return (0);

while (*b)
{
if (*b == '0' || *b == '1')
{
result = result * 2 + (*b - '0');
b++;
}
else
{
return (0);
}
}

return (result);
}
