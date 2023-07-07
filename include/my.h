/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Write your my.h header file that contains the prototypes
** of all the functions exposed
*/
#ifndef MY_H_
    #define MY_H_
    void my_putchar(char c);
    int my_put_nbr(int nb);
    int positive(int nb);
    int negative(int nb);
    int condition(int nbr, int i, int len_base, char const *base);
    int power(int nbr, int len_base, int i);
    int my_putnbr_base(int nbr, char const *base);
    int my_putstr(char const *str, int i);
    int my_strlen(char const *str);
    int modulob(const char *format, int *i, va_list list, int status);
    int modulo(const char *format, int *i, va_list list, int status);
    int flag(const char *format, int *i, va_list list);
    int my_printf(const char *format, ...);
    int my_getstr(int nb, char *tab);
#endif /* MY_H_ */
