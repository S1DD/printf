#include "main.h"

/**
 * handle_char - Handles the '%c' format specifier for characters.
 * @args: Argument list containing the character to print.
 * Return: Always returns 1 as it prints a single character.
 */
int handle_char(va_list args)
{
    char ch = (char) va_arg(args, int);
    put_char(ch);
    return (1);
}

