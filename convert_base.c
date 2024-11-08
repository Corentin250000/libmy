/*
** EPITECH PROJECT, 2024
** convert_base.c
** File description:
** task05
*/

#include <stdlib.h>
#include "day08.h"
#include "my.h"

int max_power(int nb, int base)
{
    int result = 0;

    if (nb < 0)
        nb *= -1;
    for (; my_compute_power_it(base, result) <= nb; result++);
    return result;
}

static char character_to_put(int res_mod)
{
    char result = 0;

    if (res_mod >= 10)
        result = 65 + (res_mod - 10);
    else if (res_mod < 10)
        result = 48 + res_mod;
    return result;
}

int value_to_add(int base, char letter, int power_max)
{
    int result = 0;

    if (letter >= '0' && letter <= '9')
        result = (letter - 48) * my_compute_power_it(base, power_max);
    else if (letter >= 'A' && letter <= 'F')
        result = (letter - 55) * my_compute_power_it(base, power_max);
    return result;
}

char *base10_to_base(int nb, int base)
{
    unsigned int temp = nb < 0 ? - nb : nb;
    int res_mod = 0;
    int negative = nb < 0 ? 1 : 0;
    int size = max_power(nb, base) + negative;
    char *result = malloc(sizeof(char) * (size + 1));

    if (negative)
        result[0] = '-';
    for (int i = size - 1; i >= 0; i--) {
        if (i == 0 && result[0] == '-')
            continue;
        res_mod = temp % base;
        result[i] = character_to_put(res_mod);
        temp /= base;
    }
    result[size] = '\0';
    return result;
}

int return_to_base10(char const *nb, int base)
{
    int size = my_strlen(nb);
    int power_max = size - 1;
    int result = 0;
    int negative = 1;
    int i = 0;

    if (nb[i] == '-') {
        negative = -1;
        power_max--;
        i++;
    }
    for (; i < size; i++) {
        result += value_to_add(base, nb[i], power_max);
        power_max--;
    }
    return result * negative;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int base_from_int = my_getnbr(base_from);
    int base_to_int = my_getnbr(base_to);
    int temp_base10 = return_to_base10(nbr, base_from_int);
    char *result = base10_to_base(temp_base10, base_to_int);

    return result;
}
