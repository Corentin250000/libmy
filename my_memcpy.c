/*
** EPITECH PROJECT, 2025
** my_memcpy.c
** File description:
** ...
*/

#include "my.h"

void my_memcpy(void *dest, void *src, size_t size)
{
    void *temp_dest = dest;
    void *temp_src = src;

    if (!src)
        return;
    for (size_t i = 0; i < size; ++i) {
        *(char *) dest = *(char *) src;
        dest++;
        src++;
    }
    dest = temp_dest;
    src = temp_src;
}
