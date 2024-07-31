#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct fmt_spec - Structure to map format specifiers to their handler functions.
 * @specifier: Format specifier string.
 * @handler: Function pointer to the handler for the format specifier.
 *
 * This structure is used to associate format specifiers with their respective
 * handling functions in the custom printf implementation.
 */
typedef struct fmt_spec
{
    char *specifier;
    int (*handler)(va_list args);
} fmt_spec;

/* Function prototypes for format specifier handlers */
int handle_pointer(va_list args);
int handle_hex_aux(unsigned long int num);
int handle_HEX_aux(unsigned int num);
int handle_exclusive_string(va_list args);
int handle_HEX(va_list args);
int handle_hex(va_list args);
int handle_oct(va_list args);
int handle_unsigned(va_list args);
int handle_bin(va_list args);
int handle_reverse(va_list args);
int handle_rot13(va_list args);
int handle_int(va_list args);
int handle_decimal(va_list args);

/* Utility function prototypes */
int str_length(char *s);
char *str_copy(char *dest, const char *src);
int str_length_const(const char *s);
void reverse_string(char *s);
int print_percent(void);
int handle_char(va_list args);
int handle_string(va_list args);
int put_char(char c);
int custom_printf(const char *format, ...);

#endif /* MAIN_H */
