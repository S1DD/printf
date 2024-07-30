#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Outputs formatted string
 * @format: Character string to print
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    const char specifier = '%';
    va_list args;
    int count = 0, buffer_index = 0;
    char buffer[BUFSIZE];
    int flags, width, precision, size;

    if (!format)
        return (-1);

    va_start(args, format);
    while (*format != '\0')
    {
        if (*format == specifier)
        {
            flush_buffer(buffer, &buffer_index);
            format++; 
            flags = parse_format_flags(format, &format);
            width = extract_width(format, &format, args);
            precision = extract_precision(format, &format, args);
            size = determine_size(format, &format);

            if (*format == 'c')
            {
                count += render_char(args, buffer, flags, width, precision, size);
            }
            else if (*format == 's')
            {
                count += render_string(args, buffer, flags, width, precision, size);
            }
            else if (*format == 'd' || *format == 'i')
            {
                count += convertToInt(args, buffer, flags, width, precision, size);
            }
            else if (*format == '%')
            {
                count += render_percent(args, buffer, flags, width, precision, size);
            }
            else
            {
                
                printStr("Error. The format specifier is not recognized.");
                return (-1);
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
            if (buffer_index == BUFSIZE)
                flush_buffer(buffer, &buffer_index);
            count++;
        }
        format++;
    }
    flush_buffer(buffer, &buffer_index);
    va_end(args);
    return (count);
}

/**
 * printStr - Outputs a string to stdout
 * @s: String to print
 *
 * Return: The number of characters printed
 */
int printStr(char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        putchar(*s);
        s++;
        count++;
    }
    return (count);
}

/**
 * flush_buffer - Flushes the buffer to stdout
 * @buffer: The buffer to flush
 * @buffer_index: The current index in the buffer
 */
void flush_buffer(char buffer[], int *buffer_index)
{
    if (*buffer_index > 0)
        write(1, &buffer[0], *buffer_index);
    *buffer_index = 0;
}

/**
 * printInt - Outputs an integer to stdout
 * @a: Integer to print
 *
 * Return: The number of characters printed
 */
int printInt(int a)
{
    char str[12]; // Enough to hold INT_MIN and INT_MAX
    int i = 0, is_negative = 0, count = 0;

    if (a == 0)
    {
        putchar('0');
        return (1);
    }

    if (a < 0)
    {
        is_negative = 1;
        a = -a;
    }

    while (a > 0)
    {
        str[i++] = (a % 10) + '0';
        a /= 10;
    }

    if (is_negative)
    {
        str[i++] = '-';
    }

    while (i--)
    {
        putchar(str[i]);
        count++;
    }

    return (count);
}
