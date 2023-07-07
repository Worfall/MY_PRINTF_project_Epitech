/*
** EPITECH PROJECT, 2022
** my_getstr.c
** File description:
** int to str
*/
void my_getstr(int nb, char *tab)
{
    int i;
    int quot = 1000000000;

    i = 1;
    if (nb < 0) {
        tab[0] = '-';
    } else {
        tab[0] = '+';
    }
    for (int digit = 0; digit == 0;) {
        digit = (nb / quot) % 10;
        quot = quot / 10;
    }
    quot = quot * 10;
    tab[i++] = ((nb / quot) % 10) + 48;
    for (; quot != 1; i ++) {
        quot = quot / 10;
        tab[i] = 48 + ((nb / quot) % 10);
    }
    tab[i] = '\0';
}
