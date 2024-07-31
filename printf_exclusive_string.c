#include "main.h"

/**
 * handle_exclusive_string - Handles the '%S' format specifier for strings with special character encoding.
 * @args: Argument list containing the string to print.
 * Return: The total number of characters printed.
 */
int handle_exclusive_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (str == NULL)
        str = "(null)";

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            put_char('\\');
            put_char('x');
            len += 2;

            if (str[i] < 16)
            {
                put_char('0');
                len++;
            }

            len += print_hex_aux((unsigned int) str[i]);
        }
        else
        {
            put_char(str[i]);
            len++;
        }
    }

    return (len);
}

