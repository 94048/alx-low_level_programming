#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * exit_with_error - Prints an error message to stderr and exits.
 * @code: The exit code.
 * @message: The error message.
 */
void exit_with_error(int code, const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(code);
}

/**
 * display_elf_header_info - Displays information from the ELF header.
 * @header: A pointer to the ELF header structure.
 */
void display_elf_header_info(Elf64_Ehdr *header)
{
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", header->e_ident[i]);
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("  Class:                             %s\n",
(header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
printf("  Data:                              %s\n",
(header->e_ident[EI_DATA] == ELFDATA2LSB) ?
"2's complement, little endian" : "Unknown");
printf("  Version: %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("Linux\n");
break;
default:
printf("Other\n");
}
printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                              ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (Unknown type)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("Other\n");
}
printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Entry point for the ELF header information display program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
exit_with_error(98, "Usage: elf_header elf_filename");
}

int fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
exit_with_error(98, "Error: Cannot open file");
}

Elf64_Ehdr elf_header;
if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
{
exit_with_error(98, "Error: Cannot read ELF header");
}


if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
{
exit_with_error(98, "Error: Not an ELF file");
}

display_elf_header_info(&elf_header);

close(fd);
return (0);
}
