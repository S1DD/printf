#include "main.h"

/**
 * handle_HEX - Handles the '%X' format specifier for hexadecimal numbers.
 * @args: Argument list containing the number to print.
 * Return: The number of characters printed.
 */
int handle_HEX(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char hex_chars[] = "0123456789ABCDEF";
    char buffer[32];
    int index = 0;

    if (num == 0)
    {
        put_char('0');
        return (1);
    }

    while (num > 0)
    {
        buffer[index++] = hex_chars[num % 16];
        num /= 16;
    }

    for (int i = index - 1; i >= 0; i--)
        put_char(buffer[i]);

    return (index);
}
