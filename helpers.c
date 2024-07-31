#include "main.h"

/**
 * flushBuffer - Flushes the buffer to stdout.
 * @buffer: The buffer containing data to flush.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 */
void flushBuffer(char buffer[], int *buffer_idx)
{
	if (*buffer_idx > 0)
	{
		write(1, buffer, *buffer_idx);
		*buffer_idx = 0;
	}
}

/**
 * handleFormat - Handles a format specifier and it's argument.
 * @format: Pointer to the current position in the format string.
 * @args: The variable argument list.
 * @buffer: The buffer where formatted data is stored.
 * @buffer_idx: Pointer to the current index in the buffer.
 *
 * Return: The number of characters printed to the buffer.
 */
int handleFormat(const char **format, va_list args,
		char buffer[], int *buffer_idx)
{
	int count = 0;

	if (**format == '%')
	{
		count += processFormatSpecifier(format, args, buffer, buffer_idx);
	}
	else
	{
		printChar(**format, buffer, buffer_idx);
		count += 1;
		(*format)++;
	}

	return (count);
}
/**
* printChar - Adds a single character to the buffer.
* @c: The character to print.
* @buffer: The buffer where the character will be stored.
* @buffer_idx: Pointer to the current index in the buffer.
*
* Return: The number of characters added to the buffer (always 1).
*/
int printChar(char c, char buffer[], int *buffer_idx)
{
	if (*buffer_idx >= BUFSIZE)
	{
		flushBuffer(buffer, buffer_idx);
	}

	buffer[*buffer_idx] = c;
	(*buffer_idx)++;
	return (1);
}
/**
* printInt - Adds an integer to the buffer.
* @num: The integer to print.
* @buffer: The buffer where the integer will be stored.
* @buffer_idx: Pointer to the current index in the buffer.
*
* Return: The number of characters added to the buffer.
*/
int printInt(int num, char buffer[], int *buffer_idx)
{
	char str[12];
	int i = 0, isNegative = 0, count = 0;

	if (num == 0)
	{
		count += printChar('0', buffer, buffer_idx);
		return (count);
	}

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}

	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (isNegative)
	{
		str[i++] = '-';
	}

	while (i--)
	{
		count += printChar(str[i], buffer, buffer_idx);
	}

	return (count);
}
