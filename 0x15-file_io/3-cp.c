#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * exit_with_error - Prints an error message and exits with the specified code.
 * @code: The exit code.
 * @message: The error message format string.
 * @arg: The argument for the format string.
 */
void exit_with_error(int code, const char *message, int arg)
{
dprintf(2, message, arg);
exit(code);
}

/**
 * main - Entry point for the cp program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char **argv)
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

if (argc != 3)
exit_with_error(97, "Usage: %s file_from file_to\n", 97);

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
exit_with_error(98, "Error: Can't read from file %s\n", 98);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
exit_with_error(99, "Error: Can't write to file %s\n", 99);

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written != bytes_read || bytes_written == -1)
exit_with_error(99, "Error: Can't write to file %s\n", 99);
}

if (bytes_read == -1)
exit_with_error(98, "Error: Can't read from file %s\n", 98);

if (close(fd_from) == -1)
exit_with_error(100, "Error: Can't close fd %d\n", 100);

if (close(fd_to) == -1)
exit_with_error(100, "Error: Can't close fd %d\n", 100);

return (0);
}
