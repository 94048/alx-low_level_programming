#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written = 0;
	mode_t file_permissions = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename,
	O_WRONLY | O_CREAT | O_TRUNC,
	file_permissions);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[bytes_written] != '\0')
			bytes_written += write(file_descriptor, &text_content[bytes_written], 1);
	}

	if (close(file_descriptor) == -1)
		return (-1);

	return (1);
}
