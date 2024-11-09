/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** task07
*/

#include "my.h"

void special_case(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int zeros = 1;

    if (nb == -2147483648) {
        special_case();
        return 0;
    } else if (nb < 0) {
        my_putchar('-');
        nb = - nb;
    }
    for (int div = 1000000000; div != 0; div /= 10) {
        if (nb / div == 0 && zeros == 1 && div != 1) {
            nb %= div;
            continue;
        } else {
            my_putchar(48 + (nb / div));
            zeros = 0;
            nb %= div;
        }
    }
    return 0;
}
