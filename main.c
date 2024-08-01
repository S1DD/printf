#include <stdio.h>
#include "main.h"

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", 1234);
    _printf("Signed Integer: %i\n", -5678);
    return 0;
}
