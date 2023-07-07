/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** Write he characters of a string
*/
void my_putchar(char c);

int my_putstr(char const *str, int i)
{
    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return i;
}
