#include "main.h"

int handlePercentSpecifier(char buffer[], int *buffer_idx);
int handleCharSpecifier(va_list args, char buffer[], int *buffer_idx);
int handleIntSpecifier(va_list args, char buffer[], int *buffer_idx);
int handleStrSpecifier(const char *str, char buffer[], int *buffer_idx);
int handleUnknownSpecifier(const char **format,
                char buffer[], int *buffer_idx);

/**
 * handlePercentSpecifier - Handles the '%%' format specifier.
 *
 * @buffer: The buffer where output characters are stored.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int handlePercentSpecifier(char buffer[], int *buffer_idx)
{
        return (printChar('%', buffer, buffer_idx));
}

/**
 * handleCharSpecifier - Handles the '%c' format specifier.
 *
 * @args: The variable argument list.
 * @buffer: The buffer where output characters are stored.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int handleCharSpecifier(va_list args, char buffer[], int *buffer_idx)
{
        char c = (char) va_arg(args, int);

        return (printChar(c, buffer, buffer_idx));
}
/**
 * handleIntSpecifier - Handles the '%d' and '%i' format specifiers.
 * @args: The variable argument list.
 * @buffer: The buffer where output characters are stored.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int handleIntSpecifier(va_list args, char buffer[], int *buffer_idx)
{
        int num = va_arg(args, int);

        return (printInt(num, buffer, buffer_idx));
}
/**
 * handleStrFormat - Processes and prints a string argument.
 * @str: The string to be printed. If NULL, "(null)" is printed instead.
 * @buffer: The buffer where the output characters are stored.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 * Return: The number of characters printed to the buffer.
 */
int handleStrFormat(const char *str, char buffer[], int *buffer_idx)
{
        int count = 0;

        if (str == NULL)
                str = "(null)";

        while (*str)
        {
                count += printChar(*str++, buffer, buffer_idx);
        }

        return (count);
}
/**
 * handleUnknownSpecifier - Handles unknown format specifiers by printing
 * an error message.
 * @format: Pointer to the current position in the format string.
 * @buffer: A character buffer where the formatted output will be written.
 * @buffer_idx: A pointer to an integer that keeps
 * track of the current index in the buffer.
 *
 * Return: The total number of characters written to the buffer.
 */
int handleUnknownSpecifier(const char **format, char buffer[], int *buffer_idx)
{
        int count = 0;

        const char *error_msg = "Unknown format specifier";

        while (*error_msg)
        {
                count += printChar(*error_msg++, buffer, buffer_idx);
        }
        count += printChar('%', buffer, buffer_idx);
        count += printChar(**format, buffer, buffer_idx);
        return (count);
}

