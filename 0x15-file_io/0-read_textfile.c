#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Read a text file print the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 * Return: The actual number of letters it could read and print,
 * or 0 if the file can't be opened or read, filename is NULL, or write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor;
ssize_t bytes_read, bytes_written;
char *buffer;

if (filename == NULL)
return (0);

/* Open the file for reading */
file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
return (0);

/* Allocate memory for the buffer */
buffer = malloc(letters);
if (buffer == NULL)
{
close(file_descriptor);
return (0);
}

/* Read from the file */
bytes_read = read(file_descriptor, buffer, letters);
if (bytes_read == -1)
{
free(buffer);
close(file_descriptor);
return (0);
}

/* Write to stdout */
bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

/* Clean up and return the actual number of letters read */
free(buffer);
close(file_descriptor);

if (bytes_read != bytes_written)
return (0);

return (bytes_written);
}
