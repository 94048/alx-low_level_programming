#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void exit_with_error(int code, const char *message);
void display_magic(unsigned char *ident);
void display_class(unsigned char class);
void display_data(unsigned char data);
void display_version(unsigned char version);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_elf_header_info(const char *filename);

#endif /* MAIN_H */