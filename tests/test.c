/*
** EPITECH PROJECT, 2022
** test.c
** File description:
** test_unitaire printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(const char *format, ...);

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, modulo_s, .init = redirect_all_std)
{
    my_printf("hello %s","world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, modulo_c, .init = redirect_all_std)
{
    my_printf("hello %c", 'B');
    cr_assert_stdout_eq_str("hello B");
}

Test(my_printf, modulo_d, .init = redirect_all_std)
{
    my_printf("hello %d", 12);
    cr_assert_stdout_eq_str("hello 12");
}

Test(my_printf, modulomodulo, .init = redirect_all_std)
{
    my_printf("hello %% world");
    cr_assert_stdout_eq_str("hello % world");
}

Test(my_printf, modulo_o, .init = redirect_all_std)
{
    my_printf("the number 10 in octal is %o", 10);
    cr_assert_stdout_eq_str("the number 10 in octal is 12");
}

Test(my_printf, modulo_x, .init = redirect_all_std)
{
    my_printf("the number 10 in hexa is %x", 10);
    cr_assert_stdout_eq_str("the number 10 in hexa is a");
}

Test(my_printf, modulo_X, .init = redirect_all_std)
{
    my_printf("the number 10 in HEXA is %X", 10);
    cr_assert_stdout_eq_str("the number 10 in HEXA is A");
}

Test(my_printf, modulo_b, .init = redirect_all_std)
{
    my_printf("the number 10 in binary is %b", 10);
    cr_assert_stdout_eq_str("the number 10 in binary is 1010");
}

Test(my_printf, all_modulo, .init = redirect_all_std)
{
    my_printf("hello %s, %c show you the number %d, the number in hexa %x and %%", "world", 'I', 69, 69);
    cr_assert_stdout_eq_str("hello world, I show you the number 69, the number in hexa 45 and %");
}

Test(my_printf, erreurone, .init = redirect_all_std)
{
    my_printf("", 12);
    cr_assert_stdout_eq_str("-1");
}
