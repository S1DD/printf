#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int printChar(char c, char buffer[], int *buffer_idx);
int printInt(int num, char buffer[], int *buffer_idx);
void flushBuffer(char buffer[], int *buffer_idx);
int handleFormat(const char **format, va_list args, char buffer[], int *buffer_idx);

#define BUFSIZE 1024
#define SPECIFIER '%'

#endif /* MAIN_H */
