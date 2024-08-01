#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Function to print a number */
static void print_number(int n, int *count)
{
    char buffer[12];
    int i = 0;
    int j;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        (*count)++;
    }
    do
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
        (*count)++;
    }
}

/* Function to print a string */
static void print_string(const char *str, int *count)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
        (*count)++;
    }
}

/* Function to print a character */
static void print_char(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    print_char(va_arg(args, int), &count);
                    break;
                case 's':
                    print_string(va_arg(args, char *), &count);
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                case 'd':
                case 'i':
                    print_number(va_arg(args, int), &count);
                    break;
                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
