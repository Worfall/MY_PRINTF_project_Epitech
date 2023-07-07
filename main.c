#include <stdio.h>

int my_printf(const char *format, ...);
void my_getstr(int nb, char *tb);

int main(void)
{
    my_printf("%+d", 69);
}
