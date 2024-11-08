/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** task07
*/

#include "day06.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; (s1[i] != '\0' || s2[i] != '\0') && i < n; i++) {
        if (s1[i] - s2[i] != 0)
            return s1[i] - s2[i];
    }
    return 0;
}
