#include "main.h"

/**
 * print_hex_aux - Prints a hexadecimal number in lowercase.
 * @num: Number to print.
 * Return: The number of characters printed.
 */
int print_hex_aux(unsigned int num)
{
    char hex_chars[] = "0123456789abcdef";
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

