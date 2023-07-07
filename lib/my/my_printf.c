/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** mini printf
*/
#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int modulob(const char *format, int *i, va_list list, int status)
{
    int valeur;

    valeur = 0;
    if (format[*i + 1] == '%') {
        valeur ++;
        my_putchar('%');
    }
    switch (format[*i + 1]) {
    case 's': valeur += my_putstr(va_arg(list, char*), 0); break;
    case 'b': valeur += my_putnbr_base(va_arg(list, int), "01"); break;
    case 'o': valeur += my_putnbr_base(va_arg(list, int), "01234567"); break;
    case 'u': valeur += my_putnbr_base(va_arg(list, int), "0123456789"); break;
    case 'x': valeur += my_putnbr_base(va_arg(list, int), "0123456789abcdef");
        break;
    case 'X': valeur += my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
        break;
    default: break;
    }
    return (valeur);
}

int modulo(const char *format, int *i, va_list list, int status)
{
    int valeur;
    int nb;
    char tab[11];

    valeur = 0;
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i') {
        nb = va_arg(list, int);
        my_getstr(nb, tab);
        if (status == 5 || nb < 0) {
            my_putstr(tab, 0);
        } else {
            my_putstr(tab, 1);
        }
    }
    if (format[*i + 1] == 'c') {
        valeur ++;
        my_putchar(va_arg(list, int));
    }
    valeur += modulob(format, i, list, status);
    return (valeur);
}

int flag(const char *format, int *i, va_list list)
{
    int valeur;
    int status;

    switch (format[*i + 1]) {
    case '#' : status = 1; break;
    case '0' : status = 2; break;
    case '-' : status = 3; break;
    case ' ' : status = 4; break;
    case '+' : status = 5; break;
    case '\'' : status = 6; break;
    case 'I' : status = 7; break;
    default: status = 0; break;
    }
    if (status != 0)
        *i += 1;
    valeur = modulo(format, i, list, status);
    return (valeur);
}

int my_printf(const char *format, ...)
{
    int valeur = 0;
    va_list list;
    int i = 0;
    int *ptr;
    ptr = &i;

    va_start(list, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            valeur += flag(format, ptr, list);
            i ++;
        } else {
            my_putchar(format[i]);
            valeur ++;
        }
    }
    if (valeur == 0)
        return (-1);
    va_end(list);
    return (valeur);
}
