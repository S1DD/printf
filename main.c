// main.c
#include <stdio.h>
#include "main.h"  // Make sure this file declares your _printf function

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", 1234);
    _printf("Signed Integer: %i\n", -5678);
    return 0;
}
