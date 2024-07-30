#include "main.h"

/**
 * _printf - Outputs a formatted string
 * @format: Character string to print
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[BUFSIZE];
	int buffer_idx = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == SPECIFIER)
		{
			if (buffer_idx > 0)
			{
				flushBuffer(buffer, &buffer_idx);
				count += buffer_idx;
			}
			format++;
			count += handleFormat(&format, args, buffer, &buffer_idx);
		}
		else
		{
			count += printChar(*format, buffer, &buffer_idx);
		}
		format++;

		if (buffer_idx > 0)
		{
			flushBuffer(buffer, &buffer_idx);
			count += buffer_idx;
		}

		va_end(args);
		return (count);
