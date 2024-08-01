#include "main.h"
#include <unistd.h>

/**
 * print_char - outputs a single character to stdout.
 * @ch: The character to output.
 *
 * Return: On success, returns 1.
 * On failure, returns -1 and sets errno.
 */
int print_char(char ch)
{
    ssize_t result = write(STDOUT_FILENO, &ch, 1);

    if (result == -1)
        return -1;
    return (int)result;
}
