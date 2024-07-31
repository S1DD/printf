#include "main.h"

int processFormatSpecifier(const char **format, va_list args,
		char buffer[], int *buffer_idx);
/**
 * processFormatSpecifier - Process format specifiers following a '%'
 * @format: Pointer to the current position in the format string.
 * @args: The variable argument list.
 * @buffer: The buffer where output characters are stored.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 * Return: The total number of characters writtent to the buffer
 */
int processFormatSpecifier(const char **format, va_list args,
		char buffer[], int *buffer_idx)
{
	int count = 0;

	(*format)++;
	switch (**format)
	{
		case '%':
			count += handlePercentSpecifier(buffer, buffer_idx);
			(*format)++;
			break;
		case 'c':
		{
			count += handleCharSpecifier(args, buffer, buffer_idx);
			break;
		}
		case 'd':
		case 'i':
		{
			count += handleIntSpecifier(args, buffer, buffer_idx);
			break;
		case 's':
		{
			count += handleStrFormat(va_arg(args, const char *), buffer, buffer_idx);
			break;
		}
		default:
			count += handleUnknownSpecifier(format, buffer, buffer_idx);
			break;
		}
	}
	return (count);
}
