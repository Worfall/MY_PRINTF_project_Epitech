/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** it's my_putnbr version base
*/
int my_strlen(char const *str);
void my_putchar(char c);

int power(int nbr, int len_base, int i)
{
    i = len_base;
    if ((nbr / i) >= 1) {
        while ((nbr / i) >= 1)
            i = i * len_base;
        i = i / len_base;
    }
    return (i);
}

int condition(int nbr, int i, int len_base, char const *base)
{
    int valeur;

    valeur = 0;
    while (i != 1) {
        if (nbr / i < 1) {
            my_putchar(base[0]);
        } else {
            my_putchar(base[nbr / i]);
            nbr = nbr - (i * (nbr / i));
        }
        valeur ++;
        i = i / len_base;
    }
    my_putchar(base[nbr]);
    return (valeur);
}

int my_putnbr_base(int nbr, char const *base)
{
    int len_base;
    int i = 0;
    int valeur = 0;

    len_base = my_strlen(base);
    if (nbr < 0 || len_base == 1)
        return (-1);
    i = power(nbr, len_base, i);
    if (nbr == len_base) {
        my_putchar(base[1]);
        my_putchar(base[0]);
        valeur = 2;
    } else if (nbr > len_base) {
        valeur = condition(nbr, i, len_base, base);
    } else {
        my_putchar(base[nbr]);
        valeur = 1;
    }
    return (valeur);
}
