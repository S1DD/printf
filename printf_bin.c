#include "main.h"

/**
 * handle_bin - Handles the '%b' format specifier for binary numbers.
 * @args: Argument list containing the number to print.
 * Return: The number of characters printed.
 */
int handle_bin(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int bit_set = 0, count = 0;

    for (int i = 31; i >= 0; i--)
    {
        if (num & (1 << i))
            bit_set = 1;

        if (bit_set)
        {
            put_char((num & (1 << i)) ? '1' : '0');
            count++;
        }
    }

    if (count == 0)
    {
        put_char('0');
        count = 1;
    }

    return (count);
}

