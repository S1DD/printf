#include "main.h"

/* Function prototypes */
void flush_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom implementation of printf function.
 * @format: Format string specifying the desired output.
 * Return: The number of characters printed.
 */
int _printf(const char * const format, ...)
{
    int i, total_chars = 0, flags, width, precision, size, buff_ind = 0;
    va_list args;
    char buffer[BUFF_SIZE];

    /* Format specifiers and their associated functions */
    format_match specs[] = {
        {"%s", pf_handle_string}, {"%c", pf_handle_char},
        {"%%", pf_handle_percent},
        {"%i", pf_handle_int}, {"%d", pf_handle_dec}, {"%r", pf_handle_rev},
        {"%R", pf_handle_rot13}, {"%b", pf_handle_bin}, {"%u", pf_handle_unsigned},
        {"%o", pf_handle_oct}, {"%x", pf_handle_hex}, {"%X", pf_handle_HEX},
        {"%S", pf_handle_exclusive_string}, {"%p", pf_handle_pointer}
    };

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    {
        va_end(args);
        return (-1);
    }

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                flush_buffer(buffer, &buff_ind);
            total_chars++;
        }
        else
        {
            flush_buffer(buffer, &buff_ind);
            flags = parse_flags(format, &i);
            width = parse_width(format, &i, args);
            precision = parse_precision(format, &i, args);
            size = parse_size(format, &i);
            i++;
            int printed = process_format(format, &i, args, buffer,
                flags, width, precision, size);
            if (printed == -1)
            {
                va_end(args);
                return (-1);
            }
            total_chars += printed;
        }
    }

    flush_buffer(buffer, &buff_ind);

    va_end(args);

    return (total_chars);
}

/**
 * flush_buffer - Outputs the contents of the buffer if necessary.
 * @buffer: Array of characters to be written.
 * @buff_ind: Index indicating where to write next, represents buffer length.
 */
void flush_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);

    *buff_ind = 0;
}
